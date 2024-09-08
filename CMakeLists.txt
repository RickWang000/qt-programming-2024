cmake_minimum_required(VERSION 3.28)
project(qt_programming_2024)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(
        qt_programming_2024

        assets/assets.qrc

        src/main.cpp
        src/MyGame.cpp
        src/MyGame.h
        src/Items/Item.cpp
        src/Items/Item.h
        src/Items/Mountable.cpp
        src/Items/Mountable.h
        src/Items/Physical.cpp
        src/Items/Physical.h
        src/Items/Elemental.cpp
        src/Items/Elemental.h

        src/Items/Armors/Armor.cpp
        src/Items/Armors/Armor.h
        src/Items/Armors/FlamebreakerArmor.cpp
        src/Items/Armors/FlamebreakerArmor.h
        src/Items/Armors/OldShirt.cpp
        src/Items/Armors/OldShirt.h

        src/Items/Arrows/Arrow.cpp
        src/Items/Arrows/Arrow.h
        src/Items/Arrows/FireArrow.cpp
        src/Items/Arrows/FireArrow.h
        src/Items/Arrows/IceArrow.cpp
        src/Items/Arrows/IceArrow.h
        src/Items/Arrows/ShockArrow.cpp
        src/Items/Arrows/ShockArrow.h
        src/Items/Arrows/WoodArrow.cpp
        src/Items/Arrows/WoodArrow.h

        src/Items/Bows/Bow.cpp
        src/Items/Bows/Bow.h
        src/Items/Bows/ForestDwellersBow.cpp
        src/Items/Bows/ForestDwellersBow.h
        src/Items/Bows/PhrenicBow.cpp
        src/Items/Bows/PhrenicBow.h
        src/Items/Bows/SavageLynelBow.cpp
        src/Items/Bows/SavageLynelBow.h

        src/Items/Characters/Character.cpp
        src/Items/Characters/Character.h
        src/Items/Characters/Link.cpp
        src/Items/Characters/Link.h

        src/Items/HeadEquipments/HeadEquipment.cpp
        src/Items/HeadEquipments/HeadEquipment.h
        src/Items/HeadEquipments/CapOfTheHero.cpp
        src/Items/HeadEquipments/CapOfTheHero.h
        src/Items/HeadEquipments/FlamebreakerHelm.cpp
        src/Items/HeadEquipments/FlamebreakerHelm.h
        src/Items/HeadEquipments/ThunderHelm.cpp
        src/Items/HeadEquipments/ThunderHelm.h
        src/Items/HeadEquipments/ZantsHelmet.cpp
        src/Items/HeadEquipments/ZantsHelmet.h

        src/Items/LegEquipments/LegEquipment.cpp
        src/Items/LegEquipments/LegEquipment.h
        src/Items/LegEquipments/WellWornTrousers.cpp
        src/Items/LegEquipments/WellWornTrousers.h
        
        src/Items/Maps/Map.cpp
        src/Items/Maps/Map.h
        src/Items/Maps/Battlefield.cpp
        src/Items/Maps/Battlefield.h
        src/Items/Maps/Platform.cpp
        src/Items/Maps/Platform.h

        src/Items/MeleeWeapons/MeleeWeapon.cpp
        src/Items/MeleeWeapons/MeleeWeapon.h
        src/Items/MeleeWeapons/LongSwords/LongSword.cpp
        src/Items/MeleeWeapons/LongSwords/LongSword.h
        src/Items/MeleeWeapons/LongSwords/GreatThunderBlade.cpp
        src/Items/MeleeWeapons/LongSwords/GreatThunderBlade.h
        src/Items/MeleeWeapons/Spears/Spear.cpp
        src/Items/MeleeWeapons/Spears/Spear.h
        src/Items/MeleeWeapons/Spears/FrostSpear.cpp
        src/Items/MeleeWeapons/Spears/FrostSpear.h
        src/Items/MeleeWeapons/Swords/Sword.cpp
        src/Items/MeleeWeapons/Swords/Sword.h
        src/Items/MeleeWeapons/Swords/MasterSword.cpp
        src/Items/MeleeWeapons/Swords/MasterSword.h
        src/Items/MeleeWeapons/Swords/FlameBlade.cpp
        src/Items/MeleeWeapons/Swords/FlameBlade.h
        src/Items/MeleeWeapons/Swords/ForestDwellersSword.cpp
        src/Items/MeleeWeapons/Swords/ForestDwellersSword.h

        src/Scenes/Scene.cpp
        src/Scenes/Scene.h
        src/Scenes/BattleScene.cpp
        src/Scenes/BattleScene.h
)
target_link_libraries(qt_programming_2024
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
