//
//  SceneNode3D.h
//  Game
//
//  Created by Fakhir Shaheen on 28/02/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../Common.h"
#include "SceneNodeProperties3D.h"

namespace Fakhir
{
    //typedef std::vector<class SceneNode3D *>  SceneNode3DList;
    
    class Scene3D;
    
    class SceneNode3D
    {
    public:
        SceneNode3D();
        ~SceneNode3D();
        
        virtual bool PreRender      (float dt = 0.0f);
        virtual bool Render         (float dt = 0.0f);
        virtual bool RenderChildren (float dt = 0.0f);
        virtual bool PostRender     (float dt = 0.0f);
        
        virtual bool Update(float dt);
        
        bool Add(SceneNode3D * child);
        bool Remove(SceneNode3D * child);
        
        void SetSceneNodeProperties(SceneNodeProperties3D & sceneNodeProp);
        SceneNodeProperties3D * GetSceneNodeProperties();
        
        void SetParent(SceneNode3D * parent);
        SceneNode3D * GetParent();
        
    protected:
        SceneNodeProperties3D _sceneNodeProp;
        std::vector< SceneNode3D * > _children;
        SceneNode3D * _parent;
    };
    
};
