#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>
#include "language.h"
#include "singleton.h"
#include "util.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString language_value;
    LANGUAGE language = UI_ZH;
    bool is_read = Util::readInit(QString("./user.ini"), QString("language"), language_value);
    if(is_read)
    {
        language = (LANGUAGE)language_value.toInt();
    }
    Singleton<Language>::Instance()->load(language);


    MainWindow w;
    w.show();
    return a.exec();
}
