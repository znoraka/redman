#include "console.h"

Console::Console(QWidget *parent) :
    QWidget(parent)
{
    layout = new QVBoxLayout();
    display = new QTextEdit();
    cmd = new QInputDialog();

    cmd->setOptions(QInputDialog::NoButtons);
    display->setReadOnly(true);

    layout->addWidget(display);
    layout->addWidget(cmd);

    this->setLayout(layout);

    connect(cmd, SIGNAL(textValueChanged(const QString)), this, SLOT(messageWritten(const QString)));
}


void Console::messageWritten(const QString msg)
{
    this->msg = msg;
}

void Console::enterPressed()
{
    addMessage(">" + msg);
    qDebug() << "msg : " <<  msg;
    emit send(QString(msg));
    cmd->setTextValue("");
}

void Console::keyReleaseEvent(QKeyEvent *e)
{
    if(e->key() == 16777220 || e->key() == 16777221) {
        enterPressed();
    }
}

void Console::addMessage(QString s)
{
    qDebug() << "here" << s;
    display->append(s);
}


