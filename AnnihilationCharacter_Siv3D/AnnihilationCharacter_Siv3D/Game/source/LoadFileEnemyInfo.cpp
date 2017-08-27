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
		else throw siv::String(L"enemy.txtに誤りがあります");
		return str;
	}

	void CheckSplit(int& index, const std::string& buf) {
		if ((index<buf.size() && buf[index++] == ',') == false)
			throw siv::String(L"enemy.txtに誤りがあります");
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
				throw siv::String(L"enemy.txtに誤りがあります");
			if ((index<buf.size() && buf[index++] == '}') == false)
				throw siv::String(L"enemy.txtに誤りがあります");
		}
		else
			throw siv::String(L"enemy.txtに誤りがあります");
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
			throw siv::String(L"enemy.txt読み込みに失敗しました");
		std::string buf;
		int index;
		while(std::getline(ifs, buf)){
			index = 0;
			auto info_ptr = std::make_unique<EnemyInfo>();

			//中かっこ判定
			if((index<buf.size() && buf[index++] == '{')==false)
				throw siv::String(L"enemy.txtに誤りがあります");
			
			//Actionの読み取り
			info_ptr->action = GetString(index, buf);
			CheckSplit(index, buf);

			//Posの読み取り
			info_ptr->startPos = GetPos(index, buf);
			CheckSplit(index, buf);
			info_ptr->stopPos = GetPos(index, buf);
			CheckSplit(index, buf);
			info_ptr->endPos=GetPos(index, buf);
			CheckSplit(index, buf);

			//中間位置待機時間の読み取り
			info_ptr->waitTime=GetNum(index, buf);
			CheckSplit(index, buf);

			//出現タイミングの読み取り
			info_ptr->bornTime = GetNum(index, buf);
			CheckSplit(index, buf);

			//生存時間の読み取り
			info_ptr->lifeTime = GetNum(index, buf);
			CheckSplit(index, buf);

			//弾幕種類の読み取り
			info_ptr->barrage = GetString(index, buf);
			CheckSplit(index, buf);

			//弾幕開始タイミングの読み取り
			info_ptr->barrageStartTime = GetNum(index, buf);
			CheckSplit(index, buf);

			//敵の見た目種類の読み取り
			info_ptr->model = GetString(index, buf);

			//中かっこ判定
			if ((index<buf.size() && buf[index++] == '}') == false)
				throw siv::String(L"enemy.txtに誤りがあります");
			m_enemyInfoList.push_back(std::move(info_ptr));
		}
	}

	
}