/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiSlider.h
    \brief Definition file for GSlider, GHorizSlider and GVertSlider.
    
    Definition file for GSlider, GHorizSlider and GVertSlider, the slide-select classes for Gewi.
    <br>$Id: GewiSlider.h,v 1.3 2003/05/19 23:56:05 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewislider_h__
#define __gewislider_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

class GSlider : public GWidget
{
    protected:
        bool rPressed;
        ResourceID rBackground;
        ResourceID rSlider;
        float rMin,rMax,rPos;
        int rIncrement;
    public:
        GSlider();

        virtual void Create(float x, float y, float width, float height, ResourceID backgroundImg, ResourceID sliderImg, 
            float min, float max, int increment);

        void SetPos(float pos);
        float GetPos();
};

class GHorizSlider : public GSlider
{
    public:
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        virtual void Show();
};

class GVertSlider : public GSlider
{
    public:
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        virtual void Show();
};

}

#endif //__gewislider_h__
