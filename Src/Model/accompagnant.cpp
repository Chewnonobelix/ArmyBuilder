#include "Header/Model/accompagnant.h"
#include <QMessageBox>

Accompagnant::Accompagnant()
{
}

Accompagnant::Accompagnant(const Accompagnant & a)
{
    m_nb = a.m_nb;
    m_membre = a.m_membre;
    m_nom = a.m_nom;
}

QMap<QString, QPair<ab::cles, int> >& Accompagnant::getMembre()
{
    return m_membre;
}

int Accompagnant::getNb()
{
    return m_nb;
}

QString Accompagnant::getNom()
{
    return m_nom;
}

void Accompagnant::setMembre(QMap<QString, QPair<ab::cles, int> > a)
{
    m_membre = a;
}

void Accompagnant::setNb(int nb)
{
    m_nb = nb;
}

void Accompagnant::setNom(QString nom)
{
    m_nom = nom;
}

Accompagnant& Accompagnant::operator = (const Accompagnant& b)
{
    m_membre = b.m_membre;
    m_nb = b.m_nb;
    m_nom = b.m_nom;

    return *this;
}
