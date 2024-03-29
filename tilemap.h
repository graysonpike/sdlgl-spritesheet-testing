#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>

#include "tileset.h"

class Tilemap {
    int scale; // Px per tile
    int width; // In tiles
    int height; // In tiles
    std::vector<std::vector<int> > layers;
    Tileset tileset;

    int coords_to_index(int x, int y);
    SDL_Point index_to_coords(int index);

public:
    Tilemap(int scale, int width, int height, Tileset tileset);
    void add_layer();
    void set_tile(int layer, int x, int y, int tile);
    int get_tile(int layer, int x, int y);
    void draw();
    void draw(int layer);
};


#endif
