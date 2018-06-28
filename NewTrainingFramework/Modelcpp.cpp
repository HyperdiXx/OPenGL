#include "stdafx.h"
#include "Model.h"
#include "SceneManager.h"


Model::Model()
{
	//numVert = 240;
	//numInd = 585;
	//model.SetIdentity();
}

Model::~Model()
{

}


bool Model::LoadFile(const char* const filename, std::vector<Vertex>& vertex, std::vector<Indices>& indices)
{
	std::vector<unsigned int> vertexIndexes, uvIndexes;

	FILE *pFile = fopen(filename, "r");
	if (!pFile)
	{
		return false;
	}

	int nVertices;
	if (fscanf_s(pFile, "NrVertices: %d\n", &nVertices) != 1)
	{
		return false;
	}

	for (int i = 0; i < nVertices; ++i)
	{
		if (fscanf_s(pFile, " %*d. pos:[%f, %f, %f]; norm:[%f, %f, %f]; binorm:[%*f, %*f, %*f]; tgt:[%*f, %*f, %*f]; uv:[%f, %f];\n",
			&verticesData.pos.x, &verticesData.pos.y, &verticesData.pos.z, &verticesData.normal.x, &verticesData.normal.y, &verticesData.normal.z, &verticesData.uv.x, &verticesData.uv.y) == 8)
		{
			vertex.push_back(verticesData);
		}
	}

	int nIndices;
	if (fscanf_s(pFile, "NrIndices: %d\n", &nIndices) != 1)
	{
		return false;
	}

	for (int i = 0; i < nIndices; ++i)
	{
		if (fscanf_s(pFile, "%*d.   %d,    %d,    %d   ",
			&indicesD.f, &indicesD.s, &indicesD.t) == 3)
		{
			indices.push_back(indicesD);
		}
		else
		{
			//
		}
	}

	fclose(pFile);

	return true;
}



