#include "TextComponent.h"
#include "Engine.h" 

namespace anthemum
{
	void TextComponent::Update()
	{
	}

	void TextComponent::Draw(Renderer& renderer)
	{
		g_renderer.Draw(m_texture, m_owner->m_transform, registration);
	}

	void TextComponent::SetText(const std::string& text)
	{
		m_texture->CreateFromSurface(m_font -> CreateSurface(text, color), g_renderer);
	}

	bool TextComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool TextComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, text);
		READ_DATA(value, font_name);
		READ_DATA(value, font_size);
		READ_DATA(value, color);

		m_font = g_resourceManager.Get<Font>(font_name, font_size); // !! Get<Font> from g_resources, passing in font_name and 
		m_texture = std::make_unique<Texture>();

		SetText(text);

		return true;
	}
}