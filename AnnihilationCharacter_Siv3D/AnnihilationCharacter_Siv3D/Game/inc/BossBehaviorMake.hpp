#pragma once
#include <memory>
#include "SceneBase.hpp"
namespace game {

	class BulletListCreator;
	class BossBehavior;

	//任意のBossBehaviorを生成する基底のクラス
	class BossBehaviorMakeBase {
	public:
		virtual std::unique_ptr<BossBehavior> Create(const Level, const siv::Vec2&,const BulletListCreator&) const =0;

	};

	//上記のクラスをテンプレートで実現
	template<class T>
	class BossBehaviorMake : public BossBehaviorMakeBase {
	public:
		virtual std::unique_ptr<BossBehavior> Create(const Level level,const siv::Vec2& playerRefPos,const BulletListCreator& bulletListCreator) const override final {
			return std::make_unique<T>(level,playerRefPos,bulletListCreator);
		}

	};

}