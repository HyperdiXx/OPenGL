#pragma once

#ifndef _TeRRAIN_
#define _TERRAIN_


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


class Terrain
{
public:
	Terrain();
	Terrain(const Terrain& obj);
	~Terrain();

	bool LoadTerrain(const char* const filename, std::vector<Vertex>& vertices, std::vector<Indices>& indices);

	int Init(ESContext*, const char* const);
	void Draw(ESContext*, Texture*, Texture*, Texture*, Texture*, Shaders*, Matrix&);
	void DrawMulti(ESContext*, Texture*, Texture*, Texture*, Texture*, Shaders*, Matrix&);
	void CleanUp();

	Vertex verticesData;
	Indices indicesD;

	GLuint vertexBuffer, indexBuffer;
	Matrix mvp;
	int indexCount = 0;
private:

};
#endif // !_TeRRAIN_

