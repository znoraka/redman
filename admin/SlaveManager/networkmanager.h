#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QApplication>
#include <QtNetwork/QTcpSocket>
#include <QStringList>

#include "slaveswindow.h"

class NetworkManager : public QObject
{
    Q_OBJECT

public:
    NetworkManager(SlavesWindow* sw);
    void connect();
    void login(QString s);

public slots:
    void receive(int index, QString t);

private slots:
    void connexion_OK();
    void lecture();
    void closed();
    void error(QAbstractSocket::SocketError);

signals:
    void connectionSuccessful();
    void connectionLost();
    void loginSuccessful();
    void errorOccured(QAbstractSocket::SocketError);

private:
    QString IP;
    int port;
    QTcpSocket *sock;
    SlavesWindow* sw;
    bool logged;

};

#endif // NETWORKMANAGER_H
