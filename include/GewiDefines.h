/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiDefines.h
    \brief Define file for Gewi where enumerations, typedefs and #define statements are placed.

    Definition file, holds enumerations and typedefs which need to be accessed by many files within Gewi.
    <br>$id$<br>
    \author James Turk
**/

#ifndef __gewidefines_h__
#define __gewidefines_h__

namespace Gewi
{

//! Resources are stored centrally and widgets access them by their ResourceID.
typedef unsigned int ResourceID;
//! GewiJustify is a hack so that members of the _GewiJustify enum can be or'ed (|) together.
typedef unsigned int GewiJustify;

/*!
    \brief Enumeration for basic events that a widget can handle.

    Defines names for specific events that are filtered and given to widgets.
**/
enum GewiEvent
{ 
    GE_LDOWN,       /*!< Left mouse button pressed event. */
    GE_LUP,         /*!< Left mouse button released event. */
    GE_RDOWN,       /*!< Right mouse button pressed event. */
    GE_RUP,         /*!< Right mouse button released event. */
    GE_KDOWN,       /*!< Key pressed. */
    GE_KUP,         /*!< Key released. */
    GE_GOTFOCUS,    /*!< Widget got focus. */
    GE_LOSTFOCUS    /*!< Widget lost focus. */
};

/*!
    \brief Describess justification options in text buttons and static fields.

    Justification options in text buttons and static fields, these values can be or'ed 
    together via the typedef GewiJustify.  For example GJ_LEFT|GJ_TOP would position the
    label in the upper left corner. GJ_RIGHT|GJ_CENTER would be in the vertical center of 
    the box, yet justified to the right on the horizontal axis.
**/
enum _GewiJustify
{ 
    GJ_CENTER = 0,      /*!< Center text. */
    GJ_LEFT =   1<<0,   /*!< Align text to the left. */
    GJ_RIGHT =  1<<1,   /*!< Align text to the right. */
    GJ_TOP =    1<<2,   /*!< Position text to the top. */
    GJ_BOTTOM = 1<<3    /*!< Position text to the bottom. */
};

};

#endif //__gewidefines_h__
