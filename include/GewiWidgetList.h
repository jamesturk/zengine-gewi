/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiWidgetList.h
    \brief Definition file for WidgetList.
    
    Definition file for WidgetList, a list of widgets used by GewiEngine and GContainers.
    <br>$Id: GewiWidgetList.h,v 1.4 2003/06/07 05:41:18 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewiwidgetlist_h__
#define __gewiwidgetlist_h__

#include "GewiIncludes.h"

namespace Gewi
{

class GWidget;

/*!
    \brief WidgetNode class, node for linked list.

    Doubly linked list node containing a widget.
**/
class WidgetNode
{
    public:
        /*!
            \brief Basic constructor.
            
            Simple safety constructor just sets all values to NULL.
        **/
        WidgetNode();

        //! Pointer to widget for this node.
        GWidget *widget;
        //! Pointer to previous node.
        WidgetNode *prev;
        //! Pointer to next node.
        WidgetNode *next;
};


/*!
    \brief Class containing a linked list of widgets.

    Linked list of widgets, and various utility functions for containers.
    Class is internally used only, GContainer and GewiEngine heavily rely on it.
**/
class WidgetList
{
    private:
        //! Pointer to head of list.
        WidgetNode *mWidgetList;
        //! Variable keeping track of where the last click was, to change focus.
        WidgetNode *mClick;

        /*!
            \brief Internal function to delete widget memory.

            Deletes the memory used by a widget node, interally used.
            \param node Node to delete.
        **/
        void DeleteWidgetMem(WidgetNode *node);
    public:
        /*!
            \brief Constructor for the linked list.

            Simply NULLs pointers for the linked list.
        **/
        WidgetList();

        /*!
            \brief Add a WidgetNode to the list.

            Adds a WidgetNode to the list, in the 'front'.
            \param node Node to add to list.
        **/
        void AddWidget(WidgetNode *node);

        /*!
            \brief Delete a widget.

            Deletes a widget, it's memory and frees it from it's container or GewiEngine.
            \param widget Widget to delete.
        **/
        void DeleteWidget(GWidget *widget);

        /*!
            \brief Delete all widgets.

            Deletes all widgets and their memory.
        **/
        void DeleteWidgets();
        
        /*!
            \brief Intercepts a message to process.

            Intercepts and processes incoming messages, delegating them where they belong.
            \param rawEvent SDL_Event of original message, may be needed if more information is available on event. (May be NULL).
            \param event GewiEvent enum, description of event recieved.
            \param mouseX Mouse x position in event, if not mouse event may be incorrect.
            \param mouseY Mouse y position in event, if not mouse event may be incorrect.
            \param ch Character pressed in event, may be 0 if not a keypress event.
        **/
        void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);

        /*!
            \brief Fit all widgets to the parent.

            Fits widgets to parent of which this linked list is a part of.
        **/
        void FitParent();

        /*!
            \brief Show widgets.

            Calls Show method of widgets in reverse order for proper appearance.
        **/
        void ShowWidgets();
};

}

#endif //__gewiwidgetlist_h__
