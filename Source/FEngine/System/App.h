//
//  App.h
//  WordGame
//
//  Created by Fakhir Shaheen on 24/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once


/**********************************************************************************
 * App 
 *  |-- This class represents Machine or hardware abstraction.
 *  |-- It can communicate directly with the OS and native API.
 **********************************************************************************/

#include <string>
#include <glm/glm.hpp>

#include "SystemConfig.h"

namespace Fakhir
{
    class IOManager;
    class IRenderer;
    
    class App
    {
    public:
        App();
        ~App();
        
        /**
         * Function: Init(...)
         * Pre-conditions: File manager MUST be initialized and set BEFORE calling Init
         */
        bool Init(const SystemConfig * sysConfig);
        
        void    Tick(float dt);
        
        void    SetDeviceContentScaleFactor(float deviceContentScaleFactor);
        float   GetDeviceContentScaleFactor();
    
        void        SetIOManager(IOManager * fileManager);
        IOManager * GetIOManager();
        
        IRenderer * GetRenderer();
        
        void   SetFrameBufferWidth(float val);
        void   SetFrameBufferHeight(float val);
        //void    SetViewportWidth(float val);
        //void    SetViewportHeight(float val);
        void    SetLogicalWidth(float val);
        void    SetLogicalHeight(float val);
    
        float   GetFrameBufferWidth();
        float   GetFrameBufferHeight();
        float   GetViewportWidth();
        float   GetViewportHeight();
        float   GetLogicalWidth();
        float   GetLogicalHeight();
        float   GetDesignWidth();
        float   GetDesignHeight();
        float   GetContentScaleFactor();
        
        float   GetFPS();
        float   GetMaxFPS();
        
        glm::vec2   GetOrigin();
        float       GetSafeWidth();
        float       GetSafeHeight();
        
        glm::vec2   DesignSpaceToViewportSpace(const glm::vec2 & designSpace);
        glm::vec2   ViewportSpaceToDesignSpace(const glm::vec2 & vpSpace);
        glm::vec2   DesignSpaceToSafeZone(const glm::vec2 & designSpace);
        glm::vec2   SafeZoneToDesignSpace(const glm::vec2 & safeZone);

        //void    SetResourceLoader(FIResourceLoader * resourceLoader);
        
        // Rename these to "***AssetPath()"
        void        SetAssetPath(const char * path);
        std::string GetAssetPath();
        
        void    TouchDown(int x, int y);
        void    TouchUp(int x, int y);
        void    TouchMoved(int x, int y);
        void    TouchCancelled(int x, int y);
        
    private:

        void    Update(float dt);
        void    Render(float dt = 0.0f);

        void    ComputeLetterBoxPolicy();
        
        // Width and Height of the device framebuffer / actual screen
        float   _frameBufferWidth;
        float   _frameBufferHeight;

        // Logical width and height which esp iOS uses for downward compatibility
        float   _logicalWidth;
        float   _logicalHeight;

        // Width and Height of the final "Letter-boxed" gameplay area.
        float   _viewportWidth;
        float   _viewportHeight;
        
        // Actual content scale factor of the device
        float   _deviceContentScaleFactor;
        // Actual aspect ratio of the device
        float   _deviceAspectRatio;
        // "Logical" content scale factor used while rescaling content in Letter box mode
        float   _contentScaleFactor;

        // "Logical" or "Design" width and height
        float   _designWidth;
        float   _designHeight;
        
        // Width and height for which the assets have been optimized...
        float   _assetDesignWidth;
        float   _assetDesignHeight;
        
        glm::vec2   _origin;
        // The "safe zone" within which you can draw sprites without any fear of being cropped.
        struct RECT
        {
            float x, y;
            float width, height;
        };
        RECT  _safeZoneRect;
        
        float   _availableRAM;
        float   _availableStorage;
        float   _cpuSpeed;
        
        float   _elapsed;
        float   _currentFPS;
        float   _maxFPS;
        
        // rename this to "_assetPath"
        std::string  _assetPath;
        
        //FIResourceLoader * _resourceLoader;
        IOManager * _ioManager;
        IRenderer * _renderer;
        // And other system specific crap...
        
    /////////////////////////////////////////

    };
        
};


