#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>

#include "../controller/controller.h"
#include "../model/model.h"
#include "../plot/plot.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 private:
  Ui::MainWindow *ui;
  s21::Plot window2;
  s21::Controller controller;

 public:
  // Controller *controller;
  MainWindow(s21::Controller c) : controller(c) {}
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 protected:
  void keyPressEvent(QKeyEvent *e) override;

 private slots:
  void digits_numbers();
  void on_pushButton_dot_clicked();
  void operations();
  void on_pushButton_AC_clicked();
  void s21_on_pushButton_EQUAL_clicked();
  void math_operations();
  void functions();
  void on_pushButton_right_bracket_clicked();
  void on_pushButton_left_bracket_clicked();
  void on_pushButton_x_clicked();
  void on_pushButton_make_plot_clicked();
};

#endif  // MAINWINDOW_H
