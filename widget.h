#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

class ActiveWindow: public QObject
{
    Q_OBJECT
public:
    ActiveWindow(QObject *parent = 0);

    WId getId();

Q_SIGNALS:
    void windowChanged(WId wid);

public slots:
    void scan();

private:
    WId m_id;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


protected:
    void paintEvent(QPaintEvent *);

private Q_SLOTS:
    void setSize();

private:
    ActiveWindow *m_aw;
    QImage m_img;
    QTimer m_timer;
};

#endif // WIDGET_H
