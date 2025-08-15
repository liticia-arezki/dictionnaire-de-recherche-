#ifndef BIBLIOTHEQUE_H_INCLUDED
#define BIBLIOTHEQUE_H_INCLUDED


#define MAX_MOTS 10000 // nombre maximum de mots

/* ______________________________________ la strecture utulisee __________________________________*/

typedef struct liste {
   char *syll ;
   struct liste* suiv ;
} liste ;

typedef struct listebd {
   char *mot[25] ;
   char *motSlash[25] ;
   struct liste *syllable ;
   struct listebd *prec ;
   struct listebd *suiv ;
   struct listebd *MotsFormes ;
   struct listebd *ed ;
   struct listebd *ing ;
   struct listebd *ajouteLettre ;
   struct listebd *ProcheLexica ;
   struct listebd *anagramme ;
   int cara ;
   int cons ;
   int voy ;
   int syl ;
   char ordr [10] ;
   char ordalph[25] ;
   struct maillon* tete ;
   struct maillon* queue ;
} listebd ;


/*____________________________________________________________________________________________________________*/


/////////////////////////////// LES FONCTIONS DE LA MACHINE ABSTRAITE UTULISEE //////////////////////////////////

listebd* suivant(listebd* p) ; // elle nous affectue le maillon suivant de maillon donne
listebd* precedant(listebd* p) ; // elle nous affectue le maillon precedent de maillon donne
void suiv_Maillon (listebd* p,listebd* q) ; // elle affectue a un suivant de maillon un autre maillon
void prec_Maillon (listebd* p,listebd* q) ; // elle affectue a un precedent de maillon  un autre maillon
void deleteMaillonByValue(struct listebd **head , char *m   ) ; // la fonction qui cherche un mot dans une liste puis le supprimer
void freeListes (struct listebd* tete[] ) ; // la fonction qui liberes toutes les listes en donnant la tete :
void insererMot ( struct listebd* tete[] , char mot[] ) ; // la fonction qui inser un mot dans une liste et puis elle le met dans sa position


//////////////////////////////  LES FONCTION POUR CHANGER UN MAILLON PAR CHAMPS POUR LE TP ///////////////////////////////////

struct listebd *creemaillon (char *mot ) ; // Fonction pour cr�er un nouvel �l�ment

////////////////////////////// LES FONCTION UTULISEE POUR LA CREATION DE LA STRECTURE DEMANDEE ///////////////////////////////

int Separateur (char c) ; // la fonction qui precise le separateur dans un texte
void SuppSlash ( char mot[] ) ; // la fonction qui supprimes les salshs dans un mot
int compareChaines(char* chaine1, char* chaine2) ;  // la fonction qui renvoit un 0 si les deux mots donnes sont les memes
void trier ( char* T [] , int nbMots ) ;  // la fonction qui trie un tableau donnee selon la taille des mots puis selon l'ordre alphabitique si ils ont la meme taille
int NombCara ( char m[] ) ; // la fonction qui calculer le nombre de caractere dans un mot donner et le mot en englais  :
int NombCons ( char m[] ) ; // la fonction qui calculer le nombre de consonnes dans un mot donner en englais :
int NombVoy ( char m[] ) ; // la fonction calculer le nombre de voyelles dans un mot donner en englais :
int NombSyll ( char m[] ) ; // la fonction qui calculer le nombre de syllables dans un mot en englais donnee ( le syllables sont seprees par ' / ' ) :
int OrdrAlph ( char m[] ) ; // la fonction qui donne un boolean qui dit si un mot est dans l'ordre alphabitique ou non :
void OrdMot ( char mot[] ) ;  // la fonction qui donne un nouveau mot triee selon l'ordre alphabitique des lettres a partir d'un autre mot :
void freeTab ( char* T []  , int nbMots ) ; // la fonction qui libere un tableau :
void toLowerCase(char str[]) ;  // la fonction qui transforme tous le mot en miniscule
bool estVoyelle(char c) ;  // un boolean qui dit si c'est une voyelle ou non
int Chercher_Mot (struct listebd** tete[], char* mot ) ; // la fonction qui cherche un mot , une fois il est trouve elle returne 1
liste* create_list( char* mot , int n ) ;  // cree une sous liste qui contient les parties de mots separees par les "/" en renvoiyant la tete pour l'affectuer au champs de syllables de maillon
void CreeListeSyll ( struct listebd* tete[] ) ;  // la fonction qui cree pour les listes bidirectionnelles les sous listes de syllables
void remplir_listes_bidirecitionnelles (   FILE* fichier , struct listebd* tete[]  ) ; // la fonction qui remplit les 26 listtes bidirectionnelles et ses sous listes de syllables


//////////////////////// LES FONCTION UTULISEE POUR LA CREATION DES LIEN ENTRE LES MAILLONS PAR ORDRE DE QUESTION /////////////////////////

