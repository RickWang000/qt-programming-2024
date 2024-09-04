//
// Created by gerw on 8/21/24.
//

#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/g9tOqth.png") {}

FloorInfo Battlefield::getFloorInfo() {
    auto sceneRect = sceneBoundingRect();
    FloorInfo floorInfo;
    floorInfo.startX = (sceneRect.left() + sceneRect.right()) * 0.06;
    floorInfo.endX = (sceneRect.left() + sceneRect.right()) * 0.94;
    floorInfo.height = (sceneRect.top() + sceneRect.bottom()) * 0.63;
    return floorInfo;
}
