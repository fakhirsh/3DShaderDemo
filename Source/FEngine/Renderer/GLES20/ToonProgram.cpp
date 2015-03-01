//
//  ToonProgram.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ToonProgram.h"

#include "../../../../Assets/Effects/GLES20/Toon.vs"
#include "../../../../Assets/Effects/GLES20/Toon.fs"

namespace Fakhir
{
    
    ToonProgram::ToonProgram()
    {
        _positionAttrib     =   GLuint(-1);
        _normalAttrib       =   GLuint(-1);
        _PMVMatrixUniform   =   GLuint(-1);
    }
    
    ToonProgram::~ToonProgram()
    {
        
    }
    
    bool ToonProgram::Init()
    {
        
        _name = "ToonProgram";
        
        if (!LinkProgram(std::string(ToonVS), std::string(ToonFS))) {
            return false;
        }
        
        _positionAttrib	=	glGetAttribLocation(_programID, "a_position");
        _normalAttrib  =   glGetAttribLocation(_programID, "a_normal");
        _PMVMatrixUniform = glGetUniformLocation(_programID, "PMVMatrix");
        
        return true;
        
    }
    
    
    GLuint ToonProgram::GetPositionAttribLocation()
    {
        return _positionAttrib;
    }
    
    GLuint ToonProgram::GetNormalAttribLocation()
    {
        return _normalAttrib;
    }
    
    GLuint ToonProgram::GetPVMMatrixLoc()
    {
        return _PMVMatrixUniform;
    }
    
};


