#pragma once
namespace game {

	//�G�̂����蔻��ƌ����ڂ̏��
	struct EnemyModelInfo {
		//�G�̕�����
		siv::String text;
		//�G�̃J���[
		siv::Color color;
		//�����蔻��̈ʒu�𒲐�
		siv::Vec2 collisionOffsetPos = {0,0};
		//�����蔻��̔��a
		double r=0;
	};

	//EnemyModelInfo�𐶐�����r���_�[�N���X�p��interface
	class EnemyModelInfoGenerator {
	public:
		virtual EnemyModelInfo GenerateEnemyModelInfo()const = 0;
	};

}