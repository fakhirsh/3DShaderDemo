//
//  FState.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "State.h"
//#include "../ProcessManager/ProcessManager.h"
//#include "../EventManager/EventManager.h"

#include "../Graphics3D/RootSceneNode3D.h"

namespace Fakhir
{

    State::State()
    {
        _isPaused   =   false;
        //_processMgr =   boost::make_shared<Fakhir::ProcessManager>();
        //_eventMgr   =   boost::make_shared<Fakhir::EventManager>();
        _rootSceneNode = new RootSceneNode3D();
    }

    State::~State()
    {

    }

    bool State::IsPaused()
    {
        return _isPaused;
    }

};