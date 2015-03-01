//
//  Test3D.h
//  Game
//
//  Created by Fakhir Shaheen on 28/02/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <StateManager/State.h>
#include <Graphics2D/Texture.h>
#include <Graphics3D/SceneNode3D.h>

#include <Renderer/GLES20/Vertex3DProgram.h>
#include <Renderer/GLES20/VertexBoilProgram.h>
#include <Renderer/GLES20/ToonProgram.h>
#include <Renderer/GLES20/BloomProgram.h>


class Test3D : public Fakhir::State
{
public:
    
    virtual bool Load();
    virtual bool UnLoad();
    
    virtual bool Init();
    virtual void Free();
    
    virtual void Pause();
    virtual void Resume();
    
    virtual void Update(float dt);
    virtual void Render(float dt = 0.0f);
        
private:
    
    Fakhir::SceneNode3D * _vertexBoilNode;
    Fakhir::SceneNode3D * _vertexBoilNode2;
    Fakhir::SceneNode3D * _toonNode;
    Fakhir::SceneNode3D * _bananaNode;
    Fakhir::SceneNode3D * _odoNode;
    Fakhir::SceneNode3D * _needleNode;

    Fakhir::SceneNode3D * _carNode;
    
    //float ROTATION_SPEED;
    
};
