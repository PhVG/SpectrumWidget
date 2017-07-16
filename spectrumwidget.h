#ifndef SPECTRUMWIDGET_H
#define SPECTRUMWIDGET_H

#include <QWidget>
#include <QVector>


class SpectrumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SpectrumWidget(QWidget *parent = nullptr);
    ~SpectrumWidget();

    void setSpectrum(QVector<float> spectrum) { m_spectrum = spectrum; }
    void setAmplitude(float amplitude) { m_amplitude = amplitude; }

private:
    QVector<float> m_spectrum;
    float m_amplitude = 1.0;

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mouseMoveEvent(QMouseEvent* pe);

};


#endif // SPECTRUMWIDGET_H
