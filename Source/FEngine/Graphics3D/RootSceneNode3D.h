//
//  RootSceneNode3D.h
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../Common.h"
#include "SceneNodeProperties3D.h"
#include "SceneNode3D.h"

namespace Fakhir
{
    class RootSceneNode3D : public SceneNode3D
    {
    public:
        RootSceneNode3D();
        ~RootSceneNode3D();
        
        std::vector<SceneNodeProperties3D> snpStack;
        std::vector<glm::mat4> transformationStack;
        
    private:
        
    };
}