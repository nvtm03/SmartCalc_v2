#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/model.h"

namespace s21 {
class Controller {
 private:
  s21::Model model_;

 public:
  Controller() {}
  ~Controller() {}

  double Calculate(std::string& str, double x);
};
}  // namespace s21

#endif  // CONTROLLER_H
