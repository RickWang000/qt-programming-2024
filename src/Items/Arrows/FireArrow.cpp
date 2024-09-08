#include "FireArrow.h"

FireArrow::FireArrow(QGraphicsItem *parent) : Arrow(parent, 
    ":/Items/Arrows/FireArrow/FireArrow.png") {
        setMaterial(MaterialType::Metal);
        setElement(ElementalType::Fire);
        setIsSource(true);
}