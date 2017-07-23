#pragma once
#include <vector>
#include <memory>
#include <functional>
namespace elipmocframework {

	//�A�N�V�������N���X-----------------------------------------------------------------
	class ActionBase {
	protected:
		//�A�N�V�����폜�t���O
		bool m_deleteFlag = false;
		//���Ɏ��s�����A�N�V����
		std::unique_ptr<ActionBase> m_nextAction;
	public:
		virtual ~ActionBase() {};
		virtual void Init() {};
		virtual void Update() {};
		bool CanDelete() { return m_deleteFlag; }
	};

	//�ړ��A�N�V�����iT�^��GetPos()��SetPos()�����Ɖ��肷��j-----------------------------------------------------------------------------------------
	template<class T>
	class MoveAction:public ActionBase {
		T& t;
		//�A�N�V�����̎��s����
		const int interval;
		//�J�E���g�_�E��
		int nowTime=0;
		//�ω���
		siv::Vec2 deltaPos;
		//�I���n�_
		const siv::Vec2 endPos;
	public:
		//(_t=�A�N�V�����Ώ� , _endPos=�I���n�_ , _interval=���s����)
		MoveAction(T& _t,const siv::Vec2& _endPos,const int _interval):t(std::forward<T>(_t)),endPos(_endPos),interval(_interval){}

		virtual void Init()override{
			deltaPos=(endPos - t.GetPos()) / interval;
		}
		virtual void Update()override{
			nowTime++;
			t.SetPos(t.GetPos()+deltaPos);
			if (nowTime >= interval)m_deleteFlag = true;
		}
	};
	

	//�g��k���A�N�V�����iT�^��GetScale()��SetScale()�����Ɖ��肷��j-----------------------------------------------------
	template<class T>
	class ScaleAction :public ActionBase {
		T& t;
		//�A�N�V�����̎��s����
		const int interval;
		//�J�E���g�_�E��
		int nowTime = 0;
		//�ω���
		double deltaScale;
		//�ŏI�g�嗦
		const double endScale;
	public:
		//(_t=�A�N�V�����Ώ� , _endScale=�ŏI�g�嗦, _interval=���s����)
		ScaleAction(T& _t, const double _endScale, const int _interval) :t(std::forward<T>(_t)), endScale(_endScale), interval(_interval) {}

		virtual void Init()override {
			deltaScale = (endScale - t.GetScale()) / interval;
		}
		virtual void Update()override {
			nowTime++;
			t.SetScale(t.GetScale() + deltaScale);
			if (nowTime >= interval)m_deleteFlag = true;
		}
	};


	//�A�N�V�������X�g
	class ActionList {
		std::vector<std::unique_ptr<ActionBase>> actions;
	public:
		//�A�N�V�����ǉ�
		ActionList& push_back(std::unique_ptr<ActionBase>&& action) {
			action->Init();
			actions.push_back(std::move(action));
			return *this;
		}
		//�A�N�V�����X�V
		void Update() {
			for(auto it=actions.begin();it!=actions.end();)
			{ 
				(*it)->Update();
				if ((*it)->CanDelete())
					it = actions.erase(it);
				else
					++it;
			}
		}

	};
}