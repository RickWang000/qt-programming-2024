#include "Spear.h"
#include <QSequentialAnimationGroup>

Spear::Spear(QGraphicsItem *parent, const QString &pixmapPath) : MeleeWeapon(parent, pixmapPath) {
    
}

void Spear::mountToParent() {
    Mountable::mountToParent();
    setScale(1);
    setTransform(QTransform().scale(-2.5, 0.7));
    setPos(40, -150);
    if (pixmapItem != nullptr) {
        pixmapItem->setPos(0, 0);
    }
}
void Spear::playAttackAnimation() {
    int duration = 250;

    // 设置动画的起始和结束位置
    QPointF startPos = pos();
    QPointF endPos = startPos + QPointF(-50, 0); // 向前移动100个单位

    QPropertyAnimation *moveForward = new QPropertyAnimation(this, "pos");
    moveForward->setDuration(duration);
    moveForward->setStartValue(startPos);
    moveForward->setEndValue(endPos);

    QPropertyAnimation *moveBackward = new QPropertyAnimation(this, "pos");
    moveBackward->setDuration(duration);
    moveBackward->setStartValue(endPos);
    moveBackward->setEndValue(startPos);

    // 创建一个动画组来顺序播放两个动画
    QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup;
    animationGroup->addAnimation(moveForward);
    animationGroup->addAnimation(moveBackward);

    animationGroup->start(QAbstractAnimation::DeleteWhenStopped);
}