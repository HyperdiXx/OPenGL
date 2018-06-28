#include "stdafx.h"
#include "SceneManager.h"



SceneManager * SceneManager::m_Instance = NULL;

bool SceneManager::Load(ESContext * escontext)
{
	bool result;

	LoadCamera("../Resources/SM.txt");


	m_Camera = new Camera;
	if (!m_Camera)
	{
		return false;
	}
	result = m_Camera->Init(cameraFOV, cameraNear, cameraFar, cameraSpeed);
	if (!result)
	{
		return false;
	}

	p_Object = new Object;
	if (!p_Object)
	{
		return false;
	}

	result = p_Object->Init(escontext);
	if (!result)
	{
		return false;
	}


	//Light coming...



	return true;
}

void SceneManager::Draw(ESContext *esContext)
{
	p_Object->Draw(esContext);
}

void SceneManager::Update(ESContext *esContext, float deltaTime)
{
	m_Camera->Update(esContext, deltaTime);
	p_Object->Update(esContext, deltaTime);
}

bool SceneManager::LoadTextfile(char* filename)
{
	/*FILE* pFile = fopen(filename, "r+");
	if (!pFile)
	{
		//error
	}

	char in[50];
	char out[50];
	std::string output;
	unsigned int Objects, d, n, m, shaderN;
	int j;
	Position pos, rot, scale;
	float f;

	Color colorA, colorC;
	LightposDir posdir;
	float r, sp;

	if (fscanf_s(pFile, "#Objects: %d\n", &nOobjects) != -1)
	{

	}

	for (int i = 0; i < nOobjects; ++i)
	{

		while (fscanf_s(pFile, "\nID %d\n"
			"MODEL %d\n"
			"TEXTURES %d\n"
			"CUBETEXTURES %d\n"
			"SHADER %d\n"
			"LIGHTS %d\n"
			"POSITION %f, %f, %f\n"
			"ROTATION %f, %f, %f\n"
			"SCALE %f, %f, %f\n", &d, &m, &countTextures, &shaderN, &d, &countLight, &pos.x, &pos.y, &pos.z,
			&rot.x, &rot.y, &rot.z, &scale.x, &scale.y, &scale.z) == 15)
		{
			m_ModelObj = ResourceManager::GetInstance()->GetModelbyID(m);
			m_2DTexture = ResourceManager::GetInstance()->Get2DTexturebyID(countTextures);
			m_ShaderObj = ResourceManager::GetInstance()->GetShaderbyID(shaderN);

			//	ID.push_back(d);
			//InitModel(m);
			positions.push_back(pos);
			rotations.push_back(rot);
			scales.push_back(scale);
		}

	}

	if (fscanf_s(pFile, "\n#LIGHTS\n", &d) != -1)
	{

	}

	while (fscanf(pFile, "AmbientColor %f, %f, %f\nAmbientWeight %f\nLightsCount: %d", &colorA.x, &colorA.y, &colorA.z, &weig, &countLight) == 5)
	{
		loght.push_back(colorA);
	}

	while (fscanf(pFile, "\n\nID %d\nPOS/DIR %f, %f, %f\nTYPE DIRECTION\nCOLOR %f, %f, %f\nMOVING %s\nRADIUS %f\nSPEED %f\n", &d, &posdir.x, &posdir.y, &posdir.z, &colorC.x, &colorC.y, &colorC.z, out, &r, &sp) == 10)
	{
		lightID.push_back(d);
		posdirLight.push_back(posdir);
		colorColor.push_back(colorC);
		typeMove.push_back(out);
		radiusLight.push_back(r);
		speedLight.push_back(sp);
	}

	if (fscanf_s(pFile, "#CAMERA\n") != -1)
	{

	}

	float camNear, camFar, camFov, camSpeed;

	while (fscanf(pFile, "NEAR %f\nFAR %f\nFOV %f\nSPEED %f", &camNear, &camFar, &camFov, &camSpeed) == 4)
	{
		m_Camera->nearN = camNear;
		m_Camera->farR = camFar;
		m_Camera->farR = camFov;
		m_Camera->speed = camSpeed;
	}

	/*if (countTextures > 0)
	{
	if (fscanf_s(pFile, "#Objects: %d\n\n"
	"ID %d\n"
	"MODEL %d\n"
	"TEXTURES %d\n", &j, &j, &j, &j) != -1)
	{

	}
	for (int i = 0; i < countTextures; ++i)
	{
	fprintf(pFile, "TEXTURE %d\n", i);
	}
	}
	else
	{

	}*/


	/*for (int i = 0; i < countLight; ++i)
	{
	while (fscanf(pFile, "LIGHT &d", &n) == 1)
	{
	//Initlight
	}
	}

	fclose(pFile);*/

	return true;
}

