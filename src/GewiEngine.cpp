/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiEngine.cpp
    \brief Implementation of GewiEngine.
    
    Implementation of GewiEngine, core engine for Gewi GUI control.
    <br>$Id: GewiEngine.cpp,v 1.8 2003/06/12 09:32:33 cozman Exp $<br>
    \author James Turk
**/

#include "GewiWidget.h"
#include "GewiEngine.h"

namespace Gewi
{

VersionInfo GewiEngine::Version(0,2,0,"dev");
VersionInfo GewiEngine::MinZEVersion(0,8,4,"dev");  //important to keep this accurate
GewiEngine *GewiEngine::sInstance=NULL;

GewiEngine::GewiEngine()
{
    ZE::ZEngine *ze = ZE::ZEngine::GetInstance();

    //check version of ZEngine
    if(ZE::ZEngine::Version < GewiEngine::MinZEVersion)
        ze->WriteLog(ZE::FormatStr("Gewi %s requires ZEngine %s or greater, ZEngine %s in use.",
        GewiEngine::Version.GetString().c_str(), 
        GewiEngine::MinZEVersion.GetString().c_str(), 
        ZE::ZEngine::Version.GetString().c_str()));

    ze->SetEventFilter((SDL_EventFilter)GewiEngine::EventFilter);
    SDL_EnableUNICODE(1);   //needed for the key translation
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);  //more like typing, less like game
}

GewiEngine* GewiEngine::GetInstance()
{
    if(!sInstance)
        sInstance = new GewiEngine;
    return sInstance;
}

void GewiEngine::ReleaseInstance()
{
    if(sInstance)
    {
        sInstance->FreeResources();
        sInstance->mWidgetList.DeleteWidgets();
        delete sInstance;
        sInstance = NULL;
        //set everything back to default
        SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_INTERVAL,SDL_DEFAULT_REPEAT_INTERVAL);
        SDL_EnableUNICODE(0);
        ZE::ZEngine::GetInstance()->SetEventFilter(NULL);
    }
}

int GewiEngine::EventFilter(SDL_Event *event)
{
    static char noChar = '\0';
    GewiEngine *gewi = GewiEngine::GetInstance();
    char ch;

    //called inside ZEngine::CheckEvents
    switch(event->type)
    {
        case SDL_MOUSEBUTTONDOWN:
            if(event->button.button == SDL_BUTTON_LEFT)
                gewi->SendMessage(event,GE_LDOWN,event->button.x,event->button.y,noChar);
            if(event->button.button == SDL_BUTTON_RIGHT)
                gewi->SendMessage(event,GE_RDOWN,event->button.x,event->button.y,noChar);
            break;
        case SDL_MOUSEBUTTONUP:
            if(event->button.button == SDL_BUTTON_LEFT)
                gewi->SendMessage(event,GE_LUP,event->button.x,event->button.y,noChar);
            if(event->button.button == SDL_BUTTON_RIGHT)
                gewi->SendMessage(event,GE_RUP,event->button.x,event->button.y,noChar);
            break;
        case SDL_KEYDOWN:
            ch = TranslateKey(event->key.keysym);
            gewi->SendMessage(event,GE_KDOWN,0,0,ch);
            break;
        case SDL_KEYUP:
            ch = TranslateKey(event->key.keysym);
            gewi->SendMessage(event,GE_KUP,0,0,ch);
            break;
        default:
            break;
    }
    return 1;   //pass the event on, allowing ZEngine to do what it needs
}

char GewiEngine::TranslateKey(SDL_keysym key)
{
    //this is why unicode must be enabled, without this it'd be one massive switch statement
    if(key.unicode > 0 && key.unicode <= 255)
        return static_cast<char>(key.unicode);
    else
        return static_cast<char>(127);
}

void GewiEngine::Display()
{
    mWidgetList.ShowWidgets();
}

ResourceID GewiEngine::AddResource(ZE::ZImage *image)
{
    mImageVec.push_back(image);
    return static_cast<ResourceID>(mImageVec.size()-1);
}

ResourceID GewiEngine::AddResource(ZE::ZFont *font)
{
    mFontVec.push_back(font);
    return static_cast<ResourceID>(mFontVec.size()-1);
}

ZE::ZImage* GewiEngine::Image(ResourceID id)
{
    //do range checking
    if(id >= 0 && id < mImageVec.size())
        return mImageVec[id];
    else
        return NULL;
}

ZE::ZFont* GewiEngine::Font(ResourceID id)
{
    //do range checking
    if(id >= 0 && id < mFontVec.size())
        return mFontVec[id];
    else
        return NULL;
}

void GewiEngine::FreeResources()
{
    for(ResourceID i=0; i < mImageVec.size(); i++)
    {
        if(mImageVec[i])
            mImageVec[i]->Release();
    }
    for(ResourceID i=0; i < mFontVec.size(); i++)
    {
        if(mFontVec[i])
            mFontVec[i]->Release();
    }
}

void GewiEngine::Register(GWidget *widget)
{
    WidgetNode *node = new WidgetNode;
    node->widget = widget;
    mWidgetList.AddWidget(node);
}

void GewiEngine::SendMessage(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    mWidgetList.Message(rawEvent,event,mouseX,mouseY,ch);
}

void GewiEngine::DeleteWidget(GWidget *widget)    //finds + frees memory of widget
{
    mWidgetList.DeleteWidget(widget);
}

void GewiEngine::InsertWidget(WidgetNode *node)   //insert at front
{
    mWidgetList.AddWidget(node);
}

}
