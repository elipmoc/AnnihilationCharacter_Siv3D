#pragma once
#include <memory>
#include <functional>
namespace elipmocframework {

	class FontObject;
	class ActionList;
	//アクション基底クラス-----------------------------------------------------------------
	class ActionBase {
		using ActionPtr=std::unique_ptr<ActionBase>;
		friend ActionList;
		void SetFontObject(FontObject* f) { m_f = f; }
		void SetNextAction(ActionPtr&& nextAction) { m_nextAction=std::move(nextAction); }
	protected:
		FontObject* m_f;
		//アクション削除フラグ
		bool m_deleteFlag = false;
		//次に実行されるアクション
		ActionPtr m_nextAction=nullptr;
	public:
		//次に実行されるアクションをムーブ
		ActionPtr MoveNextAction() {
			return std::move(m_nextAction);
		}
		//シーケンス結合
		friend ActionPtr operator <<(ActionPtr&& nextAction, ActionPtr&& action) {
			action->SetNextAction(std::move(nextAction));
			return std::move(action);
		}

		virtual ~ActionBase() {};
		virtual void Init() {};
		virtual void Update() {};
		bool CanDelete() { return m_deleteFlag; }
	};

	


	
}