//
//  ToonNode.h
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "SceneNode3D.h"

namespace Fakhir
{
    class ToonNode : public SceneNode3D
    {
    public:
        ToonNode();
        ~ToonNode();
        
        virtual bool PreRender      (float dt = 0.0f);
        virtual bool Render         (float dt = 0.0f);
        virtual bool PostRender     (float dt = 0.0f);
        
    private:
        
    };
}