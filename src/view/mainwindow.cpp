#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
  connect(ui->pushButton_div, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_mul, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_sub, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_exp, SIGNAL(clicked()), this, SLOT(math_operations()));
  connect(ui->pushButton_equal, SIGNAL(clicked()), this,
          SLOT(s21_on_pushButton_EQUAL_clicked()));
  connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this,
          SLOT(operations()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(math_operations()));

  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(functions()));
}

void MainWindow::s21_on_pushButton_EQUAL_clicked() {
  try {
    std::string str = ui->input->text().toStdString();
    std::string x = ui->doubleSpinBox_set_x->text().toStdString();
    x[x.find(',')] = '.';
    double answer =
        std::round(controller.Calculate(str, std::stof(x)) * 10000000) /
        10000000;
    ui->label_result->setText(QString::number(answer, 'g', 16));
  } catch (const std::exception &e) {
    QMessageBox::critical(this, "Warning", e.what());
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *e) {
  if (ui->input->text() == "0") {
    ui->input->setText("");
  }
  if (e->key() == Qt::Key_Backspace) {
    on_pushButton_AC_clicked();
  } else if (e->key() == Qt::Key_Plus) {
    ui->input->setText(ui->input->text() + "+");
  } else if (e->key() == Qt::Key_Minus) {
    ui->input->setText(ui->input->text() + "-");
  } else if (e->key() == Qt::Key_Slash) {
    ui->input->setText(ui->input->text() + "/");
  } else if (e->key() == Qt::Key_Asterisk) {
    ui->input->setText(ui->input->text() + "*");
  } else if (e->key() == Qt::Key_Equal || e->key() == Qt::Key_Enter) {
    s21_on_pushButton_EQUAL_clicked();
  } else if (e->key() == Qt::Key_Percent) {
    ui->input->setText(ui->input->text() + "%");
  } else if (e->key() == Qt::Key_Period) {
    ui->input->setText(ui->input->text() + ".");
  } else if (e->key() == Qt::Key_BracketLeft) {
    ui->input->setText(ui->input->text() + "(");
  } else if (e->key() == Qt::Key_BracketRight) {
    ui->input->setText(ui->input->text() + ")");
  } else if (e->key() == Qt::Key_AsciiCircum) {
    ui->input->setText(ui->input->text() + "^");
  } else if (e->key() == Qt::Key_X) {
    ui->input->setText(ui->input->text() + "x");
  }

  if (e->key() == Qt::Key_1) {
    ui->input->setText(ui->input->text() + "1");
  } else if (e->key() == Qt::Key_2) {
    ui->input->setText(ui->input->text() + "2");
  } else if (e->key() == Qt::Key_3) {
    ui->input->setText(ui->input->text() + "3");
  } else if (e->key() == Qt::Key_4) {
    ui->input->setText(ui->input->text() + "4");
  } else if (e->key() == Qt::Key_5) {
    ui->input->setText(ui->input->text() + "5");
  } else if (e->key() == Qt::Key_6) {
    ui->input->setText(ui->input->text() + "6");
  } else if (e->key() == Qt::Key_7) {
    ui->input->setText(ui->input->text() + "7");
  } else if (e->key() == Qt::Key_8) {
    ui->input->setText(ui->input->text() + "8");
  } else if (e->key() == Qt::Key_9) {
    ui->input->setText(ui->input->text() + "9");
  } else if (e->key() == Qt::Key_0) {
    ui->input->setText(ui->input->text() + "0");
  }
}

void MainWindow::functions() {
  if (ui->input->text() == "0") {
    ui->input->setText("");
  }
  QPushButton *button = (QPushButton *)(QObject::sender());
  ui->input->setText(ui->input->text() + button->text() + "(");
}

void MainWindow::digits_numbers() {
  if (ui->input->text() == "0") {
    ui->input->setText("");
  }
  if (ui->input->text().endsWith(")") != true) {
    QPushButton *button = (QPushButton *)(QObject::sender());
    ui->input->setText(ui->input->text() + button->text());
  }
}

void MainWindow::on_pushButton_dot_clicked() {
  ui->input->setText(ui->input->text() + '.');
}

void MainWindow::operations() {
  // ui->input->setText(ui->input->text() + ' ');
  QPushButton *button = (QPushButton *)(QObject::sender());
  std::string str = ui->input->text().toStdString();
  if (!ui->input->text().isEmpty()) {
    try {
      double result =
          std::round(controller.Calculate(
                         str, ui->doubleSpinBox_set_x->text().toDouble()) *
                     10000000) /
          10000000;
      if (button->text() == "+/-") {
        ui->label_result->setText(QString::number(-result));
      } else if (button->text() == '%') {
        ui->label_result->setText(QString::number(result * 0.01));
      }
    } catch (const std::exception &e) {
      QMessageBox::critical(this, "Warning", e.what());
    }
  }
}

void MainWindow::on_pushButton_AC_clicked() {
  ui->input->setText("");
  ui->label_result->setText("");
}

void MainWindow::math_operations() {
  QPushButton *button = (QPushButton *)(QObject::sender());
  if (button->text() == "x") {
    ui->input->setText(ui->input->text() + "*");
  } else if (button->text() == "÷") {
    ui->input->setText(ui->input->text() + "/");
  } else {
    ui->input->setText(ui->input->text() + button->text());
  }
}

void MainWindow::on_pushButton_right_bracket_clicked() {
  ui->input->setText(ui->input->text() + ')');
}

void MainWindow::on_pushButton_left_bracket_clicked() {
  ui->input->setText(ui->input->text() + "(");
}

void MainWindow::on_pushButton_x_clicked() {
  if (ui->input->text() == "0") {
    ui->input->setText("");
  }
  ui->input->setText(ui->input->text() + "x");
}

void MainWindow::on_pushButton_make_plot_clicked() {
  if (ui->input->text() != "") {
    std::string str = ui->input->text().toStdString();
    window2.setWindowTitle("График");
    window2.draw_plot(str, -10, 10, -10, 10);
    window2.show();
  }
}
