#pragma once

#include <QString>
#include <QWidget>

class Avatar;
class FlatButton;
class QLabel;
class QListWidget;
class Toggle;

struct DeviceInfo
{
        QString device_id;
        QString display_name;
};

Q_DECLARE_METATYPE(std::vector<DeviceInfo>)

namespace dialogs {

class DeviceItem : public QWidget
{
        Q_OBJECT

public:
        explicit DeviceItem(DeviceInfo device, QWidget *parent);

private:
        DeviceInfo info_;

        // Toggle *verifyToggle_;
};

class UserProfile : public QWidget
{
        Q_OBJECT
public:
        explicit UserProfile(QWidget *parent = nullptr);

        void init(const QString &userId, const QString &roomId);

protected:
        void paintEvent(QPaintEvent *) override;

signals:
        void devicesRetrieved(const std::vector<DeviceInfo> &devices);

private slots:
        void updateDeviceList(const std::vector<DeviceInfo> &devices);

private:
        Avatar *avatar_;

        QLabel *userIdLabel_;
        QLabel *displayNameLabel_;

        FlatButton *banBtn_;
        FlatButton *kickBtn_;
        FlatButton *ignoreBtn_;
        FlatButton *startChat_;

        QLabel *devicesLabel_;
        QListWidget *devices_;
};

} // dialogs