/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiTextField.h
    \brief Definition file for GTextField.
    
    Definition file for GTextField, text input area widget.
    <br>$Id: GewiTextField.h,v 1.5 2003/06/07 05:41:18 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewitextfield_h__
#define __gewitextfield_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

/*!
    \brief GTextField class for basic text input area.

    GTextField simple text input area widget, derived from GWidget.
**/
class GTextField : public GWidget
{
    protected:
        //! Text currently entered.
        string rText;
        //! Text buffer, used internally.
        ZImage rBuffer;
        //! Font for text.
        ResourceID rFont;
        //! Background for text input area.
        ResourceID rBackground;
        //! Maximum number of characters allowed to be entered.
        int rMaxChars;
        //! Amount of padding on left hand side.
        int rLeftPadding;

    public:
        /*!
            \brief Simple constructor for GTextField.

            Constructor for GTextField, can take a parent.
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GTextField(GContainer *parent=NULL);

        /*!
            \brief GButton's create function, must be called to set up actual button.

            Every widget has a create function which must be called to define the button's appearance and settings.
            \param x X position of widget within it's container (entire screen if no parent)
            \param y Y position of widget within it's container (entire screen if no parent)
            \param width Width of widget.
            \param height Height of widget.
            \param font Font for text.
            \param backgroundImg Image for text input box.
            \param maxChars Maximum number of characters to be entered, defaults to 256.
            \param leftPad padding on left side, defaults to zero.
        **/
        virtual void Create(float x, float y, float width, float height, ResourceID font, ResourceID backgroundImg, int maxChars=256, int leftPad=0);

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
            \brief Draws the text input area & text to the screen.

            Draws widget to the screen, required overload for all widgets.
        **/
        virtual void Show();

        /*!
            \brief Set text in input area.

            Sets the current text of the buffer for input area.
            \param text New text for button.
        **/
        void SetText(string text);

        /*!
            \brief Get current text of the input box.
            
            Return text in the input buffer.
            \return text currently in input buffer.
        **/
        string GetText();
};

}

#endif //__gewiewitextfield_h__
