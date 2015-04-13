#ifndef SCADASERVER_H
#define SCADASERVER_H

#include <QObject>
#include <QSignalMapper>
#include <QTcpServer>
#include <QTcpSocket>

#include "packet.h"
#include "sensor.h"
//#include "regulator.h"


class ScadaServer : public QObject
{
    Q_OBJECT
public:
    explicit ScadaServer(QObject *parent = 0);
    ~ScadaServer();

    bool startServer(int portNumber);

signals:

private slots:
    void onNewDeviceConnected();
    void onDeviceDataRx();

private:
    QList<ScadaDevice*>* deviceList;
    QTcpServer *server;
    QList<QTcpSocket*> devicesConnected;

};

#endif // SCADASERVER_H
