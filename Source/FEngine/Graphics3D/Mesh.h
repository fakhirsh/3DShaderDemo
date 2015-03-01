//
//  Mesh.h
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

namespace Fakhir
{
    class Mesh
    {
    public:
        Mesh();
        ~Mesh();
        
        unsigned int GetVBOID();
        unsigned int GetIBOID();
        
    protected:
        unsigned int _vboID;
        unsigned int _iboID;
        
    };
}