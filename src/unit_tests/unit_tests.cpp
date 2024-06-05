//
// Created by Timofey on 05.02.2024.
//

#include <gtest/gtest.h>

#include "../model/model.h"

TEST(SmartCalculator, TestOperation) {
  std::string str = "4+9+7+9";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_EQ(res, 29);
}

TEST(SmartCalculator, TestOperation1) {
  std::string str = "4+9/2*67787";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_EQ(res, 305045.5);
}

TEST(SmartCalculator, TestFunc) {
  std::string str = "(4^acos(2/4))";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 4.27047);
}

TEST(SmartCalculator, TestFunc1) {
  std::string str = "(tan(2*2))";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 1.1578213);
}

TEST(SmartCalculator, TestFunc2) {
  std::string str = "(4^acos(2/4)/tan(2*2))";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 3.6883678);
}

TEST(SmartCalculator, TestFunc3) {
  std::string str = "(4^acos(2/4)/tan(2*2)/5^acos(2/4))";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 0.68371409);
}

TEST(SmartCalculator, TestFunc4) {
  std::string str = "(4^acos(2/4)/tan(2*2)/5^acos(2/4)/tan(tan(tan(2*2))))";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, -0.58934796);
}

TEST(SmartCalculator, TestFunc5) {
  std::string str = "3^cos(0.5)/5";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 0.52449733);
}

TEST(SmartCalculator, TestFunc6) {
  std::string str = "3^cos(0.5)/sqrt(25)";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 0.52449733);
}

TEST(SmartCalculator, TestFunc7) {
  std::string str = "log(10)";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 1);
}

TEST(SmartCalculator, TestFunc8) {
  std::string str = "1+2*(3^sin(0.4))^3*2+1";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 16.436413);
}

TEST(SmartCalculator, TestFunc9) {
  std::string str = "ln(10)";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 2.3025851);
}

TEST(SmartCalculator, TestFunc10) {
  std::string str = "1+2*3^sin(0.4)^3*2+1";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 6.2681131);
}

TEST(SmartCalculator, TestFunc11) {
  std::string str = "1+2*3^sin(0.4)^56*2+1";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 6);
}

TEST(SmartCalculator, TestFunc12) {
  std::string str = "acos(-0.5)+asin(-0.5)+atan(0.1)*cos(30)*sin(20)*tan(45)";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 1.5935309);
}

TEST(SmartCalculator, TestFunc13) {
  std::string str = "(-5)^(-4)";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 0.0016);
}

TEST(SmartCalculator, TestFunc14) {
  std::string str = "-4+5";
  s21::Model a;
  a.Calculator(str, 0.0);
  double res = a.GetAnswer();
  EXPECT_FLOAT_EQ(res, 1);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
