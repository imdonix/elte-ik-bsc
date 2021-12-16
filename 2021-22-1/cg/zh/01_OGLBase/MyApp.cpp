#include "MyApp.h"

#include <math.h>
#include <vector>

#include <array>
#include <list>
#include <tuple>
#include <imgui/imgui.h>
#include "includes/GLUtils.hpp"

CMyApp::CMyApp(void)
{
	m_camera.SetView(glm::vec3(5, 5, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	m_Gula = nullptr;
}

CMyApp::~CMyApp(void)
{
}

void CMyApp::InitKup()
{
	// NxM darab négyszöggel közelítjük a parametrikus felületünket => (N+1)x(M+1) pontban kell kiértékelni
	std::vector<Vertex> vertices;
	vertices.reserve(10 * 10);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			float u = (float)i / (10 - 1);
			float v = (float)j / (10 - 1);
			vertices.push_back({
				glm::vec3(
					(1.0f - v) * sin(u * 2.0f * M_PI),
					v,
					(1.0f - v) * cos(u * 2.0f * M_PI)
				),
				glm::normalize(glm::vec3(
					cos(u * 2.0f * M_PI),
					1,
					cos(u * 2.0f * M_PI)
				)),
				glm::vec2(u, v)
			});
		}
	}

	// indexpuffer adatai: NxM négyszög = 2xNxM háromszög = háromszöglista esetén 3x2xNxM index
	const int N = 10;
	GLushort indices[3 * 2 * (N) * (N)];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			indices[6 * i + j * 3 * 2 * (N)+0] = (i)+(j) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+1] = (i + 1) + (j) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+2] = (i)+(j + 1) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+3] = (i + 1) + (j) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+4] = (i + 1) + (j + 1) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+5] = (i)+(j + 1) * (N + 1);
		}

	m_KupBuffer.BufferData(vertices);
	m_KupIndices.BufferData(indices);


	m_KupVao.Init(
		{
			{ CreateAttribute<0,	glm::vec3,	0,						sizeof(Vertex)>, m_KupBuffer },
			{ CreateAttribute<1,	glm::vec3,	(sizeof(glm::vec3)),	sizeof(Vertex)>, m_KupBuffer },
			{ CreateAttribute<2,	glm::vec2,	(2 * sizeof(glm::vec3)),sizeof(Vertex)>, m_KupBuffer },
		},
		m_KupIndices
	);
}

