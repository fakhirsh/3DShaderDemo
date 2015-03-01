//
//  SceneNode3D.cpp
//  Game
//
//  Created by Fakhir Shaheen on 28/02/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SceneNode3D.h"


namespace Fakhir
{
    SceneNode3D::SceneNode3D()
    {
        
    }
    SceneNode3D::~SceneNode3D()
    {
        
    }
    
    bool SceneNode3D::PreRender(float dt)
    {
        return true;
    }
    
    bool SceneNode3D::Render(float dt)
    {
        return true;
    }
    
    bool SceneNode3D::RenderChildren(float dt)
    {
        if(_children.size() <= 0) return false;
        
        for(int i = 0; i < _children.size(); i++)
        {
            if(_children[i]->PreRender(dt) == true)
            {
                _children[i]->Render(dt);
                _children[i]->RenderChildren(dt);
            }
            _children[i]->PostRender(dt);
        }
        
        return true;
    }
    
    bool SceneNode3D::PostRender(float dt)
    {
        return true;
    }
    
    bool SceneNode3D::Update(float dt)
    {
        
        for(int i = 0; i < _children.size(); i++)
        {
            _children[i]->Update(dt);
        }
        
        return true;
    }
    
    bool SceneNode3D::Add(SceneNode3D * child)
    {
        child->SetParent(this);
        _children.push_back(child);
        
        return true;
    }
    
    bool SceneNode3D::Remove(SceneNode3D * child)
    {
        for(int i = 0; i < _children.size(); i++)
        {
            if(_children[i] == child)
            {
                _children.erase(_children.begin()+i);
                return true;
            }
        }
        return false;
        
    }
    
    void SceneNode3D::SetSceneNodeProperties(SceneNodeProperties3D & sceneNodeProp)
    {
        _sceneNodeProp = sceneNodeProp;
    }
    
    SceneNodeProperties3D * SceneNode3D::GetSceneNodeProperties()
    {
        return &_sceneNodeProp;
    }
    
    void SceneNode3D::SetParent(SceneNode3D * parent)
    {
        _parent = parent;
    }
    
    SceneNode3D * SceneNode3D::GetParent()
    {
        return _parent;
    }
    
}