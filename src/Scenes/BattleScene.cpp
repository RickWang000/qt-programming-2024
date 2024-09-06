//
// Created by gerw on 8/20/24.
//

#include <QDebug>
#include <QMessageBox>
#include <algorithm>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMap>
#include <functional>

#include "BattleScene.h"
#include "../Items/Characters/Link.h"
#include "../Items/Maps/Battlefield.h"
#include "../Items/Maps/Platform.h"

// Armor 类
#include "../Items/Armors/OldShirt.h"
#include "../Items/Armors/FlamebreakerArmor.h"

// Arrow 类
#include "../Items/Arrows/FireArrow.h"
#include "../Items/Arrows/IceArrow.h"
#include "../Items/Arrows/ShockArrow.h"
#include "../Items/Arrows/WoodArrow.h"

// Bow 类
#include "../Items/Bows/ForestDwellersBow.h"
#include "../Items/Bows/PhrenicBow.h"
#include "../Items/Bows/SavageLynelBow.h"

// HeadEquipment 类
#include "../Items/HeadEquipments/CapOfTheHero.h"
#include "../Items/HeadEquipments/FlamebreakerHelm.h"
#include "../Items/HeadEquipments/ThunderHelm.h"
#include "../Items/HeadEquipments/ZantsHelmet.h"

// LegEquipment 类
#include "../Items/LegEquipments/WellWornTrousers.h"

// MeleeWeapon 类
#include "../Items/MeleeWeapons/LongSwords/GreatThunderBlade.h"
#include "../Items/MeleeWeapons/Spears/FrostSpear.h"
#include "../Items/MeleeWeapons/Swords/FlameBlade.h"
#include "../Items/MeleeWeapons/Swords/ForestDwellersSword.h"
#include "../Items/MeleeWeapons/Swords/MasterSword.h"


BattleScene::BattleScene(QObject *parent) : Scene(parent) {
    // This is useful if you want the scene to have the exact same dimensions as the view
    setSceneRect(0, 0, 1280, 720);
    std::srand(std::time(nullptr));

    maps.push_back(new Battlefield());
    maps.push_back(new Platform(nullptr, MaterialType::Wood,1));
    maps.push_back(new Platform(nullptr, MaterialType::Stone,2));
    maps.push_back(new Platform(nullptr, MaterialType::Metal,3));
    for (auto map : maps) {
        addItem(map);
        map->scaleToFitScene(this);
    }

    characters.push_back(new Link()); // 第一个角色
    characters.push_back(new Link()); // 第二个角色
    for (auto character : characters) {
        addItem(character);
    }
    characters[0]->setPos(maps[0]->getSpawnPos());
    characters[1]->setPos(maps[0]->getSpawnPos() + QPointF(50, 0)); // 第二个角色的位置稍微偏移

    // 创建QLineEdit用于输入作弊码
    cheatCodeInput = new QLineEdit();
    cheatCodeInput->setPlaceholderText("Enter cheat code");
    connect(cheatCodeInput, &QLineEdit::returnPressed, this, &BattleScene::handleCheatCode);

    // 将QLineEdit添加到场景中
    QGraphicsProxyWidget *proxy = addWidget(cheatCodeInput);
    proxy->setPos(10, 10); // 设置位置
}

void BattleScene::processInput() {
    Scene::processInput();
    for (auto character : characters) {
        if (character != nullptr) {
            character->processInput();
        }
    }
}

void BattleScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        // 第一个角色的按键绑定 (WASD)
        case Qt::Key_A:
            if (characters[0] != nullptr) {
                characters[0]->setLeftDown(true);
            }
            break;
        case Qt::Key_D:
            if (characters[0] != nullptr) {
                characters[0]->setRightDown(true);
            }
            break;
        case Qt::Key_W:
            if (characters[0] != nullptr) {
                characters[0]->setJumpDown(true);
            }
            break;
        case Qt::Key_S:
            if (characters[0] != nullptr) {
                characters[0]->setPickDown(true);
            }
            break;
        case Qt::Key_F:
            if (characters[0] != nullptr) {
                characters[0]->setMeleeAttackDown(true);
            }
            break;
        // 第二个角色的按键绑定 (IJKL)
        case Qt::Key_J:
            if (characters[1] != nullptr) {
                characters[1]->setLeftDown(true);
            }
            break;
        case Qt::Key_L:
            if (characters[1] != nullptr) {
                characters[1]->setRightDown(true);
            }
            break;
        case Qt::Key_I:
            if (characters[1] != nullptr) {
                characters[1]->setJumpDown(true);
            }
            break;
        case Qt::Key_K:
            if (characters[1] != nullptr) {
                characters[1]->setPickDown(true);
            }
            break;
        case Qt::Key_Semicolon:
            if (characters[1] != nullptr) {
                characters[1]->setMeleeAttackDown(true);
            }
            break;
        default:
            Scene::keyPressEvent(event);
    }
}

