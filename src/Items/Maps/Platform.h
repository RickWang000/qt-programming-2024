#ifndef QT_PROGRAMMING_2024_PLATFORM_H
#define QT_PROGRAMMING_2024_PLATFORM_H

#include "Map.h"
#include "../Elemental.h"

// enum class MaterialType {
//     Wood,
//     Metal,
//     Stone
// };

class Platform: public Map, public Elemental {
public:
    explicit Platform(QGraphicsItem *parent = nullptr,
                      MaterialType material = MaterialType::Wood,
                      qint32 position = 1);

    void scaleToFitScene(QGraphicsScene *scene) override;

    qreal getFloorHeight() override;

    QPointF getFloorRange() override;

private:
    // MaterialType material{};
    qint32 position{};
};

#endif //QT_PROGRAMMING_2024_PLATFORM_H