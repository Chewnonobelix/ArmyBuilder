#ifndef CONTROLLEURCHARGEMENT_H
#define CONTROLLEURCHARGEMENT_H

#include <QString>
#include <QMessageBox>
#include "Header/Controlleur/controlleur.h"

class ControlleurChargement: public Controlleur
{
public:
    ControlleurChargement();
    void exec(); //Charge une liste préablement sauvegarder
    bool chargerNouveau(QString, QString);
};

#endif // CONTROLLEURCHARGEMENT_H
