#include "stdafx.h"
#include "Sky.h"
#include "SceneManager.h"
#include "Globals.h"

bool Sky::LoadSky(const char * const filename, std::vector<Vertex>& vertices)
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

	/*for (int i = 0; i < nVertices; ++i)
	{
		if (fscanf_s(file, " %*d. pos:[%f, %f, %f]; norm:[%*f, %*f, %*f]; binorm:[%*f, %*f, %*f]; tgt:[%*f, %*f, %*f]; uv:[%f, %f];\n",
			&verticesData.pos.x, &verticesData.pos.y, &verticesData.pos.z, &verticesData.uv.x, &verticesData.uv.y) == 5)
		{
			vertices.push_back(verticesData);
		}
	}*/

	fclose(file);

	return true;
}

int Sky::Init(ESContext * esContext, const char * const filename)
{

	auto sm = SceneManager::GetInstance();
	auto camera = sm->getCamera();
	auto cameraPos = camera->getCamPos();


	Matrix translation, scale;
	translation.SetTranslation(cameraPos);
	scale = scale.SetScale(60.0, 50.0, 50.0);
	model = scale;
	//bool result = LoadSky(filename, vertData);
	Matrix v;
	v.SetPerspective(0.721321, float(Globals::screenWidth) / float(Globals::screenHeight), 0.1, 100.0);

	view = v;

	Vertex verticesData[36];
	Indices indData[12];

	verticesData[0].pos.x = -1.0f;	verticesData[0].pos.y = -1.0f; verticesData[0].pos.z = 1.0f;
	verticesData[1].pos.x = 1.0f;	verticesData[1].pos.y = -1.0f; verticesData[1].pos.z = 1.0f;
	verticesData[2].pos.x = 1.0f;	verticesData[2].pos.y = 1.0f; verticesData[2].pos.z = 1.0f;
	verticesData[3].pos.x = -1.0f;	verticesData[3].pos.y = 1.0f; verticesData[3].pos.z = 1.0f;
	verticesData[4].pos.x = -1.0f;	verticesData[4].pos.y = -1.0f; verticesData[4].pos.z = -1.0f;
	verticesData[5].pos.x = 1.0f;	verticesData[5].pos.y = -1.0f; verticesData[5].pos.z = -1.0f;
	verticesData[6].pos.x = 1.0f;	verticesData[6].pos.y = 1.0f; verticesData[6].pos.z = -1.0f;
	verticesData[7].pos.x = -1.0f;	verticesData[7].pos.y = 1.0f; verticesData[7].pos.z = -1.0f;

	/*verticesData[0].uv3.x = 1.0f;	verticesData[0].uv3.y = 0.0f;	verticesData[0].uv3.z = 0.0f;
	verticesData[1].uv3.x = 0.0f;	verticesData[1].uv3.y = 1.0f;	verticesData[1].uv3.z = 0.0f;
	verticesData[2].uv3.x = 0.0f;	verticesData[2].uv3.y = 0.0f;	verticesData[2].uv3.z = 1.0f;
	verticesData[3].uv3.x = 1.0f;	verticesData[3].uv3.y = 1.0f;	verticesData[3].uv3.z = 1.0f;

	verticesData[4].uv3.x = 1.0f;	verticesData[4].uv3.y = 0.0f;	verticesData[4].uv3.z = 0.0f;
	verticesData[5].uv3.x = 0.0f;	verticesData[5].uv3.y = 1.0f;	verticesData[5].uv3.z = 0.0f;
	verticesData[6].uv3.x = 0.0f;	verticesData[6].uv3.y = 0.0f;	verticesData[6].uv3.z = 1.0f;
	verticesData[7].uv3.x = 1.0f;	verticesData[7].uv3.y = 1.0f;	verticesData[7].uv3.z = 1.0f;*/

	/*verticesData[8].uv3.x = 1.0f;	verticesData[8].uv3.y = 1.0f;	verticesData[8].uv3.z = 1.0f;
	verticesData[9].uv3.x = 1.0f;	verticesData[9].uv3.y = 1.0f;	verticesData[9].uv3.z = 1.0f;
	verticesData[10].uv3.x = 1.0f;	verticesData[10].uv3.y = 1.0f;	verticesData[10].uv3.z = 1.0f;
	verticesData[11].uv3.x = 1.0f;	verticesData[11].uv3.y = 1.0f;	verticesData[11].uv3.z = 1.0f;

	verticesData[12].uv3.x = 0.0f;	verticesData[12].uv3.y = 0.0f;	verticesData[12].uv3.z = 1.0f;
	verticesData[13].uv3.x = 1.0f;	verticesData[13].uv3.y = 0.0f;	verticesData[13].uv3.z = 1.0f;
	verticesData[14].uv3.x = 1.0f;	verticesData[14].uv3.y = 1.0f;	verticesData[14].uv3.z = 1.0f;
	verticesData[15].uv3.x = 0.0f;	verticesData[15].uv3.y = 1.0f;	verticesData[15].uv3.z = 1.0f;

	verticesData[16].uv3.x = 0.0f;	verticesData[16].uv3.y = 0.0f;	verticesData[16].uv3.z = 1.0f;
	verticesData[17].uv3.x = 1.0f;	verticesData[17].uv3.y = 0.0f;	verticesData[17].uv3.z = 1.0f;
	verticesData[18].uv3.x = 1.0f;	verticesData[18].uv3.y = 1.0f;	verticesData[18].uv3.z = 1.0f;
	verticesData[19].uv3.x = 0.0f;	verticesData[19].uv3.y = 1.0f;	verticesData[19].uv3.z = 1.0f;

	verticesData[20].uv3.x = 0.0f;	verticesData[20].uv3.y = 0.0f;	verticesData[20].uv3.z = 1.0f;
	verticesData[21].uv3.x = 1.0f;	verticesData[21].uv3.y = 0.0f;	verticesData[21].uv3.z = 1.0f;
	verticesData[22].uv3.x = 1.0f;	verticesData[22].uv3.y = 1.0f;	verticesData[22].uv3.z = 1.0f;
	verticesData[23].uv3.x = 0.0f;	verticesData[23].uv3.y = 1.0f;	verticesData[23].uv3.z = 1.0f;

	verticesData[24].uv3.x = 0.0f;	verticesData[24].uv3.y = 0.0f;	verticesData[24].uv3.z = 1.0f;
	verticesData[25].uv3.x = 1.0f;	verticesData[25].uv3.y = 0.0f;	verticesData[25].uv3.z = 1.0f;
	verticesData[26].uv3.x = 1.0f;	verticesData[26].uv3.y = 1.0f;	verticesData[26].uv3.z = 1.0f;
	verticesData[27].uv3.x = 0.0f;	verticesData[27].uv3.y = 1.0f;	verticesData[27].uv3.z = 1.0f;

	verticesData[28].uv3.x = 0.0f;	verticesData[28].uv3.y = 0.0f;	verticesData[28].uv3.z = 1.0f;
	verticesData[29].uv3.x = 1.0f;	verticesData[29].uv3.y = 0.0f;	verticesData[29].uv3.z = 1.0f;
	verticesData[30].uv3.x = 1.0f;	verticesData[30].uv3.y = 1.0f;	verticesData[30].uv3.z = 1.0f;
	verticesData[31].uv3.x = 0.0f;	verticesData[31].uv3.y = 1.0f;	verticesData[31].uv3.z = 1.0f;

	verticesData[32].uv3.x = 0.0f;	verticesData[32].uv3.y = 0.0f;	verticesData[32].uv3.z = 1.0f;
	verticesData[33].uv3.x = 1.0f;	verticesData[33].uv3.y = 0.0f;	verticesData[33].uv3.z = 1.0f;
	verticesData[34].uv3.x = 1.0f;	verticesData[34].uv3.y = 1.0f;	verticesData[34].uv3.z = 1.0f;
	verticesData[35].uv3.x = 0.0f;	verticesData[35].uv3.y = 1.0f;	verticesData[35].uv3.z = 1.0f;*/

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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



	return 0;
}

