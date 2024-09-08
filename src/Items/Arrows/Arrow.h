#ifndef QT_PROGRAMMING_2024_ARROW_H
#define QT_PROGRAMMING_2024_ARROW_H

#include "../Item.h"
#include "../Mountable.h"
#include "../Physical.h"
#include "../Elemental.h"

class Arrow : public Item, public Mountable, public Physical, public Elemental {
public:
    explicit Arrow(QGraphicsItem *parent = nullptr, const QString &pixmapPath = "");

    void mountToParent() override;

    void unmount() override;

    void updateMove(double deltaTime) override;
};

#endif //QT_PROGRAMMING_2024_ARROW_H