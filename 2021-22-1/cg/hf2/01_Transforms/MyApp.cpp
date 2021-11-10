#include "MyApp.h"
#include "GLUtils.hpp"

#include <math.h>

CMyApp::CMyApp()
{
}

CMyApp::~CMyApp()
{
}

bool CMyApp::Init()
{
	cameraPos = glm::vec3(0, 0, -5);
	input = glm::vec3(0);
	timer = 0;
	last = SDL_GetTicks();
	speed = 2;
	amplitudo = 3;
	amplitudoTime = 5;

	// törlési szín legyen kékes
	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_DEPTH_TEST); // mélységi teszt bekapcsolása (takarás)
	glCullFace(GL_BACK); // GL_BACK: a kamerától "elfelé" néző lapok, GL_FRONT: a kamera felé néző lapok


	Vertex vert[] =
	{ 
		//Sides
		{glm::vec3(-1, 0, 0), glm::vec3(0, 0, 1)},
		{glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)},
		{glm::vec3(0, 0, -1), glm::vec3(1, 1, 1)},

		{glm::vec3(1, 0, 0), glm::vec3(0, 0, 1)},
		{glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)},
		{glm::vec3(0, 0, -1), glm::vec3(1, 1, 1)},

		{glm::vec3(1, 0, 0), glm::vec3(0, 0, 1)},
		{glm::vec3(0, 1, 0), glm::vec3(0, 1, 0)},
		{glm::vec3(-1, 0, 0), glm::vec3(1, 1, 1)},

		//Base
		{glm::vec3(1, 0, 0), glm::vec3(1, 0, 0)},
		{glm::vec3(0, 0, -1), glm::vec3(0, 1, 0)},
		{glm::vec3(-1,  0, 0), glm::vec3(0, 0, 1)},
	};

	// 1 db VAO foglalasa
	glGenVertexArrays(1, &m_vaoID);
	// a frissen generált VAO beallitasa aktívnak
	glBindVertexArray(m_vaoID);
	
	// hozzunk létre egy új VBO erőforrás nevet
	glGenBuffers(1, &m_vboID); 
	glBindBuffer(GL_ARRAY_BUFFER, m_vboID); // tegyük "aktívvá" a létrehozott VBO-t
	// töltsük fel adatokkal az aktív VBO-t
	glBufferData( GL_ARRAY_BUFFER,	// az aktív VBO-ba töltsünk adatokat
				  sizeof(vert),		// ennyi bájt nagyságban
				  vert,	// erről a rendszermemóriabeli címről olvasva
				  GL_STATIC_DRAW);	// úgy, hogy a VBO-nkba nem tervezünk ezután írni és minden kirajzoláskor felhasnzáljuk a benne lévő adatokat
	

	// VAO-ban jegyezzük fel, hogy a VBO-ban az első 3 float sizeof(Vertex)-enként lesz az első attribútum (pozíció)
	glEnableVertexAttribArray(0); // ez lesz majd a pozíció
	glVertexAttribPointer(
		0,				// a VB-ben található adatok közül a 0. "indexű" attribútumait állítjuk be
		3,				// komponens szam
		GL_FLOAT,		// adatok tipusa
		GL_FALSE,		// normalizalt legyen-e
		sizeof(Vertex),	// stride (0=egymas utan)
		0				// a 0. indexű attribútum hol kezdődik a sizeof(Vertex)-nyi területen belül
	); 

	// a második attribútumhoz pedig a VBO-ban sizeof(Vertex) ugrás után sizeof(glm::vec3)-nyit menve újabb 3 float adatot találunk (szín)
	glEnableVertexAttribArray(1); // ez lesz majd a szín
	glVertexAttribPointer(
		1,
		3, 
		GL_FLOAT,
		GL_FALSE,
		sizeof(Vertex),
		(void*)(sizeof(glm::vec3)) );

	glBindVertexArray(0); // feltöltüttük a VAO-t, kapcsoljuk le
	glBindBuffer(GL_ARRAY_BUFFER, 0); // feltöltöttük a VBO-t is, ezt is vegyük le

	//
	// shaderek betöltése
	//
	GLuint vs_ID = loadShader(GL_VERTEX_SHADER,		"myVert.vert");
	GLuint fs_ID = loadShader(GL_FRAGMENT_SHADER,	"myFrag.frag");

	// a shadereket tároló program létrehozása
	m_programID = glCreateProgram();

	// adjuk hozzá a programhoz a shadereket
	glAttachShader(m_programID, vs_ID);
	glAttachShader(m_programID, fs_ID);

	// VAO-beli attribútumok hozzárendelése a shader változókhoz
	// FONTOS: linkelés előtt kell ezt megtenni!
	glBindAttribLocation(	m_programID,	// shader azonosítója, amiből egy változóhoz szeretnénk hozzárendelést csinálni
							0,				// a VAO-beli azonosító index
							"vs_in_pos");	// a shader-beli változónév
	glBindAttribLocation( m_programID, 1, "vs_in_col");

	// illesszük össze a shadereket (kimenő-bemenő változók összerendelése stb.)
	glLinkProgram(m_programID);

	// linkeles ellenorzese
	GLint infoLogLength = 0, result = 0;

	glGetProgramiv(m_programID, GL_LINK_STATUS, &result);
	glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if (GL_FALSE == result || infoLogLength != 0)
	{
		std::vector<char> VertexShaderErrorMessage(infoLogLength);
		glGetProgramInfoLog(m_programID, infoLogLength, nullptr, VertexShaderErrorMessage.data());
		std::cerr << "[glLinkProgram] Shader linking error:\n" << &VertexShaderErrorMessage[0] << std::endl;
	}

	// mar nincs ezekre szukseg
	glDeleteShader( vs_ID );
	glDeleteShader( fs_ID );

	//
	// egyéb inicializálás
	//

	// shader-beli transzformációs mátrixok címének lekérdezése
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
	cameraPos += input * (delta * speed);

	m_matView = glm::lookAt(
			cameraPos,					// honnan nézzük a színteret	   - eye
			cameraPos + glm::vec3( 0,  0,  1),		// a színtér melyik pontját nézzük - at
			glm::vec3( 0,  1,  0));		// felfelé mutató irány a világban - up

	//input = glm::vec3(0);
}

