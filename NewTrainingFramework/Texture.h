#pragma once

#ifndef _TEXTURE_
#define _TEXTURE_

#include "../Utilities/utilities.h"
#include "Shaders.h"
#include "Vertex.h"
#include <vector>



class Texture
{
public:

	Shaders shader;
	GLuint textureHandler;
	//GLuint textureHandler1[5];

	Texture();

	int Init(ESContext*, char*);
	int InitFire(ESContext* esContext, const char* filename, GLint t);
	int InitMulti(ESContext*, char*, char*, char*, char*);
	int InitCubeTexture(ESContext* esContext, char* filename);
	int ExtractFace(ESContext* escontext);
	void Draw(ESContext *esContext);
	void DrawMulti(ESContext *esContext);
	void DrawCube(ESContext *esContext);
	void CleanUp();

	void Bind(const int location);

	static void ResetTextureUnitAllocator();
	

	~Texture();
private:
	static GLint sm_textureUnit;
	
	GLenum m_target;
};

#endif // !_TEXTURE_

