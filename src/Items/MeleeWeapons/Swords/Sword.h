#ifndef QT_PROGRAMMING_2024_SWORD_H
#define QT_PROGRAMMING_2024_SWORD_H

#include "../MeleeWeapon.h"

class Sword : public MeleeWeapon {
public:
    explicit Sword(QGraphicsItem *parent, const QString &pixmapPath);
};

#endif //QT_PROGRAMMING_2024_SWORD_H