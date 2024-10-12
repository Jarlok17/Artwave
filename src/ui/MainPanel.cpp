#include "MainPanel.hpp"

#include <QMouseEvent>
#include <QTransform>

namespace art
{
    CustomPanel::CustomPanel(QWidget *parent)
        : QWidget(parent), scaleFactor(1.0)
    {
        m_drawColor = Qt::black;
    }

    void CustomPanel::setColor(const QColor &color)
    {
        m_drawColor = color;
    }

    void CustomPanel::mousePressEvent(QMouseEvent *event)
    {
        if (event->button() == Qt::LeftButton)
        {
            m_undoStack.push(m_lines);
            m_redoStack.clear();
            m_lastPoint = event->pos();
            m_lines.append(QVector<QPoint>());
            m_lines.last().append(m_lastPoint);
        }
    }

    void CustomPanel::mouseMoveEvent(QMouseEvent *event)
    {
        if (event->buttons() & Qt::LeftButton) 
        {
            drawLineTo(event->pos());
        }
    }

    void CustomPanel::mouseReleaseEvent(QMouseEvent *event)
    {
        if (event->button() == Qt::LeftButton)
        {
            update();
        }
    }

    void CustomPanel::setFixedSize(int width, int height)
    {
        this->setMinimumSize(width, height);
        this->setMaximumSize(width, height);
    }

    void CustomPanel::paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.fillRect(rect(), Qt::white);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.scale(scaleFactor, scaleFactor);

        painter.setPen(QPen(m_drawColor, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

        for (const auto &line : m_lines)
        {
            for (int i = 1; i < line.size(); ++i)
            {
                painter.drawLine(line.at(i - 1), line.at(i));
            }
        }
        
        painter.drawPixmap((width() - m_canvasWidth) / 2, (height() - m_canvasHeight) / 2, m_canvas);
        QWidget::paintEvent(event);
    }

    void CustomPanel::drawLineTo(const QPoint &endPoint)
    {
        if (!m_lines.isEmpty())
        {
            m_lines.last().append(endPoint);
        }

        m_lastPoint = endPoint;
        update();
    }

    void CustomPanel::clearPanel()
    {
        for (auto &line : m_lines)
        {
            line.clear();
        }
        m_lines.clear();
        update();
    }

    void CustomPanel::undo()
    {
        if (!m_undoStack.isEmpty())
        {
            m_redoStack.push(m_lines);
            m_lines = m_undoStack.pop();
            update();
        }  
    }

    void CustomPanel::redo()
    {
        if (!m_redoStack.isEmpty())
        {
            m_undoStack.push(m_lines);
            m_lines = m_redoStack.pop();
            update();
        }
    }
    void CustomPanel::wheelEvent(QWheelEvent* event)
    {
        // Перевірка, чи натиснута клавіша CTRL
        if (event->modifiers() & Qt::ControlModifier)
        {
            if (event->angleDelta().y() > 0)
            {
                zoomIn();  // Масштабування на збільшення
            }
            else
            {
                zoomOut();  // Масштабування на зменшення
            }
            event->accept();  // Запобігаємо звичайній поведінці коліщатка
        }
        else
        {
            QWidget::wheelEvent(event);  // Виклик стандартної поведінки
        }
    }

    void CustomPanel::zoomIn()
    {
        scaleFactor *= 1.1;  // Збільшуємо масштаб
    }

    void CustomPanel::zoomOut()
    {
        scaleFactor /= 1.1;  // Зменшуємо масштаб
    }
}

