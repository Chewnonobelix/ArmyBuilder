#ifndef WIDGETCOUPLE_H
#define WIDGETCOUPLE_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QStringList>
#include <QPushButton>

class WidgetCouple : public QWidget
{
    Q_OBJECT
private:
    QPushButton* m_push;
    QComboBox* m_label;
    QSpinBox* m_spin;
    QHBoxLayout* m_layout;
    QString m_nomCat;
    bool m_editable;
    QString m_current;

public:
    explicit WidgetCouple(QString, bool = false, int = 1, QWidget *parent = 0);
    WidgetCouple(const WidgetCouple&);
    ~WidgetCouple();
    void addItems (const QStringList&);
    void setMaximum(int);
    void setNom(QString);
    QString getNom();
    QString getCurrent();
    int getMax();
    int getValue();
    void setValue(int);
    void operator =(const WidgetCouple&);
    void setCurrent(QString);
    void enleve(QString);
    void ajoute(QString);
    QStringList getItem();

signals:
    void changement(WidgetCouple*,bool);
    void rajout(WidgetCouple*, int, QString);
    void edition(WidgetCouple*);

public slots:
    
private slots:
    void changementDeValeur(int);
    void changementText(QString);
    void edition();
};

#endif // WIDGETCOUPLE_H
