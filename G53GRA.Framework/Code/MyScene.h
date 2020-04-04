#pragma once

#include "../Framework/Engine/Scene.h"
#include "Car.h"
#include "SkyBox.h"
#include "Environment.h"

class MyScene :
	public Scene
{
public:
	MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight);
	~MyScene() {};

private:
    Car *car;
    SkyBox *skybox;
    Environment * env;
	void Initialise();
	void Projection();

};


void draw();
void setup();
void setGlobalLight();
void timer(int value);
void reshape(int _width, int _height);
void checkGLError();
void drawPerspective();
