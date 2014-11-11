#ifndef CONSOLE_H
#define CONSOLE_H

#include <QWidget>
#include <QTextEdit>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QShortcut>
#include <QDebug>
#include <QKeyEvent>
#include <QTabWidget>

#include <iostream>

class Console : public QWidget
{
    Q_OBJECT
public:
    explicit Console(QWidget *parent = 0);
    
    void keyReleaseEvent(QKeyEvent *e);
    void addMessage(QString s);
signals:
    void send(QString msg);
    
public slots:
    void messageWritten(const QString);
    void enterPressed();

private:
    QVBoxLayout *layout;
    QTextEdit *display;
    QInputDialog *cmd;
    QString msg;
};

#endif // CONSOLE_H
