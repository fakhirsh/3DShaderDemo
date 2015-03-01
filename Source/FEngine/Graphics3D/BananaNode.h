//
//  BananaNode.h
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "SceneNode3D.h"

namespace Fakhir
{
    class BananaNode : public SceneNode3D
    {
    public:
        BananaNode();
        ~BananaNode();
        
        virtual bool PreRender      (float dt = 0.0f);
        virtual bool Render         (float dt = 0.0f);
        virtual bool PostRender     (float dt = 0.0f);
        
    private:
        
    };
}