#ifndef ACCOMPAGNANT_H
#define ACCOMPAGNANT_H

#include <QSet>
#include <QString>
#include <QMap>
#include <QPair>
#include "Header/Model/enum.h"
class Accompagnant
{
private:
    int m_nb;
    QMap<QString, QPair<ab::cles, int> > m_membre;
    QString m_nom;


public:
    Accompagnant();
    Accompagnant(const Accompagnant&);
    QMap<QString, QPair<ab::cles, int> >& getMembre();
    int getNb();
    QString getNom();

    void setMembre(QMap<QString, QPair<ab::cles, int> >);
    void setNb(int);
    void setNom(QString);

    Accompagnant& operator = (const Accompagnant&);
};

#endif // ACCOMPAGNANT_H
