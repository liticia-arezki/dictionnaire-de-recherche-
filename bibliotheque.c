#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "bibliotheque.h"
#include "conio2.h"



/////////////////////////////// LES FONCTIONS DE LA MACHINE ABSTRAITE UTULISEE //////////////////////////////////

// elle nous affectue le maillon suivant de maillon donne
listebd* suivant(listebd* p) {
    return (*p).suiv ;
}

// elle nous affectue le maillon precedent de maillon donne
listebd* precedant(listebd* p) {
    return (*p).prec ;
}

// elle affectue a un suivant de maillon un autre maillon
void suiv_Maillon (listebd* p,listebd* q)
{p->suiv=q;}


// elle affectue a un precedent de maillon  un autre maillon
void prec_Maillon (listebd* p,listebd* q) {
    p->prec=q;
    }


// la fonction qui cherche un mot dans une liste puis le supprimer
void deleteMaillonByValue(struct listebd **head , char *m   )
{ if (*head == NULL) {
        return;    // Cas o� la liste est vide
    }
    struct listebd* del = *head ;
    while (del != NULL && strcmp( del->mot , m ) != 0) {
        del = del->suiv ; // Chercher le maillon a supprimer
    }
    if (del == NULL) {
        return; // Si le maillon a supprimer n'existe pas
    }
    if (del == *head) {
        *head = del->suiv;  // Si le maillon a supprimer est la tete de liste
    }
    if (del->suiv != NULL) {
        del->suiv->prec = del->prec ;  // Si le maillon a supprimer n'est pas la derniere maillon
    }
    if (del->prec != NULL) {
        del->prec->suiv = del->suiv ;  // Si le maillon a supprimer n'est pas la premiere maillon
    }
    free(del); // liberer la memoire occupee par le maillon a supprimer
    printf ( "\n the word has been deleted .  \n" ) ;
}


// la fonction qui liberes toutes les listes en donnant la tete :
void freeListes (struct listebd* tete[] ) {
for ( int i=0 ; i<26 ; i++ ) {
    struct listebd* head = tete[i] ;
    struct listebd* current = head; // on accede chaque fois a la tete de la liste
    while (current != NULL) {
        struct listebd* next = current->suiv;
        free(current); // on libere chaque maillon
        current = next ; // on parcour la liste
    }
}
}

// la fonction qui inser un mot dans une liste et puis elle le met dans sa position
void insererMot ( struct listebd* tete[] , char mot[] ){
int i=mot[0]-'a' ;  // on cherche l'indice pour la liste
struct listebd *p = creemaillon(mot) ; // on cree un maillon avec tous les carcteres de mot
 p->syllable = create_list ( p->motSlash , p->syl ) ; // on cree la sous liste des syllables
   struct listebd* q = tete[i] ; // on parcour les listes bidirectionnelles
    if (tete[i]==NULL) {
        tete[i]= p;
        return;
    } // on essaie de trouver la place de mot comparant la taille puis l'ordre alphabitique
    if (strlen(p->mot)<strlen((tete[i])->mot)) {
        suiv_Maillon(p,tete[i]);
        prec_Maillon(tete[i],p);
        tete[i]=p;
        return;
    }
    while ((suivant(q)!=NULL)&&(strlen(p->mot)>=strlen(suivant(q)->mot))) {
            q=suivant(q);
    }
    prec_Maillon(p,q);
    suiv_Maillon(p,q->suiv);
    if (suivant(q)!=NULL) {
        prec_Maillon(suivant(q),p);
    }
    suiv_Maillon(q,p);


    }


//////////////////////////////  LES FONCTION POUR CHANGER UN MAILLON PAR CHAMPS POUR LE TP ///////////////////////////////////

// Fonction pour creer un nouvel element
struct listebd *creemaillon (char *mot ) {
struct   listebd *p = malloc(sizeof(listebd)); // allouer un espace memoire
    char copymot [25] ;
    strcpy ( p->motSlash , mot ) ; // affectuer le mot slash
    strcpy ( copymot , mot ) ;
    SuppSlash( copymot ) ;
    strcpy(p->mot,copymot);   // le mot sans slash
    p->cara = NombCara(mot);  // on affectue le nombre de caractere
    p->cons = NombCons(mot) ;  // on affectue le nombre de consonne
    p->voy = NombVoy (mot) ;  // on affctue le nombre de voyelles
    p->syl = NombSyll(mot) ;  // on affectue le nombre de syllables
    if (OrdrAlph ( mot)==0){
    strcpy(p->ordr , "NO");  // on affectue si le mot en ordre alphabitique
    }
    else {
    strcpy(p->ordr ,"YES");
    }
    OrdMot ( copymot) ;
    strcpy(p->ordalph,copymot);  // on affectue le nombre d'alphabets
    p->prec= NULL;
    p->suiv = NULL;
    return p ;
}



////////////////////////////// LES FONCTION UTULISEE POUR LA CREATION DE LA STRECTURE DEMANDEE ///////////////////////////////


// la fonction qui precise le separateur dans un texte
int Separateur (char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}



// la fonction qui supprimes les salshs dans un mot
void SuppSlash ( char mot[] ) {
    int i , j ;
    // parcourt chaque caract�re du mot
    for(i = 0 , j = 0 ; i < strlen(mot) ; i++) {
        // si le caractere n'est pas un "/"
        if(mot[i] != '/') {
            // ajoute le caractere a la nouvelle chaine
            mot[j++] = mot[i];
        }
    }
 mot[j] = '\0';
    return mot ;
}


