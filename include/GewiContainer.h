/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiContainer.h
    \brief Definition file for GContainer.
    
    Definition file for GContainer, a barebones widget that can contain child widgets.
    <br>$Id: GewiContainer.h,v 1.4 2003/05/21 02:47:56 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewicontainer_h__
#define __gewicontainer_h__

#include "GewiIncludes.h"
#include "GewiWidgetList.h"
#include "GewiWidget.h"

namespace Gewi
{

class GContainer : public GWidget
{
    //friend here is used simply to allow GWidget proper access to what used to belong to it before 
    //the class split GWidget needs access to Add/ReleaseChild but to make them public would _reduce_
    //encapsulation (for those keeping score, this is to many people the only effective use of friend)
    friend GWidget; 

    protected:
        WidgetList rChildList;
        void AddChild(GWidget *widget);
        void ReleaseChild(GWidget *widget);
        void InsertWidget(WidgetNode *node);
    public:
        GContainer(GContainer *parent=NULL);

        virtual void Kill();
        virtual void Move(float x, float y);
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        virtual void Show();
};

}

#endif //__gewicontainer_h__
