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
    rZE(ZEngine::GetInstance()),
    rParent(parent),
    rRelX(0),
    rRelY(0),
    rVisible(true),
    rAlive(true)
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

void GWidget::Kill()
{
    if(rParent)
    {
        rParent->ReleaseChild(this);
        rParent = NULL;
    }
    else
        rGewi->DeleteWidget(this);

    //rChildList.DeleteWidgets();
    rAlive = rVisible = false;
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
