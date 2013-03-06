#include <QtGui/QApplication>
#include "Header/Controlleur/controlleurmain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controlleur* c = new ControlleurMain;

    c->exec();

    return a.exec();
}
