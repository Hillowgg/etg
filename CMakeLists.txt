cmake_minimum_required(VERSION 3.25)
project(raylib_trying)

find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()
set(CMAKE_CXX_STANDARD 20)
# This is the main part:
set(SOURCES main.cpp App.cpp App.h Window.cpp Window.h
        focuses/Focusable.h
        focuses/Scene.cpp
        focuses/Scene.h
        focuses/Scene.h
        focuses/Scene.h
        focuses/MainMenu.cpp
        focuses/MainMenu.h
        objects/UI/Button.cpp
        objects/UI/Button.h
        objects/UI/HUD.h
        objects/UI/HUD.cpp
        objects/UI/HUD.h
        objects/UI/HUD.h
        objects/UI/StatusBar.h
        objects/Scene/Player/Player.cpp
        objects/Scene/Player/Player.h
        objects/Scene/Enemies/Enemy.cpp
        objects/Scene/Enemies/Enemy.h
        objects/Scene/World/World.cpp
        objects/Scene/World/World.h
        objects/Scene/Guns/Projectile.h
        objects/Scene/Guns/Gun.h
        objects/Scene/Guns/Gun.cpp
        objects/Scene/Guns/Projectile.cpp
        objects/Base/Object.h
        objects/Base/TextureBase.h
        objects/Base/TextureBase.cpp
        objects/Base/Object.cpp
        objects/Base/TextureBase.cpp
        objects/Base/AutoAnimTexture.cpp
        objects/Base/AutoAnimTexture.h
        utils/CameraController.h
        utils/CameraController.cpp
        utils/SmartVector.cpp
        utils/SmartVector.h
        objects/Scene/Character.cpp
        objects/Scene/Character.h
        utils/Textures.h
        utils/Textures.cpp
        utils/Textures.cpp
        objects/Scene/World/RoomGraph.h
        objects/Scene/World/RoomGraph.cpp
        objects/Scene/World/Room/Room.h
        objects/Scene/World/Room/Room.cpp
        objects/Scene/World/Room/Chest.cpp
        objects/Scene/World/Room/Chest.h
        objects/Scene/World/Room/Entity.cpp
        objects/Scene/World/Room/Entity.h
        objects/Scene/Player/Boost.cpp
        objects/Scene/Player/Boost.h
        objects/Scene/Guns/SniperGun.cpp
        objects/Scene/Guns/SniperGun.h
        objects/Scene/Guns/PistolGun.cpp
        objects/Scene/Guns/PistolGun.h
        objects/Scene/Guns/RifleGun.cpp
        objects/Scene/Guns/RifleGun.h
        objects/Scene/Guns/ShotGun.cpp
        objects/Scene/Guns/ShotGun.h
        objects/Scene/Enemies/Boss.cpp
        objects/Scene/Enemies/Boss.h
)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

