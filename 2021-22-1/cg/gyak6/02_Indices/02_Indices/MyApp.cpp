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
	// Nézeti szög (elfordulás az Y tengely körül)
	// Ebből számoljuk ki, hogy éppen merre néz a kamera.
	// Ezt az értéket növeli/csökkenti a fordulás során a billentyűk lenyomása.
	angle = 0.0f;

	// A kamera pozíciója
	cameraPos = glm::vec3(0.0f, 0.0f, 5.0f);
	// A kamera nézeti iránya.
	cameraDir = glm::vec3(0.0f, 0.0f, -1.0f);

	// A kocka pozíciója
	cubePos = glm::vec3(rand() % 20, 0.0f, rand() % 20);

	point = 0;

	// törlési szín legyen kékes
	glClearColor(0.125f, 0.25f, 0.5f, 1.0f);

	glEnable(GL_CULL_FACE); // kapcsoljuk be a hatrafele nezo lapok eldobasat
	glEnable(GL_DEPTH_TEST); // mélységi teszt bekapcsolása (takarás)
	glCullFace(GL_BACK); // GL_BACK: a kamerától "elfelé" néző lapok, GL_FRONT: a kamera felé néző lapok

	//
	// geometria letrehozasa
	//

	Vertex vert[] =
	{ 
		{glm::vec3(-0.5f, -0.5f, +0.5f), glm::vec3(1, 0, 0)},
		{glm::vec3(+0.5f, -0.5f, +0.5f), glm::vec3(1, 0, 0)},
		{glm::vec3(+0.5f, -0.5f, -0.5f), glm::vec3(1, 0, 0)},
		{glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1, 0, 0)},

		{glm::vec3(-0.5f, +0.5f, +0.5f), glm::vec3(1, 0, 0)},
		{glm::vec3(+0.5f, +0.5f, +0.5f), glm::vec3(1, 0, 0)},
		{glm::vec3(+0.5f, +0.5f, -0.5f), glm::vec3(1, 0, 0)},
		{glm::vec3(-0.5f, +0.5f, -0.5f), glm::vec3(1, 0, 0)},
	};

	// indexpuffer adatai
    GLushort indices[]=
    {
		0,1,4,
		4,1,5,

		5,1,2,
		5,2,6,

		7,2,3,
		7,6,2,

		4,7,3,
		4,3,0,

		7,4,6,
		4,5,6,

		0,2,1,
		3,2,0

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

	// index puffer létrehozása
	glGenBuffers(1, &m_ibID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(0); // feltöltüttük a VAO-t, kapcsoljuk le
	glBindBuffer(GL_ARRAY_BUFFER, 0); // feltöltöttük a VBO-t is, ezt is vegyük le
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); // feltöltöttük a VBO-t is, ezt is vegyük le

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
	m_loc_mvp = glGetUniformLocation( m_programID, "MVP");
	m_loc_color = glGetUniformLocation(m_programID, "color");

	return true;
}

void CMyApp::Clean()
{
	glDeleteBuffers(1, &m_vboID);
	glDeleteBuffers(1, &m_ibID);
	glDeleteVertexArrays(1, &m_vaoID);

	glDeleteProgram( m_programID );
}

void CMyApp::Update()
{
	// Jelenlegi idő (programindítás óta eltelt idő ms-ben)
	int currentTime = SDL_GetTicks();

	// Előző update óta eltelt idő ms-ben
	float deltaTime = currentTime - lastTime;

	// Frissítjük a legutolsó megjegyzett "időbélyeget"
	lastTime = currentTime;

	// Elmozgatjuk a kamerát az inputnak megfelelő irányba.
	// Mivel azt akarjuk hogy 2 egységet mozogjon 1 mp alatt, ezért
	// Az eltelt időt (ms-ben) megszorozzuk az egy ms alatti sebességgel (2 / 1000).
	// Tehát az irányt a moveDir adja, a hosszát pedig a deltaTime és mozgási sebesség alapján számoljuk ki.
	cameraPos += moveDir * 15.0f / 1000.0f * deltaTime;

	// Lenullázzuk az input szerinti irányt, hogy mindig újraszámolódjon a jelenleg lenyomott billentyűk alapján.
	moveDir = glm::vec3(0.0f, 0.0f, 0.0f);

	// Kiszámoljuk a kamera nézeti irányát az elfordulás alapján.
	cameraDir = glm::vec3(cos(angle), 0.0f, sin(angle));

	// nézeti transzformáció beállítása
	// Nézett pont: jelenlegi pozíció + jelenlegi nézeti irány
	// A kamera előtt "lebegő" pont, amit nézünk.
	m_matView = glm::lookAt(cameraPos,					// honnan nézzük a színteret
							cameraPos + cameraDir,		// a színtér melyik pontját nézzük
							glm::vec3( 0,  1,  0));		// felfelé mutató irány a világban

	// Ha közelebb vagyunk a kockához mint 3 egység, akkor rakjuk új helyre.
	if (glm::distance(cameraPos, cubePos) < 3.0f) {
		point++;
		std::cout << point << std::endl;
		cubePos = glm::vec3(rand() % 20, 0.0f, rand() % 20);
	}
}


