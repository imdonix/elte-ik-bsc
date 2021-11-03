#include "MyApp.h"
#include "GLUtils.hpp"

#include <math.h>
#include <array>

CMyApp::CMyApp()
{
}

CMyApp::~CMyApp()
{
}

GLuint CMyApp::GenerateRandomTexture()
{
	const int W = 128, H = 128;
	unsigned char tex[W][H][3];

	for (int i = 0; i < W; ++i)
		for (int j = 0; j < H; ++j)
		{
			tex[i][j][0] = rand() % 256;
			tex[i][j][1] = rand() % 256;
			tex[i][j][2] = rand() % 256;
		}

	GLuint tmpID;

	// generáljunk egy textúra erőforrás nevet
	glGenTextures(1, &tmpID);
	// aktiváljuk a most generált nevű textúrát
	glBindTexture(GL_TEXTURE_2D, tmpID);

	// töltsük fel adatokkal
	glTexImage2D(GL_TEXTURE_2D,	// melyik binding point-on van a textúra erőforrás, amihez tárolást rendelünk
		0,						// melyik részletességi szint adatait határozzuk meg
		GL_RGB,					// textúra belső tárolási formátuma (GPU-n)
		W, H,					// szélesség, magasság
		0,						// nulla kell, hogy legyen ( https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml )
		GL_RGB,					// forrás (=CPU-n) formátuma
		GL_UNSIGNED_BYTE,		// forrás egy pixelének egy csatornáját hogyan tároljuk
		tex);					// forráshoz pointer

	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, 0);

	return tmpID;
}

void CMyApp::InitFloor()
{
	//struct Vertex{ glm::vec3 position; glm::vec2 texture; };

	Vertex vert[] =
	{
		{glm::vec3(-1, 0,  1), glm::vec2(0,0)},
		{glm::vec3( 1, 0,  1), glm::vec2(1,0)},
		{glm::vec3( 1, 0, -1), glm::vec2(1,1)},
		{glm::vec3(-1, 0, -1), glm::vec2(0,1)}
	};

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	// 1 db VAO foglalasa
	glGenVertexArrays(1, &m_floor_vaoID);
	// a frissen generált VAO beallitasa aktívnak
	glBindVertexArray(m_floor_vaoID);
	// hozzunk létre egy új VBO erőforrás nevet
	glGenBuffers(1, &m_floor_vboID);
	glBindBuffer(GL_ARRAY_BUFFER, m_floor_vboID); // tegyük "aktívvá" a létrehozott VBO-t

	// töltsük fel adatokkal az aktív VBO-t
	glBufferData(GL_ARRAY_BUFFER,	// az aktív VBO-ba töltsünk adatokat
		sizeof(vert),		// ennyi bájt nagyságban
		vert,	// erről a rendszermemóriabeli címről olvasva
		GL_STATIC_DRAW);	// úgy, hogy a VBO-nkba nem tervezünk ezután írni és minden kirajzoláskor felhasnzáljuk a benne lévő adatokat
		

	// VAO-ban jegyezzük fel, hogy a VBO-ban az első 3 float sizeof(Vertex)-enként lesz az első attribútum (pozíció)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,				// a VB-ben található adatok közül a 0. "indexű" attribútumait állítjuk be
		3,				// komponens szam
		GL_FLOAT,		// adatok tipusa
		GL_FALSE,		// normalizalt legyen-e
		sizeof(Vertex),	// stride (0=egymas utan)
		0				// a 0. indexű attribútum hol kezdődik a sizeof(Vertex)-nyi területen belül
	);

	// a második attribútumhoz pedig a VBO-ban sizeof(Vertex) ugrás után sizeof(glm::vec3)-nyit menve 2 float adatot találunk (textúrakoordináták)
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3)));

	// index puffer létrehozása
	glGenBuffers(1, &m_floor_ibID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_floor_ibID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0); // feltöltüttük a VAO-t, kapcsoljuk le
	glBindBuffer(GL_ARRAY_BUFFER, 0); // feltöltöttük a VBO-t is, ezt is vegyük le
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // feltöltöttük az index buffert is, ezt is vegyük le

}

