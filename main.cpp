#include <QApplication>
#include "mainwindow.h"
#include "Game.h"

game* game::thegame=NULL;

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MainWindow fenetre;
    fenetre.show();




    return app.exec();
}