void SceneManager::LoadCamera(char* filename)
{
	FILE* pFile = fopen(filename, "r+");
	if (!pFile)
	{
		//error
	}

	char in[50];
	char out[50];
	std::string output;
	unsigned int Objects, d, n, m;
	int j;
	Position pos, rot, scale;
	float f;

	Color colorA, colorC;
	LightposDir posdir;
	float r, sp, weig;

	if (fscanf_s(pFile, "#Objects: %d\n", &Objects) != -1)
	{

	}

	for (int i = 0; i < Objects; ++i)
	{

		while (fscanf_s(pFile, "\nID %d\n"
			"MODEL %d\n"
			"TEXTURE %d\n"
			"CUBETEXTURES %d\n"
			"SHADER %d\n"
			"LIGHTS %d\n"
			"POSITION %f, %f, %f\n"
			"ROTATION %f, %f, %f\n"
			"SCALE %f, %f, %f\n", &d, &m, &countTextures, &d, &d, &countLight, &pos.x, &pos.y, &pos.z,
			&rot.x, &rot.y, &rot.z, &scale.x, &scale.y, &scale.z) == 15)
		{
		
		}

	}

	int mNoTerrains;
	int shaderN;

	int tex1, tex2;

	if (fscanf_s(pFile, "\n#Terrain: %d\n", &mNoTerrains) != -1)
	{

		while (fscanf_s(pFile, "\nID %d\n"
			"MODEL %d\n"
			"TEXTURE %d\n"
			"TEXTURE %d\n"
			"TEXTURE %d\n"
			"SHADER %d\n"
			"LIGHTS %d\n"
			"POSITION %f, %f, %f\n"
			"ROTATION %f, %f, %f\n"
			"SCALE %f, %f, %f\n", &d, &m, &countTextures, &tex1, &tex2, &shaderN, &countLight, &pos.x, &pos.y, &pos.z,
			&rot.x, &rot.y, &rot.z, &scale.x, &scale.y, &scale.z) == 16)
		{

		}
	}

	int a;

	if (fscanf_s(pFile, "\n#Skybox: %d\n", &d) != -1)
	{
		while (fscanf_s(pFile, "\nID %d\n"
			"MODEL %d\n"
			"TEXTURE %d\n"
			"SHADER %d\n"
			"LIGHT %d\n",
			&a, &m, &countTextures, &shaderN, &countLight) == 5)
		{
			
		}
	}



	if (fscanf_s(pFile, "\n#LIGHTS\n", &d) != -1)
	{

	}

	while (fscanf(pFile, "AmbientColor %f, %f, %f\nAmbientWeight %f\nLightsCount: %d", &colorA.x, &colorA.y, &colorA.z, &weig, &countLight) == 5)
	{
		
	}

	while (fscanf(pFile, "\n\nID %d\nPOS/DIR %f, %f, %f\nTYPE DIRECTION\nCOLOR %f, %f, %f\nMOVING %s\nRADIUS %f\nSPEED %f\n", &d, &posdir.x, &posdir.y, &posdir.z, &colorC.x, &colorC.y, &colorC.z, out, &r, &sp) == 10)
	{

	}

	if (fscanf_s(pFile, "#CAMERA\n") != -1)
	{

	}

	float camNear, camFar, camFov, camSpeed;

	while (fscanf(pFile, "NEAR %f\nFAR %f\nFOV %f\nSPEED %f", &camNear, &camFar, &camFov, &camSpeed) == 4)
	{
		cameraNear = camNear;
		cameraFar = camFar;
		cameraFOV = camFov;
		cameraSpeed = camSpeed;
	}


	fclose(pFile);

}

Camera* SceneManager::getCamera()
{
	return m_Camera;
}

void SceneManager::CleanUp()
{
	for (int i = 0; i < nObject; ++i)
	{
		p_Object[i].CleanUp();
	}

}

void SceneManager::UpdateKey(ESContext *esContext, unsigned char key, bool bIsPressed)
{
	switch (key)
	{
	case 'U':
	{
		m_Camera->moveUp();
		break;
	}
	case 'J':
	{
		m_Camera->moveDown();
		break;
	}
	case 'W':
	{
		m_Camera->moveForward();
		break;
	}
	case 'S':
	{
		m_Camera->moveBack();
		break;
	}
	case 'D':
	{
		m_Camera->moveRight();
		break;
	}
	case 'A':
	{
		m_Camera->moveLeft();
		break;
	}
	case 'N':
	{
		m_Camera->RotateLeft();
		break;
	}
	case 'B':
	{
		m_Camera->RotateRight();
		break;
	}
	case 'Y':
	{
		m_Camera->RotateUp();
		break;
	}
	case 'H':
	{
		m_Camera->RotateDown();
		break;
	}
	case 27:
	{
		exit(0);
		break;
	}

	}
}