void CMyApp::InitCube()
{
	//struct Vertex{ glm::vec3 position; glm::vec3 normals; glm::vec2 texture; };
	std::vector<Vertex>vertices;

	//front									 
	vertices.push_back({ glm::vec3(-0.5, -0.5, +0.5), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, +0.5), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, +0.5), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, +0.5), glm::vec2(1, 1) });
	//back
	vertices.push_back({ glm::vec3(+0.5, -0.5, -0.5), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(-0.5, -0.5, -0.5), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, -0.5), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, -0.5), glm::vec2(1, 1) });
	//right									 
	vertices.push_back({ glm::vec3(+0.5, -0.5, +0.5), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, -0.5), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, +0.5), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, -0.5), glm::vec2(1, 1) });
	//left									 
	vertices.push_back({ glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(-0.5, -0.5, +0.5), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, -0.5), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, +0.5), glm::vec2(1, 1) });
	//top									 
	vertices.push_back({ glm::vec3(-0.5, +0.5, +0.5), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, +0.5), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, +0.5, -0.5), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, +0.5, -0.5), glm::vec2(1, 1) });
	//bottom								 
	vertices.push_back({ glm::vec3(-0.5, -0.5, -0.5), glm::vec2(0, 0) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, -0.5), glm::vec2(1, 0) });
	vertices.push_back({ glm::vec3(-0.5, -0.5, +0.5), glm::vec2(0, 1) });
	vertices.push_back({ glm::vec3(+0.5, -0.5, +0.5), glm::vec2(1, 1) });
	
	GLushort indices[36];
	int index = 0;
	//4 csúcspontonként 6 index eltárolása
	for (int i = 0; i < 6*4; i += 4)
	{
		indices[index + 0] = i + 0;
		indices[index + 1] = i + 1;
		indices[index + 2] = i + 2;
		indices[index + 3] = i + 1;
		indices[index + 4] = i + 3;
		indices[index + 5] = i + 2;
		index += 6;
	}

	glGenVertexArrays(1, &m_cube_vaoID);
	glBindVertexArray(m_cube_vaoID);

	glGenBuffers(1, &m_cube_vboID);
	glBindBuffer(GL_ARRAY_BUFFER, m_cube_vboID);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec3)));

	glGenBuffers(1, &m_cube_ibID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_cube_ibID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}

void CMyApp::InitShaders()
{
	//
	// shaderek betöltése
	//
	GLuint vs_ID = loadShader(GL_VERTEX_SHADER, "myVert.vert");
	GLuint fs_ID = loadShader(GL_FRAGMENT_SHADER, "myFrag.frag");

	// a shadereket tároló program létrehozása
	m_programID = glCreateProgram();

	// adjuk hozzá a programhoz a shadereket
	glAttachShader(m_programID, vs_ID);
	glAttachShader(m_programID, fs_ID);

	// VAO-beli attribútumok hozzárendelése a shader változókhoz
	// FONTOS: linkelés előtt kell ezt megtenni!
	glBindAttribLocation(m_programID,	// shaderprogram azonosítója, amiből egy változóhoz szeretnénk hozzárendelést csinálni
		0,				// a VAO-beli azonosító index
		"vs_in_pos");	// a shader-beli változónév
	glBindAttribLocation(m_programID, 1, "vs_in_tex0");

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
	glDeleteShader(vs_ID);
	glDeleteShader(fs_ID);
}