void CMyApp::InitCube()
{
	std::vector<Vertex>vertices;
	
	//front
	vertices.push_back({ glm::vec3(-1.0, -1.0, +1.0) / 2.F , glm::vec3(0, 0, 1), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+1.0, -1.0, +1.0) / 2.F, glm::vec3(0, 0, 1), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-1.0, +1.0, +1.0) / 2.F, glm::vec3(0, 0, 1), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+1.0, +1.0, +1.0) / 2.F, glm::vec3(0, 0, 1), glm::vec2(1, 1) });
	//back
	vertices.push_back({ glm::vec3(+1.0, -1.0, -1.0) / 2.F, glm::vec3(0, 0, -1), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(-1.0, -1.0, -1.0) / 2.F, glm::vec3(0, 0, -1), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(+1.0, +1.0, -1.0) / 2.F, glm::vec3(0, 0, -1), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(-1.0, +1.0, -1.0) / 2.F, glm::vec3(0, 0, -1), glm::vec2(1, 1) });
	//right
	vertices.push_back({ glm::vec3(+1.0, -1.0, +1.0) / 2.F, glm::vec3(1, 0, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+1.0, -1.0, -1.0) / 2.F, glm::vec3(1, 0, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(+1.0, +1.0, +1.0) / 2.F, glm::vec3(1, 0, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+1.0, +1.0, -1.0) / 2.F, glm::vec3(1, 0, 0), glm::vec2(1, 1) });
	//left
	vertices.push_back({ glm::vec3(-1.0, -1.0, -1.0) / 2.F, glm::vec3(-1, 0, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(-1.0, -1.0, +1.0) / 2.F, glm::vec3(-1, 0, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-1.0, +1.0, -1.0) / 2.F, glm::vec3(-1, 0, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(-1.0, +1.0, +1.0) / 2.F, glm::vec3(-1, 0, 0), glm::vec2(1, 1) });
	//top
	vertices.push_back({ glm::vec3(-1.0, +1.0, +1.0) / 2.F, glm::vec3(0, 1, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+1.0, +1.0, +1.0) / 2.F, glm::vec3(0, 1, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-1.0, +1.0, -1.0) / 2.F, glm::vec3(0, 1, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+1.0, +1.0, -1.0) / 2.F, glm::vec3(0, 1, 0), glm::vec2(1, 1) });
	//bottom
	vertices.push_back({ glm::vec3(-1.0, -1.0, -1.0) / 2.F, glm::vec3(0, -1, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+1.0, -1.0, -1.0) / 2.F, glm::vec3(0, -1, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-1.0, -1.0, +1.0) / 2.F, glm::vec3(0, -1, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+1.0, -1.0, +1.0) / 2.F, glm::vec3(0, -1, 0), glm::vec2(1, 1) });

	std::vector<uint32_t> indices(36);
	int index = 0;
	for (int i = 0; i < 6 * 4; i += 4)
	{
		indices[index + 0] = i + 0;
		indices[index + 1] = i + 1;
		indices[index + 2] = i + 2;
		indices[index + 3] = i + 1;
		indices[index + 4] = i + 3;
		indices[index + 5] = i + 2;
		index += 6;
	}

	m_CubeVertexBuffer.BufferData(vertices);
	m_CubeIndices.BufferData(indices);

	m_CubeVao.Init(
		{
			{ CreateAttribute<0,	glm::vec3,	0,						sizeof(Vertex)>, m_CubeVertexBuffer },
			{ CreateAttribute<1,	glm::vec3,	(sizeof(glm::vec3)),	sizeof(Vertex)>, m_CubeVertexBuffer },
			{ CreateAttribute<2,	glm::vec2,	(2 * sizeof(glm::vec3)),sizeof(Vertex)>, m_CubeVertexBuffer },
		},
		m_CubeIndices
	);
}


void CMyApp::InitGround()
{
	std::vector<Vertex> verts;
	for (int x = 0; x < 50; ++x)
	{
		for (int z = 0; z < 50; ++z)
		{
			verts.push_back({ glm::vec3(x, 0.0f, z),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec2(x / 49.0f, z / 49.0f) });
		}
	}

	std::vector<int> indices;
	// CELLÁKON MEGYÜNK VÉGIG
	for (int x = 0; x < 49; ++x) {
		for (int z = 0; z < 49; ++z) {
			int topLeft = x * 50 + z;
			int topRight = (x + 1) * 50 + z;
			int bottomLeft = x * 50 + (z + 1);
			int bottomRight = (x + 1) * 50 + (z + 1);

			indices.push_back(topLeft);
			indices.push_back(bottomLeft);
			indices.push_back(bottomRight);

			indices.push_back(topLeft);
			indices.push_back(bottomRight);
			indices.push_back(topRight);
		}
	}

	m_GroundBuffer.BufferData(verts);
	m_GroundIndices.BufferData(indices);

	m_GroundVao.Init(
		{

			{ CreateAttribute<0 ,glm::vec3,		0 * sizeof(glm::vec3),	sizeof(Vertex)>, m_GroundBuffer },
			{ CreateAttribute<1, glm::vec3,		(1 * sizeof(glm::vec3)),	sizeof(Vertex)>, m_GroundBuffer },
			{ CreateAttribute<2, glm::vec2,		(2 * sizeof(glm::vec3)),	sizeof(Vertex)>, m_GroundBuffer },
		},
		m_GroundIndices
	);

}

void CMyApp::InitSkyBox()
{
	m_SkyboxPos.BufferData(
		std::vector<glm::vec3>{
		// hátsó lap
		glm::vec3(-1, -1, -1),
		glm::vec3(1, -1, -1),
		glm::vec3(1, 1, -1),
		glm::vec3(-1, 1, -1),
		// elülsõ lap
		glm::vec3(-1, -1, 1),
		glm::vec3(1, -1, 1),
		glm::vec3(1, 1, 1),
		glm::vec3(-1, 1, 1),
	}
	);

	// és a primitíveket alkotó csúcspontok indexei (az elõzõ tömbökbõl) - triangle list-el való kirajzolásra felkészülve
	m_SkyboxIndices.BufferData(
		std::vector<uint32_t>{
			// hátsó lap
			0, 1, 2,
			2, 3, 0,
			// elülsõ lap
			4, 6, 5,
			6, 4, 7,
			// bal
			0, 3, 4,
			4, 3, 7,
			// jobb
			1, 5, 2,
			5, 6, 2,
			// alsó
			1, 0, 4,
			1, 4, 5,
			// felsõ
			3, 2, 6,
			3, 6, 7,
	}
	);

	// geometria VAO-ban való regisztrálása
	m_SkyboxVao.Init(
		{
			{ CreateAttribute<0, glm::vec3, 0, sizeof(glm::vec3)>, m_SkyboxPos },
		}, m_SkyboxIndices
	);

	// skybox texture
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

	m_skyboxTexture.AttachFromFile("assets/xpos.png", true, GL_TEXTURE_CUBE_MAP_POSITIVE_X);
	m_skyboxTexture.AttachFromFile("assets/xneg.png", true, GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
	m_skyboxTexture.AttachFromFile("assets/ypos.png", true, GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
	m_skyboxTexture.AttachFromFile("assets/yneg.png", true, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
	m_skyboxTexture.AttachFromFile("assets/zpos.png", true, GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
	m_skyboxTexture.AttachFromFile("assets/zneg.png", true, GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);

	// a GL_TEXTURE_MAG_FILTER-t és a GL_TEXTURE_MIN_FILTER-t beállítja az AttachFromFile
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void CMyApp::InitShaders()
{
	// a shadereket tároló program létrehozása az OpenGL-hez hasonló módon:
	m_program.AttachShaders({
		{ GL_VERTEX_SHADER, "myVert.vert"},
		{ GL_FRAGMENT_SHADER, "myFrag.frag"}
	});

	// attributomok osszerendelese a VAO es shader kozt
	m_program.BindAttribLocations({
		{ 0, "vs_in_pos" },				// VAO 0-as csatorna menjen a vs_in_pos-ba
		{ 1, "vs_in_norm" },			// VAO 1-es csatorna menjen a vs_in_norm-ba
		{ 2, "vs_in_tex" },				// VAO 2-es csatorna menjen a vs_in_tex-be
	});

	m_program.LinkProgram();

	// shader program rövid létrehozása, egyetlen függvényhívással a fenti három:
	m_programSkybox.Init(
		{
			{ GL_VERTEX_SHADER, "skybox.vert" },
			{ GL_FRAGMENT_SHADER, "skybox.frag" }
		},
		{
			{ 0, "vs_in_pos" },				// VAO 0-as csatorna menjen a vs_in_pos-ba
		}
	);

	//winter

	m_programGround.AttachShaders({
	{ GL_VERTEX_SHADER, "ground.vert"},
	{ GL_FRAGMENT_SHADER, "ground.frag"}
	});

	// attributomok osszerendelese a VAO es shader kozt
	m_programGround.BindAttribLocations({
		{ 0, "vs_in_pos" },				// VAO 0-as csatorna menjen a vs_in_pos-ba
		{ 1, "vs_in_norm" },			// VAO 1-es csatorna menjen a vs_in_norm-ba
		{ 2, "vs_in_tex" },				// VAO 2-es csatorna menjen a vs_in_tex-be
		});

	m_programGround.LinkProgram();
}

bool CMyApp::Init()
{
	// törlési szín legyen kékes
	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_CULL_FACE); // kapcsoljuk be a hatrafele nezo lapok eldobasat
	glEnable(GL_DEPTH_TEST); // mélységi teszt bekapcsolása (takarás)

	InitShaders();
	InitGround();
	InitCube();
	InitSkyBox();

	// egyéb textúrák betöltése
	m_houseTexture.FromFile("Assets/house.jpg");
	m_roofTexture.FromFile("Assets/roof.jpg");
	m_casteTexture.FromFile("Assets/castle.jpg");
	m_groundTexture.FromFile("Assets/ground.jpg ");
	m_groundWinTexture.FromFile("Assets/groundWinter.jpg  ");
	m_treeTexture.FromFile("Assets/wood.jpg");
	m_workerTexture.FromFile("Assets/marron.jpg ");

	// Gula
	m_Gula = std::unique_ptr<Mesh>(ObjParser::parse("Assets/Pyramid.obj"));
	m_Gula->initBuffers();
	
	// kamera
	m_camera.SetProj(60.0f, 640.0f / 480.0f, 0.01f, 1000.0f);

	// Game

	//Empty
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			world[i][j].used = false;
			world[i][j].type = 0;
		}


	//Caste
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			world[i][j].used = true;

	//Tree
	std::vector<int> xs;
	std::vector<int> ys;
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
		{
			int rn = std::rand() % 100;
			if(rn <= 30 && world[i][j].used == false)
			{
				world[i][j].type = 1;
				world[i][j].randval = std::rand() % 100;
				xs.push_back(i);
				ys.push_back(j);
			}
		}

	//House
	const int count = 5;
	int i = count;
	std::vector<int> xhs;
	std::vector<int> yhs;
	while (i > 0)
	{
		int x = 1+rand() % 8;
		int y = 1+rand() % 8;
		if (world[x][y].used == false && world[x][y].type == 0)
		{
			xhs.push_back(x);
			yhs.push_back(y);
			world[x][y].type = 2;
			i--;
		}
	}

	//Job
	for (int i = 0; i < 5; i++)
	{
		int randtree = rand() % xs.size();
		jobs[i].x = xs[randtree];
		jobs[i].y = ys[randtree];
		jobs[i].timer = 0;
		jobs[i].state = 0;
		jobs[i].pos = glm::vec2(xhs[i]*5, yhs[i]*5);
	}


	return true;
}

void CMyApp::Clean()
{
}

void CMyApp::Update()
{
	static Uint32 last_time = SDL_GetTicks();
	float delta_time = (SDL_GetTicks() - last_time) / 1000.0f;

	m_camera.Update(delta_time);

	time += delta_time;
	float summer = fmod(time, 40) / 40;

	const float speed = 3;
	for (int i = 0; i < 5; i++)
	{
		glm::vec3 treePos = glm::vec3(jobs[i].x * 5, 0, jobs[i].y * 5);
		glm::vec3 castlePos = glm::vec3(5, 0, 5);
		glm::vec3 myPos = glm::vec3(jobs[i].pos.x, 0, jobs[i].pos.y);

		if (jobs[i].state == 0)
		{
			if (glm::length(treePos - myPos) < 0.25F)
			{
				jobs[i].state++;
			}
			else
			{
				glm::vec3 dir = glm::normalize(treePos - myPos);
				glm::vec3 dif = dir * delta_time * (1.5F + (3.F - 1.5F) * speed);
				jobs[i].pos.x += dif.x;
				jobs[i].pos.y += dif.z;
			}
		}
		else if (jobs[i].state == 1)
		{
			if (jobs[i].timer > (3 * (1 - summer)))
			{
				jobs[i].timer = 0;
				jobs[i].state++;
			}
			else
			{
				jobs[i].timer += delta_time;
			}
		}
		else if (jobs[i].state == 2)
		{
			if (glm::length(castlePos - myPos) < 0.25F)
			{
				jobs[i].state++;
			}
			else
			{
				glm::vec3 dir = glm::normalize(castlePos - myPos);
				glm::vec3 dif = dir * delta_time * (1.5F + (3.F - 1.5F) * speed);
				jobs[i].pos.x += dif.x;
				jobs[i].pos.y += dif.z;
			}
		}
		else if (jobs[i].state == 3)
		{
			if (jobs[i].timer > (3 * (1 - summer)))
			{
				jobs[i].timer = 0;
				jobs[i].state = 0;
				wood += 5;
			}
			else
			{
				jobs[i].timer += delta_time;
			}
		}
	}

	last_time = SDL_GetTicks();
}

void CMyApp::RenderHouse(glm::vec3 pos)
{
	glm::mat4 viewProj = m_camera.GetViewProj();

	m_program.Use();

	m_CubeVao.Bind();
	glm::mat4 cubeWorld;
	cubeWorld = glm::translate(glm::vec3(pos)) * glm::scale(glm::vec3(2, 1.5F, 2));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_program.SetTexture("texImage", 0, m_houseTexture);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	
	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(0,1.5F/2,0)) * glm::scale(glm::vec3(3, 1, 3));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_program.SetTexture("texImage", 0, m_roofTexture);
	m_Gula->draw();
	m_program.Unuse();
}

void CMyApp::RenderCastle(glm::vec3 pos)
{
	glm::mat4 viewProj = m_camera.GetViewProj();

	m_program.Use();
	m_program.SetTexture("texImage", 0, m_casteTexture);

	m_CubeVao.Bind();

	//Corners
	glm::mat4 cubeWorld;
	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(-5,0,-5)) * glm::scale(glm::vec3(3,6,3));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(5, 0, -5)) * glm::scale(glm::vec3(3, 6, 3));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(-5, 0, 5)) * glm::scale(glm::vec3(3, 6, 3));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(5, 0, 5)) * glm::scale(glm::vec3(3, 6, 3));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	//Walls
	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(5, -1, 0)) * glm::scale(glm::vec3(1.5, 4, 7));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(-5, -1, 0)) * glm::scale(glm::vec3(1.5, 4, 7));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(0, -1, 5)) * glm::scale(glm::vec3(7, 4, 1.5));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(0, -1, -5)) * glm::scale(glm::vec3(7, 4, 1.5));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	m_program.Unuse();

	//Tornyok

	m_program.Use();
	m_KupVao.Bind();
	m_program.SetTexture("texImage", 0, m_casteTexture);
	
	
	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(-5, 3, -5)) * glm::scale(glm::vec3(2.5F, 3, 2.5F));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(5, 3, -5)) * glm::scale(glm::vec3(2.5F, 3, 2.5F));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(-5, 3, 5)) * glm::scale(glm::vec3(2.5F, 3, 2.5F));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(5, 3, 5)) * glm::scale(glm::vec3(2.5F, 3, 2.5F));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();
	m_program.Unuse();
}

