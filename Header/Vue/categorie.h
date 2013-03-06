#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QDialog>
#include "Header/Vue/affichage.h"
#include <QSet>
#include <QString>
#include <QTableWidgetItem>
#include <QMultiMap>

namespace Ui {
class Categorie;
}

class Categorie : public QDialog
{
    Q_OBJECT
    
public:
    explicit Categorie(QWidget *parent = 0);
    ~Categorie();

    
private:
    Ui::Categorie *ui;

public slots:

signals:

};

#endif // CATEGORIE_H
