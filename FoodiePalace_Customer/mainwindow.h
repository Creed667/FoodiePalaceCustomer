#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_logInButton_clicked();

    void on_loginPageBackButton_clicked();

    void on_registerPageBackButton_clicked();

    void on_RegisterButton_clicked();

    void on_cartButton_clicked();

    void on_menuButton_clicked();

    void on_cartViewIconButton_clicked();

    void on_cartPageBackButton_clicked();

    void on_pushButton_2_clicked();

    void on_aboutUsButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
