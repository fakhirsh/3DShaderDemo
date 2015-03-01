

#include "EMCGlue.h"

//#include <string>
//#include <sstream>
//#include <stdlib.h>
#include <stdio.h>

#include <Common.h>
#include <System/App.h>
#include <System/SystemConfig.h>
#include <ResourceCache/IOManagerDefault.h>
#include <Renderer/GLES20/RendererGLES20.h>


using namespace Fakhir;
App * gApp;

namespace EMCGlue
{
    bool Init(int width, int height)
    {
        printf("EMCGlueGlue.cpp: Width = %d: --- Height = %d:\n", width, height);
        
        Fakhir::SystemConfig sysConfig;
        
        // Get bundle root directory.
        //gApp->SetBundlePath("Assets/");
        
        sysConfig.assetPath = "Assets/";
        
        sysConfig.renderer = new Fakhir::RendererGLES20();
        
        sysConfig.ioManager = new Fakhir::IOManagerDefault();
        vector<char> buffer;
        string sysConfXMLPath = sysConfig.assetPath + "Config/SystemConfig.xml";
        sysConfig.ioManager->GetAssetStream(sysConfXMLPath, buffer);
        sysConfig.LoadConfig(buffer);
        
        sysConfig.frameBufferWidth = width;
        sysConfig.frameBufferHeight = height;
        sysConfig.logicalWidth = width;
        sysConfig.logicalHeight = height;
        sysConfig.deviceContentScaleFactor = 1.0f;
        
        gApp = new App();
        
        if (!gApp->Init(&sysConfig))
        {
            std::cout << "------------------ Error initialising game engine -----------------" << std::endl;
            return false;
        }

        
        return true;
    }
    
    clock_t prev_t;
    
    void Tick()
    {
        clock_t t = clock();
        float dt = float(t - prev_t)/CLOCKS_PER_SEC;
        
        //std::cout << "dt: " << dt << std::endl;
        
        gApp->Tick(dt);
        
        prev_t = t;
    }
    
    void Shutdown()
    {
    
    }
    
    void MouseDown(float x, float y)
    {
        gApp->TouchDown(x, y);
    }
    
    void MouseMoved(float x, float y)
    {
        gApp->TouchMoved(x, y);
    }
    
    void MouseUp(float x, float y)
    {
        gApp->TouchUp(x, y);
    }
    
    void MouseCancelled(float x, float y)
    {
    
    }
    
};

