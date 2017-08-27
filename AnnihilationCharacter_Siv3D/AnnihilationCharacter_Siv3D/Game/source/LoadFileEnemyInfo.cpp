#include "LoadFileEnemyInfo.hpp"
#include "EnemyInfo.hpp"
#include <cctype>

namespace game {

	std::string GetString(int& index, const std::string& buf) {
		std::string str = "";
		if (index<buf.size() && buf[index++] == '"') {
			while (index < buf.size() && buf[index] != '"') {
				str += buf[index];
				index++;
			}
			index++;
		}
		else throw siv::String(L"enemy.txt�Ɍ�肪����܂�");
		return str;
	}

	void CheckSplit(int& index, const std::string& buf) {
		if ((index<buf.size() && buf[index++] == ',') == false)
			throw siv::String(L"enemy.txt�Ɍ�肪����܂�");
	}

	int GetNum(int& index, const std::string& buf) {
		std::string numstr = "";
		while (index < buf.size() && isdigit(buf[index])) {
			numstr += buf[index];
			index++;
		}
		return std::stoi(numstr);
	}

	siv::Vec2 GetPos(int& index, const std::string& buf) {
		siv::Vec2 pos;
		if (index <buf.size() && buf[index++] == '{') {
			pos.x = GetNum(index, buf);
			if (index<buf.size() && buf[index++] == ',')
				pos.y = GetNum(index, buf);
			else
				throw siv::String(L"enemy.txt�Ɍ�肪����܂�");
			if ((index<buf.size() && buf[index++] == '}') == false)
				throw siv::String(L"enemy.txt�Ɍ�肪����܂�");
		}
		else
			throw siv::String(L"enemy.txt�Ɍ�肪����܂�");
		return pos;
	}




	LoadFileEnemyInfo::LoadFileEnemyInfo()
	{
	}
	LoadFileEnemyInfo::~LoadFileEnemyInfo()
	{
	}
	void LoadFileEnemyInfo::LoadFile()
	{
		std::ifstream ifs("enemy.txt");
		if (!ifs.is_open())
			throw siv::String(L"enemy.txt�ǂݍ��݂Ɏ��s���܂���");
		std::string buf;
		int index;
		while(std::getline(ifs, buf)){
			index = 0;
			auto info_ptr = std::make_unique<EnemyInfo>();

			//������������
			if((index<buf.size() && buf[index++] == '{')==false)
				throw siv::String(L"enemy.txt�Ɍ�肪����܂�");
			
			//Action�̓ǂݎ��
			info_ptr->action = GetString(index, buf);
			CheckSplit(index, buf);

			//Pos�̓ǂݎ��
			info_ptr->startPos = GetPos(index, buf);
			CheckSplit(index, buf);
			info_ptr->stopPos = GetPos(index, buf);
			CheckSplit(index, buf);
			info_ptr->endPos=GetPos(index, buf);
			CheckSplit(index, buf);

			//���Ԉʒu�ҋ@���Ԃ̓ǂݎ��
			info_ptr->waitTime=GetNum(index, buf);
			CheckSplit(index, buf);

			//�o���^�C�~���O�̓ǂݎ��
			info_ptr->bornTime = GetNum(index, buf);
			CheckSplit(index, buf);

			//�������Ԃ̓ǂݎ��
			info_ptr->lifeTime = GetNum(index, buf);
			CheckSplit(index, buf);

			//�e����ނ̓ǂݎ��
			info_ptr->barrage = GetString(index, buf);
			CheckSplit(index, buf);

			//�e���J�n�^�C�~���O�̓ǂݎ��
			info_ptr->barrageStartTime = GetNum(index, buf);
			CheckSplit(index, buf);

			//�G�̌����ڎ�ނ̓ǂݎ��
			info_ptr->model = GetString(index, buf);

			//������������
			if ((index<buf.size() && buf[index++] == '}') == false)
				throw siv::String(L"enemy.txt�Ɍ�肪����܂�");
			m_enemyInfoList.push_back(std::move(info_ptr));
		}
	}

	
}