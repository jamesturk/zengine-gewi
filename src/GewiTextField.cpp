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

#include "GewiTextField.h"

namespace Gewi
{

GTextField::GTextField(GContainer *parent) :
    GWidget(parent),
    rFont(GewiEngine::InvalidID),
    rBackground(GewiEngine::InvalidID),
    rMaxChars(256),
    rLeftPadding(0)
{}

GTextField::~GTextField()
{
}

void GTextField::Kill()
{
    rBuffer.Release();
    GWidget::Kill();
}

void GTextField::Create(float x, float y, float width, float height, ResourceID font, ResourceID backgroundImg, int maxChars, int leftPad)
{
    GWidget::Create(x,y,width,height);
    rFont = font;
    rBackground = backgroundImg;
    rMaxChars = maxChars;
    rLeftPadding = leftPad;
}

void GTextField::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    if(event == GE_KDOWN)
    {
                                                            //casted to avoid warning
        if((isgraph(ch) || ch == ' ') && rText.length() < static_cast<size_t>(rMaxChars))   //only add characters + spaces
            rText += ch;
        else if(ch == '\b')
            rText = rText.length() ? rText.substr(0,rText.length()-1) : "";    //go back one character

        rGewi->Font(rFont)->DrawText(rText.length() ? rText : " ",rBuffer);
    }
}

void GTextField::Show()
{
    rGewi->Image(rBackground)->Resize(static_cast<unsigned int>(rBoundRect.Width()),static_cast<unsigned int>(rBoundRect.Height()));
    rGewi->Image(rBackground)->Draw(rBoundRect.X(),rBoundRect.Y());
    if(rBuffer.IsLoaded())  //don't draw empty buffer image
        rBuffer.Draw(rLeftPadding+rBoundRect.X(),rBoundRect.Y()+(rBoundRect.Height()-rBuffer.Height())/2);
}

void GTextField::SetText(string text)
{
    rText = text;
    rGewi->Font(rFont)->DrawText(rText,rBuffer);
}

string GTextField::GetText()
{
    return rText;
}

}
