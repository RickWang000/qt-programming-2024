#include "ForestDwellersSword.h"

ForestDwellersSword::ForestDwellersSword(QGraphicsItem *parent) : Sword(parent,
    ":/Items/MeleeWeapons/Swords/ForestDwellersSword/ForestDwellersSword.png") {
    setMaterial(MaterialType::Wood);
    setElement(ElementalType::None);

    setAttackRange(150);
    setDamage(5);
}