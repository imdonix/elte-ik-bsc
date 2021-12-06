#include "MyApp.h"

#include <math.h>
#include <vector>

#include <array>
#include <list>
#include <tuple>

#include <random>

#include "imgui\imgui.h"

#include "Includes/ObjParser_OGL3.h"
#include "Includes/GLUtils.hpp"


glm::vec3 CMyApp::lighPosition()
{	
	float adjusted = fmod(m_lightState, m_lightAmplitudo) / m_lightAmplitudo;
	glm::vec3 pos = glm::vec3(sin(adjusted * M_PI * 2), 0, cos(adjusted * M_PI * 2));
	return glm::vec3(0) - pos;
}

glm::vec3 CMyApp::GetSpherePos(float u, float v)
{
	u *= float(2 * M_PI);
	v *= float(M_PI);
	float r = 2;

	return glm::vec3(r * sin(v) * cos(u),
		r * cos(v),
		r * sin(v) * sin(u));
}

glm::vec3 CMyApp::GetNorm(float u, float v)
{
	u *= float(2 * M_PI);
	v *= float(M_PI);
	return glm::vec3(sin(v) * cos(u), cos(v), sin(v) * sin(u));
}

glm::vec2 CMyApp::GetTex(float u, float v)
{
	return glm::vec2(1 - u, 1 - v);
}

void CMyApp::InitSphere()
{
	// NxM darab négyszöggel közelítjük a parametrikus felületünket => (N+1)x(M+1) pontban kell kiértékelni
	glm::vec3 pos[(N + 1) * (M + 1)];
	glm::vec3 norm[(N + 1) * (M + 1)];
	glm::vec2 tex[(N + 1) * (M + 1)];
	for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= M; ++j)
		{
			float u = i / (float)N;
			float v = j / (float)M;

			pos[i + j * (N + 1)] = GetSpherePos(u, v);
			norm[i + j * (N + 1)] = GetNorm(u, v);
			tex[i + j * (N + 1)] = GetTex(u, v);
		}

	// indexpuffer adatai: NxM négyszög = 2xNxM háromszög = háromszöglista esetén 3x2xNxM index
	GLushort indices[3 * 2 * (N) * (M)];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			indices[6 * i + j * 3 * 2 * (N)+0] = (i)+(j) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+1] = (i + 1) + (j) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+2] = (i)+(j + 1) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+3] = (i + 1) + (j) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+4] = (i + 1) + (j + 1) * (N + 1);
			indices[6 * i + j * 3 * 2 * (N)+5] = (i)+(j + 1) * (N + 1);
		}

	m_globe_gpuBufferPos.BufferData(pos);
	m_globe_gpuBufferNorm.BufferData(norm);
	m_globe_gpuBufferTex.BufferData(tex);
	m_globe_gpuBufferIndices.BufferData(indices);


	m_globe_vao.Init(
		{
			{ CreateAttribute<0, glm::vec3, 0, sizeof(glm::vec3)>, m_globe_gpuBufferPos },
			{ CreateAttribute<1, glm::vec3, 0, sizeof(glm::vec3)>, m_globe_gpuBufferNorm },	
			{ CreateAttribute<2, glm::vec2, 0, sizeof(glm::vec2)>, m_globe_gpuBufferTex }
		},
		m_globe_gpuBufferIndices
	);
}

void CMyApp::InitCube()
{
	m_gpuBufferPos.BufferData(
		std::vector<glm::vec3>{
		// hátsó lap
		glm::vec3(-1, -1, -1),
			glm::vec3(1, -1, -1),
			glm::vec3(1, 1, -1),
			glm::vec3(-1, 1, -1),
			// elülső lap
			glm::vec3(-1, -1, 1),
			glm::vec3(1, -1, 1),
			glm::vec3(1, 1, 1),
			glm::vec3(-1, 1, 1),

	}
	);

	// és a primitíveket alkotó csúcspontok indexei (az előző tömbökből) - triangle list-el való kirajzolásra felkészülve
	m_gpuBufferIndices.BufferData(
		std::vector<int>{
		// hátsó lap
		0, 1, 2,
		2, 3, 0,
		// elülső lap
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
		// felső
		3, 2, 6,
		3, 6, 7,
	}
	);


	m_vao.Init(
	{
		{ CreateAttribute<0, glm::vec3, 0, sizeof(glm::vec3)>, m_gpuBufferPos },		// 0-ás attribútum "lényegében" glm::vec3-ak sorozata és az adatok az m_gpuBufferPos GPU pufferben vannak
	},
		m_gpuBufferIndices
	);
}

