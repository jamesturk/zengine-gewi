/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiStaticText.h
    \brief Definition file for GStaticText.
    
    Definition file for GStaticText, file to hold static text, labels and such.
    <br>$Id: GewiStaticText.h,v 1.5 2003/06/11 00:19:40 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewistatictext_h__
#define __gewistatictext_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

/*!
    \brief GStaticText for stationary labels.

    GStaticText, stationary label class, derived from GWidget.
**/
class GStaticText : public GWidget
{
    protected:
        //! Image for background of label (often no image).
        ResourceID rBackgroundImage;
        //! Font to use for label.
        ResourceID rFont;
        //! Current text of label.
        std::string rText;
        //! Text buffer ZImage, used internally.
        ZE::ZImage rTextBuf;
        //! Calculated X Offset for text, calculated from justification.
        int rXOff;
        //! Calculated Y Offset for text, calculated from justification.
        int rYOff;
        //! Justification, can be or'ed together enums from _GewiJustify, see documentation of that enum for details.
        GewiJustify rJustify;
    public:
        /*!
            \brief Simple constructor for GStaticText.

            Constructor for GStaticText, can take a parent.
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GStaticText(GContainer *parent=NULL);

        /*!
            \brief GButton's create function, must be called to set up actual button.

            Every widget has a create function which must be called to define the button's appearance and settings.
            \param x X position of widget within it's container (entire screen if no parent)
            \param y Y position of widget within it's container (entire screen if no parent)
            \param width Width of widget.
            \param height Height of widget.
            \param font Font ID for text.
            \param text Text for static label. (Defaults to a blank space.)
            \param just Justification, see documented _GewiJustify for details. Defaults to GJ_CENTER.
            \param backgroundImg Image for background, defaults to GewiEngine::InvalidID.
        **/
        virtual void Create(float x, float y, float width, float height, 
            ResourceID font, std::string text=" ", GewiJustify just=GJ_CENTER, ResourceID backgroundImg=GewiEngine::InvalidID);

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
            \brief Draws static label to the screen.

            Draws static label to the screen, required overload for all widgets.
        **/
        virtual void Show();

        /*!
            \brief Set text of label.

            Sets the current text of the label.
            \param text New text for label.
        **/
        void SetText(std::string text);

        /*!
            \brief Get current text in label.
            
            Return text in label.
            \return text currently in label.
        **/
        std::string GetText();
};

}

#endif //__gewistatictext_h__
