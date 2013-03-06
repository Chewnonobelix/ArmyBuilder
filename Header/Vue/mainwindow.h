#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QTableWidgetItem>
#include <QCheckBox>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>
#include <QDir>
#include <QPushButton>
#include <QLineEdit>
#include <QtXml>
#include <QMultiMap>
#include <QList>
#include <QPair>
#include <QString>
#include "Header/Model/enum.h"
#include "Header/Model/model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void enable(bool);
    void limite(int);
    void setModel(Model* );
    Model* getModel();
    ~MainWindow();

public slots:
    void aProposeQt();

private slots:
    void nouveau();
    void fermer();

private:
    Ui::MainWindow *ui;
    Model* m_model;

signals:
    void s_nouveau();
};

#endif // MAINWINDOW_H
