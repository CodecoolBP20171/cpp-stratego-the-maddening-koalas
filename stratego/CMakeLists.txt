cmake_minimum_required(VERSION 3.8)
project(stratego)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

set(SOURCE_FILES main.cpp GameBoard.cpp GameBoard.h
        Game.cpp Game.h Card.cpp Card.h Player.cpp Player.h
        engine/Engine.h engine/Engine.cpp engine/Scene.h engine/Scene.cpp engine/Sprite.h engine/Sprite.cpp GameObject.hpp SpriteCardsResource.cpp SpriteCardsResource.h StrategoEnum.h SideBoard.cpp SideBoard.h Background.cpp Background.h EventHandler.cpp EventHandler.h HighLight.cpp HighLight.h)
add_executable(stratego ${SOURCE_FILES})

target_link_libraries(stratego ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})