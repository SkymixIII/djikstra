#ifndef COORD_H    
#define COORD_H

#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


/**
 * Type coord_t représentant un couple de coordonée, caractérisé par
 *  - l'x (entière)
 *  - l'ordonnée (entière)
 */
typedef struct coord_t {
    int x;
    int y;
} coord_t;


/**
 * creer_coord : creer une coordonnée d'un point ayant pour valeur d'x = x et et pour valeur d'ordonnée = ordonnée  
 *
 * Pré-conditions : x = int && y = int 
 * Post-conditions : *creer_coord(5,4).x == 5 && *creer_coord(5,4).y == 4
 *
 * @param x x 
 * @param y ye du point 
 * @return un pointeur vers la structure contenant la coordonée
 */
coord_t creer_coord(int x, int y);


/**
 * get_x : recupere l'x du point passer en parametre 
 *
 * Pré-conditions : coo != null
 * Post-conditions : coo.x == get_x(coo)
 *
 * @param coo point de coordonée dont on veut la valeur de l'x
 * @return l'absicce du point passé en parametre 
 */
int get_x(coord_t coo);


/**
 * get_y : recupere l'ordonnée du point passer en parametre 
 *
 * Pré-conditions : coo != null
 * Post-conditions : coo->y == get_y(coo)
 *
 * @param coo point de coordonée dont on veut la valeur de l'ordonée
 * @return l'ordonnée du point passé en parametre 
 */
int get_y(coord_t coo);


/**
 * set_x : change la valeur de l'x du point passé en paramètre 
 *
 * Pré-conditions : coo != null
 * Post-conditions : coo->x == val 
 *
 * @param coo point dont on veut changer l'x 
 * @param val nouvelle valeure d'x 
 */
void set_x(coord_t* coo, int val);


/**
 * set_y : change la valeur de l'ordonnée du point passé en paramètre 
 *
 * Pré-conditions : coo != null
 * Post-conditions : coo->y == val 
 *
 * @param coo point dont on veut changer l'ordonnée 
 * @param val nouvelle valeure d'ordonnée 
 */
void set_y(coord_t* coo, int val);


/**
 * memes_coord : verifie si les deux points passés en paramètres sont les mêmes
 *
 * Pré-conditions : coo1 != null && coo2 != null
 * Post-conditions : 
 *
 * @param coo1 point 1 
 * @param coo2 point 2
 * @return vrai si point1.x == point2.x && point1.y == point2.y; faux sinon 
 */
bool memes_coord(coord_t coo1, coord_t coo2);


/**
 * translation : renvoie un nouveau point dont l'x est dépalcé de dx et l'ordonnée de dy
 *
 * Pré-conditions : dx (int) && dy (int) && coo != null
 * Post-conditions : coo_return.x == coo.x + dx && coo_return.y == coo.y + dy
 *
 * @param coo point de base 
 * @param dx translation de l'x
 * @param dy translation de l'orodnnée
 * @return une copie du point en paramètre translaté de dx et dy 
 */
coord_t translation(coord_t coo, int dx, int dy);


/**
 * distance_euclidienne : calcul la distance euclidienne entre deux points 
 *
 * Pré-conditions : coo1 != null && coo2 != null 
 * Post-conditions : distance_euclidienne(point1,point2) >= 0
 *
 * @param coo1 point 1
 * @param coo2 point 2
 * @return la distance euclidienne entre coo1 et coo2
 */
float distance_euclidienne(coord_t coo1, coord_t coo2);


#endif



