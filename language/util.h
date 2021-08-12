#ifndef UTIL_H
#define UTIL_H

#include <QSettings>

class Util
{
public:
    /**
     * @brief Util
     */
    Util();

    /**
     * @brief writeInit
     * @param path
     * @param user_key
     * @param user_value
     * @return
     */
    static bool writeInit(QString path, QString user_key, QString user_value);

    /**
     * @brief readInit
     * @param path
     * @param user_key
     * @param user_value
     * @return
     */
    static bool readInit(QString path, QString user_key, QString &user_value);

};

#endif // UTIL_H
