#include "Header/Model/item.h"

Item::Item()
{

}

Item::Item(QString nom, QString des)
{
    m_nom = nom;
    m_description = des;
}

Item::Item(const Item & i)
{
    m_nom = i.m_nom;
    m_description = i.m_description;
}

QString Item::getDes()
{
    return m_description;
}

QString Item::getNom()
{
    return m_nom;
}
