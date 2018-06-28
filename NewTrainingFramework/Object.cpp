#include "stdafx.h"
#include "Object.h"


Object::Object()
{
	m_ModelObj = nullptr;
	m_ShaderObj = nullptr;
	m_2DTexture = nullptr;
	m_cubeTexture = nullptr;

	pos = Vector3(0.0, 0.0, 0.0);
	rotationVector = Vector3(0.0, 0.0, 0.0);
	scaleVector = Vector3(1.0, 1.0, 1.0);
}

Object::~Object()
{

}

bool Object::Init(ESContext* esContext)
{
	bool result;
	//std::vector<Indices> indicesData;
	//std::vector<Vertex> verticesData;

	ResourceManager::CreateInstance();
	ResourceManager::GetInstance()->LoadRMText("../Resources/RM.txt");



	Load("../Resources/SM.txt");

	m_Cube = ResourceManager::GetInstance()->GetModelbyID(0);
	m_cubeTexture = ResourceManager::GetInstance()->Get2DTexturebyID(0);
	m_cubshader = ResourceManager::GetInstance()->GetShaderbyID(0);

	Matrix scale;
	scale = scale.SetScale(5.0, 5.0, 5.0);
	Matrix ma = ma.SetTranslation(-10.0, 0.0, 0.0);

	model1 = scale * ma;

	CalculateWordlMatrix();
	//CalculateWordlMatrix(model1);
	CalculateWordlMatrixTer();

	return true;
}

Vector3 Object::SetPos(Vector3 possit, std::vector<Position>& a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		possit.x = a[i].x;
		possit.y = a[i].y;
		possit.z = a[i].z;
	}

	return possit;
}

Vector3 Object::SetRotation(Vector3 r, std::vector<Position>& a)
{

	for (int i = 0; i < a.size(); ++i)
	{
		r.x = a[i].x;
		r.y = a[i].y;
		r.z = a[i].z;
	}
	return r;
}

Vector3 Object::SetScale(Vector3 sc, std::vector<Position>& a)
{
	for (int i = 0; i < a.size(); ++i)
	{
		sc.x = a[i].x;
		sc.y = a[i].y;
		sc.z = a[i].z;
	}
	return sc;
}

void Object::Draw(ESContext* esContext)
{
	glDisable(GL_DEPTH_TEST);
	glDepthMask(GL_FALSE);

	m_Sky->Draw(esContext, ResourceManager::GetInstance()->GetCubeTexturebyID(0), ResourceManager::GetInstance()->GetSkyShaderbyID(0));

	glDepthMask(GL_TRUE);
	glEnable(GL_DEPTH_TEST);

	m_Terrain->Draw(esContext, ResourceManager::GetInstance()->GetTerrainTexturebyID(0), ResourceManager::GetInstance()->GetTerrainTexturebyID(1), ResourceManager::GetInstance()->GetTerrainTexturebyID(2), ResourceManager::GetInstance()->GetTerrainTexturebyID(3), ResourceManager::GetInstance()->GetTerShaderbyID(0), worldterrain);

	m_Cube->Draw(esContext, ResourceManager::GetInstance()->Get2DTexturebyID(0), ResourceManager::GetInstance()->GetShaderbyID(0), model1);

	m_ModelObj->Draw(esContext, ResourceManager::GetInstance()->Get2DTexturebyID(1), ResourceManager::GetInstance()->GetShaderbyID(1), model);
		
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	m_Fire->Draw(esContext, ResourceManager::GetInstance()->GetFireTexturebyID(0), ResourceManager::GetInstance()->GetFireTexturebyID(1), ResourceManager::GetInstance()->GetFireTexturebyID(2), ResourceManager::GetInstance()->GetFireShaderbyID(0));
	
	glDisable(GL_BLEND);
	
}


void Object::Update(ESContext* esContext, float deltaTime)
{
	m_ModelObj->Update(esContext, deltaTime);
	m_Fire->Update(esContext, deltaTime, ResourceManager::GetInstance()->GetFireShaderbyID(0));
}

