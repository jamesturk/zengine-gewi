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
    <br>$Id: GewiTextButton.h,v 1.3 2003/05/19 23:56:05 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewitextbutton_h__
#define __gewitextbutton_h__

#include "GewiEngine.h"
#include "GewiButton.h"

namespace Gewi
{

class GTextButton : public GButton
{
    protected:
        string rText;
        ZImage rTextBuf;
        int rXOff,rYOff;
        ResourceID rFont;
    public:
        GTextButton(GContainer *parent=NULL);

        virtual void Create(float x, float y, float width, float height, ResourceID normalImg, ResourceID pressImg, ResourceID font,
            string text=" ", GButtonType type=G_PRESS);
        virtual void Show();

        void SetText(string text);
        string GetText();
};

}

#endif //__gewitextbutton_h__
