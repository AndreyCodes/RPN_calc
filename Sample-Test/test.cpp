#include "pch.h"
#include"../RPN/Calc.hpp"

TEST(SimpleCase, Test1)
{
	EXPECT_EQ(Calc::compute("1 2 3 + +"), 6);
}
TEST(SimpleCase, Test2)
{
	EXPECT_EQ(Calc::compute("1 2 3 - -"), 2);// 
}
TEST(SimpleCase, Test3)
{
	EXPECT_EQ(Calc::compute("1 2 - 3 -"), -4);
}
TEST(SimpleCase, Test4)
{
	EXPECT_EQ(Calc::compute("-3 -2 * 2 +"), 8);
}
TEST(SimpleCase, Test5)
{
	EXPECT_EQ(Calc::compute("1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 + 1 -"), 54);
}
TEST(SimpleCase, Test6)
{
	EXPECT_EQ(Calc::compute("2 7 * 1 6 + /"), 2);
}

TEST(ExtreameCase, Test1)
{
	EXPECT_EQ(Calc::compute("1 1 /"), 1);
}
TEST(ExtreameCase, Test2)
{
	EXPECT_EQ(Calc::compute("-1 -1 /"), 1);
}
TEST(ExtreameCase, Test3)
{
	EXPECT_EQ(Calc::compute("-1 1 /"), -1);
}
TEST(ExtreameCase, Test4)
{
	EXPECT_EQ(Calc::compute("0 1 *"), 0);
}
TEST(ExtreameCase, Test5)
{
	EXPECT_EQ(Calc::compute("1 1 /"), 1);
}
TEST(ExtreameCase, Test6)
{
	EXPECT_EQ(Calc::compute("0 0 *"), 0);
}
TEST(ExtreameCase, Test7)
{
	EXPECT_EQ(Calc::compute("-1 -1 *"), 1);
}
