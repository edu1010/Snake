#include "FallingChar.h"

FallingChar::FallingChar()
{
}

FallingChar::FallingChar(int lineToStart, char ch)
{
	line = lineToStart;
	c = ch;
	index = 2;
	indexForExplosion = 0;
	shieldProtector = false;
	isAlive = true;
}

FallingChar::FallingChar(int lineToStart, char ch, bool shield)
{
	isAlive = true;
	line = lineToStart;
	c = ch;
	index = 2;
	shieldProtector = shield;
}

FallingChar::FallingChar(int lineToStart, char ch, bool shield, bool firstTime)
{
	isAlive = true;
	line = lineToStart;
	c = ch;
	index = 2;
	shieldProtector = shield;
	pause = firstTime;
}

FallingChar::~FallingChar()
{
}

void FallingChar::IncrementIndex()
{
	if (isAlive) 
	{
		index++;
	}
}

void FallingChar::Die()
{
	isAlive = false;
	c = ' ';
	indexForExplosion = index;
	index = 2;
	iNeedToExplode = true;
	//shieldProtector = false;
}

void FallingChar::Revive( char ch)
{
	isAlive = true;
	iNeedToExplode = false;
	index = 2;
	indexForExplosion = 2;
	c = ch;
	pause = true;
	invulnerable = false;
}

void FallingChar::TakeDamage()
{
	if (shieldProtector || invulnerable)
	{
		shieldProtector = false;
		invulnerable = true;
	}
	else
	{
		Die();
	}
}

