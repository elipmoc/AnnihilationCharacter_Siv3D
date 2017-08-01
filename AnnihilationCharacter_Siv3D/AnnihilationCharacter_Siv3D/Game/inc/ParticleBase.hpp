#pragma once
#include <memory>
#include "ObjectPool.hpp"
#include "ParticleFontObject.hpp"
namespace game {
	class ParticleBase {
		elipmocframework::ObjectPool<ParticleFontObject> m_particleFobjList;
		//siv::Array<std::unique_ptr<ParticleFontObject>> m_particleFobjList;


		const siv::Font m_font;
		const siv::String m_text;
		const siv::Vec2 m_pos;
		//�p�[�e�B�N���N���X���g�̐�������
		int m_lifeTime;
		//���q��������
		const int m_particleLifeTime;
		//��x�ɕ��o���闱�q�̐�
		const int m_particleNum;
		//�����x
		const double m_speed;
		//�����x
		const double m_vspeed;
		//���q�̐F
		const siv::Color m_color;
		//�������ߓx
		const double m_vopacity;
		//���΂̊Ԋu
		const int m_fireInterval;

		const siv::Vec2 m_g;


	public:

		ParticleBase(
			const siv::String& text, const siv::Vec2& pos,
			const int lifeTime, const int particleLifeTime, const int particleNum,
			const double speed, const double vspeed, const siv::Color& color,
			const double vopacity, const int fireInterval, const size_t size, const siv::Vec2& g = {0,0})noexcept;

		static std::unique_ptr<ParticleBase> Create(
			const siv::String& text, const siv::Vec2& pos,
			const int lifeTime, const int particleLifeTime, const int particleNum,
			const double speed, const double vspeed, const siv::Color& color,
			const double vopacity, const int fireInterval, const size_t size, const siv::Vec2& g = {0,0}
			) {
			return std::make_unique<ParticleBase>(text,pos,lifeTime,particleLifeTime,particleNum,speed,vspeed,color,vopacity,fireInterval,size,g);
		}

		~ParticleBase();

		bool IsCanDelete() const noexcept{ return m_lifeTime<=0; }

		void Init() {
		}

		void Update();
		void Draw()const;
	private:
		//����
		virtual void Fire();


	};
}