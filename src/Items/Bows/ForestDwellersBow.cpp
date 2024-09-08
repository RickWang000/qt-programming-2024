#include "ForestDwellersBow.h"

ForestDwellersBow::ForestDwellersBow(QGraphicsItem *parent) : Bow(parent,
    ":/Items/Bows/ForestDwellersBow/ForestDwellersBow.png") {
    setMaterial(MaterialType::Wood);
    setAttackRange(200);
    setMultiShot(3);
}