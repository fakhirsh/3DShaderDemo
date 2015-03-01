//
//  SceneNodeProperties3D.h
//  Game
//
//  Created by Fakhir Shaheen on 28/02/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../Common.h"

namespace Fakhir
{
    struct SceneNodeProperties3D
    {
        SceneNodeProperties3D();
        
        unsigned int _actorID;
        std::string _name;
        
        float x, y, z;
        float angleX, angleY, angleZ;
        float scaleX, scaleY, scaleZ;
        
        //int zOrder;
        
        class Program * program;
        class Texture * texture;
    };
}