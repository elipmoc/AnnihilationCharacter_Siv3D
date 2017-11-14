#pragma once
#include <vector>

namespace game {

	class Power;
	//�t�B�[���h�ɗ͂𐶐�����N���X
	class PowerSpawn {
		std::vector<std::unique_ptr<Power>> m_powerList;
		//�J�E���g�p
		size_t count = 0;
	public:

		PowerSpawn();
		~PowerSpawn();

		//�͕`��
		void Draw()const;
		//�͍X�V
		void Update();
	};
}