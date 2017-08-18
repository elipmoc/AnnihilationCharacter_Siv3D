#include "TestBarrage.hpp"
#include "BulletList.hpp"

namespace  game{
	void TestBarrage::Update()
	{
		static int count = 0;
		GetBulletList().Update();
		count++;
		if (count % 20 == 0) {
			GetBulletList().MakeBullet(GetPos(), { 1,1 }, { 0,0 });
		}
	}
}
