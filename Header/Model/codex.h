#ifndef CODEX_H
#define CODEX_H

#include <QString>
#include <QMultiMap>
#include <QVector>
#include <QFile>
#include <QMessageBox>
#include <QList>
#include <QtXml>
#include "Header/Model/unite.h"


class Codex
{

private:
    QString m_nomArmee;
    QString m_nomListe;
    QMap<QString, QMap<int, Unite*> > m_liste;

public:
    Codex();
    ~Codex();

    QString getNomArmee();
    QString getNomListe();
    QMap<QString, QMap<int, Unite*> >& getListe();
    QMap<int, Unite*>& getListe(QString);

    void setNomArmee(QString);
    void setNomListe(QString);
    void addUnite(QString, Unite*);
    void removeUnite(int);
};

#endif // CODEX_H
