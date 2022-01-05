#include "mainwindow.h"
#include "ui_mainwindow.h"

QVector<User> usersInfoArray;
class User userObject;

QVector<Food> foodInfoArray;
class Food foodObject;
long long userTotalBill;

void readUserFile()
{
      QString userName;
      QString mobileNumber;
      int userAge;
      QString userGender;
      QString password;
     // QVector<history> userHistory;
      QString temp1;
      int historySize;
      history tempHistory;

      QFile file("D:\\Source code\\FoodiePalace_CustomerVersion\\FoodiePalace_Customer\\users.txt");

      if (!file.open(QFile::ReadOnly | QFile::Text))
      {
        qDebug() << "Not Ok 2";
        return;
      }
      QTextStream in(&file);
      usersInfoArray.clear();
      //base=0;
      while (!in.atEnd())
      {
        userName = in.readLine();
        temp1 = in.readLine();
        userGender = in.readLine();
        mobileNumber = in.readLine();
        password = in.readLine();
        userAge = temp1.split(" ")[0].toInt();
        temp1 = in.readLine();
        historySize = temp1.split(" ")[0].toInt();
        for(int i=0;i<historySize;i++)
        {
        tempHistory.foodname  = in.readLine();
        tempHistory.amount = in.readLine();
        tempHistory.bill = in.readLine();
        tempHistory.date = in.readLine();
        userObject.userHistory.push_back(tempHistory);
        }
        userObject.setAllUserInfo(userName,userAge,userGender,mobileNumber,password);
        usersInfoArray.push_back(userObject);

      }
}
void saveUserFile()
{
    qDebug() <<"file writing";
  QFile file("D:\\Source code\\FoodiePalace_CustomerVersion\\FoodiePalace_Customer\\users.txt");
  QFile file2("D:\\Source code\\FoodiePalace_CustomerVersion\\FoodiePalace_Customer\\orderHistory.txt");

  if (!file.open(QFile::WriteOnly | QFile::Text))
  {
    qDebug() << "Not ok";
    return;
  }
  if (!file2.open(QFile::WriteOnly | QFile::Text))
  {
    qDebug() << "Not ok2";
    return;
  }

  QTextStream out(&file);
  QTextStream out2(&file2);
  for (int i = 0; i < usersInfoArray.size(); i++)
  {
    QString temp1;
    out << usersInfoArray[i].getUserName() << "\n";
    temp1 = QString::number(usersInfoArray[i].getUserAge());
    out << temp1 << "\n";
    out << usersInfoArray[i].getUserGender() << "\n";
    out << usersInfoArray[i].getMobileNumber() << "\n";
    out << usersInfoArray[i].getPassword() << "\n";
    out << usersInfoArray[i].userHistory.size() <<"\n";
    for(int j=0;j< usersInfoArray[i].userHistory.size();j++)
    {
        out << usersInfoArray[i].userHistory[j].foodname<<"\n";
        out << usersInfoArray[i].userHistory[j].amount<<"\n";
        out << usersInfoArray[i].userHistory[j].bill<<"\n";
        out << usersInfoArray[i].userHistory[j].date<<"\n";

        //writing in orderHistory file which will be read in Owner version program
        //this should be the common file between two version of programs
        out2 << usersInfoArray[i].userHistory[j].foodname<<"\n";
        out2 << usersInfoArray[i].userHistory[j].amount<<"\n";
        out2 << usersInfoArray[i].userHistory[j].bill<<"\n";
    }
    }

  }

void showFile()
{
    for(int i=0;i<usersInfoArray.size();i++)
    {
    qDebug() <<usersInfoArray[i].getUserName();
    qDebug() <<usersInfoArray[i].getMobileNumber();
    qDebug() <<usersInfoArray[i].getPassword();
    qDebug() <<usersInfoArray[i].getUserAge();
    qDebug() <<usersInfoArray[i].getUserGender();
    qDebug() <<usersInfoArray[i].userHistory.size();
    for(int j=0;j<usersInfoArray[i].userHistory.size();j++)
    {
        qDebug() <<usersInfoArray[i].userHistory[j].foodname;
        qDebug() <<usersInfoArray[i].userHistory[j].amount;
        qDebug() <<usersInfoArray[i].userHistory[j].bill;
        qDebug() <<usersInfoArray[i].userHistory[j].date;
    }
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    readUserFile();
    showFile();
    saveUserFile();
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


void MainWindow::on_cartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_menuButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_cartViewIconButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_cartPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

// back button of about us page
void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3); //back button in about us page

}


void MainWindow::on_aboutUsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_historyPageBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_historyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