void Sky::Draw(ESContext * esContext, Texture* texture, Shaders* shader)
{
	auto sm = SceneManager::GetInstance();
	auto camera = sm->getCamera();
	auto cameraPos = camera->getCamPos();

	glUseProgram(shader->program);

	mvp = view.SetIdentity() * camera->getPerspectiveMatrix();

	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);

	glUniformMatrix4fv(shader->MVP, 1, false, (GLfloat*)&mvp);
	glUniform3fv(shader->campos, 1, (GLfloat*)&cameraPos);

	Texture::ResetTextureUnitAllocator();

	texture->Bind(shader->cubeTexture);

	GLfloat* ptr = (GLfloat*)0;

	if (shader->positionAttribute != -1)
	{
		glEnableVertexAttribArray(shader->positionAttribute);
		glVertexAttribPointer(shader->positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr);
	}

	/*if (shader->textureAttribute3 != -1)
	{
		glEnableVertexAttribArray(shader->textureAttribute3);
		glVertexAttribPointer(shader->textureAttribute3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 6);
	}*/

	//glDrawArrays(GL_TRIANGLES, 0, 36);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void Sky::CleanUp()
{
	glDeleteBuffers(1, &vertexBuffer);
	glDeleteBuffers(1, &indexBuffer);
}
