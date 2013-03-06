#include "Header/Vue/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setEnabled(false);
    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(fermer()));
    connect(ui->actionNouveau, SIGNAL(triggered()), this, SLOT(nouveau()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aProposeQt()
{
    QMessageBox::aboutQt(0, "Qt");
}

void MainWindow::fermer()
{
    close();
}

void MainWindow::nouveau()
{
    emit s_nouveau();
}

void MainWindow::enable(bool ok)
{
    ui->centralwidget->setEnabled(ok);
}

void MainWindow::limite(int l)
{
    ui->progressBar->setMaximum(l);
    ui->progressBar->setFormat("%v/" + QString::number(l));
}

void MainWindow::setModel(Model * m)
{
    m_model = m;

    setWindowTitle(getModel()->getListe()->getNomListe()+" "+getModel()->getListe()->getNomArmee());
    QStringList nomCategorie = getModel()->getCodex().keys();
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(nomCategorie.size());
    ui->tableWidget->setVerticalHeaderLabels(nomCategorie);
    nomCategorie.clear();
    nomCategorie<<"Points"<<"Editer"<<"Vider";
    ui->tableWidget->setHorizontalHeaderLabels(nomCategorie);
    ui->tableWidget->setMouseTracking(true);
    ui->tableWidget->setEnabled(true);
    for(int i =0; i <ui->tableWidget->rowCount(); i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem("Editer");
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->setItem(i,1,item);
        QTableWidgetItem* item2 = new QTableWidgetItem("Vider");
        item2->setData(Qt::CheckStateRole, "Vider");
        item2->setFlags(item2->flags()|Qt::ItemIsUserCheckable);
        item2->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(i,2, item2);
        item = new QTableWidgetItem(QString::number(0));
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        ui->tableWidget->setItem(i,0,item);
    }
}

Model* MainWindow::getModel()
{
    return m_model;
}
