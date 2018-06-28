#include "stdafx.h"
#include "Terrain.h"
#include "SceneManager.h"

Terrain::Terrain()
{

}

Terrain::Terrain(const Terrain & obj)
{

}

Terrain::~Terrain()
{

}

bool Terrain::LoadTerrain(const char * const filename, std::vector<Vertex>& vertices, std::vector<Indices>& indices)
{
	FILE* file = fopen(filename, "r");
	if (!file)
	{
		return false;
	}

	int nVertices;
	if (fscanf_s(file, "NrVertices: %d\n", &nVertices) != 1)
	{
		return false;
	}

	for (int i = 0; i < nVertices; ++i)
	{
		if (fscanf_s(file, " %*d. pos:[%f, %f, %f]; norm:[%*f, %*f, %*f]; binorm:[%*f, %*f, %*f]; tgt:[%*f, %*f, %*f]; uv:[%f, %f];\n",
			&verticesData.pos.x, &verticesData.pos.y, &verticesData.pos.z, &verticesData.uv.x, &verticesData.uv.y) == 5)
		{
			vertices.push_back(verticesData);
		}
	}

	int nIndices;
	if (fscanf_s(file, "NrIndices: %d\n", &nIndices) != 1)
	{
		return false;
	}

	for (int i = 0; i < nIndices; ++i)
	{
		if (fscanf_s(file, "%*d.   %d,    %d,    %d   ",
			&indicesD.f, &indicesD.s, &indicesD.t) == 3)
		{
			indices.push_back(indicesD);
		}
		else
		{
			//
		}
	}

	fclose(file);
	return true;
}

int Terrain::Init(ESContext* esContext, const char* const filename)
{
	std::vector<Vertex> vertData;
	std::vector<Indices> indData;
	bool result;

	result = LoadTerrain(filename, vertData, indData);

	indexCount = indData.size() * 3;

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertData.size(), &vertData[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices) * indData.size(), &indData[0], GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	return 0;
}

void Terrain::Draw(ESContext* esContext, Texture* texture, Texture* texture1, Texture* texture2, Texture* texture3, Shaders* shader, Matrix& model)
{
	auto sm = SceneManager::GetInstance();
	auto camera = sm->getCamera();
	Vector3 cameraPos = camera->getCamPos();

	glUseProgram(shader->program);

	mvp = model * camera->getlookAtMatrix() * camera->getPerspectiveMatrix();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glUniformMatrix4fv(shader->MVP, 1, false, (GLfloat*)&mvp);
	glUniform3fv(shader->campos, 1, (GLfloat*)&cameraPos);
	
	Texture::ResetTextureUnitAllocator();

	texture->Bind(shader->uniformLocation);
	texture1->Bind(shader->t1);
	texture2->Bind(shader->t2);
	texture3->Bind(shader->t3);

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

	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Terrain::DrawMulti(ESContext* esContext, Texture* texture1, Texture* texture2, Texture* texture3, Texture* texture4, Shaders* shader, Matrix& model)
{
	auto sm = SceneManager::GetInstance();
	auto camera = sm->getCamera();
	auto cameraPos = camera->getCamPos();

	glUseProgram(shader->program);

	mvp = model * camera->getlookAtMatrix() * camera->getPerspectiveMatrix();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glUniformMatrix4fv(shader->MVP, 1, false, (GLfloat*)&mvp);
	//	glUniform3f(shader->campos, 1, false, (GLfloat*)&cameraPos);

	texture1->Draw(esContext);

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

	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Terrain::CleanUp()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
}




