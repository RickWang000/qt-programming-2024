#include "Physical.h"


const QPointF &Physical::getVelocity() const {
    return velocity;
}

const QPointF &Physical::getAcceleration() const {
    return acceleration;
}

bool Physical::isOnGround() const {
    return onGround;
}

void Physical::setVelocity(const QPointF &velocity) {
    Physical::velocity = velocity;
}

void Physical::setAcceleration(const QPointF &acceleration) {
    Physical::acceleration = acceleration;
}

void Physical::setOnGround(bool onGround) {
    Physical::onGround = onGround;
}

void Physical::updateMove(double deltaTime) {
    
}