#pragma once
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class BulletListCreator;

	//�e���N���X
	class BarrageBase {
		//�e���X�g
		std::unique_ptr<BulletListCreator> m_bulletListCreator;

		//��l���̎Q�ƍ��W
		const siv::Vec2& m_playerBindPos;

		//�e�łl�̍��W
		const siv::Vec2& m_bindPos;
		//�e�łl�̍��W�C���p
		const siv::Vec2 m_fixPos;

		const Level m_level;
	protected:

		BulletListCreator& GetBulletListCreator();

		siv::Vec2 GetPlayerPos() {
			return m_playerBindPos;
		}

		siv::Vec2 GetPos()const noexcept {
			return m_bindPos + m_fixPos;
		}

	public:
		BarrageBase(BulletListCreator&,const Level level, const siv::Vec2& bindPos,const siv::Vec2&playerBindPos, const siv::Vec2& fixPos);
		~BarrageBase();
		void Update();
		virtual void YawarakaUpdate() = 0;
		virtual void NormalUpdate()=0;
		virtual void RengokuUpdate()=0;
		//void Draw()const;
	};

	//BarrageBase�𐶐�����r���_�[�N���X�p��interface
	class BarrageGenerator {
	public:
		virtual std::unique_ptr<BarrageBase> GenerateBarrage(BulletListCreator& ,const Level level,const siv::Vec2& bindPos, const siv::Vec2&playerBindPos, const siv::Vec2& fixPos = {0,0})const = 0;
	};

	template<class BarrageT>
	class MakeBarrageGenerator :public BarrageGenerator {
		virtual std::unique_ptr<BarrageBase> GenerateBarrage(BulletListCreator& bulletListCreator,const Level level, const siv::Vec2& bindPos, const siv::Vec2&playerBindPos, const siv::Vec2& fixPos)const override final {
			return std::make_unique<BarrageT>(bulletListCreator,level,bindPos,playerBindPos, fixPos);
		}
	};
}