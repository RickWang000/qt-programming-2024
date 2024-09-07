#include "Sword.h"
#include "../../Characters/Character.h"
#include <QSequentialAnimationGroup>

Sword::Sword(QGraphicsItem *parent, const QString &pixmapPath) : MeleeWeapon(parent, pixmapPath) {
    // 初始化剑的图像
}

void Sword::mountToParent() {
    Mountable::mountToParent();
    setScale(1);
    setTransform(QTransform().scale(-1, 1));
    setPos(-20, -170);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}

void Sword::playAttackAnimation() {
    int duration = 250;
    setTransformOriginPoint(this->boundingRect().bottomLeft());
    int startRotation = 0;
    int endRotation = 70;

    QPropertyAnimation *rotateForward = new QPropertyAnimation(this, "rotation");
    rotateForward->setDuration(duration);
    rotateForward->setStartValue(startRotation);
    rotateForward->setEndValue(endRotation);

    QPropertyAnimation *rotateBackward = new QPropertyAnimation(this, "rotation");
    rotateBackward->setDuration(duration);
    rotateBackward->setStartValue(endRotation);
    rotateBackward->setEndValue(startRotation);

    // 创建一个动画组来顺序播放两个动画
    QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup;
    animationGroup->addAnimation(rotateForward);
    animationGroup->addAnimation(rotateBackward);

    animationGroup->start(QAbstractAnimation::DeleteWhenStopped);
}