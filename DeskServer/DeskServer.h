#pragma once

#include <QWidget>
#include <QSharedMemory>

#include "ui_DeskServer.h"
#include "PeerClient.h"
#include "RelayPeerClient.h"

class DeskServer : public QWidget
{
    Q_OBJECT

public:
    explicit DeskServer(QWidget* parent = nullptr);
    ~DeskServer();

private slots:
    void onStartClicked();
    void onRegistrationResult(int result);
    void onClientError(const QString& errorString);

    void writeSharedMemory();

private:
    void updateStatus(bool online);
    void loadConfig();
    void saveConfig();

private:
    Ui::DeskServerClass ui;
    QString m_uuidStr;
    PeerClient* m_peerClient;
    RelayPeerClient* m_relayPeerClient;

    QSharedMemory m_shared;
};
