#pragma once
#include <memory>
#include "ObjectPool.hpp"
#include "ParticleFontObject.hpp"
namespace elipmocframework {

	struct ParticleState {
		//表示する文字
		siv::String text;
		//表示する文字サイズ
		size_t fontSize=20;
		//パーティクルクラス自身の生存時間
		int lifeTime=0;
		//粒子生存時間
		int particleLifeTime=0;
		//一度に放出する粒子の数
		size_t particleNum=0;
		//存在できる粒子の数
		size_t particleMaxNum=100;
		//初速度
		double speed=0;
		//加速度
		double vspeed=0;
		//粒子の色
		siv::Color color=siv::Palette::White;
		//加速透過度
		double vopacity=0;
		//発火の間隔
		int fireInterval=99999;
		//重力加速度の設定
		siv::Vec2 g = {0,0};
	};

	class Particle {
		ObjectPool<ParticleFontObject> m_particleFobjList;
		const ParticleState m_state;
		siv::Vec2 m_pos;
		//表示するフォントオブジェクト
		const siv::Font m_font;
		//生存時間カウント用
		int m_lifeCount;


	public:

		Particle(const ParticleState state)noexcept
			:m_state(state), m_font(state.fontSize), m_particleFobjList(state.particleMaxNum) {}


		bool IsCanDelete() const noexcept{ return m_lifeCount<=0; }

		void Start(const siv::Vec2& pos) {
			m_particleFobjList.DeleteAll();
			m_pos = pos; 
			m_lifeCount = m_state.lifeTime; 
		}

		void Update() {
			//寿命が来た粒子を削除する
			elipmocframework::DeleteIf(m_particleFobjList, [](const auto& particle) {
				return particle.IsCanDelete();
			});

			//粒子更新
			for (auto&& item : m_particleFobjList)
				item.Update();
			//発火するタイミングなら発火させる
			if (m_lifeCount%m_state.fireInterval == 0)
				Fire();

			m_lifeCount--;
		}

		void Draw()const {
			for (const auto& item : m_particleFobjList)
				item.Draw();
		}

	private:
		//発火
		virtual void Fire() {
			for (size_t i = 0; i < m_state.particleNum; i++) {

				//プールがいっぱいになったら抜ける
				if (m_particleFobjList.MaxSize() == m_particleFobjList.Size())
					return;

				double angle = siv::Math::Radians(siv::Random(0, 359));
				siv::Vec2 e = { siv::Math::Cos(angle),siv::Math::Sin(angle) };
				m_particleFobjList.New(
					m_state.text, m_state.color, m_font, m_pos, m_state.particleLifeTime, e*m_state.speed, e*m_state.vspeed, m_state.vopacity, m_state.g);
			}
		}


	};
}