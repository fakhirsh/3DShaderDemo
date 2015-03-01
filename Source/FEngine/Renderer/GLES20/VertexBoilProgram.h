//
//  VertexBoilProgram.h
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Program.h"

namespace Fakhir
{
    
    class VertexBoilProgram : public Program
    {
    public:
        VertexBoilProgram();
        ~VertexBoilProgram();
        
        virtual bool Init();
        
        GLuint GetPositionAttribLocation();
        GLuint GetNormalAttribLocation();
        GLuint GetPVMMatrixLoc();
        GLuint GetAngleUniformLoc();
        
    private:
        GLuint _positionAttrib;
        GLuint _normalAttrib;
        GLuint _PMVMatrixUniform;
        GLuint _angleUniform;
    };
    
};
