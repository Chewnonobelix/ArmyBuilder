#ifndef WIDGETPAGE_H
#define WIDGETPAGE_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QVBoxLayout>
#include "Header/Vue/widgetcouple.h"
#include "Header/Model/equipement.h"
#include "Header/Model/enum.h"

class WidgetPage : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetPage(Equipement*, QMultiMap<QString, int>&, int = 1, QWidget *parent = 0);
    ~WidgetPage();
    Equipement* getActuel();
    void setMax(int);
    QString getTitre();
    void setTitre(QString);
    int getMax();
    void setNb(int);
    QVector<WidgetCouple*>& getVecteur();
    void ext(QString, int);

    
private:
    QVBoxLayout* m_layout;
    QVector<WidgetCouple*> m_vecteur;
    QString m_titre;
    Equipement* m_actuel;
    int m_nb;
    int m_max;


public slots:
    void changement(WidgetCouple*, bool);
    void rajout(WidgetCouple*, int, QString);

signals:
    void exclus(WidgetPage*, bool);
    
};

#endif // WIDGETPAGE_H
