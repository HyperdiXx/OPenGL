#include <stdafx.h>
#include "Shaders.h"

int Shaders::Init(char * fileVertexShader, char * fileFragmentShader)
{
	vertexShader = esLoadShader(GL_VERTEX_SHADER, fileVertexShader);

	if ( vertexShader == 0 )
		return -1;

	fragmentShader = esLoadShader(GL_FRAGMENT_SHADER, fileFragmentShader);

	if ( fragmentShader == 0 )
	{
		glDeleteShader( vertexShader );
		return -2;
	}

	program = esLoadProgram(vertexShader, fragmentShader);

	//finding location of uniforms / attributes
	positionAttribute = glGetAttribLocation(program, "a_posL");
	colorAttribute = glGetAttribLocation(program, "a_color");
	//matrixTransform = glGetUniformLocation(program, "u_matT");
	model = glGetUniformLocation(program, "model");
	view = glGetUniformLocation(program, "view");
	projection = glGetUniformLocation(program, "projection");
	textureAttribute = glGetAttribLocation(program, "a_uv");
	textureAttribute3 = glGetUniformLocation(program, "uva");
	uvAt = glGetUniformLocation(program, "uv");
	uniformLocation = glGetUniformLocation(program, "u_s_texture");
	t1 = glGetUniformLocation(program, "text1");
	t2 = glGetUniformLocation(program, "text2");
	t3 = glGetUniformLocation(program, "text3");
	lookAt = glGetUniformLocation(program, "m_lookAt");
	MVP = glGetUniformLocation(program, "u_mvp");
	cubeTexture = glGetUniformLocation(program, "sky");
	campos = glGetUniformLocation(program, "camPos");
	disp = glGetUniformLocation(program, "displacement");
	fire = glGetUniformLocation(program, "texcoord");
	mask = glGetUniformLocation(program, "alpha");
	t = glGetUniformLocation(program, "time");
	viewprojection = glGetUniformLocation(program, "viewproj");
	normal = glGetUniformLocation(program, "a_normal");
	return 0;
}

void Shaders::Draw(ESContext* esContext)
{
	glUseProgram(program);
	glUniformMatrix4fv(this->MVP, 1, false, (GLfloat*)&this->MVP);

	GLfloat* ptr = (GLfloat*)0;
	if (positionAttribute != -1)
	{
		glEnableVertexAttribArray(positionAttribute);
		glVertexAttribPointer(positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr);
	}

	if (colorAttribute != -1)
	{
		glEnableVertexAttribArray(colorAttribute);
		glVertexAttribPointer(colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 3);
	}

	if (textureAttribute != -1)
	{
		glEnableVertexAttribArray(textureAttribute);
		glVertexAttribPointer(textureAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ptr + 6);
	}

}

Shaders::~Shaders()
{
	glDeleteProgram(program);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}