void BattleScene::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        // 第一个角色的按键绑定 (WASD)
        case Qt::Key_A:
            if (characters[0] != nullptr) {
                characters[0]->setLeftDown(false);
            }
            break;
        case Qt::Key_D:
            if (characters[0] != nullptr) {
                characters[0]->setRightDown(false);
            }
            break;
        case Qt::Key_W:
            if (characters[0] != nullptr) {
                characters[0]->setJumpDown(false);
            }
            break;
        case Qt::Key_S:
            if (characters[0] != nullptr) {
                characters[0]->setPickDown(false);
            }
            break;
        case Qt::Key_F:
            if (characters[0] != nullptr) {
                characters[0]->setMeleeAttackDown(false);
            }
            break;
        // 第二个角色的按键绑定 (IJKL)
        case Qt::Key_J:
            if (characters[1] != nullptr) {
                characters[1]->setLeftDown(false);
            }
            break;
        case Qt::Key_L:
            if (characters[1] != nullptr) {
                characters[1]->setRightDown(false);
            }
            break;
        case Qt::Key_I:
            if (characters[1] != nullptr) {
                characters[1]->setJumpDown(false);
            }
            break;
        case Qt::Key_K:
            if (characters[1] != nullptr) {
                characters[1]->setPickDown(false);
            }
            break;
        case Qt::Key_Semicolon:
            if (characters[1] != nullptr) {
                characters[1]->setMeleeAttackDown(false);
            }
            break;
        default:
            Scene::keyReleaseEvent(event);
    }
}

void BattleScene::update() {
    Scene::update();

    spawnArmor();
    spawnHeadEquipment();
    spawnLegEquipment();
    spawnMeleeWeapon();
    spawnBow();
    spawnArrow();
    // checkExpiredMountables();

    processAttack();

    checkGameOver();
}

void BattleScene::processAttack() {
    for (auto character : characters) {
        if (character != nullptr) {
            for (auto enemy : characters) {
                if (enemy != nullptr && enemy != character) {
                    if (isEnemyInRange(character, enemy, 150)) {
                        attack(character, enemy);
                        qDebug() << "Attack!";
                    }
                }
            }
        }
    }
}

bool BattleScene::isEnemyInRange(Character *character, Character *enemy, qreal range) {
    // 计算角色与敌人之间的距离
    qreal distance = QLineF(character->pos(), enemy->pos()).length();
    if (distance >= range) {
        return false;
    }

    // 获取角色的旋转角度（以度为单位）
    qreal characterRotation = character->rotation();

    // 将角度转换为弧度
    qreal characterRotationRad = qDegreesToRadians(characterRotation);

    // 计算角色面向方向的向量
    QPointF directionVector(cos(characterRotationRad), sin(characterRotationRad));

    // 计算角色与敌人之间的向量
    QPointF enemyVector = enemy->pos() - character->pos();

    // 归一化敌人向量
    qreal enemyVectorLength = sqrt(enemyVector.x() * enemyVector.x() + enemyVector.y() * enemyVector.y());
    QPointF normalizedEnemyVector = enemyVector / enemyVectorLength;

    // 计算两个向量的夹角
    qreal dotProduct = directionVector.x() * normalizedEnemyVector.x() + directionVector.y() * normalizedEnemyVector.y();
    qreal angle = acos(dotProduct);

    // 判断夹角是否在允许的范围内（例如，10度）
    qreal maxAngle = qDegreesToRadians(10.0); // 10度
    return angle < maxAngle;
    qDebug() << "angle: " << angle;
}


