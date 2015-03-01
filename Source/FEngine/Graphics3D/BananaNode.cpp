//
//  BananaNode.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "BananaNode.h"
#include "RootSceneNode3D.h"

#include "../Graphics2D/Texture.h"
#include "../Renderer/GLES20/Vertex3DProgram.h"
#include "../../../../Assets/Meshes/banana.h"

#include "../System/App.h"
#include "../StateManager/StateManager.h"

extern Fakhir::App * gApp;


//float angle = 0.0f;

namespace Fakhir
{
    
    BananaNode::BananaNode()
    {
        
    }
    
    BananaNode::~BananaNode()
    {
        
    }
    
    
    bool BananaNode::PreRender(float dt)
    {
        
        RootSceneNode3D * root = (RootSceneNode3D *)StateManager::Get()->GetRootSceneNode();
        glm::mat4 matStack = root->transformationStack.back();
        
        float x = _sceneNodeProp.x;
        float y = _sceneNodeProp.y;
        float z = _sceneNodeProp.z;
        glm::mat4 translate = glm::translate<GLfloat>(glm::mat4(1.0f), glm::vec3(x, y, z));
        
        glm::mat4 rotate = glm::rotate<GLfloat>(glm::mat4(1.0f), _sceneNodeProp.angleY/10.0f, glm::vec3(1.0f, 1.0f, 1.0f));
        
        float S = _sceneNodeProp.scaleX;
        glm::mat4 scale     = glm::scale<GLfloat>(glm::mat4(1.0f), glm::vec3(S, S, S));
        
        glm::mat4 modelMat = rotate * translate * rotate * scale;
        
        //root->transformationStack.push_back(matStack * modelMat);
        root->transformationStack.push_back(matStack * modelMat);
        
        return true;
    }
    
    bool BananaNode::Render(float dt)
    {
        

        _sceneNodeProp.texture->Bind();
        ((Vertex3DProgram *)_sceneNodeProp.program)->Bind();
        
        int posLoc      =   ((Vertex3DProgram *)_sceneNodeProp.program)->GetPositionAttribLocation();
        int texLoc      =   ((Vertex3DProgram *)_sceneNodeProp.program)->GetTexCoordAttribLocation();
        //int angleLoc      =   ((Vertex3DProgram *)_sceneNodeProp.program)->GetAngleUniformLoc();
        int normLoc     =   ((Vertex3DProgram *)_sceneNodeProp.program)->GetNormalAttribLocation();
        int pvmLoc      =   ((Vertex3DProgram *)_sceneNodeProp.program)->GetPVMMatrixLoc();
        
        
        glm::mat4 Projection = glm::perspective(45.0f, 960.0f / 640.0f, 0.1f, 100.0f);
        glm::mat4 View       = glm::lookAt(
                                           glm::vec3(0,0,1), // Camera is at (4,3,3), in World Space
                                           glm::vec3(0,0,0), // and looks at the origin
                                           glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                           );
        
        RootSceneNode3D * root = (RootSceneNode3D *)StateManager::Get()->GetRootSceneNode();
        glm::mat4 modelMat = root->transformationStack.back();
        
        glm::mat4 projMat        = Projection * View * modelMat; // Remember, matrix multiplication is the other way around
        
        glUniformMatrix4fv( pvmLoc, 1, GL_FALSE, glm::value_ptr(projMat));
        
        
        // Enable the user-defined vertex array
        glEnableVertexAttribArray(posLoc);
        glEnableVertexAttribArray(texLoc);
        glEnableVertexAttribArray(normLoc);
        glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)&bananaVerts[0]);
        glVertexAttribPointer(texLoc, 2, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)&bananaTexCoords[0]);
        glVertexAttribPointer(normLoc, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)&bananaNormals[0]);
        glDrawArrays(GL_TRIANGLES, 0, bananaNumVerts);
        glDisableVertexAttribArray(normLoc);
        glDisableVertexAttribArray(texLoc);
        glDisableVertexAttribArray(posLoc);
        
        _sceneNodeProp.texture->UnBind();
        
        return true;
    }
    
    bool BananaNode::PostRender(float dt)
    {
        RootSceneNode3D * root = (RootSceneNode3D *)StateManager::Get()->GetRootSceneNode();
        root->transformationStack.pop_back();
        
        return true;
    }
    
}