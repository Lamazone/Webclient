#ifndef WEBCLIENT_H
#define WEBCLIENT_H

#include "ui_webclient.h"
#include <QTcpSocket>
#include <QtNetwork>

class Webclient : public QWidget, private Ui::Webclient
{
    Q_OBJECT

public:
    explicit Webclient(QWidget *parent = nullptr);
    QString m_HostNameString;
    QString HTMLOutput;
    QTcpSocket *socket;
    QString ret;

private slots:
    void on_ButtonGo_clicked();

public slots:
    void connected();
    void ReadyRead();
};

#endif // WEBCLIENT_H