// la fonction qui renvoit un 0 si les deux mots donnes sont les memes
int compareChaines(char* chaine1, char* chaine2) {
    int i = 0;
    if (chaine1[0] != chaine2[0]) {
        while (tolower(chaine1[i]) == tolower(chaine2[i])) {
            if (tolower(chaine1[i]) == '\0' || tolower(chaine2[i]) == '\0')
                break;
            i++;
        }
        if (tolower(chaine1[i]) < tolower(chaine2[i]))
            return -1;
        else if (tolower(chaine1[i]) > tolower(chaine2[i]))
            return 1;
        else
            return 0;
    }
    else {
        if (strlen(chaine1) != strlen(chaine2)) {
            return strlen(chaine1) - strlen(chaine2);
        }
        else {
            while (tolower(chaine1[i]) == tolower(chaine2[i])) {
                if (tolower(chaine1[i]) == '\0' || tolower(chaine2[i]) == '\0')
                    break;
                i++;
            }
            if (tolower(chaine1[i]) < tolower(chaine2[i]))
                return -1;
            else if (tolower(chaine1[i]) > tolower(chaine2[i]))
                return 1;
            else
                return 0;
        }
    }
}



// la fonction qui trie un tableau donnee selon la taille des mots puis selon l'ordre alphabitique si ils ont la meme taille
void trier ( char* T [] , int nbMots )
{
    int i, j;
    char au[25];

    // trier selon la longueur des mots
    for(i = 0; i < nbMots - 1 ; i++)
    {
        for( j = 0 ; j < nbMots - i - 1 ; j++)
        {
            if(strlen(T[j]) > strlen(T[j+1]))
            {
                strcpy(au, T[j]);
                strcpy(T[j], T[j+1]);
                strcpy(T[j+1], au);
            }
        }
    }

    // trier selon l'ordre alphab�tique apres avoir les deux mots ont la meme taille
    for(i = 0; i < nbMots - 1; i++)
    {
        for(j = 0; j < nbMots - i - 1; j++)
        {
            if(strlen(T[j]) == strlen(T[j+1]) && strcmp(T[j], T[j+1]) > 0) // on verifie qui a la plus grande taille
            {
                strcpy( au, T[j]);
                strcpy(T[j], T[j+1]);
                strcpy(T[j+1], au);
            }
        }
    }
}

// la fonction qui calculer le nombre de caractere dans un mot donner et le mot en englais  :
int NombCara ( char m[] ) {
int i, count = 0;
 for (i = 0; m[i] != '\0'; i++) {
    // on fiat parcour le mot jusqu'on trouve un vide
        if (isalpha(m[i])) {
            count++; // chaque fois qu'on trouve une lettre albabet on incrimente le conteure
        }
    }
  return count ;
}



// la fonction qui calculer le nombre de consonnes dans un mot donner en englais :
int NombCons ( char m[] ) {
int i, count = 0;
 for (i = 0; m[i] != '\0'; i++) {
        if ( m[i] != 'A' && m[i] != 'O' && m[i] != 'E' &&m[i] != 'I' && m[i] != 'U' && m[i] != 'Y' && m[i] != 'a' && m[i] != 'o' && m[i] != 'e' &&m[i] != 'i' && m[i] != 'u' && m[i] != 'y' && m[i] != '\/'  ) {
                        count++ ;
        }
    }
  return count ;
}



// la fonction calculer le nombre de voyelles dans un mot donner en englais :
int NombVoy ( char m[] ) {
int i, c=0 ;
 for (i = 0; m[i] != '\0'; i++) {
        if ( m[i] == 'A' || m[i] == 'O' || m[i] == 'E' || m[i] == 'I' || m[i] == 'U' || m[i] == 'Y' || m[i] == 'a' || m[i] == 'o' || m[i] == 'e' || m[i] == 'i' || m[i] == 'u' || m[i] == 'y' ) {
                c++ ;

        }
    }
  return c ;
}



// la fonction qui calculer le nombre de syllables dans un mot en englais donnee ( le syllables sont seprees par ' / ' ) :
int NombSyll ( char m[] ) {
// le nombre de caractere dans le plus grand mot en englais est 45 car alphabet
int i, count = 1 ;
 for (i = 0; m[i] != '\0'; i++) {
    // on fiat parcour le mot jusqu'on trouve un vide
        if ( m[i]== '\/' ) {
            count++; // chaque fois qu'on trouve une lettre albabet on incrimente le conteure
        }
    }
  return count ;
}



// la fonction qui donne un boolean qui dit si un mot est dans l'ordre alphabitique ou non :
int OrdrAlph ( char m[] ) {
// on suppose qu'il est ordonnee et si on trouve qu'il n'est pas ordonnee on affecute au boolean faux
int i ;
int ordre = 1 ;
char s[25] ;
strcpy ( s , m ) ;
SuppSlash (s) ;
 for(i=1 ; i<strlen(s) ; i++)
   {
      if(s[i] < s[i-1])
      { // on trouve qu'il n'est pas ordonnee alphabitiquement
         ordre = 0 ;
         break;
      }

   }
   return ordre ;
}


// la fonction qui donne un nouveau mot triee selon l'ordre alphabitique des lettres a partir d'un autre mot :
void OrdMot ( char mot[] ) {
int n , i , j ;
char t ;
n = strlen(mot);

for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
        if (mot[i] > mot[j]) {
            t = mot[i];
            mot[i] = mot[j];
            mot[j] = t ;
        }
    }
}

return mot ;
}

// la fonction qui libere un tableau :
void freeTab ( char* T []  , int nbMots ) {
for ( int i=0 ; i<nbMots ; i++ ) {
    free (T[nbMots]) ;
}
}

// la fonction qui transforme tous le mot en miniscule
void toLowerCase(char str[]) {
    int i = 0;

    while(str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}


// un boolean qui dit si c'est une voyelle ou non
bool estVoyelle(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||c == 'y'  );
}


