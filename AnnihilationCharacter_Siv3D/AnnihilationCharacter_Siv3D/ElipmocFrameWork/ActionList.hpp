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

			for (auto it = actions.begin(); it != actions.end();)
			{
				(*it)->Update();
				if ((*it)->CanDelete()) {
					auto nextAction=(*it)->MoveNextAction();
					it = actions.erase(it);
					if (nextAction != nullptr) {
						nextActions.push_back(std::move(nextAction));
					}
					
				}
				else
					++it;
			}
			for (auto&& item : nextActions) {
				push_back(std::move(item));
			}
			nextActions.clear();
		}

	};
}