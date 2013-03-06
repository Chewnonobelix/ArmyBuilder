#include "Header/Vue/widgetpageeditable.h"

WidgetPageEditable::WidgetPageEditable(Accompagnant a, int nb, QWidget *parent) :
    QWidget(parent)
{
    m_accomp = a;
    m_layout = new QVBoxLayout;
    m_nom = m_accomp.getNom();
    m_nb = nb;
    QStringList list;
    list<<"Aucune";
    foreach (QString nom, m_accomp.getMembre().keys())
    {
        switch(m_accomp.getMembre()[nom].first)
        {
        case ab::si:
            if(m_nb == m_accomp.getMembre()[nom].second)
            {
                list<<nom;
            }
            break;
        case ab::sup:
            if(m_nb > m_accomp.getMembre()[nom].second)
            {
                list<<nom;
            }
            break;
        case ab::inf:
            if(m_nb < m_accomp.getMembre()[nom].second)
            {
                list<<nom;
            }
            break;
        case ab::defaut:
            list<<nom;
            break;
        default:
            break;
        }
    }

    WidgetCouple* couple = new WidgetCouple(m_accomp.getNom(), true);
    couple->addItems(list);
    m_vecteur.push_back(couple);
    m_layout->addWidget(couple);
    setLayout(m_layout);
    connect(couple, SIGNAL(edition(WidgetCouple*)), this, SLOT(edition(WidgetCouple*)));
    connect(couple, SIGNAL(rajout(WidgetCouple*,int,QString)), this, SLOT(rajout(WidgetCouple*,int,QString)));
}


WidgetPageEditable::~WidgetPageEditable()
{
    foreach (WidgetCouple* it, m_vecteur)
    {
        delete it;
    }
    delete m_layout;
}

void WidgetPageEditable::edition(WidgetCouple * widget)
{
    int i = m_vecteur.indexOf(widget);

    emit editions(m_nom, i);
}

void WidgetPageEditable::rajout(WidgetCouple * widget, int i, QString texte)
{
    int place = m_vecteur.indexOf(widget);
    switch(i)
    {
    case 1:
        emit rajoute(texte, place);
        //envoie le nom
        if(m_vecteur.size() < m_accomp.getNb())
        {
            QStringList list;
            list<<"Aucune";
            foreach (QString nom, m_accomp.getMembre().keys())
            {
                switch(m_accomp.getMembre()[nom].first)
                {
                case ab::si:
                    if(m_nb == m_accomp.getMembre()[nom].second)
                    {
                        list<<nom;
                    }
                    break;
                case ab::sup:
                    if(m_nb > m_accomp.getMembre()[nom].second)
                    {
                        list<<nom;
                    }
                    break;
                case ab::inf:
                    if(m_nb < m_accomp.getMembre()[nom].second)
                    {
                        list<<nom;
                    }
                    break;
                case ab::defaut:
                    list<<nom;
                    break;
                default:
                    break;
                }
            }
            WidgetCouple* couple = new WidgetCouple(m_accomp.getNom(), true);
            couple->addItems(list);
            m_vecteur.push_back(couple);
            m_layout->addWidget(couple);
            connect(couple, SIGNAL(edition(WidgetCouple*)), this, SLOT(edition(WidgetCouple*)));
            connect(couple, SIGNAL(rajout(WidgetCouple*,int,QString)), this, SLOT(rajout(WidgetCouple*,int,QString)));
        }
        break;
    case 2:
        emit enleve(m_nom,place);
        emit rajoute(texte, place);
        //supprime ancien, envoie le nouveau
        break;
    case 3:
        emit enleve(m_nom,place);
        if(place < m_vecteur.size() - 1 && m_vecteur.size() > 1)
        {
            WidgetCouple* temp = m_vecteur[place];
            widget->close();
            m_vecteur.remove(place);
            m_layout->removeWidget(temp);
            delete temp;

            if(m_vecteur[m_vecteur.size() - 1]->getCurrent() != "Aucune" && m_vecteur.size() < m_accomp.getNb())
            {
                QStringList list;
                list<<"Aucune";
                foreach (QString nom, m_accomp.getMembre().keys())
                {
                    switch(m_accomp.getMembre()[nom].first)
                    {
                    case ab::si:
                        if(m_nb == m_accomp.getMembre()[nom].second)
                        {
                            list<<nom;
                        }
                        break;
                    case ab::sup:
                        if(m_nb > m_accomp.getMembre()[nom].second)
                        {
                            list<<nom;
                        }
                        break;
                    case ab::inf:
                        if(m_nb < m_accomp.getMembre()[nom].second)
                        {
                            list<<nom;
                        }
                        break;
                    case ab::defaut:
                        list<<nom;
                        break;
                    default:
                        break;
                    }
                }
                WidgetCouple* couple = new WidgetCouple(m_accomp.getNom(), true);
                couple->addItems(list);
                m_vecteur.push_back(couple);
                m_layout->addWidget(couple);
                connect(couple, SIGNAL(rajout(WidgetCouple*,int,QString)), this, SLOT(rajout(WidgetCouple*,int,QString)));
            }
        }
        break;
    default:
        break;
    }
}