// la fonction qui cherche un mot , une fois il est trouve elle returne 1
int Chercher_Mot (struct listebd** tete[], char* mot ) {
 int trouve=0 ; // on initialise le trouve a 0
  for ( int i=0 ; i<26 ; i++ ) {
    listebd* p = tete[i];
    while ( p != NULL) {
        if (strcmp(p->mot,mot)==0 || strcmp(p->motSlash,mot)==0 ) {
                trouve=1 ; // si on le trouve on affcetue 1
        }
        p = suivant(p);
    }
}
 return trouve ;
}



// cree une sous liste qui contient les parties de mots separees par les "/" en renvoiyant la tete pour l'affectuer au champs de syllables de maillon
liste* create_list( char* mot , int n ) {
    liste* tete = NULL;
    liste* p = NULL;
    char word[strlen(mot)] ;
    strcpy ( word , mot ) ;
    char* t = strtok(word, "/");
    int i = 0;
    while (t != NULL && i < n) {
        liste* maillon = malloc(sizeof(liste)); // on alloue un espace memoire
        maillon->syll = strdup(t);  // on affectue les syllables
        maillon->suiv = NULL;
        if ( p == NULL) {
            tete = maillon ;
        } else {
            p->suiv = maillon ;
        }
        p = maillon ;
        t = strtok(NULL, "/");
        i++;
    }
    return tete ;  //on returne la tete de la liste des syllables
}




// la fonction qui cree pour les listes bidirectionnelles les sous listes de syllables
void CreeListeSyll ( struct listebd* tete[] ) {
    for (int i = 0 ; i < 26 ; i++) {
    listebd* p = tete[i] ;
  while (p != NULL) {
  p->syllable = create_list ( p->motSlash , p->syl ) ; // on cree une sous listepour chaque maillon
   p = p->suiv;
    }
    }
  }


  // la fonction qui remplit les 26 listtes bidirectionnelles et ses sous listes de syllables
void remplir_listes_bidirecitionnelles (   FILE* fichier , struct listebd* tete[]  ) {
   char mot[25]; // la taille maximal d'un mot donnee est 25
    char* MotsText [MAX_MOTS]; // un tableau qui a les mots de texte
    int nbMots = 0; // le nombre de mot
  int i, j ;

      // Initialisation de toutes les tetes a NULL
    for (i = 0; i < 26; i++) {
        tete[i] = NULL;
    }

   // lire chaque mot du fichier
    while(fscanf(fichier, "%s", mot) != EOF)  {  // il est defferent de la fin de fichier
        // retire les caract�res de ponctuation du mot
        for(i = 0, j = 0; i < strlen(mot); i++) {
            if(!Separateur(mot[i])) { // il est defferent d'un blanc ou une nouvelle ligne ou une tabulation
                mot[j++] = mot[i]; // on creer un nouveau mot a partir de premier mot q'uil est dans le fichier
            }
        }

        mot[j] = '\0';
        toLowerCase (mot) ;

        // ajoute le mot au tableau s'il n'y est pas d�j�
        for(i = 0; i < nbMots; i++) {
            if(strcmp(MotsText[i], mot) == 0) {
                break; // ce n'est pas un mot
            }
        }
        if(i == nbMots) {
            MotsText [nbMots] = (char*) malloc((strlen(mot)+1) * sizeof(char)); // on alloue a chaque fois dans notre tableau
            strcpy(MotsText[nbMots], mot); // on met dans la case allouee le mot
            nbMots++;
        }
    }

    trier ( MotsText , nbMots ) ; // on trie le tableau selon la taille puis si on trouve des mots ont la meme taille on ordonne selon l'ordre lphabitique

    // Parcours des mots et ajout � la liste appropri�e selon l'alphabet de debut
    for (i = nbMots-1 ; i >= 0 ; i--) {
        int indice = MotsText[i][0] - 'a'; // Indice de la t�te de liste correspondante
       struct  listebd *p = creemaillon (MotsText[i]);
        if (tete[indice] == NULL) {
            tete[indice] = p ;
        } else {
            p->suiv = tete[indice];
            tete[indice]->prec = p ;
            tete[indice] = p ;
        }
    }
CreeListeSyll ( tete ) ; // on cree les sous listes qui contient les syllables
freeTab ( MotsText , nbMots ) ; // on libere le tableau pour eveter la saturation de la memoire
}


//////////////////////// LES FONCTION UTULISEE POUR LA CREATION DES LIEN ENTRE LES MAILLONS PAR ORDRE DE QUESTION /////////////////////////


// une fonction qui dit si un mot2 est form� a partir d'un autre mot1 et return si oui un et si non 0
int MotForme (const char* m1 , const char* m2 ) {
    int l1 = strlen(m1);   // la taille de premier mot
    int l2 = strlen(m2);  //la taille de 2 eme mot
    if ( l1 <= l2 ) {
        char* t = (char*)malloc( l1 + 1);
        int i, j = 0, s = 0;
        for (i = 0; i < l2 ; i++) {
            if ( m2[i] == m1[j]) {
                t [j] = m2 [i]; // on compare les mots
                j++;
                if ( m2[i + 1] != m1[j] &&  i < l2 - 1 ) {
                        s++;} // si l'un plus grand que l'autre
            } else {
                if ( m2[i + 1] == m1[j] && i < l2 - 1 ) {
                        s++;} // si l'un est formee de l'autre
            }
        }
        t[j] = '\0';
        if (strcmp(t,m1)==0 && ((s<=1)||(s<=2 && m2[0]==m1[0]))){
            free(t);
            return 1;
        }
        free(t);
        return 0;
    }
    return 0;
}

