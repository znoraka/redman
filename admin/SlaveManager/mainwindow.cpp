#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    sw = new SlavesWindow();
    container = new QStackedWidget();
    n = new NetworkManager(sw);
    login = new QInputDialog();
    label = new QTextEdit();

    resize(800, 600);

    login->show();
    login->resize(200, 75);
    login->setLabelText("Password");
    login->setTextEchoMode(QLineEdit::Password);

    label->resize(600, 400);
    label->move(100, 100);
    label->setReadOnly(true);

    this->setCentralWidget(login);
    //loginPressed();
    //connectionSuccessful();
    connect(login, SIGNAL(accepted()), this, SLOT(loginPressed()));
    connect(login, SIGNAL(rejected()), this, SLOT(exitPressed()));
    connect(n, SIGNAL(loginSuccessful()), this, SLOT(loginSucessful()));
    connect(n, SIGNAL(connectionSuccessful()), this, SLOT(connectionSuccessful()));
    connect(n, SIGNAL(connectionLost()), this, SLOT(connectionLost()));
    connect(sw, SIGNAL(send(int,QString)), n, SLOT(receive(int,QString)));
    connect(n, SIGNAL(errorOccured(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::loginPressed()
{
    n->connect();
}

void MainWindow::exitPressed()
{
    exit(0);
}

void MainWindow::connectionSuccessful()
{
    qDebug() << "connected, sending password";
    n->login(login->textValue());
}

void MainWindow::connectionLost()
{
    this->setCentralWidget(login);
}

void MainWindow::loginSucessful()
{
    this->setCentralWidget(sw->getWidget());
}

void MainWindow::error(QAbstractSocket::SocketError e)
{
    qDebug() << e;
    if(e == 0) {
        label->setText("The connection was refused by the peer (or timed out).");
    }
    this->setCentralWidget(label);
}
