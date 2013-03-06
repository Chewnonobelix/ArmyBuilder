#ifndef ARME_H
#define ARME_H

#include "Header/Model/item.h"
#include <QStringList>

class Arme: public Item
{
public:
    Arme();
    Arme(const Arme&);
    Arme(QString, QString, QString, QString = QString(), int = 0, int = 0, int = 0, QStringList = QStringList());
    QString getPortee();
    int getForce();
    int getPa();
    QString getCat();
    int getNb();
    QStringList getAttribut();


private:
    QString m_portee;
    int m_force;
    int m_pa;
    QString m_cat;
    int m_nb;
    QStringList m_attribut;
};

#endif // ARME_H
