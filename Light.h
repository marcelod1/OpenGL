#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>

class Light	
{
public:
	Light();

	Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity);

	void UseLight(GLfloat ambientIntenistyLocation, GLfloat ambientColourLocation);



	~Light();

private:
	glm::vec3 colour;
	GLfloat ambientIntensity;
};

