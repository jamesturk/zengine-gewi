/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiWidget.h
    \brief Definition file for GWidget.
    
    Definition file for GWidget, virtual widget base class.
    <br>$Id: GewiWidget.h,v 1.3 2003/05/19 23:56:05 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewiwidget_h__
#define __gewiwidget_h__

#include "GewiIncludes.h"

namespace Gewi
{


class GewiEngine;
class GContainer;

class GWidget
{
    protected:
        GewiEngine *rGewi;
        ZEngine *rZE;
        ZRect rBoundRect;
        GContainer *rParent;
        float rRelX,rRelY;
        bool rVisible;
        bool rAlive;

    public:
        GWidget(GContainer *parent=NULL);
        virtual ~GWidget();
        
        void FitParent();
        void ToggleVisible();

        virtual void Kill();
        virtual void Create(float x, float y, float width, float height);
        virtual void Move(float x, float y);
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)=0;
        virtual void Show()=0;

        float X();
        float Y();
        bool Visible();
        bool MouseInWidget();
        bool Contains(Sint16 x, Sint16 y);
};

}

#endif //__gewiwidget_h__
