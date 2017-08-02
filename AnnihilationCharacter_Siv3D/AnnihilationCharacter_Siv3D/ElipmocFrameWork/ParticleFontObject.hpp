#pragma once
namespace elipmocframework {
	//�p�[�e�B�N���p�̕����I�u�W�F�N�g
	class ParticleFontObject {
		const siv::Font& m_font;
		//�\�����镶����
		const siv::String m_text;
		//color
		siv::Color m_color;
		//�ʒu
		siv::Vec2 m_pos;
		//��������
		int m_lifeTime;
		//���x�x�N�g��
		siv::Vec2 m_speedv;
		//�����x�x�N�g��
		const siv::Vec2 m_vspeedv;
		//���ߓx
		double m_opacity;
		//�������ߓx
		const double m_vopacity;
		//�d�͉����x
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