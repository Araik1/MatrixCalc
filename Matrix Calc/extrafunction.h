#ifndef EXTRAFUNCTION_H
#define EXTRAFUNCTION_H

#include "Matrix.h"
#include <QTableWidget>
#include <QLineEdit>

void TableToMatrix(QTableWidget *table, Matrix &matrix){
    int rows = table->rowCount();
    int cols = table->columnCount();
    matrix.setSize(rows, cols);
    try{
        for (int i =0; i<rows;i++){
            for (int j=0;j<cols;j++){
                bool ok;//переменная отвечающая за успешное конвертирование строки в число
                long double t = (table->item(i, j)->text()).toDouble(&ok);//извлекаем содержимое ячейки [i][j]
                if (!ok)//если конвертация не удалась, бросить исключение
                    throw Exception(10, "incorrec data");
                matrix.setElement(i, j, t);//записываем значение в таблицу

             }

         }
    }
    catch (Exception error){
            error.showErrorMsg();
    }
}

double ReadLineEdit(QLineEdit *x)
{
    bool ok;
    double t = x->text().toDouble(&ok);
    if (!ok)
        throw Exception(10, "incorrec data");

   return t;
}

void MatrixToTable(Matrix &matrix, QTableWidget *table)
{
    for (auto i = 0; i<table->rowCount(); i++)
    {
        for (auto j = 0; j<table->columnCount(); j++)
        {
            QString str = QString::number(matrix.element(i, j), 'f', 6);
            table->setItem(i, j, new QTableWidgetItem(str));
        }
    }
}


void SetRowCount(QTableWidget *x, int a)
{
    x->setRowCount(a);

    for (size_t i = 0; i < a; i++)
    {
        QTableWidgetItem *cell;
        if (x->item(i, 0) == NULL )
        {
         cell = new QTableWidgetItem();
         x->setItem(i, 0, cell);
        }
    }
}

void SetColumnCount(QTableWidget *x, int a)
{
    x->setColumnCount(a);
    for (size_t i = 0; i < a; i++)
    {
        QTableWidgetItem *cell;
        if (x->item(0, i) == NULL )
        {
         cell = new QTableWidgetItem();
         x->setItem(0, i, cell);
        }
    }

}

#endif // EXTRAFUNCTION_H
