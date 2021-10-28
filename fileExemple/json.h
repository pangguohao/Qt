#ifndef JSON_H
#define JSON_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>


#define JSDDATAADDRESS "address"
#define JSDDATAPARAM "param"
#define JSDDATATYPE "type"
#define JSDDATANUM "data_num"

class JSon
{
public:
static JSon *GetInstance();
static void testCreate();

void writeJson();
void readJson();
void setCfgCount(uint32_t data_num);
void setCfg(uint32_t _index, QJsonObject dDataCfgJson);
QJsonArray getArray(){return m_array;};
void setArray(QJsonArray array){m_array = array;};
private:
static JSon *s_ptr;

private:
    JSon() {readJson();}
    QJsonDocument m_document;
    QJsonArray m_array;
};


#endif // JSON_H
