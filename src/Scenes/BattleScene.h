//
// Created by gerw on 8/20/24.
//

#ifndef QT_PROGRAMMING_2024_BATTLESCENE_H
#define QT_PROGRAMMING_2024_BATTLESCENE_H

#include <QKeyEvent>
#include <QLineEdit>
#include <QGraphicsProxyWidget>
#include "Scene.h"
#include "../Items/Maps/Map.h"
#include "../Items/Characters/Character.h"

class BattleScene : public Scene {
Q_OBJECT

public:
    explicit BattleScene(QObject *parent);

    void processInput() override;

    void processMovement() override;

    void processAttack();

    bool isEnemyInRange(Character* character, Character* enemy, qreal range);

    void attack(Character* character, Character* enemy);
    
    template <typename T>
    void checkCollision(T* object, Map* map);

    template <typename T>
    void spawnMountable(std::vector<std::pair<T*, double>> itemList, std::vector<Map*> maps, std::vector<T*>& itemContainer);


    void processPicking() override;

protected slots:

    void update() override;
    void handleCheatCode(); // 声明处理作弊码的槽函数
    

protected:
    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

private:

    Mountable *findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold = std::numeric_limits<qreal>::max());

    static Mountable * pickupMountable(Character *character, Mountable *mountable);

    void checkGameOver();
    void spawnArmor();
    void spawnHeadEquipment();
    void spawnLegEquipment();
    void spawnMeleeWeapon();
    void spawnBow();
    void spawnArrow();
    void checkExpiredMountables();

    std::vector<Map*> maps;
    std::vector<Character*> characters;
    std::vector<Armor*> armors;
    std::vector<HeadEquipment*> headEquipments;
    std::vector<LegEquipment*> legEquipments;
    std::vector<MeleeWeapon*> meleeWeapons;
    std::vector<Bow*> bows;
    std::vector<Arrow*> arrows;

    QLineEdit *cheatCodeInput; // 添加一个QLineEdit用于输入作弊码
    
};


#endif //QT_PROGRAMMING_2024_BATTLESCENE_H
