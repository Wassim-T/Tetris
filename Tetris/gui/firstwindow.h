#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include "../src/controller/TetrisController.h"
#include "mainwindow.h"
#include <QMainWindow>
#include "mainwindow.h"
#include "ui_firstwindow.h"
#include "../src/model/Loader.h"
#include "../src/model/TypeBrick.hpp"
#include <QKeyEvent>
#include <QMessageBox>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class firstWindow; }
QT_END_NAMESPACE

class firstWindow : public QMainWindow
{
    Q_OBJECT

public:
    firstWindow(QWidget *parent = nullptr);

    ~firstWindow();

private slots:
    void onSubmitButtonClicked();
    void onSubmitButtonClickedDefault();
private:
    Ui::firstWindow *ui;
    std::shared_ptr<MainWindow> mainWindow;
    void checkName(std::string name);
    model::TypeBrick getBrickChoice(const std::string& choice);
};

#endif // FIRSTWINDOW_H
