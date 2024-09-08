#include "PhrenicBow.h"

PhrenicBow::PhrenicBow(QGraphicsItem *parent) : Bow(parent,
    ":/Items/Bows/PhrenicBow/PhrenicBow.png") {
    setMaterial(MaterialType::Metal);
    setAttackRange(400);
    setMultiShot(1);
}