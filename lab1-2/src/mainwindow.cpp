#include "mainwindow.h"
#include "controlpanel.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(600, 400);
    ControlPanel* mainScene = new ControlPanel();
    setCentralWidget(mainScene);
}

MainWindow::~MainWindow()
{

}

