//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_CHARACTER_H
#define QT_PROGRAMMING_2024_CHARACTER_H

#include <QGraphicsEllipseItem>
#include "../HeadEquipments/HeadEquipment.h"
#include "../Armors/Armor.h"
#include "../LegEquipments/LegEquipment.h"
#include "../Physical.h"
#include "../MeleeWeapons/MeleeWeapon.h"
#include "../Bows/Bow.h"
#include "../Arrows/Arrow.h"

class Character : public Item , public Physical {
public:
    explicit Character(QGraphicsItem *parent);

    // 按键相关方法
    [[nodiscard]] bool isLeftDown() const;
    [[nodiscard]] bool isRightDown() const;
    [[nodiscard]] bool isJumpDown() const;
    [[nodiscard]] bool isPickDown() const;
    [[nodiscard]] bool isPicking() const;

    void setLeftDown(bool leftDown);
    void setRightDown(bool rightDown);
    void setJumpDown(bool jumpDown);
    void setPickDown(bool pickDown);

    void processInput();


    // 装备相关方法
    Armor* pickupArmor(Armor* newArmor);
    HeadEquipment* pickupHeadEquipment(HeadEquipment* newHeadEquipment);
    LegEquipment* pickupLegEquipment(LegEquipment* newLegEquipment);
    MeleeWeapon* pickupMeleeWeapon(MeleeWeapon* newMeleeWeapon);
    Bow* pickupBow(Bow* newBow);
    Arrow* pickupArrow(Arrow* newArrow);

    void updateMove(double deltaTime) override;

    // 生命值相关方法
    int getHealth() const;
    void setHealth(int health);
    void takeDamage(int damage);
    void initHealthDisplay();
    void updateHealthDisplay();

protected:
    Armor *armor{};
    HeadEquipment *headEquipment{};
    LegEquipment *legEquipment{};
    MeleeWeapon *meleeWeapon{};
    Bow *bow{};
    std::vector<Arrow*> arrows{};

    int health{100}; // 初始生命值为100
    QGraphicsTextItem* healthText{}; // 用于显示生命值
    QGraphicsRectItem* healthBar{}; // 用于显示生命值的血条

//    QGraphicsEllipseItem *ellipseItem; // for debugging
private:
    bool leftDown{}, rightDown{}, jumpDown{}, pickDown{};
    bool lastPickDown{}, lastJumpDown{};
    bool picking{};
};


#endif //QT_PROGRAMMING_2024_CHARACTER_H
