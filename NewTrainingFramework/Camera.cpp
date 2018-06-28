#include "stdafx.h"
#include "Camera.h"
#include "Globals.h"


Camera::Camera()
{
	rotationY = 0.0f;
	camPos = Vector3(0.0, 2.0, 10.0);
	camTarget = Vector3(0.0, 0.0, 0.0);
	upV = Vector3(0.0, 1.0, 0.0);

}

Camera::~Camera()
{
	
}

bool Camera::Init(float fov ,float nearr, float faR, float sp)
{
	projection = projection.SetPerspective(fov, float(Globals::screenWidth) / float(Globals::screenHeight), nearr, faR);
	lookAtM = SetLookAt(camPos, camTarget, upV);
	speed = sp;
	return true;
}

Matrix Camera::calculateLookAtMatrix(Vector3 eye, Vector3 cent, Vector3 up)
{
	Vector3 zaxis = (cent - eye).Normalize();
	Vector3 xaxis = up.Cross(zaxis).Normalize();
	Vector3 yaxis = xaxis.Cross(zaxis);

	Matrix lookAtMatrix;

	lookAtMatrix.m[0][0] = xaxis.x;
	lookAtMatrix.m[0][1] = yaxis.x;
	lookAtMatrix.m[0][2] = zaxis.x;
	lookAtMatrix.m[0][3] = 0.0f;

	lookAtMatrix.m[1][0] = xaxis.y;
	lookAtMatrix.m[1][1] = yaxis.y;
	lookAtMatrix.m[1][2] = zaxis.y;
	lookAtMatrix.m[1][3] = 0.0f;


	lookAtMatrix.m[2][0] = xaxis.z;
	lookAtMatrix.m[2][1] = yaxis.z;
	lookAtMatrix.m[2][2] = zaxis.z;
	lookAtMatrix.m[2][3] = 0.f;

	lookAtMatrix.m[3][0] = -xaxis.Dot(eye);
	lookAtMatrix.m[3][1] = -yaxis.Dot(eye);
	lookAtMatrix.m[3][2] = -zaxis.Dot(eye);


	lookAtMatrix.m[3][3] = 1;
	
	return lookAtMatrix;
}

Matrix Camera::SetLookAt(Vector3& position, Vector3& target, Vector3& up)
{
	Vector3 pos(position.x, position.y, position.z);

	Vector3 xaxis;
	Vector3 yaxis(up.x, up.y, up.z);
	Vector3 zaxis;

	zaxis = (position - target).Normalize();
	xaxis = (yaxis.Cross(zaxis)).Normalize();
	yaxis = (zaxis.Cross(xaxis)).Normalize();

	Matrix m_view;

	m_view.SetIdentity();

	m_view.m[0][0] = xaxis.x;
	m_view.m[0][1] = yaxis.x;
	m_view.m[0][2] = zaxis.x;
	m_view.m[0][3] = 0.f;

	m_view.m[1][0] = xaxis.y;
	m_view.m[1][1] = yaxis.y;
	m_view.m[1][2] = zaxis.y;
	m_view.m[1][3] = 0.f;

	m_view.m[2][0] = xaxis.z;
	m_view.m[2][1] = yaxis.z;
	m_view.m[2][2] = zaxis.z;
	m_view.m[2][3] = 0.f;

	m_view.m[3][0] = -xaxis.Dot(pos);
	m_view.m[3][1] = -yaxis.Dot(pos);
	m_view.m[3][2] = -zaxis.Dot(pos);
	m_view.m[3][3] = 1.f;

	//m_view.Transpose();

	return m_view;
	// transpose before uploading
}


void Camera::moveForward()
{
	float angle = camRot * 0.0174532925f;

	camPos.x -= sinf(angle) * speed;
	camPos.z -= cosf(angle) * speed;
}

void Camera::moveBack()
{
	float angle = camRot * 0.0174532925f;

	camPos.x += sinf(angle) * speed;
	camPos.z += cosf(angle) * speed;
}

void Camera::moveUp()
{
	camPos.y += speed * upV.y;
}

void Camera::moveDown()
{
	camPos.y -= speed * upV.y;
}

void Camera::moveLeft()
{
	float angle = camRot * 0.0174532925f;

	//Vector3 crossupFor = camTarget.Cross(camUp).Normalize();
	camPos.x -= cosf(angle) * speed;
	//camPos.z -= sinf(angle) * speed;
}

void Camera::moveRight()
{
	Vector3 crossupFor = camTarget.Cross(camUp).Normalize();
	
	float angle = camRot * 0.0174532925f;

	//Vector3 crossupFor = camTarget.Cross(camUp).Normalize();
	camPos.x += cosf(angle) * speed;
	//camPos.z += speed;
}


void Camera::RotateLeft()
{
	//Matrix rotation = rotation.SetRotationY(10);
	float angle = 0.05f;
	camRot += angle;

	float yaw = camRot * 0.0174532925f;

	if (yaw < 0.0f)
	{
		yaw += 360.0f;
	}
}


void Camera::RotateRight()
{
	float angle = 0.05f;
	camRot -= angle;

	float yaw = camRot * 0.0174532925f;

	if (yaw < 0.0f)
	{
		yaw -= 360.0f;
	}
}

void Camera::RotateUp()
{
	float angle = 0.05f;
	camRotX -= angle;

	float yaw = camRotX * 0.0174532925f;

	if (yaw < -90.0f)
	{
		yaw = -90.0f;
	}
}

void Camera::RotateDown()
{
	float angle = 0.05f;

	camRotX += angle;

	float yaw = camRotX * 0.0174532925f;

	if (yaw >= 90.0f)
	{
		yaw = 90.0f;
	}
}

void Camera::Update(ESContext *esContext, float deltatime)
{
	//model = model.SetRotationY(deltatime);
	//lookAtM = lookAtM.SetRotationAngleAxis(camRot, camRotation.x, camRotation.y, camRotation.z);
	//lookAtM = lookAtM.SetTranslation(camPos);

	
	translat.SetTranslation(-camPos);
	rotY.SetRotationY(camRot);
	rotX.SetRotationX(camRotX);

	lookAtM = translat * rotY * rotX;
}


