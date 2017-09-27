#pragma once
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class BulletList;

	//�e���N���X
	class BarrageBase {
		//�e���X�g
		std::unique_ptr<BulletList> m_bulletList;

		//��l���̎Q�ƍ��W
		const siv::Vec2& m_playerBindPos;

		//�e�łl�̍��W
		const siv::Vec2& m_bindPos;
		//�e�łl�̍��W�C���p
		const siv::Vec2 m_fixPos;

		const Level m_level;
	protected:

		BulletList& GetBulletList();

		siv::Vec2 GetPlayerPos() {
			return m_playerBindPos;
		}

		siv::Vec2 GetPos()const noexcept {
			return m_bindPos + m_fixPos;
		}

	public:
		BarrageBase(const size_t,const Level level, const siv::Vec2& bindPos,const siv::Vec2&playerBindPos, const siv::Vec2& fixPos);
		~BarrageBase();
		void Update();
		virtual void NormalUpdate()=0;
		virtual void RengokuUpdate()=0;
		void Draw()const;
	};

	//BarrageBase�𐶐�����r���_�[�N���X�p��interface
	class BarrageGenerator {
	public:
		virtual std::unique_ptr<BarrageBase> GenerateBarrage(const Level level,const siv::Vec2& bindPos, const siv::Vec2&playerBindPos, const siv::Vec2& fixPos = {0,0})const = 0;
	};

	template<class BarrageT>
	class MakeBarrageGenerator :public BarrageGenerator {
		virtual std::unique_ptr<BarrageBase> GenerateBarrage(const Level level, const siv::Vec2& bindPos, const siv::Vec2&playerBindPos, const siv::Vec2& fixPos)const override final {
			return std::make_unique<BarrageT>(level,bindPos,playerBindPos, fixPos);
		}
	};
}