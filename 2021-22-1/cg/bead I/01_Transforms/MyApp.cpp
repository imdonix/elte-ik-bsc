#include "MyApp.h"
#include "GLUtils.hpp"

#include <math.h>

// x^3 + y^4 – x*y+ x*z^3 <10
bool p(glm::vec3 pos)
{
	return pow(pos.x, 3) + pow(pos.y, 4) - (pos.x * pos.y) + (pos.x * pow(pos.z, 3)) < 10;
}

float rf(float a, float b)
{
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

const float twoPi = 3.14 * 2;
glm::vec3 pf(float time)
{
	float state = fmod(time, 10) / 10;
	float x = sin((state + twoPi / 3) * twoPi) * 10;
	return glm::vec3(x, 0.05 * pow(x, 2), 0);
}

float ps(float time)
{
	float state = fmod(time, 6) / 6;
	return 0.5 + ((sin((state + twoPi / 3) * twoPi) + 1) / 2) * (2 - 0.5);
}

CMyApp::CMyApp()
{
}

CMyApp::~CMyApp()
{
}

bool CMyApp::Init()
{
	active = false;
	timer = 0;
	ts = 0;
	last = SDL_GetTicks();

	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_DEPTH_TEST); 
	glCullFace(GL_BACK);

	static const GLfloat g_vertex_buffer_data[] = {
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f,-1.0f, 1.0f
	};

	Vertex vert[] =
	{ 
		//s0
		{glm::vec3(-1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0, 0, 0.5)},
		{glm::vec3(-1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(0, 0, 0.5)},
		{glm::vec3(-1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(0, 0, 0.5)},

		{glm::vec3(1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(0, 0, 1)},
		{glm::vec3(-1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0, 0, 1)},
		{glm::vec3(-1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(0, 0, 1)},

		//s1
		{glm::vec3(1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(0, 0.5, 0)},
		{glm::vec3(-1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0, 0.5, 0)},
		{glm::vec3(1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0, 0.5, 0)},

		{glm::vec3(1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(0, 1, 0)},
		{glm::vec3(1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0, 1, 0)},
		{glm::vec3(-1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0, 1, 0)},


		//s2
		{glm::vec3(-1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0.5, 0, 0.5)},
		{glm::vec3(-1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0, 0.5)},
		{glm::vec3(-1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(0.5, 0, 0.5)},

		{glm::vec3(1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(1, 0, 1)},
		{glm::vec3(-1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(1, 0, 1)},
		{glm::vec3(-1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(1, 0, 1)},

		//s3
		{glm::vec3(-1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0, 0)},
		{glm::vec3(-1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0, 0)},
		{glm::vec3(1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0, 0)},

		{glm::vec3(1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(1, 0, 0)},
		{glm::vec3(1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(1, 0, 0)},
		{glm::vec3(1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(1, 0, 0)},

		//s4
		{glm::vec3(1.0f,-1.0f,-1.0f) / 2.f, glm::vec3(0.5, 0.5, 0)},
		{glm::vec3(1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0.5, 0)},
		{glm::vec3(1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0.5, 0)},

		{glm::vec3(1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(1, 1, 0)},
		{glm::vec3(1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(1, 1, 0)},
		{glm::vec3(-1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(1, 1, 0)},

		//s5
		{glm::vec3(1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0.5, 0.5)},
		{glm::vec3(-1.0f, 1.0f,-1.0f) / 2.f, glm::vec3(0.5, 0.5, 0.5)},
		{glm::vec3(-1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(0.5, 0.5, 0.5)},

		{glm::vec3(1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(1, 1, 1)},
		{glm::vec3(-1.0f, 1.0f, 1.0f) / 2.f, glm::vec3(1, 1, 1)},
		{glm::vec3(1.0f,-1.0f, 1.0f) / 2.f, glm::vec3(1, 1, 1)},

	};

	shape[0] = glm::vec3(0, 0, 0);
	shape[1] = glm::vec3(-1, 0, 0);
	shape[2] = glm::vec3(-1, 1, 0);
	shape[3] = glm::vec3(-2, 1, 0);
	shape[4] = glm::vec3(-2, 2, 0);

	int i = 0;
	while (i < 6)
	{
		//–5 <= x,y,z<= 5
		glm::vec3 pos = glm::vec3(rf(-5,5), rf(-5, 5), rf(-5, 5));
		if (p(pos))
			objects[i++] = pos;
	}


	glGenVertexArrays(1, &m_vaoID);
	glBindVertexArray(m_vaoID);
	glGenBuffers(1, &m_vboID); 
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID); 
	glBufferData( GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),0); 

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1,3, GL_FLOAT,GL_FALSE,sizeof(Vertex), (void*)(sizeof(glm::vec3)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint vs_ID = loadShader(GL_VERTEX_SHADER,		"myVert.vert");
	GLuint fs_ID = loadShader(GL_FRAGMENT_SHADER,	"myFrag.frag");

	m_programID = glCreateProgram();

	glAttachShader(m_programID, vs_ID);
	glAttachShader(m_programID, fs_ID);


	glBindAttribLocation(m_programID, 0,"vs_in_pos");
	glBindAttribLocation( m_programID, 1, "vs_in_col");
	glLinkProgram(m_programID);

	GLint infoLogLength = 0, result = 0;

	glGetProgramiv(m_programID, GL_LINK_STATUS, &result);
	glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (GL_FALSE == result || infoLogLength != 0)
	{
		std::vector<char> VertexShaderErrorMessage(infoLogLength);
		glGetProgramInfoLog(m_programID, infoLogLength, nullptr, VertexShaderErrorMessage.data());
		std::cerr << "[glLinkProgram] Shader linking error:\n" << &VertexShaderErrorMessage[0] << std::endl;
	}

	glDeleteShader( vs_ID );
	glDeleteShader( fs_ID );

	m_loc_world = glGetUniformLocation( m_programID, "world");
	m_loc_view  = glGetUniformLocation( m_programID, "view" );
	m_loc_proj  = glGetUniformLocation( m_programID, "proj" );

	return true;
}

void CMyApp::Clean()
{
	glDeleteBuffers(1, &m_vboID);
	glDeleteVertexArrays(1, &m_vaoID);
	glDeleteProgram( m_programID );
}

void CMyApp::Update()
{
	Uint32 curr = SDL_GetTicks();
	float delta = ((curr - last) / 1000.0F);
	last = curr;


	timer += delta;
	if (active) ts += delta;

	glm::vec3 camPos = glm::vec3(0, 0, -20);
	m_matView = glm::lookAt(
			camPos,		
			camPos + glm::vec3( 0,  0,  1),
			glm::vec3( 0,  1,  0));
}

void CMyApp::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram( m_programID );

	/*
	GLM transzformációs mátrixokra példák:
		glm::rotate<float>( szög, glm::vec3(tengely_x, tengely_y, tengely_z) ) <- tengely_{xyz} körüli elforgatás
		glm::translate<float>( glm::vec3(eltol_x, eltol_y, eltol_z) ) <- eltolás
		glm::scale<float>( glm::vec3(s_x, s_y, s_z) ) <- skálázás
	*/

	glBindVertexArray(m_vaoID);

	glUniformMatrix4fv( m_loc_view,  1, GL_FALSE, &( m_matView[0][0]) );
	glUniformMatrix4fv( m_loc_proj,  1, GL_FALSE, &( m_matProj[0][0]) );

	std::cout << ps(ts) << std::endl << ts << std::endl;
	for (int j = 0; j < 6; j++)
		for (int i = 0; i < 5; i++)
		{
			m_matWorld = glm::translate<float>(pf(timer) + objects[j] + (shape[i] * glm::vec3(ps(ts), 1, 1))) * glm::scale<float>(glm::vec3(ps(ts) ,1, 1));
			glUniformMatrix4fv(m_loc_world, 1, GL_FALSE, &(m_matWorld[0][0]));
			glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		}

	glBindVertexArray(0);
	glUseProgram(0);
}

void CMyApp::KeyboardDown(SDL_KeyboardEvent& key)
{
	if (key.keysym.sym == SDLK_SPACE)
		active = !active;
}

void CMyApp::KeyboardUp(SDL_KeyboardEvent& key){}

void CMyApp::MouseMove(SDL_MouseMotionEvent& mouse){}

void CMyApp::MouseDown(SDL_MouseButtonEvent& mouse){}

void CMyApp::MouseUp(SDL_MouseButtonEvent& mouse){}

void CMyApp::MouseWheel(SDL_MouseWheelEvent& wheel){}


void CMyApp::Resize(int _w, int _h)
{
	glViewport(0, 0, _w, _h);
	m_matProj = glm::perspective(glm::radians(60.0f),_w/(float)_h,0.01f,100.0f);
}