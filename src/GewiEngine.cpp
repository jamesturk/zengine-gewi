/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file ZE_ZConfigFile.h
    \brief Definition file for ZConfigFile.
    
    Definition file for ZConfigFile, an INI-style config file format.
    <br>$ id: ZE_ZConfigFile.h,v 1.9 2003/02/10 04:40:16 cozman Exp $<br>
    \author James Turk
**/

#include "GewiWidget.h"
#include "GewiEngine.h"

namespace Gewi
{

GewiEngine *GewiEngine::sInstance=NULL;
SDL_EventFilter GewiEngine::sOldFilter=NULL;

GewiEngine::GewiEngine()
{
    sOldFilter = SDL_GetEventFilter();  //store event filter and set the new one
    SDL_SetEventFilter((SDL_EventFilter)GewiEngine::EventFilter);
    SDL_EnableUNICODE(1);   //needed for the key translation
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
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
        SDL_SetEventFilter(sOldFilter);
    }
}

int GewiEngine::EventFilter(SDL_Event *event)
{
    static char noChar = static_cast<char>(0);
    GewiEngine *gewi = GewiEngine::GetInstance();
    char ch;

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
        case SDL_QUIT:
            //.
            break;
        default:
            break;
    }
    return 1;   //pass the event on
}

char GewiEngine::TranslateKey(SDL_keysym key)
{
    char ch;

    if(key.unicode && key.unicode <= 255)
        ch = static_cast<char>(key.unicode);
    else
        ch = static_cast<char>(127);

    if(ch >= 'a' && ch <= 'z' && (key.mod & KMOD_SHIFT))
        ch -= 20;   //capitalize

    return ch;
}

void GewiEngine::Display()
{
    mWidgetList.ShowWidgets();
}

ResourceID GewiEngine::AddResource(ZImage *image)
{
    mImageVec.push_back(image);
    return static_cast<ResourceID>(mImageVec.size()-1);
}

ResourceID GewiEngine::AddResource(ZFont *font)
{
    mFontVec.push_back(font);
    return static_cast<ResourceID>(mFontVec.size()-1);
}

ZImage* GewiEngine::Image(ResourceID id)
{
    //do range checking
    if(id >= 0 && id < mImageVec.size())
        return mImageVec[id];
    else
        return NULL;
}

ZFont* GewiEngine::Font(ResourceID id)
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
        {
            mImageVec[i]->Release();
            delete mImageVec[i];
        }
    }
    for(ResourceID i=0; i < mFontVec.size(); i++)
    {
        if(mFontVec[i])
        {
            mFontVec[i]->Release();
            delete mFontVec[i];
        }
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
