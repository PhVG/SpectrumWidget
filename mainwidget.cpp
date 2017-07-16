#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <ctime>
//#include <QDebug>


#define AMPLITUDE_MAX 1

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    ui->chartWidget->show();

    connect(ui->controlWidget, SIGNAL(signalVisualiseClicked()), this, SLOT(slotVisualiseClicked()));
}


MainWidget::~MainWidget()
{
    delete ui;
}


void MainWidget::reset()
{
    QVector<float> spectrum;
    srand(clock());

    for(int i = 0; i < ui->controlWidget->getNumberOfElements(); i++)
    {
        spectrum.append(static_cast<float>(rand() * AMPLITUDE_MAX) / static_cast<float>(RAND_MAX));
    }

    ui->chartWidget->setSpectrum(spectrum);
    ui->chartWidget->setAmplitude(ui->controlWidget->getMaxAmplitude());

    ui->chartWidget->repaint();
}


void MainWidget::slotVisualiseClicked()
{
    reset();
}
