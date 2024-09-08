#include "ThunderHelm.h"

ThunderHelm::ThunderHelm(QGraphicsItem *parent) : HeadEquipment(parent,
    ":/Items/HeadEquipments/ThunderHelm/ThunderHelm.png") {
    setResistElement(ElementalType::Thunder);
    }