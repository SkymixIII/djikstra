#define _GNU_SOURCE
#include "grille.h"
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/**
 * coord_lin : fonction statique (de module) qui transforme des coordonnées
 * cartésiennes dans la grille en coordonnées "linéaires" permettant d'adresser
 * le tableau contenu dans la grille.
 *
 * @param grille grille avec le bon système de coordonnées
 * @param position position dans la grille en coordonnées cartésiennes entières
 * @return position dans le tableau en coordonnée linéaire
 */
static size_t coord_lin(grille_t grille, coord_t position) {
    return grille.largeur * position.ordonne + position.abscisse;
}


grille_t creer_grille(int largeur, int profondeur){
    float * tab = malloc(sizeof(float) * largeur * profondeur);
    grille_t grille;
    grille.largeur = largeur;
    grille.profondeur = profondeur;
    grille.tableau = tab;
    return grille;
}


void detruire_grille(grille_t grille){
    free(grille.tableau);
}


bool dans_les_bornes(grille_t grille, coord_t position){
    return (0<=position.abscisse && position.abscisse<=grille.largeur-1) && (0<=position.ordonne && position.ordonne<=grille.profondeur-1);
}


int get_largeur(grille_t grille){
    return grille.largeur;
}


int get_profondeur(grille_t grille){
    return grille.profondeur;
}


coord_t inferieur_gauche(grille_t grille){
    return creer_coord(0,0);
}


coord_t superieur_droit(grille_t grille){
    return creer_coord(grille.largeur - 1, grille.profondeur - 1);
}


void set_hauteur(grille_t grille, coord_t position, float hauteur){
    grille.tableau[coord_lin(grille, position)] = hauteur;
}


float get_hauteur(grille_t grille, coord_t position){
    return grille.tableau[coord_lin(grille, position)]; 
}



size_t get_voisins(grille_t grille, coord_t position, float seuil, coord_t** voisins){
    coord_t directions[4] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    coord_t temp_voisins[4];
    int compteur = 0;
    float hauteur_position = get_hauteur(grille, position);
    for (int i = 0; i < 4; i++){
        coord_t candidat;
        candidat.abscisse = position.abscisse + directions[i].abscisse;
        candidat.ordonne = position.ordonne + directions[i].ordonne;
        if (dans_les_bornes(grille, candidat)){
            float hauteur_voisin = get_hauteur(grille, candidat);
            if (fabsf(hauteur_position - hauteur_voisin) <= seuil){
                temp_voisins[compteur] = candidat;
                compteur++;
            }
        }
    }
    if (compteur > 0) {
        *voisins = malloc(sizeof(coord_t) * compteur);
        for (int i = 0; i < compteur; i++) {
            (*voisins)[i] = temp_voisins[i];
        }
    } else {
        *voisins = NULL;
    }
    return compteur;
}
