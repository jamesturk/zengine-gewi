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
             string text, GButtonType type)
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

void GTextButton::SetText(string text)
{
    rText = text;
    rGewi->Font(rFont)->DrawText(rText,rTextBuf);
    //center the text
    rXOff = static_cast<int>(rBoundRect.Width()-rTextBuf.Width())/2;
    rYOff = static_cast<int>(rBoundRect.Height()-rTextBuf.Height())/2;
}

string GTextButton::GetText()
{
    return rText;
}

}
