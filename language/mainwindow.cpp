#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "language.h"
#include "singleton.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->TranslateUi();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *event)
{
    switch (event->type()) {
    case QEvent::LanguageChange:
        TranslateUi();
        break;
    default:
        QWidget::changeEvent(event);
    }
}

void MainWindow::TranslateUi()
{
    ui->btnCh->setText(tr("chinese"));
    ui->btnEn->setText(tr("english"));
    ui->btn1->setText(tr("start"));
    ui->btn2->setText(tr("stop"));
    ui->btn3->setText(tr("reset"));
    ui->label1->setText(tr("name"));
    ui->label2->setText(tr("servo type"));
    ui->label3->setText(tr("user limit"));
}

void MainWindow::on_btnEn_clicked()
{
    Singleton<Language>::Instance()->load(UI_EN);
}

void MainWindow::on_btnCh_clicked()
{
    Singleton<Language>::Instance()->load(UI_ZH);
}
