/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiTextButton.cpp
    \brief Implementation of GTextButton.
    
    Implementation of GTextButton, a GButton that has a text label.
    <br>$Id: GewiTextButton.cpp,v 1.4 2003/06/11 00:19:29 cozman Exp $<br>
    \author James Turk
**/

#include "GewiTextButton.h"

namespace Gewi
{

GTextButton::GTextButton(GContainer *parent) : 
    GButton(parent),
    rXOff(0),
    rYOff(0),
    rFont(GewiEngine::InvalidID)
{}


void GTextButton::Create(float x, float y, float width, float height, ResourceID normalImg, ResourceID pressImg, ResourceID font,
             std::string text, GButtonType type)
{
    GButton::Create(x,y,width,height,normalImg,pressImg,type);
    rFont = font;
    SetText(text);
}

void GTextButton::Show()
{
    GButton::Show();    //draw button before text

    //TODO: calculate decent pressed offset based upon scale
    if(rPressed)
        rTextBuf.Draw(rBoundRect.X()+rXOff+5,rBoundRect.Y()+rYOff+3);   //draw text shifted by offset + a bit (for pressed look)
    else
        rTextBuf.Draw(rBoundRect.X()+rXOff,rBoundRect.Y()+rYOff);   //draw text shifted by offset
}

void GTextButton::SetText(std::string text)
{
    rText = text;
    rGewi->Font(rFont)->DrawText(rText,rTextBuf);
    //center the text
    rXOff = static_cast<int>(rBoundRect.Width()-rTextBuf.Width())/2;
    rYOff = static_cast<int>(rBoundRect.Height()-rTextBuf.Height())/2;
}

std::string GTextButton::GetText()
{
    return rText;
}

}
