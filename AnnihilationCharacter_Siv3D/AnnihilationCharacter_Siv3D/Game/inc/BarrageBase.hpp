#pragma once
#include <memory>
#include "SceneBase.hpp"

namespace game {
	class BulletList;

	//弾幕クラス
	class BarrageBase {
		//弾リスト
		BulletList& m_bulletList;

		//主人公の参照座標
		const siv::Vec2& m_playerBindPos;

		//弾打つ人の座標
		const siv::Vec2& m_bindPos;
		//弾打つ人の座標修正用
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
		BarrageBase(BulletList&,const Level level, const siv::Vec2& bindPos,const siv::Vec2&playerBindPos, const siv::Vec2& fixPos);
		~BarrageBase();
		void Update();
		virtual void NormalUpdate()=0;
		virtual void RengokuUpdate()=0;
		void Draw()const;
	};

	//BarrageBaseを生成するビルダークラス用のinterface
	class BarrageGenerator {
	public:
		virtual std::unique_ptr<BarrageBase> GenerateBarrage(BulletList& ,const Level level,const siv::Vec2& bindPos, const siv::Vec2&playerBindPos, const siv::Vec2& fixPos = {0,0})const = 0;
	};

	template<class BarrageT>
	class MakeBarrageGenerator :public BarrageGenerator {
		virtual std::unique_ptr<BarrageBase> GenerateBarrage(BulletList& bulletList,const Level level, const siv::Vec2& bindPos, const siv::Vec2&playerBindPos, const siv::Vec2& fixPos)const override final {
			return std::make_unique<BarrageT>(bulletList,level,bindPos,playerBindPos, fixPos);
		}
	};
}