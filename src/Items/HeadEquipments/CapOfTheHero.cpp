//
// Created by gerw on 8/20/24.
//

#include "CapOfTheHero.h"

CapOfTheHero::CapOfTheHero(QGraphicsItem *parent) : HeadEquipment(parent,
    ":/Items/HeadEquipments/CapOfTheHero/CapOfTheHero.png") {
    }

void CapOfTheHero::mountToParent() {
    HeadEquipment::mountToParent();
    setScale(0.4);
    setPos(-30, -210);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void CapOfTheHero::unmount() {
    HeadEquipment::unmount();
    setScale(0.4);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}
