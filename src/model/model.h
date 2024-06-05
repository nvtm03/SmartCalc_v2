#ifndef MODEL_H
#define MODEL_H

#include <deque>
#include <string>

namespace s21 {
enum token {
  COS = 1,
  SIN = 2,
  TAN = 3,
  ACOS = 4,
  ASIN = 5,
  ATAN = 6,
  SQRT = 7,
  LN = 8,
  LOG = 9,
  IsNotFunction = 10,
  X = 11,
  MINUS = 12,
  PLUS = 13,
  POW = 14,
  MOD = 15,
  LEFT_BRACKET = 16,
  RIGHT_BRACKET = 17,
  MUL = 18,  //  multiplication
  DIV = 19,  //  division
  UNARY_MINUS = 20,
  UNARY_PLUS = 21
};

typedef struct symbol {
  int token = IsNotFunction;
  int priority = 0;
  double double_value = 0.0;
} symbol;

class Model {
 private:
  double answer_;
  std::deque<symbol> operators;
  std::deque<symbol> numbers;
  symbol IdentifyFunction(std::string& str, int* pos);
  symbol IdentifyOperator(std::string& str, int* pos);
  bool IsOperator(char symbol);
  symbol IsMod(std::string& str, int* pos);
  double GetNumber(std::string& str, int* pos);
  std::string find_operator(symbol Operator);
  void ToPostfix(std::string& str);
  void Validator(std::string& str);

 public:
  Model() {}
  ~Model() {}
  void Calculator(std::string& str, double x);
  double GetAnswer() const;
};
}  //  namespace s21

#endif  // MODEL_H
