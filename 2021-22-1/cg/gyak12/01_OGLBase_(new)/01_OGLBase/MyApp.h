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

#include "includes/gCamera.h"

#include "includes/ProgramObject.h"
#include "includes/BufferObject.h"
#include "includes/VertexArrayObject.h"
#include "includes/TextureObject.h"

// mesh
#include "includes/ObjParser_OGL3.h"

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
	// shaderekhez szükséges változók
	ProgramObject		m_program;			// mesh shader
	ProgramObject		m_programSkybox;	// skybox shader

	VertexArrayObject	m_CubeVao;			// VAO
	IndexBuffer			m_CubeIndices;		// index buffer
	ArrayBuffer			m_CubeVertexBuffer;	// VBO

	VertexArrayObject	m_SkyboxVao;
	IndexBuffer			m_SkyboxIndices;	
	ArrayBuffer			m_SkyboxPos;		

	std::vector<std::vector<float>> m_GroundHeights;
	VertexArrayObject m_GroundVao;
	IndexBuffer m_GroundIndices;
	ArrayBuffer m_GroundBuffer;

	gCamera				m_camera;

	Texture2D			m_grassTexture;
	Texture2D			m_forestTexture;
	Texture2D			m_barkTexture;
	TextureCubeMap		m_skyboxTexture;

	struct Vertex
	{
		glm::vec3 p;
		glm::vec3 n;
		glm::vec2 t;
	};

	// mesh adatok
	std::unique_ptr<Mesh> m_mesh;

	struct Tree {
		bool exists = false;
		float size = 0.05f;
		glm::vec3 pos;
	};

	std::vector<std::vector<Tree>> m_TreePositions;

	int lastTreeUpdate = 0;

	int numCutTrees = 0;
	float treeGrowthTime = 10.0f;

	// a jobb olvashatóság kedvéért
	void InitShaders();
	void InitCube();
	void InitGround();
	void InitSkyBox();
};

