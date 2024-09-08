#include "WoodArrow.h"

WoodArrow::WoodArrow(QGraphicsItem *parent) : Arrow(parent,
    ":/Items/Arrows/WoodArrow/WoodArrow.png") {
        setMaterial(MaterialType::Wood);
        setElement(ElementalType::None);
        setIsSource(false);
}