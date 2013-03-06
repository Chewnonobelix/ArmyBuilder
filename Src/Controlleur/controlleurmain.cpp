#include "Header/Controlleur/controlleurmain.h"

ControlleurMain::ControlleurMain(QObject *parent): Controlleur(parent)
{
    m_vue = new MainWindow;
    connect(getVue(), SIGNAL(s_nouveau()), this, SLOT(nouveau()));
}

ControlleurMain::~ControlleurMain()
{
    destroyModel();
}

void ControlleurMain::exec()
{
    m_vue->show();
}

MainWindow* ControlleurMain::getVue()
{
    return m_vue;
}

void ControlleurMain::setVue(MainWindow* m)
{
    m_vue = m;
}

void ControlleurMain::nouveau()
{
    ControlleurNouveau* c = new ControlleurNouveau;
    connect(c, SIGNAL(s_enable(bool)), this, SLOT(enable(bool)));
    connect(c, SIGNAL(s_max(int)), this, SLOT(max(int)));
    c->exec();
    getVue()->setModel(getModel());
    delete c;
}

void ControlleurMain::enable(bool ok)
{
    getVue()->enable(ok);
}

void ControlleurMain::max(int m)
{
    getVue()->limite(m);
}
