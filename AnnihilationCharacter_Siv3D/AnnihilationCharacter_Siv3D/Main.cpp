#include "UseSiv3D.hpp"
void Main()
{
	siv::Font font(20);
	siv::String text;
	while (siv::System::Update()){
		siv::Input::GetCharsHelper(text);
		font(text).draw();
	}
}
