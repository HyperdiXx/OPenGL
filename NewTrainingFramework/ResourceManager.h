#pragma once

#ifndef _RESOURCEMANAGER_
#define _RESOURCEMANAGER_



#include "Model.h"
#include "Texture.h"
#include "Shaders.h"
#include "Terrain.h"
#include "Sky.h"
#include "Fire.h"
#include <map>

class ResourceManager
{

protected:
	ResourceManager() {}
	ResourceManager(const ResourceManager&) {}
	~ResourceManager() {}
	ResourceManager& operator =(const ResourceManager &) {}
public:
	static void CreateInstance()
	{
		if (m_Instance == NULL)
		{
			m_Instance = new ResourceManager;
		}
	}
	static ResourceManager* GetInstance()
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

	bool LoadRMText(const char*);

	Model* GetModelbyID(unsigned int ID);
	Texture* Get2DTexturebyID(int ID);
	Texture* GetCubeTexturebyID(int ID);
	Texture* GetTerrainTexturebyID(int ID);
	Texture* GetFireTexturebyID(int ID);
	Shaders* GetTerShaderbyID(int ID);
	Shaders* GetShaderbyID(int ID);
	Shaders* GetSkyShaderbyID(int ID);
	Shaders* GetFireShaderbyID(int ID);
	Terrain* GetTerrainbyID(int ID);
	Sky* GetSkybyID(int ID);
	FireEffect* GetFirebyID(int ID);

protected:
	static ResourceManager * m_Instance;
private:
	unsigned int m_NoTextures, m_NoTerTextures, m_NoCubeTextures, m_NoModels, m_NoShaders, m_NoTerrain, m_NoTerShaders, m_NoSky, m_NoSkyShaders, mNoFires, mNoFTextures, mNoFShaders;
	std::vector<Model> models;
	std::vector<Sky> sky;
	std::vector<FireEffect> fireVect;
	std::vector<Texture> textures, tertext, skytext, firetextV;
	std::vector<Shaders> shaders, tershaders, skyshaders, fireshaderV;
	std::vector<Terrain> terrains;
	std::vector<unsigned int> ID, IDtext, IDShader;
	std::vector<char*> faces;
	std::vector<std::string> filePathesModels, filePathesTextures, filePathesShadersVS, textureType, filePathesShadersFS;
	Model* p_Models;
	Texture* p_Textures, *p_2DTextures;
	Shaders* p_Shaders;
	Terrain* p_Terrain;
};
#endif // !_RESOURCEMANAGER_

