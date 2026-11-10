// UnitTest_08_1.cpp
// Тестування функцій лабораторної роботи 8.1 (Варіант 16)
#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "Lab_08_1_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest081
{
    TEST_CLASS(UnitTest081)
    {
    public:
        // ---------------------------------------------------------------------
        // Тест 1: Перевірка функції Count (підрахунок груп виду 'n?o')
        // ---------------------------------------------------------------------
        TEST_METHOD(TestMethod_Count)
        {
            char str1[] = "nao and nbo test n!o";
            // Входження: "nao", "nbo", "n!o" -> разом 3
            Assert::AreEqual(3, Count(str1));

            char str2[] = "hello world no match";
            // Немає трійок з будь-яким проміжним символом між n та o
            Assert::AreEqual(0, Count(str2));

            char str3[] = "n o";
            // Трійка 'n', пробіл, 'o' -> рівно 1
            Assert::AreEqual(1, Count(str3));
        }

        // ---------------------------------------------------------------------
        // Тест 2: Перевірка функції Change (заміна кожної трійки 'n?o' парою зірочок '**')
        // ---------------------------------------------------------------------
        TEST_METHOD(TestMethod_Change)
        {
            char str1[100] = "start nao middle nbo end";
            char* res = Change(str1);

            // Очікуваний рядок після заміни
            Assert::AreEqual("start ** middle ** end", res);
            Assert::AreEqual("start ** middle ** end", str1);

            char str2[100] = "nxo";
            Change(str2);
            Assert::AreEqual("**", str2);
        }
    };
}
