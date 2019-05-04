#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QTableWidget>

#include "Matrix.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_spinBox_rowA_valueChanged(int arg1);
    void on_spinBox_colA_valueChanged(int arg1);

    void on_spinBox_rowB_valueChanged(int arg1);
    void on_spinBox_colB_valueChanged(int arg1);

    void on_pushButton_detA_clicked();
    void on_pushButton_detB_clicked();

    void on_pushButton_transpA_clicked();
    void on_pushButton_transpB_clicked();

    void on_pushButton_multAValA_clicked();

    void on_pushButton_multBValB_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_mult_clicked();

    void on_pushButton_copyInA_clicked();

    void on_pushButton_copyInB_clicked();

private:
    Ui::MainWindow *ui;

    Matrix a;
    Matrix b;
};

#endif // MAINWINDOW_H
