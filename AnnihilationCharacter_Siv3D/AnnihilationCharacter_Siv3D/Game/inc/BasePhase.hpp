#pragma once

namespace game {

	//BossPhase��ZakoEnemyPhase�����ʂ��Ĉ������߂̊��N���X
	class BasePhase {

	public:
		virtual void Update() = 0;
		virtual void Draw()const = 0;
	};

}