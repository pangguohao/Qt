#include <QCoreApplication>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QMutex>
#include <QFile>
#include <QDate>
#include <QDir>
#include <iostream>
#include <QObject>
#include <QString>
#include <qlogging.h>
using namespace std;

//��־����
void LogMsgOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
 {
    // ����
       static QMutex mutex;
       mutex.lock();

       QByteArray localMsg = msg.toLocal8Bit();

       QString strMsg("");
       switch(type)
       {
       case QtDebugMsg:
           strMsg = QString("Debug:");
           break;
       case QtWarningMsg:
           strMsg = QString("Warning:");
           break;
       case QtCriticalMsg:
           strMsg = QString("Critical:");
           break;
       case QtFatalMsg:
           strMsg = QString("Fatal:");
           break;
       }

       // ���������Ϣ��ʽ
       QString strDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
       QString strMessage = QString("[%1  File:%2  Line:%3  Function:%4  DateTime:%5] %6")
               .arg(strMsg).arg(context.file).arg(context.line).arg(context.function).arg(strDateTime).arg(localMsg.constData());

       // �����Ϣ���ļ��У���д��׷����ʽ��
       QFile file("./log.txt");
       file.open(QIODevice::ReadWrite | QIODevice::Append);
       QTextStream stream(&file);
       stream << strMessage << "\r\n";
       file.flush();
       file.close();

       // ����
       mutex.unlock();
 }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
#if 1
    qInstalMessageHandler(LogMsgOutput);
#endif

    qInfo() << "test message!";
    return a.exec();
}
