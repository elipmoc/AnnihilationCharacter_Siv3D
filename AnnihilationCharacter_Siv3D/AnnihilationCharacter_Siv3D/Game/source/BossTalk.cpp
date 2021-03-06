#include "BossTalk.hpp"
#include "FontObject.hpp"

namespace game {
	BossTalk::BossTalk(const siv::Vec2& pos):
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
		str[1] = L"だがしょせんお前も文字だ";
		str[2] = L"最強の文字である私には\n勝てまい";
		str[3] = L"お前も消滅させてやろう！";
		str[4] = L"いくぞ！";
	}
	BossTalk::~BossTalk()
	{
	}

	bool BossTalk::IsFinished() const noexcept{
		return count / 180 >= 5;
	}

	void BossTalk::Update()
	{
		if (count % 180 == 0 && count / 180 < 5)
			m_talkFont->SetText(str[count / 180]);
		count++;
	}
	void BossTalk::Draw() const
	{
		m_frameFont->Draw();
		m_talkFont->Draw();
		
	}
}