void BattleScene::attack(Character *character, Character *enemy) {
    if (character->isMeleeAttackDown() && !character->isMeleeAttacking()) {
        enemy->takeDamage(5);
        character->setMeleeAttackDown(false);
    } 
}
void BattleScene::processMovement() {
    Scene::processMovement();
    for (auto map : maps){ // 对每个 map 进行循环
        for (auto character : characters){
            if (character != nullptr){
                if (map->isOnFloor(character->pos())){
                    character->setOnGround(true);
                }
                character->updateMove(deltaTime);
                checkCollision(character, map);
            }
        }

        for (auto armor : armors){
            if (armor != nullptr){
                armor->updateMove(deltaTime);
                checkCollision(armor, map);
            }
        }

        for (auto headEquipment : headEquipments){
            if (headEquipment != nullptr){
                headEquipment->updateMove(deltaTime);
                checkCollision(headEquipment, map);
            }
        }

        for (auto legEquipment : legEquipments){
            if (legEquipment != nullptr){
                legEquipment->updateMove(deltaTime);
                checkCollision(legEquipment, map);
            }
        }

        for (auto meleeWeapon : meleeWeapons){
            if (meleeWeapon != nullptr){
                meleeWeapon->updateMove(deltaTime);
                checkCollision(meleeWeapon, map);
            }
        }

        for (auto bow : bows){
            if (bow != nullptr){
                bow->updateMove(deltaTime);
                checkCollision(bow, map);
            }
        }

        for (auto arrow : arrows){
            if (arrow != nullptr){
                arrow->updateMove(deltaTime);
                checkCollision(arrow, map);
            }
        }
    }
}

template <typename T>
void BattleScene::checkCollision(T* object, Map* map) {
    // 碰撞检测：如果物体的位置低于地面且位于地面内，调整物体的位置并重置速度和加速度
    auto posY = object->pos().y();
    auto posX = object->pos().x();
    auto velocity = object->getVelocity();
    auto floorHeight = map->getFloorHeight();
    auto floorRange = map->getFloorRange();

    // 如果物体在 y 方向的速度是下落的，则进行地板碰撞检测
    if (velocity.y() >= 0) {
        // 预测下一帧的位置
        auto nextPosY = posY + velocity.y() * deltaTime;
        auto nextPosX = posX + velocity.x() * deltaTime;

        // 检查物体是否在地板上或地板下方一帧的高度，并且在地图的边界矩形内
        if (posY <= floorHeight + 30 && // 当前 y 值处于地板或地板下方一帧的高度
            nextPosY > floorHeight && // 预测的 y 值低于地板高度
            nextPosX >= floorRange.x() && nextPosX <= floorRange.y() // 预测的 x 值在地图的边界矩形内 
            ){
            object->setY(floorHeight);
            object->setVelocity({object->getVelocity().x(), 0});
            object->setAcceleration({object->getAcceleration().x(), 0});
        }
    }
}

void BattleScene::processPicking() {
    Scene::processPicking();
    for (auto character : characters) {
        if (character->isPicking()) {
            auto mountable = findNearestUnmountedMountable(character->pos(), 100.);
            if (mountable != nullptr) {
                if (auto pickedHeadEquipment = dynamic_cast<HeadEquipment *>(pickupMountable(character, mountable))){ // 如果拾取的物品是头部装备
                    headEquipments.push_back(pickedHeadEquipment); // 将拾取的头部装备添加到headEquipments向量中
                }
                else if (auto pickedLegEquipment = dynamic_cast<LegEquipment *>(pickupMountable(character, mountable))){ // 如果拾取的物品是腿部装备
                    legEquipments.push_back(pickedLegEquipment); // 将拾取的腿部装备添加到legEquipments向量中
                }
                else if (auto pickedArmor = dynamic_cast<Armor *>(pickupMountable(character, mountable))){ // 如果拾取的物品是盔甲
                    armors.push_back(pickedArmor); // 将拾取的盔甲添加到armors向量中
                }
                else if (auto pickedMeleeWeapon = dynamic_cast<MeleeWeapon *>(pickupMountable(character, mountable))){ // 如果拾取的物品是近战武器
                    meleeWeapons.push_back(pickedMeleeWeapon); // 将拾取的近战武器添加到meleeWeapons向量中
                }
                else if (auto pickedBow = dynamic_cast<Bow *>(pickupMountable(character, mountable))){ // 如果拾取的物品是弓
                    bows.push_back(pickedBow); // 将拾取的弓添加到bows向量中
                }
                else if (auto pickedArrow = dynamic_cast<Arrow *>(pickupMountable(character, mountable))){ // 如果拾取的物品是箭
                    arrows.push_back(pickedArrow); // 将拾取的箭添加到arrows向量中
                }
            }
        }
    }
}

Mountable *BattleScene::findNearestUnmountedMountable(const QPointF &pos, qreal distance_threshold) {
    Mountable *nearest = nullptr;
    qreal minDistance = distance_threshold;

    for (QGraphicsItem *item: items()) {
        if (auto mountable = dynamic_cast<Mountable *>(item)) {
            if (!mountable->isMounted()) {
                qreal distance = QLineF(pos, item->pos()).length();
                if (distance < minDistance) {
                    minDistance = distance;
                    nearest = mountable;
                }
            }
        }
    }

    return nearest;
}

