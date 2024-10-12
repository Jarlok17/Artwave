#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QPixmap>
#include <QStack>

namespace art
{
    class CustomPanel : public QWidget
    {
        Q_OBJECT

        public:
            explicit CustomPanel(QWidget *parent = nullptr);
            void setColor(const QColor &color);

        public slots:
            void clearPanel();
            void undo();
            void redo();
            void setFixedSize(int width, int height);

        protected:
            void mousePressEvent(QMouseEvent *event) override;
            void mouseMoveEvent(QMouseEvent *event) override;
            void mouseReleaseEvent(QMouseEvent *event) override;
            void paintEvent(QPaintEvent *event) override; 
            void wheelEvent(QWheelEvent* event) override;
            
        private:
            QColor m_drawColor;

            QPoint m_lastPoint;
            QVector<QVector<QPoint>> m_lines;

            QPixmap m_canvas;
            uint m_canvasWidth;
            uint m_canvasHeight;
            double scaleFactor;

            QStack<QVector<QVector<QPoint>>> m_undoStack;
            QStack<QVector<QVector<QPoint>>> m_redoStack;
            
            void drawLineTo(const QPoint &endPoint);

            void zoomIn();
            void zoomOut();
            void adjustScale();
    };
}
