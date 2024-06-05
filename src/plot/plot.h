#ifndef PLOT_H
#define PLOT_H

#include <QWidget>

#include "../controller/controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Plot;
}
QT_END_NAMESPACE

namespace s21 {
class Plot : public QWidget {
  Q_OBJECT

 public:
  explicit Plot(QWidget *parent = nullptr);
  void draw_plot(std::string text, double x_min_num, double x_max_num,
                 double range_x, double range_y);
  ~Plot();

 private slots:
  void on_pushButton_change_diapason_clicked();

 private:
  Ui::Plot *ui;
  Controller controller;
  double xBegin, xEnd, h, X;
  int N;
  std::string temp_str;
  QVector<double> x, y;
};
}  //  namespace s21
#endif  // PLOT_H
