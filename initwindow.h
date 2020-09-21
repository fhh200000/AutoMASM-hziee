#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QDialog>
#include "vardefs.h"
namespace Ui {
class InitWindow;
}

class InitWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InitWindow(QWidget *parent = nullptr);
    ~InitWindow();

private slots:
    void on_pushButton_dosbox_clicked();

    void on_pushButton_proteus_clicked();

private:
    Ui::InitWindow *ui;
};

#endif // INITWINDOW_H
