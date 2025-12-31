#define _GNU_SOURCE
#include "liste_noeud.h"





liste_noeud_t* creer_liste(){
    liste_noeud_t* liste = malloc(sizeof(liste_noeud_t));
    if (liste != NULL){
        liste->tete = NULL;
        liste->taille = 0;
    }
    return liste;
}


void detruire_liste(liste_noeud_t ** liste_ptr){
    if (liste_ptr == NULL || *liste_ptr == NULL){
        return;
    }
    liste_noeud_t* liste = *liste_ptr;
    cellule_t* courant = liste->tete;
    while (courant != NULL){
        cellule_t* a_supprimer = courant;
        courant = courant->suivant;
        free(a_supprimer);
    }
    free(liste);
    *liste_ptr = NULL;
}


bool est_vide_liste(const liste_noeud_t * liste){
    return (liste->taille == 0);
}


bool contient_noeud_liste(const liste_noeud_t * liste, coord_t noeud){
    bool contient = false;
    if (liste == NULL){
        return false;
    }
    cellule_t * courant = liste->tete;
    while ((courant != NULL) && (!contient)){
        if (memes_coord(courant->noeud, noeud)){
            contient = true;
        }
        courant = courant->suivant;
    }
    return contient;
}


bool contient_arrete_liste(const liste_noeud_t * liste, coord_t source, coord_t destination){
    bool contient = false;
    if (liste == NULL){
        return false;
    }
    cellule_t * courant = liste->tete;
    while ((courant != NULL) && (!contient)){
        if (memes_coord(courant->noeud, destination) && (courant->precedent != NULL) && (memes_coord(courant->precedent->noeud, source))){
            contient = true;
        }
        courant = courant->suivant;
    }
    return contient;
}


float cout_noeud_liste(const liste_noeud_t * liste, coord_t noeud){
    float cout = INFINITY;
    if (liste == NULL){
        return INFINITY;
    }
    cellule_t * courant = liste->tete;
    while ((courant != NULL) && (cout == INFINITY)){
        if (memes_coord(courant->noeud, noeud)){
            cout = courant->cout;
        }
        courant = courant->suivant;
    }
    return cout;
}


coord_t precedent_noeud_liste(const liste_noeud_t * liste, coord_t noeud){
    coord_t noeud_resultat;
    noeud_resultat.abscisse = -1;
    noeud_resultat.ordonne = -1;
    if (liste == NULL){
        return noeud_resultat;
    }
    cellule_t * courant = liste->tete;
    while ((courant != NULL) ){
        if (memes_coord(courant->noeud, noeud)){
            noeud_resultat.abscisse = get_x(courant->precedent->noeud);
            noeud_resultat.ordonne = get_y(courant->precedent->noeud);
        }
        courant = courant->suivant;
    }
    return noeud_resultat;
}


coord_t min_noeud_liste(const liste_noeud_t * liste){
    float cout = INFINITY;
    coord_t noeud_resultat;
    cellule_t * courant = liste->tete;
    while (courant != NULL){
        if (courant->cout<cout){
            cout = courant->cout;
            noeud_resultat = courant->noeud;
        }
        courant = courant->suivant;
    }
    return noeud_resultat;
}


void inserer_noeud_liste(liste_noeud_t * liste, coord_t noeud, cellule_t* precedent, float cout){
    bool trouve = false; 
    cellule_t * courant = liste->tete;
    while ((courant != NULL) && (!trouve)){
        if (memes_coord(courant->noeud, noeud)){
            trouve = true;
        }else{
            courant = courant->suivant;
        } 
    }
    if (courant !=NULL){
        courant->precedent = precedent;
        courant->cout = cout;
    }
    
}

