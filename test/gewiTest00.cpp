/*******************************************************************************
            This file is Part of the Gewi GUI Library for ZEngine.
             Gewi and ZEngine Copyright (C) 2002, 2003 James Turk

            Licensed under a BSD-style license. (see licensing.txt)

    The maintainer of this library is James Turk (james@conceptofzero.net) 
  this library is found at the home of ZEngine http://zengine.sourceforge.net
*******************************************************************************/

#include "ZEngine.h"
#include "Gewi.h"
#include <string>
using namespace ZE;
using namespace Gewi;

void Init()
{
    ZEngine *ze = ZEngine::GetInstance();

    ZConfigFile cfg("gewiTest.zcf");
    int w,h,bpp;
    bool fs;
    std::string title;

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

    ZImage bg,temp[8];
    ZFont font;
    ResourceID id[8],fontID;
    //all of the widgets//
    GWindow window;
    GTextButton txtButton;
    GTextField txtField,txtField2(&window);
    GButton button(&window);
    GHorizSlider hSlider;
    GVertSlider vSlider;
    GButton hoverButton(&window);
    GStaticText label;
    
    bg.Open("data/rainbow.bmp");
    bg.Resize(ze->DisplayWidth(),ze->DisplayHeight());

    //opening the images//
    temp[0].Open("data/b1.bmp");
    temp[1].Open("data/b2.bmp");
    temp[2].Open("data/skin1.bmp");
    temp[3].Open("data/text.bmp");
    temp[4].Open("data/bg3.bmp");
    temp[5].Open("data/slider.bmp");
    temp[6].Open("data/bg4.bmp");
    temp[7].Open("data/slider2.bmp");
    font.Open("data/axaxax.ttf",20);

    //registering the resources//
    for(int i=0; i < 8; ++i)
    {
        temp[i].SetColorKey(255,0,255);
        id[i] = gewi->AddResource(&temp[i]);
    }
    fontID = gewi->AddResource(&font);

    //each widget must be created//
    window.Create(300,300,300,300,id[2]);
    button.Create(50,30,10,10,id[0],id[1]);
    txtField.Create(100,100,500,50,fontID,id[3],20,20);
    txtField2.Create(50,200,200,50,fontID,id[3],20,20);
    txtButton.Create(400,200,300,50,id[0],id[1],fontID,"restore window");
    hSlider.Create(100,500,200,50,id[4],id[5],0,3,1);
    vSlider.Create(700,200,50,200,id[6],id[7],0,200,5);
    hoverButton.Create(70,40,100,100,id[0],id[1],GBT_HOVER);
    label.Create(100,100,100,100,fontID,"static",GJ_CENTER,GewiEngine::InvalidID);

    do
    {
        ze->CheckEvents();

        if(ze->IsActive())
        {
            if(ze->KeyIsPressed(SDLK_ESCAPE) || hoverButton.IsPressed())
                ze->RequestQuit();

            if( (button.IsPressed() && window.Visible()) || (txtButton.IsPressed() && !window.Visible()) )
            {
                window.ToggleVisible();
                txtButton.SetState(false);
                button.SetState(false);
            }
            temp[2].SetAlpha(static_cast<Uint8>(63+hSlider.GetPos()*64));

            bg.Draw(0,0);
            gewi->Display();    //draws everything 
            ze->Update();
            
        }

    } while(!ze->QuitRequested());
}


int main(int argc, char *argv[])
{
    Init();
    Test1();
    
    GewiEngine::ReleaseInstance();
    ZEngine::ReleaseInstance();

    return 0;
}