CMyApp::CMyApp(void)
{
	m_camera.SetView(glm::vec3(5, 5, 5), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
}


CMyApp::~CMyApp(void)
{
	
}

bool CMyApp::Init()
{
	glClearColor(0.1f,0.1f,0.41f, 1);

	glEnable(GL_DEPTH_TEST); 

	glLineWidth(4.0f);
	glPointSize(15.0f); 

	m_camera.SetProj(45.0f, 640.0f / 480.0f, 0.01f, 1000.0f);

	// shaderek betöltése
	m_globeProgram.Init({
	{ GL_VERTEX_SHADER,		"globe.vert" },
	{ GL_FRAGMENT_SHADER,	"globe.frag" }
	},
	{
		{0, "vs_in_pos"},
		{1, "vs_in_norm"},
		{2, "vs_in_tex"}
	});

	m_passthroughProgram.Init({
		{ GL_VERTEX_SHADER,		"passthrough.vert" },
		{ GL_FRAGMENT_SHADER,	"passthrough.frag" }
	},
	{
		{0, "vs_in_pos"}
	});

	m_boidProgram.Init({
		{ GL_VERTEX_SHADER,		"boid.vert" },
		{ GL_FRAGMENT_SHADER,	"boid.frag" }
	},
	{
		{ 0, "vs_in_pos" },
		{ 1, "vs_in_vel" },
	});

	// textura betöltése

	m_globe_Texture.FromFile("earthmap1k.jpg");

	// geometria definiálása
	InitSphere();
	InitCube();

	// boidok inicializálása
	m_boidPos.reserve(m_boidCount);
	m_boidVel.reserve(m_boidCount);

	// véletlenszám generátor inicializálása
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> rnd(-1,1);

	// CPU oldali boidok feltöltése
	for (int i = 0; i < m_boidCount; ++i)
	{
		m_boidPos.push_back( glm::vec3(rnd(gen), rnd(gen), rnd(gen)) );
		m_boidVel.push_back( glm::vec3( 2*rnd(gen), 2*rnd(gen), 2*rnd(gen) ) );
	}

	// GPU-ra áttölteni a részecskék pozícióit
	m_gpuBoidBuffer.BufferData(m_boidPos);

	// és végül a VAO-t inicializálni
	m_gpuBoidVAO.Init({
		{CreateAttribute<0, glm::vec3, 0, sizeof(glm::vec3)>, m_gpuBoidBuffer}
	});

	return true;
}

void CMyApp::Clean()
{
}

void CMyApp::Update()
{
	static Uint32 last_time = SDL_GetTicks();
	float delta_time = (SDL_GetTicks() - last_time) / 1000.0f;

	m_lightState += delta_time * m_lightTravel;
	m_camera.Update(delta_time);

	// frissítsük a pozíciókat
	static const float energyRemaining = 1;	// tökéletesen rugalmas ütközés
	for (int i = 0; i < m_boidCount; ++i)
	{
		//Coherence
		int count = 0;
		glm::vec3 s = glm::vec3(0);
		for (int j = 0; j < m_boidCount; ++j)
			if (glm::distance(m_boidPos[i], m_boidPos[j]) < 0.3F)
			{
				count++;
				s += m_boidPos[j];
			}

		glm::vec3 wp = s / (float) count;
		m_boidVel[i] += (wp - m_boidPos[i]) * a;
		
		//Separation
		for (int j = 0; j < m_boidCount; ++j)
			if (glm::distance(m_boidPos[i], m_boidPos[j]) < 0.3F)
				m_boidVel[i] += (m_boidPos[i] - m_boidPos[j]) * b;
		

		//Alignment
		count = 0;
		s = glm::vec3(0);
		for (int j = 0; j < m_boidCount; ++j)
			if (glm::distance(m_boidPos[i], m_boidPos[j]) < 0.3F)
			{
				s += m_boidVel[j];
				count++;
			}

		glm::vec3 va = s / (float) count;
		m_boidVel[i] += va * c;
		
		
		//Limit
		if (glm::length(m_boidVel[i]) > limit)
			m_boidVel[i] *= limit / glm::length(m_boidVel[i]);


		m_boidPos[i] += m_boidVel[i] * delta_time;

		if ( (m_boidPos[i].x >= 1 && m_boidVel[i].x > 0) || (m_boidPos[i].x <= -1 && m_boidVel[i].x < 0) )
			m_boidVel[i].x *= -energyRemaining;
		if ( (m_boidPos[i].y >= 1 && m_boidVel[i].y > 0) || (m_boidPos[i].y <= -1 && m_boidVel[i].y < 0))
			m_boidVel[i].y *= -energyRemaining;
		if ( (m_boidPos[i].z >= 1 && m_boidVel[i].z > 0) || (m_boidPos[i].z <= -1 && m_boidVel[i].z < 0))
			m_boidVel[i].z *= -energyRemaining;
	}

	// frissítsük a puffert
	glBindBuffer(GL_ARRAY_BUFFER, m_gpuBoidBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::vec3)* m_boidPos.size(), &(m_boidPos[0][0]));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	last_time = SDL_GetTicks();
}

