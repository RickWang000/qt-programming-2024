//
// Created by gerw on 8/21/24.
//

#include "Battlefield.h"

Battlefield::Battlefield(QGraphicsItem *parent) : Map(parent, ":/Items/Maps/Battlefield/g9tOqth.png") {
    auto sceneRect = sceneBoundingRect();
    auto absWidth = sceneRect.left() + sceneRect.right();
    auto absHeight = sceneRect.top() + sceneRect.bottom();
    addFloor(absWidth * 0.1, absWidth * 1.6, absHeight * 1.12);
    addFloor(absWidth * 0.26, absWidth * (0.26 + 0.38), absHeight * 0.7);
    addFloor(absWidth * 1.05, absWidth * (1.05 + 0.38), absHeight * 0.7);
    addFloor(absWidth * 0.65, absWidth * (0.65 + 0.38), absHeight * 0.322);
}
