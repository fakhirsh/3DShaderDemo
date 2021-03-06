//
//  SoundManager.h
//  WordGame
//
//  Created by Fakhir Shaheen on 06/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __WordGame__SoundManager__
#define __WordGame__SoundManager__

#include "../Common.h"


namespace Fakhir
{

    class SoundManager
    {
    public:
        ~SoundManager();
        
        static SoundManager * Get();
        
        
    /////////////////////////////////////////////////////////////////////////////////////
        
        bool LoadOGGFromFile(std::string fileName);
        
        bool LoadOGGFromMem(std::vector<char> & oggFileData, std::vector<char> & buffer);
        
        void PlaySound(std::string fileName);
        void StopSound(std::string fileName);
        void SetVolume(std::string fileName, float newVolume);
        
    private:
        
        SoundManager();
        bool Init();
        
        static SoundManager * _instance;
        
        ALCdevice * _deviceAL;
        ALCcontext * _contextAL;
        
        std::map<std::string, ALuint> _bufferMap;
        std::map<std::string, ALuint> _sourceMap;
        
/////////////////////////////////////////////////////////////////////////////////////////////
        
        ALenum _format;
        ALsizei _freq;
        
        ALint _state;                // The state of the sound source
        //ALuint _bufferID;            // The OpenAL sound buffer ID
        //ALuint _sourceID;            // The OpenAL sound source
        
    };

};

#endif /* defined(__WordGame__SoundManager__) */
