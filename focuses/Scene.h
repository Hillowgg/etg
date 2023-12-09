#pragma once
#include "Focusable.h"
#include "../utils/CameraController.h"
#include "../objects/Scene/World/World.h"
#include "../objects/UI/HUD.h"
#include "../objects/Scene/Player/Player.h"
#include <raylib-cpp.hpp>

#include "../objects/Scene/Enemies/Enemy.h"


struct Scene: public Focusable {
    static Scene& instance() {
        static Scene scene;
        return scene;
    }

    void reset();

    void draw() const override;

    void update() override;

    void focus() override;

    void unfocus() override;

    bool handleInputs() override;

    std::shared_ptr<Player> getPlayer() const;

    void spawnEnemy(const RVector2& pos);

    void spawnBoss(const RVector2& pos);

    void addEntity(Entity& entity) { entities.push_back(std::move(entity)); }

    size_t enemyCount() const { return npcs.size(); }

    std::vector<Projectile>& getProjectiles() { return projectiles; }

    std::shared_ptr<const CameraController> getCamera() const { return camera; }

private:
    explicit Scene();
    Scene(const Scene&) = delete;
    Scene& operator=(const Scene&) = delete;
    
    std::shared_ptr<CameraController> camera;
    std::unique_ptr<HUD> hud = std::make_unique<HUD>();
    std::shared_ptr<Player> player;
    std::unique_ptr<World> world;
    std::vector<std::unique_ptr<Character>> npcs;
    std::vector<Projectile> projectiles;
    std::vector<Entity> entities;
};
