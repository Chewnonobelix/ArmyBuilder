#ifndef NOUVEAU_H
#define NOUVEAU_H

#include <QDialog>
#include <QDir>
#include <QStringList>
#include <QFileInfoList>

namespace Ui {
class Nouveau;
}

class Nouveau : public QDialog
{
    Q_OBJECT
    
public:
    explicit Nouveau(QWidget *parent = 0);
    ~Nouveau();

    void get(bool&, int&, QString&, QString&, QString&);
    
private:
    Ui::Nouveau *ui;

    QString m_nb;
    QString m_limite;
    void info();

private slots:
    void armee(QString);
    void limite(int);
    void nb(int);
    void depasse(int);

};

#endif // NOUVEAU_H
