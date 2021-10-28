#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void changeEvent(QEvent *event);
private slots:
    void on_btnEn_clicked();

    void on_btnCh_clicked();

private:
    void TranslateUi();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
