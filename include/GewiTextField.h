/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file ZE_ZConfigFile.h
    \brief Definition file for ZConfigFile.
    
    Definition file for ZConfigFile, an INI-style config file format.
    <br>$ id: ZE_ZConfigFile.h,v 1.9 2003/02/10 04:40:16 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewitextfield_h__
#define __gewitextfield_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

class GTextField : public GWidget
{
    protected:
        string rText;
        ZImage rBuffer;
        ResourceID rFont;
        ResourceID rBackground;
        int rMaxChars,rLeftPadding;
    public:
        GTextField(GContainer *parent=NULL);
        ~GTextField();

        void Kill();

        virtual void Create(float x, float y, float width, float height, ResourceID font, ResourceID backgroundImg, int maxChars=256, int leftPad=0);
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        virtual void Show();

        void SetText(string text);
        string GetText();
};

}

#endif //__gewiewitextfield_h__
