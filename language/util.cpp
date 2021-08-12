#include "util.h"

/**
 * @brief Util::Util
 */
Util::Util()
{

}

/**
 * @brief Util::writeInit
 * @param path
 * @param user_key
 * @param user_value
 * @return
 */
bool Util::writeInit(QString path, QString user_key, QString user_value)
{
    if(path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }

    //创建配置文件操作对象
    QSettings *config = new QSettings(path, QSettings::IniFormat);

    //将信息写入配置文件
    config->beginGroup("config");
    config->setValue(user_key, user_value);
    config->endGroup();

    return true;
}

/**
 * @brief Util::readInit
 * @param path
 * @param user_key
 * @param user_value
 * @return
 */
bool Util::readInit(QString path, QString user_key, QString &user_value)
{
    user_value = QString("");
    if(path.isEmpty() || user_key.isEmpty())
    {
        return false;
    }

    //创建配置文件操作对象
    QSettings *config = new QSettings(path, QSettings::IniFormat);

    //读取用户配置信息
    user_value = config->value(QString("config/") + user_key).toString();

    return true;
}
