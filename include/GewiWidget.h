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
    <br>$Id: GewiWidget.h,v 1.5 2003/06/09 03:28:59 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewiwidget_h__
#define __gewiwidget_h__

#include "GewiIncludes.h"

namespace Gewi
{

class GewiEngine;
class GContainer;

/*!
    \brief GWidget base widget class.

    Basic widget class, framework and base class for all other widgets.
**/
class GWidget
{
    protected:
        //! Pointer to GewiEngine instance.
        GewiEngine *rGewi;
        //! Pointer to ZEngine instance.
        ZEngine *rZE;
        //! Rectangle describing area of widget.
        ZRect rBoundRect;
        //! Pointer to parent container. (NULL means it lays in the global setting).
        GContainer *rParent;
        //! Relative X position, relative to parent, or top corner of screen if in global setting.
        float rRelX;
        //! Relative Y position, relative to parent, or top corner of screen if in global setting.
        float rRelY;
        //! Stores if widget is currently visible.
        bool rVisible;

    public:
        /*!
            \brief Simple constructor for GWidget.

            Constructor for GWidget, like all widgets this must initialize private data and can take a parent.
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GWidget(GContainer *parent=NULL);

        /*!
            \brief Simple destructor.

            Must be virtual so that each derived class can free it's members.
        **/
        virtual ~GWidget();

        /*!
            \brief Toggle the visible flag.

            Toggles the visible flag, only visible widgets are drawn.
        **/
        void ToggleVisible();

        /*!
            \brief Reposition widget within parent.
            
            Adjust this widget to be in the correct position in relationship to it's parent.  Only containers call this on 
            their children, it generally shouldn't be called.
        **/
        void FitParent();

        /*!
            \brief Sets position and dimensions of widget.

            Sets up widget rectangle, most widgets must override this to include their specific settings.
            \param x X position of widget within it's container (entire screen if no parent)
            \param y Y position of widget within it's container (entire screen if no parent)
            \param width Width of widget.
            \param height Height of widget.
        **/
        virtual void Create(float x, float y, float width, float height);

        /*!
            \brief Change relative position.

            Set new relative position for widget.
            \param x New relative x position.
            \param y New relative y position.
        **/
        virtual void Move(float x, float y);

        /*!
            \brief Important function used to recieve messages.

            Recieves and processes a message, required overload for all widgets.
            \param rawEvent SDL_Event of original message, may be needed if more information is available on event. (May be NULL).
            \param event GewiEvent enum, description of event recieved.
            \param mouseX Mouse x position in event, if not mouse event may be incorrect.
            \param mouseY Mouse y position in event, if not mouse event may be incorrect.
            \param ch Character pressed in event, may be 0 if not a keypress event.
        **/
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)=0;

        /*!
            \brief Draws this button to the screen.

            Draws widget to the screen, required overload for all widgets.
        **/
        virtual void Show()=0;

        /*!
            \brief Get X position of widget.

            Get actual (not relative) X position of top left corner of widget.
            \return Actual x position of widget.
        **/
        float X();

        /*!
            \brief Get Y position of widget.

            Get actual (not relative) Y position of top left corner of widget.
            \return Actual y position of widget.
        **/
        float Y();

        /*!
            \brief Get visible state of widget.

            Returns status of internal visible flag.
            \return true if visible, false otherwise.
        **/
        bool Visible();

        /*!
            \brief Check if mouse is in widget.

            Returns status of mouse inside widget.
            \return true if mouse pointer inside widget, false otherwise.
        **/
        bool MouseInWidget();

        /*!
            \brief Check if the widget contains a point.

            Check if the widget contains the point specified.
            \param x X value of point to check.
            \param y Y value of point to check.
        **/
        bool Contains(Sint16 x, Sint16 y);
};

}

#endif //__gewiwidget_h__
