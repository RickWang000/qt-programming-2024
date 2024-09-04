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

    // 按键相关方法
    [[nodiscard]] bool isLeftDown() const;
    void setLeftDown(bool leftDown);

    [[nodiscard]] bool isRightDown() const;
    void setRightDown(bool rightDown);

    [[nodiscard]] bool isJumpDown() const;
    void setJumpDown(bool jumpDown);

    [[nodiscard]] bool isPickDown() const;
    void setPickDown(bool pickDown);

    [[nodiscard]] bool isPicking() const;

    void processInput();


    // 装备相关方法
    Armor* pickupArmor(Armor* newArmor);

    
    // 运动相关方法
    [[nodiscard]] const QPointF &getVelocity() const;
    void setVelocity(const QPointF &velocity);

    [[nodiscard]] const QPointF &getAcceleration() const;
    void setAcceleration(const QPointF &acceleration);

    [[nodiscard]] bool isOnGround() const;
    void setOnGround(bool onGround);

    void updateMove(double deltaTime);

    // 生命值相关方法
    int getHealth() const;
    void setHealth(int health);
    void takeDamage(int damage);
    void initHealthDisplay();
    void updateHealthDisplay();

protected:
    HeadEquipment *headEquipment{};
    LegEquipment *legEquipment{};
    Armor *armor{};
    QPointF velocity{};
    QPointF acceleration{};
    int health{100}; // 初始生命值为100
    QGraphicsTextItem* healthText{}; // 用于显示生命值
    QGraphicsRectItem* healthBar{}; // 用于显示生命值的血条

//    QGraphicsEllipseItem *ellipseItem; // for debugging
private:
    bool leftDown{}, rightDown{}, jumpDown{}, pickDown{};
    bool lastPickDown{}, lastJumpDown{};
    bool picking{};
    bool onGround{};
};


#endif //QT_PROGRAMMING_2024_CHARACTER_H
