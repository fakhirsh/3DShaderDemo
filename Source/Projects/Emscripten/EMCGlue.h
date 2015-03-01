
#pragma once

namespace EMCGlue
{
    bool Init(int width, int height);
    void Tick();
    void Shutdown();

    void MouseDown(float x, float y);
    void MouseMoved(float x, float y);
    void MouseUp(float x, float y);
    void MouseCancelled(float x, float y);
};