#include "GameMaster.hpp"
#include "TitleScene.hpp"
#include "SelectPlayerScene.hpp"
#include "GameOverScene.hpp"
#include "GameScene.hpp"
#include "ObjectPoolUtil.hpp"
#include "CollisionControl.hpp"
#include "LoadFileTerrainData.hpp"



int elipmocframework::ObjectPoolCount::count = 0;

namespace game {


	//�C���X�^���X�̎��ԍ쐬
	GameMaster GameMaster::instance;

	GameMaster::GameMaster()
		:mySceneManager(std::make_unique<MySceneManager>())
	{
	}

	GameMaster::~GameMaster()
	{
	}

	//����������
	void GameMaster::Init()
	{
		//�E�C���h�E�ݒ�
		siv::Window::SetTitle(L"���ŕ��� ver 1919810114514");
		siv::Window::Resize(700, 580);

		//�V�[���Z�b�g
		mySceneManager->add<TitleScene>(L"Title");
		mySceneManager->add<SelectPlayerScene>(L"SelectPlayer");
		mySceneManager->add<GameScene>(L"Game");
		mySceneManager->add<GameOverScene>(L"GameOver");

		//�n�`�f�[�^���[�h
		LoadFileTerrainData terrainData;
		try
		{
			terrainData.LoadFile();
		}
		catch (const siv::String& str)
		{
			siv::MessageBox::Show(str);
			return;
		}
	}

	//�Q�[�����[�v�X�^�[�g
	void GameMaster::Start()
	{
		while (siv::System::Update() && mySceneManager->updateAndDraw()) {
			siv::Println(elipmocframework::ObjectPoolCount::count);
			game::CollisionControl::GetInstance().Update();
			game::CollisionControl::GetInstance().DebugDraw();
		}
	}

	void GameMaster::End()
	{
	}
}