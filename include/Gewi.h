/*!
    \file Gewi.h
    \brief Header file for Gewi.

    Header file for the Gewi GUI lib, an addon for the ZEngine Game Engine, both from Concept of Zero, this is the 
    file that programs that wish to use should include.
    <br>$Id: Gewi.h,v 1.5 2003/08/10 01:43:18 cozman Exp $<br>
    \author James Turk
**/

/*!
    \mainpage Gewi Documentation

    \author James Turk
    \version 0.2.0
    \date July 12th, 2003

    \section Gewi About ZEngine and Gewi
    <br>
    &nbsp;&nbsp;&nbsp;&nbsp;-ZEngine is designed to provide a powerful yet easy to use 2D game engine in a well designed 
    Object Oriented manner, and uses cross platform libraries such as SDL and OpenGL. (ZEngine can use SDL_ttf,SDL_image,
    SDL_mixer, and PhysFS all of which are cross platform as well as Open Source.) Gewi sits neatly on top of ZEngine and
    is written in much the same style, Gewi is designed to be the GUI portion of ZEngine but grew so large it needed to become
    a seperate project.<br>
    &nbsp;&nbsp;&nbsp;&nbsp;-Both are licensed under a BSD-style license, and anyone is free to suggest or implement changes 
    to be added to either, as well as modify ZEngine or Gewi to fit their own needs or use it however they like.<br>
    &nbsp;&nbsp;&nbsp;&nbsp;-Because Gewi relys so heavily on ZEngine it has no website, if anybody writes a version of Gewi
    that does not use the ZEngine backend I'd be glad to see it and even integrate it with the ZEngine/Gewi source.  Until
    there is some other version, Gewi will always be found right next to ZEngine.<br>
    &nbsp;&nbsp;&nbsp;&nbsp;-The ZEngine website : http://zengine.sourceforge.net/.<br>
    
    \section Licensing Licensing
    <br>
<pre>            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
    </pre>
    \section Authors Contributing Authors
    <br>
    James Turk <a href="mailto:james@conceptofzero.net">james@conceptofzero.net</a> - Core Engine, Design, Docs, and Classes<br>
    Atani <a href="mailto:atani@atani-software.net">atani@atani-software.net</a> - Revised Linux Build System<br>
**/

#ifndef __gewi_h__
#define __gewi_h__

#include "GewiIncludes.h"
#include "GewiDefines.h"
#include "GewiContainer.h"
#include "GewiButton.h"
#include "GewiEngine.h"
#include "GewiSlider.h"
#include "GewiStaticText.h"
#include "GewiTextButton.h"
#include "GewiTextField.h"
#include "GewiWindow.h"

#endif //__zengine_h__
