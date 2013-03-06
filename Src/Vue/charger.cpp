#include "Header/Vue/charger.h"
#include "ui_charger.h"

Charger::Charger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Charger)
{
    ui->setupUi(this);

    QDir dir("Liste\\");

    foreach (QFileInfo info, dir.entryInfoList())
    {
        if(info.isFile())
        {
            ui->listWidget->addItem(info.baseName());
        }
    }

    connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClique(QListWidgetItem*)));
}

Charger::~Charger()
{
    delete ui;
}

QString Charger::recup()
{
    return ui->listWidget->currentItem()->text();
}

void Charger::accept()
{
    if(ui->listWidget->count() != 0 && ui->listWidget->currentRow() >= 0)
    {
        done(QDialog::Accepted);
    }
    else
    {
        done(QDialog::Rejected);
    }

    close();
}


void Charger::doubleClique(QListWidgetItem * item)
{
    accept();
}
