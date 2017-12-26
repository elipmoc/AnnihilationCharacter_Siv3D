#include "BossPhase.hpp"
#include "BossTalk.hpp"
#include "Boss.hpp"
#include "TerrainControl.hpp"
#include "BossPhase.hpp"
#include "BulletListCreator.hpp"
#include "PowerSpawn.hpp"
#include "BossHpGage.hpp"
#include "GameMaster.hpp"
#include "BossBehaviorMake.hpp"
#include "BossBehaviorMakeList.hpp"

namespace game {
	BossPhase::BossPhase(Level level, const siv::Vec2 & playerRefPos, BulletListCreator & bulletListCreator,TerrainControl& terrainControl):
		m_test(std::make_unique<BossTalk>(siv::Vec2(100,70))),
		m_terrainControl(terrainControl),
		m_boss(std::make_unique<Boss>(level,playerRefPos,bulletListCreator)),
		m_powerSpawn(std::make_unique<PowerSpawn>()),
		m_bossHpGage(std::make_unique<BossHpGage>()),
		m_bossBehaviorMakeList(std::make_unique<BossBehaviorMakeList>())
	{
		siv::SoundAsset(L"bgm").stop();
		m_terrainControl.SetTerrainData(GameMaster::GetInstance().GetTerrainData(m_terrainNameList[listIndex]));
		m_boss->SetHp(m_hpList[listIndex]);
		m_bossHpGage->SetMaxHp(m_hpList[listIndex]);
	}

	BossPhase::~BossPhase() = default;

	bool BossPhase::IsClear() const noexcept
	{
		return m_bossEndCount <= 0;
//		return listIndex >= m_bossBehaviorMakeList->GetSize();
	}

	void BossPhase::Draw() const
	{
		if (m_test != nullptr)
			m_test->Draw();
		m_boss->Draw();
		m_powerSpawn->Draw();
		if (m_test == nullptr)
			m_bossHpGage->Draw();
	}
	void BossPhase::Update()
	{
		if (m_test != nullptr) {
			m_test->Update();
			if (m_test->IsFinished()) {
				siv::SoundAsset(L"bossBgm").setLoop(true);
				siv::SoundAsset(L"bossBgm").play();
				m_test = nullptr;
				m_boss->SetBossBehavior(*m_bossBehaviorMakeList->Next());
			}
		}
		else{
			//hpが0になったら、ボスの状態を次に移行する
			if (m_boss->GetHp() <= 0) {
				listIndex++;
				if (listIndex >= m_bossBehaviorMakeList->GetSize()) {
					m_bossEndCount--;
				}
				else {
					m_boss->SetBossBehavior(*m_bossBehaviorMakeList->Next());
					m_boss->SetHp(m_hpList[listIndex]);
					m_bossHpGage->SetMaxHp(m_hpList[listIndex]);
					m_terrainControl.SetTerrainData(GameMaster::GetInstance().GetTerrainData(m_terrainNameList[listIndex]));
				}
			}
			m_bossHpGage->SetSizeFromHp(m_boss->GetHp());
			m_boss->Update();
			m_powerSpawn->Update();
		}
	}
}