//verifie si le mot se termine par ed et tourne 0 si non
int seTermineParED(char mot[]) {
    int longueur = strlen(mot);
    if (longueur < 2) {
        return 0;
    }
    else if (mot[longueur-2] == 'e' && mot[longueur-1] == 'd') {
        return 1; // on return 1 si le mot se termine pae ed
    }
    else {
        return 0;
    }
}


// la fonction qui cree le partiipe passe d'un mot en anglais en ajoutant ed selon les regles de grammaire
void ajouteEd(char mot[], int nbSyllabes)
{
    int n = strlen(mot);
// si le mot se termine par une voyelle y
    if (mot[n-1] == 'y' && !estVoyelle(mot[n-2])) {
        mot[n-1] = 'i';
        mot[n] = 'e';
        mot[n+1] = 'd';
        mot[n+2] = '\0';
    } else if (mot[n-1] == 'e') { // si le mot se termine par ed
        mot[n] = 'd';
        mot[n+1] = '\0';
    } else { // si le mot se termine par normale consonne
         mot[n] = 'e';
        mot[n+1] = 'd';
        mot[n+2] = '\0';
    } if (nbSyllabes == 1 && !estVoyelle(mot[n-1]) && estVoyelle(mot[n-2]) && !estVoyelle(mot[n-3]) && mot[n-1] != 'x' && mot[n-1] != 'w' ) {
        mot[n] = mot[n-1]; // si le mot la lettre avant dernier n'est pas une voyelle
        mot[n+1] = 'e';
        mot[n+2] = 'd';
        mot[n+3] = '\0';

    }
}

// verifie si un mot se termine par ing et tourne 0 si non
int seTermineParIng(char *mot) {
    int longueurMot = strlen(mot);
    int longueurIng = strlen("ing");
    if (longueurMot >= longueurIng) {
        char *finMot = mot + longueurMot - longueurIng;
        if (strcmp(finMot, "ing") == 0) {
            return 1; // return 1 si il termine par ing
        }
    }

    return 0;
}


// la fonction qui ajoute au mot ing selon les regles de grammaire d'anglais
void ajouteIng(char *word)
{
    int length = strlen(word);

    if (length >= 2 && word[length-2] == 'i' && word[length-1] == 'e')
    {
        // r�gle 1 : remplacer "ie" par "ying"
        word[length-2] = 'y';
         word[length-1] = '\0';
        strcat(word, "ing");
        return ;

    }
    if (length >= 2 && word[length-1] == 'e' && (word[length-2] != 'a' || word[length-2] != 'e' ||  word[length-2] != 'o' || word[length-2] != 'u'))
    {
        // r�gle 2 : supprimer "e" et ajouter "ing"
        word[length-1] = '\0';
        strcat(word, "ing");
        return ;
    }
    else if ( strcmp ( word , "play") !=0 && length >= 2 && word[length-1] != 'e' && !estVoyelle(word[length-1]) && estVoyelle(word[length-2]) && !estVoyelle(word[length-3])  )
    {
        // r�gle 3 : doubler la consonne finale et ajouter "ing"
        char lastChar = word[length-1];
        word[length] = lastChar;
        word[length+1] = '\0';
        strcat(word, "ing");
        return ;
    }
    else
    {
        // par d�faut, ajouter simplement "ing"
        strcat(word, "ing");
    }
}


// la fonction qui verifie si on a ajouter une lettre ou il ya une defference d'une nouvelle lettre
int Deff_Lettre (const char* m1, const char* m2) {
    return (MotForme(m1,m2) && strlen(m2)==strlen(m1)+1); // on compare les chaines
}


// une fonction qui dit sit deux mots ordonn�s sont proche lexicalement elle return 1 et si non elle return 0
int Proche_Lexicalement (char* m1 , char* m2) {
    if (strlen(m1) != strlen(m2)) {return 0;} // si ils sont une taille defferente donc evidament non proches
    int i,deff = 0;
    OrdrAlph(m1) ;
    OrdrAlph(m2) ;
    for (i = 0; i < strlen(m1) ; i++) {
        if ( m1[i] != m2[i] ) {
            deff++; // on trouve les lettres deffirentes
            if ( deff > 1) {return 0;} // si il y a plus d'une lettre sont defferent
        }
    }
    return deff == 1; // return 1 si il sont proche lexicalement
}


////////////////// LES FONCTION DE CREATION DES LIENS ET CHQUE FONCTION DE CREATION AVEC SON AFFICHAGE /////////////////


// la fonction qui cree les liens entre les maillon qui ont de mots formee a partir d'autres mots et au meme temps elle calcule le nombre de liens cree pour la derniere question de tp
int CreeMotsFormes ( struct listebd** tete[] ) {
    listebd* p = NULL; // pour la tete de chaque liste bidirecionelles
    listebd* q = NULL; // pour chaque maillon de la liste bidirectionnelle
    int i, j,cmpt = 0;
    for (i = 0; i < 26; i++) {
        p = tete[i]; // on initialise la tete a chaque fois
        while ( p != NULL) {
             p->MotsFormes = NULL; // on initialise le champ a nill
            for (j = 0; j < 26; j++) {
                q = tete[j];
                while ( q != NULL) {
                    if ( q == p ) {}
                    else if (MotForme(p->mot,q->mot)==1) {
                         if (p->MotsFormes == NULL || strlen(q->mot) < strlen(p->MotsFormes->mot)) { // on trouve si les mots sont formee l'un de l'autre
                            p->MotsFormes = q ;
                            cmpt++; // on compte le nombre de liens de mots formee
                        }
                    }
                    q = suivant(q);
                }
            }
            p = suivant(p);
        }
    }
    return cmpt; // on retourne le nombre des liens
}

