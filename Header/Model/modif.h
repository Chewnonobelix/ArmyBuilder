#ifndef MODIF_H
#define MODIF_H

#include "Header/Model/enum.h"
#include <QHash>

using namespace ab;
class Modif
{

private:
    QString m_nom;
    QString m_depuis;
    QString m_vers;
    modif m_cles;
public:
    Modif();
    Modif(const Modif&);

    QString getNom();
    modif getCles();
    QString getDepuis();
    QString getVers();

    void setCles(modif);
    void setDepuis(QString);
    void setVers(QString);
    void setNom(QString);

    void operator =(const Modif&);

    friend bool operator == (const Modif&, const Modif&);
};

uint qHash(Modif);
#endif // MODIF_H
