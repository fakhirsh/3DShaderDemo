//
//  IRenderer.h
//  Game
//
//  Created by Fakhir Shaheen on 23/02/2015.
//
//

#pragma once


namespace Fakhir
{
    class Texture;
    
    class IRenderer
    {
    public:
        IRenderer(){}
        virtual ~IRenderer(){}
        
        /**
         * @param	texture		Generic Texture object that holds the actual texture ID and some other stuff;
         */
        //virtual void BindTexture(const Texture & texture) = 0;
        
        virtual void UnbindTexture() = 0;
        //virtual void DeleteTexture(const Texture & texture) = 0;
        virtual unsigned int LoadTextureFromBuffer(unsigned int texWidth, unsigned int texHeight, bool hasAlpha, unsigned int * pixels ) = 0;
        
        virtual void EnableBlend() = 0;
        
        virtual void ClearColor(float r, float g, float b, float a) = 0;
        virtual void Clear() = 0;
        
        virtual void SetViewPort(float x, float y, float width, float height) = 0;
    };

};