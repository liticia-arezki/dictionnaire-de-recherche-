
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "bibliotheque.c"
#include "conio.c"



int main() {
    char NomFichier[10]  ;
    char m[25] , c ; // le mot pour l'insertion
    FILE* fichier ; // le fichier
    struct listebd *tete[26] ; // Tableau de 26 t�tes de listes
    int i , ip=0 , ed , eding , ing , anagram , prlx , prMotsuf , ping , choix ,choix2 , nb_Mots=0 , im=0 , option1=1 ;
    int tab_liste[26] ;
    char *ch ;
    textcolor(YELLOW) ;
    printf ( "\t") ;
    textbackground(WHITE) ;
    textcolor(BLUE) ;
    printf (" THIS CODE INSERTS A FILE OF YOUR CHOICE , THEN PROCESSES IT TO CREAT A DICTIONARY OF ENGLISH WORDS .\n\t\tTO USE THIS DECTIONARY YOU ONLY HAVE TO SELECT ANY SEGGESTION IN THE MENU .") ;
    textcolor (YELLOW) ;
    textbackground(BLACK);
                         // acceder vers le fichier :
     printf("\n\n Enter the name of the file  : ");
     scanf("%s", NomFichier); // lire le nom de fichier
     fichier = fopen(NomFichier, "r"); //ouvrir le fichier
     if(fichier == NULL) {
        printf(" !! Erreur : The file doesn't exist !!\n"); // le fichier n'existe pas
        return 1 ;
    }


    // remplir la strecture avec la creation des liens :
        remplir_listes_bidirecitionnelles ( fichier , tete  )  ;
        prMotsuf = CreeMotsFormes(&tete) ;
        CreeED(&tete);
        CreeING(&tete);
        CreeAjouteLettre(&tete);
        CreeProchesLexicalement(&tete) ;
        CreeAnagramme ( &tete ) ;
        clrscr () ;
                                          // le menu :
          printf("\n To go to the Menu press OK key  ") ;
          getchar();
          getchar();
          menu :
 while (1){
     do{
        gotoxy(20,7);
        textbackground(BLUE);
        printf("____________________________________ MENU ______________________________________");
        textbackground(BLACK);
        gotoxy(20 ,9);
        printf("      Show the results of forming lists without the characteristics of words    ");
        gotoxy(20,10);
        printf("     Show the results of forming lists with all the characteristics of words    ");
        gotoxy(20,11);
        printf("         Show the results of searching a word with its characteristics           ");
        gotoxy(20,12);
        printf("               Show the results of words formed from other words                ");
        gotoxy(20,13);
        printf("      Search results of verbs , thier 'ED' past participal , and 'ING' forms    ");
        gotoxy(20,14);
        printf("Show the results of words formed from other words by adding one letter each time");
        gotoxy(20,15);
        printf("                Show search results of words lexically close                    ");
        gotoxy(20,16);
        printf("                        Show search results of Anagrams                         ");
        gotoxy(20,17);
        printf("                        Insert a new word in the lists                          ");
        gotoxy(20,18);
        printf("                          Delete a word in the list                             ");
        gotoxy(20,19);
        printf("                 Show the statistics lists and existing words                   ");
        gotoxy(20,20);
        printf("            Show the statistics the number of words in all the lists            ");
        gotoxy(20,21);
        printf("                              Leave the program                                 ");
                switch(option1)
                {
                    case 1 :
                        gotoxy(20,9);
                        textbackground(MAGENTA);
                        printf("      Show the results of forming lists without the characteristics of words    ");
                        textbackground(BLACK);
                        textcolor(15);
                        break;
                    case 2 :
                        gotoxy(20,10);
                        textbackground(MAGENTA);
                        printf("     Show the results of forming lists with all the characteristics of words    ");
                        textbackground(BLACK);
                        textcolor(15);
                        break;

                    case 3 :
                        gotoxy(20,11);
                        textbackground(MAGENTA);
                        printf("         Show the results of searching a word with its characteristics           ");
                        textbackground(BLACK);
                        textcolor(15);
                        break;
                    case 4  :
                        gotoxy(20,12);
                        textbackground(MAGENTA);
                        printf("               Show the results of words formed from other words                ");
                        textbackground(BLACK);
                        textcolor(15);
                    break ;
                    case 5  :
                        gotoxy(20,13);
                        textbackground(MAGENTA);
                        printf("      Search results of verbs , thier 'ED' past participal , and 'ING' forms    ");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;
                    case 6 :
                        gotoxy(20,14);
                        textbackground(MAGENTA);
                        printf("Show the results of words formed from other words by adding one letter each time");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;
                    case 7 :
                        gotoxy(20,15);
                        textbackground(MAGENTA);
                        printf("                Show search results of words lexically close                    ");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;
                    case 8 :
                        gotoxy(20,16);
                        textbackground(MAGENTA);
                        printf("                        Show search results of Anagrams                         ");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;
                    case 9 :
                        gotoxy(20,17);
                        textbackground(MAGENTA);
                        printf("                        Insert a new word in the lists                          ");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;
                    case 10 :
                      gotoxy(20,18);
                      textbackground(MAGENTA);
                      printf("                          Delete a word in the list                             ");
                      textbackground(BLACK);
                      textcolor(15);
                     break ;
                    case 11 :
                        gotoxy(20,19);
                        textbackground(MAGENTA);
                        printf("                 Show the statistics lists and existing words                   ");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;
                    case 12 :
                        gotoxy(20,20);
                        textbackground(MAGENTA);
                        printf("            Show the statistics the number of words in all the lists            ");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;
                    case 13 :
                        gotoxy(20,21);
                        textbackground(MAGENTA);
                        printf("                              Leave the program                                 ");
                        textbackground(BLACK);
                        textcolor(15);
                     break ;

                }

                ch = getch();
                if(ch==72)
                {
                    (option1)--;
                    if(option1 == 0)
                    option1 = 13 ;
                }
                else if(ch==80)
                {
                    (option1)++;
                    if(option1==14)
                    option1 = 1 ;
                }
         textcolor(YELLOW) ;

            } while ( ch != 13 );
        clrscr ();
        printf("\n");
        switch (option1) {
        case 1 :
             textbackground(BLUE) ;
             printf("\nThe results of forming lists without the characteristics of words : \n") ;
             textbackground(BLACK) ;
             AFficher_26listes_Sans_Details ( tete ) ;
             printf("\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
            break ;
        case 2 :
             textbackground(BLUE) ;
             printf("\nThe results of forming lists with all the characteristics of words : \n");
             textbackground(BLACK) ;
             AFficher_26listes ( tete ) ;
             printf("\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
             break ;
        case 3 :
            textbackground(BLUE) ;
             printf("\nThe results of searchin a word with its characteristics : \n");
            textbackground(BLACK) ;
             printf ( "\nGive us a word you want to search for its characteristics : ") ;
             scanf ( "%s" , &m ) ;
            if ( Chercher_Mot( tete , m )==0 ){
                textcolor(RED) ;
                printf ( "\nthis word doesn't exist please select another one ! \n") ;
                textcolor(YELLOW) ;
                printf("\n")  ;
             } else {
             ChercherAfficher_Mot(tete,m) ;
             }
              printf("\n")  ;
              printf("\n To return to the Menu press OK key  ") ;
              getchar() ;
              getchar () ;
              clrscr () ;
             goto menu ;
             break ;
        case 4 :
             textbackground(BLUE) ;
             printf("\nThe results of words formed from other words : \n");
             textbackground(BLACK) ;
             Afficher_Mots_Formes ( tete ) ;
             printf("\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
             break ;
        case 5 :
             textbackground(BLUE) ;
             printf("\nShow search results of verbs , thier 'ED' past participal , and 'ING' forms \n");
             textbackground(BLACK) ;
             afficherED(tete) ;
             afficherING(tete) ;
             afficherEdIng(tete) ;
             printf("\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
             break ;
        case 6 :
             textbackground(BLUE) ;
             printf("\nShow the results of words formed from other words by adding one letter each time : \n");
             textbackground(BLACK) ;
             AfficherAjouteLettre(tete) ;
             printf("\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
             break ;
        case 7 :
             textbackground(BLUE) ;
             printf("\nShow search results of words lexically close  : \n");
             textbackground(BLACK) ;
             Afficher_Proche_lexicalement (tete) ;
             printf("\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
             break ;
        case 8 :
             textbackground(BLUE) ;
             printf("\nShow search results of Anagrams : \n");
             textbackground(BLACK) ;
             Afficher_Anagramme  ( tete ) ;
             printf("\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
             break ;
        case 9 :
             textbackground(BLUE) ;
             printf("\nInsert a new word in the lists :\n");
             textbackground(BLACK) ;
             printf ( "\nGive us the word you want to insert ( please make sure that you seperated sylla by / ) : ") ;
             scanf ( "%s" , &m ) ;
            if ( Chercher_Mot( tete , m )==1 ){
                textcolor(RED) ;
                printf ( "\nthis word already exist in the lists please select another one ! \n") ;
                textcolor(YELLOW) ;
                printf("\n")  ;
             } else {
             insererMot(&tete,m) ;
             printf ("\n Do you want to show the result lists with characteristics    : press number 1 ") ;
             printf ("\n Do you want to show the result lists without characteristics : press number 2 ") ;
             printf  ( "\n Your choice : " ) ;
             scanf ( "%d" , &choix2) ;
             if( choix2 != 1 ) {
                if ( choix2 != 2 ) {
                    textcolor(RED) ;
                    printf ( "\n There is no choice with the selected number !! " ) ;
                    textcolor(YELLOW) ;
             }
             }
             if ( choix2==1 ) { AFficher_26listes(tete) ;}
             if ( choix2==2 ) { AFficher_26listes_Sans_Details(tete) ;}
             }
              printf("\n")  ;
              printf("\n To return to the Menu press OK key  ") ;
              getchar() ;
              getchar () ;
              clrscr () ;
             goto menu ;
             break ;
        case 10 :
             textbackground(BLUE) ;
             printf("\nDelete a word in the list  : \n");
             textbackground(BLACK) ;
             printf ( "\nGive us the word you want to delet : ") ;
             scanf ( "%s" , &m ) ;
            if ( Chercher_Mot( tete , m )==0 ){
               textcolor(RED) ;
                printf ( "\nthis word doesn't exist please select another one ! \n") ;
               textcolor(YELLOW) ;
                printf("\n")  ;
             } else {
              ChercherEtSupprimer ( tete , m ) ;
             printf ("\n Do you want to show the result lists with characteristics    : press number 1 ") ;
             printf ("\n Do you want to show the result lists without characteristics : press number 2 ") ;
             printf  ( "\n Your choice : " ) ;
             scanf ( "%d" , &choix2) ;
             if( choix2 != 1 ) {
                if ( choix2 != 2 ) {
                    textcolor(RED) ;
                    printf ( "\n There is no choice with the selected number !! " ) ;
                    textcolor(YELLOW) ;
             }
             }
             if ( choix2==1 ) { AFficher_26listes(tete) ;}
             if ( choix2==2 ) { AFficher_26listes_Sans_Details(tete) ;}
             }
              printf("\n")  ;
                printf("\n To return to the Menu press OK key  ") ;
                getchar() ;
                getchar () ;
                clrscr () ;
             goto menu ;
             break ;
        case 11 :
              textbackground(BLUE) ;
              printf("\nShow the statistics lists and words : \n");
              textbackground(BLACK) ;
              prMotsuf = CreeMotsFormes(&tete) ;
              ed = CreeED(&tete);
              ing = CreeING(&tete);
              ping = CreeAjouteLettre(&tete);
              prlx = CreeProchesLexicalement(&tete) ;
              anagram = CreeAnagramme ( &tete ) ;
              eding = NumberEdIng(tete) ;
              nb_Mots = Number_Mot(tete) ;
              textcolor(GREEN) ;
              printf("\nNumber of the words in the lists                                                : %d \n" , nb_Mots );
              printf("\nNumber of  words formed from other words links                                  : %d\n",prMotsuf);
              printf("\nNumber of  verbs with thiers 'ed' links alone  is                               : %d\n" , ed );
              printf("\nNumber of  verbs with thiers 'ing' links alone  is                              : %d \n",ing);
              printf("\nNumber of  links of verbs with theirs 'ed' and 'ing' form both int the file     : %d\n",eding);
              printf("\nNumber of  words formed from other words by adding one letter each time links   : %d\n",ping);
              printf("\nNumber of close lexically links                                                 : %d\n",prlx);
              printf("\nNumber of anagram links                                                         : %d\n",anagram);
              textcolor(YELLOW) ;
              printf("\n")  ;
              printf("\n")  ;
              printf("\n To return to the Menu press OK key  ") ;
              getchar() ;
              clrscr () ;
             goto menu ;
              break ;
        case 12 :
            Taille_26Listes ( tab_liste , tete ) ;
            textbackground(BLUE) ;
            printf ( "\n The number of words in each liste is : \n") ;
            textbackground(BLACK) ;
            textcolor(GREEN) ;
            Affiche_listes_tailles ( tab_liste ) ;
            textcolor(YELLOW) ;
            printf("\n\n")  ;
             printf("\n To return to the Menu press OK key  ") ;
             getchar() ;
             clrscr () ;
             goto menu ;
            break ;
        case 13 :
             printf("\n");
             textcolor(MAGENTA);
             printf("\n\t\t                THE END OF THE PROGRAM \n");
             printf("\n\t\t                      THANK YOU !! \n");
             textcolor(WHITE) ;
             return 0;
        }
    }

    freeListes ( tete ) ;
    fclose(fichier);

    return 0;
}





/* le principe de la realisation :

 Lire un fichier en donnant son nom , puis on parcour le fichie en classe ses mots dans un tableau
 on ttrie ce tableau selon la taille puis l'ordre alphabitique des lettres de mot
 on crie un tableau qui a 26 tete vers listes bicirectionnelle puis on parcour le tableau et en classe chaque mot dans sa liste
 on cree les listes de syllabes au meme temps
 on libere le tableau
 on cree les liens donnees par le parcour des listes et a chaque fois selon la carctirestique donnee on cree des champs qui ont des liens puis on affectue les liens entre eux
 ces fonction qui cree les liens sont au meme temps la pour calculer le nombre de liens cree pour l'affichage de nombre des sous listes
 on insert le mot par la creation d'un nouveau maillon puis on cherche sa position dans la liste et on le classe
 pour la supression on cherche le mot et on supprime son maillon
 pour le nombre des mots stockee on a cree un tableau qui classe le nombre des mot dans chaque listes pui on calcule la somme et on donne le nombre complete
 et on peut afficher aussi la taille de chaque liste comme un choix dans le menu
 on donne le menu et on laisse l'utulisateur choisir
 une foix l'execution est fini : on libere tous les listes qu'on a cree et on ferme le fichier .*/
