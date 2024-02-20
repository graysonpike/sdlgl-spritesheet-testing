#include <sdlgl/game/clock.h>
#include <sdlgl/game/context.h>
#include <sdlgl/game/scene.h>
#include <sdlgl/graphics/graphics.h>
#include <sdlgl/input/inputs.h>
#include <sdlgl/ui/entity_count.h>
#include <sdlgl/ui/fps_display.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "tilemap.h"

#define BACKGROUND_COLOR (SDL_Color){222, 222, 222, 255}

int main() {
    srand(time(NULL));

    // Load a window
    Graphics::initialize(1020, 768);
    Context context(std::make_shared<Clock>());
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();
    Resources::get_instance().load_resources("resources.json");

    Resources& resources = Resources::get_instance();

    Texture furniture_tileset_texture = resources.get_texture("furniture");
    Tileset furniture_tileset = Tileset(furniture_tileset_texture, 16, 64);
    Tilemap furniture_tilemap = Tilemap(64, 16, 16, furniture_tileset);

    Texture room_tileset_texture = resources.get_texture("room_builder");
    Tileset room_tileset = Tileset(room_tileset_texture, 16, 64);
    Tilemap room_tilemap = Tilemap(64, 12, 12, room_tileset);

    room_tilemap.add_layer();
    room_tilemap.set_tile(0, 1, 0, 49);
    room_tilemap.set_tile(0, 2, 0, 49);
    room_tilemap.set_tile(0, 3, 0, 49);
    room_tilemap.set_tile(0, 4, 0, 49);
    room_tilemap.set_tile(0, 5, 0, 49);
    room_tilemap.set_tile(0, 6, 0, 49);
    room_tilemap.set_tile(0, 7, 0, 49);
    room_tilemap.set_tile(0, 8, 0, 49);
    room_tilemap.set_tile(0, 9, 0, 49);
    room_tilemap.set_tile(0, 10, 0, 49);
    room_tilemap.set_tile(0, 1, 1, 61);
    room_tilemap.set_tile(0, 2, 1, 61);
    room_tilemap.set_tile(0, 3, 1, 61);
    room_tilemap.set_tile(0, 4, 1, 61);
    room_tilemap.set_tile(0, 5, 1, 61);
    room_tilemap.set_tile(0, 6, 1, 61);
    room_tilemap.set_tile(0, 7, 1, 61);
    room_tilemap.set_tile(0, 8, 1, 61);
    room_tilemap.set_tile(0, 9, 1, 61);
    room_tilemap.set_tile(0, 10, 1, 61);
    room_tilemap.add_layer();
    room_tilemap.set_tile(1, 0, 0, 18);
    room_tilemap.set_tile(1, 1, 0, 19);
    room_tilemap.set_tile(1, 2, 0, 19);
    room_tilemap.set_tile(1, 3, 0, 19);
    room_tilemap.set_tile(1, 4, 0, 19);
    room_tilemap.set_tile(1, 5, 0, 19);
    room_tilemap.set_tile(1, 6, 0, 19);
    room_tilemap.set_tile(1, 7, 0, 19);
    room_tilemap.set_tile(1, 8, 0, 19);
    room_tilemap.set_tile(1, 9, 0, 19);
    room_tilemap.set_tile(1, 10, 0, 19);
    room_tilemap.set_tile(1, 11, 0, 20);
    room_tilemap.set_tile(1, 0, 1, 30);
    room_tilemap.set_tile(1, 11, 1, 32);

    while (*context.loop) {
        Graphics &graphics = Graphics::get_instance();
        Inputs &inputs = Inputs::get_instance();
        inputs.update();
        context.clock->tick();
        graphics.clear_screen(BACKGROUND_COLOR);

        room_tilemap.draw();

        scene->update(context.clock->get_delta());
        scene->render();

        if (inputs.get_quit()) {
            *context.loop = false;
        }

        graphics.present_renderer(context.clock->get_delta());
    }

    return 0;
}
