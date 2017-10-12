#pragma once

namespace game {
	//BossPhaseとZakoEnemyPhaseを共通して扱うための基底クラス
	class BasePhase {
		public:
		virtual void Update() = 0;
		virtual void Draw()const = 0;
	};

}