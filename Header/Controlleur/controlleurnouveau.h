#ifndef CONTROLLEURNOUVEAU_H
#define CONTROLLEURNOUVEAU_H

#include "Header/Controlleur/controlleur.h"
#include "Header/Controlleur/controlleurchargement.h"
#include "Header/Vue/nouveau.h"

class ControlleurNouveau: public Controlleur
{
    Q_OBJECT

public:
    ControlleurNouveau(QObject* = 0);
    void exec();
    void setVue(Nouveau* );
    Nouveau* getVue();

private:
    Nouveau* m_vue;

private slots:

signals:
    void s_enable(bool);
    void s_max(int);
 };

#endif // CONTROLLEURNOUVEAU_H
