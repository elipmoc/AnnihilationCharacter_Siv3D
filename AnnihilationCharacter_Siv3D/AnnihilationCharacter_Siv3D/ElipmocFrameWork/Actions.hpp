#pragma once
#include "Action.hpp"
#include "FontObject.hpp"
namespace elipmocframework {

	//�ړ��A�N�V����-----------------------------------------------------------------------------------------
	class MoveAction :public ActionBase {

		//�A�N�V�����̎��s����
		const int interval;
		//�J�E���g�_�E��
		int nowTime = 0;
		//�ω���
		siv::Vec2 deltaPos;
		//�I���n�_
		const siv::Vec2 endPos;
		//( _endPos=�I���n�_ , _interval=���s����)
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


	//�g��k���A�N�V����-----------------------------------------------------
	class ScaleAction :public ActionBase {
		//�A�N�V�����̎��s����
		const int interval;
		//�J�E���g�_�E��
		int nowTime = 0;
		//�ω���
		double deltaScale;
		//�ŏI�g�嗦
		const double endScale;
		//(_endScale=�ŏI�g�嗦, _interval=���s����)
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
}