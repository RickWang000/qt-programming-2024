#ifndef QT_PROGRAMMING_2024_SPEAR_H
#define QT_PROGRAMMING_2024_SPEAR_H

#include "../MeleeWeapon.h"
#include <QPropertyAnimation>

class Spear : public QObject, public MeleeWeapon {
Q_OBJECT
Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    explicit Spear(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void playAttackAnimation() override;
};

#endif //QT_PROGRAMMING_2024_SPEAR_H