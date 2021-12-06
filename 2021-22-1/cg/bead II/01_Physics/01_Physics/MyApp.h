#pragma once

// C++ includes
#include <memory>

// GLEW
#include <GL/glew.h>

// SDL
#include <SDL.h>
#include <SDL_opengl.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

#include "Includes/ProgramObject.h"
#include "Includes/BufferObject.h"
#include "Includes/VertexArrayObject.h"
#include "Includes/TextureObject.h"

#include "Includes/Mesh_OGL3.h"
#include "Includes/gCamera.h"

#include <vector>

class CMyApp
{
public:

	CMyApp(void);
	~CMyApp(void);

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

	glm::vec3 CMyApp::GetSpherePos(float u, float v);
	glm::vec3 CMyApp::GetNorm(float u, float v);
	glm::vec2 CMyApp::GetTex(float u, float v);

	glm::vec3 CMyApp::lighPosition();

	void CMyApp::InitSphere();
	void CMyApp::InitCube();

protected:
	static const int N = 80;
	static const int M = 40;

	// shaderekhez szükséges változók
	ProgramObject		m_passthroughProgram;
	ProgramObject		m_boidProgram;
	ProgramObject		m_globeProgram;

	//Kocka
	VertexArrayObject	m_vao;				// VAO objektum
	IndexBuffer			m_gpuBufferIndices;	// indexek
	ArrayBuffer			m_gpuBufferPos;		// pozíciók tömbje

	//Globe
	Texture2D			m_globe_Texture;
	VertexArrayObject	m_globe_vao;
	IndexBuffer			m_globe_gpuBufferIndices;
	ArrayBuffer			m_globe_gpuBufferPos;
	ArrayBuffer			m_globe_gpuBufferNorm;
	ArrayBuffer			m_globe_gpuBufferTex;

	//Particle
	VertexArrayObject	m_gpuBoidVAO;
	ArrayBuffer			m_gpuBoidBuffer;

	gCamera				m_camera;

	//Engine
	int	m_boidCount = 150;

	float m_lightAmplitudo = 5;
	float m_lightState = 0;
	int m_lightTravel = 1;

	std::vector<glm::vec3> m_boidPos;
	std::vector<glm::vec3> m_boidVel;

	float a = .5F;
	float b = .5F;
	float c = .5F;
	float limit = 1;
};

