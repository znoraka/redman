#include "client.h"

Client::Client()
{
    port=1717;
    QObject::connect(&soc,SIGNAL(connected()),this,SLOT(connexion_OK()));
    // signal émis lors de la connexion au serveur
    QObject:: connect(&soc, SIGNAL(readyRead()), this, SLOT(lecture()));
    // signal émis lorsque des données sont prêtes à être lues
}
void Client::recoit_IP(QString IP2)
{
    IP=IP2;
    soc.connectToHost(IP,port); // pour se connecter au serveur
}
void Client::recoit_texte(QString t)
{
    QTextStream texte(&soc); // on associe un flux à la socket
    texte << t<<endl;        // on écrit dans le flux le texte saisi dans l'IHM
}
void Client::connexion_OK()
{
    emit vers_IHM_connexion_OK(); // on envoie un signal à l'IHM
}
void Client::lecture()
{
    QString ligne;
    while(soc.canReadLine()) // tant qu'il y a quelque chose à lire dans la socket
    {
        ligne = soc.readLine();     // on lit une ligne
        emit vers_IHM_texte(ligne); // on envoie à l'IHM
    }
}
