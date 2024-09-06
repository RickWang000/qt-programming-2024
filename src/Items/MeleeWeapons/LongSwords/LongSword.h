#ifndef QT_PROGRAMMING_2024_LONGSWORD_H
#define QT_PROGRAMMING_2024_LONGSWORD_H

#include "../MeleeWeapon.h"

class LongSword : public MeleeWeapon {
public:
    explicit LongSword(QGraphicsItem *parent, const QString &pixmapPath);

    void attack() override;
};

#endif //QT_PROGRAMMING_2024_LONGSWORD_H