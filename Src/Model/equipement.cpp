#include "Header/Model/equipement.h"

Equipement::Equipement()
{
}

Equipement::Equipement(const Equipement & equip)
{
    m_nomCategorie = equip.m_nomCategorie;
    m_cles = equip.m_cles;
    m_nDansM = equip.m_nDansM;
    m_membre = equip.m_membre;
    m_exclus = equip.m_exclus;
}

QString Equipement::getNom()
{
    return m_nomCategorie;
}

cles Equipement::getCles()
{
    return m_cles;
}

QPair<int, int>& Equipement::getNDansM()
{
    return m_nDansM;
}

QMultiMap<int, QString>& Equipement::getMembre()
{
    return m_membre;
}

void Equipement::setNom(QString nom)
{
    m_nomCategorie = nom;
}

void Equipement::setCles(cles cle)
{
    m_cles = cle;
}

void Equipement::setNDansM(QPair<int, int>& n)
{
    m_nDansM = n;
}

void Equipement::setMembre(QMultiMap<int, QString>& membre)
{
    m_membre = membre;
}

void Equipement::operator =(const Equipement& equip)
{
    m_nomCategorie = equip.m_nomCategorie;
    m_cles = equip.m_cles;
    m_nDansM = equip.m_nDansM;
    m_membre = equip.m_membre;
    m_exclus = equip.m_exclus;
}

QSet<QString>& Equipement::getExclus()
{
    return m_exclus;
}

void Equipement::setExclus(QSet<QString> e)
{
    m_exclus = e;
}
