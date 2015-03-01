//
//  BloomProgram.h
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

//#include "../../Common.h"
#include "Program.h"

namespace Fakhir
{
    
    class BloomProgram : public Program
    {
    public:
        BloomProgram();
        ~BloomProgram();
        
        virtual bool Init();
        
        void SetMatrix(float screenWidth, float screenHeight, glm::mat4 testMat);
        
        GLuint GetPositionAttribLocation();
        GLuint GetTexCoordAttribLocation();
        GLuint GetNormalAttribLocation();
        GLuint GetPVMMatrixLoc();
        GLuint GetAngleUniformLoc();
        
    private:
        GLuint _positionAttrib;
        GLuint _texCoordAttrib;
        GLuint _normalAttrib;
        GLuint _PMVMatrixUniform;
        GLuint _angleUniform;
    };
    
};
