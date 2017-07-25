#pragma once
#include <string>
#include "Action.hpp"
#include "ActionList.hpp"
namespace elipmocframework {
	//フォントオブジェクト
	class FontObject {
		double m_scale=1;
		const siv::Font m_font;
		siv::String m_text;
		siv::Vec2 m_pos;
		//文字色
		siv::Color m_color=siv::Palette::White;
		//アクションリスト
		ActionList m_actionList;

	public:
		FontObject& AddAction(std::unique_ptr<ActionBase>&& action) {
			m_actionList.push_back(std::move(action));
			return *this;
		}
		//posアクセサ
		siv::Vec2 GetPos()const { return m_pos; }
		FontObject& SetPos(const siv::Vec2& _pos) { m_pos = _pos; return *this; }

		//scaleアクセサ
		double GetScale() const{ return m_scale; };
		FontObject& SetScale(double _scale) { m_scale = _scale; return *this; }

		//textアクセサ
		siv::String GetText() const { return m_text; }
		FontObject& SetText(const siv::String& _text) { m_text = _text; return *this; }

		//Colorアクセサ
		siv::Color GetColor()const { return m_color; }
		FontObject& SetColor(const siv::Color& color) { m_color = color; return *this; }

		FontObject(int fontsize=20) :m_scale(1),m_font(fontsize) ,m_actionList(this){

		}

		FontObject(siv::String _text, int fontsize = 20) :m_scale(1), m_font(fontsize),m_text(_text),m_actionList(this) {

		}

		virtual void Update() {
			m_actionList.Update();
		}

		virtual void Draw() const{
			siv::Mat3x2 mat = siv::Mat3x2::Scale(m_scale, m_pos);
			siv::Transformer2D t(mat, false);
			m_font(m_text).draw(m_pos,m_color);
		}
		void DrawCenter()const {
			siv::Mat3x2 mat = siv::Mat3x2::Scale(m_scale, m_pos);
			siv::Transformer2D t(mat, false);
			m_font(m_text).drawCenter(m_pos, m_color);
		}

	};
}