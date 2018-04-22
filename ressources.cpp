#include "ressources.h"
#include <string>


QIcon* ressources::cartes[8];

void ressources::init()
{

        cartes[0] = new QIcon("1.jpg");
        cartes[1] = new QIcon("2.jpg");
        cartes[2] = new QIcon("3.jpg");
        cartes[3] = new QIcon("4.jpg");
        cartes[4] = new QIcon("5.jpg");
        cartes[5] = new QIcon("6.jpg");
        cartes[6] = new QIcon("7.jpg");
        cartes[7] = new QIcon("8.jpg");

}




