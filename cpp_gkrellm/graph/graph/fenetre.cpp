#include "fenetre.h"

Fenetre::Fenetre(int x, int y) : QWidget()
{
    setFixedSize(x, y);
    m_button = new QPushButton("QUIT", this);
    m_button->setFont(QFont("Arial", 18));
    m_button->setCursor(Qt::PointingHandCursor);
    m_button->move(100, 100);

    QObject::connect(m_button, SIGNAL(clicked()), qApp, SLOT(quit()));

}
