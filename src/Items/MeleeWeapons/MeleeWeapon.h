#ifndef QT_PROGRAMMING_2024_MELEEWEAPON_H
#define QT_PROGRAMMING_2024_MELEEWEAPON_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Physical.h"
#include "../Elemental.h"

class MeleeWeapon : public Item, public Mountable, public Physical, public Elemental {
public:
    explicit MeleeWeapon(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount() override;

    void updateMove(double deltaTime) override;

    virtual void playAttackAnimation() = 0;

    int getAttackRange() const;

    int getDamage() const;

    void setAttackRange(int attackRange);

    void setDamage(int damage);

private:
    int attackRange = 200;
    int damage = 5;
};

#endif //QT_PROGRAMMING_2024_MELEEWEAPON_H