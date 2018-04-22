#ifndef JOUEUR_VIEW_H
#define JOUEUR_VIEW_H

#include <QFrame>
#include <QLayout>
#include "carte_view.h"
#include "QLabel"

class Joueur_view : public QFrame
{
      Q_OBJECT


public:
    Joueur_view(QWidget *parent =0);
 //   void pioche(Carte_view* carte);
    void turnOn();
    void turnOff();
    void drawCard(Carte_view* carte, int position);
    void discardCard(Carte_view* carte);
    bool mustplay;
    void Veliminate();
    void Vprotected();
    void VignoreEverything();
    void VstopIgnore();
    void Vslide(Carte_view* cv);

private :
    int cartes_en_mains;
    int cartes_defausse;
    QGridLayout *Layout;
    QLabel* ignore;
};


#endif // JOUEUR_VIEW_H
