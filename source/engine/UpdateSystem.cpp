#include "UpdateSystem.h"

void UpdateSystem::Attach(IObserver* observer)
{
    list_observer.push_back(observer);
}

void UpdateSystem::Detach(IObserver* observer)
{
    list_observer.remove(observer);
}

void UpdateSystem::NotifyUpdateTextures(SDL_Renderer* renderer)
{
    std::list<IObserver*>::iterator iterator = list_observer.begin();
    while (iterator != list_observer.end()) 
    {
        (*iterator)->RenderTexture(renderer);
        ++iterator;
    }
}

void UpdateSystem::NotifyHandleEvent(SDL_Event* event)
{
    std::list<IObserver*>::iterator iterator = list_observer.begin();
    while (iterator != list_observer.end()) 
    {
        (*iterator)->HandleEvent(event);
        ++iterator;
    }
}

void UpdateSystem::NotifyUpdateMove()
{
    std::list<IObserver*>::iterator iterator = list_observer.begin();
    while (iterator != list_observer.end()) 
    {
        (*iterator)->UpdateMove();
        ++iterator;
    }
}

void UpdateSystem::NotifyTurnEnd(int participantID) // Croupier = 0, Player = 1
{
    std::list<IObserver*>::iterator iterator = list_observer.begin();
    while (iterator != list_observer.end())
    {
        (*iterator)->HandleTurnEnd(participantID);
        ++iterator;
    }
}