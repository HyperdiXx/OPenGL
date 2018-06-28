// NewTrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
 // if you use STL, please include this line AFTER all other include
#include <iterator>
#include <vector>
#include "Shaders.h"
#include "Globals.h"
#include "InputManager.h"
#include "Texture.h"
#include "Camera.h"
#include "Model.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "../Utilities/utilities.h"

GLuint vboId;
GLuint modelHandler;
GLuint numIndexes;
GLuint m_hIndexBuffer;
Shaders myShaders;
Matrix m, model, view, projection, lookAt, mvp;
GLuint textureHandler;
Input* m_Input;
Texture textureM;
Camera cam;
Vector3 pos;
Model modelObject;


int index = 585;
float m_time;
float rot = 30;
std::vector<unsigned int> ind;
std::vector<Indices> indicesData;
std::vector<Vertex> verticesData;


int Init(ESContext *esContext)
{
	//glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepthf(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	SceneManager::CreateInstance();
	SceneManager::GetInstance()->Load(esContext);

	return 0;
}

void Draw(ESContext *esContext)
{
	glClear(GL_COLOR_BUFFER_BIT);
	

	SceneManager::GetInstance()->Draw(esContext);

	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void Update(ESContext *esContext, float deltaTime)
{
	SceneManager::GetInstance()->Update(esContext, deltaTime);
}

void Key(ESContext *esContext, unsigned char key, bool bIsPressed)
{
	SceneManager::GetInstance()->UpdateKey(esContext, key, bIsPressed);
}

void CleanUp()
{
	SceneManager::GetInstance()->CleanUp();
	SceneManager::DestroyInstance();
	ResourceManager::DestroyInstance();
}


//////////////////////////////////////////// WINDOWS main function ////////////////////////////////////////////////////
#ifdef _WIN32

#include <conio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	ESContext esContext;

	esInitContext(&esContext);

	esCreateWindow(&esContext, "Hello Triangle", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);

	if (Init(&esContext) != 0)
		return 0;

	esRegisterDrawFunc(&esContext, Draw);
	esRegisterUpdateFunc(&esContext, Update);
	esRegisterKeyFunc(&esContext, Key);

	esMainLoop(&esContext);

	//releasing OpenGL resources
	CleanUp();

	printf("Press any key...\n");

	_getch();

	return 0;
}

#endif
//////////////////////////////////////////// WINDOWS main function ////////////////////////////////////////////////////
