#include "BossTalk.hpp"
#include "FontObject.hpp"

namespace game {
	BossTalk::BossTalk(const siv::Vec2& pos):
		m_frameFont(std::make_unique<elipmocframework::FontObject>(12, L"�l�r �o�S�V�b�N")),
		m_talkFont(std::make_unique<elipmocframework::FontObject>(16, L"�l�r �o�S�V�b�N")),
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
		str[0] = L"�悭�������܂ł��ǂ蒅�����B";
		str[1] = L"�������傹�񂨑O��������";
		str[2] = L"�ŋ��̕����ł��鎄�ɂ�\n���Ă܂�";
		str[3] = L"���O�����ł����Ă�낤�I";
		str[4] = L"�������I";
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