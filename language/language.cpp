#include "language.h"
#include "util.h"
#include <QFile>
#include <QDebug>

bool Language::load(LANGUAGE type)
{
    if(m_transLator != nullptr)
    {
        qApp->removeTranslator(m_transLator);
        m_transLator = new QTranslator;
    }

    QString language_value;
    LANGUAGE language = type;
    QString language_suffix;

    if(language == UI_EN)
    {
        language_suffix = QString("en");
    }
    else if(language == UI_ZH)
    {
        language_suffix = QString("zh");
    }

    QFile file(QString(":/file/language_") + language_suffix+QString(".qm"));
    if(!file.exists())
    {
        qDebug() << "file no exist";
    }
    qDebug() << "filepath:" << QString(":/file/language_") + language_suffix;
    m_transLator->load(QString(":/file/language_") + language_suffix);
    qApp->installTranslator(m_transLator);

}
