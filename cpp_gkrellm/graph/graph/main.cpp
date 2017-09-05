#include "QApplication"
#include "fenetre.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Fenetre fenetre(500, 500);

    //affichage fenetre
    fenetre.show();

    return app.exec();
}
