#include "initwindow.h"
#include "ui_initwindow.h"
#include <QFileDialog>
#include "iniutil.h"
InitWindow::InitWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InitWindow)
{
    ui->setupUi(this);
    ui->lineEdit_dosbox->setText(get_settings("Dosbox"));
    ui->lineEdit_proteus->setText(get_settings("Proteus"));
}

InitWindow::~InitWindow()
{
    delete ui;
}

void InitWindow::on_pushButton_dosbox_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("选择Dosbox主程序"));
    fileDialog->setNameFilter(tr(DOSBOX_EXEC_NAME));
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    fileDialog->setViewMode(QFileDialog::Detail);
    if(fileDialog->exec()) {
        ui->lineEdit_dosbox->setText(fileDialog->selectedFiles().at(0));
    }
}

void InitWindow::on_pushButton_proteus_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog->setWindowTitle(tr("选择Proteus主程序"));
    fileDialog->setNameFilter(tr(PROTEUS_EXEC_NAME));
    fileDialog->setFileMode(QFileDialog::ExistingFile);
    fileDialog->setViewMode(QFileDialog::Detail);
    if(fileDialog->exec()) {
        ui->lineEdit_dosbox->setText(fileDialog->selectedFiles().at(0));
    }
}

void InitWindow::on_buttonBox_accepted()
{
    set_settings("Dosbox",ui->lineEdit_dosbox->text());
    set_settings("Proteus",ui->lineEdit_proteus->text());
}
