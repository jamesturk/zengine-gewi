/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiSlider.h
    \brief Definition file for GSlider, GHorizSlider and GVertSlider.
    
    Definition file for GSlider, GHorizSlider and GVertSlider, the slide-select classes for Gewi.
    <br>$Id: GewiSlider.h,v 1.4 2003/06/07 05:41:18 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewislider_h__
#define __gewislider_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

/*!
    \brief GSlider (virtual) slider widget class.

    Framework for simple slider widget, virtual (fails to overload Show), derived from GWidget.
**/
class GSlider : public GWidget
{
    protected:
        //! Boolean value holding if slider is currently 'pressed' or active.
        bool rPressed;
        //! ID for background image for slider.
        ResourceID rBackground;
        //! Image ID for the sliding part of the slider.
        ResourceID rSlider;
        //! Minimum position for slider.
        float rMin;
        //! Maximum position for slider.
        float rMax;
        //! Current position of slider.
        float rPos;
        //! Movement snap increment.
        int rIncrement;

    public:
        /*!
            \brief Simple constructor for GSlider.

            Default constructor for GSlider, can take a parent.
            \param parent Pointer to GContainer derived class to be the parent.  Default value is NULL which means no parent.
        **/
        GSlider(GContainer *parent=NULL);

        /*!
            \brief GSlider's create function, must be called to set up actual slider.

            Every widget has a create function which must be called to define the button's appearance and settings.
            \param x X position of widget within it's container (entire screen if no parent)
            \param y Y position of widget within it's container (entire screen if no parent)
            \param width Width of widget.
            \param height Height of widget.
            \param backgroundImg Image for stationary portion of slider.
            \param sliderImg Image for moving portion of slider.
            \param min Minimum value on slider.
            \param max Maximum value on slider.
            \param increment Slider snap-to increment.
        **/
        virtual void Create(float x, float y, float width, float height, ResourceID backgroundImg, ResourceID sliderImg, 
            float min, float max, int increment);

        /*!
            \brief Set position of slider.

            Sets position of slider, will snap within bounds.
            \param pos Desired position.
        **/
        void SetPos(float pos);

        /*!
            \brief Get position of slider.

            Access current position of slider.
            \return Slider position.
        **/
        float GetPos();
};

/*!
    \brief GHorizSlider, horizontal slider widget class.

    Derived from GSlider, overloads message and show to complete the class.
**/
class GHorizSlider : public GSlider
{
    public:
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
            \brief Draws this slider to the screen.

            Draws widget to the screen, required overload for all widgets.
        **/
        virtual void Show();
};

/*!
    \brief GHorizSlider, horizontal slider widget class

    Derived from GSlider, overloads message and show to complete the class.
**/
class GVertSlider : public GSlider
{
    public:
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
            \brief Draws this slider to the screen.

            Draws widget to the screen, required overload for all widgets.
        **/
        virtual void Show();
};

}

#endif //__gewislider_h__
