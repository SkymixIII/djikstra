#include "dijkstra.h"
//#include "animation.h"

/**
 * cout : calcule le coût pour rejoindre le noeud suivant depuis le noeud
 * courant. Ce coût est égal à la distance euclidienne entre les deux noeuds,
 * plus le dénivelé entre ces deux noeuds s'il est positif.
 * 
 * Pré-conditions :
 *  - dans_les_bornes(grille, courant)
 *  - dans_les_bornes(grille, suivant)
 * Post-conditions :
 *  - cout > 0, potentiellement infini (INFINITIY)
 *
 * @param grille heightmap contenant les hauteurs
 * @param courant noeud duquel on part pour calculer le coût
 * @param suivant noeud auquel on arrive pour calculer le coût
 * @return coût pour passer de courant à suivant
 */
static float cout(grille_t grille, coord_t courant, coord_t suivant){
    float resultat = get_hauteur(grille, suivant)-get_hauteur(grille, courant);
    if (resultat>0.0){
        return distance_euclidienne(courant, suivant) + resultat;
    }
    return distance_euclidienne(courant, suivant);
}

/**
 * construire_chemin_vers - Construit le chemin depuis le noeud de départ donné vers le
 * noeud donné. On passe un chemin en entrée-sortie de la fonction, qui est mis à jour
 * par celle-ci.
 *
 * Ce sous-programme fonctionne récursivement :
 *  1. Si le noeud est égal au noeud de départ, on a fini
 *  2. Sinon, on construit le chemin du départ au noeud précédent (appel récursif)
 *  3. Dans tous les cas, on ajoute le noeud au chemin, avec les caractéristiques associées dans visites
 *
 * @param chemin [in/out] chemin dans lequel enregistrer les étapes depuis le départ vers noeud
 * @param visites [in] liste des noeuds visités créée par l'algorithme de Dijkstra
 * @param source noeud de départ du chemin
 * @param noeud noeud vers lequel on veut construire le chemin depuis le départ
 */
void construire_chemin_vers(liste_noeud_t** chemin, liste_noeud_t * visites, coord_t source, coord_t noeud){
    coord_t prec;
    float cout;
    if (memes_coord(source, noeud)){
        prec = precedent_noeud_liste(visites, noeud); 
        cout = cout_noeud_liste(visites, noeud);
        inserer_noeud_liste(*chemin, noeud, prec, cout);
        return; 
    }
    prec = precedent_noeud_liste(visites, noeud);
    construire_chemin_vers(chemin, visites, source, prec);
    cout = cout_noeud_liste(visites, noeud); 
    inserer_noeud_liste(*chemin, noeud, prec, cout);
}

float dijkstra(grille_t grille, coord_t source, coord_t destination, float seuil, liste_noeud_t** chemin){
    liste_noeud_t* visites = creer_liste();
    liste_noeud_t* aVisites = creer_liste();
    coord_t min_noeud_coord;
    inserer_noeud_liste(aVisites, source, source, 0.0);
    while (!est_vide_liste(aVisites)){
        min_noeud_coord = min_noeud_liste(aVisites);
        inserer_noeud_liste(visites,min_noeud_coord,precedent_noeud_liste(aVisites,min_noeud_coord),cout_noeud_liste(aVisites,min_noeud_coord));
        supprimer_noeud_liste(aVisites,min_noeud_coord);
        coord_t* voisins = NULL; 
        int n = get_voisins(grille, min_noeud_coord, seuil, &voisins); 
        for (int i = 0; i < n; i++){
            if (!contient_noeud_liste(visites, voisins[i])){
                float cout_maj = cout(grille, min_noeud_coord, voisins[i]) + cout_noeud_liste(visites, min_noeud_coord);
                float cout_actuel = cout_noeud_liste(aVisites, voisins[i]);
                
                if (cout_maj < cout_actuel){
                    inserer_noeud_liste(aVisites, voisins[i], min_noeud_coord, cout_maj);
                }
            }
        }
        free(voisins);
    }
    if (chemin != NULL){
        *chemin = creer_liste(); 
        construire_chemin_vers(chemin, visites, source, destination);
    }
    float resultat = cout_noeud_liste(visites, destination); 
    detruire_liste(&visites);  
    detruire_liste(&aVisites); 
    return resultat;
}


