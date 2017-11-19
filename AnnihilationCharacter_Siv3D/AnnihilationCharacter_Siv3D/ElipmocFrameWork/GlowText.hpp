#pragma once
#include "FontObjectBase.hpp"
#include "Action.hpp"
#include "ActionList.hpp"

namespace elipmocframework {

	class GlowText:public FontObjectBase
	{
	private:

		double m_scale = 1;

		siv::Vec2 m_pos;
		//文字色
		siv::Color m_color = siv::Palette::White;
		siv::Color m_glowColor = siv::Palette::White;

		siv::Font m_font;

		const siv::String m_text;

		siv::Texture m_texture;

		siv::Point m_offset = { 0,0 };

		//アクションリスト
		ActionList m_actionList;

	public:

		GlowText() = default;

		GlowText(const siv::Font& font, const siv::String& text, int32 blur, double gamma = 2.0)
			: m_font(font)
			, m_text(text)
			, m_offset(blur + 4, blur + 4)
			, m_actionList(this)
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

		virtual GlowText& AddAction(std::unique_ptr<ActionBase>&& action)
		override final{
			m_actionList.push_back(std::move(action));
			return *this;
		}

		//posの参照を得る
		virtual const siv::Vec2& GetRefPos() override final { return m_pos; }

		//posアクセサ
		virtual siv::Vec2 GetPos()const noexcept override final { return m_pos; }
		virtual GlowText& SetPos(const siv::Vec2& _pos) noexcept override final { m_pos = _pos; return *this; }

		//scaleアクセサ
		virtual double GetScale() const noexcept override final { return m_scale; };
		virtual GlowText& SetScale(double _scale)noexcept override final { m_scale = _scale; return *this; }

		//textアクセサ
		virtual siv::String GetText() const noexcept override final { return m_text; }
		virtual GlowText& SetText(const siv::String&) noexcept override final { return *this; }

		//Colorアクセサ
		virtual siv::Color GetColor()const noexcept override final { return m_color; }
		virtual GlowText& SetColor(const siv::Color& color) noexcept override final { m_color = color; return *this; }

		//GlowColorアクセサ
		siv::Color GetGlowColor()const noexcept  { return m_glowColor; }
		GlowText& SetGlowColor(const siv::Color& color) noexcept { m_glowColor = color; return *this; }

		const siv::Texture& getGlowTexture() const
		{
			return m_texture;
		}

		virtual void Update() override {
			m_actionList.Update();
		}

		virtual void Draw() 
			const override final
		{
			m_texture.draw(m_pos- m_offset, m_glowColor);

			m_font(m_text).draw(m_pos , m_color);
		}

		void DrawCenter() 
			const override final
		{
			m_texture.draw(m_pos - m_texture.size / 2-m_offset, m_glowColor);

			m_font(m_text).draw(m_pos - m_texture.size / 2 , m_color);
		}
	};
}