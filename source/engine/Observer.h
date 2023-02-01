#pragma once

#include <list>
#include <SDL.h>

class IObserver {
public:
    virtual void RenderTexture(SDL_Renderer* renderer) {};
    virtual void UpdateMove() {};
    virtual void HandleEvent(SDL_Event* event) {};
};

class ISubject {
public:
    virtual void Attach(IObserver* observer) {};
    virtual void Detach(IObserver* observer) {};
    virtual void NotifyUpdateTextures(SDL_Renderer* renderer) {};
    virtual void NotifyHandleEvent(SDL_Event* event) {};
    virtual void NotifyUpdateMove() {};
};
