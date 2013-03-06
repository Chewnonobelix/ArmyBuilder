#ifndef LISTE_H
#define LISTE_H

#include<QListWidget>
#include <QMouseEvent>

class Liste: public QListWidget
{
public:
    Liste(QWidget* = 0);
    void mouseMoveEvent(QMouseEvent *);

};

#endif // LISTE_H
