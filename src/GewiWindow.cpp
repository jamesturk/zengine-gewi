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

#include "GewiWindow.h"

namespace Gewi
{

GWindow::GWindow() : 
    GContainer(),
    rDrag(false),
    rDragX(0),
    rDragY(0),
    rBackground(GewiEngine::InvalidID)
{}

void GWindow::Create(float x, float y, float width, float height, ResourceID backgroundImg)
{
    GWidget::Create(x,y,width,height);
    rBackground = backgroundImg;
}

void GWindow::Message(SDL_Event *rawEvent, GewiEvent event, Uint16 mouseX, Uint16 mouseY, char ch)
{
    if(event == GE_LDOWN)
    {
        //keep dragging window while mouse is down
        rDrag = true;
        rDragX = rBoundRect.X()-mouseX;
        rDragY = rBoundRect.Y()-mouseY;
    }
    else if(event == GE_LUP)
    {
        //release mouse-drag and actually move window
        Move(rZE->MouseX()+rDragX,rZE->MouseY()+rDragY);
        rDrag = false;
        rDragX = rDragY = 0;
    }
    GContainer::Message(rawEvent,event,mouseX,mouseY,ch);  //send to children
}

void GWindow::Show()
{
    if(rVisible)
    {   
        if(rDrag)
        {
            Move(rZE->MouseX()+rDragX,rZE->MouseY()+rDragY);    //draw at dragged position if mouse is held
            if(!rZE->LButtonPressed())
                rDrag = false;
        }

        //resize (shared resources) and draw
        rGewi->Image(rBackground)->Resize(static_cast<unsigned int>(rBoundRect.Width()),static_cast<unsigned int>(rBoundRect.Height()));
        rGewi->Image(rBackground)->Draw(rBoundRect.X(),rBoundRect.Y());

        GContainer::Show();    //important that a window draws it's children
    }
}

}
