#ifndef Exception_H
#define Exception_H

#include <QErrorMessage>
#include <iostream>
#include <QString>

using namespace std;

class Exception
{
	int num;
    QString str;
public:
    Exception(int num, QString str);

    void showErrorMsg();
};

#endif // !Exception_H
