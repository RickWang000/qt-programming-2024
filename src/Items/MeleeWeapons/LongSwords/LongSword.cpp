#include "LongSword.h"

LongSword::LongSword(QGraphicsItem *parent, const QString &pixmapPath) : MeleeWeapon(parent, pixmapPath) {
    
}

void LongSword::mountToParent() {
    Mountable::mountToParent();
    setScale(1.2);
    setTransform(QTransform().scale(-1, 1));
    setPos(-20, -175);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void LongSword::attack() {
    // TODO implement
}
