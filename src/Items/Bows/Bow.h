#ifndef QT_PROGRAMMING_2024_BOW_H
#define QT_PROGRAMMING_2024_BOW_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Physical.h"

class Bow : public Item, public Mountable, public Physical {
public:
    explicit Bow(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount() override;

    void updateMove(double deltaTime) override;
};

#endif //QT_PROGRAMMING_2024_BOW_H