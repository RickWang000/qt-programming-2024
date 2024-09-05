#ifndef QT_PROGRAMMING_2024_SPEAR_H
#define QT_PROGRAMMING_2024_SPEAR_H

#include "../MeleeWeapon.h"

class Spear : public MeleeWeapon {
public:
    explicit Spear(QGraphicsItem *parent, const QString &pixmapPath);
};

#endif //QT_PROGRAMMING_2024_SPEAR_H