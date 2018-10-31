#include <iostream>

#include "go_to_bin_dir.hpp"

#include "EntityManager.hpp"

#include "common/systems/LuaSystem.hpp"
#include "common/systems/LogSystem.hpp"
#include "common/components/GraphicsComponent.hpp"
#include "common/components/TransformComponent.hpp"

int main(int, char ** av) {
    // Go to the executable's directory to be next to resources and scripts
    putils::goToBinDir(av[0]);

    // Create an EntityManager
    kengine::EntityManager em(std::make_unique<kengine::ExtensibleFactory>());

    // Load the specified systems, and any plugin placed in the executable's directory
    //      If you specify 'KENGINE_SFML' as TRUE in your CMakeLists.txt, this will load the SfSystem
    em.loadSystems<kengine::LuaSystem, kengine::LogSystem>(".");

    // To add a new system, simply add a DLL with a
    //      `ISystem *getSystem(kengine::EntityManager &em)`
    // function to the "plugins" directory


    // Get the factory and register any desired types
    auto & factory = em.getFactory<kengine::ExtensibleFactory>();
    factory.registerTypes<kengine::GameObject>();

    // Create a GameObject and attach Components to it
    auto & player = em.createEntity<kengine::GameObject>("player");
    player.attachComponent<kengine::TransformComponent3f>();
    player.attachComponent<kengine::GraphicsComponent>();

    // Attach a lua script to a GameObject
    auto & luaComp = player.attachComponent<kengine::LuaComponent>();
    luaComp.attachScript("scripts/unit/unit.lua");

    // Add a directory of scripts to be executed
    try {
        auto & lua = em.getSystem<kengine::LuaSystem>();
        lua.addScriptDirectory("scripts");
        lua.registerTypes<
                kengine::GraphicsComponent,
                kengine::TransformComponent3f, putils::Point<double, 3>, putils::Rect<double, 3>,
                kengine::LuaComponent,
                kengine::packets::Log
        >();
    }
    catch (const std::out_of_range &) {} // If the LuaSystem wasn't found, ignore

    // Start game
    while (em.running)
        em.execute();

    return (EXIT_SUCCESS);
}
