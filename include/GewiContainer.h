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
    <br>$Id: GewiContainer.h,v 1.6 2003/06/09 03:28:59 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewicontainer_h__
#define __gewicontainer_h__

#include "GewiIncludes.h"
#include "GewiWidgetList.h"
#include "GewiWidget.h"

namespace Gewi
{

/*!
    \brief GContainer class, definition of a container widget.

    GContainer widget which is a standard GWidget that can serve as a parent, contain and manage other widgets.
**/
class GContainer : public GWidget
{
    /*! 
    The usage of friend here is used simply to allow GWidget proper access to what used to belong to 
    it before the class split GWidget needs access to Add/ReleaseChild but to make them public would 
    <strong>reduce</strong> encapsulation. (For those keeping score, this is to many people the only effective use of 
    friend.)
    **/
    friend GWidget; 

    protected:
        //! List of child widgets assigned to this container.
        WidgetList rChildList;
        
        /*!
            \brief Adds a child to the child list.

            Registers the widget as a child of this container, private because GWidget is a friend.
            \param widget Widget to register as a child of this container.
        **/
        void AddChild(GWidget *widget);

        /*!
            \brief Removes a child from the child list.

            Releases the widget which is a child of this container, private because GWidget is a friend.
            \param widget Widget to release from this container.
        **/
        void ReleaseChild(GWidget *widget);

        /*!
            \brief Inserts a child to the child list.

            Calls needed function of WidgetList class to put widget into the linked list.
            \param node WidgetNode to insert into rChildList.
        **/
        void InsertWidget(WidgetNode *node);

    public:
        /*!
            \brief Simple constructor for GContainer.

            Constructor for GContainer, can take a parent (to be contained on a GContainer derived class, allowing nested containers).
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GContainer(GContainer *parent=NULL);

        ~GContainer();

        /*!
            \brief Move container and children.

            Same as GWidget::Move but overloaded to move children.
            \param x New x position for container.
            \param y New y position for container.
        **/
        virtual void Move(float x, float y);

        /*!
            \brief Overload of Message, used to recieve messages.

            Recieves and processes a message, required overload for all widgets, overloaded to also account for children.
            \param rawEvent SDL_Event of original message, may be needed if more information is available on event. (May be NULL).
            \param event GewiEvent enum, description of event recieved.
            \param mouseX Mouse x position in event, if not mouse event may be incorrect.
            \param mouseY Mouse y position in event, if not mouse event may be incorrect.
            \param ch Character pressed in event, may be 0 if not a keypress event.
        **/
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);

        /*!
            \brief Show children.

            Draws all children in appropriate back-to-front order.
        **/
        virtual void Show();
};

}

#endif //__gewicontainer_h__
