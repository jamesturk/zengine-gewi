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

#ifndef __gewiwidgetlist_h__
#define __gewiwidgetlist_h__

#include "GewiIncludes.h"

namespace Gewi
{

class GWidget;

class WidgetNode
{
    public:
        WidgetNode();
        GWidget *widget;
        WidgetNode *prev;
        WidgetNode *next;
};

class WidgetList
{
    private:
        WidgetNode *mWidgetList;
        WidgetNode *mClick;

        void DeleteWidgetMem(WidgetNode *node);
    public:
        WidgetList();

        void AddWidget(WidgetNode *node);
        void DeleteWidget(GWidget *widget);
        void DeleteWidgets();
        
        void Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        void FitParent();
        void ShowWidgets();      
};

}

#endif //__gewiwidgetlist_h__
