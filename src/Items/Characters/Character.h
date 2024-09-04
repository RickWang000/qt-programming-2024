//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_CHARACTER_H
#define QT_PROGRAMMING_2024_CHARACTER_H

#include <QGraphicsEllipseItem>
#include "../HeadEquipments/HeadEquipment.h"
#include "../Armors/Armor.h"
#include "../LegEquipments/LegEquipment.h"

class Character : public Item {
public:
    explicit Character(QGraphicsItem *parent);

    [[nodiscard]] bool isLeftDown() const;

    void setLeftDown(bool leftDown);

    [[nodiscard]] bool isRightDown() const;

    void setRightDown(bool rightDown);

    [[nodiscard]] bool isJumpDown() const;

    void setJumpDown(bool jumpDown);

    [[nodiscard]] bool isPickDown() const;

    void setPickDown(bool pickDown);

    [[nodiscard]] const QPointF &getVelocity() const;

    [[nodiscard]] const QPointF &getAcceleration() const;

    [[nodiscard]] bool isPicking() const;

    void setVelocity(const QPointF &velocity);

    void setAcceleration(const QPointF &acceleration);

    void processInput();

    Armor* pickupArmor(Armor* newArmor);

    [[nodiscard]] bool isOnGround() const;
    
    void setOnGround(bool onGround);

    void updateMove(double deltaTime);

protected:
    HeadEquipment *headEquipment{};
    LegEquipment *legEquipment{};
    Armor *armor{};
    QPointF velocity{};
    QPointF acceleration{};

//    QGraphicsEllipseItem *ellipseItem; // for debugging
private:
    bool leftDown{}, rightDown{}, jumpDown{}, pickDown{};
    bool lastPickDown{}, lastJumpDown{};
    bool picking{};
    bool onGround{};
};


#endif //QT_PROGRAMMING_2024_CHARACTER_H
