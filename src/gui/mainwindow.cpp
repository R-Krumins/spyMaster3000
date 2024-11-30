#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	AlgoArgsBuilder builder (Algo::AES128);
    connect(ui->encrypt_btn, SIGNAL(clicked()), this, SLOT(doStuff()));
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doStuff() {
    ui->output_textbox->setPlainText(QString("FUCK FFF"));
}
void MainWindow::onInputGiven(AlgoArgsBuilder builder) {}
void MainWindow::onKeyGiven(AlgoArgsBuilder builder) {}
void MainWindow::onEncryptBtnClicked(AlgoArgsBuilder builder) {}
void MainWindow::onDecryptBtnClicked(AlgoArgsBuilder builder) {}

