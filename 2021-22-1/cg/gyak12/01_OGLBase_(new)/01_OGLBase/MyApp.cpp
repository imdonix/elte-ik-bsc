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
	m_mesh = nullptr;
}

CMyApp::~CMyApp(void)
{
}

void CMyApp::InitGround() {
	m_GroundHeights.resize(20);
	for (int x = 0; x < 20; ++x) {
		m_GroundHeights[x].resize(20);
		for (int z = 0; z < 20; ++z) {
			m_GroundHeights[x][z] = sin(x * z) / 4.0f;
		}
	}

	std::vector<Vertex> vertices;
	for (int x = 0; x < 20; ++x) {
		for (int z = 0; z < 20; ++z) {
			vertices.push_back({
				glm::vec3(x, m_GroundHeights[x][z], z) - glm::vec3(10.0f, 0.0f, 10.0f),
				glm::vec3(0.0f, 1.0f, 0.0f),
				glm::vec2(x / 19.0f, z / 19.0f)
			});
		}
	}

	std::vector<int> indices;
	// CELLÁKON MEGYÜNK VÉGIG
	for (int x = 0; x < 19; ++x) {
		for (int z = 0; z < 19; ++z) {
			int topLeft = x * 20 + z;
			int topRight = (x + 1) * 20 + z;
			int bottomLeft = x * 20 + (z + 1);
			int bottomRight = (x + 1) * 20 + (z + 1);

			indices.push_back(topLeft);
			indices.push_back(bottomLeft);
			indices.push_back(bottomRight);

			indices.push_back(topLeft);
			indices.push_back(bottomRight);
			indices.push_back(topRight);
		}
	}

	m_GroundBuffer.BufferData(vertices);

	// és a primitíveket alkotó csúcspontok indexei (az elõzõ tömbökbõl) - triangle list-el való kirajzolásra felkészülve
	m_GroundIndices.BufferData(indices);

	// geometria VAO-ban való regisztrálása
	m_GroundVao.Init(
		{
			// 0-ás attribútum "lényegében" glm::vec3-ak sorozata és az adatok az m_CubeVertexBuffer GPU pufferben vannak
			{ CreateAttribute<		0,						// attribútum: 0
									glm::vec3,				// CPU oldali adattípus amit a 0-ás attribútum meghatározására használtunk <- az eljárás a glm::vec3-ból kikövetkezteti, hogy 3 darab float-ból áll a 0-ás attribútum
									0,						// offset: az attribútum tároló elejétõl vett offset-je, byte-ban
									sizeof(Vertex)			// stride: a következõ csúcspont ezen attribútuma hány byte-ra van az aktuálistól
								>, m_GroundBuffer },
			{ CreateAttribute<1, glm::vec3, (sizeof(glm::vec3)), sizeof(Vertex)>, m_GroundBuffer },
			{ CreateAttribute<2, glm::vec2, (2 * sizeof(glm::vec3)), sizeof(Vertex)>, m_GroundBuffer },
		},
		m_GroundIndices
	);

}

