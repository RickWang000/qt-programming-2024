#include "Sword.h"
#include "../../Characters/Character.h"
#include <QPropertyAnimation>
#include <QGraphicsScene>

Sword::Sword(QGraphicsItem *parent, const QString &pixmapPath) : MeleeWeapon(parent, pixmapPath) {
    // 初始化剑的图像
}

void Sword::mountToParent() {
    Mountable::mountToParent();
    setScale(1);
    setTransform(QTransform().scale(-1, 1));
    setPos(-20, -170);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Sword::attack() {
    
}

