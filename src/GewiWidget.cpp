/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

/*!
    \file GewiWidget.cpp
    \brief Implementation of GWidget.
    
    Implementation of GWidget, virtual widget base class.
    <br>$Id: GewiWidget.cpp,v 1.6 2003/06/11 00:19:29 cozman Exp $<br>
    \author James Turk
**/

#include "GewiWidget.h"
#include "GewiEngine.h"
#include "GewiContainer.h"

namespace Gewi
{

void GWidget::FitParent()   //adjust to relative pos + parent pos
{
    if(rParent)
        rBoundRect.Move(rRelX+rParent->X(),rRelY+rParent->Y());
    else
        rBoundRect.Move(rRelX,rRelY);
}

GWidget::GWidget(GContainer *parent) :
    rGewi(GewiEngine::GetInstance()),
    rZE(ZE::ZEngine::GetInstance()),
    rParent(parent),
    rRelX(0),
    rRelY(0),
    rVisible(true)
{
    if(rParent)
        rParent->AddChild(this);
    else
        rGewi->Register(this);
}

GWidget::~GWidget()
{
}

void GWidget::ToggleVisible()
{
    rVisible = !rVisible;
}

void GWidget::Create(float x, float y, float width, float height)
{
    Move(x,y);
    rBoundRect.Resize(width,height);
    rVisible = true;
}

void GWidget::Move(float x, float y)
{
    rRelX = x;
    rRelY = y;
    FitParent();    //use relative x and relative y to position this inside the parent
}

float GWidget::X()
{
    return rBoundRect.X();
}

float GWidget::Y()
{
    return rBoundRect.Y();
}

bool GWidget::Visible()
{
    return rVisible;
}

bool GWidget::MouseInWidget()
{
    return rZE->MouseInRect(&rBoundRect.SDLrect());
}

bool GWidget::Contains(Sint16 x, Sint16 y)
{
    return rBoundRect.Contains(static_cast<float>(x), static_cast<float>(y));
}

}
