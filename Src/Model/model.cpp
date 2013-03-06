#include "Header/Model/model.h"

Model::Model(QObject *parent) :
    QObject(parent)
{
    m_liste = new Codex;
}

void Model::setNomJeux(QString n)
{
    m_nomJeux = n;
}

void Model::setliste(Codex* l)
{
    m_liste = l;
}

QString Model::getNomJeux()
{
    return m_nomJeux;
}

Codex* Model::getListe()
{
    return m_liste;
}

QMap<QString, QMap<QString, EntreeCodex*> >& Model::getCodex()
{
    return m_codex;
}

QMap<QString, EntreeCodex*>& Model::getCodex(QString n)
{
    return m_codex[n];
}

void Model::addLimite(QString n, int l)
{
    m_limite.insert(n,l);
}

QMap<QString, int>& Model::getLimite()
{
    return m_limite;
}

void Model::setFactory(UniteFactory* f)
{
    m_factory = f;
}

UniteFactory* Model::getFactory()
{
    return m_factory;
}
