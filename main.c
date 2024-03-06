#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include<unistd.h>
#define N 4

/* initialisation du plateau*/
void intialisation_du_plateau_a_0(int plateau[N][N])
{
    int i,j;

    for (i=0;i<N;i++)
    {
        printf("\n");
        for(j=0;j<N;j++)
        {
            plateau[i][j]=0;
        }
    }
}
void affichage(int plateau[N][N])
{

        int i,j;
        for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%6d",plateau[i][j]);
        }

        printf("\n");
        printf("\n");
    }

}
    /* fonction qui va nous aider aremplir notre tableau aleatoirement */
void alea(int plateau[N][N])
{
        int i, j;
    do {
        i = rand()%N;
        j = rand()%N;
       } while (plateau[i][j] != 0);
    plateau[i][j] =  2;
}
/* fonction qui va nous aide a deplace le plateau vers la gauche*/
void deplacement_gauche(int plateau[N][N],int*t)
{
    int i,j,k;

        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                for(k=1;k<N;k++)
                {
                    if((plateau[i][k-1]==0)&&(plateau[i][k]!=0))
                {
                    plateau[i][k-1]=plateau[i][k];
                    plateau[i][k]=0;
                    *t=1;
                }

                }

            }
        }
}
/* fonction qui va nous aide a deplace le plateau vers la droite*/
void deplacement_droite(int plateau[N][N],int*t)
{
    int i,j,k;
     for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                for(k=1;k<N;k++)
                {
                    if((plateau[i][k-1]!=0)&&(plateau[i][k]==0))
                {
                    plateau[i][k]=plateau[i][k-1];
                    plateau[i][k-1]=0;
                    *t=1;
                }
                }
            }
        }
}
/* fonction qui va nous aide a deplace le plateau vers le haut*/
void deplacement_haut(int plateau[N][N],int*t)
{
    int i,j,k,c;
    for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                for(k=1;k<N;k++)
                {
                    if((plateau[k-1][i]==0)&&(plateau[k][i]!=0))
                {
                    plateau[k-1][i]=plateau[k][i];
                    plateau[k][i]=0;
                    *t=1;
                }

                }
            }
        }
}
/* fonction qui va nous aide a deplace le plateau vers le bas*/
void deplacement_bas(int plateau[N][N],int *t)
{
    int i,j,k;
    for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                for(k=1;k<N;k++)
                {
                    if((plateau[k][i]==0)&&(plateau[k-1][i]!=0))
                {
                    plateau[k][i]=plateau[k-1][i];
                    plateau[k-1][i]=0;
                    *t=1;
                }

                }
            }
        }
}
/* fonction qui va nous aidé à faire la somme des valeures du plateau
vers la gauche lorsque celui ci sera déplacé */
void somme_gauche(int plateau[N][N],int*score)
{
    int i,j,c;

    for(i=0;i<N;i++)
        {
                   for(j=1;j<N;j++)
                   {
                       if(plateau[i][j-1]==plateau[i][j])
                       {
                        plateau[i][j-1]=plateau[i][j-1]*2;
                        c= plateau[i][j-1];
                        *score=*score+c;
                        plateau[i][j]=0;
                       }
                   }

        }
}
/* fonction qui va nous aidé à faire la somme des valeures du plateau
vers la droite lorsque celui ci sera déplacé */
void somme_droite(int plateau[N][N],int *score)
{
    int i,j,c;

     for(i=0;i<N;i++)
        {
            for(j=1;j<N;j++)
            {
               if(plateau[i][N-j]==plateau[i][N-j-1])
               {
                   plateau[i][N-j]=plateau[i][N-j]*2;
                   c=plateau[i][N-j];
                   plateau[i][N-j-1]=0;
                   *score=*score+c;
               }
            }
        }
}
/* fonction qui va nous aidé à faire la somme des valeures du plateau
vers le haut lorsque celui ci sera déplacé */
void somme_haut(int plateau[N][N],int *score)
{
    int i,j,c;
     for(i=0;i<N;i++)
        {
            for(j=1;j<N;j++)
            {
                if(plateau[j-1][i]==plateau[j][i])
                {
                    plateau[j][i]=plateau[j][i]*2;
                    c=plateau[j][i];
                    plateau[j-1][i]=0;
                    *score+=c;
                }
            }
        }
}
/* fonction qui va nous aidé à faire la somme des valeures du plateau
vers le haut lorsque celui ci sera déplacé */
void somme_bas(int plateau[N][N],int *score)
{
    int i,j,c;
     for(i=0;i<N;i++)
     {
         for(j=1;j<N;j++)
         {
             if(plateau[N-j-1][i]==plateau[N-j][i])
             {
                 plateau[N-j][i]=plateau[N-j][i]*2;
                 c= plateau[N-j][i];
                 plateau[N-j-1][i]=0;
                 *score+=c;
             }
         }
     }
}
/*fonction qui permet de vérifier si un joueur a gagné*/
int winner(int plateau[N][N])
{
    int i,j,n;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(plateau[i][j]==2048)
                //si un joueur réussi à atteindre 2048; alors il gagne le jeu
            {
                n=1;
            }
        }
    }return(n);
}
/*fonction qui permet de vérifier si un joueur a perdu*/
int you_lose(int plateau[N][N])
{
    int i,j,k;
    /* vérifions si il y'a pas de case vide */
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(plateau[i][j]==0)
            {
                return 0;
                /* si il y'a une case vide; le jouer n'a pas perdu*/
            }
        }
    }
    /* fonction qui nous aide à vérifié si deux cases sont adjacentes */
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(plateau[i][j]==plateau[i][j+1])
            {
                return 0;
                /*si deux cases sont adjacentes et ont la meme valeur alors le joueur n'a pas perdu */
            }
        }
    }
    /* fonction qui nous aide à vérifié si deux cases sont adjacentes */
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(plateau[i][j]==plateau[i+1][j+1])
            {
                return 0;
                /*si deux cases sont adjacentes et ont la meme valeur alors le joueur n'a pas perdu */
            }
        }
    }
    return 1;
    /* si la fonction ne retourne pas 0 qlors le joueur aura perdu*/
}

