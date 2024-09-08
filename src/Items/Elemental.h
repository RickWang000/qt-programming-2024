#ifndef QT_PROGRAMMING_2024_ELEMENTAL_H
#define QT_PROGRAMMING_2024_ELEMENTAL_H

enum class MaterialType {
    Wood,
    Metal,
    Stone,
    Character
};

enum class ElementalType {
    None,
    Fire,
    Ice,
    Thunder
};

class Elemental {
public:
    // Elemental(MaterialType material, ElementalType element = ElementalType::None, bool isSource);
    MaterialType getMaterial() const;
    ElementalType getElement() const;
    bool getIsSource() const;
    ElementalType getResistElement() const;

    void setMaterial(MaterialType material);
    void setElement(ElementalType element);
    void setIsSource(bool isSource);
    void setResistElement(ElementalType resistElement);

    void reactToElement(ElementalType otherElement);



protected:
    MaterialType material{};
    ElementalType element{};
    bool isSource{};
    ElementalType resistElement{};
};

#endif //QT_PROGRAMMING_2024_ELEMENTAL_H