int Model::Init(ESContext* escontext)
{
	/*Vertex verticesData[36];
	Indices indData[12];

	sizeind = 36;

	verticesData[0].pos.x = -1.0f;	verticesData[0].pos.y = -1.0f; verticesData[0].pos.z = 1.0f;
	verticesData[1].pos.x = 1.0f;	verticesData[1].pos.y = -1.0f; verticesData[1].pos.z = 1.0f;
	verticesData[2].pos.x = 1.0f;	verticesData[2].pos.y = 1.0f; verticesData[2].pos.z = 1.0f;
	verticesData[3].pos.x = -1.0f;	verticesData[3].pos.y = 1.0f; verticesData[3].pos.z = 1.0f;
	verticesData[4].pos.x = -1.0f;	verticesData[4].pos.y = -1.0f; verticesData[4].pos.z = -1.0f;
	verticesData[5].pos.x = 1.0f;	verticesData[5].pos.y = -1.0f; verticesData[5].pos.z = -1.0f;
	verticesData[6].pos.x = 1.0f;	verticesData[6].pos.y = 1.0f; verticesData[6].pos.z = -1.0f;
	verticesData[7].pos.x = -1.0f;	verticesData[7].pos.y = 1.0f; verticesData[7].pos.z = -1.0f;

	
	indData[0].f = 0; indData[0].s = 1; indData[0].t = 2;
	indData[1].f = 2; indData[1].s = 3; indData[1].t = 0;
	indData[2].f = 1; indData[2].s = 5; indData[2].t = 6;
	indData[3].f = 6; indData[3].s = 2; indData[3].t = 1;
	indData[4].f = 7; indData[4].s = 6; indData[4].t = 5;
	indData[5].f = 5; indData[5].s = 4; indData[5].t = 7;
	indData[6].f = 4; indData[6].s = 0; indData[6].t = 3;
	indData[7].f = 3; indData[7].s = 7; indData[7].t = 4;
	indData[8].f = 4; indData[8].s = 5; indData[8].t = 1;
	indData[9].f = 1; indData[9].s = 0; indData[9].t = 4;
	indData[10].f = 3; indData[10].s = 2; indData[10].t = 6;
	indData[11].f = 6; indData[11].s = 7; indData[11].t = 3;


	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 36, verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices) * 24, indData, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/


	return 0;
}

int Model::InitModel(ESContext * escontext, const char * const filename)
{
	std::vector<Indices> indiceData;
	std::vector<Vertex> vertData;
	bool result;
	result = LoadFile(filename, vertData, indiceData);

	sizeind = indiceData.size() * 3;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertData.size(), &vertData[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices) * indiceData.size(), &indiceData[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return 0;
}

int Model::InitSky(ESContext * escontext, Shaders* shader, Texture* texture)
{
	//std::vector<Indices> indiceData;


	//sizeind = indiceData.size() * 3;
	
	/*0.000059f, 1.0f - 0.000004f,
		0.000103f, 1.0f - 0.336048f,
		0.335973f, 1.0f - 0.335903f,
		1.000023f, 1.0f - 0.000013f,
		0.667979f, 1.0f - 0.335851f,
		0.999958f, 1.0f - 0.336064f,
		0.667979f, 1.0f - 0.335851f,
		0.336024f, 1.0f - 0.671877f,
		0.667969f, 1.0f - 0.671889f,
		1.000023f, 1.0f - 0.000013f,
		0.668104f, 1.0f - 0.000013f,
		0.667979f, 1.0f - 0.335851f,
		0.000059f, 1.0f - 0.000004f,
		0.335973f, 1.0f - 0.335903f,
		0.336098f, 1.0f - 0.000071f,
		0.667979f, 1.0f - 0.335851f,
		0.335973f, 1.0f - 0.335903f,
		0.336024f, 1.0f - 0.671877f,
		1.000004f, 1.0f - 0.671847f,
		0.999958f, 1.0f - 0.336064f,
		0.667979f, 1.0f - 0.335851f,
		0.668104f, 1.0f - 0.000013f,
		0.335973f, 1.0f - 0.335903f,
		0.667979f, 1.0f - 0.335851f,
		0.335973f, 1.0f - 0.335903f,
		0.668104f, 1.0f - 0.000013f,
		0.336098f, 1.0f - 0.000071f,
		0.000103f, 1.0f - 0.336048f,
		0.000004f, 1.0f - 0.671870f,
		0.336024f, 1.0f - 0.671877f,
		0.000103f, 1.0f - 0.336048f,
		0.336024f, 1.0f - 0.671877f,
		0.335973f, 1.0f - 0.335903f,
		0.667969f, 1.0f - 0.671889f,
		1.000004f, 1.0f - 0.671847f,
		0.667979f, 1.0f - 0.335851f
		*/

	std::vector<char*> f;
	texture->InitCubeTexture(escontext, "../Resources/Textures/envMap.tga");

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticesData), &verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return shader->Init("../Resources/Shaders/Skybox.vs", "../Resources/Shaders/Skybox.fs");

}

