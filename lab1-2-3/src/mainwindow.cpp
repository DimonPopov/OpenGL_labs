#include "mainwindow.h"
#include "controlpanel.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon(":icon/image/mainIcon.png"));
    setWindowTitle("OpenGl_lab1-2-3");
    setFixedSize(800, 600);
    ControlPanel* mainScene = new ControlPanel();
    setCentralWidget(mainScene);
}

MainWindow::~MainWindow()
{

}