void CMyApp::RenderGround()
{
	glm::mat4 viewProj = m_camera.GetViewProj();

	m_GroundVao.Bind();
	m_programGround.Use();
	
	m_programGround.SetUniform("MVP", viewProj);
	m_programGround.SetUniform("world", glm::mat4(1.0f));
	m_programGround.SetUniform("worldIT", glm::mat4(1.0f));
	m_programGround.SetUniform("timer", glm::vec3(fmod(time, 40) / 40));
	m_programGround.SetTexture("texImage", 0, m_groundTexture);
	m_programGround.SetTexture("texImageWin", 1, m_groundWinTexture);

	glDrawElements(GL_TRIANGLES, 3 * 2 * 49 * 49, GL_UNSIGNED_INT, nullptr);
	m_programGround.Unuse();
}

void CMyApp::RenderTree(glm::vec3 pos, float size)
{
	glm::mat4 viewProj = m_camera.GetViewProj();
	glm::mat4 cubeWorld;

	m_program.Use();
	m_program.SetTexture("texImage", 0, m_treeTexture);

	cubeWorld = glm::translate(glm::vec3(pos)) * glm::scale(glm::vec3(1, 1, 1) * size);
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(0,.8,0)) * glm::scale(glm::vec3(.9, .9, .9) * size);
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();

	cubeWorld = glm::translate(glm::vec3(pos) + glm::vec3(0, 1.5, 0)) * glm::scale(glm::vec3(.7, .7, .7) * size);
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();

	m_program.Unuse();
	
}

