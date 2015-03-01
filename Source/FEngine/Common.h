//
//  Common.h
//  WordGame
//
//  Created by Fakhir Shaheen on 28/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform2.hpp>

#include <tinyxml2.h>

#include <FastDelegate.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>


#include <png.h>

#include <vector>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>


#ifdef __APPLE__
#include <OpenGLES/ES2/gl.h>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <GLES2/gl2.h>
#include <AL/al.h>
#include <AL/alc.h>
#endif


#define STRINGIFY(A) #A


///////////////////////////////////////////////////////////////////
// Common pointer typedefs

namespace Fakhir
{
    class State;
    class Process;
    class ProcessManager;
    class Texture;
    class TextureAtlas;
    class SpriteBatch;
    class Sprite;
    class Event;
    class EventManager;
    class FontAtlas;
};


typedef boost::shared_ptr<Fakhir::State>             StatePtr;

typedef boost::shared_ptr<Fakhir::Process>           ProcessPtr;
typedef boost::weak_ptr  <Fakhir::Process>           ProcessWeakPtr;
typedef boost::shared_ptr<Fakhir::ProcessManager>    ProcessManagerPtr;

typedef boost::shared_ptr<Fakhir::Texture>           TexturePtr;
typedef boost::shared_ptr<Fakhir::TextureAtlas>      TextureAtlasPtr;

typedef boost::shared_ptr<Fakhir::SpriteBatch>       SpriteBatchPtr;
typedef boost::shared_ptr<Fakhir::Sprite>            SpritePtr;

typedef boost::shared_ptr<Fakhir::Event>             EventPtr;
typedef boost::weak_ptr  <Fakhir::Event>             EventWeakPtr;
typedef boost::shared_ptr<Fakhir::EventManager>      EventManagerPtr;

typedef boost::shared_ptr<Fakhir::FontAtlas>         FontAtlasPtr;

// Consider this as a "Function Pointer" for class member functions
typedef fastdelegate::FastDelegate1<EventPtr>      EventListenerDelegate;

///////////////////////////////////////////////////////////////////


struct RECT
{
    float x, y;
    float width, height;
};


