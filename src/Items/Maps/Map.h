//
// Created by gerw on 8/21/24.
//

#ifndef QT_PROGRAMMING_2024_MAP_H
#define QT_PROGRAMMING_2024_MAP_H

#include <QGraphicsScene>
#include <QPointF>
#include "../Item.h"

class Map : public Item {
public:
    explicit Map(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

    virtual void scaleToFitScene(QGraphicsScene *scene);

    virtual qreal getFloorHeight();

    virtual QPointF getFloorRange();

    virtual bool isOnFloor(const QPointF &pos);

    virtual QPointF getSpawnPos();
};


#endif //QT_PROGRAMMING_2024_MAP_H
