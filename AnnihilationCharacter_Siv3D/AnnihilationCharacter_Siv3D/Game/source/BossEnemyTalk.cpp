#include "BossEnemyTalk.hpp"
#include "FontObject.hpp"

namespace game {
	BossEnemyTalk::BossEnemyTalk(const siv::Vec2& pos):
		m_frameFont(std::make_unique<elipmocframework::FontObject>(12, L"ＭＳ Ｐゴシック")),
		m_talkFont(std::make_unique<elipmocframework::FontObject>(16, L"ＭＳ Ｐゴシック")),
		m_pos(pos)
	{
		m_frameFont->SetText(
			L"----------------------------------\n"
			L"|                                                        |\n"
			L"|                                                        |\n"
			L"|                                                        |\n"
			L"|                                                        |\n"
			L"|                                                        |\n"
			L"----------------------------------\n"
		);
		m_frameFont->SetPos(pos);
		m_talkFont->SetPos(pos + siv::Vec2{10,20});
		str[0] = L"よくぞここまでたどり着いた。";
		str[1] = L"まあ、それはそれとして・・・";
		str[2] = L"基本情報勉強やだああああ\nああああ！！！！！！";
		str[3] = L"あああああああああああ！\nうわあああああ！！\nんほおおおお！！！";
		str[4] = L"ぶちちちちｔ！！";
	}
	BossEnemyTalk::~BossEnemyTalk()
	{
	}

	bool BossEnemyTalk::IsFinished() const noexcept{
		return count / 180 >= 5;
	}

	void BossEnemyTalk::Update()
	{
		if (count % 180 == 0 && count / 180 < 5)
			m_talkFont->SetText(str[count / 180]);
		count++;
	}
	void BossEnemyTalk::Draw() const
	{
		m_frameFont->Draw();
		m_talkFont->Draw();
		
	}
}