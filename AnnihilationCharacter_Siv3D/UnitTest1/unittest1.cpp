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

	};
}