void Model::DrawSky(ESContext* escontext, Texture* texture, Shaders* shader, Matrix& model)
{
	auto sm = SceneManager::GetInstance();
	auto camera = sm->getCamera();

	glUseProgram(shader->program);

	//mvp = res * lookAt * projection;

	mvp = model * camera->getlookAtMatrix() * camera->getPerspectiveMatrix();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	glUniformMatrix4fv(shader->MVP, 1, false, (GLfloat*)&mvp);

	texture->DrawCube(escontext);

	GLfloat* ptr = (GLfloat*)0;

	if (shader->positionAttribute != -1)
	{
		glEnableVertexAttribArray(shader->positionAttribute);
		glVertexAttribPointer(shader->positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr);
	}

	if (shader->colorAttribute != -1)
	{
		glEnableVertexAttribArray(shader->colorAttribute);
		glVertexAttribPointer(shader->colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 3);
	}

	if (shader->textureAttribute != -1)
	{
		glEnableVertexAttribArray(shader->textureAttribute);
		glVertexAttribPointer(shader->textureAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 6);
	}

	glDrawElements(GL_ARRAY_BUFFER, 36, GL_FLOAT, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}



void Model::Draw(ESContext* escontext, Texture* texture, Shaders* shader, Matrix& model)
{	
	auto sm = SceneManager::GetInstance();
	auto camera = sm->getCamera();

	glUseProgram(shader->program);

	//mvp = res * lookAt * projection;

	mvp = model * camera->getlookAtMatrix() * camera->getPerspectiveMatrix();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glUniformMatrix4fv(shader->MVP, 1, false, (GLfloat*)&mvp);
	glUniformMatrix4fv(shader->model, 1, false, (GLfloat*)&model);
	glUniformMatrix4fv(shader->view, 1, false, (GLfloat*)&camera->getlookAtMatrix());
	glUniformMatrix4fv(shader->projection, 1, false, (GLfloat*)&camera->getPerspectiveMatrix());


	Texture::ResetTextureUnitAllocator();

	texture->Bind(shader->uniformLocation);

	//texture->Draw(escontext);

	GLfloat* ptr = (GLfloat*)0;

	if (shader->positionAttribute != -1)
	{
		glEnableVertexAttribArray(shader->positionAttribute);
		glVertexAttribPointer(shader->positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr);
	}

	if (shader->colorAttribute != -1)
	{
		glEnableVertexAttribArray(shader->colorAttribute);
		glVertexAttribPointer(shader->colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 3);
	}

	if (shader->textureAttribute != -1)
	{
		glEnableVertexAttribArray(shader->textureAttribute);
		glVertexAttribPointer(shader->textureAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 6);
	}

	if (shader->normal != -1)
	{
		glEnableVertexAttribArray(shader->normal);
		glVertexAttribPointer(shader->normal, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 11);
	}


	glDrawElements(GL_TRIANGLES, sizeind, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Model::DrawCube(ESContext* escontext, Texture* texture, Shaders* shader, Matrix& model)
{
	auto sm = SceneManager::GetInstance();
	auto camera = sm->getCamera();

	glUseProgram(shader->program);

	//mvp = res * lookAt * projection;

	//viewprojection = camera->getlookAtMatrix() * camera->getPerspectiveMatrix();

	mvp = model * camera->getlookAtMatrix() * camera->getPerspectiveMatrix();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glUniformMatrix4fv(shader->MVP, 1, false, (GLfloat*)&mvp);
	//glUniformMatrix4fv(shader->viewprojection, 1, false, (GLfloat*)&viewprojection);
	//glUniformMatrix4fv(shader->model, 1, false, (GLfloat*)&model);


	//Texture::ResetTextureUnitAllocator();

	//texture->Bind(shader->uniformLocation);

	//texture->Draw(escontext);

	GLfloat* ptr = (GLfloat*)0;

	if (shader->positionAttribute != -1)
	{
		glEnableVertexAttribArray(shader->positionAttribute);
		glVertexAttribPointer(shader->positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr);
	}

	if (shader->colorAttribute != -1)
	{
		glEnableVertexAttribArray(shader->colorAttribute);
		glVertexAttribPointer(shader->colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 3);
	}

	if (shader->textureAttribute != -1)
	{
		glEnableVertexAttribArray(shader->textureAttribute);
		glVertexAttribPointer(shader->textureAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 6);
	}

	glDrawElements(GL_TRIANGLES, sizeind, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void Model::Update(ESContext* escontext, float deltatime)
{
	static float elapsedTime = 0.f;

	//speed += deltatime;
	//res = res.SetRotationY(elapsedTime * 3.14f);

	elapsedTime += deltatime;
}

void Model::CleanUp()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
}
