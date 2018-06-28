#include "stdafx.h"
#include "InputManager.h"

Input::Input()
{
	
}

Input::~Input()
{

}

void Input::MoveForward(float dt, float speed)
{
	cam.camPos.x += dt * speed;
}

void Input::MoveBackward()
{

}

void Input::Left()
{

}

void Input::Right()
{

}

void Input::Up()
{

}

void Input::Down()
{

}

void Input::TurnLeft()
{

}

void Input::TurnRight()
{

}
