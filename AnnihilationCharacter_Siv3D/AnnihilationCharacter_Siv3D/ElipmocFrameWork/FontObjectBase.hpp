#pragma once

namespace elipmocframework {
	class ActionBase;
	//フォントオブジェクトのインターフェイス
	class FontObjectBase {
	public:
		virtual FontObjectBase& AddAction(std::unique_ptr<ActionBase>&& action) = 0;

		//posの参照を得る
		virtual const siv::Vec2& GetRefPos() = 0;

		//posアクセサ
		virtual siv::Vec2 GetPos()const noexcept =0;
		virtual FontObjectBase& SetPos(const siv::Vec2& _pos) noexcept = 0;

		//scaleアクセサ
		virtual double GetScale() const noexcept =0;
		virtual FontObjectBase& SetScale(double _scale)noexcept = 0;

		//textアクセサ
		virtual siv::String GetText() const noexcept = 0;
		virtual FontObjectBase& SetText(const siv::String& _text) noexcept = 0;

		//Colorアクセサ
		virtual siv::Color GetColor()const noexcept = 0;
		virtual FontObjectBase& SetColor(const siv::Color& color) noexcept = 0;

		virtual void Update() = 0;

		virtual void Draw() const = 0;

		virtual void DrawCenter()const = 0;

	};
}