
#include "stdafx.h"
#include "Texture.h"

GLint Texture::sm_textureUnit = 0;

Texture::Texture()
{
	
}

Texture::~Texture()
{

}


int Texture::Init(ESContext* escontex, char* filename)
{
	m_target = GL_TEXTURE_2D;

	glGenTextures(1, &textureHandler);
	glBindTexture(GL_TEXTURE_2D, textureHandler);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		
	int width, height, bpp;

	char * bufferTGA = LoadTGA(filename, &width, &height, &bpp);

	if (bpp == 24) { //bpp = bits per pixel (8*number of channels, for RGBA = 8*4=32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA);
	}

	delete[] bufferTGA;

		// generate the mipmap chain 
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	return 0;
}

int Texture::InitFire(ESContext *esContext, const char * filename, GLint t)
{
	m_target = GL_TEXTURE_2D;

	glGenTextures(1, &textureHandler);
	glBindTexture(GL_TEXTURE_2D, textureHandler);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, t);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, t);

	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	int width, height, bpp;

	char * bufferTGA = LoadTGA(filename, &width, &height, &bpp);

	if (bpp == 24) { //bpp = bits per pixel (8*number of channels, for RGBA = 8*4=32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA);
	}

	delete[] bufferTGA;

	// generate the mipmap chain 
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);


	return 0;
}

int Texture::InitCubeTexture(ESContext * esContext, char* filename)
{
	m_target = GL_TEXTURE_CUBE_MAP;

	glGenTextures(1, &textureHandler);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureHandler);

	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


	int width, height, bpp;
	int oofsetx, offsety;
	//width = width / 4;
	//height = height / 3;

	char *bufferTGA, *img1, *img2, *img3, *img4, *img5;
	
	bufferTGA = LoadTGA("../Resources/Textures/miramar_rt.tga", &width, &height, &bpp);
	img1 = LoadTGA("../Resources/Textures/miramar_lt", &width, &height, &bpp);
	img2 = LoadTGA("../Resources/Textures/miramar_up.tga", &width, &height, &bpp);
	img3 = LoadTGA("../Resources/Textures/miramar_dn.tga", &width, &height, &bpp);
	img4 = LoadTGA("../Resources/Textures/miramar_ft.tga", &width, &height, &bpp);
	img5 = LoadTGA("../Resources/Textures/miramar_bk.tga", &width, &height, &bpp);

	if (bpp = 24)
	{
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 0, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 1, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img1);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 2, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img2);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 3, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img3);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 4, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img4);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 5, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img5);
	}
	else
	{
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 0, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 1, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img1);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 2, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img2);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 3, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img3);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 4, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img4);
		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + 5, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img5);
	}
	
	delete[] bufferTGA;

	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return 0;
}

int Texture::ExtractFace(ESContext * escontext)
{
	//char *bufferTGA = LoadTGA();

	std::vector<int> par;

	int width, height; 
	int faces[12];
	int rightX = width / 2;
	int rightY = height / 3;
	int leftY = height / 3;
	int topX = width / 4;
	int bottomX = width / 4;
	int bottomY = height * 2 / 3;
	int frontX = width / 4;
	int frontY = height / 3;
	int backX = width * 3 / 4;
	int backY = height / 3;

	faces[0] = rightX;
	faces[1] = rightY;
	faces[3] = leftY;
	faces[4] = 0;
	faces[5] = topX;
	faces[6] = 0;
	faces[7] = bottomX;
	faces[8] = bottomY;
	faces[9] = frontX;
	faces[10] = frontY;
	faces[11] = backX;
	faces[12] = backY;


	return 0;
}

