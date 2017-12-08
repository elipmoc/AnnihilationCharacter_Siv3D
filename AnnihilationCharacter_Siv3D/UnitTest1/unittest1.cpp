#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: テスト コードをここに挿入します
			auto gc =std::make_shared<game::GameCounter>(0);
			std::weak_ptr<game::GameCounterReader> gcr = gc;
			std::weak_ptr<game::GameCounterReader> gcr2=gcr;
			gc->CountDown();
			Assert::IsTrue(gc->GetCount() == 1,L"gc");
			Assert::IsTrue(gcr.lock()->GetCount() == 1, L"gcr");
			Assert::IsTrue(gcr2.lock()->GetCount() == 1,L"gcr2");
			gc->CountDown();
			Assert::IsTrue(gc->GetCount() == 2, L"gc");
			Assert::IsTrue(gcr.lock()->GetCount() == 2, L"gcr");
			Assert::IsTrue(gcr2.lock()->GetCount() == 2, L"gcr2");

		}

		TEST_METHOD(GamePadConfigLoaderTest)
		{
			
			game::GamePadData gpd{ 99,99,99,99,99,99,99 };
			game::GamePadConfigLoader gpl;
			gpl.Load("GamePadConfig.json", [&gpd](game::GamePadData new_gpd) {gpd = new_gpd; });
			Assert::IsTrue(gpd.right == 0, L"gpd.right");
			Assert::IsTrue(gpd.left == 1, L"gpd.left");
			Assert::IsTrue(gpd.up == 2, L"gpd.up");
			Assert::IsTrue(gpd.down == 3, L"gpd.down");
			Assert::IsTrue(gpd.jump == 4, L"gpd.jump");
			Assert::IsTrue(gpd.barrier == 5, L"gpd.barrier");
			Assert::IsTrue(gpd.fuwari==6,L"gpd.fuwari");
		}
	};
}