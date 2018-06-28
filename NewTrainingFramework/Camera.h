#pragma once

#ifndef _CAMERA_
#define _CAMERA_

#include "../Utilities/utilities.h"
#include <math.h>

class Camera
{
public:
	Camera();
	~Camera();

	bool Init(float, float, float , float);
	void Update(ESContext * esContext, float deltatime);

	Matrix calculateLookAtMatrix(Vector3 eye, Vector3 cent, Vector3 up);
	Matrix SetLookAt(Vector3& position, Vector3& target, Vector3& up);
	Matrix& getlookAtMatrix()
	{
		return lookAtM;
	}
	Matrix& getPerspectiveMatrix()
	{
		return projection;
	}
	Vector3& getCamPos()
	{
		return camPos;
	}

	Vector3 camPos, camRotation, camTarget, upV, camRight, camUp;
	Matrix lookAtM, projection;
	Matrix translat, rotY, rotX, rotZ;
	float speed;
	float camRot = 0.0f, camRotX = 0.f, camRotZ = 0.f;
	float nearN = 0.1, fov = 45.0f, farR = 200.0;

	float rotationY;

	void moveBack();
	void moveForward();
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void RotateLeft();
	void RotateRight();
	void RotateUp();
	void RotateDown();
};
#endif // !_CAMERA_


