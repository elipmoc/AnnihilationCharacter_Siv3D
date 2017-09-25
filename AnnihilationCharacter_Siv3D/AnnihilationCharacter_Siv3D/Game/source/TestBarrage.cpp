/*#include "TestBarrage.hpp"
#include "BulletList.hpp"

namespace  game{
	void TestBarrage::Update()
	{
		GetBulletList().Update();
		count++;
		if (count % 20 == 0) {
			auto&& rad=siv::Math::Radians(siv::Random(0, 359));
			GetBulletList().MakeBullet(GetPos(), { siv::Math::Cos(rad)*2,siv::Math::Sin(rad)*2 }, { 0,0 });
		}
	}
}
*/