#pragma once
#include <memory>
namespace game {
	//読み取り専用のGameCounter
	class GameCounterReader {
	public:
		virtual size_t GetCount() const=0;
	};

	//ゲームシーンでの時間をカウントするクラス
	class GameCounter :public GameCounterReader {
		size_t m_count;
	public:
		GameCounter(size_t count) :m_count(count){}

		//1カウントする
		void CountDown() { m_count++; }
		virtual size_t GetCount() const override final{ return  m_count; }
		GameCounter(const GameCounter&) = delete;
	};
}