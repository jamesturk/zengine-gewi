/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiWindow.h
    \brief Definition file for GWindow.
    
    Definition file for GWindow, a basic window class based on GContainer.
    <br>$Id: GewiWindow.h,v 1.4 2003/06/07 05:41:18 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewiwindow_h__
#define __gewiwindow_h__

#include "GewiEngine.h"
#include "GewiContainer.h"

namespace Gewi
{

/*!
    \brief GWindow, a simple window class.

    GWindow, basic window class, derived from GContainer.
**/
class GWindow : public GContainer
{
    protected:
        //! Holds internal state of if mouse is dragging the window or not.
        bool rDrag;
        //! X value of drag coordinate used for drag calculation.
        float rDragX;
        //! Y value of drag coordinate used for drag calculation.
        float rDragY;
        //! Image used for window.
        ResourceID rBackground;

    public:
        /*!
            \brief Simple constructor for GWindow.

            Default constructor for GWindow, can take a parent.
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GWindow(GContainer *parent=NULL);

        /*!
            \brief GButton's create function, must be called to set up actual button.

            Every widget has a create function which must be called to define the button's appearance and settings.
            \param x X position of widget within it's container (entire screen if no parent)
            \param y Y position of widget within it's container (entire screen if no parent)
            \param width Width of widget.
            \param height Height of widget.
            \param backgroundImg Image for window.
        **/
        virtual void Create(float x, float y, float width, float height, ResourceID backgroundImg);

        /*!
            \brief Overload of Message, used to recieve messages.

            Recieves and processes a message, required overload for all widgets.
            \param rawEvent SDL_Event of original message, may be needed if more information is available on event. (May be NULL).
            \param event GewiEvent enum, description of event recieved.
            \param mouseX Mouse x position in event, if not mouse event may be incorrect.
            \param mouseY Mouse y position in event, if not mouse event may be incorrect.
            \param ch Character pressed in event, may be 0 if not a keypress event.
        **/
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);

        /*!
            \brief Draws window & children to the screen.

            Draws window & children to the screen, required overload for all widgets.
        **/
        virtual void Show();
};

}

#endif //__gewiwindow_h__
