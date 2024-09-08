#include "MasterSword.h"

MasterSword::MasterSword(QGraphicsItem *parent) : Sword(parent, 
    ":/Items/MeleeWeapons/Swords/MasterSword/MasterSword.png") {
    setMaterial(MaterialType::Metal);
    setElement(ElementalType::None);
}