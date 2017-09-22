#pragma once

namespace elipmocframework {
	class ActionBase;
	//�t�H���g�I�u�W�F�N�g�̃C���^�[�t�F�C�X
	class FontObjectBase {
	public:
		virtual FontObjectBase& AddAction(std::unique_ptr<ActionBase>&& action) = 0;

		//pos�̎Q�Ƃ𓾂�
		virtual const siv::Vec2& GetRefPos() = 0;

		//pos�A�N�Z�T
		virtual siv::Vec2 GetPos()const noexcept =0;
		virtual FontObjectBase& SetPos(const siv::Vec2& _pos) noexcept = 0;

		//scale�A�N�Z�T
		virtual double GetScale() const noexcept =0;
		virtual FontObjectBase& SetScale(double _scale)noexcept = 0;

		//text�A�N�Z�T
		virtual siv::String GetText() const noexcept = 0;
		virtual FontObjectBase& SetText(const siv::String& _text) noexcept = 0;

		//Color�A�N�Z�T
		virtual siv::Color GetColor()const noexcept = 0;
		virtual FontObjectBase& SetColor(const siv::Color& color) noexcept = 0;

		virtual void Update() = 0;

		virtual void Draw() const = 0;

		virtual void DrawCenter()const = 0;

	};
}