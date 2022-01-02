#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// when login button is pressed it will go to login page
void MainWindow::on_logInButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

//when login back button is pressed it will go to welcome page
void MainWindow::on_loginPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


// when register back button is pressed
void MainWindow::on_registerPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// going to register page by clicking registerButton
void MainWindow::on_RegisterButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