// la fonction qui affiche les liens entre les maillon qui ont de mots formee a partir d'autres mots
void Afficher_Mots_Formes ( struct listebd** tete[] ) {
    int i;
    textcolor ( MAGENTA ) ;
     printf("\n_______________________ Words Formed From Other Words  : _______________________________\n");
     textcolor ( YELLOW ) ;
    for (i = 0 ; i < 26 ; i++) {
        listebd* p = tete[i] ;
        while (p != NULL) {
            if (p->MotsFormes == NULL) {
                p = suivant(p); // si il ne sont pas formee
                continue;
            }
            printf("\n-The words of this link are :  %s    %s   ",p->mot , p->MotsFormes->mot );
            listebd* q = p->MotsFormes->MotsFormes ;
            while ( q != NULL) {
                printf("  %s   ",q->mot);
                q = q->MotsFormes; // on passe vers le suivant de lien
            }
            printf("\n");
            p = suivant(p);
        }
    }
    printf("\n");
    textcolor( MAGENTA ) ;
         printf("\n__________________________________________________________________________________________\n");
    textcolor ( YELLOW ) ;
}


// la fonction qui cree les liens entre les maillon qui ont des verbes avec leur participe passe "ed" forme et au meme temps elle calcule le nombre de liens cree pour la derniere question de tp
int CreeED ( struct listebd** tete[]) {
    int i, cmpt = 0, trouve = 0;
    char m[25] ;
    for (i = 0; i < 26; i++) {
        listebd* p = tete[i]; // on initialise chaque tete pour le parcour
        while ( p != NULL) {
            listebd* q = tete[i] ;
            while ( q != NULL) {
                if (q == p ) {
                    q = suivant(q);
                    continue;
                }
                strcpy(m, p->mot) ; // on prend le mot est on ecrit sa form ed et puis on compare
                ajouteEd(m,p->syl) ;
                if (strcmp(q->mot,m ) == 0) {
                    p->ed = q ; // si ils ont la meme forme donc on cree un lien
                    trouve++;
                    break;
                }
                q = suivant(q);
            }
            if ( trouve == 0) {
                p->ed = NULL;
            }
            p = suivant(p);
            if (trouve>0) {
                cmpt++;
                trouve--;
            }
        }
    }
    return cmpt; // on retourne le nombre des liens crees
}

 // la fonction qui affiche les liens entre les maillon qui ont des verbes avec leur participe passe "ed" forme
void afficherED (struct listebd* tete[]) {
    int i , cpt=0;
    char pl[25] ;
    char ql[25] ;
    textcolor ( MAGENTA ) ;
    printf ( "\n_____________________________________________ The Words And Thier Past Participal : ______________________________________________\n") ;
    textcolor(YELLOW) ;
    // Parcourir chaque lettre de l'alphabet
    for (i = 0; i < 26; i++) {
        listebd* p = tete[i];
        // Parcourir la liste chaine de chaque lettre
        while (p != NULL) {
            // Verifier si le mot a des ed
            if (p->ed != NULL) {
                   strcpy ( pl , p->mot) ;
            if ( seTermineParED(pl)==0 ) {
                    cpt++ ;
                  printf("\n");
                textcolor ( BROWN ) ;
                printf(" - The Past Participel 'ED' form of the word < %s > is :  " , pl );
                textcolor(YELLOW) ;
                // Parcourir la liste ed
                listebd* q = p->ed;
                    printf("%s\n", q->mot );
            }
            }
            p = suivant(p);

        }
    }
    if ( cpt==0 ){
        textcolor(RED) ;
        printf ( "\nThere is no words with their Past Participel 'Ed' form in the file ! \n") ;
       textcolor(YELLOW) ;
    }
     printf ( "\n") ;
}


// la fonction qui cree les liens entre les maillon qui ont des verbes avec leur "ing" forme et au meme temps elle calcule le nombre de liens cree pour la derniere question de tp
int CreeING ( struct listebd** tete[]) {
    int i, cmpt = 0, trouve = 0;
    char m[25] ;
    for (i = 0; i < 26; i++) {
        listebd* p = tete[i]; // on parcours tous les listes
        while ( p != NULL) {
            listebd* q = tete[i] ;
            while ( q != NULL) {
                if (q == p ) {
                    q = suivant(q); // on parcour chaque maillon
                    continue;
                }
                strcpy(m, p->mot) ;
                ajouteIng(m) ; // on pend le mot et on ajoute ing forme et puis on compare
                if (strcmp(q->mot,m ) == 0) {
                    p->ing = q ; // si ils sont egaux donc on cree un lien
                    trouve++;
                    break;
                }
                q = suivant(q);
            }
            if ( trouve == 0) {
                p->ing = NULL;
            }
            p = suivant(p);
            if (trouve>0) {
                cmpt++;
                trouve--;
            }
        }
    }
    return cmpt; // on return le nombre de liens cree
}


 // la fonction qui affiche les liens entre les maillon qui ont des verbes avec leur  "ing" forme
void afficherING (struct listebd* tete[]) {
    int i , cpt=0;
    char pl[25] ;
    char ql[25] ;
    textcolor(MAGENTA) ;
    printf ( "\n________________________________________________ The Words And Thier'ING' Form : _________________________________________________\n") ;
    textcolor(YELLOW) ;
    // Parcourir chaque lettre de l'alphabet
    for (i = 0; i < 26; i++) {
        listebd* p = tete[i];
        // Parcourir la liste chainee de chaque lettre
        while (p != NULL) {
            // Verifier si le mot a des ing
            if (p->ing != NULL) {
                   strcpy ( pl , p->mot) ;
            if ( seTermineParIng(pl)==0 ) {
                    cpt++ ;
                  printf("\n");
                  textcolor (BROWN) ;
                printf(" - The ' ING ' form of the word < %s > is :  " , pl );
                textcolor(YELLOW) ;
                // Parcourir la liste ed
                listebd* q = p->ing;
                    printf("%s\n", q->mot );
            }
             }
            p = suivant(p);

        }
    }
    if ( cpt==0 ){
            textcolor(RED) ;
        printf ( "\nThere is no words with their 'ING' form in the file ! \n") ;
    textcolor (YELLOW) ;
    }
     printf ( "\n") ;
}

 // la fonction qui affiche les liens entre les maillon qui ont des verbes avec leur participe passe "ed" forme et leur 'ing" forme ( les deux existe dans le fichier )
