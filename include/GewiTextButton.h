/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiTextButton.h
    \brief Definition file for GTextButton.
    
    Definition file for GTextButton, a GButton that has a text label.
    <br>$Id: GewiTextButton.h,v 1.4 2003/06/07 05:41:18 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewitextbutton_h__
#define __gewitextbutton_h__

#include "GewiEngine.h"
#include "GewiButton.h"

namespace Gewi
{

/*!
    \brief GTextButton class for button with text label.

    GTextButton text label button widget, derived from GButton.
**/
class GTextButton : public GButton
{
    protected:
        //! Text label for button.
        string rText;
        //! Text Buffer, used internally.
        ZImage rTextBuf;
        //! X offset of text.
        int rXOff;
        //! Y offset of text.
        int rYOff;
        //! Font ID for text label.
        ResourceID rFont;

    public:
        /*!
            \brief Simple constructor for GButton.

            Constructor for GButton, can take a parent.
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GTextButton(GContainer *parent=NULL);

        /*!
            \brief GButton's create function, must be called to set up actual button.

            Every widget has a create function which must be called to define the button's appearance and settings.
            \param x X position of widget within it's container (entire screen if no parent)
            \param y Y position of widget within it's container (entire screen if no parent)
            \param width Width of widget.
            \param height Height of widget.
            \param normalImg Image for button when not pressed.
            \param pressImg Image for button when pressed (or hovered if type is GBT_HOVER).
            \param font Font to draw label with.
            \param text Text for button. (default is blank)
            \param type GButtonType, either the default, GBT_PRESS (normal button), or GBT_HOVER (a button which responds to the hovering mouse).
        **/
        virtual void Create(float x, float y, float width, float height, ResourceID normalImg, ResourceID pressImg, ResourceID font,
            string text=" ", GButtonType type=GBT_PRESS);
        
        /*!
            \brief Draws static label to the screen.

            Draws static label to the screen, required overload for all widgets.
        **/
        virtual void Show();

        /*!
            \brief Set text of button.

            Sets the current text of the button.
            \param text New text for button.
        **/
        void SetText(string text);

        /*!
            \brief Get current text of button label.
            
            Return text on button label.
            \return text currently on button label.
        **/
        string GetText();
};

}

#endif //__gewitextbutton_h__
