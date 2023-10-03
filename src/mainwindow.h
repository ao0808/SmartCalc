#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

extern "C" {
#include "calk.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  double xBegin = 0;
  double xEnd = 0;
  double h = 0;
  double X = 0;
  double x_arg = 0;
  double y_1 = 0;
  double Y_O = 0;
  int N;

  QVector<double> x, y;

 private slots:
  void digits_numbers();
  void digits_math();
  void on_pushButton_tochka_clicked();
  void digits_trigonomrtia();
  void result();
  void graf();
  void uno();
  void AC();
  void on_doubleSpinBox_valueChanged(double arg1);
  void on_doubleSpinBox_2_valueChanged(double arg2);
  void on_doubleSpinBox_3_valueChanged(double arg3);
  void on_doubleSpinBox_5_valueChanged(double arg4);
};
#endif  // MAINWINDOW_H
