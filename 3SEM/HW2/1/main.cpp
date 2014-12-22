#include "mainwindow.h"
#include <QApplication>
#include "netwroktest.h"

int main(int argc, char *argv[])
{
    netwrokTest nTest;
    QTest::qExec(&nTest);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
