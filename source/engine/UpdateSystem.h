#pragma once

#include "Observer.h"
#include <SDL.h>

class UpdateSystem : public ISubject
{
public:
    void Attach(IObserver* observer) final;
    void Detach(IObserver* observer) final;
    void NotifyUpdateTextures(SDL_Renderer* renderer) final;
    void NotifyHandleEvent(SDL_Event* event) final;
    void NotifyUpdateMove() final;
private:
    std::list<IObserver*> list_observer;
    SDL_Renderer* renderer;
};

