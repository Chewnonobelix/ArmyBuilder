#include "Header/Vue/export.h"
#include "ui_export.h"

Exporte::Exporte(QString texte, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exporte)
{
    ui->setupUi(this);

    ui->textBrowser->setText(texte);
}

Exporte::~Exporte()
{
delete ui;
}