QString WidgetPageEditable::getNom()
{
    return m_nom;
}

void WidgetPageEditable::editable(QVector<QString> vect)
{
    foreach (WidgetCouple* couple, m_vecteur)
    {
        delete couple;
    }
    m_vecteur.clear();
    foreach (QString nom, vect)
    {
        WidgetCouple* couple = new WidgetCouple(m_accomp.getNom(), true);
        QStringList list;
        list<<"Aucune";
        foreach (QString nom, m_accomp.getMembre().keys())
        {
            switch(m_accomp.getMembre()[nom].first)
            {
            case ab::si:
                if(m_nb == m_accomp.getMembre()[nom].second)
                {
                    list<<nom;
                }
                break;
            case ab::sup:
                if(m_nb > m_accomp.getMembre()[nom].second)
                {
                    list<<nom;
                }
                break;
            case ab::inf:
                if(m_nb < m_accomp.getMembre()[nom].second)
                {
                    list<<nom;
                }
                break;
            case ab::defaut:
                list<<nom;
                break;
            default:
                break;
            }
        }
        couple->addItems(list);
        couple->setCurrent(nom);
        connect(couple, SIGNAL(edition(WidgetCouple*)), this, SLOT(edition(WidgetCouple*)));
        connect(couple, SIGNAL(rajout(WidgetCouple*,int,QString)), this, SLOT(rajout(WidgetCouple*,int,QString)));
        m_vecteur.append(couple);
        m_layout->addWidget(couple);
    }
}

void WidgetPageEditable::change(int nb)
{
    QStringList list;
    list<<"Aucune";
    m_nb = nb;
    foreach (QString nom, m_accomp.getMembre().keys())
    {
        switch(m_accomp.getMembre()[nom].first)
        {
        case ab::si:
            if(m_nb == m_accomp.getMembre()[nom].second)
            {
                list<<nom;
            }
            break;
        case ab::sup:
            if(m_nb > m_accomp.getMembre()[nom].second)
            {
                list<<nom;
            }
            break;
        case ab::inf:
            if(m_nb < m_accomp.getMembre()[nom].second)
            {
                list<<nom;
            }
            break;
        case ab::defaut:
            list<<nom;
            break;
        default:
            break;
        }
    }
    foreach (WidgetCouple* it, m_vecteur)
    {
        it->disconnect();
        QString nom = it->getCurrent();
        if(!list.contains(it->getCurrent()))
        {
            int place = m_vecteur.indexOf(it);
            emit enleve(m_nom,place);
            it->enleve(nom);
            nom = "Aucune";
        }
        it->addItems(list);
        it->setCurrent(nom);
        connect(it, SIGNAL(edition(WidgetCouple*)), this, SLOT(edition(WidgetCouple*)));
        connect(it, SIGNAL(rajout(WidgetCouple*,int,QString)), this, SLOT(rajout(WidgetCouple*,int,QString)));
    }
}
