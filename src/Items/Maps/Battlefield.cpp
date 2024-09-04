//
// Created by gerw on 8/21/24.
//

#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/g9tOqth.png") {
    auto sceneRect = sceneBoundingRect();
    auto absWidth = sceneRect.left() + sceneRect.right();
    auto absHeight = sceneRect.top() + sceneRect.bottom();
    addFloor(absWidth * 0.1, absWidth * 1.6, absHeight * 1.12);
    addFloor(absWidth * 0.3, absWidth * 0.6, absHeight * 0.7);
}
