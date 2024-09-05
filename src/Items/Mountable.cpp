//
// Created by gerw on 8/21/24.
//

#include "Mountable.h"

Mountable::Mountable() {
    spawnTime = QDateTime::currentDateTime(); // 初始化生成时间
}

void Mountable::unmount() {
    mounted = false;
}

bool Mountable::isMounted() const {
    return mounted;
}

void Mountable::mountToParent() {
    mounted = true;
}

QDateTime Mountable::getSpawnTime() const {
    return spawnTime;
}
