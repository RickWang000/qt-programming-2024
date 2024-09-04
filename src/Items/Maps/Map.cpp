//
// Created by gerw on 8/21/24.
//

#include "Map.h"

Map::Map(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {}

void Map::scaleToFitScene(QGraphicsScene *scene) {
    // Calculate scale factors to scale the item to fit the entire scene
    QRectF sceneRect = scene->sceneRect();
    QRectF itemRect = boundingRect();

    qreal scaleX = sceneRect.width() / itemRect.width();
    qreal scaleY = sceneRect.height() / itemRect.height();

    // Choose the smaller scale factor to maintain aspect ratio
    qreal scaleFactor = qMin(scaleX, scaleY);

    // Apply the scale to the item
    setTransform(QTransform::fromScale(scaleFactor, scaleFactor), true);

    // Center the item in the scene (optional)
    setPos((sceneRect.width() - boundingRect().width() * scaleFactor) / 2,
           (sceneRect.height() - boundingRect().height() * scaleFactor) / 2);

}

QPointF Map::getSpawnPos() {
    auto boundingRect = sceneBoundingRect();
    auto midX = (boundingRect.left() + boundingRect.right()) * 0.5;
    return {midX, getFloorInfo().height};
}

FloorInfo Map::getFloorInfo() {
    auto sceneRect = sceneBoundingRect();
    FloorInfo floorInfo;
    floorInfo.startX = sceneRect.left();
    floorInfo.endX = sceneRect.right();
    floorInfo.height = sceneRect.top() + (sceneRect.bottom() - sceneRect.top()) * 0.5;
    return floorInfo;
}

bool Map::isOnFloor(const QPointF &pos) {
    auto floorInfo = getFloorInfo();
    qreal tolerance = 0.1; // 允许的误差范围
    return std::abs(pos.y() - floorInfo.height) < tolerance &&
           pos.x() >= floorInfo.startX && pos.x() <= floorInfo.endX;
}