Matrix Object::CalculateWordlMatrix()
{
	Vector3 p, r, s;

	//p.resize(positions.size());
	//r.resize(rotations.size());
	//s.resize(scales.size());

	p = SetPos(p, positions);
	r = SetRotation(r, rotations);
	s = SetScale(s, scales);
	//Matrix translation1, rotation1, scale1;
	translation = translation.SetTranslation(p);
	rotation = rotation.SetRotationAngleAxis(0, r.x, r.y, r.z);
	scale = scale.SetScale(s);

	model = translation * rotation * scale;

	return model;
}

Matrix Object::CalculateWordlMatrixTer()
{
	Vector3 p, r, s;
	p = SetPos(p, positionsTer);
	r = SetRotation(r, rotationsTer);
	s = SetScale(s, scalesTer);
	Matrix translation1, rotation1, scale1;
	translation1 = translation1.SetTranslation(p);
	rotation1 = rotation1.SetRotationAngleAxis(0, r.x, r.y, r.z);
	scale1 = scale1.SetScale(s);

	worldterrain = translation1 * rotation1 * scale1;

	return worldterrain;
}

Matrix Object::SetTranslation(Vector3 pos)
{
	translation = translation.SetTranslation(pos);
	return translation;
}

Matrix Object::SetRotation(float a, float x, float y, float z)
{
	rotation = rotation.SetRotationAngleAxis(a,x,y,z);
	return rotation;
}

Matrix Object::SetScale(Vector3 sclaeNew)
{
	scale = scale.SetScale(sclaeNew);
	return scale;
}


void Object::CleanUp()
{
	//m_ModelObj->CleanUp();


	/*if (m_ShaderObj)
	{
		delete m_ShaderObj;
		m_ShaderObj = 0;
	}

	if (m_2DTexture)
	{
		delete m_2DTexture;
		m_2DTexture = 0;
	}

	if (m_ModelObj)
	{
		delete m_ModelObj;
		m_ModelObj = 0;
	}

	if (m_cubeTexture)
	{
		delete m_cubeTexture;
		m_cubeTexture = 0;
	}*/

	
	ResourceManager::GetInstance()->GetModelbyID(0)->CleanUp();
	ResourceManager::GetInstance()->Get2DTexturebyID(0)->CleanUp();
	ResourceManager::GetInstance()->GetTerrainbyID(0)->CleanUp();
	for (int i = 0; i < countTexturesTer; ++i)
	{
		ResourceManager::GetInstance()->GetTerrainTexturebyID(i)->CleanUp();
	}
	ResourceManager::GetInstance()->GetSkybyID(0)->CleanUp();
	ResourceManager::GetInstance()->GetCubeTexturebyID(0)->CleanUp();
	ResourceManager::GetInstance()->GetFirebyID(0)->CleanUp();
	for (int i = 0; i < 3; ++i)
	{
		ResourceManager::GetInstance()->GetFireTexturebyID(i)->CleanUp();
	}

}


