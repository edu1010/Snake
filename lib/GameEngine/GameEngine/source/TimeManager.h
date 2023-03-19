#pragma once
#include <time.h>

class TimeManager
{
	const float timePerFrame		= 1.0f / 8.0f;
	clock_t		elapsedTimeClocks	= 0;
	clock_t		lastFrameClockTime	= 0;
	float		elapsedTime			= 0.0f;

public:
	TimeManager();
	TimeManager(int framesXSecond);
	~TimeManager();

	bool ShouldExecuteNextFrame() const;
	float GetElapsedTime() const;

	void Update();
	void NextFrameExecuted();
};

