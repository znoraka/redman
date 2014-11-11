#include "networkmanager.h"

NetworkManager::NetworkManager(SlavesWindow* sw)
{
    this->sw = sw;
    logged = false;
}

void NetworkManager::connect()
{
    port = 1717;
    sock = new QTcpSocket();
    sock->connectToHost("37.187.60.127", port);
    //sock->connectToHost("127.0.0.1", port);
    QObject::connect(sock,SIGNAL(connected()),this,SLOT(connexion_OK()));
    QObject::connect(sock, SIGNAL(readyRead()), this, SLOT(lecture()));
    QObject::connect(sock, SIGNAL(disconnected()), this, SLOT(closed()));
    QObject::connect(sock, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
}

void NetworkManager::receive(int index, QString msg)
{
    QString s = "" + QString::number(index) + ":" + msg;

    qDebug() << "sending " << s << " to client " << index;
    sock->write(s.toUtf8());
    sock->write("\n");
    sock->flush();
}

void NetworkManager::connexion_OK()
{
    emit connectionSuccessful();
    qDebug() << "connected";
}

void NetworkManager::lecture()
{
    while(sock->bytesAvailable() > 0) {
        QString s = sock->readLine();
        qDebug()  << "s : " << s;

        if(logged == false) {
            if(!s.compare("true\n")) {
                logged = true;
                emit loginSuccessful();
            } else {
                emit connectionLost();
            }
        } else {
            QString cmd = s.left(2);
            QString data = s.right(s.length() - 3);
            data.chop(1);

            //liste de tous les clients
            if(!cmd.compare("AC")) {
                QStringList ss = data.split(";");
                for (int i = 0; i < ss.size(); ++i) {
                    sw->addTab(ss[i]);
                }
            }

            //client déco
            if(!cmd.compare("DC")) {
                sw->removeClient(data.toInt());
            }

            //nouveau client
            if(!cmd.compare("NC")) {
                sw->addTab(data);
            }

            //retour d'une commande
            if(!cmd.compare("CM")) {
                QStringList ss = data.split(";");
                qDebug() << "index : " << ss[0].toInt();
                qDebug() << "data : " << ss[1];
                sw->addText(ss[0].toInt(), ss[1]);
            }
        }
        sw->update();
    }
}

void NetworkManager::closed()
{
    logged = false;
    emit connectionLost();
}

void NetworkManager::error(QAbstractSocket::SocketError e)
{
    emit errorOccured(e);
}


void NetworkManager::login(QString s)
{
    qDebug() << "sending password";
    sock->write(s.toUtf8());
    sock->write("\n");
    sock->flush();
}
