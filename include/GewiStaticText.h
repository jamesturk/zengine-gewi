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
