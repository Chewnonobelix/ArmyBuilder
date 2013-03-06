#ifndef ENTREECODEX_H
#define ENTREECODEX_H

#include <QMap>
#include <QPair>
#include <QString>
#include <QSet>
#include "Header/Model/equipement.h"
#include "Header/Model/accompagnant.h"
#include "Header/Model/modif.h"

class EntreeCodex
{
private:
    QString m_Nom_Usuel;
    QString m_Categorie;
    QString m_Type;
    QSet<QString> m_Regle;
    QMap<QString, int> m_Caracteristique;
    QMap<QString, Equipement> m_Equipement_Disponible;
    int m_Cout_Base;
    int m_coutUnit;
    int m_Nombre_Minimum;
    int m_Nombre_Maximum;
    bool m_unique;
    QMap<QString, Accompagnant> m_accompagnant;
    QSet<Modif> m_modif;

public:
    EntreeCodex();
    EntreeCodex(const EntreeCodex&);
    //accesseur
    int getCout_Base();
    int getCoutUnit();
    int getNombreMin();
    int getNombreMax();
    bool getUnique();
    QString getNomUs();
    QString getCategorie();
    QString getType();
    QMap<QString, int>& getCaracteristique();
    QSet<QString>& getRegle();
    QMap<QString, Equipement>& getEquipementDisp();
    QMap<QString, Accompagnant> getAccompagnant();
    QSet<Modif>& getModif();

    //Mutateur
    void ajoutRegle(const QString);
    void suppressionRegle(const QString);
    void setRegle(QSet<QString>&);
    void setType(const QString);
    void setCategorie(const QString);
    void setNomUs(const QString);
    void setCarac(QMap<QString, int>&);
    void setEquipementDisp(QMap<QString, Equipement>&);
    void setNombreMin(int);
    void setNombreMax(int);
    void setCoutUnit(int);
    void setCoutBase(int);
    void setUnique(bool);
    void ajouteAccompagnant(Accompagnant);
    void setModif(QSet<Modif>);

};

#endif // ENTREECODEX_H
