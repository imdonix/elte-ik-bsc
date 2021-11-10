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

#include "gCamera.h"

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
	struct Vertex
	{
		glm::vec3 p;
		glm::vec3 n;
		glm::vec2 t;
	};

	// segédfüggvények
	glm::vec3 GetSpherePos(float u, float v);
	glm::vec3 GetNorm(float u, float v);
	glm::vec2 GetTex(float u, float v);

	// shaderekhez szükséges változók
	GLuint m_programID = 0; // shaderek programja

	// OpenGL-es dolgok
	GLuint m_vaoID = 0; // vertex array object erőforrás azonosító
	GLuint m_vboID = 0; // vertex buffer object erőforrás azonosító
	GLuint m_ibID = 0;  // index buffer object erőforrás azonosító
	GLuint m_loadedTextureID = 0; // betöltött textúra erőforrás azonosító

	gCamera	m_camera;


	// uniform változók helye a shaderekben
	GLuint m_loc_mvp = 0;
	GLuint m_loc_world = 0;
	GLuint m_loc_worldIT = 0;
	//GLuint m_loc_tex;

	// NxM darab négyszöggel közelítjük a parametrikus felületünket => (N+1)x(M+1) pontban kell kiértékelni
	static const int N = 80;
	static const int M = 40;

	//A jobb olvashatóság kedvéért
	void InitSphere();
	void InitShaders();
	void InitTextures();
};

