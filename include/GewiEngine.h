/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiEngine.h
    \brief Definition file for GewiEngine.
    
    Definition file for GewiEngine, core engine for Gewi GUI control.
    <br>$id$<br>
    \author James Turk
**/

#ifndef __gewiengine_h__
#define __gewiengine_h__

#include "GewiIncludes.h"
#include "GewiWidgetList.h"

namespace Gewi
{

class GewiEngine
{
    private:
        static GewiEngine *sInstance;
        static SDL_EventFilter sOldFilter;
        vector<ZImage*> mImageVec;
        vector<ZFont*> mFontVec;
        WidgetList mWidgetList;

    //singleton setup//
    private:    
        GewiEngine();
    public:
        static const ResourceID InvalidID = UINT_MAX;    //UINT_MAX b/c many compilers don't like numeric_limits
        static GewiEngine* GetInstance();
        static void ReleaseInstance();

    //utilities//    
        static int EventFilter(SDL_Event *event);
        static char TranslateKey(SDL_keysym key);
        void Display();

    //resource management//
        ResourceID AddResource(ZImage *image);
        ResourceID AddResource(ZFont *font);
        ZImage* Image(ResourceID id);
        ZFont* Font(ResourceID id);
        void FreeResources();

    //widget management//
    private:
        void InsertWidget(WidgetNode *node);
    public:
        void Register(GWidget *widget);
        void SendMessage(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);
        void DeleteWidget(GWidget *widget);
};

}

#endif //__gewiengine_h__
