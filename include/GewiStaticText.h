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
    <br>$Id: GewiStaticText.h,v 1.3 2003/05/19 23:56:05 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewistatictext_h__
#define __gewistatictext_h__

#include "GewiEngine.h"
#include "GewiWidget.h"

namespace Gewi
{

class GStaticText : public GWidget
{
    protected:
        ResourceID rBackgroundImage;
        ResourceID rFont;
        string rText;
        ZImage rTextBuf;
        int rXOff,rYOff;
        GewiJustify rJustify;
    public:
        GStaticText(GContainer *parent=NULL);

        virtual void Create(float x, float y, float width, float height, 
            ResourceID font, ResourceID backgroundImg=GewiEngine::InvalidID, string text=" ", GewiJustify just=GJ_CENTER);
        virtual void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        virtual void Show();

        void SetText(string text);
        string GetText();
};

}

#endif //__gewistatictext_h__
