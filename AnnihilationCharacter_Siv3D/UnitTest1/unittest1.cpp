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

			struct Animal {
				virtual void Action() const{
					std::cout << "動物です" << std::endl;
				}
			};

			struct Pig:Animal {
				int a[100];
				virtual void Action()const override{
					std::cout << "ぶひー！" << std::endl;
				}

			};

			using elipmocframework::ObjectPool;

			ObjectPool<Animal, Pig> hoge_pool(10);
			hoge_pool.New<Animal>();
			hoge_pool.New<Pig>();
			hoge_pool.New<Pig>();
			for (const auto& item : hoge_pool) {
				item.Action();
			}

		}

	};
}