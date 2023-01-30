#pragma once
#include <SDL.h>	

class Time
{
public:
	void InitTime();
	void UpdateTime();
	Uint32 GetTime();
	Uint32 GetDeltaTime();
	Uint32 GetCurrentFrame();

private:
	Uint32 _startTime = 0;
	Uint32 _previousFrameTime = 0;
	Uint32 _currentTime = 0;
	Uint32 _currentFrame = 0;
};

