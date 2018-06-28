#pragma once

#ifndef _SKY_
#define _SKY_

#include <vector>
#include <fstream>
#include <string>
#include "../Utilities//utilities.h"
#include "Vertex.h"
#include "Indices.h"
#include "Shaders.h"
#include "Texture.h"


struct Vertex;
struct Indices;

class Sky
{
public:
	Sky() {}
	Sky(const Sky& obj) {}
	~Sky() {}


	bool LoadSky(const char* const filename, std::vector<Vertex>& vertices);

	int Init(ESContext*, const char* const);
	void Draw(ESContext* esContext, Texture* texture, Shaders* shader);
	void CleanUp();

	Vertex verticesData;
	Indices indexData;

	GLuint vertexBuffer, indexBuffer;
	Matrix mvp, model, view;
	int indexCount = 0;


private:

};
#endif // !_SKY_

