#include "spectrumwidget.h"
#include "ui_spectrumwidget.h"
//#include <QDebug>
#include <ctime>
#include <QPainter>
#include <QRgb>
#include <QFontMetrics>


SpectrumWidget::SpectrumWidget(QWidget *parent) :
    QWidget(parent)
{

}


SpectrumWidget::~SpectrumWidget()
{

}


/*virtual*/ void SpectrumWidget::paintEvent(QPaintEvent*)
{
    for (int i = 1; i < m_spectrum.count(); i++)
    {
        QColor tmpBarCol;// = QColor(Qt::red);

        if(i >= 8 && i <= 13)
        {
            tmpBarCol = Qt::green;
        }
        else if(i >= 14 && i <= 40)
        {
            tmpBarCol = QColor(qRgb(128, 0, 255));
        }
        else if(i >= 4 && i <= 8)
        {
            tmpBarCol = Qt::red;
        }
        else if(i >= 0.5 && i <= 3)
        {
            tmpBarCol = QColor(qRgb(128, 64, 0));
        }
        else if(i >= 40)
        {
            tmpBarCol = Qt::blue;
        }

        //Перечисление ритмов в виде таблицы
        //alpha 8-13 Hz зеленый
        //beta 14-40 Нz фиолетовый
        //tetha 4-8 Нz красный
        //delta 0.5-3 Нz коричневый
        //gamma 40+ Нz голубой

        int mergin = 1;
        int footerHeight = 10;
        int widgetHeight = this->height();

        float elemWidth = (float)this->width() / (float)m_spectrum.count();
        float elementHeight = m_spectrum[i] * (widgetHeight - footerHeight) / m_amplitude;

        QPainter painter(this);

        painter.fillRect(i * elemWidth,
                         widgetHeight - elementHeight - footerHeight,
                         elemWidth - mergin,
                         elementHeight,
                         tmpBarCol);

        QFontMetrics fm(font());
        int txtWidth = fm.width("x-max");
        int txtHeight = fm.height();

        painter.drawText(this->width() - txtWidth - mergin * 2, widgetHeight - mergin * 2, "x-max");
        painter.drawText(mergin * 2, widgetHeight - mergin * 2, "0");
        painter.drawText(mergin * 2, txtHeight + mergin * 2, "y-max");
    }// for i
}


/*virtual*/ void SpectrumWidget::mouseMoveEvent(QMouseEvent* pe)
{

}
