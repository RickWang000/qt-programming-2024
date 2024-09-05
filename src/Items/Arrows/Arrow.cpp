#include "Arrow.h"

Arrow::Arrow(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {

}


void Arrow::mountToParent() {
    Mountable::mountToParent();
    setScale(0.8);
    setPos(-59, -176);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Arrow::unmount() {
    Mountable::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void Arrow::updateMove(double deltaTime) {
    if (!isMounted()) {
        setAcceleration(QPointF(0, GRAVITY));
        setVelocity(getVelocity() + getAcceleration() * deltaTime);
        setPos(pos() + getVelocity() * deltaTime);
    }
}