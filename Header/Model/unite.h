#ifndef UNITE_H
#define UNITE_H

#include <QString>
#include <QSet>
#include <QMap>
#include <QMultiMap>
#include <QPair>
#include "Header/Model/entreecodex.h"

class Unite
{

private:
    static int m_compteur;
    int m_id;
    QString m_Nom_Donne;
    int m_Cout_Actuel;
    int m_Nombre_Actuel;
    int m_place;
    EntreeCodex* m_entree;

public:
    Unite();
    Unite(const Unite&);
    ~Unite();

    //Accesseur
    int getCout_Actuel();
    int getNombreAct();
    QString getNomDon();
    int getPlace();
    int getId();
    EntreeCodex* getEntree();

    //Mutateur
    void setId(int);
    void setPlace(int);
    void setNomDon(const QString);
    void setNombre(const int);
    void setCoutAct(const int);
    virtual void setCoutAct() = 0;
    void setEntree(EntreeCodex*);

    void operator = (Unite&);
    friend bool operator ==(const Unite&, const Unite&);
};

#endif // UNITE_H