const float twoPi = 3.14 * 2;

void CMyApp::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// shader bekapcsolasa, ebben a projektben a teljes programot jelöli, hisz nem váltunk a shaderek között
	glUseProgram( m_programID );

	/*
	GLM transzformációs mátrixokra példák:
		glm::rotate<float>( szög, glm::vec3(tengely_x, tengely_y, tengely_z) ) <- tengely_{xyz} körüli elforgatás
		glm::translate<float>( glm::vec3(eltol_x, eltol_y, eltol_z) ) <- eltolás
		glm::scale<float>( glm::vec3(s_x, s_y, s_z) ) <- skálázás
	*/

	// kapcsoljuk be a VAO-t (a VBO jön vele együtt)
	glBindVertexArray(m_vaoID);

	glUniformMatrix4fv( m_loc_view,  1, GL_FALSE, &( m_matView[0][0]) );
	glUniformMatrix4fv( m_loc_proj,  1, GL_FALSE, &( m_matProj[0][0]) );

	float state = fmod(timer, amplitudoTime) / amplitudoTime;
	float y1 = sin((state + twoPi / 3) * twoPi) * amplitudo;
	float y2 = sin((state + twoPi / 3 * 2) * twoPi) * amplitudo;
	float y3 = sin((state + twoPi / 3 * 3) * twoPi) * amplitudo;

	//1.
	m_matWorld = glm::translate<float>(glm::vec3(-2, y1, 0));
	glUniformMatrix4fv(m_loc_world, 1, GL_FALSE, &(m_matWorld[0][0]));
	glDrawArrays(GL_TRIANGLES, 0, 3 * 4);

	//2.
	m_matWorld = glm::translate<float>(glm::vec3(0, y2, 0));
	glUniformMatrix4fv(m_loc_world, 1, GL_FALSE, &(m_matWorld[0][0]));
	glDrawArrays(GL_TRIANGLES, 0, 3 * 4);

	//3.
	m_matWorld = glm::translate<float>(glm::vec3(2, y3, 0));
	glUniformMatrix4fv(m_loc_world, 1, GL_FALSE, &(m_matWorld[0][0]));
	glDrawArrays(GL_TRIANGLES, 0, 3 * 4);

	// VAO kikapcsolasa
	glBindVertexArray(0);

	// shader kikapcsolasa
	glUseProgram( 0 );
}

void CMyApp::KeyboardDown(SDL_KeyboardEvent& key)
{
	if (key.keysym.sym == SDLK_w)
		input.z = 1;
	else if (key.keysym.sym == SDLK_s)
		input.z = -1;
	else if (key.keysym.sym == SDLK_a)
		input.x = 1;
	else if (key.keysym.sym == SDLK_d)
		input.x = -1;
	else if (key.keysym.sym == SDLK_q)
		input.y = 1;
	else if (key.keysym.sym == SDLK_e)
		input.y = -1;
}

void CMyApp::KeyboardUp(SDL_KeyboardEvent& key)
{
	if (key.keysym.sym == SDLK_w)
		input.z = 0;
	else if (key.keysym.sym == SDLK_s)
		input.z = 0;
	else if (key.keysym.sym == SDLK_a)
		input.x = 0;
	else if (key.keysym.sym == SDLK_d)
		input.x = 0;
	else if (key.keysym.sym == SDLK_q)
		input.y = 0;
	else if (key.keysym.sym == SDLK_e)
		input.y = 0;
}

void CMyApp::MouseMove(SDL_MouseMotionEvent& mouse)
{

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
	glViewport(0, 0, _w, _h);

	// vetítési mátrix beállítása
	m_matProj = glm::perspective(   glm::radians(60.0f),	// 60 fokos nyilásszog radiánban
									_w/(float)_h,			// ablakméreteknek megfelelő nézeti arány
									0.01f,					// közeli vágósík
									100.0f);				// távoli vágósík
}