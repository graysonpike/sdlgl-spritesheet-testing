#ifndef TILESET_H
#define TILESET_H

#include <map>
#include <sdlgl/graphics/texture.h>


class Tileset {
    int src_scale;
    int dst_scale;
    Texture texture;
    int width; // Width in number of tiles
    SDL_Point get_src_coords(int tile);

public:
    Tileset(Texture texture, int src_scale, int dst_scale);
    void draw_tile(int x, int y, int tile);
};


#endif
