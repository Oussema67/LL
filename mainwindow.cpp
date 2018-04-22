#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "Player.h"
#include "Game.h"
#include "ressources.h"
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QInputDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{



    //Set Layout and contained elements
    QGridLayout* Layout = new QGridLayout;
    /*
    joueur1 = new Joueur_view(this);
    joueur2 = new Joueur_view(this);
    joueur3 = new Joueur_view(this);
    joueur4 = new Joueur_view(this);

    */

   // toplabel=new QLabel("Bienvenue au  <Love Letter>!");
   // Layout->addWidget(toplabel,0,0,1,0,0);
    //Layout->addWidget(joueur1,1,0,0);
    //Layout->addWidget(joueur2,1,1,0);
    //Layout->addWidget(joueur3,2,0,0);
    //Layout->addWidget(joueur4,2,1,0);


    //Set layout in a new centralWidget
    QWidget * center = new QWidget();
    center->setLayout(Layout);
    setCentralWidget(center);

    //Start a new Game





    /*   ///////////////////////////////////////////////////      */

   // QWidget *menu = new QWidget(this);


  /* QPushButton *q_bouton = new QPushButton("Quitter", menu);
    q_bouton->setFont(QFont("Comic Sans MS", 14));

    QPushButton * p_bouton = new QPushButton("Jouer", menu);
    p_bouton->setFont(QFont("Comic Sans MS",14));
*/
    this->setStyleSheet("background-image: url(./Images/bg.jpg);");
       // menu->setLayout(Layout);
       // setCentralWidget(menu);
        //p_bouton->move(50, 100);
      //  q_bouton->move(100, 100);


    // Connexion du clic du bouton à la fermeture de l'application


      //  QObject::connect(q_bouton, SIGNAL(clicked()), qApp, SLOT(quit()));
    //    QObject::connect(p_bouton, SIGNAL(clicked()), this, SLOT(PlayGame()));

        PlayGame();

/*
    int answer = QMessageBox::question(this,"aide","do you want some thinks??",QMessageBox::Yes,QMessageBox::No);
    if(answer == QMessageBox::Yes)
    {

        PlayGame();

    }
    else {
        exit(0);
    }
*/


}

void MainWindow::PlayGame()
{

    game::thegame = new game(this);
    game::thegame->howManyPlayers(4);
    game::thegame->setup();
    game::thegame->theGame();
}


MainWindow::~MainWindow()
{
}


void MainWindow::addChildJoueurView(Joueur_view* joueur, int i)
{

    dynamic_cast<QGridLayout*>(this->centralWidget()->layout())->addWidget(joueur,1+i/2,i%2,0);
}


void MainWindow::guessWho()
{

    //toplabel.setText("Selection d'un joueur");
    int p = QInputDialog::getInt(this,tr("IHM"),
                                 tr("Choississez un joueur :"),0,0,4,1,0);
    int what=QInputDialog::getInt(this,tr("IHM"),
                                  tr("Choississez une carte :"),2,2,8,1,0);
    game::thegame->guessWho_resume(p,what);
}

void MainWindow::VCompareWith(){
    int p = QInputDialog::getInt(this,tr("IHM"),
                                 tr("Choississez un joueur :"),0,0,4,1,0);

    game::thegame->compareWith_Resume(p);
}

void MainWindow::VdrawAndDiscard(){
    int p = QInputDialog::getInt(this,tr("IHM"),
                                 tr("Choississez un joueur :"),0,0,4,1,0);

    game::thegame->drawAndDiscard_Resume(p);
}

void MainWindow::VtradeWith(){
    int p = QInputDialog::getInt(this,tr("IHM"),
                                 tr("Choississez un joueur :"),0,0,4,1,0);

    game::thegame->tradeWith_Resume(p);

}





/*
void MainWindow::feedback_findetours(int prochain_joueur)
{
    this->centralWidget()->layout()->
}

*/




/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->toolButton->hide();
    ui->toolButton_3->hide();
    ui->toolButton_6->hide();
    ui->toolButton_7->hide();


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_toolButton_clicked()
{
    QToolButton* sender = qobject_cast<QToolButton *>(QObject::sender());
    QIcon *image;


    int pioche = Jeu::jeu.pioche();
    switch (pioche)
    {
        case 1 : image = new QIcon("1.jpg");
                            break;
        case 2 : image = new QIcon("2.jpg");
                            break;
        case 3 : image = new QIcon("3.jpg");
                        break;
        case 4 : image = new QIcon("4.jpg");
                       break;
        case 5 : image = new QIcon("5.jpg");
                        break;
        case 6 : image = new QIcon("6.jpg");
                        break;
        case 7 : image = new QIcon("7.jpg");
                        break;
        case 8 : image = new QIcon("8.jpg");
                        break;
    }


    sender->setIcon(*image);
}


void MainWindow::on_toolButton_2_clicked()
{
    QIcon *image;
    int pioche = Jeu::jeu.pioche();

    //image->~QIcon();
    switch (pioche)
    {
        case 1 : image = new QIcon("1.jpg");
                            break;
        case 2 : image = new QIcon("2.jpg");
                            break;
        case 3 : image = new QIcon("3.jpg");
                        break;
        case 4 : image = new QIcon("4.jpg");
                       break;
        case 5 : image = new QIcon("5.jpg");
                        break;
        case 6 : image = new QIcon("6.jpg");
                        break;
        case 7 : image = new QIcon("7.jpg");
                        break;
        case 8 : image = new QIcon("8.jpg");
                        break;
    }

    QToolButton* sender = qobject_cast<QToolButton *>(QObject::sender());
    sender->setIcon(*image);

    ui->toolButton->show();
}

*/
