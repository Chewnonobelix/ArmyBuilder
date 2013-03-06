#include "Module/Warhammer40KV5/unitewarhammer40kv5.h"

UniteWarhammer40KV5::UniteWarhammer40KV5()
{
}

UniteWarhammer40KV5::UniteWarhammer40KV5(const UniteWarhammer40KV5& u):Unite(u)
{
    m_Equipement_Actuel = ((UniteWarhammer40KV5)u).getEquipementAct();
    m_editable = ((UniteWarhammer40KV5)u).getEditable();
}

QMap<QString, QVector<int> >& UniteWarhammer40KV5::getEditable()
{
    return m_editable;
}

void UniteWarhammer40KV5::ajouteEditable(QString nom, int id, int place)
{
    m_editable[nom].insert(place, id);
}

void UniteWarhammer40KV5::supprimeEditable(QString nom, int id)
{
    m_editable[nom].remove(id);
}

QVector<int>& UniteWarhammer40KV5::getEditable(QString nom)
{
    return m_editable[nom];
}

void UniteWarhammer40KV5::ajoutEquipement(const QPair<QString, int> equipement, QString cat)
{
    if(m_Equipement_Actuel.contains(cat))
    {
        m_Equipement_Actuel.find(cat).value().insert(equipement.first, equipement.second);
    }
    else
    {
        QMultiMap<QString, int> map;
        map.insert(equipement.first, equipement.second);
        m_Equipement_Actuel.insert(cat, map);
    }
    setCoutAct();
}

void UniteWarhammer40KV5::suppressionEquipement(const QString equipement, int cout, QString cat)
{
    m_Equipement_Actuel.find(cat).value().remove(equipement, cout);
    setCoutAct();
}

QMultiMap<QString, QMultiMap<QString, int> >& UniteWarhammer40KV5::getEquipementAct()
{
    return m_Equipement_Actuel;
}

void UniteWarhammer40KV5::operator = (UniteWarhammer40KV5& u)
{
    Unite::operator =(u);
    m_Equipement_Actuel = u.getEquipementAct();
    m_editable = u.getEditable();
}

bool operator ==(const UniteWarhammer40KV5& a, const UniteWarhammer40KV5& b)
{
    return ((UniteWarhammer40KV5)a).getId()== ((UniteWarhammer40KV5)b).getId();
}

void UniteWarhammer40KV5::setCoutAct()
{

}
