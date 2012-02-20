#include "widget.h"
#include <QDebug>
#include <QPainter>

#ifdef Q_WS_WIN
#include <Windows.h>
#include <WinUser.h>
#endif

ActiveWindow::ActiveWindow(QObject *parent)
    : QObject(parent)
{
    QTimer::singleShot(0, this, SLOT(scan()));
}

WId ActiveWindow::getId()
{
    return m_id;
}

void ActiveWindow::scan()
{
    WId tempId;
    // Win32
#ifdef Q_WS_WIN
    tempId = (WId)GetForegroundWindow();
#endif

    // Mac

    // X11

    // Other

    if (m_id != tempId) {
        m_id = tempId;
        emit windowChanged(m_id);
    }
    QTimer::singleShot(1000, this, SLOT(scan()));
}


/* Test widget */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_aw = new ActiveWindow(this);
    connect(m_aw, SIGNAL(windowChanged(WId)), this, SLOT(setSize()));
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(update()));
    m_timer.start(100);
}

Widget::~Widget()
{

}

void Widget::setSize()
{
    m_img = QPixmap::grabWindow(m_aw->getId()).toImage();
    resize(m_img.size());
}

void Widget::paintEvent(QPaintEvent *)
{
    m_img = QPixmap::grabWindow(m_aw->getId()).toImage();
    QPainter painter(this);
//    painter.drawImage(rect(), m_img.scaled(rect().size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    painter.drawImage(rect(), m_img);
}