void afficherEdIng (struct listebd* tete[]) {
    int i , cpt=0;
    char pl[25] ;
    char ql[25] ;
    textcolor(MAGENTA) ;
    printf ( "\n_______________________________ The Words And Thier'ING' And Past participel 'ED' Form Together: ________________________________\n") ;
    textcolor(YELLOW) ;
    // Parcourir chaque lettre de l'alphabet
    for (i = 0; i < 26; i++) {
        listebd* p = tete[i];
        // Parcourir la liste cha�n�e de chaque lettre
        while (p != NULL) {
            // V�rifier si le mot a des ed
            if (p->ing != NULL && p->ed != NULL ) {
                   strcpy ( pl , p->mot) ;
            if ( seTermineParIng(pl)==0 && seTermineParED(pl)==0 ) {
                    cpt++ ;
                  printf("\n");
                  textcolor(BROWN) ;
                printf(" - The word < %s > : " , pl );
                // Parcourir la liste ed
                listebd* q = p->ing;
                textcolor(YELLOW) ;
                    printf(" The 'ING' Form : %s | ", q->mot );
                    // Parcourir la liste ed
                    q = p->ed;
                    printf(" The Past Particpel 'ED' Form is : %s\n", q->mot );
            }
            }
            p = suivant(p);

        }
    }
    if ( cpt==0 ){
            textcolor(RED) ;
        printf ( "\nThere is no words with their 'ING' and Past participel 'ED' form in the same time in the file ! \n") ;
    textcolor(YELLOW) ;
    }
    textcolor(MAGENTA) ;
      printf ( "\n__________________________________________________________________________________________________________________________________\n") ;
 textcolor(YELLOW) ;
}


// la fonction qui cree les liens entre les maillon qui ont de mots formee a partir d'autres mots en ajoutant a chaque fois une lettre et au meme temps elle calcule le nombre de liens cree pour la derniere question
int CreeAjouteLettre ( struct listebd** tete[]) {
    listebd* p = NULL;
    listebd* q = NULL;
    int i, j, cmpt = 0;
    for (i = 0; i < 26; i++) {
        p = tete[i] ; // parcour les listes
        while ( p != NULL) {
            p->ajouteLettre = NULL;
            for (j = 0; j < 26; j++) {
                q = tete[j];
                while ( q != NULL) {
                    if (Deff_Lettre(p->mot, q->mot)) {
                        p->ajouteLettre = q ; // on compare le mots si on a ajouter une lettre
                        cmpt++;
                    }
                    q = suivant(q);
                }
            }
            p = suivant(p);
        }
    }
    for (i = 0; i < 26; i++) {
        p = tete[i];
        while ( p != NULL) {
            for (j = 0; j < 26; j++) {
                q = tete[j];
                while ( q != NULL) {
                    if (Deff_Lettre(p->mot, q->mot)) {
                        if (q->ajouteLettre!=NULL) {
                            p->ajouteLettre = q ; // si pn a ajouter on cree un lien
                        }
                        else {}
                    }
                    q = suivant(q);
                }
            }
            p = suivant(p);
        }
    }
    return cmpt; // on return le nombre de liens crees
}

// la fonction qui affiche les liens entre les maillon qui ont de mots formee a partir d'autres mots en ajoutant a chaque fois une lettre
void AfficherAjouteLettre ( struct listebd** tete[]) {
    int i;
    textcolor(MAGENTA) ;
    printf("\n-------------------------------------------- The Words Formed By Adding A Lettre Each Time : -------------------------------------------\n");
    textcolor(YELLOW) ;
    for (i = 0 ; i < 26 ; i++) {
        listebd* p = tete[i];
            while (p!=NULL) {
                if (p->ajouteLettre==NULL) {
                    p = suivant(p); // on parcour tous les listes et les maillons
                    continue;
                }
                textcolor(BROWN) ;
                printf("\n-The word < %s > : ",p->mot);
                textcolor(YELLOW) ;
                listebd* q = p->ajouteLettre;
                while ( q != NULL) {
                    printf("  %s  ",q->mot);
                    q = q->ajouteLettre ;
                }
                printf("\n");
                p = suivant(p);
        }
    }
    printf("\n");
    textcolor(MAGENTA) ;
    printf("\n---------------------------------------------------------------------------------------------------------------------------------------------\n");
    textcolor(YELLOW) ;
}


// la fonction qui cree les liens entre les maillon qui ont de mots proche lexicalement et calcule le nombre pour la dernier question
int CreeProchesLexicalement ( struct listebd** tete[] ) {
    listebd* p = NULL;
    listebd* q = NULL;
    int i, j,cmpt = 0 , l = 0 ;
    for (i = 0; i < 26; i++) {
        p = tete[i];
        while ( p != NULL) {
            p->ProcheLexica = NULL; // on inbitialise le champs a nill
            for (j = 0; j < 26; j++) {
                q = tete[j] ; // on parcour tous les listes
                while ( q != NULL) {
                    if ( q == p ) {l=1;}
                    else if (Proche_Lexicalement(p->mot,q->mot)==1 ) { // on compare les mots si sont proche lexicalement puis on cree un lien si oui
                        if ( l==1 && p->ProcheLexica == NULL) {
                            p->ProcheLexica = q ;
                            cmpt++;
                        }
                    }
                    q = suivant(q);
                }
            }
            p = suivant(p);
            l=0;
        }
    }
    return cmpt; // on return le nombre de liens crees
}

