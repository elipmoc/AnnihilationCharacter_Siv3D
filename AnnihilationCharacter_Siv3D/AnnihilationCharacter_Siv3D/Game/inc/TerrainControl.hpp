#pragma once
#include <deque>
namespace game {
	//�n�`�z��𐧌䂷��N���X
	class TerrainControl {
	public:
		//�n�`��̃T�C�Y
		static constexpr size_t TERRAIN_SIZE = 40;
		//���[����
		static constexpr size_t LANE_NUM = 3;

		//����̃��[���̒n�`�̍����𓾂�
		double GetTerrainY(size_t lane)const {
			if (lane >= LANE_NUM)throw siv::String(L"�����ȃ��[���ԍ��ł�");
			return 450 - lane * 150;
		}

		//����X���W�̂��郌�[���ɒn�`�����邩�ǂ���
		bool IsExistTerrainFromX(double x, size_t lane) const{
			return m_activeTerrains[lane][(int)(x+m_offset) / TERRAIN_SIZE];
		}

		TerrainControl();
		void Update();
	private:

		//�n�`���̃��X�g
		std::vector<bool>m_terrainFlags[LANE_NUM];

		//���݉�ʂɕ\������Ă���n�`
		std::deque<bool> m_activeTerrains[LANE_NUM];

		//�\���p�̒n�`����
		const siv::Font m_terrainFont;

		//�f�o�b�N�p
		siv::Circle circle;

		//�����̍����␳�p�i�����͕\���ʒu������邽�߁A�M���b�v�𖄂߂Ȃ���΂Ȃ�ʁj
		static constexpr size_t FIX_TERRAIN_Y=19;

		//�n�`�̍��W�����炷
		double m_offset = 0;

		void NextTerrainLoad();

	};
}