#include "Spear.h"

Spear::Spear(QGraphicsItem *parent, const QString &pixmapPath) : MeleeWeapon(parent, pixmapPath) {
    
}

void Spear::mountToParent() {
    Mountable::mountToParent();
    setScale(1);
    setTransform(QTransform().scale(-2.5, 0.7));
    setPos(40, -150);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Spear::attack() {
}