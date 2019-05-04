#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "extrafunction.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a.setSize(1, 1);
    b.setSize(1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_spinBox_rowA_valueChanged(int arg1)
{
    SetRowCount(ui->tableWidget_A, arg1);
    a.setRows(arg1);
}

void MainWindow::on_spinBox_colA_valueChanged(int arg1)
{
    SetColumnCount(ui->tableWidget_A, arg1);
    a.setColumns(arg1);
}

void MainWindow::on_spinBox_rowB_valueChanged(int arg1)
{
    SetRowCount(ui->tableWidget_B, arg1);
    b.setRows(arg1);

}

void MainWindow::on_spinBox_colB_valueChanged(int arg1)
{
    SetColumnCount(ui->tableWidget_B, arg1);
    b.setColumns(arg1);
}


void MainWindow::on_pushButton_detA_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_A, a);
        ui->label_detValue->setNum(a.det());
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }

}

void MainWindow::on_pushButton_detB_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_B, b);
        ui->label_detValue->setNum(b.det());
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_transpA_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_A, a);
        a.transp();
        MatrixToTable(a, ui->tableWidget_A);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_transpB_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_B, b);
        b.transp();
        MatrixToTable(b, ui->tableWidget_B);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_multAValA_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_A, a);
        Matrix tmp(a * ReadLineEdit(ui->lineEdit_valA));
        MatrixToTable(tmp, ui->tableWidget_A);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_multBValB_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_B, b);
        Matrix tmp(b * ReadLineEdit(ui->lineEdit_valB));
        MatrixToTable(tmp, ui->tableWidget_B);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_add_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_A, a);
        TableToMatrix(ui->tableWidget_B, b);
        Matrix tmp(a + b);

        SetRowCount(ui->tableWidget_Res, a.rows());
        SetColumnCount(ui->tableWidget_Res, a.columns());

        MatrixToTable(tmp, ui->tableWidget_Res);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_sub_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_A, a);
        TableToMatrix(ui->tableWidget_B, b);
        Matrix tmp(a - b);

        SetRowCount(ui->tableWidget_Res, a.rows());
        SetColumnCount(ui->tableWidget_Res, a.columns());

        MatrixToTable(tmp, ui->tableWidget_Res);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_mult_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_A, a);
        TableToMatrix(ui->tableWidget_B, b);
        Matrix tmp(a * b);

        SetRowCount(ui->tableWidget_Res, a.columns());
        SetColumnCount(ui->tableWidget_Res, b.rows());

        MatrixToTable(tmp, ui->tableWidget_Res);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_copyInA_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_Res, a);
        MatrixToTable(a, ui->tableWidget_A);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}

void MainWindow::on_pushButton_copyInB_clicked()
{
    try
    {
        TableToMatrix(ui->tableWidget_Res, b);
        MatrixToTable(b, ui->tableWidget_B);
    }
    catch(Exception err)
    {
        err.showErrorMsg();
    }
}
