//
// Created by gerw on 8/20/24.
//

#include <QTransform>
#include "Character.h"

Character::Character(QGraphicsItem *parent) : Item(parent, "") {
//    ellipseItem = new QGraphicsEllipseItem(-5, -5, 10, 10, this);
//    // Optionally, set some properties of the ellipse
//    ellipseItem->setBrush(Qt::green);          // Fill color
//    ellipseItem->setZValue(1);
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

const QPointF &Character::getVelocity() const {
    return velocity;
}

const QPointF &Character::getAcceleration() const {
    return acceleration;
}

void Character::setVelocity(const QPointF &velocity) {
    Character::velocity = velocity;
}

void Character::setAcceleration(const QPointF &acceleration) {
    Character::acceleration = acceleration;
}

bool Character::isOnGround() const {
    return onGround;
}

void Character::setOnGround(bool onGround) {
    Character::onGround = onGround;
}

void Character::processInput() {
    auto velocity = getVelocity();
    const auto moveSpeed = 0.15;
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
    auto acceleration = QPointF(0, 0);
    if (isOnGround() && isJumpDown() && !lastJumpDown) {
        acceleration.setY(-0.015);
        onGround = false;
    } else {
        acceleration.setY(0.001);
    }
    setVelocity(velocity);
    setAcceleration(acceleration);

    if (!lastPickDown && pickDown) { // first time pickDown
        picking = true;
    } else {
        picking = false;
    }
    lastPickDown = pickDown;
    lastJumpDown = jumpDown;
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

