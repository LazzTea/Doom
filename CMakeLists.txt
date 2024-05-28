cmake_minimum_required(VERSION 3.28)
project(project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project3
        Actors.cpp
        Actors.h
        Player.h
        Player.cpp
        Bogeymen.h
        Bogeymen.cpp
        MagicFang.cpp
        MagicAxes.cpp
        LongSwords.cpp
        ShortSwords.cpp
        Maces.h
        Weapons.h
        Objects.h
        Objects.cpp
        Weapons.cpp
        Maces.cpp
        utilities.cpp
        main.cpp
        Game.cpp
        Scrolls.cpp
        Scrolls.h
        ScrollsOfTeleportation.cpp
        ScrollsOfTeleportation.h
        ScrollsOfImprovedArmor.cpp
        ScrollsOfImprovedArmor.h
        ScrollsOfRaisedStrength.cpp
        ScrollsOfRaisedStrength.h
        ScrollsOfEnhancedHealth.cpp
        ScrollsOfEnhancedHealth.h
        ScrollsOfEnhancedDexterity.cpp
        ScrollsOfEnhancedDexterity.h
        Temple.cpp
        Temple.h
        Coord.cpp
        Coord.h
        Stairway.cpp
        Stairway.h
        Idol.cpp
        Idol.h
        Dragons.cpp
        Snakewomen.cpp
        Goblins.cpp)
