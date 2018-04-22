#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joueur_view.h"
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private :
/*
Joueur_view *joueur1;
Joueur_view *joueur2;
Joueur_view *joueur3;
Joueur_view *joueur4;
*/

 public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addChildJoueurView(Joueur_view* joueur, int i);
    void guessWho();
    void VCompareWith();
    void VdrawAndDiscard();
    void VtradeWith();
    QLabel* toplabel;
    //void feedback_findetours(int prochain_joueur);






public slots:
void PlayGame();
/*

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::MainWindow *ui;
*/

};

#endif // MAINWINDOW_H
