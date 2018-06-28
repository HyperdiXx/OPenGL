#pragma once
#include "../Utilities/utilities.h"
#include "Vertex.h"

struct Vertex;

class Shaders 
{
public:
	GLuint program, vertexShader, fragmentShader;
	char fileVS[260];
	char fileFS[260];
	GLint positionAttribute;
	GLint colorAttribute;
	GLint uvAt;
	GLint textureAttribute, t1, t2, t3, textureAttribute3;
	GLint matrixTransform;
	GLint model, view, projection, lookAt;
	GLint uniformLocation;
	GLint MVP, viewprojection;
	GLfloat fogStart, fogEnd;
	GLint campos, cubeTexture;
	GLint disp, mask, fire, normal;
	GLfloat t;

	int Init(char * fileVertexShader, char * fileFragmentShader);
	void Draw(ESContext *esContext);
	
	~Shaders();
};