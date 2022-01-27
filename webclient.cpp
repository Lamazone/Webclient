#include "webclient.h"
#include <QTcpSocket>
#include <QtNetwork>

Webclient::Webclient(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void Webclient::on_ButtonGo_clicked()
{
    ResultText->clear();

    socket = new QTcpSocket(this);


    m_HostNameString = HostName -> text();

    connect(socket, &QTcpSocket::connected, this, &Webclient::connected);
    connect(socket, &QTcpSocket::readyRead, this, &Webclient::ReadyRead);

    socket->connectToHost(m_HostNameString, 80);

    if(!socket->waitForConnected(5000))
    {
        ResultText->append("connect failed!");
    }

}
void Webclient::connected()
{

    this->socket->write("GET / HTTP/1.1\r\nHost:" + m_HostNameString.toLocal8Bit() + "\r\n\r\n");
}
void Webclient::ReadyRead()
{
    HTMLOutput = QString(socket->readAll());

    this->ResultText->setTextColor("black");
    ResultText->append(HTMLOutput);

    socket->disconnectFromHost();

}
