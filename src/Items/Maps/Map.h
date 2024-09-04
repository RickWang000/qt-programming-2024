//
// Created by gerw on 8/21/24.
//

#ifndef QT_PROGRAMMING_2024_MAP_H
#define QT_PROGRAMMING_2024_MAP_H

#include <QGraphicsScene>
#include <QPointF>
#include "../Item.h"

struct FloorInfo {
    qreal startX;
    qreal endX;
    qreal height;
};

class Map : public Item {
public:
    explicit Map(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

    void scaleToFitScene(QGraphicsScene *scene);

    virtual FloorInfo getFloorInfo(); // Need to rewrite to support multiple platforms

    virtual bool isOnFloor(const QPointF &pos);

    virtual QPointF getSpawnPos();
};


#endif //QT_PROGRAMMING_2024_MAP_H
