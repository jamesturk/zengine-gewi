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
    <br>$Id: GewiButton.h,v 1.4 2003/06/07 05:41:18 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewibutton_h__
#define __gewibutton_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

/*!
    \brief Enumeration for the button types.

    Definitions of the two possible button types.
**/
enum GButtonType
{
    GBT_PRESS,  /*!< Simple button with standard behavior. */
    GBT_HOVER   /*!< Button which shows itself clicked when hovered over. */
};

/*!
    \brief GButton class for basic buttons.

    GButton simple button widget, derived from GWidget.
**/
class GButton : public GWidget
{
    protected:
        //! Boolean holding if button is currently pressed or not.
        bool rPressed;
        //! Enum for type of button.
        GButtonType rType;
        //! Resource ID for the non-pressed image.
        ResourceID rNormalImage;
        //! Resource ID for the pressed (or hover) image.
        ResourceID rPressedImage;

    public:
        /*!
            \brief Simple constructor for GButton.

            Constructor for GButton, can take a parent.
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GButton(GContainer *parent=NULL);

        /*!
            \brief GButton's create function, must be called to set up actual button.

            Every widget has a create function which must be called to define the button's appearance and settings.
            \param x X position of widget within it's container (entire screen if no parent)
            \param y Y position of widget within it's container (entire screen if no parent)
            \param width Width of widget.
            \param height Height of widget.
            \param normalImg Image for button when not pressed.
            \param pressImg Image for button when pressed (or hovered if type is GBT_HOVER).
            \param type GButtonType, either the default, GBT_PRESS (normal button), or GBT_HOVER (a button which responds to the hovering mouse).
        **/
        virtual void Create(float x, float y, float width, float height, ResourceID normalImg, ResourceID pressImg, GButtonType type=GBT_PRESS);

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
            \brief Draws this button to the screen.

            Draws widget to the screen, required overload for all widgets.
        **/
        virtual void Show();

        /*!
            \brief Returns button state.

            Returns true if buttons is pressed, false otherwise.  (GBT_HOVER can only be pressed once, after that they stay down.)
            \return button pressed state
        **/
        bool IsPressed();

        /*!
            \brief Sets button state (pressed/unpressed).

            Sets button to pressed (true) or unpressed (false).
            \param pressed true means pressed, false means unpressed.
        **/
        void SetState(bool pressed);
};

}

#endif //__gewibutton_h__
