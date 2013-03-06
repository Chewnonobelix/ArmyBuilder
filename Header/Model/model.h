#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "Header/Model/codex.h"
#include "Header/Model/unitefactory.h"

class Model : public QObject
{
    Q_OBJECT

private:
    QString m_nomJeux;
    Codex* m_liste;
    QMap<QString, QMap<QString, EntreeCodex*> >m_codex;
    QMap<QString, int> m_limite;
    UniteFactory* m_factory;

public:
    explicit Model(QObject *parent = 0);

    void setNomJeux(QString);
    void setliste(Codex* );
    void addLimite(QString, int);
    void setFactory(UniteFactory*);

    QString getNomJeux();

    Codex* getListe();
    QMap<QString, QMap<QString, EntreeCodex*> >& getCodex();
    QMap<QString, EntreeCodex*>& getCodex(QString);
    QMap<QString, int>& getLimite();
    UniteFactory* getFactory();

signals:
    
public slots:
    
};

#endif // MODEL_H
