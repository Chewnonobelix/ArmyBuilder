#ifndef CONTROLLEURMAIN_H
#define CONTROLLEURMAIN_H

#include "Header/Controlleur/controlleur.h"
#include "Header/Vue/mainwindow.h"
#include "Header/Controlleur/controlleurnouveau.h"

class ControlleurMain: public Controlleur
{
    Q_OBJECT

private:
    MainWindow* m_vue;
public:
    ControlleurMain(QObject *parent = 0);
    ~ControlleurMain();
    void exec();
    MainWindow* getVue();
    void setVue(MainWindow* );

private slots:
    void nouveau();
    /*void sauvegarder();
    void charger();*/

public slots:
    void enable(bool);
    void max(int);
};

#endif // CONTROLLEURMAIN_H
