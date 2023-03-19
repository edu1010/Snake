#pragma once
#include "ConsoleDrawer.h"
#include "PlayerInput.h"

class LogicManager
{
public:
	virtual void Start(ConsoleDrawer* drawer, PlayerInput* inputManager)=0;
	virtual void Update(float deltaTime)=0;
	virtual void FastUpdate()=0;

};

