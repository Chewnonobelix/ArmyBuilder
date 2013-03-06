#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>
#include <QMultiMap>
#include <QPair>
#include <QMessageBox>
#include <QSet>
#include "Header/Model/enum.h"

using namespace ab;

class Equipement
{
public:
    Equipement();
    Equipement(const Equipement&);
    QString getNom();
    cles getCles();
    QPair<int, int>& getNDansM();
    QMultiMap<int, QString>& getMembre();
    QSet<QString>& getExclus();

    void setNom(QString);
    void setCles(cles);
    void setNDansM(QPair<int, int>&);
    void setMembre(QMultiMap<int, QString>&);
    void setExclus(QSet<QString>);


    void operator = (const Equipement&);

private:
    QString m_nomCategorie;
    cles m_cles;
    QPair<int, int> m_nDansM; //premier: nombre d'equipement en fonction de du second membre
    QMultiMap<int, QString> m_membre;
    QSet<QString> m_exclus;
};

#endif // EQUIPEMENT_H
