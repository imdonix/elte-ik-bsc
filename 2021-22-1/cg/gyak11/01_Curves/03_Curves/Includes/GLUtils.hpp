#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include <GL/glew.h>

#include <SDL_image.h>

/* 

Az http://www.opengl-tutorial.org/ oldal alapján.

*/
GLuint loadShader(GLenum _shaderType, const char* _fileName)
{
	// shader azonosito letrehozasa
	GLuint loadedShader = glCreateShader( _shaderType );

	// ha nem sikerult hibauzenet es -1 visszaadasa
	if ( loadedShader == 0 )
	{
		fprintf(stderr, "Error while initing shader %s (glCreateShader)!", _fileName);
		return 0;
	}
	
	// shaderkod betoltese _fileName fajlbol
	std::string shaderCode = "";

	// _fileName megnyitasa
	std::ifstream shaderStream(_fileName);

	if ( !shaderStream.is_open() )
	{
		fprintf(stderr, "Error while loading shader %s!", _fileName);
		return 0;
	}

	// file tartalmanak betoltese a shaderCode string-be
	std::string line = "";
	while ( std::getline(shaderStream, line) )
	{
		shaderCode += line + "\n";
	}

	shaderStream.close();

	// fajlbol betoltott kod hozzarendelese a shader-hez
	const char* sourcePointer = shaderCode.c_str();
	glShaderSource( loadedShader, 1, &sourcePointer, NULL );

	// shader leforditasa
	glCompileShader( loadedShader );

	// ellenorizzuk, h minden rendben van-e
	GLint result = GL_FALSE;
    int infoLogLength;

	// forditas statuszanak lekerdezese
	glGetShaderiv(loadedShader, GL_COMPILE_STATUS, &result);
	glGetShaderiv(loadedShader, GL_INFO_LOG_LENGTH, &infoLogLength);

	if ( GL_FALSE == result )
	{
		// hibauzenet elkerese es kiirasa
		std::vector<char> VertexShaderErrorMessage(infoLogLength);
		glGetShaderInfoLog(loadedShader, infoLogLength, NULL, &VertexShaderErrorMessage[0]);

		fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);
	}

	return loadedShader;
}

