#include "model.h"

#include <cmath>
#include <stdexcept>

void s21::Model::Validator(std::string& str) {
  if (str.empty()) {
    throw std::logic_error("empty");
  }
  int left_bracket = 0;
  int right_bracket = 0;

  for (int i = 0; i < (int)str.size(); ++i) {
    if (IsOperator(str[i])) {
      if (IsOperator(str[i + 1]) || i == (int)str.size() - 1 ||
          (i == 0 && str[i] != '-' && str[i] != '+')) {
        throw std::logic_error(
            "два оператора подряд или оператор стоит последним в "
            "строке или первым символом является оператор, кроме минуса и "
            "плюса");
      }
    } else if (str[i] == '.') {
      if (i == (int)str.size() - 1 || i == 0 || !isdigit(str[i + 1]) ||
          !isdigit(str[i - 1])) {
        throw std::logic_error(
            "точка стоит первой и последней или после точки не идет число или "
            "перед точкой не стоит число");
      }
    } else if (str[i] == '(') {
      if (i == (int)str.size() - 1 || str[i + 1] == ')') {
        throw std::logic_error(
            "открывающая скобка стоит последней или после открывающей скобки "
            "сразу идет закрывающая скобка");
      }

      ++left_bracket;
    } else if (str[i] == ')') {
      ++right_bracket;
    }
  }

  if (left_bracket != right_bracket) {
    throw std::logic_error(
        "количество открывающих и закрывающих скобок не равно");
  }
}

