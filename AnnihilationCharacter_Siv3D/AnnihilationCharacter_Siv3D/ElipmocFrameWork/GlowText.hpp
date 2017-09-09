#pragma once
namespace elipmocframework {
	class GlowText
	{
	private:

		siv::Font m_font;

		siv::String m_text;

		siv::Texture m_texture;

		siv::Point m_offset = { 0,0 };

	public:

		GlowText() = default;

		GlowText(const siv::Font& font, const siv::String& text, int32 blur, double gamma = 2.0)
			: m_font(font)
			, m_text(text)
			, m_offset(blur + 4, blur + 4)
		{
			const siv::Size region = font(text).region().stretched(blur + 4).size;

			siv::Image image(region, siv::Color(0, 0));

			font(text).write(image, m_offset, siv::Palette::White);

			image.gaussianBlur(blur, blur).gammaCorrect(gamma);

			for (auto& pixel : image)
			{
				pixel.a = pixel.r;

				pixel.r = pixel.g = pixel.b = 255;
			}

			m_texture = siv::Texture(image);
		}

		const siv::Texture& getGlowTexture() const
		{
			return m_texture;
		}

		siv::RectF draw(const siv::Vec2& pos, const siv::Color& glow = siv::Palette::White, const siv::Color& text = siv::Palette::White) const
		{
			m_texture.draw(pos, glow);

			return m_font(m_text).draw(pos + m_offset, text);
		}

		siv::RectF drawCenter(double y, const siv::Color& glow = siv::Palette::White, const siv::Color& text = siv::Palette::White) const
		{
			return drawCenter(siv::Vec2(siv::Window::Width() / 2, y), glow, text);
		}

		siv::RectF drawCenter(const siv::Vec2& pos, const siv::Color& glow = siv::Palette::White, const siv::Color& text = siv::Palette::White) const
		{
			return draw(pos - m_texture.size / 2, glow, text);
		}

		siv::RectF region(const siv::Vec2& pos = siv::Vec2(0, 0)) const
		{
			return siv::RectF(pos, m_texture.size).stretched(-m_offset);
		}

		siv::RectF regionCenter(double y) const
		{
			return regionCenter(siv::Vec2(siv::Window::Width() / 2, y));
		}

		siv::RectF regionCenter(const siv::Vec2& pos) const
		{
			return region(pos - m_texture.size / 2);
		}
	};
}