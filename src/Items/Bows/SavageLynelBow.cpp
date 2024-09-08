#include "SavageLynelBow.h"

SavageLynelBow::SavageLynelBow(QGraphicsItem *parent) : Bow(parent,
    ":/Items/Bows/SavageLynelBow/SavageLynelBow.png") {
    setMaterial(MaterialType::Metal);
    setAttackRange(300);
    setMultiShot(5);
}