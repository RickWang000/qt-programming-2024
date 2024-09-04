//
// Created by gerw on 8/21/24.
//

#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/g9tOqth.png") {}

qreal Battlefield::getFloorHeight() {
    auto sceneRect = sceneBoundingRect();
    return (sceneRect.top() + sceneRect.bottom()) * 0.63;
}

QPointF Battlefield::getFloorRange() {
    auto sceneRect = sceneBoundingRect();
    auto absWidth = sceneRect.left() + sceneRect.right();
    return {absWidth * 0.1, absWidth * 0.9};
}