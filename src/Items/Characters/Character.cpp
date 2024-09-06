//
// Created by gerw on 8/20/24.
//

#include <QTransform>
#include "Character.h"

Character::Character(QGraphicsItem *parent) : Item(parent,""), healthText(new QGraphicsTextItem(this)), healthBar(new QGraphicsRectItem(this)) {
//    ellipseItem = new QGraphicsEllipseItem(-5, -5, 10, 10, this);
//    // Optionally, set some properties of the ellipse
//    ellipseItem->setBrush(Qt::green);          // Fill color
//    ellipseItem->setZValue(1);
    initHealthDisplay();
}

bool Character::isLeftDown() const {
    return leftDown;
}

void Character::setLeftDown(bool leftDown) {
    Character::leftDown = leftDown;
}

bool Character::isRightDown() const {
    return rightDown;
}

void Character::setRightDown(bool rightDown) {
    Character::rightDown = rightDown;
}

bool Character::isJumpDown() const {
    return jumpDown;
}

void Character::setJumpDown(bool jumpDown) {
    Character::jumpDown = jumpDown;
}

bool Character::isPickDown() const {
    return pickDown;
}

void Character::setPickDown(bool pickDown) {
    Character::pickDown = pickDown;
}

bool Character::isMeleeAttackDown() const {
    return meleeAttackDown;
}

void Character::setMeleeAttackDown(bool meleeAttackDown) {
    Character::meleeAttackDown = meleeAttackDown;
}

bool Character::isMeleeAttacking() const {
    return meleeAttacking;
}

MeleeWeapon *Character::getMeleeWeapon() const {
    return meleeWeapon;
}

void Character::processInput() {
    auto velocity = getVelocity();
    const auto moveSpeed = 0.1;
    bool moving = false;
    if (isLeftDown()) {
        velocity.setX( - moveSpeed);
        setTransform(QTransform().scale(1, 1));
        moving = true;
    } 
    if (isRightDown()) {
        velocity.setX( + moveSpeed);
        setTransform(QTransform().scale(-1, 1));
        moving = true;
    } 
    if (!moving) {
        velocity.setX(0);
    }
    auto acceleration = getAcceleration();
    if (isOnGround() && isJumpDown() && !lastJumpDown) {
        acceleration.setY(-0.015);
        setOnGround(false);
    } else {
        acceleration.setY(GRAVITY);
    }
    setVelocity(velocity);
    setAcceleration(acceleration);

    if (!lastPickDown && pickDown) { // first time pickDown
        picking = true;
    } else {
        picking = false;
    }

    if (isMeleeAttackDown() && !lastMeleeAttackDown) {
        if (meleeWeapon) {
            meleeWeapon->attack();
        }
        meleeAttacking = true;
    } else {
        meleeAttacking = false;
    }

    lastPickDown = pickDown;
    lastJumpDown = jumpDown;
    lastMeleeAttackDown = meleeAttackDown;

    
}

void Character::updateMove(double deltaTime) {
    setVelocity(getVelocity() + getAcceleration() * deltaTime);
    setPos(pos() + getVelocity() * deltaTime);
}

bool Character::isPicking() const {
    return picking;
}

Armor *Character::pickupArmor(Armor *newArmor) {
    auto oldArmor = armor;
    if (oldArmor != nullptr) {
        oldArmor->unmount();
        oldArmor->setPos(newArmor->pos());
        oldArmor->setParentItem(parentItem());
    }
    newArmor->setParentItem(this);
    newArmor->mountToParent();
    armor = newArmor;
    return oldArmor;
}

HeadEquipment *Character::pickupHeadEquipment(HeadEquipment *newHeadEquipment) {
    auto oldHeadEquipment = headEquipment;
    if (oldHeadEquipment != nullptr) {
        oldHeadEquipment->unmount();
        oldHeadEquipment->setPos(newHeadEquipment->pos());
        oldHeadEquipment->setParentItem(parentItem());
    }
    newHeadEquipment->setParentItem(this);
    newHeadEquipment->mountToParent();
    headEquipment = newHeadEquipment;
    return oldHeadEquipment;
}

LegEquipment *Character::pickupLegEquipment(LegEquipment *newLegEquipment) {
    auto oldLegEquipment = legEquipment;
    if (oldLegEquipment != nullptr) {
        oldLegEquipment->unmount();
        oldLegEquipment->setPos(newLegEquipment->pos());
        oldLegEquipment->setParentItem(parentItem());
    }
    newLegEquipment->setParentItem(this);
    newLegEquipment->mountToParent();
    legEquipment = newLegEquipment;
    return oldLegEquipment;
}

MeleeWeapon *Character::pickupMeleeWeapon(MeleeWeapon *newMeleeWeapon) {
    auto oldMeleeWeapon = meleeWeapon;
    if (oldMeleeWeapon != nullptr) {
        oldMeleeWeapon->unmount();
        oldMeleeWeapon->setPos(newMeleeWeapon->pos());
        oldMeleeWeapon->setParentItem(parentItem());
    }
    newMeleeWeapon->setParentItem(this);
    newMeleeWeapon->mountToParent();
    meleeWeapon = newMeleeWeapon;
    return oldMeleeWeapon;
}

Bow *Character::pickupBow(Bow *newBow) {
    auto oldBow = bow;
    if (oldBow != nullptr) {
        oldBow->unmount();
        oldBow->setPos(newBow->pos());
        oldBow->setParentItem(parentItem());
    }
    newBow->setParentItem(this);
    newBow->mountToParent();
    bow = newBow;
    return oldBow;
}

Arrow *Character::pickupArrow(Arrow *newArrow) {
    newArrow->setParentItem(this);
    arrows.push_back(newArrow);
    return newArrow;
}
// 获取生命值
int Character::getHealth() const { return health; }

// 设置生命值
void Character::setHealth(int health) { this->health = health; }

// 处理受到的伤害
void Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

// 初始化生命值显示
void Character::initHealthDisplay() {
    // 初始化血条
    healthBar->setRect(0, 0, 100, 15);
    healthBar->setBrush(Qt::red); 
    healthBar->setPos(-50, -220);
    healthBar->setZValue(0);
    // 初始化生命值显示
    healthText->setPos(-50, -220);
    healthText->setDefaultTextColor(Qt::black);
    healthText->setPlainText(QString("%1").arg(health));
    healthText->setZValue(1);
}

// 更新生命值显示
void Character::updateHealthDisplay() {
    healthBar->setRect(0, 0, health, 15);
    healthText->setPlainText(QString("%1").arg(health));
}
