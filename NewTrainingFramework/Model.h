#pragma once

#ifndef _MODEL_
#define _MODEL_


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

class Model
{

public:
	Model();
	~Model();

	bool LoadFile(const char* const, std::vector<Vertex>&, std::vector<Indices>&);

	int Init(ESContext*);
	int InitModel(ESContext*, const char* const);
	int InitSky(ESContext* esContext, Shaders* shader, Texture* texture);
	void Draw(ESContext*, Texture*, Shaders*, Matrix&);
	void DrawSky(ESContext*, Texture*, Shaders*, Matrix&);
	void DrawCube(ESContext*, Texture*, Shaders*, Matrix&);
	void Update(ESContext*, float);
	void CleanUp();
	void ClearData();


	Vertex verticesData;
	Indices indicesD;

	Matrix model, view, projection, mvp, lookAt, res, viewprojection;
	GLuint vertexBuffer, indexBuffer;
	float speed = 1.0f;

	int sizeind = 0;
};

#endif // !_MODEL_
