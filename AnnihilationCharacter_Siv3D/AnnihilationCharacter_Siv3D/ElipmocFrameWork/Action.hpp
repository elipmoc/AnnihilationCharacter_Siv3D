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
		void SetFontObject(FontObject* f)noexcept { m_f = f; }
		void SetNextAction(ActionPtr&& nextAction)noexcept { m_nextAction=std::move(nextAction); }
	protected:
		FontObject* m_f;
		//�A�N�V�����폜�t���O
		bool m_deleteFlag = false;
		//���Ɏ��s�����A�N�V����
		ActionPtr m_nextAction=nullptr;
	public:
		//���Ɏ��s�����A�N�V���������[�u
		ActionPtr MoveNextAction()noexcept {
			return std::move(m_nextAction);
		}
		//�V�[�P���X����
		friend ActionPtr operator <<(ActionPtr&& nextAction, ActionPtr&& action) {
			action->SetNextAction(std::move(nextAction));
			return std::move(action);
		}

		virtual ~ActionBase()noexcept {};
		virtual void Init() noexcept {};
		virtual void Update() noexcept {};
		bool CanDelete()noexcept { return m_deleteFlag; }
	};

	


	
}