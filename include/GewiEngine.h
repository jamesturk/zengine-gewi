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
    <br>$Id: GewiEngine.h,v 1.7 2003/06/11 00:19:40 cozman Exp $<br>
    \author James Turk
**/

#ifndef __gewiengine_h__
#define __gewiengine_h__

#include "GewiIncludes.h"
#include "GewiWidgetList.h"


/*!
    \brief Gewi Namespace.
    
    Namespace for all Gewi classes and utility functions.
**/
namespace Gewi
{


/*!
    \brief Main GewiEngine Singleton Class

    GewiEngine Singleton Class, accessible from anywhere in a program via GetInstance.  Contains widgets in global context
    (those drawn in relation to screen, with a NULL parent) also handles resource management of fonts and images.
**/
class GewiEngine
{
    public:
        //! Static version information.
        static VersionInfo Version;
        //! Required ZEngine version.
        static VersionInfo MinZEVersion;

    private:
        //! Singleton static instance of GewiEngine.
        static GewiEngine *sInstance;
        //! Vector of pointers to ZImages, used by resource management system.
        std::vector<ZE::ZImage*> mImageVec;
        //! Vector of pointers to ZFonts, used by resource management system.
        std::vector<ZE::ZFont*> mFontVec;
        //! List of widgets in global context.
        WidgetList mWidgetList;

    //singleton setup//
    private:
        /*!
            \brief GewiEngine constructor, private due to singleton design.

            Initializes GewiEngine instance variables, can only be called once per run of program due to design.
        **/
        GewiEngine();

    public:
        //! Static variable used to represent invalid IDs (before an ID has been assigned all resourceIDs should == InvalidID).
        static const ResourceID InvalidID = UINT_MAX;    //UINT_MAX b/c many compilers don't like numeric_limits
        
        /*!
            \brief Get the static instance of GewiEngine.

            Important key to the singleton's design, gets the static instance stored within. Creates static instance on first call.
            \return Pointer to static instance of GewiEngine.
        **/

        static GewiEngine* GetInstance();

        /*!
            \brief Release static instance.

            Releases the instance of GewiEngine, basically only called at very end of program.
        **/
        static void ReleaseInstance();

    //utilities//

        /*!
            \brief Static event filter, defined to SDL specifications.

            Replaces SDL default event filter, and filters events into static GewiEngine instance.
            \param event SDL_Event to handle.
            \return Return values specified by SDL.
        **/
        static int EventFilter(SDL_Event *event);

        /*!
            \brief Translate an SDL structure into a character, used by EventFilter.

            Converts SDL_keysym into a standard char, only works for certain meaningful keys.
            \param key SDL_keysm structure to convert.
            \return Converted character.
        **/
        static char TranslateKey(SDL_keysym key);

        /*!
            \brief Draw all widgets in the Gewi system.

            Draws all top level widgets and containers, container widgets are expected to draw their own children.
        **/
        void Display();

    //resource management//

        /*!
            \brief Adds an image resource to the private vector.

            Add a ZImage to the private vector of images and assign it a ResourceID.
            \param image Image to add to resources.
            \return ID number of new resource.
        **/
        ResourceID AddResource(ZE::ZImage *image);

        /*!
            \brief Adds a font resource to the private vector.

            Add a ZFont to the private vector of fonts and assign it a ResourceID.
            \param font Font to add to resources.
            \return ID number of new resource.
        **/
        ResourceID AddResource(ZE::ZFont *font);

        /*!
            \brief Access an image in the resource vector.

            Given the images ID get a pointer to an image stored in the image vector.
            \param id ID of image to retrieve.
            \return Pointer to image or NULL if invalid ID for images.
        **/
        ZE::ZImage* Image(ResourceID id);

        /*!
            \brief Access a font in the resource vector.

            Given the fonts ID get a pointer to a font stored in the font vector.
            \param id ID of font to retrieve.
            \return Pointer to font or NULL if invalid ID for fonts.
        **/
        ZE::ZFont* Font(ResourceID id);

        /*!
            \brief Free all resources.

            Frees memory for all resources.
        **/
        void FreeResources();

    //widget management//
    private:
        /*!
            \brief Inserts a child to the child list.

            Calls needed function of WidgetList class to put widget into the linked list.
            \param node WidgetNode to insert into mWidgetList.
        **/
        void InsertWidget(WidgetNode *node);

    public:
        /*!
            \brief Register a widget, adding it to the list of widgets.

            Add a widget to the list of widgets, all widgets register themselves.
            \param widget Widget to register.
        **/
        void Register(GWidget *widget);

        /*!
            \brief Send a message to the widgets, this function will decide which widgets the message is relevant to.

            Send a message to the widgets, this function will decide which widgets the message is relevant to.
            This generally isn't called by the client of GewiEngine, instead the EventFilter hook on events will filter
            and process.  This can be used to fake an event however.
            \param rawEvent SDL_Event of original message, may be needed if more information is available on event. (May be NULL).
            \param event GewiEvent enum, description of event recieved.
            \param mouseX Mouse x position in event, if not mouse event may be incorrect.
            \param mouseY Mouse y position in event, if not mouse event may be incorrect.
            \param ch Character pressed in event, may be 0 if not a keypress event.
        **/
        void SendMessage(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch);

        /*!
            \brief Delete a widget.

            This deletes a widget and memory associated with that widget, like register, widgets do this for themselves.
            \param widget to delete
        **/
        void DeleteWidget(GWidget *widget);
};

}

#endif //__gewiengine_h__
