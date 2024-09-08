#include "IceArrow.h"

IceArrow::IceArrow(QGraphicsItem *parent) : Arrow(parent,
    ":/Items/Arrows/IceArrow/IceArrow.png") {
        setMaterial(MaterialType::Metal);
        setElement(ElementalType::Ice);
        setIsSource(true);
}