#ifndef UNITEWARHAMMER40KV5_H
#define UNITEWARHAMMER40KV5_H

#include "Header/Model/unite.h"

class UniteWarhammer40KV5: public Unite
{
private:
    QMultiMap<QString, QMultiMap<QString, int> > m_Equipement_Actuel;
    QMap<QString, QVector<int> >m_editable;

public:
    UniteWarhammer40KV5();
    UniteWarhammer40KV5(const UniteWarhammer40KV5&);

    QMultiMap<QString, QMultiMap<QString, int> > & getEquipementAct();
    QVector<int>& getEditable(QString);
    QMap<QString, QVector<int> >& getEditable();

    void ajoutEquipement(const QPair<QString, int>, QString);
    void suppressionEquipement(const QString, int, QString);
    void ajouteEditable(QString, int, int);
    void supprimeEditable(QString, int);

    void setCoutAct();

    void operator = (UniteWarhammer40KV5&);
    friend bool operator ==(const UniteWarhammer40KV5&, const UniteWarhammer40KV5&);
};

#endif // UNITEWARHAMMER40KV5_H
