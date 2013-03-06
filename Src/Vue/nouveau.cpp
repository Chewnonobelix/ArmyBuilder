#include "Header/Vue/nouveau.h"
#include "ui_nouveau.h"

Nouveau::Nouveau(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nouveau)
{
    ui->setupUi(this);

    QDir dir;
    dir.cd("Data");
    QFileInfoList info = dir.entryInfoList();
    QStringList list;
    for(int i = 0; i < info.count(); i++)
    {
        if(info.at(i).isDir() && info.at(i).fileName() != "." && info.at(i).fileName() != "..")
        {
            list << info.at(i).baseName().replace("_", " ");
        }
    }
    ui->w_jeux->addItems(list);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(depasse(int)));
    connect(ui->w_nombre, SIGNAL(valueChanged(int)), this, SLOT(limite(int)));
    connect(ui->w_jeux, SIGNAL(currentIndexChanged(QString)), this, SLOT(armee(QString)));
    connect(ui->w_nb, SIGNAL(stateChanged(int)), this, SLOT(nb(int)));
    armee(ui->w_jeux->currentText());

    m_limite = "Limite en nombre de points desactiver";
    m_nb = "Limite en nombre d'unité desactiver";

    this->info();
}

Nouveau::~Nouveau()
{
    delete ui;
}

void Nouveau::armee(QString jeux)
{
    QDir dir;
    dir.cd("Data\\" + jeux.replace(" ", "_") +"\\Armee");

    QFileInfoList info = dir.entryInfoList();
    QStringList list;
    for(int i = 0; i < info.count(); i++)
    {
        if(info.at(i).isFile() &&  info.at(i).suffix() == "xml")
        {
            list << info.at(i).baseName().replace("_", " ");
        }
    }

    ui->w_armee->clear();
    ui->w_armee->addItems(list);
    if(list.empty())
    {
        ui->w_armee->setEnabled(false);
    }
    else
    {
        ui->w_armee->setEnabled(true);
    }
}

void Nouveau::limite(int value)
{
    if(value > 0)
    {
        m_limite = "Limite en nombre de points activer";
        ui->horizontalSlider->setEnabled(true);
    }
    else if(value == 0)
    {
        m_limite = "Limite en nombre de points desactiver";
        ui->horizontalSlider->setValue(0);
        ui->horizontalSlider->setEnabled(false);
    }
    this->info();
}

void Nouveau::nb(int state)
{
    switch(state)
    {
    case Qt::Checked:
        m_nb = "Limite en nombre d'unité activer";
        break;
    case Qt::Unchecked:
        m_nb = "Limite en nombre d'unité desactiver";
        break;
    default :
        break;
    }
    this->info();
}

void Nouveau::get(bool& nb, int& limite, QString& jeux, QString& armee, QString& liste)
{
    nb = ui->w_nb->checkState();
    limite = ui->w_nombre->value();
    liste = ui->w_nom->text();
    armee = ui->w_armee->currentText();
    jeux = ui->w_jeux->currentText();
}

void Nouveau::info()
{
    ui->l_info->setText(m_limite + ", " + m_nb);
}

void Nouveau::depasse(int value)
{
    ui->label_2->setText(QString::number(value) + "%");
}
