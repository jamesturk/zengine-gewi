/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiButton.cpp
    \brief Implementation of GButton.
    
    Implementation of GButton, a simple button class.
    <br>$Id: GewiButton.cpp,v 1.4 2003/08/10 01:40:56 cozman Exp $<br>
    \author James Turk
**/

#include "GewiButton.h"

namespace Gewi
{

GButton::GButton(GContainer *parent) : 
    GWidget(parent),
    rPressed(false),
    rType(GBT_PRESS),
    rNormalImage(GewiEngine::InvalidID),
    rPressedImage(GewiEngine::InvalidID)
{
}

void GButton::Create(float x, float y, float width, float height, ResourceID normalImg, ResourceID pressImg, GButtonType type)
{
    GWidget::Create(x,y,width,height);
    rNormalImage = normalImg;
    rPressedImage = pressImg;
    rType = type;
}

void GButton::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    if(event == GE_LUP && MouseInWidget())
    {
        rPressed = !rPressed;   //toggle button state on mouseup
    }
}

void GButton::Show()
{
    float x,y;
    float w,h;
    x = rBoundRect.X();
    y = rBoundRect.Y();

    //images must be "resized" with each draw, disadvantage to shared resources
    //yet luckily the ZImage resize system is only two assignments, not actual stretching code
    //if resize is to be rewritten the shared resources system of Gewi should be reconsidered
    w = rBoundRect.Width();
    h = rBoundRect.Height();
    rGewi->Image(rPressedImage)->Resize(w,h);
    rGewi->Image(rNormalImage)->Resize(w,h);

    if(rVisible)
    {
        if(rType == GBT_PRESS)    //G_PRESS: standard press button, down when pressed, up when not
        {
            if(rPressed)
                rGewi->Image(rPressedImage)->Draw(x,y);
            else
                rGewi->Image(rNormalImage)->Draw(x,y);
        }
        else if(rType == GBT_HOVER)   //G_HOVER: button shows as down when hovered over
        {
            if(MouseInWidget())
                rGewi->Image(rPressedImage)->Draw(x,y);
            else
                rGewi->Image(rNormalImage)->Draw(x,y);
        }
    }
}

bool GButton::IsPressed()
{
    return rPressed;
}

void GButton::SetState(bool pressed)
{
    rPressed = pressed;
}

}
