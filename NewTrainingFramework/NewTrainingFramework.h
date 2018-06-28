#pragma once

#include "../Utilities/utilities.h"
#include "Globals.h"
#include "Windows.h"
#include <stdlib.h>




int Init(ESContext *esContext);

void Draw(ESContext *esContext);

void Update(ESContext *esContext, float deltaTime);

void Key(ESContext *esContext, unsigned char key, bool bIsPressed);


void CleanUp();
