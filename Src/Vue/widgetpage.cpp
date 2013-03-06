#include "Header/Vue/widgetpage.h"
#include <QMultiMap>
#include <cmath>
#include <QRegExp>


WidgetPage::WidgetPage(Equipement* equip, QMultiMap<QString, int>& map, int max, QWidget *parent) :
    QWidget(parent)
{
    m_layout = new QVBoxLayout;
    m_titre = equip->getNom();
    m_actuel = equip;
    m_max = max;
    QStringList liste;
    liste<<"Aucune";
    for(QMultiMap<int, QString>::iterator it = m_actuel->getMembre().begin() ; it != m_actuel->getMembre().end(); it++)
    {
        liste<<it.value() + " ... " + QString::number(it.key()) + "pts";
    }
    WidgetCouple* couple = new WidgetCouple(equip->getNom());
    couple->addItems(liste);
    couple->setMaximum(m_max);
    m_vecteur.push_back(couple);
    connect(couple, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
    connect(couple, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
    m_layout->addWidget(couple);
    setLayout(m_layout);
}

WidgetPage::~WidgetPage()
{
    foreach (WidgetCouple* it, m_vecteur)
    {
        delete it;
    }
    delete m_layout;
}

void WidgetPage::rajout(WidgetCouple* couple1, int ok, QString texte)
{
    switch(ok)
    {
    case 1:
    {
        emit exclus(this, true);
        QStringList liste = couple1->getItem();
        liste.removeOne(texte);
        int act = 0;

        for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
        {
            if(*it != couple1)
            {
                (*it)->enleve(texte);
            }

            if(texte != "Aucune")
            {
                act += (*it)->getValue();
            }
        }

        switch(m_actuel->getCles())
        {
        int newMax;
        case ab::par:
            newMax = m_max - act;
            if(newMax > 0)
            {
                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
            else
            {
                for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
                {
                    (*it)->setMaximum((*it)->getValue() + newMax);
                }
            }
            break;
        case ab::si:
            newMax = m_max - act;
            if(newMax > 0)
            {
                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
            else
            {
                for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
                {
                    (*it)->setMaximum((*it)->getValue() + newMax);
                }
            }
            break;
        case ab::defaut:
            newMax = m_max - act;
            if(newMax > 0)
            {
                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
            else
            {
                for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
                {
                    (*it)->setMaximum((*it)->getValue() + newMax);
                }
            }
            break;
        default:
            if(m_vecteur.count() < m_actuel->getMembre().count())
            {

                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                couple2->setMaximum(1);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
            break;
        }
    }
        break;

    case 2:
    {
        QString act = couple1->getCurrent();
        foreach (WidgetCouple* it, m_vecteur)
        {
            if(it != couple1)
            {
                it->enleve(texte);
                it->ajoute(act);
            }
        }
    }
        break;
    case 3:
    {
        emit exclus(this, false);
        int act = 0;
        for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
        {
            if(*it != couple1)
            {
                (*it)->ajoute(texte);
                act += (*it)->getValue();
            }
            else
            {
                if(it != m_vecteur.end() - 1)
                {
                    couple1->close();
                    WidgetCouple* it2 = *it;
                    it--;
                    m_layout->removeWidget(it2);
                    m_vecteur.remove(m_vecteur.indexOf(it2));
                    delete it2;
                }
            }
        }
        QStringList liste = m_vecteur.at(m_vecteur.count()-1)->getItem();
        if(m_vecteur.at(m_vecteur.count()-1)->getCurrent() != "Aucune")
        {
            liste.removeOne(m_vecteur.at(m_vecteur.count()-1)->getCurrent());
        }

        switch(m_actuel->getCles())
        {
        int newMax;
        case ab::par:
        {
            newMax = m_max - act;
            for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
            {
                (*it)->setMaximum((*it)->getValue() + newMax);
            }

            if((newMax > 0) && ((*(m_vecteur.end() - 1)) != couple1))
            {
                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
        }
            break;
        case ab::si:
        {
            newMax = m_max - act;
            for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
            {
                (*it)->setMaximum((*it)->getValue() + newMax);
            }

            if((newMax > 0) && ((*(m_vecteur.end() - 1)) != couple1))
            {
                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
        }
            break;
        case ab::defaut:
        {
            newMax = m_max - act;
            for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
            {
                (*it)->setMaximum((*it)->getValue() + newMax);
            }

            if((newMax > 0) && ((*(m_vecteur.end() - 1)) != couple1))
            {
                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
        }
            break;
        default:
        {
            if(m_vecteur.count() < m_actuel->getMembre().count())
            {
                WidgetCouple* couple2 = new WidgetCouple(m_titre);
                couple2->setMaximum(m_max);
                couple2->addItems(liste);
                couple2->setMaximum(1);
                m_layout->addWidget(couple2);
                m_vecteur.append(couple2);
                connect(couple2, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                connect(couple2, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
            }
        }
            break;
        }
    }
        break;

    default:
        break;
    }
}

void WidgetPage::changement(WidgetCouple* widget, bool main)
{
    if(!main)
    {
        if(m_actuel->getCles() == ab::par || m_actuel->getCles() == ab::si || m_actuel->getCles() == ab::defaut)
        {
            int act = 0;

            QStringList liste;
            liste<<"Aucune";
            for(QMultiMap<int, QString>::iterator it = m_actuel->getMembre().begin() ; it != m_actuel->getMembre().end(); it++)
            {
                liste<<it.value() + " ... " + QString::number(it.key()) + "pts";
            }

            for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
            {
                if(*it != widget)
                {
                    (*it)->enleve(widget->getCurrent());
                }
                if((*it)->getCurrent() != "Aucune")
                {
                    liste.removeOne((*it)->getCurrent());
                    act += (*it)->getValue();
                }

            }

            int newMax = m_max - act;
            for(QVector<WidgetCouple*>::iterator it = m_vecteur.begin(); it != m_vecteur.end(); it++)
            {

                if((*it)->getCurrent().contains("Aucune") && newMax == 0)
                {
                    WidgetCouple* it2 = *it;
                    it--;
                    m_layout->removeWidget(it2);
                    m_vecteur.remove(m_vecteur.indexOf(it2));
                    delete it2;
                }
                else
                {
                    (*it)->setMaximum((*it)->getValue() + newMax);
                }

                if((newMax != 0) && (it + 1 == m_vecteur.end()) && ((*it)->getCurrent() != "Aucune"))
                {
                    WidgetCouple* couple = new WidgetCouple(m_actuel->getNom());
                    couple->addItems(liste);
                    couple->setMaximum(m_max);
                    m_vecteur.push_back(couple);
                    connect(couple, SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
                    connect(couple, SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));
                    m_layout->addWidget(couple);
                    break;
                }
            }
        }
    }
}

void WidgetPage::setNb(int nb)
{
    m_nb = nb;

    switch(m_actuel->getCles())
    {
    case ab::defaut:
        m_max = m_actuel->getNDansM().first;
        break;
    case ab::si:
        m_max = m_actuel->getNDansM().first;
        if(nb >= m_actuel->getNDansM().second)
        {
            setEnabled(true);
        }
        else
        {
            setEnabled(false);
        }
        break;
    case ab::par:
        m_max = (nb/m_actuel->getNDansM().second)*m_actuel->getNDansM().first;
        break;
    default:
        break;
    }
}

int WidgetPage::getMax()
{
    return m_max;
}

Equipement* WidgetPage::getActuel()
{
    return m_actuel;
}

void WidgetPage::setMax(int max)
{
    m_max = max;
    foreach (WidgetCouple* it, m_vecteur)
    {
        it->setMaximum(max);
    }
}

QString WidgetPage::getTitre()
{
    return m_titre;
}

void WidgetPage::setTitre(QString titre)
{
    m_titre = titre;
}

QVector<WidgetCouple*>& WidgetPage::getVecteur()
{
    return m_vecteur;
}

void WidgetPage::ext(QString nom, int nb)
{
    QStringList liste;
    liste<<"Aucune";
    int index;
    for(QMultiMap<int, QString>::iterator it = m_actuel->getMembre().begin() ; it != m_actuel->getMembre().end(); it++)
    {
        liste<<it.value() + " ... " + QString::number(it.key()) + "pts";
        if(nom == it.value())
        {
            index = liste.size() - 1;
        }
    }
    int i = 0;
    while(m_vecteur.at(i)->getCurrent() != "Aucune" && i < m_vecteur.size())
    {
        i++;
    }

    if(i < m_vecteur.size())
    {
        m_vecteur.at(i)->disconnect();

        m_vecteur.at(i)->setCurrent(liste.at(index));
        m_vecteur.at(i)->setValue(nb);
        rajout(m_vecteur.at(i), 1, liste.at(index));
        changement(m_vecteur.at(i), false);
        connect(m_vecteur.at(i), SIGNAL(changement(WidgetCouple*, bool)), this, SLOT(changement(WidgetCouple*, bool)));
        connect(m_vecteur.at(i), SIGNAL(rajout(WidgetCouple*, int, QString)), this, SLOT(rajout(WidgetCouple*, int, QString)));

    }
}
