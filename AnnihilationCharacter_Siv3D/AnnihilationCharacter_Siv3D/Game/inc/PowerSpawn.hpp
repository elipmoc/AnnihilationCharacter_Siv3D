#pragma once
#include <vector>

namespace game {

	class Power;
	//�t�B�[���h�ɗ͂𐶐�����N���X
	class PowerSpawn {
	
		std::unique_ptr<std::vector<Power>> m_powerList;
	public:

		PowerSpawn();
		~PowerSpawn();

		//�͕`��
		void Draw()const;
		//�͍X�V
		void Update();
	};
}