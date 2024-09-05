#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon(QGraphicsItem *parent, const QString &pixmapPath) : Item(parent, pixmapPath) {

}


void MeleeWeapon::mountToParent() {
    Mountable::mountToParent();
    setScale(0.8);
    setPos(-59, -176);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void MeleeWeapon::unmount() {
    Mountable::unmount();
    setScale(0.8);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, -120);
    }
}

void MeleeWeapon::updateMove(double deltaTime) {
    if (!isMounted()) {
        setAcceleration(QPointF(0, GRAVITY));
        setVelocity(getVelocity() + getAcceleration() * deltaTime);
        setPos(pos() + getVelocity() * deltaTime);
    }
}