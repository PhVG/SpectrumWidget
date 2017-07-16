#include "controlwidget.h"
#include "ui_controlwidget.h"
#include "spectrumwidget.h"
//#include <QDebug>


ControlWidget::ControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlWidget)
{
    ui->setupUi(this);

    ui->leMaxAmplitude->setText(QString::number(1.0));
    ui->leNumberOfElements->setText(QString::number(48));

    ui->leMaxAmplitude->setValidator(new QDoubleValidator(0, 100, 1, this));
    ui->leNumberOfElements->setValidator(new QIntValidator(0, 400, this));

    connect(ui->pbVisualise, SIGNAL(clicked(bool)), this, SLOT(slotVisualiseClicked()));
}


ControlWidget::~ControlWidget()
{
    delete ui;
}


int ControlWidget::getNumberOfElements()
{
    return ui->leNumberOfElements->text().toInt();
}


float ControlWidget::getMaxAmplitude()
{
    return ui->leMaxAmplitude->text().toFloat();
}


void ControlWidget::slotVisualiseClicked()
{
    ui->pbVisualise->setText("Refresh");
    emit signalVisualiseClicked();
}
