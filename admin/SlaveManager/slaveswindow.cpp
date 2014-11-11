#include "slaveswindow.h"

SlavesWindow::SlavesWindow(QWidget *parent) :
    QWidget(parent)
{
    tabs = new QTabWidget();
}

QWidget *SlavesWindow::getWidget()
{
    return tabs;
}


void SlavesWindow::addTab(QString tabName)
{
    Console *c = new Console();
    tabs->addTab(c, tabName);
    qDebug() << "adding tab : " << tabName;
    connect(c, SIGNAL(send(QString)), this, SLOT(onEnterPressed(QString)));
}

void SlavesWindow::removeClient(int index)
{
    tabs->removeTab(index);
}

void SlavesWindow::addText(int index, QString s)
{
    ((Console*) tabs->widget(index))->addMessage(s);
}

void SlavesWindow::onEnterPressed(QString msg)
{
    emit send(tabs->currentIndex(), msg);
}
