#pragma once
#include <string>
#include "FontObjectBase.hpp"
#include "Action.hpp"
#include "ActionList.hpp"
#include "GlowTextImage.hpp"
namespace elipmocframework {

	

	//フォントオブジェクト
	class FontObject:public FontObjectBase {
		double m_scale=1;
		siv::Font m_font;
		siv::String m_text;
		siv::Vec2 m_pos;
		//文字色
		siv::Color m_color=siv::Palette::White;
		//アクションリスト
		ActionList m_actionList;

		//光らせる用の画像
		std::unique_ptr<GlowTextImage> m_glowTextImage;


	public:
		virtual FontObject& AddAction(std::unique_ptr<ActionBase>&& action)
		override final{
			m_actionList.push_back(std::move(action));
			return *this;
		}

		void SetGlow(int32 blur, double gamma = 2.0) {
			m_glowTextImage=std::make_unique<GlowTextImage>(m_font,m_text,blur,gamma);
		}

		//posの参照を得る
		virtual const siv::Vec2& GetRefPos() override final{ return m_pos; }

		//posアクセサ
		virtual siv::Vec2 GetPos()const noexcept override final{ return m_pos; }
		virtual FontObject& SetPos(const siv::Vec2& _pos) noexcept override final{ m_pos = _pos; return *this; }

		//scaleアクセサ
		virtual double GetScale() const noexcept override final{ return m_scale; };
		virtual FontObject& SetScale(double _scale)noexcept override final{ 
			m_scale = _scale;
			m_font = siv::Font(m_scale);
			return *this;
		}

		//textアクセサ
		virtual siv::String GetText() const noexcept override final{ return m_text; }
		virtual FontObject& SetText(const siv::String& _text) noexcept override final {m_text = _text; return *this; }

		//Colorアクセサ
		virtual siv::Color GetColor()const noexcept override final{ return m_color; }
		virtual FontObject& SetColor(const siv::Color& color) noexcept override final{ m_color = color; return *this; }

		FontObject(int fontsize=20) :m_scale(1),m_font(fontsize) ,m_actionList(this){

		}

		FontObject(int fontsize,const siv::String& fontType) :m_scale(1), m_font(fontsize,fontType), m_actionList(this) {

		}

		FontObject(siv::String _text, int fontsize = 20):m_scale(1), m_font(fontsize),m_text(_text),m_actionList(this) {

		}

		virtual void Update() override {
			m_actionList.Update();
		}

		virtual void Draw() const override final{
			//siv::Mat3x2 mat = siv::Mat3x2::Scale(m_scale, m_pos);
			//siv::Transformer2D t(mat, false);
			if (m_glowTextImage != nullptr) {
				m_glowTextImage->Draw({ (int)m_pos.x,(int)m_pos.y });
			}
			m_font(m_text).draw({ (int)m_pos.x,(int)m_pos.y },m_color);
		}
		
		virtual void DrawCenter()const  override final{
			//siv::Mat3x2 mat = siv::Mat3x2::Scale(m_scale, m_pos);
			//siv::Transformer2D t(mat, false);
			//siv::Graphics2D::SetTransform(siv::Mat3x2::Scale(m_scale, m_pos));
			if (m_glowTextImage != nullptr) {
				m_glowTextImage->DrawCenter({ (int)m_pos.x,(int)m_pos.y });
			}
			m_font(m_text).drawCenter({ (int)m_pos.x,(int)m_pos.y }, m_color);
		}

	};
}