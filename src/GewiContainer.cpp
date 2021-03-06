/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiContainer.cpp
    \brief Implementation of GContainer.
    
    Implementation of GContainer, a barebones widget that can contain child widgets.
    <br>$Id: GewiContainer.cpp,v 1.6 2003/06/12 09:32:32 cozman Exp $<br>
    \author James Turk
**/

#include "GewiContainer.h"

namespace Gewi
{

//all the work for GContainer is now done by WidgetList//

void GContainer::AddChild(GWidget *widget)
{
    WidgetNode *node = new WidgetNode;
    node->widget = widget;
    rChildList.AddWidget(node); //create new child on top
}

void GContainer::ReleaseChild(GWidget *widget) //this simply releases a child, usually called when the child is being destroyed
{
    rChildList.DeleteWidget(widget);
}

void GContainer::InsertWidget(WidgetNode *node)   //insert at front
{
    rChildList.AddWidget(node);
}

GContainer::GContainer(GContainer *parent)
{
}

GContainer::~GContainer()
{
    rChildList.DeleteWidgets();
}

void GContainer::Move(float x, float y)
{
    GWidget::Move(x,y);
    rChildList.FitParent(); //fit each child to parent
}

void GContainer::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    rChildList.Message(rawEvent,event,mouseX,mouseY,ch);    //rChildList does the work of passing the event correctly
}

void GContainer::Show()
{
    rChildList.ShowWidgets();
}

}
