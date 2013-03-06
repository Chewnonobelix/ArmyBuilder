#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QDialog>
#include <QVector>
#include <QMultiMap>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include <QPair>
#include <QVector>
#include "Header/Vue/widgetpage.h"
#include "Header/Vue/widgetpageeditable.h"
#include "Header/Model/codex.h"
#include "Header/Model/enum.h"
#include "Header/Vue/info.h"

namespace Ui {
class Affichage;
}

class Affichage : public QDialog
{
    Q_OBJECT

public:
    explicit Affichage(QWidget *parent = 0);
    ~Affichage();

private:
    Ui::Affichage *ui;

public slots:

private slots:

signals:

};

#endif // AFFICHAGE_H
