#pragma once
#include <memory>
namespace elipmocframework {
	class FontObject;
}

namespace game {

	//�{�X����b���邽�߂̃N���X
	class BossEnemyTalk {
		//�O�g
		std::unique_ptr<elipmocframework::FontObject> m_frameFont;
		//��b���e
		std::unique_ptr<elipmocframework::FontObject> m_talkFont;
		//�\���ʒu
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