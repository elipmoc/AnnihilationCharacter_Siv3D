#pragma once
#include "Action.hpp"
#include "FontObjectBase.hpp"
namespace elipmocframework {

	//移動アクション-----------------------------------------------------------------------------------------
	class MoveAction :public ActionBase {

		//アクションの実行時間
		const int interval;
		//カウントダウン
		int nowTime = 0;
		//変化量
		siv::Vec2 deltaPos;
		//終着地点
		const siv::Vec2 endPos;
		//( _endPos=終着地点 , _interval=実行時間)
		MoveAction(const siv::Vec2& _endPos, const int _interval)noexcept :endPos(_endPos), interval(_interval) {}
	public:


		static std::unique_ptr<ActionBase> Create(const siv::Vec2& _endPos, const int _interval) {
			return std::unique_ptr<ActionBase>(new MoveAction(_endPos, _interval));
		}

		virtual void Init() noexcept override {
			deltaPos = (endPos - m_f->GetPos()) / interval;
		}
		virtual void Update()noexcept override {
			nowTime++;
			m_f->SetPos(m_f->GetPos() + deltaPos);
			if (nowTime >= interval)delete_flag = true;
		}
	};

	//移動アクション2-----------------------------------------------------------------------------------------
	//ずっと移動量を加算し続けるだけ
	class Move2Action :public ActionBase {

		//変化量
		const siv::Vec2 deltaPos;
		//( _endPos=終着地点 , _interval=実行時間)
		Move2Action(const siv::Vec2& _deltaPos)noexcept :deltaPos(_deltaPos) {}
	public:


		static std::unique_ptr<ActionBase> Create(const siv::Vec2& _deltaPos) {
			return std::unique_ptr<ActionBase>(new Move2Action(_deltaPos));
		}

		virtual void Init() noexcept override {
		}
		virtual void Update()noexcept override {
			m_f->SetPos(m_f->GetPos() + deltaPos);
		}
	};


	//拡大縮小アクション-----------------------------------------------------
	class ScaleAction :public ActionBase {
		//アクションの実行時間
		const int interval;
		//カウントダウン
		int nowTime = 0;
		//変化量
		double deltaScale;
		//最終拡大率
		const double endScale;
		//(_endScale=最終拡大率, _interval=実行時間)
		ScaleAction(const double _endScale, const int _interval)noexcept :endScale(_endScale), interval(_interval) {}
	public:

		static std::unique_ptr<ActionBase> Create(const double _endScale, const int _interval) {
			return std::unique_ptr<ActionBase>(new ScaleAction(_endScale, _interval));
		}

		virtual void Init()noexcept override {
			deltaScale = (endScale - m_f->GetScale()) / interval;
		}
		virtual void Update() noexcept override {
			nowTime++;
			m_f->SetScale(m_f->GetScale() + deltaScale);
			if (nowTime >= interval)delete_flag = true;
		}
	};

	//待機アクション-----------------------------------------------------------------------------------------
	class WaitAction :public ActionBase {

		//アクションの待機時間
		int m_waitTime;
		WaitAction(const int waitTime)noexcept :m_waitTime(waitTime) {}
	public:


		static std::unique_ptr<ActionBase> Create(const int waitTime) {
			return std::unique_ptr<ActionBase>(new WaitAction(waitTime));
		}

		virtual void Init() noexcept override {}
		virtual void Update()noexcept override {
			if (m_waitTime <= 0)delete_flag = true;
			m_waitTime--;
		}
	};
}