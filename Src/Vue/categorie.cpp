#include "Header/Vue/categorie.h"
#include "ui_categorie.h"
#include <QInputDialog>
#include <QStringList>
#include <QMessageBox>

Categorie::Categorie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Categorie)
{
    ui->setupUi(this);
}

Categorie::~Categorie()
{
    delete ui;
}