void CMyApp::InitTextures()
{
	// fájlból betöltés
	m_loadedTextureID = TextureFromFile("wood.jpg");
	// mintavételezés beállításai
	glBindTexture(GL_TEXTURE_2D, m_loadedTextureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // bilineáris szürés nagyításkor (ez az alapértelmezett)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // trilineáris szűrés a mipmap-ekböl kicsinyítéskor
	// mi legyen az eredmény, ha a textúrán kívülröl próbálunk mintát venni?
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // vízszintesen
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // függölegesen

	// másik textúra, kézzel feltöltve
	m_generatedTextureID = TextureFromFile("cat.jpg");
	// erre a textúrára a GenerateRandomTexture már beállította a mintavételezést, így nekünk nem kell (de átállíthatjuk, ha szükséges)

	glBindTexture(GL_TEXTURE_2D, m_generatedTextureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // bilineáris szürés nagyításkor (ez az alapértelmezett)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // trilineáris szűrés a mipmap-ekböl kicsinyítéskor
	// mi legyen az eredmény, ha a textúrán kívülröl próbálunk mintát venni?
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // vízszintesen
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // függölegesen
}

bool CMyApp::Init()
{
	// törlési szín legyen kékes
	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_CULL_FACE); // kapcsoljuk be a hatrafele nezo lapok eldobasat
	glEnable(GL_DEPTH_TEST); // mélységi teszt bekapcsolása (takarás)
	glCullFace(GL_BACK); // GL_BACK: a kamerától "elfelé" néző lapok, GL_FRONT: a kamera felé néző lapok

	InitFloor();
	InitCube();
	InitShaders();
	InitTextures();

	// vetítési mátrix létrehozása
	m_matProj = glm::perspective( 45.0f, 640/480.0f, 1.0f, 1000.0f );

	// shader-beli transzformációs mátrixok címének lekérdezése
	m_loc_mvp = glGetUniformLocation( m_programID, "MVP");
	m_loc_w = glGetUniformLocation( m_programID, "world" );
	m_loc_tex = glGetUniformLocation(m_programID, "texImage");
	m_loc_tex2 = glGetUniformLocation(m_programID, "texImage2");

	return true;
}

void CMyApp::Clean()
{
	glDeleteTextures(1, &m_loadedTextureID);
	glDeleteTextures(1, &m_generatedTextureID);

	glDeleteBuffers(1, &m_floor_vboID);
	glDeleteBuffers(1, &m_cube_vboID);
	glDeleteBuffers(1, &m_floor_ibID);
	glDeleteBuffers(1, &m_cube_ibID);
	glDeleteVertexArrays(1, &m_floor_vaoID);
	glDeleteVertexArrays(1, &m_cube_vaoID);

	glDeleteProgram( m_programID );
}

void CMyApp::Update()
{
	// nézeti transzformáció beállítása
	m_matView = glm::lookAt(glm::vec3( 0,  6, 10),		// honnan nézzük a színteret
							glm::vec3( 0,  0,  0),		// a színtér melyik pontját nézzük
							glm::vec3( 0,  1,  0));		// felfelé mutató irány a világban
}

void CMyApp::Render()
{
	// töröljük a frampuffert (GL_COLOR_BUFFER_BIT) és a mélységi Z puffert (GL_DEPTH_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// shader bekapcsolasa, ebben a projektben a teljes programot jelöli, hisz nem váltunk a shaderek között
	glUseProgram(m_programID);

	//
	// - A talaj kirajzolása
	//
	// kapcsoljuk be a VAO-t (a VBO jön vele együtt)
	glBindVertexArray(m_floor_vaoID);

	// a talaj átméretezése és eltolása
	m_matWorld = glm::translate(glm::vec3(0, -0.5, 0))*glm::scale(glm::vec3(10, 1, 10));
	glm::mat4 mvp = m_matProj * m_matView * m_matWorld;
	glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
	glUniformMatrix4fv(m_loc_w, 1, GL_FALSE, &(m_matWorld[0][0]));

	// textúra beállítása
	// aktiváljuk a 0-ás textúramintavételezőt (innenőt a gl*Texture* hívások erre vonatkoznak)
	// ez akkor fontos, ha több textúrát akarunk egyszerre használni, ha egyszerre csak egy kell,
	// akkor ezt elhagyva automatikusan a 0-ás mintavételező aktív
	glActiveTexture(GL_TEXTURE0);
	// bindoljuk a zaj textúrát (az aktív 0-ás mintavételezőhöz)
	glBindTexture(GL_TEXTURE_2D, m_generatedTextureID);

	glUniform1i(m_loc_tex, 0);

	glActiveTexture(GL_TEXTURE1);
	// bindoljuk a zaj textúrát (az aktív 0-ás mintavételezőhöz)
	glBindTexture(GL_TEXTURE_2D,m_loadedTextureID);

	// beállítjuk, hogy a fragment shaderben a "texImage" nevű mintavételező a 0-ás számú legyen
	glUniform1i(m_loc_tex2, 1);

	// kirajzolás
	//A draw hívásokhoz a VAO és a program bindolva kell legyenek (glUseProgram() és glBindVertexArray())

	//GL_TRIANGLES 3 csúcsponttal dolgozik, egy háromszöget jelenít meg belőlük
	glDrawElements(GL_TRIANGLES,	// a draw hívása típusa, van még GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, stb...
		6,							// hány darab csúcspontot akarunk kirajzolni
		GL_UNSIGNED_SHORT,			// az indexek típusa
		0							// eltolás
	);			


	//
	// - A kockák kirajzolása
	//
	// Váltsunk át a kocka VAO-jára
	glBindVertexArray(m_cube_vaoID);
	// és textúrájára (továbbra is a 0-ás mintavételező aktív, és ez van beállítva a shaderben is)
	glBindTexture(GL_TEXTURE_2D, m_loadedTextureID);

	// a középső kocka kirajzolása
	m_matWorld = glm::translate(glm::vec3(0, 0, 0));
	mvp = m_matProj * m_matView * m_matWorld;
	glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
	glUniformMatrix4fv(m_loc_w, 1, GL_FALSE, &(m_matWorld[0][0]));
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);

	//keringő kockák
	float time = SDL_GetTicks() / 1000.0f; // eltelt másodpercek
	int r = 4, n = 10; // keringés sugara + kockák száma
	for (int i = 0; i < n; ++i)
	{
		float distance = time + M_PI*2.f/n*i;
		m_matWorld = glm::translate(glm::vec3(cos(distance)*r, sin(distance)*r,0));
		mvp = m_matProj * m_matView * m_matWorld;
		glUniformMatrix4fv(m_loc_mvp, 1, GL_FALSE, &(mvp[0][0]));
		glUniformMatrix4fv(m_loc_w, 1, GL_FALSE, &(m_matWorld[0][0]));
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0);
	}

	// VAO kikapcsolasa
	glBindVertexArray(0);

	// textúra kikapcsolása
	glBindTexture(GL_TEXTURE_2D, 0);

	// shader kikapcsolasa
	glUseProgram( 0 );
}

void CMyApp::KeyboardDown(SDL_KeyboardEvent& key)
{
	switch (key.keysym.sym)
	{
		case(SDLK_w): std::cout << "---\n|W|\n"; break;
		case(SDLK_s): std::cout << "---\n|S|\n"; break;
		case(SDLK_d): std::cout << "---\n|D|\n"; break;
		case(SDLK_a): std::cout << "---\n|A|\n"; break;
		default: break;
	}
}

void CMyApp::KeyboardUp(SDL_KeyboardEvent& key)
{
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

// a két paraméterben az új ablakméret szélessége (_w) és magassága (_h) található
void CMyApp::Resize(int _w, int _h)
{
	glViewport(0, 0, _w, _h);

	m_matProj = glm::perspective(  45.0f,		// 90 fokos nyilasszog
									_w/(float)_h,	// ablakmereteknek megfelelo nezeti arany
									0.01f,			// kozeli vagosik
									100.0f);		// tavoli vagosik
}
