#include "ShockArrow.h"

ShockArrow::ShockArrow(QGraphicsItem *parent) : Arrow(parent, 
    ":/Items/Arrows/ShockArrow/ShockArrow.png") {
        setMaterial(MaterialType::Metal);
        setElement(ElementalType::Thunder);
        setIsSource(true);
}