#pragma once
#include <memory>
namespace elipmocframework {
	class FontObject;
}

namespace game {

	//ボスが会話するためのクラス
	class BossEnemyTalk {
		//外枠
		std::unique_ptr<elipmocframework::FontObject> m_frameFont;
		//会話内容
		std::unique_ptr<elipmocframework::FontObject> m_talkFont;
		//表示位置
		const siv::Vec2 m_pos;
		siv::String str[50];
		size_t count = 0;
	public:
		BossEnemyTalk(const siv::Vec2& pos);
		~BossEnemyTalk();
		bool IsFinished()const noexcept;
		void Update();
		void Draw()const;
	};

}