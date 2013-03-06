#include "Header/Vue/liste.h"

Liste::Liste(QWidget * parent): QListWidget(parent)
{

}

void Liste::mouseMoveEvent(QMouseEvent * event)
{
    if(itemAt(event->pos()) != NULL)
    {
        setCursor(Qt::PointingHandCursor);
    }
    else
    {
        setCursor(Qt::ArrowCursor);
    }
}