void CMyApp::RenderWorker(glm::vec3 pos)
{
	glm::mat4 viewProj = m_camera.GetViewProj();
	glm::mat4 cubeWorld;

	m_program.Use();
	m_program.SetTexture("texImage", 0, m_workerTexture);

	cubeWorld = glm::translate(glm::vec3(pos)) * glm::scale(glm::vec3(.5, 1.5, .5));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_Gula->draw();
}

void CMyApp::Render()
{
	// töröljük a frampuffert (GL_COLOR_BUFFER_BIT) és a mélységi Z puffert (GL_DEPTH_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	RenderGround();
	RenderCastle(glm::vec3(7, 3, 7));

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (world[i][j].type == 1 && world[i][j].used == false)
			{
				RenderTree(glm::vec3(5*i, 0, 5*j), 0.8 + ((1.2-0.8) * (world[i][j].randval / 100.F)));
			}
			else if (world[i][j].type == 2 && world[i][j].used == false)
			{
				RenderHouse(glm::vec3(5 * i, .75f, 5 * j));
			}

	for (int i = 0; i < 5; i++)
		RenderWorker(glm::vec3(jobs[i].pos.x, 0, jobs[i].pos.y));
	
	


	// skybox
	// mentsük el az elõzõ Z-test eredményt, azaz azt a relációt, ami alapján update-eljük a pixelt.
	GLint prevDepthFnc;
	glGetIntegerv(GL_DEPTH_FUNC, &prevDepthFnc);

	// most kisebb-egyenlõt használjunk, mert mindent kitolunk a távoli vágósíkokra
	glDepthFunc(GL_LEQUAL);

	glm::mat4 viewProj = m_camera.GetViewProj();

	m_SkyboxVao.Bind();
	m_programSkybox.Use();
	m_programSkybox.SetUniform("MVP", viewProj * glm::translate( m_camera.GetEye()) );
	
	// cube map textúra beállítása 0-ás mintavételezõre és annak a shaderre beállítása
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_skyboxTexture);
	glUniform1i(m_programSkybox.GetLocation("skyboxTexture"), 0);
	// az elõzõ három sor <=> m_programSkybox.SetCubeTexture("skyboxTexture", 0, m_skyboxTexture);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	m_programSkybox.Unuse();

	// végül állítsuk vissza
	glDepthFunc(prevDepthFnc);

	if (ImGui::Begin("Informations"))
	{
		ImGui::Text("Wood - %d", wood);
		ImGui::Checkbox("Evszakok", &menuflag);
		if (menuflag)
		{
			ImGui::Text("Evszakok: TODO");
		}
	}

	ImGui::End();
}

void CMyApp::KeyboardDown(SDL_KeyboardEvent& key)
{
	m_camera.KeyboardDown(key);
}

void CMyApp::KeyboardUp(SDL_KeyboardEvent& key)
{
	m_camera.KeyboardUp(key);
}

void CMyApp::MouseMove(SDL_MouseMotionEvent& mouse)
{
	m_camera.MouseMove(mouse);
}

void CMyApp::MouseDown(SDL_MouseButtonEvent& mouse)
{
}

void CMyApp::MouseUp(SDL_MouseButtonEvent& mouse)
{
}

void CMyApp::MouseWheel(SDL_MouseWheelEvent& wheel)
{
}

// a két paraméterbe az új ablakméret szélessége (_w) és magassága (_h) található
void CMyApp::Resize(int _w, int _h)
{
	glViewport(0, 0, _w, _h );

	m_camera.Resize(_w, _h);
}
