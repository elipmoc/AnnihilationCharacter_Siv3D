#pragma once
#include <memory>
namespace game {
	//�ǂݎ���p��GameCounter
	class GameCounterReader {
	public:
		virtual size_t GetCount() const=0;
	};

	//�Q�[���V�[���ł̎��Ԃ��J�E���g����N���X
	class GameCounter :public GameCounterReader {
		size_t m_count;
	public:
		GameCounter(size_t count) :m_count(count){}

		//1�J�E���g����
		void CountDown() { m_count++; }
		virtual size_t GetCount() const override final{ return  m_count; }
		GameCounter(const GameCounter&) = delete;
	};
}