void Object::Load(char * filename)
{

	FILE* pFile = fopen(filename, "r+");
	if (!pFile)
	{
		//error
	}

	char in[50];
	char out[50];
	std::string output;
	unsigned int Objects, d, n, m,shaderN;
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
			"TEXTURE %d\n"
			"CUBETEXTURES %d\n"
			"SHADER %d\n"
			"LIGHTS %d\n"
			"POSITION %f, %f, %f\n"
			"ROTATION %f, %f, %f\n"
			"SCALE %f, %f, %f\n", &d, &m, &countTextures, &d, &shaderN, &countLight, &pos.x, &pos.y, &pos.z,
			&rot.x, &rot.y, &rot.z, &scale.x, &scale.y, &scale.z) == 15)
		{
			m_ModelObj = ResourceManager::GetInstance()->GetModelbyID(m);
			m_2DTexture = ResourceManager::GetInstance()->Get2DTexturebyID(countTextures);
			m_ShaderObj = ResourceManager::GetInstance()->GetShaderbyID(shaderN);

			positions.push_back(pos);
			rotations.push_back(rot);
			scales.push_back(scale);

			++i;
		}
	}

	int text1ter, text2ter;

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
			"SCALE %f, %f, %f\n", &d, &m, &countTexturesTer, &text1ter, &text2ter, &shaderN, &countLight, &pos.x, &pos.y, &pos.z,
			&rot.x, &rot.y, &rot.z, &scale.x, &scale.y, &scale.z) == 16)
		{
			m_Terrain = ResourceManager::GetInstance()->GetTerrainbyID(d);
			m_TerTexture[0] = ResourceManager::GetInstance()->GetTerrainTexturebyID(countTexturesTer);
			m_TerTexture[1] = ResourceManager::GetInstance()->GetTerrainTexturebyID(text1ter);
			m_TerTexture[2] = ResourceManager::GetInstance()->GetTerrainTexturebyID(text2ter);
			m_TerShader = ResourceManager::GetInstance()->GetTerShaderbyID(shaderN);

			positionsTer.push_back(pos);
			rotationsTer.push_back(rot);
			scalesTer.push_back(scale);
		}
	}

	countTexturesTer = countTexturesTer + text1ter + text2ter;

	if (fscanf_s(pFile, "\n#Skybox: %d\n", &d) != -1)
	{
		while (fscanf_s(pFile, "\nID %d\n"
			"MODEL %d\n"
			"TEXTURE %d\n"
			"SHADER %d\n"
			"LIGHT %d\n",
			 &d, &m, &countTextures, &shaderN, &countLight) == 5)
		{
			m_Sky = ResourceManager::GetInstance()->GetSkybyID(m);
			m_cubeTexture = ResourceManager::GetInstance()->GetCubeTexturebyID(countTextures);
			m_cubeShader = ResourceManager::GetInstance()->GetSkyShaderbyID(shaderN);
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
	int text1, text2;

	while (fscanf(pFile, "NEAR %f\nFAR %f\nFOV %f\nSPEED %f", &camNear, &camFar, &camFov, &camSpeed) == 4)
	{
		
	}

	if (fscanf_s(pFile, "\n#FIRE: %d", &mNoFire) != -1)
	{
		while (fscanf_s(pFile, "\nID %d\n"
			"MODEL %d\n"
			"TEXTURE %d\n"
			"TEXTURE %d\n"
			"TEXTURE %d\n"
			"SHADER %d\n"
			"LIGHT %d\n"
			"POSITION %f, %f, %f\n"
			"ROTATION %f, %f, %f\n"
			"SCALE %f, %f, %f\n", &d, &m, &countTextures, &text1, &text2, &shaderN, &countLight, &pos.x, &pos.y, &pos.z,
			&rot.x, &rot.y, &rot.z, &scale.x, &scale.y, &scale.z) == 16)
		{
			m_Fire = ResourceManager::GetInstance()->GetFirebyID(d);
			m_FireTexture[0] = ResourceManager::GetInstance()->GetFireTexturebyID(countTextures);
			m_FireTexture[1] = ResourceManager::GetInstance()->GetFireTexturebyID(text1);
			m_FireTexture[2] = ResourceManager::GetInstance()->GetFireTexturebyID(text2);
			m_FireShader = ResourceManager::GetInstance()->GetFireShaderbyID(shaderN);

			posFire.push_back(pos);
			rotationFire.push_back(rot);
			scalesFire.push_back(scale);
		}
	}

	/*if (fscanf_s(pFile, "#CAMERA\n") != -1)
	{

	}

	float camNear, camFar, camFov, camSpeed;

	while (fscanf(pFile, "NEAR %f\nFAR %f\nFOV %f\nSPEED %f", &camNear, &camFar, &camFov, &camSpeed) == 4)
	{
		cameraNear = camNear;
		cameraFar = camFar;
		cameraFov = camFov;
		cameraSpeed = camSpeed;
	}*/

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
	}*/

	fclose(pFile);

}
