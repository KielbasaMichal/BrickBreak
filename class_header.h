#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Box2D\Box2D.h"


#define mtopx(metry) (metry)*50.0f
#define pxtom(pixele) (pixele)*0.02f
#define DGtoRD(deg) (b2_pi * (deg) / 180.0f)
#define RDtoDG(rad) ((rad) * (180.0f / b2_pi))

//Wymiary okna potrzebne do niektorych funkcji, wymiar okna
#define WIDTH 1280 //1600
#define HEIGHT 720 //960