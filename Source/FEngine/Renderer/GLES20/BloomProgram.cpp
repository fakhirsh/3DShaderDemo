//
//  BloomProgram.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "BloomProgram.h"

#include "../../../../Assets/Effects/GLES20/Bloom.vs"
#include "../../../../Assets/Effects/GLES20/Bloom.fs"

namespace Fakhir
{
    
    BloomProgram::BloomProgram()
    {
        _positionAttrib     =   GLuint(-1);
        _angleUniform    =   GLuint(-1);
        _normalAttrib    =   GLuint(-1);
        _texCoordAttrib =   GLuint(-1);
        _PMVMatrixUniform   =   GLuint(-1);
    }
    
    BloomProgram::~BloomProgram()
    {
        
    }
    
    bool BloomProgram::Init()
    {
        
        _name = "BloomProgram";
        
        if (!LinkProgram(std::string(BloomVS), std::string(BloomFS))) {
            return false;
        }
        
        /**
         * Good practice:	ALWAYS get attribute location.
         * Pitfall: 		I was manually binding the locations. It Worked ONLY if
         *					done BEFORE linking the program. If the attribs are bound
         *					AFTER the program then it will NOT work on WebGL, but may
         *					work on other platforms!
         */
        _positionAttrib	=	glGetAttribLocation(_programID, "a_position");
        _texCoordAttrib	=	glGetAttribLocation(_programID, "a_texCoord");
        _angleUniform   =	glGetUniformLocation(_programID, "u_angle");
        _normalAttrib  =   glGetAttribLocation(_programID, "a_normal");
        _PMVMatrixUniform = glGetUniformLocation(_programID, "PMVMatrix");
        
        return true;
        
    }
    
    
    GLuint BloomProgram::GetPositionAttribLocation()
    {
        return _positionAttrib;
    }
    
    GLuint BloomProgram::GetTexCoordAttribLocation()
    {
        return _texCoordAttrib;
    }
    
    GLuint BloomProgram::GetAngleUniformLoc()
    {
        return _angleUniform;
    }
    
    GLuint BloomProgram::GetNormalAttribLocation()
    {
        return _normalAttrib;
    }
    
    GLuint BloomProgram::GetPVMMatrixLoc()
    {
        return _PMVMatrixUniform;
    }
    
    void BloomProgram::SetMatrix(float screenWidth, float screenHeight, glm::mat4 testMat)
    {
        // Get the location of the transformation matrix in the shader using its name
        //int matrixLocation = glGetUniformLocation(_programID, "PMVMatrix");
        
        glm::mat4 projMat = glm::ortho<GLfloat>(0.0f, screenWidth, 0.0f, screenHeight);
        
        //glm::mat4 translate = glm::translate<GLfloat>(glm::mat4(1.0f), testVec);
        //float angle = 45.0f * 3.1415629f / 180.0f;
        //glm::mat4 rotate = glm::rotate<GLfloat>(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f));
        
        
        
        // Pass the transformationMatrix to the shader using its location
        glUniformMatrix4fv( _PMVMatrixUniform, 1, GL_FALSE, glm::value_ptr(projMat * testMat));
        //if (!TestGLError("glUniformMatrix4fv"))
        //{
        //	return false;
        //}
        
    }
    
};