void CMyApp::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// gömb
	m_globe_vao.Bind();
	m_globeProgram.Use();

	glm::mat4 viewProj = m_camera.GetViewProj();
	glm::mat4 world = glm::mat4(1.0f);
	glm::mat4 wolrdIT = glm::inverse(glm::transpose(world));
	glm::mat4 mvp = viewProj * world * glm::translate<float>(glm::vec3(0,4,0));

	m_globeProgram.SetUniform("MVP", mvp);
	m_globeProgram.SetUniform("world", world);
	m_globeProgram.SetUniform("worldIT", wolrdIT);

	m_globeProgram.SetUniform("camera_pos", m_camera.GetViewProj());
	m_globeProgram.SetUniform("light_dir", lighPosition());

	m_globeProgram.SetTexture("texImage", 0, m_globe_Texture);

	glDrawElements(GL_TRIANGLES, 3 * 2 * (N) * (M), GL_UNSIGNED_SHORT, 0);

	// kocka
	
	
	glPolygonMode(GL_BACK, GL_LINE);
	m_vao.Bind();

	m_passthroughProgram.Use();
	m_passthroughProgram.SetUniform("mvp", m_camera.GetViewProj());

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr);
	

	// részecskék

	
	glEnable(GL_PROGRAM_POINT_SIZE);
	m_gpuBoidVAO.Bind();
	m_boidProgram.Use();
	m_boidProgram.SetUniform("mvp", m_camera.GetViewProj());

	glDrawArrays(GL_POINTS, 0, m_boidCount);

	glDisable(GL_PROGRAM_POINT_SIZE);
	

	ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiSetCond_FirstUseEver);
	// csak akkor lépjünk be, hogy ha az ablak nincs csíkká lekicsinyítve...
	if (ImGui::Begin("Informations"))	
	{
		ImGui::Text("Globe - earthmap1k.jpg");
		if(ImGui::Button("Revert Light Travel")) m_lightTravel *= -1;
		ImGui::NewLine();
		ImGui::Text("Boids - 150");
		ImGui::SliderFloat("a (Coherence)", &a, 0, 1, "%.2f", 1);
		ImGui::SliderFloat("b (Separation)", &b, 0, 1, "%.2f", 1);
		ImGui::SliderFloat("c (Alignment)", &c, 0, 1, "%.2f", 1);
		ImGui::SliderFloat("Speed Limit", &limit, 1, 5, "%.2f", 1);
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