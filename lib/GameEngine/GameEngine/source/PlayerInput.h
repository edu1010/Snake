#pragma once
class PlayerInput
{
public:
	char* pressedKeys = nullptr;
	int totalKeysPressedAtTheSameTime = 0;
	PlayerInput();
	~PlayerInput();
	void GetPresedKeys();
	void Update();
	bool theGivenCharIsPress(char c);
	bool ArrowUpIsPress();
	bool ArrowDownIsPress();
	bool ArrowLeftIsPress();
	bool ArrowRightIsPress();

};

