//
// Created by gerw on 8/20/24.
//

#include <QDebug>
#include "BattleScene.h"
#include "../Items/Characters/Link.h"
#include "../Items/Maps/Battlefield.h"
#include "../Items/Armors/FlamebreakerArmor.h"

BattleScene::BattleScene(QObject *parent) : Scene(parent) {
    // This is useful if you want the scene to have the exact same dimensions as the view
    setSceneRect(0, 0, 1280, 720);
    map = new Battlefield();
    characters.push_back(new Link()); // 第一个角色
    characters.push_back(new Link()); // 第二个角色
    spareArmor = new FlamebreakerArmor();
    addItem(map);
    for (auto character : characters) {
        addItem(character);
    }
    addItem(spareArmor);
    map->scaleToFitScene(this);
    characters[0]->setPos(map->getSpawnPos());
    characters[1]->setPos(map->getSpawnPos() + QPointF(50, 0)); // 第二个角色的位置稍微偏移
    spareArmor->unmount();
    spareArmor->setPos(sceneRect().left() + (sceneRect().right() - sceneRect().left()) * 0.75, map->getFloorInfos().front().height);
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
        default:
            Scene::keyReleaseEvent(event);
    }
}

void BattleScene::update() {
    Scene::update();
}

void BattleScene::processMovement() {
    Scene::processMovement();
    for (auto character : characters) {
        if (character != nullptr) {
            character->setOnGround(map->isOnFloor(character->pos()));
            character->setVelocity(character->getVelocity() + character->getAcceleration() * (double) deltaTime);
            character->setPos(character->pos() + character->getVelocity() * (double) deltaTime);
            
            // 碰撞检测：如果人物的位置低于地面且位于地面内，调整人物的位置并重置速度和加速度
            auto posY = character->pos().y();
            auto posX = character->pos().x();
            auto velocity = character->getVelocity();
            auto floorInfos = map->getFloorInfos();
            
            // 如果物体在 y 方向的速度是下落的，则进行地板碰撞检测
            if (velocity.y() >= 0) {
                // 预测下一帧的位置
                auto nextPosY = posY + velocity.y() * deltaTime;
                auto nextPosX = posX + velocity.x() * deltaTime;
            
                for (const auto& floorInfo : floorInfos) {
                    if (
                        posY <= floorInfo.height + 60 && // 当前 y 值处于地板或地板下方一帧的高度
                        nextPosY > floorInfo.height && // 预测的 y 值低于地板高度
                        nextPosX >= floorInfo.startX && nextPosX <= floorInfo.endX) {
                        character->setY(floorInfo.height);
                        character->setVelocity({character->getVelocity().x(), 0});
                        character->setAcceleration({character->getAcceleration().x(), 0});
                        break; // 找到一个匹配的地板后退出循环
                    }
                }
            }
        }
    }
}

void BattleScene::processPicking() {
    Scene::processPicking();
    for (auto character : characters) {
        if (character->isPicking()) {
            auto mountable = findNearestUnmountedMountable(character->pos(), 100.);
            if (mountable != nullptr) {
                spareArmor = dynamic_cast<Armor *>(pickupMountable(character, mountable));
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
    }
    return nullptr;
}