// la fonction qui affiche les liens entre les maillon qui ont de mots proche lexicalement
void Afficher_Proche_lexicalement ( struct listebd** tete[]) {
    int i;
    textcolor(MAGENTA) ;
    printf("\n_______________________ The Words Close Lexically : _______________________________\n");
    textcolor(YELLOW) ;
    for (i = 0 ; i < 26 ; i++) {
        listebd* p = tete[i] ;
        while (p!=NULL) {
            if (p->ProcheLexica==NULL) {
                p = suivant(p);
                continue;
            }
            printf("\n - The words <  %s  >  ",p->mot);
            listebd* q = p->ProcheLexica ;
            while ( q != NULL && q->ProcheLexica != p->ProcheLexica ) {
                printf(", < %s  >  ",q->mot) ;
                q = q->ProcheLexica;
            }
            printf ( " are lexically close . \n") ;
            p = suivant(p);
        }
    }
    textcolor(MAGENTA) ;
    printf("\n____________________________________________________________________________________\n");
    textcolor(YELLOW) ;
}


// la fonction qui cree les liens entre les maillon qui ont de mots annagrames et calcule le nombre pour la dernier question
int CreeAnagramme (struct listebd** tete[]) {
    listebd* p = NULL;
    listebd* q = NULL;
    int i, j,cmpt = 0,m = 0;
    for (i = 0; i < 26; i++) {
        p = tete[i]; // on parcour les listes
        while (p != NULL) {
            p->anagramme = NULL; // on initialise les champs a nill
            for (j = 0; j < 26; j++) {
                q = tete[i] ;
                while (q != NULL) {
                    if (q == p) {m=1;} // on parcour chaque maillon
                    else if ((strcmp(p->mot,q->mot)!=0)&&(strcmp(p->ordalph,q->ordalph)==0)) { // on compare l'ordre alphabitique si le meme
                        if (m==1 && p->anagramme == NULL) {
                            p->anagramme= q ; // si oui on cree un lien
                            cmpt++;
                        }
                    }
                    q = suivant(q);
                }
            }
            p = suivant(p);
            m = 0;
        }
    }
    return cmpt; // on return le nombre de liens crees
}

// la fonction qui affiche les liens entre les maillon qui ont de mots proche lexicalement
void Afficher_Anagramme(struct listebd** tete[] ) {
    int i;
    textcolor(MAGENTA) ;
     printf("\n_______________________ The Anagrams  : _______________________________\n");
     textcolor(YELLOW) ;
    for (i = 0 ; i < 26 ; i++) {
        listebd* p = tete[i];
        while (p!=NULL) {
            if (p->anagramme==NULL) {
                p = suivant(p); // on parcour tous les maillon pour trouver le champs defferent de nill
                continue;
            }
            printf("\n - The anagrams of this link are : %s  ",p->mot);
            listebd* q = p->anagramme;
            while (q != NULL && q->anagramme != p->anagramme ) {
                printf(" and  %s   ",q->mot);
                q = q->anagramme;
            }

            printf("\n");
            p = suivant(p);
        }
    }
    textcolor(MAGENTA) ;
   printf("\n_______________________________________________________________________\n");
   textcolor(YELLOW) ;
}


///////////////////////////////////// LES FONCTION UTULISEE POUR LES AUTRES CHOIX DANS LE MENU //////////////////////////////


// la fonction qui cherche un mot , une fois il est trouve elle returne tous ces caractheristiques
void ChercherAfficher_Mot (struct listebd** tete[], char* mot ) {
  for ( int i=0 ; i<26 ; i++ ) {
  struct  listebd* p = tete[i]; // pour parcourir toutes les listes
    while ( p != NULL) {
        if (strcmp(p->mot,mot)==0 || strcmp(p->motSlash,mot)==0 ) { // on compare si le meme mot
                textcolor ( BROWN ) ;
                printf("\nThe word : %s ", p->mot ) ;
                textcolor(YELLOW) ;
                printf ( "\nNumber of Caracters : %d \nNumber Of Consons : %d \nNumber of Voyelles : %d \nNumber of Syllables : %d \nIs it in Order : %s \nThe Order : %s \nThe Syllables :  " ,  p->cara , p->cons , p->voy , p->syl , p->ordr , p->ordalph ) ;
                struct liste* liste = p->syllable  ;
                while ( liste != NULL) {
                printf("%s  -   ", liste->syll);
                liste = liste->suiv ;
    }

                break ;
        }
        p = suivant(p);
    }
}
}



    // la fonction qui supprime un mot dans les listes
void ChercherEtSupprimer( struct listebd* tete[] , char* mot) {
    int i  , c=0 ;
 for ( i=0 ; i<26 ; i++ ) {
    deleteMaillonByValue ( &tete[i] , mot ) ; // on supprime le maillon une fois il est trouve
    }
}


// la fonction qui donne le nombre de tous les mots
int Number_Mot (struct listebd** tete[] ) {
    int cpt =0 ;
  for ( int i=0 ; i<26 ; i++ ) {
  struct  listebd* p = tete[i];
    while ( p != NULL) {
        cpt++ ; // on parcour tous les listes et on incrimente chaque fois quand trouve un mot
        p = suivant(p);
    }
}
return cpt ; // on retourne le nombre totale
}

//la fonction qui calcule la taille d'une liste :
int taille_Liste ( listebd* tete ) {
    int size = 0;
    while ( tete != NULL) {
        size++; // on incrimente la taille chaque fois defferent de nill
        tete = tete->suiv ;
    }

    return size; // on donne la taille de la liste
}

