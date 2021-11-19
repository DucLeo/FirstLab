#include "pch.h"
#include "CppUnitTest.h"
#include "../First Lab/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_FirstLab
{
	TEST_CLASS(UnitTest_FirstLab)
	{
	public:

		TEST_METHOD(Test_at)
		{
			List list;
			bool check;

			//When list is empty
			check = 0;
			try
			{
				list.at(0);
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			for (int i = 0; i < 5; i++) list.push_back(10 * i);
			//Current list: 0 10 20 30 40
			Assert::AreEqual(list.at(0), 0);
			Assert::AreEqual(list.at(1), 10);
			Assert::AreEqual(list.at(2), 20);
			Assert::AreEqual(list.at(3), 30);
			Assert::AreEqual(list.at(4), 40);

			//When index < 0
			check = 0;
			try
			{
				list.at(-1);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			//When index > size - 1
			check = 0;
			try
			{
				list.at(5);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);
		}

		TEST_METHOD(Test_get_size)
		{
			List list;

			//list is empty
			Assert::IsTrue(list.get_size() == 0);

			for (int i = 0; i < 10; i++) list.push_back(i);
			//Current list: 10 elements from 0 to 9
			Assert::IsTrue(list.get_size() == 10);
		}

		TEST_METHOD(Test_push_back)
		{
			List list;

			list.push_back(1);
			//Current list: 1
			Assert::AreEqual(list.at(0), 1);
			Assert::IsTrue(list.get_size() == 1);

			list.push_back(5);
			list.push_back(9);
			//Current list: 1 5 9
			Assert::AreEqual(list.at(0), 1);
			Assert::AreEqual(list.at(1), 5);
			Assert::AreEqual(list.at(2), 9);
			Assert::IsTrue(list.get_size() == 3);
		}

		TEST_METHOD(Test_push_front)
		{
			List list;

			list.push_front(1);
			//Current list: 1
			Assert::AreEqual(list.at(0), 1);
			Assert::IsTrue(list.get_size() == 1);

			list.push_front(5);
			list.push_front(9);
			//Current list: 9 5 1
			Assert::AreEqual(list.at(0), 9);
			Assert::AreEqual(list.at(1), 5);
			Assert::AreEqual(list.at(2), 1);
			Assert::IsTrue(list.get_size() == 3);
		}

		TEST_METHOD(Test_pop_back)
		{
			List list;
			bool check;

			//When list is empty
			check = 0;
			try
			{
				list.pop_back();
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			list.push_back(100);
			//Current list: 100

			list.pop_back();
			//List is empty

			Assert::IsTrue(list.isEmpty());
			Assert::IsTrue(list.get_size() == 0);

			for (int i = 1; i < 4; i++) list.push_back(3*i);
			//Current list: 3 6 9

			list.pop_back();
			//Current list: 3 6

			Assert::AreEqual(list.at(0), 3);
			Assert::AreEqual(list.at(1), 6);
			Assert::IsTrue(list.get_size() == 2);
		
		}

		TEST_METHOD(Test_pop_front)
		{
			List list;
			bool check;

			//When list is empty
			check = 0;
			try
			{
				list.pop_front();
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			list.push_back(100);
			//Current list: 100

			list.pop_back();
			//List is empty

			Assert::IsTrue(list.isEmpty());
			Assert::IsTrue(list.get_size() == 0);

			for (int i = 1; i < 4; i++) list.push_back(3 * i);
			//Current list: 3 6 9

			list.pop_front();
			//Current list: 6 9

			Assert::AreEqual(list.at(0), 6);
			Assert::AreEqual(list.at(1), 9);
			Assert::IsTrue(list.get_size() == 2);

		}

		TEST_METHOD(Test_insert)
		{
			List list;
			bool check;
			
			//When list is empty
			check = 0;
			try
			{
				list.insert(100, -1);
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);
			
			for (int i = 1; i < 4; i++) list.push_back(3 * i);
			//Current list: 3 6 9, size = 3
			//When index < 0
			check = 0;
			try
			{
				list.insert(100, -1);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			//When index > size -1
			check = 0;
			try
			{
				list.insert(100, 3);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);
			
			//When index = 0
			list.insert(1, 0);
			//Current list: 1 3 6 9

			Assert::AreEqual(list.at(0), 1);
			Assert::AreEqual(list.at(1), 3);
			Assert::AreEqual(list.at(2), 6);
			Assert::AreEqual(list.at(3), 9);
			Assert::IsTrue(list.get_size() == 4);

			//When 0 < index =< size -1
			list.insert(12, 3);
			//Current list: 1 3 6 12 9

			Assert::AreEqual(list.at(0), 1);
			Assert::AreEqual(list.at(1), 3);
			Assert::AreEqual(list.at(2), 6);
			Assert::AreEqual(list.at(3), 12);
			Assert::AreEqual(list.at(4), 9);
			Assert::IsTrue(list.get_size() == 5);
			
		}

		TEST_METHOD(Test_remove)
		{
			List list;
			bool check;

			//When list is empty
			check = 0;
			try
			{
				list.remove(0);
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			for (int i = 1; i < 4; i++) list.push_back(3 * i);
			//Current list: 3 6 9, size = 3
			//When index < 0
			check = 0;
			try
			{
				list.remove(-1);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			//When index > size - 1
			check = 0;
			try
			{
				list.remove(3);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			//When index = 0
			list.remove(0);
			//Current list: 6 9, size = 2
			
			Assert::AreEqual(list.at(0), 6);
			Assert::AreEqual(list.at(1), 9);
			Assert::IsTrue(list.get_size() == 2);

			//When index = size - 1
			list.remove(1);
			//Current list: 6 , size = 1

			Assert::AreEqual(list.at(0), 6);
			Assert::IsTrue(list.get_size() == 1);

			list.push_back(12);
			list.push_back(18);
			//Current list: 6 12 18 , size = 3
			//When 0 < index =< size -1
			list.remove(1);
			//Current list: 6 18 , size = 2

			Assert::AreEqual(list.at(0), 6);
			Assert::AreEqual(list.at(1), 18);
			Assert::IsTrue(list.get_size() == 2);
		}

		TEST_METHOD(Test_set)
		{
			List list;
			bool check;

			//When list is empty
			check = 0;
			try
			{
				list.set(0,100);
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			for (int i = 1; i < 4; i++) list.push_back(3 * i);
			//Current list: 3 6 9, size = 3
			//When index < 0
			check = 0;
			try
			{
				list.set(-1, 100);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			//When index > size - 1
			check = 0;
			try
			{
				list.set(3, 100);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			//When 0 < index =< size - 1
			list.set(2, 100);
			//Current list: 3 6 100, size = 3

			Assert::AreEqual(list.at(0), 3);
			Assert::AreEqual(list.at(1), 6);
			Assert::AreEqual(list.at(2), 100);
			Assert::IsTrue(list.get_size() == 3);


		}

		TEST_METHOD(Test_clear)
		{
			List list;

			for (int i = 0; i < 10; i++) list.push_back(i);
			//Current list: 0 1 2 3 4 5 6 7 8 9

			list.clear();
			//list is empty

			Assert::IsTrue(list.isEmpty());
			Assert::IsTrue(list.get_size() == 0);
		}

		TEST_METHOD(Test_isEmpty)
		{
			List list;

			//When list1 is empty
			Assert::IsTrue(list.isEmpty());
			Assert::IsTrue(list.get_size() == 0);

			list.push_back(100);
			//Current list: 100, is not empty

			Assert::IsFalse(list.isEmpty());
			Assert::IsFalse(list.get_size() == 0);
		}

		TEST_METHOD(Test_find_first)
		{
			List list1, list2;
			bool check;

			//When list1 is empty
			check = 0;
			try
			{
				list1.find_first(list2);
			}
			catch (std::logic_error)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			for (int i = 1; i < 4; i++) list1.push_back(i);
			for (int i = 1; i < 4; i++) list1.push_back(i);
			for (int i = 1; i < 4; i++) list1.push_back(i);
			//Current list1: 1 2 3 1 2 3 1 2 3

			list2.push_back(3);
			list2.push_back(1);
			list2.push_back(2);
			//Current list2: 3 1 2

			//The first occurrence of list2 in the list1 = 2

			Assert::AreEqual(list1.find_first(list2), 2);

			//The list2 does not contain this list1.
			check = 0;
			try
			{
				list2.find_first(list1);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

			list2.set(2, 1);
			//Current list2: 3 1 1
			//The list1 does not contain this list2.

			check = 0;
			try
			{
				list1.find_first(list2);
			}
			catch (std::invalid_argument)
			{
				check = 1;
			}
			Assert::IsTrue(check);

		}
	};
}