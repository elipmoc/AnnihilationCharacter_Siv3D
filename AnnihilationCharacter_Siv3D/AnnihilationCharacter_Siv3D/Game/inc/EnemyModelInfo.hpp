#pragma once
namespace game {

	//�G�̂����蔻��ƌ����ڂ̏��
	struct EnemyModelInfo {
		//�G�̕�����
		siv::String text;
		//�����蔻��̈ʒu�𒲐�
		siv::Vec2 collisionOffsetPos;
		//�����蔻��̔��a
		double r;
	};

	//EnemyModelInfo�𐶐�����r���_�[�N���X�p��interface
	class EnemyModelInfoGenerator {
	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo() = 0;
	};

}