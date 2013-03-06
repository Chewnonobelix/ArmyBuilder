#ifndef EXPORT_H
#define EXPORT_H

#include <QDialog>
#include <QString>

namespace Ui {
class Exporte;
}

class Exporte : public QDialog
{
    Q_OBJECT
    
public:
    explicit Exporte(QString, QWidget *parent = 0);
    ~Exporte();
    
private:
    Ui::Exporte *ui;
};

#endif // EXPORT_H
