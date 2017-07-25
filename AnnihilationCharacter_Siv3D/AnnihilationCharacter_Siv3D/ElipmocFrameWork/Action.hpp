#pragma once
#include <memory>
#include <functional>
namespace elipmocframework {

	class FontObject;
	class ActionList;
	//�A�N�V�������N���X-----------------------------------------------------------------
	class ActionBase {
		using ActionPtr=std::unique_ptr<ActionBase>;
		friend ActionList;
		void SetFontObject(FontObject* f) { m_f = f; }
		void SetNextAction(ActionPtr&& nextAction) { m_nextAction=std::move(nextAction); }
	protected:
		FontObject* m_f;
		//�A�N�V�����폜�t���O
		bool m_deleteFlag = false;
		//���Ɏ��s�����A�N�V����
		ActionPtr m_nextAction=nullptr;
	public:
		//���Ɏ��s�����A�N�V���������[�u
		ActionPtr MoveNextAction() {
			return std::move(m_nextAction);
		}
		//�V�[�P���X����
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