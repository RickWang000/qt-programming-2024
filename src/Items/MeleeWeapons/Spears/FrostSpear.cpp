#include "FrostSpear.h"

FrostSpear::FrostSpear(QGraphicsItem *parent) : Spear(parent,
    ":/Items/MeleeWeapons/Spears/FrostSpear/FrostSpear.png") {
    setMaterial(MaterialType::Metal);
    setElement(ElementalType::Ice);

    setAttackRange(400);
    setDamage(10);
}