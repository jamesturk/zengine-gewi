/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiTextField.cpp
    \brief Implementation of GTextField.
    
    Implementation of GTextField, text input area widget.
    <br>$Id: GewiTextField.cpp,v 1.7 2003/08/10 01:40:56 cozman Exp $<br>
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

        rGewi->Font(rFont)->DrawText(rText.length() ? rText : "",rBuffer);
    }
}

void GTextField::Show()
{
    rGewi->Image(rBackground)->Resize(rBoundRect.Width(),rBoundRect.Height());
    rGewi->Image(rBackground)->Draw(rBoundRect.X(),rBoundRect.Y());
    if(rBuffer.IsLoaded())  //don't draw empty buffer image
        rBuffer.Draw(rLeftPadding+rBoundRect.X(),rBoundRect.Y()+(rBoundRect.Height()-rBuffer.Height())/2);
}

void GTextField::SetText(std::string text)
{
    rText = text;
    rGewi->Font(rFont)->DrawText(rText,rBuffer);
}

std::string GTextField::GetText()
{
    return rText;
}

}
