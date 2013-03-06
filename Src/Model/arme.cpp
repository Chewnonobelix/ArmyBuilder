#include "Header/Model/arme.h"

Arme::Arme()
{

}

Arme::Arme(QString nom, QString des, QString cat, QString porte, int force, int pa, int nb, QStringList attribut): Item(nom, des)
{
    m_portee = porte;
    m_force = force;
    m_pa = pa;
    m_cat = cat;
    m_nb = nb;
    m_attribut = attribut;
}

Arme::Arme(const Arme & a):Item(a)
{
    m_portee = a.m_portee;
    m_force = a.m_force;
    m_pa = a.m_pa;
    m_cat = a.m_cat;
    m_nb = a.m_nb;
    m_attribut = a.m_attribut;
}

QString Arme::getPortee()
{
    return m_portee;
}

int Arme::getForce()
{
    return m_force;
}

int Arme::getPa()
{
    return m_pa;
}

QString Arme::getCat()
{
    return m_cat;
}

int Arme::getNb()
{
    return m_nb;
}

QStringList Arme::getAttribut()
{
    return m_attribut;
}
