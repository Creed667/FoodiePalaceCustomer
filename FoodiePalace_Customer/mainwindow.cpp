#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// when login button is pressed
void MainWindow::on_logInButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_loginPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

