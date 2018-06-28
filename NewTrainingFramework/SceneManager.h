#pragma once


#ifndef _SCENEMANAGER_
#define _SCENEMANAGER_

#include "Camera.h"
#include "Object.h"
#include <memory>

class SceneManager
{
private:
	struct Position
	{
		float x, y, z;
	};
	struct Color
	{
		float x, y, z;
	};
	struct LightposDir
	{
		float x, y, z;
	};
protected:

	SceneManager() {}
	SceneManager(const SceneManager&) {}
	~SceneManager() {}
	SceneManager& operator =(const SceneManager &) {}

public:
	static void CreateInstance()
	{
		if (m_Instance == NULL)
		{
			m_Instance = new SceneManager;
		}
	}
	static SceneManager* GetInstance()
	{
		return m_Instance;
	}
	static void DestroyInstance()
	{
		if (m_Instance)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	bool Load(ESContext*);
	bool LoadTextfile(char*);
	void LoadCamera(char*);
	void Draw(ESContext *esContext);
	void Update(ESContext *esContext, float deltaTime);
	void CleanUp();
	void UpdateKey(ESContext *esContext, unsigned char key, bool bIsPressed);

	Camera* getCamera();
protected:
	static SceneManager *m_Instance;
private:

	unsigned int nObject;
	unsigned int IDModel, countLight, countShaders, countTextures;

	float cameraNear, cameraFar, cameraFOV, cameraSpeed;

	Matrix lookAt, projection;

	Camera * m_Camera;
	Object * p_Object;
};
#endif // !_SCENEMANAGER_
