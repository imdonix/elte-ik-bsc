#include <GL\glew.h>
#include <GL\GL.h>
#include "TextureObject.h"

#include <SDL.h>
#include <SDL_image.h>

template<TextureType type>
inline TextureObject<type>::TextureObject()
{
	glGenTextures(1, &m_id);
}

template<TextureType type>
inline TextureObject<type>::TextureObject(const std::string &s)
{
	glGenTextures(1, &m_id);
	AttachFromFile(s);
}

template<TextureType type>
inline TextureObject<type>::~TextureObject()
{
	Clean();
}

template<TextureType type>
inline TextureObject<type>::TextureObject(TextureObject && rhs)
{
	if (&rhs == this)
		return;

	m_id = rhs.m_id;
	rhs.m_id = 0;
}

template<TextureType type>
inline TextureObject<type> & TextureObject<type>::operator=(TextureObject && rhs)
{
	if (&rhs == this)
		return *this;

	m_id = rhs.m_id;
	rhs.m_id = 0;

	return *this;
}

template<TextureType type>
inline TextureObject<type>& TextureObject<type>::operator=(const std::string & s)
{
	AttachFromFile(s);
	return *this;
}

inline int transform_image(int pitch, int height, void* image_pixels)
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

template<TextureType type>
inline void TextureObject<type>::AttachFromFile(const std::string& filename, bool generateMipMap, GLuint role)
{
	SDL_Surface* loaded_img = IMG_Load(filename.c_str());

	if (loaded_img == nullptr)
	{
		std::cerr << "[AttachFromFile] Error loading image file " << filename << std::endl;
		return;
	}

	// Formátum meghatározása és szükség esetén konvertálás
	Uint32 sdl_format = loaded_img->format->BytesPerPixel == 3 ? SDL_PIXELFORMAT_RGB24 : SDL_PIXELFORMAT_RGBA32;
	GLenum source_format = loaded_img->format->BytesPerPixel == 3 ? GL_RGB : GL_RGBA;
	if (loaded_img->format->format != sdl_format) {
		SDL_Surface* formattedSurf = SDL_ConvertSurfaceFormat(loaded_img, sdl_format, 0);
		SDL_FreeSurface(loaded_img);
		if (formattedSurf == nullptr)
		{
			std::cout << "[AttachFromFile] Error converting image format: " << SDL_GetError() << std::endl;
			return;
		}
		loaded_img = formattedSurf;
	}

	// Áttérés SDL koordinátarendszerrõl ( (0,0) balfent ) OpenGL textúra-koordinátarendszerre ( (0,0) ballent )
	if (type != TextureType::TextureCubeMap && type != TextureType::TextureCubeMapArray) {
		if (transform_image(loaded_img->pitch, loaded_img->h, loaded_img->pixels) == -1) {
			std::cout << "[AttachFromFile] Error transforming image: " << SDL_GetError() << std::endl;
			SDL_FreeSurface(loaded_img);
			return;
		}
	}


	glBindTexture(static_cast<GLenum>(type), m_id);
	glTexImage2D(
		role,							// melyik binding point-on van a textúra erõforrás, amihez tárolást rendelünk
		0,								// melyik részletességi szint adatait határozzuk meg
		GL_RGBA,						// textúra belsõ tárolási formátuma (GPU-n)
		loaded_img->w,					// szélesség
		loaded_img->h,					// magasság
		0,								// nulla kell, hogy legyen ( https://www.khronos.org/registry/OpenGL-Refpages/gl4/html/glTexImage2D.xhtml )
		source_format,					// forrás (=CPU-n) formátuma
		GL_UNSIGNED_BYTE,				// forrás egy pixelének egy csatornáját hogyan tároljuk
		loaded_img->pixels);			// forráshoz pointer

	if (generateMipMap)
		glGenerateMipmap(static_cast<GLenum>(type));

	glTexParameteri(static_cast<GLenum>(type), GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(static_cast<GLenum>(type), GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	SDL_FreeSurface(loaded_img);
}

template<TextureType type>
inline void TextureObject<type>::FromFile(const std::string& s)
{
	AttachFromFile(s);
}

template<TextureType type>
inline void TextureObject<type>::Clean()
{
	if (m_id != 0)
	{
		glDeleteTextures(1, &m_id);
		m_id = 0;
	}
}
