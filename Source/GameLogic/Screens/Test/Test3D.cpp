//
//  Test3D.cpp
//  Game
//
//  Created by Fakhir Shaheen on 28/02/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Test3D.h"

#include <System/App.h>
#include <ResourceCache/ResourceCache.h>
#include <ResourceCache/IOManager.h>

#include <Graphics3D/VertexBoilNode.h>
#include <Graphics3D/ToonNode.h>
#include <Graphics3D/BananaNode.h>


using namespace Fakhir;

extern App * gApp;

float angle = 0.0f;

bool Test3D::Load()
{
    std::cout << "Load() from Test3D" << std::endl;
 
    std::vector<char> textureData;
    
    IOManager * ioMgr = gApp->GetIOManager();
    
    // Get full path to PNG file
    std::string fullTexturePath = gApp->GetAssetPath() + "Textures/banana.png";
    // Read raw byte stream from the source file
    ioMgr->GetAssetStream(fullTexturePath, textureData);
    
    std::string textureString;
    for (int i = 0; i < textureData.size(); i++)
    {
        textureString += textureData[i];
    }
    
    std::istringstream textureStream( textureString );
    
    Texture * bananaTexture = new Texture();
    if(!bananaTexture->LoadFromStream(textureStream))
    {
        std::cout << "Failed to load texture: banana.png" << std::endl;
        return false;
    }
    
    Program * vbProgram = new VertexBoilProgram();
    vbProgram->Init();
    Program * tProgram = new ToonProgram();
    tProgram->Init();
    Program * bProgram = new Vertex3DProgram();
    bProgram->Init();
    
    SceneNodeProperties3D vbsnp;
    vbsnp.x = 0.0f;
    vbsnp.y = 0.0f;
    vbsnp.z = -10.0f;
    vbsnp.scaleX = 8.0f;
    vbsnp.program = vbProgram;
    
    _vertexBoilNode = new VertexBoilNode();
    _vertexBoilNode->SetSceneNodeProperties(vbsnp);
    
    _rootSceneNode->Add(_vertexBoilNode);
   
    
    SceneNodeProperties3D tsnp;
    vbsnp.x = 0.0f;
    vbsnp.y = 0.0f;
    vbsnp.z = -0.8f;
    vbsnp.scaleX = 0.7f;
    vbsnp.program = tProgram;
    
    _toonNode = new ToonNode();
    _toonNode->SetSceneNodeProperties(vbsnp);
    _vertexBoilNode->Add(_toonNode);
    
    
    SceneNodeProperties3D bsnp;
    bsnp.x = 0.0f;
    bsnp.y = 0.0f;
    bsnp.z = -0.5f;
    bsnp.scaleX = 0.7f;
    bsnp.program = bProgram;
    bsnp.texture = bananaTexture;
    
    _bananaNode = new BananaNode();
    _bananaNode->SetSceneNodeProperties(bsnp);
    _vertexBoilNode->Add(_bananaNode);
    
    
    SceneNodeProperties3D vbsnp2;
    vbsnp2.x = 0.0f;
    vbsnp2.y = 0.0f;
    vbsnp2.z = 0.5f;
    vbsnp2.scaleX = 0.2f;
    vbsnp2.program = vbProgram;
    
    _vertexBoilNode2 = new VertexBoilNode();
    _vertexBoilNode2->SetSceneNodeProperties(vbsnp2);
    
    _vertexBoilNode->Add(_vertexBoilNode2);
    
    
    SceneNodeProperties3D tsnp2;
    tsnp2.x = 0.0f;
    tsnp2.y = 0.0f;
    tsnp2.z = -0.8f;
    tsnp2.scaleX = 0.7f;
    tsnp2.program = tProgram;
    
    _toonNode = new ToonNode();
    _toonNode->SetSceneNodeProperties(tsnp2);
    _bananaNode->Add(_toonNode);
    
    
    return true;
}

bool Test3D::UnLoad()
{
    return true;
}

bool Test3D::Init()
{
    return true;
}

void Test3D::Free()
{

}

void Test3D::Pause()
{

}

void Test3D::Resume()
{

}

void Test3D::Update(float dt)
{
    angle += 60.0f * dt * 3.1415629f / 180.0f;
    
    _vertexBoilNode->GetSceneNodeProperties()->angleY = angle;
    _vertexBoilNode2->GetSceneNodeProperties()->angleY = angle;
    _toonNode->GetSceneNodeProperties()->angleY = angle*5;
    _bananaNode->GetSceneNodeProperties()->angleY = angle*6;
}

void Test3D::Render(float dt)
{
    _rootSceneNode->PreRender(dt);
    _rootSceneNode->Render(dt);
    _rootSceneNode->RenderChildren(dt);
    _rootSceneNode->PostRender(dt);
    
}

