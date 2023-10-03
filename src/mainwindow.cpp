#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton_00, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_01, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_02, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_03, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_04, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_05, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_06, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_07, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_08, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_09, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_open, SIGNAL(clicked()), this, SLOT(digits_numbers()));
  connect(ui->pushButton_close, SIGNAL(clicked()), this,
          SLOT(digits_numbers()));
  connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(digits_math()));
  connect(ui->pushButton_sun, SIGNAL(clicked()), this, SLOT(digits_math()));
  connect(ui->pushButton_del, SIGNAL(clicked()), this, SLOT(digits_math()));
  connect(ui->pushButton_mun, SIGNAL(clicked()), this, SLOT(digits_math()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_x2, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_xy, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this,
          SLOT(digits_trigonomrtia()));
  connect(ui->pushButton_ravno, SIGNAL(clicked()), this, SLOT(result()));
  connect(ui->pushButton_graf, SIGNAL(clicked()), this, SLOT(graf()));
  connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(uno()));
  connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(AC()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::AC() { ui->result_show->setText(""); }

void MainWindow::uno() {
  ui->result_show->setText(ui->result_show->text() + "*(-1)");
  double step = 0.0001;
  int error = 0;
  double res_calk = 0.0;
  QString add;
  add = ui->result_show->text();
  QByteArray add1 = add.toUtf8();
  char *a = add1.data();
  res_calk = pol(a, x_arg, &error, step);
  QString ress = QString::number(res_calk, 'g', 6);
  ui->result_show->setText(ress);
}
void MainWindow::digits_numbers() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::digits_math() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == '+') {
    ui->result_show->setText(ui->result_show->text() + "+");
  } else if (button->text() == '-') {
    ui->result_show->setText(ui->result_show->text() + "-");
  } else if (button->text() == 'x') {
    ui->result_show->setText(ui->result_show->text() + "*");
  } else if (button->text() == '/') {
    ui->result_show->setText(ui->result_show->text() + "/");
  }
}

void MainWindow::digits_trigonomrtia() {
  QPushButton *button = (QPushButton *)sender();
  if (button->text() == "sin") {
    ui->result_show->setText(ui->result_show->text() + "sin");
  } else if (button->text() == "cos") {
    ui->result_show->setText(ui->result_show->text() + "cos");
  } else if (button->text() == "tan") {
    ui->result_show->setText(ui->result_show->text() + "tan");
  } else if (button->text() == "asin") {
    ui->result_show->setText(ui->result_show->text() + "asin");
  } else if (button->text() == "acos") {
    ui->result_show->setText(ui->result_show->text() + "acos");
  } else if (button->text() == "atan") {
    ui->result_show->setText(ui->result_show->text() + "atan");
  } else if (button->text() == "X") {
    ui->result_show->setText(ui->result_show->text() + "x");
  } else if (button->text() == "x^2") {
    ui->result_show->setText(ui->result_show->text() + "^2");
  } else if (button->text() == "x^y") {
    ui->result_show->setText(ui->result_show->text() + "^");
  } else if (button->text() == "sqrt") {
    ui->result_show->setText(ui->result_show->text() + "sqrt");
  } else if (button->text() == "ln") {
    ui->result_show->setText(ui->result_show->text() + "ln");
  } else if (button->text() == "log") {
    ui->result_show->setText(ui->result_show->text() + "log10");
  } else if (button->text() == "mod") {
    ui->result_show->setText(ui->result_show->text() + "mod");
  }
}

void MainWindow::on_pushButton_tochka_clicked() {
  ui->result_show->setText(ui->result_show->text() + ".");
}

void MainWindow::result() {
  double step = 0.000001;
  double res_calk = 0.0;
  QString add;
  add = ui->result_show->text();
  QByteArray add1 = add.toUtf8();
  char *a = add1.data();
  int error = 0;
  error = check_true_str(a);
  if (error == 0) {
    res_calk = pol(a, x_arg, &error, step);
    if (error == 0) {
      QString ress = QString::number(res_calk, 'g', 6);
      ui->result_show->setText(ress);
    }
  }
  if (error == 3) {
    ui->result_show->setText("Invalid input:bracket_open>bracket_close");
  } else if (error == 4) {
    ui->result_show->setText("Invalid input:bracket_open<bracket_close");
  } else if (error == 5) {
    ui->result_show->setText("Invalid input:sign_after_sign");
  } else if (error == 6) {
    ui->result_show->setText("Invalid input:sign_after_bracket");
  } else if (error == 7) {
    ui->result_show->setText("Invalid input:dot_after_dot");
  } else if (error == 8) {
    ui->result_show->setText("Invalid input:X_after_X");
  } else if (error == 9) {
    ui->result_show->setText("nan");
  } else if (error == 10) {
    ui->result_show->setText("inf");
  } else if (error != 0) {
    ui->result_show->setText("Invalid input");
  }
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1) { x_arg = arg1; }

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg2) { xBegin = arg2; }

void MainWindow::on_doubleSpinBox_3_valueChanged(double arg3) {
  xEnd = arg3 + h;
}

void MainWindow::graf() {
  double Y = 0.0;
  int error = 0;
  double step = 0.001;
  QString add;
  add = ui->result_show->text();
  QByteArray add1 = add.toUtf8();
  char *a = add1.data();
  int count = 0;
  ui->widget->xAxis->setRange(-(fabs(xBegin)), (fabs(xEnd)));
  ui->widget->yAxis->setRange(-Y_O, Y_O);
  if ((fabs(xBegin) + fabs(xEnd)) >= 2000) {
    step = 0.01;
    if ((fabs(xBegin) + fabs(xEnd)) > 20000) {
      step = 0.1;
    }
  }
  for (X = xBegin; X <= xEnd; X = X + step) {
    for (; X <= xEnd; X = X + step) {
      pol(a, X, &error, step);
      if (error != 0) {
        while (error != 0 && X <= xEnd) {
          pol(a, X, &error, step);
          X = X + step;
        }
        break;
      } else {
        Y = pol(a, X, &error, step);
        x.push_back(X);
        y.push_back(Y);
      }
    }
    ui->widget->addGraph();
    ui->widget->graph(count)->addData(x, y);
    count++;
    x.clear();
    y.clear();
  }
  ui->widget->replot();
}

void MainWindow::on_doubleSpinBox_5_valueChanged(double arg4) { Y_O = arg4; }