Mountable *BattleScene::pickupMountable(Character *character, Mountable *mountable) {
    // Limitation: currently only supports armor
    if (auto armor = dynamic_cast<Armor *>(mountable)) {
        return character->pickupArmor(armor);
    } else if (auto headEquipment = dynamic_cast<HeadEquipment *>(mountable)) {
        return character->pickupHeadEquipment(headEquipment);
    } else if (auto legEquipment = dynamic_cast<LegEquipment *>(mountable)) {
        return character->pickupLegEquipment(legEquipment);
    } else if (auto meleeWeapon = dynamic_cast<MeleeWeapon *>(mountable)) {
        return character->pickupMeleeWeapon(meleeWeapon);
    } else if (auto bow = dynamic_cast<Bow *>(mountable)) {
        return character->pickupBow(bow);
    } else if (auto arrow = dynamic_cast<Arrow *>(mountable)) {
        return character->pickupArrow(arrow);
    }
    return nullptr;
}


void BattleScene::checkGameOver() {
    for (auto character : characters) {
        if (character != nullptr) {
            character->updateHealthDisplay();
        }
    }
    for (auto character : characters) {
        if (character != nullptr && character->getHealth() <= 0) {
            // 游戏结束逻辑
            QString winner = (character == characters[0]) ? "Player 2" : "Player 1";
            QMessageBox::information(nullptr, "Game Over", "Game Over! Winner is " + winner);
            // 停止游戏，销毁场景
            clear();
            break;
        }
    }
}

// 定义模板函数
template <typename T>
void BattleScene::spawnMountable(std::vector<std::pair<T*, double>> itemList, std::vector<Map*> maps, std::vector<T*>& itemContainer) {
    // 生成一个随机数来决定是否生成物品
    if (std::rand() % 5000 != 0) {
        return; // 只有1/10000的概率继续执行
    }

    // 计算总概率
    double totalProbability = 0;
    for (const auto &item : itemList) {
        totalProbability += item.second;
    }

    // 生成一个随机数来决定掉落物品的类型
    double randomValue = (std::rand() / (double)RAND_MAX) * totalProbability;
    T *selectedItem = nullptr;

    for (const auto &item : itemList) {
        if (randomValue < item.second) {
            selectedItem = item.first;
            break;
        }
        randomValue -= item.second;
    }

    if (selectedItem != nullptr) {
        addItem(selectedItem);
        itemContainer.push_back(selectedItem);
        selectedItem->unmount();
        // 设置掉落物品的初始位置
        auto floorRange = maps[0]->getFloorRange();
        double randomX = floorRange.x() + (std::rand() / (double)RAND_MAX) * (floorRange.y() - floorRange.x());
        selectedItem->setPos(randomX, sceneRect().top());
    }
}

// 生成盔甲函数
void BattleScene::spawnArmor() {
    std::vector<std::pair<Armor*, double>> armorList = {
        {new OldShirt(), 0.5},
        {new FlamebreakerArmor(), 0.5}
    };
    spawnMountable(armorList, maps, armors);
}

void BattleScene::spawnHeadEquipment() {
    std::vector<std::pair<HeadEquipment*, double>> headEquipmentList = {
        // {new CapOfTheHero(), 0.5},
        {new FlamebreakerHelm(), 0.25},
        {new ThunderHelm(), 0.125},
        {new ZantsHelmet(), 0.125}
    };
    spawnMountable(headEquipmentList, maps, headEquipments);
}

void BattleScene::spawnLegEquipment() {
    std::vector<std::pair<LegEquipment*, double>> legEquipmentList = {
        {new WellWornTrousers(), 0.5}
    };
    spawnMountable(legEquipmentList, maps, legEquipments);
}

void BattleScene::spawnMeleeWeapon() {
    std::vector<std::pair<MeleeWeapon*, double>> meleeWeaponList = {
        {new MasterSword(), 0.5},
        {new FlameBlade(), 0.25},
        {new ForestDwellersSword(), 0.125},
        {new GreatThunderBlade(), 0.0625},
        {new FrostSpear(), 0.0625}
    };
    spawnMountable(meleeWeaponList, maps, meleeWeapons);
}

void BattleScene::spawnBow() {
    std::vector<std::pair<Bow*, double>> bowList = {
        {new ForestDwellersBow(), 0.5},
        {new PhrenicBow(), 0.25},
        {new SavageLynelBow(), 0.25}
    };
    spawnMountable(bowList, maps, bows);
}

void BattleScene::spawnArrow() {
    std::vector<std::pair<Arrow*, double>> arrowList = {
        {new FireArrow(), 0.25},
        {new IceArrow(), 0.25},
        {new ShockArrow(), 0.25},
        {new WoodArrow(), 0.25}
    };
    spawnMountable(arrowList, maps, arrows);
}

