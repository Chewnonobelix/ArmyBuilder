#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include <QListWidgetItem>
#include "Header/Model/unite.h"
#include "Header/Model/arme.h"
#include "Header/Model/item.h"
#include <QMessageBox>

namespace Ui {
class Info;
}

class Info : public QDialog
{
    Q_OBJECT
    
public:
    explicit Info(QWidget *parent = 0);
    ~Info();
    void setUnite(Unite*);
    
private:
    Ui::Info *ui;


private slots:


signals:

};

#endif // INFO_H
