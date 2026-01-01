#include "coord.h"


coord_t creer_coord(int x, int y){
    coord_t coo;
    coo.x = x;
    coo.y = y;
    return coo;   
}

int get_x(coord_t coo){
    return coo.x;
}

int get_y(coord_t coo){
    return coo.y;
}

void set_x(coord_t* coo, int val){
    coo->x = val;
}

void set_y(coord_t* coo, int val){
    coo->y = val;
}

bool memes_coord(coord_t coo1, coord_t coo2){
    return (coo1.x == coo2.x) && (coo1.y == coo2.y);
}

coord_t translation(coord_t coo, int dx, int dy){
    coord_t new_coo = creer_coord(coo.x, coo.y);
    new_coo.x += dx;
    new_coo.y += dy;
    return new_coo;
}

float distance_euclidienne(coord_t coo1, coord_t coo2){
    float distance;
    distance = sqrt((coo1.x - coo2.x)*(coo1.x - coo2.x) + (coo1.y - coo2.y)*(coo1.y - coo2.y));
    return distance;
}

