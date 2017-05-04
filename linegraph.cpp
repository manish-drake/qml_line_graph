#include "linegraph.h"
#include <QPainter>
#include <QPointF>

LineGraph::LineGraph(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

QColor LineGraph::color() const
{
    return m_color;
}

void LineGraph::setColor(const QColor &color)
{
    if(m_color != color){
        m_color = color;
        update();
        emit colorChanged(color);
    }
}

QList<int> LineGraph::points()
{
    return m_points;
}

void LineGraph::setPoints(QList<int> points)
{
    if(m_points != points){
        m_points = points;
        this->update();
        emit pointsChanged(points);
    }
}

int LineGraph::size()
{
    return m_size;
}

void LineGraph::setSize(int size)
{
    if(m_size != size){
        m_size = size;
        update();
        emit sizeChanged(size);
    }
}

void LineGraph::paint(QPainter *painter)
{
    //    QPointF points1[] = {QPoint(10, 21), QPoint(20, 62), QPoint(30, 43), QPoint(40, 54), QPoint(50, 35)};
    QPen pen(m_color, 2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    std::vector<QPointF> points;
    auto x = 0;
    for(auto p: m_points){
        points.push_back(QPoint(x++, p));
    }
    painter->drawPolyline(points.data(), size());
}
