//
//  ToonProgram.h
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Program.h"


namespace Fakhir
{
    
    class ToonProgram : public Program
    {
    public:
        ToonProgram();
        ~ToonProgram();
        
        virtual bool Init();
        
        GLuint GetPositionAttribLocation();
        GLuint GetNormalAttribLocation();
        GLuint GetPVMMatrixLoc();
        
    private:
        GLuint _positionAttrib;
        GLuint _normalAttrib;
        GLuint _PMVMatrixUniform;
    };
    
};
