//
//  VertexBoilProgram.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "VertexBoilProgram.h"


#include "../../../../Assets/Effects/GLES20/VertexBoil.vs"
#include "../../../../Assets/Effects/GLES20/VertexBoil.fs"

namespace Fakhir
{
    
    VertexBoilProgram::VertexBoilProgram()
    {
        _positionAttrib     =   GLuint(-1);
        _angleUniform       =   GLuint(-1);
        _normalAttrib       =   GLuint(-1);
        _PMVMatrixUniform   =   GLuint(-1);
    }
    
    VertexBoilProgram::~VertexBoilProgram()
    {
        
    }
    
    bool VertexBoilProgram::Init()
    {
        
        _name = "VertexBoilProgram";
        
        if (!LinkProgram(std::string(VertexBoilVS), std::string(VertexBoilFS))) {
            return false;
        }
        
        _positionAttrib	=	glGetAttribLocation(_programID, "a_position");
        _angleUniform   =	glGetUniformLocation(_programID, "u_angle");
        _normalAttrib  =   glGetAttribLocation(_programID, "a_normal");
        _PMVMatrixUniform = glGetUniformLocation(_programID, "PMVMatrix");
        
        return true;
        
    }
    
    
    GLuint VertexBoilProgram::GetPositionAttribLocation()
    {
        return _positionAttrib;
    }
    
    GLuint VertexBoilProgram::GetAngleUniformLoc()
    {
        return _angleUniform;
    }
    
    GLuint VertexBoilProgram::GetNormalAttribLocation()
    {
        return _normalAttrib;
    }
    
    GLuint VertexBoilProgram::GetPVMMatrixLoc()
    {
        return _PMVMatrixUniform;
    }
    
};


