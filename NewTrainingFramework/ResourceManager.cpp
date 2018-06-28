#include "stdafx.h"
#include "ResourceManager.h"



ResourceManager* ResourceManager::m_Instance = NULL;



bool ResourceManager::LoadRMText(const char* filename)
{
	char fileI[12], textureI[12], shaderIVS[12], shaderIFS[12], shaderC[12];
	std::string fiklepath;
	FILE* pFile = fopen(filename, "r");
	if (!pFile)
	{
		return false;
	}
	char in[50];
	char model[50];
	char ter[50];
	char out[50];
	std::string output;
	unsigned int a, d, t;

	if (fscanf_s(pFile, "#Models: %d\n", &m_NoModels) != -1)
	{
		models.resize(m_NoModels);

		for (int i = 0; i < m_NoModels; ++i)
		{
			while (fscanf(pFile, "ID %d FILE %s\n", &d, model) == 2)
			{
				models[i].InitModel(nullptr, model);
				++i;
			}
		}
	}

	
	char ft[30];

	if (fscanf_s(pFile, "\n#2DTextures: %d\n", &m_NoTextures) != -1)
	{
		textures.resize(m_NoTextures);

		for (int i = 0; i < m_NoTextures; ++i)
		{
			while (fscanf(pFile, "ID %d FILE %s\n", &d, in) == 2)
			{
				
				textures[i].Init(nullptr, in);
				++i;
			}
		}

	}

	if (fscanf_s(pFile, "\n#Shaders: %d\n", &m_NoShaders) != -1)
	{
		shaders.resize(m_NoShaders);

		for (int i = 0; i < m_NoShaders; ++i)
		{
			while (fscanf(pFile, "ID %d VS %s FS %s\n", &d, in, out) == 3)
			{
				shaders[i].Init(in, out);
				++i;
			}
		}

	}

	if (fscanf_s(pFile, "#Terrain: %d\n", &m_NoTerrain) != -1)
	{
		terrains.resize(m_NoTerrain);

		for (int i = 0; i < m_NoTerrain; ++i)
		{
			while (fscanf(pFile, "ID %d FILE %s\n", &d, ter) == 2)
			{
				terrains[i].Init(nullptr, ter);
			}
		}
	}

	char text[50];
	bool f;
	if (fscanf_s(pFile, "\n#Terrain2DTextures: %d\n", &m_NoTerTextures) != -1)
	{
		tertext.resize(m_NoTerTextures);

		for (int i = 0; i < m_NoTerTextures; ++i)
		{
			//f = false;
			while (fscanf(pFile, "ID %d FILE %s\n", &d, text) == 2)
			{
				tertext[i].Init(nullptr, text);
				++i;
				//f = true;
			}

		}
		
	}
	char vs[50], fs[50];

	if (fscanf_s(pFile, "\n#TerrainShaders: %d\n", &m_NoTerShaders) != -1)
	{
		tershaders.resize(m_NoTerShaders);

		for (int i = 0; i < m_NoTerShaders; ++i)
		{
			while (fscanf(pFile, "ID %d VS %s FS %s\n", &d, vs, fs) == 3)
			{
				tershaders[i].Init(vs, fs);
			}
		}

	}

	char skybox[50];

	if (fscanf_s(pFile, "#Skybox: %d\n", &m_NoSky) != -1)
	{
		sky.resize(m_NoSky);

		for (int i = 0; i < m_NoSky; ++i)
		{
			while (fscanf(pFile, "ID %d FILE %s\n", &d, skybox) == 2)
			{
				sky[i].Init(nullptr, skybox);
			}
		}
	}

	char text1[50];

	if (fscanf_s(pFile, "\n#CubeMap: %d\n", &m_NoCubeTextures) != -1)
	{
		skytext.resize(m_NoCubeTextures);

		for (int i = 0; i < m_NoCubeTextures; ++i)
		{
			while (fscanf(pFile, "ID %d FILE %s\n", &d, text1) == 2)
			{
				skytext[i].InitCubeTexture(nullptr, text1);

				//faces.push_back(text1);
				
			}

		}

	}

	char vs1[50], fs1[50];

	if (fscanf_s(pFile, "\n#CubeMapShaders: %d\n", &m_NoSkyShaders) != -1)
	{
		skyshaders.resize(m_NoSkyShaders);

		for (int i = 0; i < m_NoSkyShaders; ++i)
		{
			while (fscanf(pFile, "ID %d VS %s FS %s\n", &d, vs1, fs1) == 3)
			{
				skyshaders[i].Init(vs1, fs1);
			}
		}

	}

	char fire[50];

	if (fscanf_s(pFile, "#Fire: %d\n", &mNoFires) != -1)
	{
		fireVect.resize(mNoFires);

		for (int i = 0; i < mNoFires; ++i)
		{
			while (fscanf(pFile, "ID %d FILE %s\n", &d, fire) == 2)
			{
				fireVect[i].Init(nullptr, fire);
			}
		}
	}

	char firetext[50];
	char ty[50];
	GLint type;

	if (fscanf_s(pFile, "\n#FireTextures: %d\n", &mNoFTextures) != -1)
	{
		firetextV.resize(mNoFTextures);

		for (int i = 0; i < mNoFTextures; ++i)
		{
			while (fscanf(pFile, "ID %d FILE %s %s\n", &d, firetext, ty) == 3)
			{
				if (strncmp(ty, "GL_CLAMP_TO_EDGE", strlen("GL_CLAMP_TO_EDGE")) == 0)
				{
					type = GL_CLAMP_TO_EDGE;
				}
				else
				{
					type = GL_REPEAT;
				}
				//firetextV[i].Init(nullptr, firetext);
				firetextV[i].InitFire(nullptr, firetext, type);
				++i;
			}

		}

	}
	char vsf[50], fsf[50];

	if (fscanf_s(pFile, "\n#FireShaders: %d\n", &mNoFShaders) != -1)
	{
		fireshaderV.resize(mNoFShaders);

		for (int i = 0; i < mNoFShaders; ++i)
		{
			while (fscanf(pFile, "ID %d VS %s FS %s\n", &d, vsf, fsf) == 3)
			{
				fireshaderV[i].Init(vsf, fsf);
			}
		}

	}


	fclose(pFile);

	return true;

}

