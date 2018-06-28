#pragma once

#ifndef _FIRE_
#define _FIRE_


#include <vector>
#include "../Utilities//utilities.h"
#include "Texture.h"
#include "Shaders.h"
#include "Vertex.h"
#include "Indices.h"

struct Vertex;
struct Index;


class FireEffect
{
public:
	
	FireEffect();
	FireEffect(const FireEffect& obj) {}
	~FireEffect() {}

	bool LoadFile(const char* const filename, std::vector<Vertex>&, std::vector<Indices>&);

	int Init(ESContext* esContext, const char* const filename);
	void Draw(ESContext* esContext, Texture* texture, Texture* texture1, Texture* texture2, Shaders* shader);
	void Update(ESContext* esContext, float deltaTime, Shaders* shader);
	void CleanUp();

	Vertex verticesData;
	Indices indicesD;
	
	Matrix mvp, model, view;
	GLuint vertexBuffer, indexBuffer;
private:
	int sizeind = 0;

};

#endif // !_FIRE_