void CMyApp::InitCube()
{
	//struct Vertex{ glm::vec3 position; glm::vec3 normals; glm::vec2 texture; };
	std::vector<Vertex>vertices;
	
	//front									 
	vertices.push_back({ glm::vec3(-0.5, -0.5, +0.5), glm::vec3(0, 0, 1), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, +0.5), glm::vec3(0, 0, 1), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, +0.5), glm::vec3(0, 0, 1), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, +0.5), glm::vec3(0, 0, 1), glm::vec2(1, 1) });
	//back
	vertices.push_back({ glm::vec3(+0.5, -0.5, -0.5), glm::vec3(0, 0, -1), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0, 0, -1), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, -0.5), glm::vec3(0, 0, -1), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, -0.5), glm::vec3(0, 0, -1), glm::vec2(1, 1) });
	//right									 
	vertices.push_back({ glm::vec3(+0.5, -0.5, +0.5), glm::vec3(1, 0, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, -0.5), glm::vec3(1, 0, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, +0.5), glm::vec3(1, 0, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, -0.5), glm::vec3(1, 0, 0), glm::vec2(1, 1) });
	//left									 
	vertices.push_back({ glm::vec3(-0.5, -0.5, -0.5), glm::vec3(-1, 0, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(-0.5, -0.5, +0.5), glm::vec3(-1, 0, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, -0.5), glm::vec3(-1, 0, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, +0.5), glm::vec3(-1, 0, 0), glm::vec2(1, 1) });
	//top									 
	vertices.push_back({ glm::vec3(-0.5, +0.5, +0.5), glm::vec3(0, 1, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, +0.5), glm::vec3(0, 1, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, -0.5), glm::vec3(0, 1, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, -0.5), glm::vec3(0, 1, 0), glm::vec2(1, 1) });
	//bottom								 
	vertices.push_back({ glm::vec3(-0.5, -0.5, -0.5), glm::vec3(0, -1, 0), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, -0.5), glm::vec3(0, -1, 0), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, -0.5, +0.5), glm::vec3(0, -1, 0), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, +0.5), glm::vec3(0, -1, 0), glm::vec2(1, 1) });

	std::vector<int> indices(36);
	int index = 0;
	for (int i = 0; i < 6 * 4; i += 4)
	{
		indices[index + 0] = i + 0;
		indices[index + 1] = i + 2;
		indices[index + 2] = i + 1;

		indices[index + 3] = i + 1;
		indices[index + 4] = i + 2;
		indices[index + 5] = i + 3;
		index += 6;
	}

	//
	// geometria definiálása (std::vector<...>) és GPU pufferekbe való feltöltése BufferData-val
	//

	// vertexek pozíciói:
	/*
	Az m_CubeVertexBuffer konstruktora már létrehozott egy GPU puffer azonosítót és a most következõ BufferData hívás ezt
	1. bind-olni fogja GL_ARRAY_BUFFER target-re (hiszen m_CubeVertexBuffer típusa ArrayBuffer) és
	2. glBufferData segítségével áttölti a GPU-ra az argumentumban adott tároló értékeit

	*/

	m_CubeVertexBuffer.BufferData(vertices);

	// és a primitíveket alkotó csúcspontok indexei (az elõzõ tömbökbõl) - triangle list-el való kirajzolásra felkészülve
	m_CubeIndices.BufferData(indices);

	// geometria VAO-ban való regisztrálása
	m_CubeVao.Init(
		{
			// 0-ás attribútum "lényegében" glm::vec3-ak sorozata és az adatok az m_CubeVertexBuffer GPU pufferben vannak
			{ CreateAttribute<		0,						// attribútum: 0
									glm::vec3,				// CPU oldali adattípus amit a 0-ás attribútum meghatározására használtunk <- az eljárás a glm::vec3-ból kikövetkezteti, hogy 3 darab float-ból áll a 0-ás attribútum
									0,						// offset: az attribútum tároló elejétõl vett offset-je, byte-ban
									sizeof(Vertex)			// stride: a következõ csúcspont ezen attribútuma hány byte-ra van az aktuálistól
								>, m_CubeVertexBuffer },
			{ CreateAttribute<1, glm::vec3, (sizeof(glm::vec3)), sizeof(Vertex)>, m_CubeVertexBuffer },
			{ CreateAttribute<2, glm::vec2, (2 * sizeof(glm::vec3)), sizeof(Vertex)>, m_CubeVertexBuffer },
		},
		m_CubeIndices
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
		std::vector<int>{
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
}

bool CMyApp::Init()
{
	// törlési szín legyen kékes
	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_CULL_FACE); // kapcsoljuk be a hatrafele nezo lapok eldobasat
	glEnable(GL_DEPTH_TEST); // mélységi teszt bekapcsolása (takarás)

	InitShaders();
	InitCube();
	InitSkyBox();
	InitGround();

	// egyéb textúrák betöltése
	m_grassTexture.FromFile("assets/grass.jpg");
	m_forestTexture.FromFile("assets/forest.jpg");
	m_barkTexture.FromFile("assets/bark.jpg");

	// mesh betoltese
	m_mesh = std::unique_ptr<Mesh>(ObjParser::parse("assets/henger.obj"));
	m_mesh->initBuffers();
	
	// kamera
	m_camera.SetProj(60.0f, 640.0f / 480.0f, 0.01f, 1000.0f);


	m_TreePositions.resize(20);
	for (int x = 0; x < 20; ++x) {
		m_TreePositions[x].resize(20);
	}

	int treeNum = rand() % 51 + 50;
	for (int i = 0; i < treeNum; ++i) {
		glm::vec3 treePos;

		int randX, randZ;
		do {
			randX = rand() % 18 + 1;
			randZ = rand() % 18 + 1;
		} while (m_TreePositions[randX][randZ].exists);
		
		float height = m_GroundHeights[randX][randZ];
		treePos.x = randX - 10;
		treePos.y = height;
		treePos.z = randZ - 10;

		m_TreePositions[randX][randZ].pos = treePos;
		m_TreePositions[randX][randZ].exists = true;
		m_TreePositions[randX][randZ].size = 0.05f;
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

	last_time = SDL_GetTicks();

	int treeT = SDL_GetTicks() / 2000;
	if (lastTreeUpdate < treeT) {
		for (int x = 1; x < 19; ++x) {
			for (int z = 1; z < 19; ++z) {
				if (rand() % 101 <= 5) {
					if (!m_TreePositions[x][z].exists) {
						m_TreePositions[x][z].exists = true;
						m_TreePositions[x][z].size = 0.05f;

						glm::vec3 treePos;
						float height = m_GroundHeights[x][z];
						treePos.x = x - 10;
						treePos.y = height;
						treePos.z = z - 10;

						m_TreePositions[x][z].pos = treePos;
					}
				}

			}

		}


		lastTreeUpdate = treeT;
	}
	for (int x = 0; x < 20; ++x) {
		for (int z = 0; z < 20; ++z) {
			if (m_TreePositions[x][z].exists) {
				m_TreePositions[x][z].size += delta_time / treeGrowthTime;

				if (m_TreePositions[x][z].size > 1.0f) {
					++numCutTrees;
					m_TreePositions[x][z].exists = false;
				}
			}

		}
	}
}

void CMyApp::Render()
{
	// töröljük a frampuffert (GL_COLOR_BUFFER_BIT) és a mélységi Z puffert (GL_DEPTH_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 viewProj = m_camera.GetViewProj();

	//Suzanne
	m_program.Use();
	m_program.SetTexture("texImage", 0, m_barkTexture);

	for (int x = 0; x < 20; ++x) {
		for (int z = 0; z < 20; ++z) {
			if (m_TreePositions[x][z].exists) {
				glm::mat4 treeWorld = glm::translate(m_TreePositions[x][z].pos + glm::vec3(0.0f, 2.0f * m_TreePositions[x][z].size, 0.0f))
					* glm::scale(glm::vec3(m_TreePositions[x][z].size));
				m_program.SetUniform("MVP", viewProj * treeWorld);
				m_program.SetUniform("world", treeWorld);
				m_program.SetUniform("worldIT", glm::inverse(glm::transpose(treeWorld)));
				m_mesh->draw();
			}
		}
	}

	// kockák
	//m_program.Use(); nem hívjuk meg újra, hisz ugyanazt a shadert használják


	m_CubeVao.Bind();
	glm::mat4 cubeWorld;
	cubeWorld = glm::scale(glm::vec3(20.0f, 10.0f, 20.0f));
	m_program.SetUniform("MVP", viewProj * cubeWorld);
	m_program.SetUniform("world", cubeWorld);
	m_program.SetUniform("worldIT", glm::inverse(glm::transpose(cubeWorld)));
	m_program.SetTexture("texImage", 0, m_forestTexture);
	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, nullptr);


	m_GroundVao.Bind();
	m_program.SetUniform("MVP", viewProj);
	m_program.SetUniform("world", glm::mat4(1.0f));
	m_program.SetUniform("worldIT", glm::mat4(1.0f));
	m_program.SetTexture("texImage", 0, m_grassTexture);
	glDrawElements(GL_TRIANGLES, 19 * 19 * 2 * 3, GL_UNSIGNED_INT, nullptr);

	m_program.Unuse();

	// skybox
	// mentsük el az elõzõ Z-test eredményt, azaz azt a relációt, ami alapján update-eljük a pixelt.
	GLint prevDepthFnc;
	glGetIntegerv(GL_DEPTH_FUNC, &prevDepthFnc);

	// most kisebb-egyenlõt használjunk, mert mindent kitolunk a távoli vágósíkokra
	glDepthFunc(GL_LEQUAL);

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


	if (ImGui::Begin("Fa kontrollok")) {
		ImGui::SliderFloat("Fa novekedes ido", &treeGrowthTime, 1.0f, 20.0f);
		ImGui::Text("Kivagott fak: %d", numCutTrees);


		ImGui::End();
	}
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
