#ifndef WIDGETPAGEEDITABLE_H
#define WIDGETPAGEEDITABLE_H

#include <QWidget>
#include <QVBoxLayout>
#include "Header/Vue/widgetcouple.h"
#include "Header/Model/accompagnant.h"
#include "Header/Model/unite.h"
#include "Header/Model/enum.h"
#include <QMessageBox>

class WidgetPageEditable : public QWidget
{
    Q_OBJECT

private:
    QString m_nom;
    int m_nb;
    QVector<WidgetCouple*> m_vecteur;
    QVBoxLayout* m_layout;
    Accompagnant m_accomp;

public:
    explicit WidgetPageEditable(Accompagnant,int , QWidget *parent = 0);
    void editable(QVector<QString>);
    void change(int);
    QString getNom();
    ~WidgetPageEditable();

signals:
    void enleve(QString, int);
    void rajoute(QString, int);
    void editions(QString, int);
public slots:
    void edition(WidgetCouple*);
    void rajout(WidgetCouple*, int, QString);
};

#endif // WIDGETPAGEEDITABLE_H
