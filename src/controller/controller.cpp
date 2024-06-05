#include "controller.h"

double s21::Controller::Calculate(std::string& str, double x) {
  this->model_.Calculator(str, x);
  return this->model_.GetAnswer();
}
