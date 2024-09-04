#include "Platform.h"

Platform::Platform(QGraphicsItem *parent, MaterialType material, const qint32 position)
    : Map(parent, ""), material(material), position(position) {
    // 根据材质类型初始化平台的外观
    QString pixmapPath;
    switch (material) {
        case MaterialType::Wood:
            pixmapPath = ":/Items/Maps/Platform/Wood.png";
            break;
        case MaterialType::Metal:
            pixmapPath = ":/Items/Maps/Platform/Metal.png";
            break;
        case MaterialType::Stone:
            pixmapPath = ":/Items/Maps/Platform/Stone.png";
            break;
    }

    // 设置平台的外观
    if (pixmapPath != "") {
        pixmapItem = new QGraphicsPixmapItem(QPixmap(pixmapPath), this);
    }

}

void Platform::scaleToFitScene(QGraphicsScene *scene) {
    // Calculate scale factors to scale the item to fit the entire scene
    QRectF sceneRect = scene->sceneRect();
    QRectF itemRect = boundingRect();

    qreal scaleX = sceneRect.width() / itemRect.width();
    qreal scaleY = sceneRect.height() / itemRect.height();

    // Choose the smaller scale factor to maintain aspect ratio
    qreal scaleFactor = qMin(scaleX, scaleY) * 0.22;

    // Apply the scale to the item
    setTransform(QTransform::fromScale(scaleFactor, scaleFactor), true);

    // 设置平台的位置
    auto posFactor = QPointF(0, 0);
    switch (position) {
        case 1:
            posFactor = QPointF(0.2, 0.43);
            break;
        case 2:
            posFactor = QPointF(0.5, 0.19);
            break;
        case 3:
            posFactor = QPointF(0.79, 0.43);
            break;
    }
    setPos((sceneRect.width() - boundingRect().width() * scaleFactor) * posFactor.x(),
           (sceneRect.height() - boundingRect().height() * scaleFactor) * posFactor.y());

}

qreal Platform::getFloorHeight() {
    QPointF scenePos = pos();
    return (scenePos.y());
}

QPointF Platform::getFloorRange() {
    QPointF scenePos = pos();
    return {scenePos.x(), scenePos.x() + boundingRect().width()};
}