GLuint loadProgramVSGSFS(const char* _fileNameVS, const char* _fileNameGS, const char* _fileNameFS)
{
	// a vertex, geometry es fragment shaderek betoltese
	GLuint vs_ID = loadShader(GL_VERTEX_SHADER,		_fileNameVS);
	GLuint gs_ID = loadShader(GL_GEOMETRY_SHADER,	_fileNameGS);
	GLuint fs_ID = loadShader(GL_FRAGMENT_SHADER,	_fileNameFS);

	// ha barmelyikkel gond volt programot sem tudunk csinalni, 0 vissza
	if ( vs_ID == 0 || gs_ID == 0 || fs_ID == 0 )
	{
		return 0;
	}

	// linkeljuk ossze a dolgokat
	GLuint program_ID = glCreateProgram();

	fprintf(stdout, "Linking program\n");
	glAttachShader(program_ID, vs_ID);
	glAttachShader(program_ID, gs_ID);
	glAttachShader(program_ID, fs_ID);

	glLinkProgram(program_ID);

	// linkeles ellenorzese
	GLint infoLogLength = 0, result = 0;

	glGetProgramiv(program_ID, GL_LINK_STATUS, &result);
	glGetProgramiv(program_ID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if ( GL_FALSE == result)
	{
		std::vector<char> ProgramErrorMessage( infoLogLength );
		glGetProgramInfoLog(program_ID, infoLogLength, NULL, &ProgramErrorMessage[0]);
		fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
	}

	// mar nincs ezekre szukseg
	glDeleteShader( vs_ID );
	glDeleteShader( gs_ID );
	glDeleteShader( fs_ID );

	// adjuk vissza a program azonositojat
	return program_ID;
}

int invert_image(int pitch, int height, void* image_pixels)
{
	int index;
	void* temp_row;
	int height_div_2;

	temp_row = (void *)malloc(pitch);
	if (NULL == temp_row)
	{
		SDL_SetError("Not enough memory for image inversion");
		return -1;
	}
	//if height is odd, don't need to swap middle row
	height_div_2 = (int)(height * .5);
	for (index = 0; index < height_div_2; index++) {
		//uses string.h
		memcpy((Uint8 *)temp_row,
			(Uint8 *)(image_pixels)+
			pitch * index,
			pitch);

		memcpy(
			(Uint8 *)(image_pixels)+
			pitch * index,
			(Uint8 *)(image_pixels)+
			pitch * (height - index - 1),
			pitch);
		memcpy(
			(Uint8 *)(image_pixels)+
			pitch * (height - index - 1),
			temp_row,
			pitch);
	}
	free(temp_row);
	return 0;
}

// 
int SDL_InvertSurface(SDL_Surface* image)
{
	if (NULL == image)
	{
		SDL_SetError("Surface is NULL");
		return -1;
	}

	return invert_image(image->pitch, image->h, image->pixels);
}

GLuint TextureFromFile(const char* filename)
{

	// Kép betöltése
	SDL_Surface* loaded_img = IMG_Load(filename);
	if (loaded_img == nullptr)
	{
		std::cout << "[TextureFromFile] Error while loading texture: " << filename << std::endl;
		return 0;
	}

	// Uint32-ben tárolja az SDL a színeket, ezért számít a bájtsorrend
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
	Uint32 format = SDL_PIXELFORMAT_ABGR8888;
#else
	Uint32 format = SDL_PIXELFORMAT_RGBA8888;
#endif

	// Átalakítás 32bit RGBA formátumra, ha nem abban volt
	SDL_Surface* formattedSurf = SDL_ConvertSurfaceFormat(loaded_img, format, 0);
	if (formattedSurf == nullptr)
	{
		std::cout << "[TextureFromFile] Error while processing texture: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(loaded_img);
		return 0;
	}

	// Áttérés SDL koordinátarendszerrõl ( (0,0) balfent ) OpenGL textúra-koordinátarendszerre ( (0,0) ballent )
	if (SDL_InvertSurface(formattedSurf) == -1) {
		std::cout << "[TextureFromFile] Error while processing texture: " << SDL_GetError() << std::endl;
		SDL_FreeSurface(formattedSurf);
		SDL_FreeSurface(loaded_img);
		return 0;
	}

	// OpenGL textúra generálás
	GLuint tex;
	glGenTextures(1, &tex);

	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, formattedSurf->w, formattedSurf->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, formattedSurf->pixels);

	// Mipmap generálása
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	// Használt SDL_Surface-k felszabadítása
	SDL_FreeSurface(formattedSurf);
	SDL_FreeSurface(loaded_img);

	return tex;
}

void TextureFromFileAttach(const char* filename, GLuint role)
{
	SDL_Surface* loaded_img = IMG_Load(filename);

	int img_mode = 0;

	if (loaded_img == 0)
	{
		std::cout << "[TextureFromFile] Error while loading texture: " << filename << std::endl;
		return;
	}

#if SDL_BYTEORDER == SDL_LIL_ENDIAN
	if (loaded_img->format->BytesPerPixel == 4)
		img_mode = GL_BGRA;
	else
		img_mode = GL_BGR;
#else
	if (loaded_img->format->BytesPerPixel == 4)
		img_mode = GL_RGBA;
	else
		img_mode = GL_RGB;
#endif

	glTexImage2D(role, 0, GL_RGBA, loaded_img->w, loaded_img->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, loaded_img->pixels);

	SDL_FreeSurface(loaded_img);
}

GLuint genSampler(GLint param_min = GL_LINEAR, GLint param_mag = GL_LINEAR_MIPMAP_LINEAR)
{
	GLuint samp;
	glGenSamplers(1, &samp);

	glSamplerParameteri(samp, GL_TEXTURE_MIN_FILTER, param_min);
	glSamplerParameteri(samp, GL_TEXTURE_MAG_FILTER, param_mag);

	return samp;
}