void CMyApp::Render()
{
	// töröljük a frampuffert (GL_COLOR_BUFFER_BIT) és a mélységi Z puffert (GL_DEPTH_BUFFER_BIT)
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// shader bekapcsolasa, ebben a projektben a teljes programot jelöli, hisz nem váltunk a shaderek között
	glUseProgram( m_programID );

	// shader parameterek beállítása
	/*

	GLM transzformációs mátrixokra példák:
		glm::rotate<float>( szög, glm::vec3(tengely_x, tengely_y, tengely_z) ) <- tengely_{xyz} körüli elforgatás
		glm::translate<float>( glm::vec3(eltol_x, eltol_y, eltol_z) ) <- eltolás
		glm::scale<float>( glm::vec3(s_x, s_y, s_z) ) <- léptékezés

	*/

	// A kockát eltoljuk a megfelelő helyre.
	m_matWorld = glm::translate(cubePos);

	// CPU-n kiszámoljuk a végleges transzformációs mátrixot, egyben adjuk át a shadernek.
	// MVP = Projekciós * Nézeti * Modell (világ) mátrix
	glm::mat4 mvp = m_matProj * m_matView * m_matWorld;

	// majd küldjük át a megfelelő mátrixot!
	// Uniform változó bindolása csak a program bindolása után lehetséges! (glUseProgram() )
	glUniformMatrix4fv( m_loc_mvp,// erre a helyre töltsünk át adatot
						1,			// egy darab mátrixot
						GL_FALSE,	// NEM transzponálva
						&(mvp[0][0]) ); // innen olvasva a 16 x sizeof(float)-nyi adatot

	// kapcsoljuk be a VAO-t (a VBO jön vele együtt)
	glBindVertexArray(m_vaoID);

	// kirajzolás
	//A draw hívásokhoz a VAO és a program bindolva kell legyenek (glUseProgram() és glBindVertexArray())
	glUniform3f(m_loc_color, 1, 0, 0);

	glDrawElements(	GL_TRIANGLES,		// primitív típus
					6 * 2 * 3,			// hany indexet hasznalunk a kirajzolashoz
					GL_UNSIGNED_SHORT,	// indexek tipusa
					0);					// legelső index sorszáma: a legelső indextől akarjuk a 36 indexet


	glm::vec3 pointsDir = glm::cross(glm::vec3(0, 1, 0), cameraDir);
	for (int i = 0; i < point; i++)
	{
		m_matWorld = glm::translate(cameraDir + cameraDir * 50.F + (pointsDir * (float)i)) * glm::scale(glm::vec3(0.5F, 3, 0.5F));
		mvp = m_matProj * m_matView * m_matWorld;

		// majd küldjük át a megfelelő mátrixot!
		// Uniform változó bindolása csak a program bindolása után lehetséges! (glUseProgram() )
		glUniformMatrix4fv(m_loc_mvp,// erre a helyre töltsünk át adatot
			1,			// egy darab mátrixot
			GL_FALSE,	// NEM transzponálva
			&(mvp[0][0])); // innen olvasva a 16 x sizeof(float)-nyi adatot

		glUniform3f(m_loc_color, 0, 1, 0);

		glBindVertexArray(m_vaoID);

		// kirajzolás
		//A draw hívásokhoz a VAO és a program bindolva kell legyenek (glUseProgram() és glBindVertexArray())

		glDrawElements(GL_TRIANGLES,		// primitív típus
			6 * 2 * 3,			// hany indexet hasznalunk a kirajzolashoz
			GL_UNSIGNED_SHORT,	// indexek tipusa
			0);
	}


	// VAO kikapcsolasa
	glBindVertexArray(0);

	// shader kikapcsolasa
	glUseProgram( 0 );
}

void CMyApp::KeyboardDown(SDL_KeyboardEvent& key)
{
	if (key.keysym.sym == SDLK_w) {
		// Előre szeretnénk menni (amerre nézünk)
		moveDir += cameraDir;
	}
	else if (key.keysym.sym == SDLK_s) {
		// Hátra szeretnénk menni
		moveDir -= cameraDir;
	}
	else if (key.keysym.sym == SDLK_a) {
		// Csökkentjük az elfordulás szögét
		// Ha nagyon akarjuk, ezt is framerate-függetlenné lehet tenni a mozgáshoz hasonlóan, egyelőre ez nem olyan fontos.
		angle -= 0.1f;
	}
	else if (key.keysym.sym == SDLK_d) {
		// Növeljük az elfordulás szögét
		angle += 0.1f;
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

// a két paraméterbe az új ablakméret szélessége (_w) és magassága (_h) található
void CMyApp::Resize(int _w, int _h)
{
	glViewport(0, 0, _w, _h);
	
	// vetítési mátrix beállítása
	m_matProj = glm::perspective(glm::radians(60.0f),	// 60 fokos nyilásszog radiánban
		_w / (float)_h,			// ablakméreteknek megfelelő nézeti arány
		0.01f,					// közeli vágósík
		1000.0f);				// távoli vágósík
}