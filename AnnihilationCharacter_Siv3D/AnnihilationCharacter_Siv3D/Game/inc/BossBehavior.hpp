#pragma once
namespace game {
	class BulletListCreator;

	class BossBehavior {
		std::unique_ptr<BulletListCreator> m_bulletListCreator;
	protected:
		BulletListCreator& GetBulletListCreator() { return *m_bulletListCreator; };
		
	public:
		BossBehavior::BossBehavior(const BulletListCreator & bulletListCreator);
		virtual void Update()=0;
	};
}