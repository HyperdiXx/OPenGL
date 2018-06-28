#pragma once

#include <Windows.h>
#include "Camera.h"

class Input
{
public:

	Camera cam;

	Input();
	~Input();

	void MoveForward(float dt, float speed);
	void MoveBackward();
	void Left();
	void Right();
	void TurnRight();
	void TurnLeft();
	void Up();
	void Down();

};