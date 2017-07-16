#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QWidget>


namespace Ui {
class MainWidget;
}


class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void reset();

private:
    Ui::MainWidget *ui;

private slots:
    void slotVisualiseClicked();
};


#endif // MAINWIDGET_H
