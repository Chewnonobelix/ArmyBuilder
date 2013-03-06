#include "Header/Vue/tableau.h"

Tableau::Tableau(QWidget* parent): QTableWidget(parent)
{
    setMouseTracking(true);
}

void Tableau::mouseMoveEvent(QMouseEvent * event)
{
    if(itemAt(event->pos()) != NULL)
    {
        int col = column(itemAt(event->pos()));
        QString nom = horizontalHeaderItem(col)->text();
        if((nom == "Editer" || nom == "Supprimer" || nom == "Type" || itemAt(event->pos())->text() == "Ajouter"))
        {
            setCursor(Qt::PointingHandCursor);
        }
        else
        {
            setCursor(Qt::ArrowCursor);
        }
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}
