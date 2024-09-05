
#ifndef QT_PROGRAMMING_2024_PHYSICAL_H
#define QT_PROGRAMMING_2024_PHYSICAL_H

#include <QPointF>

#define GRAVITY 0.001

class Physical {
public:
    const QPointF &getVelocity() const;
    const QPointF &getAcceleration() const;
    bool isOnGround() const;

    void setVelocity(const QPointF &velocity);
    void setAcceleration(const QPointF &acceleration);
    void setOnGround(bool onGround);

    virtual void updateMove(double deltaTime) = 0;

private:
    QPointF velocity{};
    QPointF acceleration{0, GRAVITY};
    bool onGround{};

};


#endif //QT_PROGRAMMING_2024_PHYSICAL_H
