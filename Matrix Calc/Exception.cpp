#include "Exception.h"

Exception::Exception(int num, QString str) : num(num), str(str) {}

void Exception::showErrorMsg()
{
     QErrorMessage errorMessage;

     errorMessage.showMessage("Exception! - #" + QString::number(num) + ", " + str);

     errorMessage.exec();
}
