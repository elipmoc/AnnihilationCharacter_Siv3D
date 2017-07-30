#pragma once
namespace game {
	class ParticleFontObject {
		const siv::Font& m_font;
		//表示する文字列
		const siv::String m_text;
		//color
		siv::Color m_color;
		//位置
		siv::Vec2 m_pos;
		//生存時間
		int m_lifeTime;
		//速度ベクトル
		siv::Vec2 m_speedv;
		//加速度ベクトル
		const siv::Vec2 m_vspeedv;
		//透過度
		double m_opacity;
		//加速透過度
		const double m_vopacity;
		//重力加速度
		const siv::Vec2 m_g;
	public:
		ParticleFontObject(
			const siv::String& text,const siv::Color& color,
			const siv::Font& font, const siv::Vec2& pos,const int lifeTime,
			const siv::Vec2& speedv,const siv::Vec2& vspeedv,
			const double vopacity,const siv::Vec2& g) noexcept
			: m_text(text), m_color(color), m_font(font), m_pos(pos), m_lifeTime(lifeTime), m_speedv(speedv), m_vspeedv(vspeedv), m_vopacity(vopacity),m_g(g)
		{
			m_opacity = color.a;
		}

		bool IsCanDelete() const noexcept{
			return m_lifeTime <= 0;
		}

		void Update()noexcept{
			m_pos +=m_speedv;
			m_speedv += m_vspeedv+m_g;
			m_opacity += m_vopacity;
			if (m_opacity < 0)m_opacity = 0;
			m_color.a = m_opacity;
			m_lifeTime--;
		}

		void Draw()const {
			m_font(m_text).drawCenter(m_pos, m_color);
		}
	};

}