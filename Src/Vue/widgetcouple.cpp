#include "Header/Vue/widgetcouple.h"
#include <QMessageBox>

WidgetCouple::WidgetCouple(QString nom, bool edit, int max, QWidget *parent) :
    QWidget(parent)
{
    m_nomCat = nom;
    m_label = new QComboBox(this);
    m_layout = new QHBoxLayout(this);
    m_layout->addWidget(m_label);
    m_editable = edit;
    m_current = "Aucune";
    if(!edit)
    {
        m_push = 0;
        m_spin = new QSpinBox(this);
        m_spin->setMinimum(1);
        m_spin->setMaximum(max);
        m_spin->setValue(1);
        m_layout->addWidget(m_spin);

        if(m_spin->maximum() == 1)
        {
            m_spin->setEnabled(false);
        }

        connect(m_spin, SIGNAL(valueChanged(int)), this, SLOT(changementDeValeur(int)));
    }
    else
    {
        m_spin = 0;
        m_push = new QPushButton(tr("Editer"));
        m_layout->addWidget(m_push);
        m_push->setEnabled(false);
        connect(m_push, SIGNAL(clicked()), this, SLOT(edition()));
    }
    connect(m_label, SIGNAL(currentIndexChanged(QString)), this, SLOT(changementText(QString)));

}

WidgetCouple::WidgetCouple(const WidgetCouple & couple)
{
    m_label = new QComboBox(this);
    m_label = couple.m_label;

    m_layout = new QHBoxLayout(this);
    m_layout->addWidget(m_label);

    if(couple.m_spin != 0)
    {
        m_spin = new QSpinBox(this);
        m_spin->setValue(couple.m_spin->value());
        m_layout->addWidget(m_spin);
        m_push = 0;
    }
    else
    {
        m_push = new QPushButton("Editer");
        m_spin = 0;
    }
}

void WidgetCouple::ajoute(QString texte)
{
    if(!texte.contains("Aucune"))
    {
        m_label->insertItem(m_label->count(), texte);
    }
}

void WidgetCouple::enleve(QString nom)
{ 
    m_label->removeItem(m_label->findText(nom));
    m_label->setCurrentIndex(m_label->findText(m_current));
}

int WidgetCouple::getValue()
{
    return m_spin->value();
}

int WidgetCouple::getMax()
{
    return m_spin->maximum();
}

void WidgetCouple::setCurrent(QString current)
{
    m_current = current;
    m_label->setCurrentIndex(m_label->findText(current));
    if(m_editable && m_current.contains("aucune", Qt::CaseInsensitive))
    {
        m_push->setEnabled(false);
    }
    else if(m_editable && !m_current.contains("aucune", Qt::CaseInsensitive))
    {
        m_push->setEnabled(true);
    }
    else if(!m_editable && (m_spin->maximum() == 1 || m_current.contains("aucune", Qt::CaseInsensitive)))
    {
        m_spin->setEnabled(false);
    }
    else if(!m_editable && m_spin->maximum() > 1 && !m_current.contains("aucune", Qt::CaseInsensitive))
    {
        m_spin->setEnabled(true);
    }
}

WidgetCouple::~WidgetCouple()
{
    delete m_label;
    if(m_spin != 0)
    {
        delete m_spin;
    }
    else
    {
        delete m_push;
    }
    delete m_layout;
}

void WidgetCouple::addItems(const QStringList& liste)
{
    QStringList list;
    list<<liste;
    m_label->clear();
    m_label->addItems(list);
}

void WidgetCouple::setMaximum(int max)
{
    if(m_spin != 0)
    {
        if(!m_current.contains("Aucune"))
        {
            m_spin->setMinimum(1);
            m_spin->setMaximum(max);
            if(max == 1)
            {
                m_spin->setEnabled(false);
            }
            else
            {
                m_spin->setEnabled(true);
            }
        }
        else
        {
            m_spin->setMinimum(1);
            m_spin->setMaximum(max);
            m_spin->setEnabled(false);
        }
    }
}
void WidgetCouple::setNom(QString nom)
{
    m_nomCat = nom;
}

QString WidgetCouple::getNom()
{
    return m_nomCat;
}


void WidgetCouple::operator =(const WidgetCouple& couple)
{
    m_label = new QComboBox(couple.m_label->parentWidget());
    m_label = couple.m_label;


    m_layout = new QHBoxLayout(couple.m_layout->parentWidget());
    m_layout->addWidget(m_label);

    if(couple.m_spin != 0)
    {
        m_spin = new QSpinBox(couple.m_spin->parentWidget());
        m_spin->setValue(couple.m_spin->value());
        m_layout->addWidget(m_spin);
        m_push = 0;
    }
    else
    {
        m_spin = 0;
        m_push = new QPushButton("Editer");
        m_layout->addWidget(m_push);
    }
}

QString WidgetCouple::getCurrent()
{
    return m_current;
}

void WidgetCouple::changementDeValeur(int valeur)
{
    emit changement(this, false);
}

void WidgetCouple::setValue(int value)
{
    m_spin->setValue(value);
}

void WidgetCouple::changementText(QString texte)
{
    if(!texte.contains("Aucune") && m_current.contains("Aucune"))
    {
        if(m_spin != 0)
        {
            m_spin->setEnabled(true);
            m_spin->setValue(1);
            emit rajout(this, 1, texte);
        }
        else
        {
            m_push->setEnabled(true);
            emit rajout(this, 1, texte);
        }
    }
    else if(!texte.contains("Aucune") && !m_current.contains("Aucune"))
    {
        if(m_spin != 0)
        {
            emit rajout(this, 2, texte);
        }
        else
        {
            emit rajout(this, 2, texte);
        }
    }
    else
    {
        if(m_spin != 0)
        {
            m_spin->setEnabled(false);
            emit rajout(this, 3, m_current);
        }
        else
        {
            m_push->setEnabled(false);
            emit rajout(this, 3, m_current);
        }
    }
    m_current = texte;
}

QStringList WidgetCouple::getItem()
{
    QStringList liste;
    for(int i = 0; i < m_label->count(); i++)
    {
        liste<<m_label->itemText(i);
    }
    return liste;
}

void WidgetCouple::edition()
{
    emit edition(this);
}
