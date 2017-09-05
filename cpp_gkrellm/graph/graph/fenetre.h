#ifndef FENETRE_H
#define FENETRE_H

#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QPushButton>

class Fenetre : public QWidget
{
public:
    Fenetre(int,int);

private:
    QPushButton *m_button;
};

#endif /* !FENETRE_H */