int MotForme (const char* m1 , const char* m2 ) ; // une fonction qui dit si un mot2 est form� a partir d'un autre mot1 et return si oui un et si non 0
int seTermineParED(char mot[]) ; //verifie si le mot se termine par ed et tourne 0 si non
void ajouteEd(char mot[], int nbSyllabes) ; // la fonction qui cree le partiipe passe d'un mot en anglais en ajoutant ed selon les regles de grammaire
int seTermineParIng(char *mot) ;  // verifie si un mot se termine par ing et tourne 0 si non
void ajouteIng(char *word) ; // la fonction qui ajoute au mot ing selon les regles de grammaire d'anglais
int Deff_Lettre (const char* m1, const char* m2) ; // la fonction qui verifie si on a ajouter une lettre ou il ya une defference d'une nouvelle lettre
int Proche_Lexicalement (char* m1 , char* m2) ; // une fonction qui dit sit deux mots ordonn�s sont proche lexicalement elle return 1 et si non elle return 0


////////////////// LES FONCTION DE CREATION DES LIENS ET CHQUE FONCTION DE CREATION AVEC SON AFFICHAGE /////////////////

int CreeMotsFormes ( struct listebd** tete[] ) ; // la fonction qui cree les liens entre les maillon qui ont de mots formee a partir d'autres mots et au meme temps elle calcule le nombre de liens cree pour la derniere question de tp
void Afficher_Mots_Formes ( struct listebd** tete[] ) ;  // la fonction qui affiche les liens entre les maillon qui ont de mots formee a partir d'autres mots
int CreeED ( struct listebd** tete[]) ; // la fonction qui cree les liens entre les maillon qui ont des verbes avec leur participe passe "ed" forme et au meme temps elle calcule le nombre de liens cree pour la derniere question de tp
void afficherED (struct listebd* tete[]) ; // la fonction qui affiche les liens entre les maillon qui ont des verbes avec leur participe passe "ed" forme
int CreeING ( struct listebd** tete[]) ; // la fonction qui cree les liens entre les maillon qui ont des verbes avec leur "ing" forme et au meme temps elle calcule le nombre de liens cree pour la derniere question de tp
void afficherING (struct listebd* tete[]) ; // la fonction qui affiche les liens entre les maillon qui ont des verbes avec leur "ing" forme
void afficherEdIng (struct listebd* tete[]) ; // la fonction qui affiche les liens entre les maillon qui ont des verbes avec leur participe passe "ed" forme et leur 'ing" forme ( les deux existe dans le fichier )
int CreeAjouteLettre ( struct listebd** tete[]) ; // la fonction qui cree les liens entre les maillon qui ont de mots formee a partir d'autres mots en ajoutant a chaque fois une lettre et au meme temps elle calcule le nombre de liens cree pour la derniere question de tp
void AfficherAjouteLettre ( struct listebd** tete[]) ; // la fonction qui affiche les liens entre les maillon qui ont de mots formee a partir d'autres mots en ajoutant a chaque fois une lettre
int CreeProchesLexicalement ( struct listebd** tete[] ) ; // la fonction qui cree les liens entre les maillon qui ont de mots proche lexicalement et calcule le nombre pour la dernier question
void Afficher_Proche_lexicalement ( struct listebd** tete[]) ; // la fonction qui affiche les liens entre les maillon qui ont de mots proche lexicalement
int CreeAnagramme (struct listebd** tete[]) ; // la fonction qui cree les liens entre les maillon qui ont de mots annagrames et calcule le nombre pour la dernier question
void Afficher_Anagramme(struct listebd** tete[] ) ; // la fonction qui affiche les liens entre les maillon qui ont de mots proche lexicalement

///////////////////////////////////// LES FONCTION UTULISEE POUR LES AUTRES CHOIX DANS LE MENU //////////////////////////////

void ChercherAfficher_Mot (struct listebd** tete[], char* mot ) ; // la fonction qui cherche un mot , une fois il est trouve elle returne tous ces caractheristiques
void ChercherEtSupprimer( struct listebd* tete[] , char* mot) ; // la fonction qui supprime un mot dans les listes
int Number_Mot (struct listebd** tete[] ) ; // la fonction qui donne le nombre de tous les mots
int taille_Liste ( listebd* tete ) ; //la fonction qui calcule la taille d'une liste :
void Taille_26Listes ( int tab_liste[] , struct listebd* tete[] ) ;// la fonction qui donne la taille de tous les tailles des listes et les classe dans un tableau :
int NumberEdIng (struct listebd* tete[]) ;// la fonction qui calcule le nombre de mots qui on leurs forme ed et ing au meme temps dans le fihcier
int tailleListeDelettre (int *tab_liste[] , char lettre ) ;// la fonction on lui donne la lettre elle nous donne la taille de la liste de cette lettre

/////////////////////////// LES FONCTIONS POUR L'AFFICHAGE DES LISTES DE SYLLABLLES ET SOUS LISTES ///////////////////////

void AFficher_26listes ( struct listebd* tete[] ) ; // la fonction qui affiche les listes selon l'ordre alphabitique avec tous les caracteristiques des mots
void AFficher_26listes_Sans_Details ( struct listebd* tete[] ) ;// la fonction qui affiche les listes selon l'ordre alphabitique mais sans les details juste les mots
void Affiche_listes_tailles (int tab_liste[] ) ; // la fonction qui donne les tailles de tous les listes  :


/////////////////////////////////////////////////////// LA FIN DES MODULES /////////////////////////////////////////////////////////////



#endif // BIBLIOTHEQUE_H_INCLUDED
