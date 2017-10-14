#pragma once
#include <deque>
#include "define.hpp"

namespace game {

	class TerrainData;

	//�n�`�z��𐧌䂷��N���X
	class TerrainControl {
	public:

		//�n�`�f�[�^
		const TerrainData& m_terrainData;

		//�n�`��̃T�C�Y
		static constexpr size_t TERRAIN_SIZE = 40;

		//����̃��[���̒n�`�̍����𓾂�
		double GetTerrainY(size_t lane)const {
			if (lane >= LANE_NUM)throw siv::String(L"�����ȃ��[���ԍ��ł�");
			return 450 - lane * 150;
		}

		//����X���W�̂��郌�[���ɒn�`�����邩�ǂ���
		bool IsExistTerrainFromX(double x, size_t lane) const{
			return m_activeTerrains[lane][(int)(x+m_offset) / TERRAIN_SIZE];
		}

		//param: �n�߂�ʒu
		TerrainControl(const TerrainData& terrainData,const size_t startPos=0);
		//�G���A�̖��[�܂ōs�������ǂ���
		bool IsFinished() { return finishedFlag; }
		void Update();
	private:
		//�n�`�̃C���f�b�N�X
		size_t index = 0;

		//�G���A�I���t���O
		bool finishedFlag = false;

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