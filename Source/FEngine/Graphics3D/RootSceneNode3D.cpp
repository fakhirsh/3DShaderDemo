//
//  RootSceneNode3D.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "RootSceneNode3D.h"

namespace Fakhir
{
    RootSceneNode3D::RootSceneNode3D()
    {
        SceneNodeProperties3D snp;
        snpStack.push_back(snp);
        
        glm::mat4 translate = glm::translate<GLfloat>(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
        glm::mat4 rotate    = glm::rotate<GLfloat>(glm::mat4(1.0f), 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
        glm::mat4 scale     = glm::scale<GLfloat>(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        
        glm::mat4 mat = translate * rotate * scale;
        transformationStack.push_back(mat);
    }
    
    RootSceneNode3D::~RootSceneNode3D()
    {
        
    }
    
}