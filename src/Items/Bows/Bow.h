#ifndef QT_PROGRAMMING_2024_BOW_H
#define QT_PROGRAMMING_2024_BOW_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Physical.h"
#include "../Elemental.h"

class Bow : public Item, public Mountable, public Physical, public Elemental {
public:
    explicit Bow(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount() override;

    void updateMove(double deltaTime) override;

    int getAttackRange() const;

    void setAttackRange(int attackRange);

    int getMultiShot() const;

    void setMultiShot(int multiShot);

private:
    int attackRange = 200;
    int multiShot = 1;
};

#endif //QT_PROGRAMMING_2024_BOW_H