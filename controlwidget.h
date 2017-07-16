#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>


namespace Ui {
class ControlWidget;
}


class SpectrumWidget;


class ControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ControlWidget(QWidget *parent = nullptr);
    ~ControlWidget();

    int getNumberOfElements();
    float getMaxAmplitude();

private:
    Ui::ControlWidget *ui;

signals:
    void signalVisualiseClicked();

private slots:
    void slotVisualiseClicked();

};


#endif // CONTROLWIDGET_H
