cmake_minimum_required(VERSION 3.8)
project(stratego)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

set(SOURCE_FILES main.cpp Board/GameBoard.cpp Board/GameBoard.h
        Game.cpp Game.h GameObject/Card.cpp GameObject/Card.h Player.cpp Player.h
        engine/Engine.h engine/Engine.cpp engine/Scene.h engine/Scene.cpp engine/Sprite.h engine/Sprite.cpp GameObject/GameObject.hpp Resource/SpriteCardsResource.cpp Resource/SpriteCardsResource.h Resource/StrategoEnum.h Board/SideBoard.cpp Board/SideBoard.h Resource/Background.cpp Resource/Background.h GameLogic/EventHandler.cpp GameLogic/EventHandler.h GameObject/HighLight.cpp GameObject/HighLight.h GameLogic/MouseClick.hpp NeutralPlayer.cpp NeutralPlayer.h)
add_executable(stratego ${SOURCE_FILES})

target_link_libraries(stratego ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})