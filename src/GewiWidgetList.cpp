/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiWidgetList.cpp
    \brief Implementation of WidgetList.
    
    Implementation of WidgetList, a list of widgets used by GewiEngine and GContainers.
    <br>$Id: GewiWidgetList.cpp,v 1.3 2003/05/20 00:08:55 cozman Exp $<br>
    \author James Turk
**/

#include "GewiWidgetList.h"
#include "GewiWidget.h" //needed for definition

namespace Gewi
{

WidgetNode::WidgetNode() :
    widget(NULL),
    prev(NULL),
    next(NULL)
{
}

void WidgetList::DeleteWidgetMem(WidgetNode *node)
{
    if(node == mWidgetList) //special case if deleting top node
    {
        if(mWidgetList->next != mWidgetList)
            mWidgetList = mWidgetList->next;
        else
            mWidgetList = NULL;
    }
    //adjust links and actually delete node
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}

WidgetList::WidgetList() : 
    mWidgetList(NULL),
    mClick(NULL)
{
}

void WidgetList::AddWidget(WidgetNode *node)
{
    if(mWidgetList == NULL)
    {
        node->next = node->prev = node;
    }
    else
    {
        //make connections
        node->next = mWidgetList;
        node->prev = mWidgetList->prev;
        mWidgetList->prev->next = node;
        mWidgetList->prev = node;
    }

    mWidgetList = node;
}

void WidgetList::DeleteWidget(GWidget *widget)
{
    WidgetNode *cur = mWidgetList, *found = NULL;

    if(mWidgetList)
    {
        do
        {
            if(cur->widget == widget)
                found = cur;
            cur = cur->next;
        } while(cur != mWidgetList && !found);

        if(found)
            DeleteWidgetMem(found);
    }
}

void WidgetList::DeleteWidgets()
{
    WidgetNode *cur = mWidgetList;
    while(mWidgetList)
    {
        cur = cur->next;
        cur->prev->widget->Kill();
    }
}

void WidgetList::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    GWidget *tmp=NULL;

    if(mWidgetList)
    {
        if(event == GE_LDOWN || event == GE_RDOWN)  //mouse down
        {
            if(mWidgetList->widget->MouseInWidget())  //in focus
            {
                mWidgetList->widget->Message(rawEvent,event,mouseX,mouseY,ch);
            }
            else    //not in focus
            {
                WidgetNode *cur=mWidgetList;
                do
                {
                    cur = cur->next;
                    if(cur->widget->MouseInWidget())
                    {
                        mClick = cur;   //click in out of focus window == save this and check if mouse up occurs within
                        break;
                    }
                }while(cur->next != mWidgetList);
            }
        }
        else if(event == GE_LUP || event == GE_RUP)  //mouse up
        {
            if(mWidgetList->widget->MouseInWidget())   //inside the active
            {
                mWidgetList->widget->Message(rawEvent,event,mouseX,mouseY,ch);
            }
            else if(mClick && mClick->widget->MouseInWidget()) //inside the mouse down - make active
            {
                //unlink the node.. then move to the front of the list
                mClick->prev->next = mClick->next;
                mClick->next->prev = mClick->prev;
                mClick->widget->Message(rawEvent,event==GE_LUP?GE_LDOWN:GE_RDOWN,mouseX,mouseY,ch); //simulate the lost button-down event
                mWidgetList->widget->Message(NULL,GE_LOSTFOCUS,mouseX,mouseY,ch);   //let current focus know it is focus no more
                mClick->widget->Message(NULL,GE_GOTFOCUS,mouseX,mouseY,ch); //let new focus it got focus
                mClick->widget->Message(rawEvent,event,mouseX,mouseY,ch);   //send this event
                AddWidget(mClick);   //reinsert node
            }
            mClick = NULL;  //on up there is no mClick, it simply holds where the mouse was pressed in 
        }
        else    //non-mouseclick events
        {
            mWidgetList->widget->Message(rawEvent,event,mouseX,mouseY,ch);
        }
    }
}

void WidgetList::FitParent()
{
    WidgetNode *cur = mWidgetList;
    if(mWidgetList)  //make every child fit it's parent
    {
        do
        {
            cur->widget->FitParent();
            cur = cur->next;
        }while(cur != mWidgetList);
    }
}

void WidgetList::ShowWidgets()
{
    WidgetNode *cur = mWidgetList;
    do
    {
        cur = cur->prev;        //draw from back to front, through list in reverse
        if(cur->widget->Visible())
            cur->widget->Show();
    }while(cur != mWidgetList);
}

}
