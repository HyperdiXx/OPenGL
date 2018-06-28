#pragma once

#ifndef _OBJECT_
#define _OBJECT_


#include "Texture.h"
#include "Shaders.h"
#include "Model.h"
#include "Vertex.h"
#include "Terrain.h"
#include "Fire.h"
#include "ResourceManager.h"

struct Vertex;


class Object
{
private:
	struct Position
	{
		float  x, y, z;
	};

	struct Color
	{
		float x, y, z;
	};
	struct LightposDir
	{
		float x, y, z;
	};
public:
	Object();
	Object(const Object&) {}
	~Object();

	bool Init(ESContext*);
	void Draw(ESContext*);
	void Update(ESContext*, float);
	void CleanUp();
	Vector3 SetPos(Vector3, std::vector<Position>&);
	Vector3 SetRotation(Vector3, std::vector<Position>&);
	Vector3 SetScale(Vector3, std::vector<Position>&);

	Matrix CalculateWordlMatrix();
	Matrix CalculateWordlMatrixTer();
	char* LoadTextures();
	Matrix SetTranslation(Vector3 pos);
	Matrix SetRotation(float, float, float, float);
	Matrix SetScale(Vector3 sclaeNew);
	Vector3 pos, rotationVector, scaleVector;

	void Load(char* filename);

	float cameraFov, cameraNear, cameraFar, cameraSpeed;

protected:
	Matrix translation, rotation, scale, model, mvp, lookAt, projection, worldterrain, matrixFire, model1;
private:
	char* vs, *fs;
	unsigned int nOTextures, nOobjects, countTextures, countLight, mNoTerrains, mNoFire, countTexturesTer;
	std::vector<unsigned int> ID, models, lightID;
	std::vector<Position> positions, rotations, scales, positionsTer, rotationsTer, scalesTer, posFire, rotationFire, scalesFire;
	std::vector<Color> loght, colorColor;
	std::vector<LightposDir> posdirLight;
	std::vector<float> radiusLight, speedLight;
	std::vector<std::string> typeMove;
	float weig;
	std::vector<Matrix> worldmatrix;

	Texture* m_2DTexture,* m_cubeTexture, *m_TerTexture[3], *m_FireTexture[3];
	Model* m_ModelObj, *m_Cube;
	Sky* m_Sky;
	Shaders* m_ShaderObj, *m_TerShader, *m_cubeShader, *m_FireShader, *m_cubshader;
	Terrain* m_Terrain;
	FireEffect* m_Fire;
};
#endif // !_OBJECT_

