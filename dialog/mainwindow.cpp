#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_colorBt_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "ÑÕÉ«Ñ¡Ôñ");
    QPalette palette;
    //palette.setBrush(ui->colorFrame->backgroundRole(), QBrush(color));
    palette.setColor(QPalette::Window, color);
    ui->colorFrame->setPalette(palette);
    ui->colorFrame->setAutoFillBackground(true);
}

void MainWindow::on_fileBt_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this);
    ui->textEdit->append(QString("filePath:%1").arg(filename));
}

void MainWindow::on_fontBt_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    ui->textEdit->append(QString("font-family:%1 -pointSize:%2 -pixelSize:%3")\
                         .arg(font.family()).arg(font.pointSize())
                         .arg(font.pixelSize()));
}

void MainWindow::on_inputBt_clicked()
{
    QStringList list = {QString("----"), QString("????")};
    QString str = QInputDialog::getItem(this, "ÊäÈë¿ò", "Ñ¡Ôñ", list);
    ui->textEdit->append(QString("input:%1").arg(str));
}

void MainWindow::on_messageBt_clicked()
{
    bool ret = QMessageBox::critical(this, QString("´íÎó"), QString("ÊäÈë´íÎó"));
    ui->textEdit->append(QString("message:%1").arg(ret));
}
