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

#include "GewiStaticText.h"

namespace Gewi
{

GStaticText::GStaticText(GContainer *parent) :
    GWidget(parent),
    rBackgroundImage(GewiEngine::InvalidID), 
    rFont(GewiEngine::InvalidID), 
    rXOff(0), 
    rYOff(0),
    rJustify(GJ_CENTER)
{
}


void GStaticText::Create(float x, float y, float width, float height, 
                         ResourceID font, ResourceID backgroundImg, string text, GewiJustify justify)
{
    GWidget::Create(x,y,width,height);
    
    rBackgroundImage = backgroundImg;
    rFont = font;
    rJustify = justify; //must justify pre-SetText
    SetText(text);
}

void GStaticText::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    //static text ignores messages
}

void GStaticText::Show()
{
    //images must call Resize with each draw (shared resources)
    if(rBackgroundImage != GewiEngine::InvalidID)
        rGewi->Image(rBackgroundImage)->Resize(static_cast<unsigned int>(rBoundRect.Width()),static_cast<unsigned int>(rBoundRect.Height()));

    if(rBackgroundImage != GewiEngine::InvalidID)
        rGewi->Image(rBackgroundImage)->Draw(rBoundRect.X(),rBoundRect.Y());
    rTextBuf.Draw(rBoundRect.X()+rXOff,rBoundRect.Y()+rYOff);   //draw text shifted by offset
}


void GStaticText::SetText(string text)
{
    int w,h;

    rText = text;
    rGewi->Font(rFont)->DrawText(rText,rTextBuf);

    w=rTextBuf.Width();
    h=rTextBuf.Height();

    //center each by default
    rXOff = static_cast<int>(rBoundRect.Width()-w)/2;
    rYOff = static_cast<int>(rBoundRect.Height()-h)/2;

    if(rJustify & GJ_LEFT)
    {
        printf("left");
        rXOff = 0;
    }
    else if(rJustify & GJ_RIGHT)
    {
        printf("right");
        rXOff = static_cast<int>(rBoundRect.Width()-w);
    }

    if(rJustify & GJ_TOP)
    {
        printf("top");
        rYOff = 0;
    }
    else if(rJustify & GJ_BOTTOM)
    {
        printf("bottom");
        rYOff = static_cast<int>(rBoundRect.Height()-h);
    }
    printf("\n");
}

string GStaticText::GetText()
{
    return rText;
}

}