bool s21::Model::IsOperator(char x) {
  return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

void s21::Model::Calculator(std::string& str, double x) {
  try {
    Validator(str);
  } catch (...) {
    throw std::logic_error("ошибка в выражении");
  }
  std::deque<double> result;
  ToPostfix(str);
  while (!this->numbers.empty()) {
    if (this->numbers.front().token == IsNotFunction) {
      result.push_back(this->numbers.front().double_value);
    } else if (this->numbers.front().token == X) {
      result.push_back(x);
    } else {
      int token = this->numbers.front().token;
      double num = result.back();
      result.pop_back();
      if (token == UNARY_MINUS) {
        result.push_back(-num);
      } else if (token == UNARY_PLUS) {
        result.push_back(num);
      } else if (token == COS) {
        result.push_back(cos(num));
      } else if (token == SIN) {
        result.push_back(sin(num));
      } else if (token == TAN) {
        result.push_back(tan(num));
      } else if (token == ACOS) {
        result.push_back(acos(num));
      } else if (token == ASIN) {
        result.push_back(asin(num));
      } else if (token == ATAN) {
        result.push_back(atan(num));
      } else if (token == SQRT) {
        result.push_back(sqrt(num));
      } else if (token == LN) {
        result.push_back(log(num));
      } else if (token == LOG) {
        result.push_back(log10(num));
      } else {
        double right = num;
        double left = result.back();
        result.pop_back();
        if (this->numbers.front().token == MINUS) {
          result.push_back(left - right);
        } else if (this->numbers.front().token == PLUS) {
          result.push_back(left + right);
        } else if (this->numbers.front().token == POW) {
          result.push_back(pow(left, right));
        } else if (this->numbers.front().token == MOD) {
          if (abs(right - int(right)) < 0.00000001 &&
              abs(left - int(left)) < 0.00000001) {
            result.push_back((int)left % (int)right);
          } else {
            throw std::logic_error(
                "mod можно использовать только с целыми числами");
          }
        } else if (this->numbers.front().token == MUL) {
          result.push_back(left * right);
        } else if (this->numbers.front().token == DIV) {
          result.push_back(left / right);
        }
      }
    }
    this->numbers.pop_front();
  }
  this->answer_ = result.back();
}

//  возвращает double-число, сам сдвигает индекс
double s21::Model::GetNumber(std::string& str, int* pos) {
  std::string result = "";

  for (; *pos < (int)str.size(); ++*pos) {
    if (*pos == 0 || str[*pos - 1] == '(') {
      if (isdigit(str[*pos]) || str[*pos] == '.' || str[*pos] == '+' ||
          str[*pos] == '-') {
        result += str[*pos];
      }
    } else if (isdigit(str[*pos]) || str[*pos] == '.') {
      result += str[*pos];
    } else {
      --*pos;
      break;
    }
  }
  if (result.empty()) return -1;
  return std::stof(result);
}

s21::symbol s21::Model::IdentifyFunction(std::string& str, int* pos) {
  symbol ExitCode;
  if (str[*pos] == 'c' && str[*pos + 1] == 'o' && str[*pos + 2] == 's') {
    ExitCode.token = COS;
    *pos += 2;

  } else if (str[*pos] == 's') {
    if (str[*pos + 1] == 'i' && str[*pos + 2] == 'n') {
      ExitCode.token = SIN;
      *pos += 2;
    } else if (str[*pos + 1] == 'q' && str[*pos + 2] == 'r' &&
               str[*pos + 3] == 't') {
      ExitCode.token = SQRT;
      *pos += 3;
    }
  } else if (str[*pos] == 't' && str[*pos + 1] == 'a' && str[*pos + 2] == 'n') {
    ExitCode.token = TAN;
    *pos += 2;
  } else if (str[*pos] == 'a') {
    if (str[*pos + 1] == 'c' && str[*pos + 2] == 'o' && str[*pos + 3] == 's') {
      ExitCode.token = ACOS;
    } else if (str[*pos + 1] == 's' && str[*pos + 2] == 'i' &&
               str[*pos + 3] == 'n') {
      ExitCode.token = ASIN;
    } else if (str[*pos + 1] == 't' && str[*pos + 2] == 'a' &&
               str[*pos + 3] == 'n') {
      ExitCode.token = ATAN;
    }
    *pos += 3;
  } else if (str[*pos] == 'l' && str[*pos + 1] == 'n') {
    ExitCode.token = LN;
    *pos += 1;
  } else if (str[*pos] == 'l' && str[*pos + 1] == 'o' && str[*pos + 2] == 'g') {
    ExitCode.token = LOG;
    *pos += 2;
  }
  ExitCode.priority = 6;
  return ExitCode;
}

void s21::Model::ToPostfix(std::string& str) {
  for (int i = 0; i < (int)str.size(); ++i) {
    if (isdigit(str[i])) {
      s21::symbol tmp;
      tmp.double_value = GetNumber(str, &i);
      this->numbers.push_back(tmp);
    } else if (str[i] == '(') {
      s21::symbol tmp;
      tmp.token = LEFT_BRACKET;
      tmp.priority = -1;
      this->operators.push_back(tmp);
    } else if (str[i] == 'x') {
      s21::symbol tmp;
      tmp.token = X;
      this->numbers.push_back(tmp);
    } else if (IsOperator(str[i]) ||
               (isalpha(str[i]) && IsMod(str, &i).token == MOD)) {
      symbol Operator = IdentifyOperator(str, &i);
      if (Operator.priority == 0) {
        Operator.priority = 2;
        Operator.token = MOD;
      }
      while (!this->operators.empty() &&
             (this->operators.back().priority > Operator.priority ||
              (this->operators.back().priority == Operator.priority &&
               this->operators.back().token != POW))) {
        this->numbers.push_back(this->operators.back());
        this->operators.pop_back();
      }
      this->operators.push_back(Operator);
    } else if (isalpha(str[i])) {
      this->operators.push_back(IdentifyFunction(str, &i));
    } else if (str[i] == ')') {
      while (!this->operators.empty() &&
             this->operators.back().token != LEFT_BRACKET) {
        this->numbers.push_back(this->operators.back());
        this->operators.pop_back();
      }
      this->operators.pop_back();
      if (!this->operators.empty() && this->operators.back().priority == 6) {
        this->numbers.push_back(this->operators.back());
        this->operators.pop_back();
      }
    }
  }

  while (!this->operators.empty()) {
    this->numbers.push_back(this->operators.back());
    this->operators.pop_back();
  }
}

s21::symbol s21::Model::IdentifyOperator(std::string& str, int* pos) {
  symbol result;
  if (str[*pos] == '+') {
    if (*pos == 0 ||
        (*pos > 0 && !isdigit(str[*pos - 1]) && str[*pos - 1] != ')')) {
      result.token = UNARY_PLUS;
      result.priority = 4;
    } else {
      result.token = PLUS;
      result.priority = 1;
    }
  } else if (str[*pos] == '-') {
    if (*pos == 0 || (*pos > 0 && !isdigit(str[*pos - 1]))) {
      result.token = UNARY_MINUS;
      result.priority = 4;
    } else {
      result.token = MINUS;
      result.priority = 1;
    }
  } else if (str[*pos] == '*') {
    result.token = MUL;
    result.priority = 3;
  } else if (str[*pos] == '/') {
    result.token = DIV;
    result.priority = 3;
  } else if (str[*pos] == '^') {
    result.token = POW;
    result.priority = 5;
  }
  return result;
}

s21::symbol s21::Model::IsMod(std::string& str, int* pos) {
  symbol result;
  if (str[*pos] == 'm' && str[*pos + 1] == 'o' && str[*pos + 2] == 'd') {
    result.token = MOD;
    result.priority = 2;
    *pos += 2;
  }
  return result;
}

std::string s21::Model::find_operator(symbol Operator) {
  std::string result;
  if (Operator.token == COS) {
    result = "cos";
  } else if (Operator.token == SIN) {
    result = "sin";
  } else if (Operator.token == TAN) {
    result = "tan";
  } else if (Operator.token == ACOS) {
    result = "acos";
  } else if (Operator.token == ASIN) {
    result = "asin";
  } else if (Operator.token == ATAN) {
    result = "atan";
  } else if (Operator.token == SQRT) {
    result = "sqrt";
  } else if (Operator.token == LN) {
    result = "ln";
  } else if (Operator.token == LOG) {
    result = "log";
  } else if (Operator.token == X) {
    result = "x";
  } else if (Operator.token == MINUS) {
    result = "-";
  } else if (Operator.token == PLUS) {
    result = "+";
  } else if (Operator.token == POW) {
    result = "^";
  } else if (Operator.token == MOD) {
    result = "mod";
  } else if (Operator.token == LEFT_BRACKET) {
    result = "(";
  } else if (Operator.token == RIGHT_BRACKET) {
    result = ")";
  } else if (Operator.token == MUL) {
    result = "*";
  } else if (Operator.token == DIV) {
    result = "/";
  } else if (Operator.token == UNARY_MINUS) {
    result = "u-";
  } else if (Operator.token == UNARY_PLUS) {
    result = "u+";
  }
  return result;
}

double s21::Model::GetAnswer() const { return this->answer_; }
