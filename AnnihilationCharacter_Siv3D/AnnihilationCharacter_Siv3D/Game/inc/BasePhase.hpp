#pragma once

namespace game {

	//BossPhase‚ÆZakoEnemyPhase‚ð‹¤’Ê‚µ‚Äˆµ‚¤‚½‚ß‚ÌŠî’êƒNƒ‰ƒX
	class BasePhase {

	public:
		virtual void Update() = 0;
		virtual void Draw()const = 0;
	};

}