// la fonction qui donne la taille de tous les tailles des listes et les classe dans un tableau :
void Taille_26Listes ( int tab_liste[] , struct listebd* tete[] ) {
for ( int i=0 ; i<26 ; i++ ) {
    tab_liste[i] = taille_Liste ( tete[i] ) ; // on affectue chaque taiile dans l'indice preciser
    }
}


// la fonction qui calcule le nombre de mots qui on leurs forme ed et ing au meme temps dans le fihcier
int NumberEdIng (struct listebd* tete[]) {
    int i , cpt=0;
    char pl[25] ;
    char ql[25] ;
    // Parcourir chaque lettre de l'alphabet
    for (i = 0; i < 26; i++) {
        listebd* p = tete[i];
        // Parcourir la liste chainee de chaque lettre
        while (p != NULL) {
            // Verifier si le mot a des ed et ing
            if (p->ing != NULL && p->ed != NULL ) {
                   strcpy ( pl , p->mot) ;
            if ( seTermineParIng(pl)==0 && seTermineParED(pl)==0 ) {
                    cpt++ ;
                // Parcourir la liste ing
                listebd* q = p->ing;
                    // Parcourir la liste ed
                    q = p->ed;
            }
            }
            p = suivant(p);

        }
    }
return cpt ; // on retunr le nombre de lien cree
}


// la fonction on lui donne la lettre elle nous donne la taille de la liste de cette lettre
int tailleListeDelettre (int *tab_liste[] , char lettre ) {
    int taille =0 ;
  taille = tab_liste[lettre - 'a' ] ;
  return taille ;
}


/////////////////////////// LES FONCTIONS POUR L'AFFICHAGE DES LISTES DE SYLLABLLES ET SOUS LISTES ///////////////////////

// la fonction qui affiche les listes selon l'ordre alphabitique avec tous les caracteristiques des mots
void AFficher_26listes ( struct listebd* tete[] ) {
    int i ;
    textbackground(MAGENTA) ;
printf("\n---------------------------------------------   ALL THE LISTS   ------------------------------------------------------------------------------\n");
     textbackground (BLACK) ;
for (i = 0 ; i < 26 ; i++) {
    textcolor (BROWN) ;
    printf("\n--------------------------------------------- LIST FOR THE LETTRE [ %c ] : -----------------------------------------------------", 'a' + i);
    textcolor ( WHITE ) ;
struct        listebd *p = tete[i];
if ( p == NULL) {

            printf ( "\n the list is empety \n") ;
        }
        printf("\n");

        while ( p != NULL) {
          printf("\nword : %s | Cara : %d | Cons : %d | Voy : %d | Syll : %d |is it in order : %s | Order : %s | Syllables :  ", p->mot , p->cara , p->cons , p->voy , p->syl , p->ordr , p->ordalph );

    struct liste* liste = p->syllable  ;
    while ( liste != NULL) {
        printf("%s  -   ", liste->syll);
        liste = liste->suiv ;
    }
        printf("\n");
        printf("\n");
        p = p->suiv;
        }
    }
 printf ("\n ") ;
 textbackground ( MAGENTA ) ;
 printf("---------------------------------------------------------------------------------------------------------------------------------------------");
 textbackground ( BLACK ) ;
 textcolor(YELLOW) ;
 printf ("\n");
}

// la fonction qui affiche les listes selon l'ordre alphabitique mais sans les details juste les mots
void AFficher_26listes_Sans_Details ( struct listebd* tete[] ) {
    int i ;
    textbackground(MAGENTA) ;
printf("\n---------------------------------------------   ALL THE LISTS   ------------------------------------------------------------------------------\n");
    textbackground(BLACK) ;
for (i = 0 ; i < 26 ; i++) {
        textcolor(WHITE) ;
        printf("\n- LIST FOR THE LETTRE [ %c ] :", 'a' + i);
struct        listebd *p = tete[i];
if ( p == NULL) {
            printf ( " !! The Liste Is Empety !! ") ;
        }

        while ( p != NULL) {

          printf(" %s |", p->mot  );

        p = p->suiv;
        }
           printf("\n");
    }
    printf ("\n") ;
textbackground(MAGENTA) ;
 printf("---------------------------------------------------------------------------------------------------------------------------------------------");
textbackground(BLACK) ;
printf("\n") ;
textcolor(YELLOW) ;
}


// la fonction qui donne les tailles de tous les listes  :
void Affiche_listes_tailles (int tab_liste[] ) {
 for ( int i=0 ; i<26 ; i++ ) {
   printf("\n The lenghth of the list for the lettre [ %c ] is :     %d ", 'a' + i , tab_liste[i]);
    }
}


void contor() // Une procédure pour dessiner un contour sur l'écran avec le nom de l'ESI au coin .
{
    int i;
    gotoxy(2,2);
    printf("%c",201);
    for(i=3;i<120;i++)
    {
        gotoxy(i,2);
        printf("%c",205);
        gotoxy(i,30);
        printf("%c",205);

    }
    gotoxy(120,2);
    printf("%c",187);

    for(i=3;i<30;i++)
    {
        gotoxy(2,i);
        printf("%c",186);
        gotoxy(120,i);
        printf("%c",186);
    }
    gotoxy(2,30);
    printf("%c",200);

    gotoxy(120,30);
    printf("%c",188);
    gotoxy(109,3);
    printf("%c%c%c %c%c%c %c",201,205,187,201,205,187,203);
    gotoxy(109,4);
    printf("%c%c%c %c%c%C %c",204,205,188,200,205,187,186);
    gotoxy(109,5);
    printf("%c%c%c %c%c%c %c",200,205,205,200,205,188,202);
}


////////////////////////////////////////////// LA FIN DES MODULES ////////////////////////////////////////////
