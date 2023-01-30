#include "Time.h"

void Time::InitTime()
{
	_startTime = SDL_GetTicks();
}

void Time::UpdateTime()
{
	_previousFrameTime = _currentTime;
	_currentTime = SDL_GetTicks() - _startTime;
	_currentFrame++;
}

Uint32 Time::GetTime()
{
	return SDL_GetTicks() - _startTime;
}

Uint32 Time::GetDeltaTime()
{
	return _currentTime - _previousFrameTime;
}

Uint32 Time::GetCurrentFrame()
{
	return _currentFrame;
}

