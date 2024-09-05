#ifndef QT_PROGRAMMING_2024_MELEEWEAPON_H
#define QT_PROGRAMMING_2024_MELEEWEAPON_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Physical.h"

class MeleeWeapon : public Item, public Mountable, public Physical {
public:
    explicit MeleeWeapon(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount() override;

    void updateMove(double deltaTime) override;
};

#endif //QT_PROGRAMMING_2024_MELEEWEAPON_H