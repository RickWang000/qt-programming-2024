//
// Created by gerw on 8/21/24.
//

#include "Mountable.h"

Mountable::Mountable() {
    lastUnmountTime = QDateTime::currentDateTime(); // 初始化生成时间
}

void Mountable::unmount() {
    mounted = false;
    lastUnmountTime = QDateTime::currentDateTime(); // 更新 lastUnmountTime
}

bool Mountable::isMounted() const {
    return mounted;
}

void Mountable::mountToParent() {
    mounted = true;
}

QDateTime Mountable::getLastUnmountTime() const {
    return lastUnmountTime;
}