main()
{
    srand(time(NULL));
    int plateau[N][N];
    int n,m,t,M=0,score=0;
    int *p;
    intialisation_du_plateau_a_0( plateau);
    alea(plateau);
    alea(plateau);
    /* après avoir initialisé un plateau ne contenant que des zéros on génère le chiffre 2 à deux positions quelconques */
    printf("\t\tBONJOUR MONSIEUR/MADAME SOYEZ LE(LA) BIEN VENU(E)\n \t \t APPUYER SUR 0 POUR AFFICHER L'AIDE \n\t\t APPUYER SUR 1 POUR QUITTER\n\t\t SINON APPUYER SUR LES TOUCHES DE DIRECTION POUR VOUS MOUVOIR SELON LA DIRECTION CHOISIE \n\t\t\t\tBONNE CHANCE\n ");

    printf("\n");
    affichage( plateau);
    do
    {
        n=getch();
        system("cls");
        printf("\n");
        printf("appuyer sur 0 pour afficher l'aide\n");
        printf("appuyer sur 1 pour quitter");
        printf("\n");
        /*printf("que voulez vous faire?\n"); printf("\n");
        printf("4-jouer a gauche; 6-jouer a droite;  8-jouer vers le haut;  2-jouer vers le bas; 9-aide; 0-quitter;\n--->");
        scanf("%d",&n);*/
        switch(n)
        {
        case 75:
            printf("\n");
            deplacement_gauche(plateau,&t);
            somme_gauche(plateau,&score);
            deplacement_gauche(plateau,&t);
            printf("votre score est egal a %d:\t\n",score);
           if(t==1)
            {
                t=0;
            alea(plateau);
            affichage( plateau);
            }
            else
            {
                if(t!=1)
                {
                    t=0;
                    affichage( plateau);
                    printf("deplacement impossible essaiyez une autre direction ou sur quitter \n");
                    break;
                }
            }
            /* on commence par déplacer à gauche puis on fait une somme gauche puis on déplace de nouveau vers la gauche
             par la suite on génère un nouveau2 et on affiche le résultat */
            break;

        case 77:
            printf("\n");
            deplacement_droite(plateau,&t);
            somme_droite(plateau,&score);
            deplacement_droite(plateau,&t);
            printf("votre score est egal a %d:\t\n",score);
           if(t==1)
            {
            t=0;
            alea(plateau);
            affichage( plateau);
            }
            else
            {
                if(t!=1)
                {
                    t=0;
                    affichage( plateau);
                    printf("deplacement impossible essaiyez une autre direction ou sur quitter\n");
                    break;
                }
            }
             /* on commence par déplacer vers la droite puis on fait une somme droite puis on déplace de nouveau vers la droite
             par la suite on génère un nouveau2 et on affiche le résultat */
            break;
        case 72:
            printf("\n");
            deplacement_haut(plateau,&t);
            somme_haut(plateau,&score);
            deplacement_haut(plateau,&t);
            printf("votre score est egal a %d:\t\n",score);
            if(t==1)
            {
            t=0;
            alea(plateau);
            affichage( plateau);
            }
            else
            {
                if(t!=1)
                {
                    t=0;
                    affichage( plateau);
                    printf("deplacement impossible essaiyez une autre direction ou sur quitter \n");
                    break;
                }
            }
             /* on commence par déplacer vers le haut puis on fait une somme haut puis on déplace de nouveau vers le haut
             par la suite on génère un nouveau2 et on affiche le résultat */
            break;
        case 80:
            printf("\n");
            deplacement_bas(plateau,&t);
            somme_bas(plateau,&score);
            deplacement_bas(plateau,&t);
            printf("votre score est egal a %d:\t\n",score);
           if(t==1)
            {
                t=0;
            alea(plateau);
            affichage( plateau);
            }
            else
            {
                if(t!=1)
                {
                    t=0;
                    affichage( plateau);
                    printf("deplacement impossible essaiyez une autre direction ou sur quitter \n");
                    break;
                }
            }
             /* on commence par déplacer vers le bas puis on fait une somme bas puis on déplace de nouveau vers le bas
             par la suite on génère un nouveau2 et on affiche le résultat */
            break;
        case 48:
            printf("Le 2048 est un jeu de puzzle numérique dans lequel le joueur doit combiner des tuiles portant des nombres pour atteindre le nombre 2048. Voici les règles du jeu :\n");
            printf("1.Le jeu se joue sur une plateau de 4x4 cases. \n");
            printf("2.Au début du jeu, il y a deux tuiles sur le plateau, chacune portant le nombre 2 . \n");
            printf("3.Le joueur peut déplacer les tuiles dans les quatre directions : haut, bas, gauche et droite.\n");
            printf("4.Lorsqu'une tuile est déplacée dans une direction, elle continue à se déplacer jusqu'à ce qu'elle atteigne le bord du plateau ou qu'elle rencontre une autre tuile.\n");
            printf("5.Si deux tuiles portant le même nombre se rencontrent, elles fusionnent en une seule tuile portant la somme des deux nombres.\n");
            printf("6.Après chaque mouvement, une nouvelle tuile apparaît sur le plateau, portant le nombre 2 .\n");
            printf("7.Le jeu se termine lorsque le plateu est remplie de tuiles et qu'aucun mouvement n'est possible, ou lorsque le joueur atteint la tuile portant le nombre 2048.\n");
            printf(" Le but du jeu est de combiner les tuiles pour atteindre le nombre 2048.\n \n");
            printf("\n");
            printf(" APPUYER SUR UNE AUTRE TOUCHE DE DIRECTION POUR CONTINUER\n");
            break;
        }
        m=winner(plateau);
        M=you_lose(plateau);
        if((n!=75)&&(n!=72)&&(n!=77)&&(n!=4)&&(n!=80)&&(n!=48)&&(n!=49))
        {
           printf("\n");
           printf(" mauvaise touche \n \n recommencer \n\n appuyer sur une touche de direction pour continuer\n");
        }else{
        if(m==1)
        {
            system("cls");
            printf("\n");
            printf("vous avez gagner\n VOTRE SCORE EST DE %d :",score);
        }else{
        if((M!=0))
        {

            system("cls");
            printf("\n");
            //printf("vous avez perdu\n");
            printf("vous avez perdu\n VOTRE SCORE EST DE %d :",score);
        }
        }
        }

    }while((n!=49)&&(m!=1)&&(M==0));
}

