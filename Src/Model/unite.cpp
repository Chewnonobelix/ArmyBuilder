#include "Header/Model/unite.h"
#include <QFile>
#include <QByteArray>
#include <QMessageBox>

using namespace std;

int Unite::m_compteur = 0;
//Constructeur et destructeur
Unite::Unite()
{
    m_compteur++;
    m_Nombre_Actuel = 0;
    m_Cout_Actuel = 0;
    m_place = 0;
    m_id = m_compteur;
}


Unite::Unite(const Unite & unit)
{
    m_compteur++;
    m_Nom_Donne = unit.m_Nom_Donne;
    m_Cout_Actuel = unit.m_Cout_Actuel;
    m_Nombre_Actuel = unit.m_Nombre_Actuel;
    m_place = unit.m_place;
    m_id = unit.m_id;
}

Unite::~Unite()
{
}

//Accesseur

int Unite::getCout_Actuel()
{
    return m_Cout_Actuel;
}

int Unite::getNombreAct()
{
    return m_Nombre_Actuel;
}

QString Unite::getNomDon()
{
    return m_Nom_Donne;
}

int Unite::getPlace()
{
    return m_place;
}

//Mutateur
void Unite::setId(int id)
{
    m_id = id;
}

void Unite::setPlace(int place)
{
    m_place = place;
}

void Unite::setNomDon(const QString nom)
{
    m_Nom_Donne = nom;
}

void Unite::setNombre(const int n)
{
    if(n <= getEntree()->getNombreMax() && n >= getEntree()->getNombreMin())
    {
        m_Nombre_Actuel = n;
    }

    setCoutAct();
}

void Unite::setCoutAct(const int a)
{
    m_Cout_Actuel = a;
}

//Fonction membre

void Unite::operator =(Unite& unit)
{
    m_place = unit.getPlace();
    m_Nom_Donne = unit.getNomDon();
    m_Cout_Actuel = unit.getCout_Actuel();
    m_Nombre_Actuel = unit.getNombreAct();
    m_id = unit.getId();
    m_entree = unit.getEntree();
}


bool operator ==(const Unite& a, const Unite &b)
{
    return (a.m_id == b.m_id);
}

int Unite::getId()
{
    return m_id;
}

EntreeCodex* Unite::getEntree()
{
    return m_entree;
}

void Unite::setEntree(EntreeCodex * e)
{
    m_entree = e;
}

