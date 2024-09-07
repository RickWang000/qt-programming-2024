#ifndef QT_PROGRAMMING_2024_LONGSWORD_H
#define QT_PROGRAMMING_2024_LONGSWORD_H

#include "../MeleeWeapon.h"
#include <QPropertyAnimation>

class LongSword : public QObject, public MeleeWeapon {
Q_OBJECT
Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
public:
    explicit LongSword(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;
    void playAttackAnimation() override;
};

#endif //QT_PROGRAMMING_2024_LONGSWORD_H