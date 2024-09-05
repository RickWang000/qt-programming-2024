//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_BATTLESCENE_H
#define QT_PROGRAMMING_2024_BATTLESCENE_H

#include <QKeyEvent>
#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"

class BattleScene : public Scene {
Q_OBJECT

public:
    explicit BattleScene(QObject *parent);

    void processInput() override;

    void processMovement() override;

    template <typename T>
    void checkCollision(T* object, Map* map);

    void processPicking() override;

protected slots:

    void update() override;

protected:
    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

private:

    Mountable *findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold = std::numeric_limits<qreal>::max());

    static Mountable * pickupMountable(Character *character, Mountable *mountable);

    void checkGameOver();
    void spawnArmor();

    std::vector<Map*> maps;
    std::vector<Character*> characters;
    std::vector<Armor*> armors;
};


#endif //QT_PROGRAMMING_2024_BATTLESCENE_H
