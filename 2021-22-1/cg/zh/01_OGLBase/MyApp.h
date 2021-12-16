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
	ProgramObject		m_program;
	ProgramObject		m_programSkybox;
	ProgramObject		m_programGround;

	//Cube
	VertexArrayObject	m_CubeVao;
	IndexBuffer			m_CubeIndices;
	ArrayBuffer			m_CubeVertexBuffer;

	//Ground
	VertexArrayObject	m_GroundVao;
	IndexBuffer			m_GroundIndices;	
	ArrayBuffer			m_GroundBuffer;

	//Kup
	VertexArrayObject	m_KupVao;
	IndexBuffer			m_KupIndices;
	ArrayBuffer			m_KupBuffer;

	//Gula
	std::unique_ptr<Mesh> m_Gula;

	VertexArrayObject	m_SkyboxVao;
	IndexBuffer			m_SkyboxIndices;	
	ArrayBuffer			m_SkyboxPos;		

	// Parametrikus felület GPU erőforrásai
	VertexArrayObject	m_ParVao;
	IndexBuffer			m_ParIndices;
	ArrayBuffer			m_ParVertexBuffer;

	gCamera				m_camera;

	//Textures
	Texture2D			m_houseTexture;
	Texture2D			m_roofTexture;
	Texture2D			m_casteTexture;
	Texture2D			m_groundTexture;
	Texture2D			m_treeTexture;
	Texture2D			m_workerTexture;
	Texture2D			m_groundWinTexture;
	TextureCubeMap		m_skyboxTexture;


	struct Vertex
	{
		glm::vec3 p;
		glm::vec3 n;
		glm::vec2 t;
	};

	struct Place
	{
		bool used;
		int type; // 0 empty, 1 tree, 2 house
		int randval; // 0-100
	};


	struct Job
	{
		float timer;
		int state; // 0 go to tree s3 | 1 for 3s wait at tree | 2 go to castle s3 | 3 for 3s wait at castle
		int x; // target
		int y; // target
		glm::vec2 pos;
	};

	// a jobb olvashatóság kedvéért
	void InitGround();
	void InitShaders();
	void InitCube();
	void InitKup();
	void InitSkyBox();

	//Renders
	void RenderHouse(glm::vec3 pos);
	void RenderCastle(glm::vec3 pos);
	void RenderTree(glm::vec3 pos, float size);
	void RenderWorker(glm::vec3 pos);
	
	void RenderGround();

	Place world[10][10];
	Job jobs[5];

	float time = 0;
	int wood = 0;
	bool menuflag = false;

};

