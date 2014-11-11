#ifndef SLAVES_H
#define SLAVES_H

#include <QWidget>
#include <QTabWidget>
#include <QDebug>

#include "console.h"

class SlavesWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SlavesWindow(QWidget *parent = 0);
    QWidget* getWidget();
    void addTab(QString tabName);
    void removeClient(int index);
    void addText(int index, QString s);
    
signals:
    void send(int index, QString msg);
public slots:
    void onEnterPressed(QString msg);
private:
    QTabWidget *tabs;
};

#endif // SLAVES_H
