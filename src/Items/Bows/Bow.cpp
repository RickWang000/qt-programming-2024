#include "Bow.h"

Bow::Bow(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {

}


void Bow::mountToParent() {
    Mountable::mountToParent();
    setScale(1.2);
    setTransform(QTransform().scale(1, 1));
    setPos(-110, -120);
    setRotation(-45);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Bow::unmount() {
    Mountable::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void Bow::updateMove(double deltaTime) {
    if (!isMounted()) {
        setAcceleration(QPointF(0, GRAVITY));
        setVelocity(getVelocity() + getAcceleration() * deltaTime);
        setPos(pos() + getVelocity() * deltaTime);
    }
}