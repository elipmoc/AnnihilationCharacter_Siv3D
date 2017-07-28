#pragma once
#include "Action.hpp"
#include <deque>
namespace elipmocframework {
	class FontObject;
	//�A�N�V�������X�g
	class ActionList {
		std::vector<std::unique_ptr<ActionBase>> actions;
		FontObject* m_f;
	public:

		ActionList(FontObject* f) :m_f(f) {};

		//�A�N�V�����ǉ�
		ActionList& push_back(std::unique_ptr<ActionBase>&& action) {
			action->SetFontObject(m_f);
			action->Init();
			actions.push_back(std::move(action));
			return *this;
		}
		//�A�N�V�����X�V
		void Update() {
			static std::vector<std::unique_ptr<ActionBase>> nextActions;

			auto&& tail_itr=std::remove_if(actions.begin(), actions.end(), [](std::unique_ptr<ActionBase>& actionptr) {
				if (actionptr->CanDelete()) {
					auto&& nextAction = actionptr->MoveNextAction();
					if (nextAction) {
						nextActions.push_back(std::move(nextAction));
					}
					return true;
				}
				return false;
			});
			actions.erase(tail_itr, actions.end());

			for (auto&& item : nextActions) {
				push_back(std::move(item));
			}
			nextActions.clear();

			for (auto&& item:actions)
				item->Update();
		}

	};
}