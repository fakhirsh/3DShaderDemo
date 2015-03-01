//
//  Mesh.cpp
//  Game
//
//  Created by Fakhir Shaheen on 01/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Mesh.h"


namespace Fakhir
{
    Mesh::Mesh()
    {
    
    }
    
    Mesh::~Mesh()
    {
    
    }
    
    unsigned int Mesh::GetVBOID()
    {
        return _vboID;
    }
    
    unsigned int Mesh::GetIBOID()
    {
        return _iboID;
    }
}