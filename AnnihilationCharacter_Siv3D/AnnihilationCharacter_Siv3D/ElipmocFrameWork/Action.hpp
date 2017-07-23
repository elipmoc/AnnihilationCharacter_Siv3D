#pragma once
#include <vector>
#include <memory>
#include <functional>
namespace elipmocframework {

	//アクション基底クラス-----------------------------------------------------------------
	class ActionBase {
	protected:
		//アクション削除フラグ
		bool m_deleteFlag = false;
		//次に実行されるアクション
		std::unique_ptr<ActionBase> m_nextAction;
	public:
		virtual ~ActionBase() {};
		virtual void Init() {};
		virtual void Update() {};
		bool CanDelete() { return m_deleteFlag; }
	};

	//移動アクション（T型はGetPos()とSetPos()を持つと仮定する）-----------------------------------------------------------------------------------------
	template<class T>
	class MoveAction:public ActionBase {
		T& t;
		//アクションの実行時間
		const int interval;
		//カウントダウン
		int nowTime=0;
		//変化量
		siv::Vec2 deltaPos;
		//終着地点
		const siv::Vec2 endPos;
	public:
		//(_t=アクション対象 , _endPos=終着地点 , _interval=実行時間)
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
	

	//拡大縮小アクション（T型はGetScale()とSetScale()を持つと仮定する）-----------------------------------------------------
	template<class T>
	class ScaleAction :public ActionBase {
		T& t;
		//アクションの実行時間
		const int interval;
		//カウントダウン
		int nowTime = 0;
		//変化量
		double deltaScale;
		//最終拡大率
		const double endScale;
	public:
		//(_t=アクション対象 , _endScale=最終拡大率, _interval=実行時間)
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


	//アクションリスト
	class ActionList {
		std::vector<std::unique_ptr<ActionBase>> actions;
	public:
		//アクション追加
		ActionList& push_back(std::unique_ptr<ActionBase>&& action) {
			action->Init();
			actions.push_back(std::move(action));
			return *this;
		}
		//アクション更新
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