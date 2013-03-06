#include "Header/Model/entreecodex.h"

EntreeCodex::EntreeCodex()
{
    m_Cout_Base = 0;
    m_coutUnit = 0;
    m_Nombre_Minimum = 0;
    m_Nombre_Maximum = 0;
    m_unique = false;
}

EntreeCodex::EntreeCodex(const EntreeCodex& entree)
{
    m_Nom_Usuel = entree.m_Nom_Usuel;
    m_Categorie = entree.m_Categorie;
    m_Type = entree.m_Type;
    m_Regle = entree.m_Regle;
    m_Caracteristique = entree.m_Caracteristique;
    m_Equipement_Disponible = entree.m_Equipement_Disponible;
    m_Cout_Base = entree.m_Cout_Base;
    m_Nombre_Minimum = entree.m_Nombre_Minimum;
    m_Nombre_Maximum = entree.m_Nombre_Maximum;
    m_coutUnit = entree.m_coutUnit;
    m_unique = entree.m_unique;
    m_accompagnant = entree.m_accompagnant;
    m_modif = entree.m_modif;
}


int EntreeCodex::getCout_Base()
{
    return m_Cout_Base;
}

int EntreeCodex::getCoutUnit()
{
    return m_coutUnit;
}

int EntreeCodex::getNombreMin()
{
    return m_Nombre_Minimum;
}

int EntreeCodex::getNombreMax()
{
    return m_Nombre_Maximum;
}

QString EntreeCodex::getNomUs()
{
    return m_Nom_Usuel;
}

QString EntreeCodex::getCategorie()
{
    return m_Categorie;
}

QString EntreeCodex::getType()
{
    return m_Type;
}
QMap<QString, int>& EntreeCodex::getCaracteristique()
{
    return m_Caracteristique;
}

QSet<QString>& EntreeCodex::getRegle()
{
    return m_Regle;
}

QMap<QString, Equipement>& EntreeCodex::getEquipementDisp()
{
    return m_Equipement_Disponible;
}

void EntreeCodex::ajoutRegle(const QString regle)
{
    if(!m_Regle.contains(regle))
    {
        m_Regle.insert(regle);
    }
}

void EntreeCodex::suppressionRegle(const QString regle)
{
    m_Regle.remove(regle);
}

void EntreeCodex::setType(const QString type)
{
    m_Type = type;
}

void EntreeCodex::setRegle(QSet<QString>& regle)
{
    m_Regle = regle;
}

void EntreeCodex::setCategorie(const QString cat)
{
    m_Categorie = cat;
}

void EntreeCodex::setNomUs(const QString nom)
{
    m_Nom_Usuel = nom;
}

void EntreeCodex::setCarac(QMap<QString, int>& carac)
{
    m_Caracteristique = carac;
}

void EntreeCodex::setEquipementDisp(QMap<QString, Equipement>& equip)
{
    m_Equipement_Disponible = equip;
}

void EntreeCodex::setNombreMin(int nb)
{
    m_Nombre_Minimum = nb;
}

void EntreeCodex::setNombreMax(int nb)
{
    m_Nombre_Maximum = nb;
}

void EntreeCodex::setCoutBase(int cout)
{
    m_Cout_Base = cout;
}

void EntreeCodex::setCoutUnit(int cout)
{
    m_coutUnit = cout;
}

bool EntreeCodex::getUnique()
{
    return m_unique;
}

void EntreeCodex::setUnique(bool unique)
{
    m_unique = unique;
}

void EntreeCodex::ajouteAccompagnant(Accompagnant a)
{
    m_accompagnant.insert(a.getNom(), a);
}

QMap<QString, Accompagnant> EntreeCodex::getAccompagnant()
{
    return m_accompagnant;
}

QSet<Modif>& EntreeCodex::getModif()
{
    return m_modif;
}

void EntreeCodex::setModif(QSet<Modif> a)
{
    m_modif = a;
}
