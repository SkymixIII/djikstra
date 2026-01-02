#define _GNU_SOURCE
#include "liste_noeud.h"



typedef struct cellule_t {
    coord_t noeud;
    float cout;
    struct coord_t precedent;
    struct cellule_t * suivant;
} cellule_t;


struct liste_noeud_t {
    cellule_t * tete;    
    int taille;          
};




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
    if (liste == NULL) return true;
    return (liste->taille == 0);
}

bool contient_noeud_liste(const liste_noeud_t * liste, coord_t noeud){
    if (liste == NULL){
        return false;
    }
    cellule_t * courant = liste->tete;
    while (courant != NULL){
        if (memes_coord(courant->noeud, noeud)){
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}

bool contient_arrete_liste(const liste_noeud_t * liste, coord_t source, coord_t destination){
    if (liste == NULL){
        return false;
    }
    cellule_t * courant = liste->tete;
    while (courant != NULL){
        if (memes_coord(courant->noeud, destination)){
            return memes_coord(courant->precedent, source);
        }
        courant = courant->suivant;
    }
    return false;
}

float cout_noeud_liste(const liste_noeud_t * liste, coord_t noeud){
    if (liste == NULL){
        return INFINITY;
    }
    cellule_t * courant = liste->tete;
    while (courant != NULL){
        if (memes_coord(courant->noeud, noeud)){
            return courant->cout;
        }
        courant = courant->suivant;
    }
    return INFINITY;
}

coord_t precedent_noeud_liste(const liste_noeud_t * liste, coord_t noeud){
    coord_t noeud_resultat;
    noeud_resultat.x = -1; 
    noeud_resultat.y = -1; 
    if (liste == NULL){
        return noeud_resultat;
    }
    cellule_t * courant = liste->tete;
    while (courant != NULL){
        if (memes_coord(courant->noeud, noeud)){
            return courant->precedent; 
        }
        courant = courant->suivant;
    }
    return noeud_resultat;
}

coord_t min_noeud_liste(const liste_noeud_t * liste){
    coord_t noeud_resultat = {-1, -1};
    if (liste == NULL || liste->tete == NULL) {
        return noeud_resultat;
    }
    float min_cout = INFINITY;
    cellule_t * courant = liste->tete;
    if (courant != NULL) {
        min_cout = courant->cout;
        noeud_resultat = courant->noeud;
    }
    while (courant != NULL){
        if (courant->cout < min_cout){
            min_cout = courant->cout;
            noeud_resultat = courant->noeud;
        }
        courant = courant->suivant;
    }
    return noeud_resultat;
}

void inserer_noeud_liste(liste_noeud_t * liste, coord_t noeud, coord_t precedent, float cout){
    if (liste == NULL) return;
    cellule_t * courant = liste->tete;
    bool stop = false;
    while ((courant != NULL) && (!stop)){
        if (memes_coord(courant->noeud, noeud)){
            courant->cout = cout;
            courant->precedent = precedent;
            stop = true;
        }
        courant = courant->suivant;
    }
    if (stop) return;
    cellule_t * nouveau = malloc(sizeof(cellule_t));
    if (nouveau == NULL) return;
    nouveau->noeud = noeud;
    nouveau->precedent = precedent; 
    nouveau->cout = cout;
    nouveau->suivant = liste->tete;
    liste->tete = nouveau;
    liste->taille++;
}

void supprimer_noeud_liste(liste_noeud_t * liste, coord_t noeud){
    if (liste == NULL || liste->tete == NULL) return;
    cellule_t * courant = liste->tete;
    cellule_t * prec = NULL;
    while (courant != NULL){
        if (memes_coord(courant->noeud, noeud)){
            if (prec == NULL){
                liste->tete = courant->suivant;
            } else {
                prec->suivant = courant->suivant;
            }
            free(courant);
            liste->taille--;
            return; 
        }
        prec = courant;
        courant = courant->suivant;
    }
}