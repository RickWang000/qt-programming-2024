#ifndef QT_PROGRAMMING_2024_SWORD_H
#define QT_PROGRAMMING_2024_SWORD_H

#include "../MeleeWeapon.h"
#include <QPropertyAnimation>

class Sword : public QObject, public MeleeWeapon {
Q_OBJECT
Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
public:
    explicit Sword(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;
    void playAttackAnimation() override;
};

#endif //QT_PROGRAMMING_2024_SWORD_H