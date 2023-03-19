#pragma once
class FallingChar
{
public:
	int line=0;
	char c=' ';
	int index = 0;
	int indexForExplosion = 0;
	bool shieldProtector = false;
	bool isAlive = true;
	bool pause = true;
	bool iNeedToExplode = false;
	bool invulnerable = false;
	FallingChar();
	FallingChar(int lineToStart, char ch);
	FallingChar(int lineToStart, char ch,bool shield);
	FallingChar(int lineToStart, char ch,bool shield,bool firstTime);
	~FallingChar();
	void IncrementIndex();
	void Die();
	void Revive(char ch);
	void TakeDamage();
	

};

