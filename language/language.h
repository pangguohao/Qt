#ifndef LANGUUAGE_H
#define LANGUUAGE_H

#include <QApplication>
#include <QTranslator>

typedef enum{
    UI_ZH,
    UI_EN
}LANGUAGE;



class Language
{
public:
    Language() { m_transLator = new QTranslator; }
    ~Language() {}

public:
    bool load(LANGUAGE type);

private:
    QTranslator *m_transLator;
};


#endif // LANGUUAGE_H