void BattleScene::checkExpiredMountables() {
    auto now = QDateTime::currentDateTime();

    auto checkAndRemove = [&](auto& container) {
        container.erase(std::remove_if(container.begin(), container.end(), [&](auto item) {
            if (item) { // 先检测物体是否存在
                if (!item->isMounted() && item->getLastUnmountTime().secsTo(now) > 10) { // 如果物品未被拾取时间超过10秒
                    removeItem(item);
                    delete item;
                    item = nullptr; // 将指针置为nullptr
                    return true;
                }
            }
            return false;
        }), container.end());
    };

    checkAndRemove(armors);
    checkAndRemove(headEquipments);
    checkAndRemove(legEquipments);
    checkAndRemove(meleeWeapons);
    checkAndRemove(bows);
    checkAndRemove(arrows);
}

void BattleScene::handleCheatCode() {
    QString cheatCode = cheatCodeInput->text().toLower(); // 将输入转换为小写
    QPointF spawnPos(sceneRect().center().x(), sceneRect().top()); // 设置生成位置为屏幕顶部的中间

    // 定义一个映射，将作弊码映射到生成物体的函数
    static const QMap<QString, std::function<void()>> cheatCodeMap = {
        // {"11", [this, spawnPos]() { auto item = new OldShirt(); item->setPos(spawnPos); armors.push_back(item); addItem(item); }},
        {"12", [this, spawnPos]() { auto item = new FlamebreakerArmor(); item->setPos(spawnPos); armors.push_back(item); addItem(item); }},
        {"21", [this, spawnPos]() { auto item = new CapOfTheHero(); item->setPos(spawnPos); headEquipments.push_back(item); addItem(item); }},
        {"22", [this, spawnPos]() { auto item = new FlamebreakerHelm(); item->setPos(spawnPos); headEquipments.push_back(item); addItem(item); }},
        {"23", [this, spawnPos]() { auto item = new ThunderHelm(); item->setPos(spawnPos); headEquipments.push_back(item); addItem(item); }},
        {"24", [this, spawnPos]() { auto item = new ZantsHelmet(); item->setPos(spawnPos); headEquipments.push_back(item); addItem(item); }},
        {"31", [this, spawnPos]() { auto item = new WellWornTrousers(); item->setPos(spawnPos); legEquipments.push_back(item); addItem(item); }},
        {"41", [this, spawnPos]() { auto item = new MasterSword(); item->setPos(spawnPos); meleeWeapons.push_back(item); addItem(item); }},
        {"42", [this, spawnPos]() { auto item = new FlameBlade(); item->setPos(spawnPos); meleeWeapons.push_back(item); addItem(item); }},
        {"43", [this, spawnPos]() { auto item = new ForestDwellersSword(); item->setPos(spawnPos); meleeWeapons.push_back(item); addItem(item); }},
        {"44", [this, spawnPos]() { auto item = new GreatThunderBlade(); item->setPos(spawnPos); meleeWeapons.push_back(item); addItem(item); }},
        {"45", [this, spawnPos]() { auto item = new FrostSpear(); item->setPos(spawnPos); meleeWeapons.push_back(item); addItem(item); }},
        {"51", [this, spawnPos]() { auto item = new ForestDwellersBow(); item->setPos(spawnPos); bows.push_back(item); addItem(item); }},
        {"52", [this, spawnPos]() { auto item = new PhrenicBow(); item->setPos(spawnPos); bows.push_back(item); addItem(item); }},
        {"53", [this, spawnPos]() { auto item = new SavageLynelBow(); item->setPos(spawnPos); bows.push_back(item); addItem(item); }},
        {"61", [this, spawnPos]() { auto item = new FireArrow(); item->setPos(spawnPos); arrows.push_back(item); addItem(item); }},
        {"62", [this, spawnPos]() { auto item = new IceArrow(); item->setPos(spawnPos); arrows.push_back(item); addItem(item); }},
        {"63", [this, spawnPos]() { auto item = new ShockArrow(); item->setPos(spawnPos); arrows.push_back(item); addItem(item); }},
        {"64", [this, spawnPos]() { auto item = new WoodArrow(); item->setPos(spawnPos); arrows.push_back(item); addItem(item); }}
    };

    // 查找并执行对应的生成函数
    auto it = cheatCodeMap.find(cheatCode);
    if (it != cheatCodeMap.end()) {
        it.value()();
    } else {
        qDebug() << "Unknown cheat code:" << cheatCode;
    }

    cheatCodeInput->clear(); // 清空输入框
}