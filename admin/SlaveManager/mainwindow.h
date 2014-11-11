#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QInputDialog>
#include <QStackedWidget>
#include <QTextEdit>

#include "slaveswindow.h"
#include "networkmanager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loginPressed();
    void exitPressed();
    void connectionSuccessful();
    void connectionLost();
    void loginSucessful();
    void error(QAbstractSocket::SocketError);

private:
    SlavesWindow *sw;
    QInputDialog* login;
    NetworkManager *n;
    QStackedWidget* container;
    QTextEdit* label;
};

#endif // MAINWINDOW_H
