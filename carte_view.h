#ifndef CARTE_VIEW_H
#define CARTE_VIEW_H

#include <QToolButton>
#include <QIcon>
#include <string>
using namespace std;

class Carte_view : public QToolButton
{
    Q_OBJECT

public :
    Carte_view(QWidget * parent= 0,int v=0);
    int position;
    QIcon *image;
    QIcon *back;
    void veil();
    void unveil();

public slots :
   void click();



};



#endif // CARTE_VIEW_H

