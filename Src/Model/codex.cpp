#include "Header/Model/codex.h"


//Constructeur et Destructeur
Codex::Codex()
{

}

Codex::~Codex()
{
}

void Codex::setNomArmee(QString n)
{
    m_nomArmee = n;
}

void Codex::setNomListe(QString n)
{
    m_nomListe = n;
}

QString Codex::getNomArmee()
{
    return m_nomArmee;
}

QString Codex::getNomListe()
{
    return m_nomListe;
}

QMap<QString, QMap<int, Unite*> >& Codex::getListe()
{
    return m_liste;
}

QMap<int, Unite*>& Codex::getListe(QString cat)
{
    return getListe()[cat];
}

void Codex::addUnite(QString cat , Unite* u)
{
    if(!getListe().contains(cat))
    {
        QMap<int, Unite*> map;
        map.insert(u->getId(), u);
        getListe().insert(cat, map);
    }
    else
    {
        if(!getListe(cat).contains(u->getId()))
        {
           getListe(cat).insert(u->getId(), u);
        }
    }
}

void Codex::removeUnite(int id)
{
    for(QMap<QString, QMap<int, Unite*> >::iterator it = getListe().begin(); it != getListe().end(); it++)
    {
        if(it.value().contains(id))
        {
            it.value().remove(id);
        }
    }
}
