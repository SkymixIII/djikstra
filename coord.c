#include "coord.h"


coord_t creer_coord(int abscisse, int ordonne){
    coord_t coo;
    coo.abscisse = abscisse;
    coo.ordonne = ordonne;
    return coo;   
}

int get_x(coord_t coo){
    return coo.abscisse;
}

int get_y(coord_t coo){
    return coo.ordonne;
}

void set_x(coord_t* coo, int val){
    coo->abscisse = val;
}

void set_y(coord_t* coo, int val){
    coo->ordonne = val;
}

bool memes_coord(coord_t coo1, coord_t coo2){
    return (coo1.abscisse == coo2.abscisse) && (coo1.ordonne == coo2.ordonne);
}

coord_t translation(coord_t coo, int dx, int dy){
    coord_t new_coo = creer_coord(coo.abscisse, coo.ordonne);
    new_coo.abscisse += dx;
    new_coo.ordonne += dy;
    return new_coo;
}

float distance_euclidienne(coord_t coo1, coord_t coo2){
    float distance;
    distance = sqrt((coo1.abscisse - coo2.abscisse)*(coo1.abscisse - coo2.abscisse) + (coo1.ordonne - coo2.ordonne)*(coo1.ordonne - coo2.ordonne));
    return distance;
}

