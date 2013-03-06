#include "Header/Model/modif.h"

Modif::Modif()
{
}

Modif::Modif(const Modif & mod)
{
    m_nom = mod.m_nom;
    m_cles = mod.m_cles;
    m_depuis = mod.m_depuis;
    m_vers = mod.m_vers;
}

modif Modif::getCles()
{
    return m_cles;
}

QString Modif::getDepuis()
{
    return m_depuis;
}

QString Modif::getVers()
{
    return m_vers;
}

void Modif::setCles(modif cles)
{
    m_cles = cles;
}

void Modif::setDepuis(QString depuis)
{
    m_depuis = depuis;
}

void Modif::setVers(QString vers)
{
    m_vers = vers;
}

void Modif::setNom(QString nom)
{
    m_nom = nom;
}

QString Modif::getNom()
{
    return m_nom;
}

void Modif::operator =(const Modif& mod)
{
    m_nom = mod.m_nom;
    m_cles = mod.m_cles;
    m_depuis = mod.m_depuis;
    m_vers = mod.m_vers;
}

bool operator == (const Modif& a, const Modif& b)
{
    return (a.m_nom == b.m_nom) && (a.m_cles == b.m_cles) && (a.m_depuis==b.m_depuis) && (a.m_vers==b.m_vers);
}

uint qHash(Modif mod)
{
    return qHash(mod.getNom());
}
