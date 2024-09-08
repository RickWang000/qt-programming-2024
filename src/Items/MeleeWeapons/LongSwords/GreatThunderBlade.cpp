#include "GreatThunderBlade.h"

GreatThunderBlade::GreatThunderBlade(QGraphicsItem *parent) : LongSword(parent,
    ":/Items/MeleeWeapons/LongSwords/GreatThunderBlade/GreatThunderBlade.png") {
    setMaterial(MaterialType::Metal);
    setElement(ElementalType::Thunder);

    setAttackRange(200);
    setDamage(15);
}