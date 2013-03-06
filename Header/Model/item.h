#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    Item();
    Item(const Item&);
    Item(QString, QString);
    QString getNom();
    QString getDes();

private:
    QString m_nom;
    QString m_description;
};

#endif // ITEM_H
