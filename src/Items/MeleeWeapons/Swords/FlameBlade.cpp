#include "FlameBlade.h"

FlameBlade::FlameBlade(QGraphicsItem *parent) : Sword(parent,
    ":/Items/MeleeWeapons/Swords/FlameBlade/FlameBlade.png") {
    setMaterial(MaterialType::Metal);
    setElement(ElementalType::Fire);

    setAttackRange(200);
    setDamage(10);
}