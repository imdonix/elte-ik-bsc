#pragma once

// GLEW
#include <GL/glew.h>

// SDL
#include <SDL.h>
#include <SDL_opengl.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

class CMyApp
{
public:
	CMyApp();
	~CMyApp();

	bool Init();
	void Clean();

	void Update();
	void Render();

	void KeyboardDown(SDL_KeyboardEvent&);
	void KeyboardUp(SDL_KeyboardEvent&);
	void MouseMove(SDL_MouseMotionEvent&);
	void MouseDown(SDL_MouseButtonEvent&);
	void MouseUp(SDL_MouseButtonEvent&);
	void MouseWheel(SDL_MouseWheelEvent&);
	void Resize(int, int);
protected:
	// segédfüggvények
	glm::vec3 GetSpherePos(float u, float v);

	// shaderekhez szükséges változók
	GLuint m_programID = 0; // shaderek programja

	// OpenGL-es dolgok
	GLuint m_vaoID = 0; // vertex array object erõforrás azonosító
	GLuint m_vboID = 0; // vertex buffer object erõforrás azonosító
	GLuint m_ibID = 0;  // index buffer object erõforrás azonosító

	// transzformációs mátrixok
	glm::mat4 m_matWorld = glm::mat4(1.0f);
	glm::mat4 m_matView = glm::mat4(1.0f);
	glm::mat4 m_matProj = glm::mat4(1.0f);

	// mátrixok helye a shaderekben
	GLuint	m_loc_mvp = 0; // a három mátrixunk szorzatát adjuk át a hatékonyság érdekében

	struct Vertex
	{
		glm::vec3 p;
		glm::vec3 c;
	};

	// NxM darab négyszöggel közelítjük a parametrikus felületünket => (N+1)x(M+1) pontban kell kiértékelni
	static const int N	= 20;
	static const int M	= 10;
};

