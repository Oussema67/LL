#include "joueur_view.h"
#include "carte_view.h"
#include <QGridLayout>
#include <QSpacerItem>
#include <QLabel>
Joueur_view::Joueur_view(QWidget * parent):
    QFrame(parent,0)
{
    cartes_defausse = 0;
    mustplay=false;
    //Style of the frame
    this->setFrameStyle(QFrame::Panel);
    this->setLineWidth(3);


    //Managing Layout and children widget
     Layout = new QGridLayout;

     //Carte_view *carte1= new Carte_view(this);
     //Layout->addWidget(carte1,1,1,0);

     //Carte_view *carte2= new Carte_view(this);
     //Layout->addWidget(carte2,1,2,0);


     //carte1->hide();
     this->setLayout(Layout);

     ignore = new QLabel(this);
     ignore->setText("protected until next turn.");
     ignore->hide();

}

void Joueur_view::turnOn(){

    this->setLineWidth(6);
    mustplay=true;
}

void Joueur_view::turnOff(){
    this->setLineWidth(3);
    mustplay=false;
}

void Joueur_view::drawCard(Carte_view* carte, int position){
    //Animation de pioche????
    Layout->addWidget(carte,0,position-1,0);
    carte->position=position-1;

}

void Joueur_view::discardCard(Carte_view* carte){
    //Animation de défausse?
    //Petit bug, si défausse deux fois la même carte ça affiche pas de doublon
    Layout->removeWidget(carte);
    Layout->addWidget(carte,1,cartes_defausse,0);
    cartes_defausse++;
}

void Joueur_view::Veliminate(){
    QLabel* end = new QLabel(this);
   //QIcon *fin = new QIcon("illiminer.jpg");
   // end->setPixmap(QPixmap("elliminer.jpg"));
    end->setText("Joueur elimine.");
  //  Layout->addWidget(end,3,0,0);
  //  end->setFixedSize(100,80);
   // end->setIconSize(QSize(300/2,400/2));

}

void Joueur_view::Vprotected(){
     QLabel* protect = new QLabel(this);
      protect->setText("protected until next turn.");
}

void Joueur_view::VignoreEverything(){
    Layout->addWidget(ignore,3,0,0);
    ignore->show();
}

void Joueur_view::VstopIgnore(){
    Layout->removeWidget(ignore);
    ignore->hide();
}

void Joueur_view::Vslide(Carte_view *cv){
    Layout->removeWidget(cv);
    Layout->addWidget(cv,0,0,0);
    cv->position=0;
}

/*
void pioche(Carte_view* carte){

    Layout->addWidget(carte,0,cartes_en_mains,0);
}
*/

