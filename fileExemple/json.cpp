#include "json.h"
#include <QFile>
#include <QDebug>

JSon *JSon::s_ptr = nullptr;
JSon *JSon::GetInstance()
{
    if(s_ptr == nullptr)
    {
        s_ptr = new JSon();
    }
    return s_ptr;
}

void JSon::testCreate()
{

    // ���� Json ����
    QJsonObject dDataCfgJson;
    dDataCfgJson.insert("address", 1000);
    dDataCfgJson.insert("param", 0x01);
    dDataCfgJson.insert("type", 2);
    dDataCfgJson.insert("datanum", 100);

    // ���� Json ����
    QJsonObject dDataCfg2Json;
    dDataCfg2Json.insert("address", 1000);
    dDataCfg2Json.insert("param", 0x01);
    dDataCfg2Json.insert("type", 2);
    dDataCfg2Json.insert("datanum", 100);


    // ���� Json ���� - Version
    QJsonArray jsonArray;
    jsonArray.append(QJsonValue(dDataCfgJson));
    jsonArray.append(QJsonValue(dDataCfg2Json));

    // ���� Json �ĵ�
    QJsonDocument document;
    document.setArray(jsonArray);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);

    QFile file("./DDATA.json");
    file.open(QIODevice::WriteOnly);
    file.write(byteArray);
    file.close();
}

void JSon::setCfgCount(uint32_t data_num)
{
    if(m_array.count() > data_num && data_num >= 0)
    {
        uint32_t remove_num = m_array.count() - data_num;
        for(int i = 0; i < remove_num; i++)
        {
            m_array.removeLast();
        }
    }
    else if(m_array.count() < data_num && m_array.count() >= 0)
    {
        // ���� Json ����
        QJsonObject dDataCfgJson;
        dDataCfgJson.insert("address", 0);
        dDataCfgJson.insert("param", 0);
        dDataCfgJson.insert("type", 0);
        dDataCfgJson.insert("datanum", 0);

        uint32_t add_num = data_num - m_array.count();
        for(int i = 0; i < add_num; i++)
        {
            m_array.append(dDataCfgJson);
        }
    }
}

void JSon::setCfg(uint32_t _index, QJsonObject dDataCfgJson)
{
    if(_index >= m_array.count())
    {
        return;
    }

    m_array.insert(_index, QJsonValue(dDataCfgJson));
}

void JSon::writeJson()
{
    // ���� Json �ĵ�
    QJsonDocument document;
    document.setArray(m_array);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);

    QFile file("./DDATA.json");
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        qDebug() << "WRITE JSON OPEN FILE ERROR!";
        file.close();
    }
    file.write(byteArray);
    file.close();
}

void JSon::readJson()
{
    QFile file("./DDATA.json");
    if(!file.open(QIODevice::ReadOnly))
    {
        file.close();
        return;
    }
    QByteArray byteArray = file.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);  // ת��Ϊ JSON �ĵ�
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // ����δ��������
        if (doucment.isArray()) {  // JSON �ĵ�Ϊ����
            QJsonArray array = doucment.array();  // ת��Ϊ����
            m_array = array;
        }
    }
}
