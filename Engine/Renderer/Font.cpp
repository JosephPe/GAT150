#include "Font.h"
//#include "../Core/File.h"
#include <SDL_ttf.h>

namespace anthemum
{
	Font::Font(const std::string& filename, int fontSize)
	{
		//Load(anthemum::GetFilePath() + "\\jhand.tff", 96);
		Load(filename, fontSize);
	}

	Font::~Font()
	{
		if (m_ttfFont != NULL) 
		{
			TTF_CloseFont(m_ttfFont);
		}
	}

	void Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);//(filename.c_str(), fontSize);
	}
}