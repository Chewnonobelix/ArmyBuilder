#include "Header/Controlleur/controlleur.h"

Model* Controlleur::m_model = NULL;

Controlleur::Controlleur(QObject *parent) :
    QObject(parent)
{
}

Controlleur::~Controlleur()
{
}

Model* Controlleur::getModel()
{
    if(!hasModel())
    {
        m_model = new Model;
    }

    return m_model;
}

bool Controlleur::hasModel()
{
    return (m_model != NULL);
}

void Controlleur::destroyModel()
{
    delete m_model;
    m_model = NULL;
}
