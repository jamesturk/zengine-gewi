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

#ifndef __gewiincludes_h__
#define __gewiincludes_h__

#include <vector>
#include <cmath>
#include <limits>
#include "ZEngine.h"
typedef unsigned int WidgetID;
typedef unsigned int ResourceID;
enum GewiEvent { GE_LDOWN, GE_LUP, GE_RDOWN, GE_RUP, GE_KDOWN, GE_KUP, GE_GOTFOCUS, GE_LOSTFOCUS };
enum _GewiJustify { GJ_CENTER = 0, GJ_LEFT = 1<<0, GJ_RIGHT = 1<<1, GJ_TOP = 1<<2, GJ_BOTTOM = 1<<3 };
enum GButtonType { G_PRESS, G_HOVER };
typedef unsigned int GewiJustify;
using namespace std;
using namespace ZE;

#endif //__gewiincludes_h__