/*int Texture::InitMulti(ESContext* escontex, char* filename, char* filename2, char* filename3, char* filename4)
{

	glGenTextures(1, &textureHandler1[i]);
	glBindTexture(GL_TEXTURE_2D, textureHandler1[i]);

	//filename = "../Resources/Textures/MarineText.tga";

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, bpp;
	char * bufferTGA = LoadTGA(filename, &width, &height, &bpp);

	if (bpp == 24) { //bpp = bits per pixel (8*number of channels, for RGBA = 8*4=32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA);
	}

	delete[] bufferTGA;

	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	
	glGenTextures(1, &textureHandler1);
	glBindTexture(GL_TEXTURE_2D, textureHandler1);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width1, height1, bpp1;
	char * bufferTGA1 = LoadTGA(filename2, &width1, &height1, &bpp1);

	if (bpp1 == 24) { //bpp = bits per pixel (8*number of channels, for RGBA = 8*4=32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA1);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width1, height1, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA1);
	}

	delete[] bufferTGA1;

	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);


	glGenTextures(1, &textureHandler2);
	glBindTexture(GL_TEXTURE_2D, textureHandler2);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width2, height2, bpp2;
	char * bufferTGA2 = LoadTGA(filename3, &width2, &height2, &bpp2);

	if (bpp2 == 24) { //bpp = bits per pixel (8*number of channels, for RGBA = 8*4=32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA2);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width2, height2, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA2);
	}

	delete[] bufferTGA2;

	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);


	glGenTextures(1, &textureHandler3);
	glBindTexture(GL_TEXTURE_2D, textureHandler3);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width3, height3, bpp3;
	char * bufferTGA3 = LoadTGA(filename3, &width3, &height3, &bpp3);

	if (bpp3 == 24) { //bpp = bits per pixel (8*number of channels, for RGBA = 8*4=32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width3, height3, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA3);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width3, height3, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA3);
	}

	delete[] bufferTGA3;

	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	
	glGenTextures(1, &textureHandler4);
	glBindTexture(GL_TEXTURE_2D, textureHandler4);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width4, height4, bpp4;
	char * bufferTGA4 = LoadTGA(filename4, &width4, &height4, &bpp4);

	if (bpp3 == 24) { //bpp = bits per pixel (8*number of channels, for RGBA = 8*4=32)
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width4, height4, 0, GL_RGB, GL_UNSIGNED_BYTE, bufferTGA4);
	}
	else {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width4, height4, 0, GL_RGBA, GL_UNSIGNED_BYTE, bufferTGA4);
	}

	delete[] bufferTGA4;

	// generate the mipmap chain 
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);

	return 0;
}*/

void Texture::Draw(ESContext *esContext)
{
	unsigned short textureUnit = 0;

	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, textureHandler);
	glUniform1i(shader.uniformLocation, textureUnit);
	
	textureUnit++;
}


void Texture::DrawMulti(ESContext *esContext)
{
	unsigned short textureUnit = 0;

	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, textureHandler);
	glUniform1i(shader.uniformLocation, textureUnit);
	textureUnit++;

	/*glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, textureHandler1);
	glUniform1i(shader.t1, textureUnit);
	textureUnit++;

	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, textureHandler2);
	glUniform1i(shader.t2, textureUnit);
	textureUnit++;

	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_2D, textureHandler3);
	glUniform1i(shader.t3, textureUnit);*/

	textureUnit++;
}

void Texture::DrawCube(ESContext * esContext)
{
	unsigned short textureUnit = 0;

	glActiveTexture(GL_TEXTURE0 + textureUnit);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureHandler);
	glUniform1i(shader.cubeTexture, textureUnit);

	textureUnit++;
}

void Texture::CleanUp()
{
	glDeleteBuffers(1, &textureHandler);
}

void Texture::Bind(const int location)
{
	glActiveTexture(GL_TEXTURE0 + sm_textureUnit);
	glBindTexture(m_target, textureHandler);
	glUniform1i(location, sm_textureUnit);

	++sm_textureUnit;
}

void Texture::ResetTextureUnitAllocator()
{
	sm_textureUnit = 0;
}
