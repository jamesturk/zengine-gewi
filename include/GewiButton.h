/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiButton.h
    \brief Definition file for GButton.
    
    Definition file for GButton, a simple button class.
    <br>$Id: GewiButton.h,v 1.3 2003/05/19 23:56:05 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewibutton_h__
#define __gewibutton_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

class GButton : public GWidget
{
    protected:
        bool rPressed;
        GButtonType rType;
        ResourceID rNormalImage;
        ResourceID rPressedImage;
    public:
        GButton(GContainer *parent=NULL);

        virtual void Create(float x, float y, float width, float height, ResourceID normalImg, ResourceID pressImg, GButtonType type=G_PRESS);
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        virtual void Show();

        bool IsPressed();
        void SetState(bool state);
};

}

#endif //__gewibutton_h__
