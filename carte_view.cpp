#include "carte_view.h"
#include "Game.h"
#include "joueur_view.h"
#include <QIcon>

Carte_view:: Carte_view(QWidget *parent, int v):
    QToolButton(parent)
{
    position = -1;
    //this->setText(v.data());

    back = new QIcon("./Images/letter.jpg");
    switch (v)
    {
        case 1 : image = new QIcon("./Images/1.jpg");
                            break;
        case 2 : image = new QIcon("./Images/2.jpg");
                            break;
        case 3 : image = new QIcon("./Images/3.jpg");
                        break;
        case 4 : image = new QIcon("./Images/4.jpg");
                       break;
        case 5 : image = new QIcon("./Images/5.jpg");
                        break;
        case 6 : image = new QIcon("./Images/6.jpg");
                        break;
        case 7 : image = new QIcon("./Images/7.jpg");
                        break;
        case 8 : image = new QIcon("./Images/8.jpg");
                        break;
    }

    this->setFixedSize(300/2,400/2);
    this->setIconSize(QSize(300/2,400/2));

    this->setIcon(*image);


    QObject::connect(this, SIGNAL(clicked()), this, SLOT(click()));
}

void Carte_view::click(){
    if(dynamic_cast<Joueur_view*>(this->parentWidget())->mustplay)
    {
        dynamic_cast<Joueur_view*>(this->parentWidget())->mustplay=false;
        game::thegame->resume(position);
    }



}

void Carte_view::unveil(){
    this->setIcon(*image);
}

void Carte_view::veil(){
    this->setIcon(*back);
}
