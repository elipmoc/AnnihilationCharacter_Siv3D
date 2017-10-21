#pragma once
namespace game {
	class BulletListCreator;

	class BossBehavior {
		BulletListCreator& m_bulletListCreator;
	public:
		BossBehavior(BulletListCreator&);
		virtual void Update()=0;
	};
}