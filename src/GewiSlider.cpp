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

#include "GewiSlider.h"

namespace Gewi
{

GSlider::GSlider() :
    GWidget(),
    rPressed(false),
    rBackground(GewiEngine::InvalidID),
    rSlider(GewiEngine::InvalidID),
    rMin(0),
    rMax(1),
    rPos(0),
    rIncrement(0)
{}

void GSlider::Create(float x, float y, float width, float height, ResourceID backgroundImg, ResourceID sliderImg, 
                     float min, float max, int increment)
{
    GWidget::Create(x,y,width,height);
    rBackground = backgroundImg;
    rSlider = sliderImg;
    rMin = min;
    rMax = max;
    rIncrement = increment;
    SetPos(rPos);   //clamp inside
}

void GSlider::SetPos(float pos)
{
    if(rIncrement)
    {
        int rounded;

        if(pos - static_cast<int>(pos) < 0.5)   //move to closest integer
            rounded = static_cast<int>(floorf(pos)+rIncrement/2);
        else
            rounded = static_cast<int>(ceilf(pos)+rIncrement/2);
        pos = static_cast<float>(rounded-rounded%rIncrement);   //snap to a multiple of increment
    }

    if(pos < rMin)
        pos = rMin;
    if(pos > rMax)
        pos = rMax;
    rPos = pos;
}

float GSlider::GetPos()
{
    return rPos;
}

void GHorizSlider::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    //doesn't check if mouse is in widget because Show actually checks that for the drawing 
    if(event == GE_LDOWN)
        rPressed = true;
    else if(event == GE_LUP && rPressed)
    {
        //min + (Distance Past Rect.X / Rect.Width)
        SetPos(rMin+((mouseX-rBoundRect.X())/rBoundRect.Width())*(rMax-rMin));
        rPressed = false;
    }
}

void GHorizSlider::Show()
{
    float xPos;

    if(rPressed && !rZE->LButtonPressed() || !MouseInWidget())  //dont allow them to drag pointer out of box
        Message(NULL,GE_LUP,rZE->MouseX(),rZE->MouseY(),static_cast<char>(0));  //fake a message

    //the slider is centered about the current position
    if(rPressed)
        xPos = rZE->MouseX()-rGewi->Image(rSlider)->Width()/2.0f;
    else
        xPos = rBoundRect.X()+(((rPos-rMin)/(rMax-rMin))*rBoundRect.Width())-rGewi->Image(rSlider)->Width()/2.0f;

    //draw from resources
    rGewi->Image(rBackground)->Draw(rBoundRect.X(),rBoundRect.Y());
    rGewi->Image(rSlider)->Draw(xPos,rBoundRect.Y());
}

void GVertSlider::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    //doesn't check if mouse is in widget because Show actually checks that (to avoid being dragged outside)
    if(event == GE_LDOWN)
        rPressed = true;
    else if(event == GE_LUP && rPressed)
    {
        SetPos(rMin+((mouseY-rBoundRect.Y())/rBoundRect.Height())*(rMax-rMin)); //clamp when they release the button
        rPressed = false;
    }
}

void GVertSlider::Show()
{
    float yPos;

    if(!rZE->LButtonPressed() || !MouseInWidget())  //dont allow them to drag pointer out of box
        Message(NULL,GE_LUP,rZE->MouseX(),rZE->MouseY(),static_cast<char>(0));  //faking a message

    //the slider is centered about the current position
    if(rPressed)
        yPos = rZE->MouseY()-rGewi->Image(rSlider)->Height()/2.0f;
    else
        yPos = rBoundRect.Y()+(((rPos-rMin)/(rMax-rMin))*rBoundRect.Height())-rGewi->Image(rSlider)->Height()/2.0f;

    //draw from resources
    rGewi->Image(rBackground)->Draw(rBoundRect.X(),rBoundRect.Y());
    rGewi->Image(rSlider)->Draw(rBoundRect.X(),yPos);
}

}
