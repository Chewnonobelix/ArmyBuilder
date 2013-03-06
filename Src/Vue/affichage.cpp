#include "Header/Vue/affichage.h"
#include "ui_affichage.h"
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <cmath>
#include <QList>
#include <QTabWidget>
#include "Header/Vue/widgetpage.h"
#include <QRegExp>
#include <QPair>
#include <QRegExp>

Affichage::Affichage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Affichage)
{
    ui->setupUi(this);
}

Affichage::~Affichage()
{

}
