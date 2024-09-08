#include "Elemental.h"

// Elemental::Elemental(MaterialType material, ElementalType element = ElementalType::None, bool isSource)
//         : material(material), element(element), isSource(isSource) {}

MaterialType Elemental::getMaterial() const {
    return material;
}

ElementalType Elemental::getElement() const {
    return element;
}

bool Elemental::getIsSource() const {
    return isSource;
}

ElementalType Elemental::getResistElement() const {
    return resistElement;
}

void Elemental::setMaterial(MaterialType material) {
    Elemental::material = material;
}

void Elemental::setElement(ElementalType element) {
    Elemental::element = element;
}

void Elemental::setIsSource(bool isSource) {
    Elemental::isSource = isSource;
}

void Elemental::setResistElement(ElementalType resistElement) {
    Elemental::resistElement = resistElement;
}

void Elemental::reactToElement(ElementalType otherElement) {
    
}