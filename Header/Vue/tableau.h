#ifndef TABLEAU_H
#define TABLEAU_H

#include <QTableWidget>
#include <QMessageBox>
#include <QMouseEvent>

class Tableau: public QTableWidget
{
public:
    Tableau(QWidget* = 0);
    void mouseMoveEvent(QMouseEvent *);
};

#endif // TABLEAU_H
