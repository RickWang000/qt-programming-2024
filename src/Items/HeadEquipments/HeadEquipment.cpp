//
// Created by gerw on 8/20/24.
//

#include "HeadEquipment.h"

HeadEquipment::HeadEquipment(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {
}

void HeadEquipment::mountToParent() {
    Mountable::mountToParent();
    setScale(0.4);
    setPos(-30, -210);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void HeadEquipment::unmount() {
    Mountable::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void HeadEquipment::updateMove(double deltaTime) {
    if (!isMounted()) {
        setAcceleration(QPointF(0, GRAVITY));
        setVelocity(getVelocity() + getAcceleration() * deltaTime);
        setPos(pos() + getVelocity() * deltaTime);
    }
}
