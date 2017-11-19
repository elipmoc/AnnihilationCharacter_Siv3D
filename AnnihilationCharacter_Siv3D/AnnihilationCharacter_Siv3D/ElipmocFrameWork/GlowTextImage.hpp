#pragma once
namespace elipmocframework {

	class GlowTextImage {
		const siv::Texture m_texture;
		const siv::Vec2 m_offset;
		siv::Color m_color=siv::Palette::White;
	public:


		GlowTextImage(const siv::Font& font, const siv::String& text, int32 blur, double gamma = 2.0)
		:m_offset(blur+4,blur+4),m_texture(CreateGlowTextImage(font,text,blur,gamma)){

			

		}

		void SetColor(siv::Color color){
			m_color = color;
		}

		void Draw(const siv::Vec2& pos)
			const 
		{
			m_texture.draw(pos - m_offset, m_color);

		}

		void DrawCenter(const siv::Vec2& pos)
			const 
		{
			m_texture.draw(pos - m_texture.size / 2, m_color);

		}

		//フォントを光らせるためのテクスチャを生成
		static siv::Texture CreateGlowTextImage(const siv::Font& font, const siv::String& text, int32 blur, double gamma = 2.0) {
			const siv::Size region = font(text).region().stretched(blur + 4).size;

			siv::Image image(region, siv::Color(0, 0));

			font(text).write(image, { blur + 4,blur + 4 }, siv::Palette::White);

			image.gaussianBlur(blur, blur).gammaCorrect(gamma);

			for (auto& pixel : image)
			{
				pixel.a = pixel.r;

				pixel.r = pixel.g = pixel.b = 255;
			}

			return siv::Texture(image);
		}
	};

}