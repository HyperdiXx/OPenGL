#pragma once


//triangle data (heap)


/*verticesData[0].pos.x =  0.0f;  verticesData[0].pos.y =  0.5f;  verticesData[0].pos.z =  0.0f;
verticesData[1].pos.x = -0.5f;  verticesData[1].pos.y = -0.5f;  verticesData[1].pos.z =  0.0f;
verticesData[2].pos.x =  0.5f;  verticesData[2].pos.y = -0.5f;  verticesData[2].pos.z =  0.0f;*/

//verticesData[0].pos.x = -0.5f;  verticesData[0].pos.y = 0.0f;  verticesData[0].pos.z = 0.0f;
//verticesData[1].pos.x = 0.0f;  verticesData[1].pos.y = 0.5f;  verticesData[1].pos.z = 0.0f;
//verticesData[2].pos.x = 0.5f;  verticesData[2].pos.y = 0.0f;  verticesData[2].pos.z = 0.0f;

//std::copy(begin(modelObject.vertices), end(modelObject.vertices), std::back_inserter(verticesData));



/*verticesData[0].pos.x = -1.0f; verticesData[0].pos.y = -1.0f; verticesData[0].pos.z = -1.0f;
verticesData[1].pos.x = -1.0f;	verticesData[1].pos.y = -1.0f; verticesData[1].pos.z = 1.0f;
verticesData[2].pos.x = -1.0f;	verticesData[2].pos.y = 1.0f; verticesData[2].pos.z = 1.0f;
verticesData[3].pos.x = 1.0f;	verticesData[3].pos.y = 1.0f; verticesData[3].pos.z = -1.0f;
verticesData[4].pos.x = -1.0f;	verticesData[4].pos.y = -1.0f; verticesData[4].pos.z = -1.0f;
verticesData[5].pos.x = -1.0f;	verticesData[5].pos.y = 1.0f; verticesData[5].pos.z = -1.0f;
verticesData[6].pos.x = 1.0f;	verticesData[6].pos.y = -1.0f; verticesData[6].pos.z = 1.0f;
verticesData[7].pos.x = -1.0f;	verticesData[7].pos.y = -1.0f; verticesData[7].pos.z = -1.0f;
verticesData[8].pos.x = 1.0f;	verticesData[8].pos.y = -1.0f; verticesData[8].pos.z = -1.0f;
verticesData[9].pos.x = 1.0f;	verticesData[9].pos.y = 1.0f; verticesData[9].pos.z = -1.0f;
verticesData[10].pos.x = 1.0f;	verticesData[10].pos.y = -1.0f; verticesData[10].pos.z = -1.0f;
verticesData[11].pos.x = -1.0f;	verticesData[11].pos.y = -1.0f; verticesData[11].pos.z = -1.0f;
verticesData[12].pos.x = -1.0f;	verticesData[12].pos.y = -1.0f; verticesData[12].pos.z = -1.0f;
verticesData[13].pos.x = -1.0f;	verticesData[13].pos.y = -1.0f; verticesData[13].pos.z = 1.0f;
verticesData[14].pos.x = -1.0f;	verticesData[14].pos.y = 1.0f; verticesData[14].pos.z = -1.0f;
verticesData[15].pos.x = 1.0f;	verticesData[15].pos.y = -1.0f; verticesData[15].pos.z = 1.0f;
verticesData[16].pos.x = -1.0f;	verticesData[16].pos.y = -1.0f; verticesData[16].pos.z = 1.0f;
verticesData[17].pos.x = -1.0f;	verticesData[17].pos.y = -1.0f; verticesData[17].pos.z = -1.0f;
verticesData[18].pos.x = -1.0f;	verticesData[18].pos.y = 1.0f; verticesData[18].pos.z = 1.0f;
verticesData[19].pos.x = -1.0f;	verticesData[19].pos.y = -1.0f; verticesData[19].pos.z = 1.0f;
verticesData[20].pos.x = 1.0f;	verticesData[20].pos.y = -1.0f; verticesData[20].pos.z = 1.0f;
verticesData[21].pos.x = 1.0f;	verticesData[21].pos.y = 1.0f; verticesData[21].pos.z = 1.0f;
verticesData[22].pos.x = 1.0f;	verticesData[22].pos.y = -1.0f; verticesData[22].pos.z = -1.0f;
verticesData[23].pos.x = 1.0f;	verticesData[23].pos.y = 1.0f; verticesData[23].pos.z = -1.0f;
verticesData[24].pos.x = 1.0f;	verticesData[24].pos.y = -1.0f; verticesData[24].pos.z = -1.0f;
verticesData[25].pos.x = 1.0f;	verticesData[25].pos.y = 1.0f; verticesData[25].pos.z = 1.0f;
verticesData[26].pos.x = 1.0f;	verticesData[26].pos.y = -1.0f; verticesData[26].pos.z = 1.0f;
verticesData[27].pos.x = 1.0f;	verticesData[27].pos.y = 1.0f; verticesData[27].pos.z = 1.0f;
verticesData[28].pos.x = 1.0f;	verticesData[28].pos.y = 1.0f; verticesData[28].pos.z = -1.0f;
verticesData[29].pos.x = -1.0f;	verticesData[29].pos.y = 1.0f; verticesData[29].pos.z = -1.0f;
verticesData[30].pos.x = 1.0f;	verticesData[30].pos.y = 1.0f; verticesData[30].pos.z = 1.0f;
verticesData[31].pos.x = -1.0f;	verticesData[31].pos.y = 1.0f; verticesData[31].pos.z = -1.0f;
verticesData[32].pos.x = -1.0f;	verticesData[32].pos.y = 1.0f; verticesData[32].pos.z = 1.0f;
verticesData[33].pos.x = 1.0f;	verticesData[33].pos.y = 1.0f; verticesData[33].pos.z = 1.0f;
verticesData[34].pos.x = -1.0f;	verticesData[34].pos.y = 1.0f; verticesData[34].pos.z = 1.0f;
verticesData[35].pos.x = -1.0f;	verticesData[35].pos.y = -1.0f; verticesData[35].pos.z = -1.0f;

verticesData[0].color.x = 1.0f;  verticesData[0].color.y = 0.5f;  verticesData[0].color.z = 0.0f;
verticesData[1].color.x = 0.0f;  verticesData[1].color.y = 1.0f;  verticesData[1].color.z = 0.0f;
verticesData[2].color.x = 0.0f;  verticesData[2].color.y = 0.0f;  verticesData[2].color.z = 1.0f;
verticesData[3].color.x = 1.0f;  verticesData[3].color.y = 0.5f;  verticesData[3].color.z = 0.0f;
verticesData[4].color.x = 0.0f;  verticesData[4].color.y = 1.0f;  verticesData[4].color.z = 0.0f;
verticesData[5].color.x = 0.0f;  verticesData[5].color.y = 0.0f;  verticesData[5].color.z = 1.0f;
verticesData[6].color.x = 1.0f;  verticesData[6].color.y = 0.5f;  verticesData[6].color.z = 0.0f;
verticesData[7].color.x = 0.0f;  verticesData[7].color.y = 1.0f;  verticesData[7].color.z = 0.0f;
verticesData[8].color.x = 0.0f;  verticesData[8].color.y = 0.0f;  verticesData[8].color.z = 1.0f;
verticesData[9].color.x = 1.0f;  verticesData[9].color.y = 0.5f;  verticesData[9].color.z = 0.0f;
verticesData[10].color.x = 0.0f;  verticesData[10].color.y = 1.0f;  verticesData[10].color.z = 0.0f;
verticesData[11].color.x = 0.0f;  verticesData[11].color.y = 0.0f;  verticesData[11].color.z = 1.0f;
verticesData[12].color.x = 1.0f;  verticesData[12].color.y = 0.5f;  verticesData[12].color.z = 0.0f;
verticesData[13].color.x = 0.0f;  verticesData[13].color.y = 1.0f;  verticesData[13].color.z = 0.0f;
verticesData[14].color.x = 0.0f;  verticesData[14].color.y = 0.0f;  verticesData[14].color.z = 1.0f;
verticesData[15].color.x = 1.0f;  verticesData[15].color.y = 0.5f;  verticesData[15].color.z = 0.0f;
verticesData[16].color.x = 0.0f;  verticesData[16].color.y = 1.0f;  verticesData[16].color.z = 0.0f;
verticesData[17].color.x = 0.0f;  verticesData[17].color.y = 0.0f;  verticesData[17].color.z = 1.0f;
verticesData[18].color.x = 1.0f;  verticesData[18].color.y = 0.5f;  verticesData[18].color.z = 0.0f;
verticesData[19].color.x = 0.0f;  verticesData[19].color.y = 1.0f;  verticesData[19].color.z = 0.0f;
verticesData[20].color.x = 0.0f;  verticesData[20].color.y = 0.0f;  verticesData[20].color.z = 1.0f;
verticesData[21].color.x = 0.0f;  verticesData[21].color.y = 0.0f;  verticesData[21].color.z = 1.0f;
verticesData[22].color.x = 1.0f;  verticesData[22].color.y = 0.5f;  verticesData[22].color.z = 0.0f;
verticesData[23].color.x = 0.0f;  verticesData[23].color.y = 1.0f;  verticesData[23].color.z = 0.0f;
verticesData[24].color.x = 0.0f;  verticesData[24].color.y = 0.0f;  verticesData[24].color.z = 1.0f;
verticesData[25].color.x = 1.0f;  verticesData[25].color.y = 0.5f;  verticesData[25].color.z = 0.0f;
verticesData[26].color.x = 0.0f;  verticesData[26].color.y = 1.0f;  verticesData[26].color.z = 0.0f;
verticesData[27].color.x = 0.0f;  verticesData[27].color.y = 0.0f;  verticesData[27].color.z = 1.0f;
verticesData[28].color.x = 1.0f;  verticesData[28].color.y = 0.5f;  verticesData[28].color.z = 0.0f;
verticesData[29].color.x = 0.0f;  verticesData[29].color.y = 1.0f;  verticesData[29].color.z = 0.0f;
verticesData[30].color.x = 0.0f;  verticesData[30].color.y = 0.0f;  verticesData[30].color.z = 1.0f;
verticesData[31].color.x = 1.0f;  verticesData[31].color.y = 0.5f;  verticesData[31].color.z = 0.0f;
verticesData[32].color.x = 0.0f;  verticesData[32].color.y = 1.0f;  verticesData[32].color.z = 0.0f;
verticesData[33].color.x = 0.0f;  verticesData[33].color.y = 0.0f;  verticesData[33].color.z = 1.0f;
verticesData[34].color.x = 0.0f;  verticesData[34].color.y = 1.0f;  verticesData[34].color.z = 0.0f;
verticesData[35].color.x = 0.0f;  verticesData[35].color.y = 0.0f;  verticesData[35].color.z = 1.0f;

verticesData[0].pos.x = 23.333275;	verticesData[0].pos.y = 0.518513; verticesData[0].pos.z = -14.657627;
verticesData[1].pos.x = 23.335003;	verticesData[1].pos.y = 0.518513; verticesData[1].pos.z = -14.657631;
verticesData[2].pos.x = -23.335003;	verticesData[2].pos.y = 0.518528; verticesData[2].pos.z = 27.450874;
verticesData[3].pos.x = 23.333275;	verticesData[3].pos.y = 0.518528; verticesData[3].pos.z = 27.450878;
verticesData[4].pos.x = -7.135693;	verticesData[4].pos.y = 44.548943; verticesData[4].pos.z = 10.074564;
verticesData[5].pos.x = -10.965742;	verticesData[5].pos.y = 48.300278; verticesData[5].pos.z = 1.592334;
verticesData[6].pos.x = -12.905154;	verticesData[6].pos.y = 38.794979; verticesData[6].pos.z = -0.171605;
verticesData[7].pos.x = -4.649901;	verticesData[7].pos.y = 33.789177; verticesData[7].pos.z = 6.426813;
verticesData[8].pos.x = -7.248648;	verticesData[8].pos.y = 40.408443; verticesData[8].pos.z = -7.873207;
verticesData[9].pos.x = -4.721881;	verticesData[9].pos.y = 49.979492; verticesData[9].pos.z = -6.732523;


verticesData[0].uv.x = 1.0f;	verticesData[0].uv.y = 1.0f;
verticesData[1].uv.x = 1.0f;	verticesData[1].uv.y = 0.0f;
verticesData[2].uv.x = 1.0f;	verticesData[2].uv.y = 1.0f;
verticesData[3].uv.x = 1.0f;	verticesData[3].uv.y = 1.0f;

verticesData[4].uv.x = 1.0f;	verticesData[4].uv.y = 1.0f;
verticesData[5].uv.x = 1.0f;	verticesData[5].uv.y = 0.0f;
verticesData[6].uv.x = 1.0f;	verticesData[6].uv.y = 1.0f;
verticesData[7].uv.x = 1.0f;	verticesData[7].uv.y = 1.0f;

verticesData[8].uv.x = 1.0f;	verticesData[8].uv.y = 1.0f;
verticesData[9].uv.x = 1.0f;	verticesData[9].uv.y = 1.0f;
verticesData[10].uv.x = 1.0f;	verticesData[10].uv.y = 1.0f;
verticesData[11].uv.x = 1.0f;	verticesData[11].uv.y = 1.0f;

verticesData[12].uv.x = 0.0f;	verticesData[12].uv.y = 0.0f;
verticesData[13].uv.x = 1.0f;	verticesData[13].uv.y = 0.0f;
verticesData[14].uv.x = 1.0f;	verticesData[14].uv.y = 1.0f;
verticesData[15].uv.x = 0.0f;	verticesData[15].uv.y = 1.0f;

verticesData[16].uv.x = 0.0f;	verticesData[16].uv.y = 0.0f;
verticesData[17].uv.x = 1.0f;	verticesData[17].uv.y = 0.0f;
verticesData[18].uv.x = 1.0f;	verticesData[18].uv.y = 1.0f;
verticesData[19].uv.x = 0.0f;	verticesData[19].uv.y = 1.0f;

verticesData[20].uv.x = 0.0f;	verticesData[20].uv.y = 0.0f;
verticesData[21].uv.x = 1.0f;	verticesData[21].uv.y = 0.0f;
verticesData[22].uv.x = 1.0f;	verticesData[22].uv.y = 1.0f;
verticesData[23].uv.x = 0.0f;	verticesData[23].uv.y = 1.0f;

verticesData[24].uv.x = 0.0f;	verticesData[24].uv.y = 0.0f;
verticesData[25].uv.x = 1.0f;	verticesData[25].uv.y = 0.0f;
verticesData[26].uv.x = 1.0f;	verticesData[26].uv.y = 1.0f;
verticesData[27].uv.x = 0.0f;	verticesData[27].uv.y = 1.0f;

verticesData[28].uv.x = 0.0f;	verticesData[28].uv.y = 0.0f;
verticesData[29].uv.x = 1.0f;	verticesData[29].uv.y = 0.0f;
verticesData[30].uv.x = 1.0f;	verticesData[30].uv.y = 1.0f;
verticesData[31].uv.x = 0.0f;	verticesData[31].uv.y = 1.0f;

verticesData[32].uv.x = 0.0f;	verticesData[32].uv.y = 0.0f;
verticesData[33].uv.x = 1.0f;	verticesData[33].uv.y = 0.0f;
verticesData[34].uv.x = 1.0f;	verticesData[34].uv.y = 1.0f;
verticesData[35].uv.x = 0.0f;	verticesData[35].uv.y = 1.0f;


ind =
{
	0,    1,    2,
	2,    3,    0,
	4,    5,    6,
	6,    7,    4,
	8,    6,    5,
	5,    9,    8,
	10,    8,    9,
	9,   11,   10,
	4,    7,   12,
	12,   13,    4,
	14,   15,   13,
	13,   12,   14,
	10,   11,   15,
	15,   14,   10,
	16,   17,   18,
	18,   19,   20,
	20,   21,   18,
	22,   23,   24,
	24,   25,   22,
	23,   26,   27,
	27,   24,   23,
	28,   29,   18,
	18,   26,   28,
	18,   29,   30,
	30,   19,   18,
	31,   32,   23,
	23,   22,   31,
	23,   32,   28,
	28,   26,   23,
	17,   33,   26,
	17,   26,   18,
	34,   35,   36,
	36,   37,   34,
	38,   39,   40,
	40,   41,   38,
	37,   36,   42,
	42,   38,   37,
	37,   43,   34,
	44,   45,   38,
	38,   41,   44,
	38,   45,   37,
	46,   47,   48,
	48,   49,   46,
	50,   51,   52,
	52,   53,   50,
	54,   55,   56,
	56,   57,   54,
	58,   59,   60,
	60,   61,   58,
	62,   63,   64,
	64,   65,   62,
	66,   67,   68,
	67,   69,   70,
	70,   71,   67,
	72,   73,   74,
	74,   75,   72,
	75,   74,   76,
	76,   77,   75,
	78,   77,   67,
	67,   79,   78,
	67,   71,   80,
	80,   79,   67,
	81,   72,   75,
	75,   82,   81,
	75,   77,   78,
	78,   82,   75,
	68,   77,   83,
	68,   67,   77,
	84,   85,   86,
	86,   87,   84,
	88,   89,   90,
	90,   91,   88,
	85,   88,   92,
	92,   86,   85,
	85,   84,   93,
	94,   89,   88,
	88,   95,   94,
	88,   85,   95,
	96,   97,   98,
	98,   99,   96,
	100,  101,  102,
	102,  103,  100,
	104,  105,  106,
	106,  107,  104,
	108,  109,  110,
	110,  111,  108,
	112,  113,  114,
	114,  115,  112,
	116,  117,  118,
	118,  119,  116,
	120,  116,  119,
	119,  121,  120,
	120,  122,  116,
	123,  122,  120,
	116,  124,  117,
	117,  125,  126,
	127,  128,  118,
	118,  117,  127,
	127,  117,  126,
	129,  130,  131,
	131,  132,  129,
	120,  121,  130,
	130,  129,  120,
	120,  129,  133,
	123,  120,  133,
	129,  132,  134,
	132,  126,  135,
	127,  132,  131,
	131,  128,  127,
	127,  126,  132,
	136,  137,  138,
	138,  139,  136,
	137,  140,  141,
	141,  138,  137,
	142,  143,  144,
	145,  146,  144,
	144,  147,  145,
	148,  149,  141,
	141,  140,  148,
	150,  151,  152,
	152,  153,  150,
	153,  152,  154,
	154,  155,  153,
	156,  157,  151,
	151,  150,  156,
	158,  159,  160,
	161,  158,  144,
	161,  144,  146,
	161,  146,  162,
	148,  155,  154,
	154,  149,  148,
	161,  159,  158,
	145,  162,  146,
	143,  147,  144,
	160,  142,  144,
	144,  158,  160,
	163,  164,  165,
	165,  166,  163,
	167,  168,  169,
	169,  170,  167,
	165,  171,  166,
	167,  163,  166,
	166,  168,  167,
	164,  163,  172,
	163,  167,  173,
	174,  167,  175,
	167,  170,  175,
	176,  177,  178,
	178,  179,  176,
	180,  181,  182,
	182,  183,  180,
	177,  180,  183,
	183,  178,  177,
	184,  185,  186,
	186,  187,  184,
	188,  184,  187,
	187,  189,  188,
	186,  190,  187,
	187,  191,  189,
	192,  193,  194,
	194,  195,  192,
	196,  197,  198,
	198,  199,  196,
	194,  193,  200,
	196,  199,  193,
	193,  192,  196,
	195,  201,  192,
	192,  202,  196,
	203,  204,  196,
	196,  204,  197,
	205,  206,  207,
	207,  208,  205,
	209,  210,  211,
	211,  212,  209,
	208,  207,  210,
	210,  209,  208,
	213,  214,  215,
	215,  216,  213,
	217,  218,  214,
	214,  213,  217,
	215,  214,  219,
	214,  218,  220,
	221,  222,  223,
	224,  225,  226,
	226,  227,  224,
	228,  229,  226,
	226,  225,  228,
	230,  231,  224,
	232,  233,  228,
	227,  234,  230,
	230,  224,  227,
	235,  229,  228,
	228,  233,  235,
	236,  237,  238,
	238,  239,  236

};

//int ind[5] = {};



//textue mapping
/*glGenTextures(1, &textureHandler);
glBindTexture(GL_TEXTURE_2D, textureHandler);

const char* file = "../Resources/SCV.tga";
if (!file)
{

}

glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

int width, height, bpp;
char * bufferTGA = LoadTGA(file, &width, &height, &bpp);

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
*/



/////////////Draw/////

//textureM.Draw();


//glUniformMatrix4fv(myShaders.model, 1, false, (GLfloat*)&model);
//glUniformMatrix4fv(myShaders.view, 1, false, (GLfloat*)&view);
//glUniformMatrix4fv(myShaders.projection, 1, false, (GLfloat*)&projection);
//glUniformMatrix4fv(myShaders.lookAt, 1, false, (GLfloat*)&lookAt);


//texturing
/*unsigned short textureUnit = 0;

glActiveTexture(GL_TEXTURE0 + textureUnit);
glBindTexture(GL_TEXTURE_2D, textureHandler);
glUniform1i(myShaders.uniformLocation, textureUnit);
textureUnit++;*/


//SceneMAnager->Object
//ResourceManager