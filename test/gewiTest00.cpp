/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "ZEngine.h"
#include "GewiEngine.h"
#include "GewiButton.h"
#include "GewiTextButton.h"
#include "GewiWindow.h"
#include "GewiTextField.h"
#include "GewiSlider.h"
#include "GewiStaticText.h"
using namespace ZE;
using namespace Gewi;

void Init()
{
    ZEngine *ze = ZEngine::GetInstance();

    ZConfigFile cfg("gewiTest.zcf");
    int w,h,bpp;
    bool fs;
    string title;

    w = cfg.GetInt("screen","width",800);
    h = cfg.GetInt("screen","height",600);
    bpp = cfg.GetInt("screen","bpp",32);
    fs = cfg.GetBool("screen","fullscreen",false);
    title = cfg.GetString("screen","title","Gewi Test");

    ze->SetupDisplay(w,h,bpp,fs);
    ze->CreateDisplay(title);
}

void Test1()
{
    ZEngine *ze = ZEngine::GetInstance();
    GewiEngine *gewi = GewiEngine::GetInstance();
    ZImage bg("data/rainbow.bmp"),buf;
    ResourceID id1,id2,id3,id4,id5,id6,id7,id8,id9;
    GWindow w1;
    GTextButton tb1;    
    GTextField t1,t2(&w1);
    GButton b1(&w1);
    GHorizSlider s1;
    GVertSlider s2;
    GButton hb1(&w1);
    GStaticText st1;

    bg.Resize(800,600);

    ZImage *temp,*temp2,*temp3,*temp4,*temp5,*temp6,*temp7,*temp8;
    ZFont *font;
    temp = new ZImage("data/b1.bmp");
    temp2 = new ZImage("data/b2.bmp");
    temp3 = new ZImage("data/skin1.bmp");
    temp4 = new ZImage("data/text.bmp");
    temp5 = new ZImage("data/bg3.bmp");
    temp6 = new ZImage("data/slider.bmp");
    temp7 = new ZImage("data/bg4.bmp");
    temp8 = new ZImage("data/slider2.bmp");
    font = new ZFont("c:\\windows\\fonts\\arial.ttf",20);
    temp->SetColorKey(255,0,255);
    temp2->SetColorKey(255,0,255);
    temp3->SetColorKey(255,0,255);
    id1 = gewi->AddResource(temp);
    id2 = gewi->AddResource(temp2);
    id3 = gewi->AddResource(temp3);
    id4 = gewi->AddResource(font);
    id5 = gewi->AddResource(temp4);
    id6 = gewi->AddResource(temp5);
    id7 = gewi->AddResource(temp6);
    id8 = gewi->AddResource(temp7);
    id9 = gewi->AddResource(temp8);
    temp4->SetColorKey(255,0,255);
    temp6->SetColorKey(255,0,255);
    temp8->SetColorKey(255,0,255);

    w1.Create(300,300,300,300,id3);
    b1.Create(50,30,10,10,id1,id2);
    t1.Create(100,100,500,50,id4,id5,20,20);
    t2.Create(50,200,200,50,id4,id5,20,20);
    tb1.Create(400,200,300,50,id1,id2,id4,"restore window");
    s1.Create(100,500,200,50,id6,id7,0,3,1);
    s2.Create(700,200,50,200,id8,id9,0,200,5);
    hb1.Create(70,40,100,100,id1,id2,G_HOVER);
    st1.Create(100,100,100,100,id4,Gewi::GewiEngine::InvalidID,"static",GJ_CENTER);

    do
    {
        ze->CheckEvents();

        if(ze->IsActive())
        {
            if(ze->KeyIsPressed(SDLK_ESCAPE))
                ze->RequestQuit();

            font->DrawText(FormatStr("%f",s1.GetPos()),buf);
            bg.Draw(0,0);
            temp3->SetAlpha(63+s1.GetPos()*64);
            gewi->Display();

            buf.Draw(0.0f,s2.GetPos());
            
            if(b1.IsPressed() && w1.Visible())
            {
                w1.ToggleVisible();
                tb1.SetState(false);
                b1.SetState(false);
            }
            if(tb1.IsPressed() && !w1.Visible())
            {
                w1.ToggleVisible();
                b1.SetState(false);
                tb1.SetState(false);
            }
            if(hb1.IsPressed())
                ze->RequestQuit();

            ze->Update();
            
        }

    } while(!ze->QuitRequested());

    GewiEngine::ReleaseInstance();
}

int main(int argc, char *argv[])
{
//    _crtBreakAlloc=163;
    Init();
    
    Test1();

    ZEngine::ReleaseInstance();
    _CrtDumpMemoryLeaks();
    return 0;
}