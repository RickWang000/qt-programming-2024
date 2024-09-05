//
// Created by gerw on 8/21/24.
//

#ifndef QT_PROGRAMMING_2024_MOUNTABLE_H
#define QT_PROGRAMMING_2024_MOUNTABLE_H

#include <QDateTime>
#include <memory>

class Mountable {
public:
    Mountable();
    
    virtual void mountToParent();
    virtual void unmount();
    [[nodiscard]] bool isMounted() const;

    QDateTime getSpawnTime() const;

private:
    bool mounted{};
    QDateTime spawnTime; 
};


#endif //QT_PROGRAMMING_2024_MOUNTABLE_H
