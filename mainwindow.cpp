#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iniutil.h"
#include "initwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_settings();
    QStringList keys = settings->allKeys();
    if((!keys.size())||get_settings("Dosbox").isEmpty()||get_settings("Proteus").isEmpty()) {
        InitWindow* w = new InitWindow(this);
        w->show();
    }
}

MainWindow::~MainWindow()
{
    unload_settings();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
