#pragma once
#include <memory>
#include <functional>
#include "Interface.hpp"
namespace elipmocframework {

	class FontObjectBase;
	class ActionList;
	//アクション基底クラス-----------------------------------------------------------------
	class ActionBase :public has_delete_flag{
		using ActionPtr=std::unique_ptr<ActionBase>;
		friend ActionList;
		void SetFontObject(FontObjectBase* f)noexcept { m_f = f; }
		void SetNextAction(ActionPtr&& nextAction)noexcept { m_nextAction=std::move(nextAction); }
	protected:
		FontObjectBase* m_f;
		//次に実行されるアクション
		ActionPtr m_nextAction=nullptr;
	public:
		//次に実行されるアクションをムーブ
		ActionPtr MoveNextAction()noexcept {
			return std::move(m_nextAction);
		}
		//シーケンス結合
		friend ActionPtr operator <<(ActionPtr&& nextAction, ActionPtr&& action) {
			action->SetNextAction(std::move(nextAction));
			return std::move(action);
		}

		virtual ~ActionBase()noexcept {};
		virtual void Init() noexcept {};
		virtual void Update() noexcept {};
	};

	


	
}