//FILE "../Resources/Models/Marine.nfg"


Model* ResourceManager::GetModelbyID(unsigned int Id)
{
	if (Id >= models.size())
		return nullptr;
	return &models[Id];
}



Texture* ResourceManager::Get2DTexturebyID(int ID)
{
	if (ID >= textures.size())
		return nullptr;
	return &textures[ID];
}

Texture* ResourceManager::GetCubeTexturebyID(int ID)
{
	if (ID >= skytext.size())
		return nullptr;
	return &skytext[ID];
}

Texture * ResourceManager::GetTerrainTexturebyID(int ID)
{
	if (ID > tertext.size())
		return nullptr;
	return &tertext[ID];
}

Texture * ResourceManager::GetFireTexturebyID(int ID)
{
	if (ID >= firetextV.size())
		return nullptr;
	return &firetextV[ID];
}

Shaders * ResourceManager::GetTerShaderbyID(int ID)
{
	if (ID > tershaders.size())
		return nullptr;
	return &tershaders[ID];
}

Shaders* ResourceManager::GetShaderbyID(int ID)
{
	if (ID >= shaders.size())
		return nullptr;
	return &shaders[ID];
}

Shaders * ResourceManager::GetSkyShaderbyID(int ID)
{
	if (ID >= skyshaders.size())
		return nullptr;
	return &skyshaders[ID];
}

Shaders * ResourceManager::GetFireShaderbyID(int ID)
{
	if (ID >= fireshaderV.size())
		return nullptr;
	return &fireshaderV[ID];
}

Terrain* ResourceManager::GetTerrainbyID(int ID)
{
	if (ID > terrains.size())
		return nullptr;
	return &terrains[ID];
}

Sky * ResourceManager::GetSkybyID(int ID)
{
	if (ID >= sky.size())
		return nullptr;
	return &sky[ID];
}

FireEffect * ResourceManager::GetFirebyID(int ID)
{
	if (ID >= fireVect.size())
		return nullptr;
	return &fireVect[ID];;
}
