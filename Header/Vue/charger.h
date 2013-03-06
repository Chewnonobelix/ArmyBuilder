#ifndef CHARGER_H
#define CHARGER_H

#include <QDialog>
#include <QDir>
#include <QMessageBox>
#include <QListWidgetItem>

namespace Ui {
class Charger;
}

class Charger : public QDialog
{
    Q_OBJECT
    
public:
    explicit Charger(QWidget *parent = 0);
    ~Charger();
    QString recup();
private:
    Ui::Charger *ui;

public slots:
    void accept();
    void doubleClique(QListWidgetItem*);
};

#endif // CHARGER_H
