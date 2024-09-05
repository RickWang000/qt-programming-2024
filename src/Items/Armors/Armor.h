//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_ARMOR_H
#define QT_PROGRAMMING_2024_ARMOR_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Physical.h"

class Armor : public Item, public Mountable, public Physical {
public:
    explicit Armor(QGraphicsItem *parent, const QString &pixmapPath);

    void mountToParent() override;

    void unmount() override;

    void updateMove(double deltaTime) override;
};


#endif //QT_PROGRAMMING_2024_ARMOR_H
