#pragma once
#include <memory>

namespace game {

	class BulletListCreator;
	class BossBehavior;

	//任意のBossBehaviorを生成する基底のクラス
	class BossBehaviorMakeBase {
	public:
		virtual std::unique_ptr<BossBehavior> Create(BulletListCreator*)=0;

	};

	//上記のクラスをテンプレートで実現
	template<class T>
	class BossBehaviorMake:BossBehaviorMakeBase {
	public:
		virtual std::unique_ptr<BossBehavior> Create(BulletListCreator* bulletListCreator) override final {
			return std::make_unique<T>(bulletListCreator);
		}

	};

}