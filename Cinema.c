//Exercice Cinema Kassandra en C

//Intégration des bibliothèques permettant de réaliser ce projet

#include <stdio.h>
#include <cs50.h>

//On écrit la fonction principal qui ne renvoie rien

int main(void){
    
    //On créé les varibles char(caractères) qui vont nous permettrent de poser les différentes questions pour celui qui va utiliser le programme.
    
    char q1;
    char q2;
    char q3;
   
   //On créé les variables int(entier) pour déterminer si celui qui reponds aux questions est Adulte, Ados ou bien enfants.
    int adulte = 0;
    int vuado = 0;
    int vuenf = 0;
    
    //On créé une assignation pour déterminé l'age de celui qui va répondre aux questions.
    int Age = get_int("Quelle est ton âge ?\n");
    
    //On créé un tableau en 2D qui comporte 3 lignes et 4 colonnes qui ont des chaînes de caractères dans ce dernier.
    string catégorie[3][4] = {{"film Categorie Enfant ", "PatPatrol le film","Les Minions","Mon Voisin Totoro"},
                              {"film Categorie Ados","Demon Slayer","Akira","Pokemon le film"},
                              {"film Categorie Adulte","Mad Max", "The Thing","Evil Dead"}
    };
    
    //On crée une boucle do while pour éviter de faire pleins de If mais aussi pour arrêter les boucles for si on veut revenir au tout début de la boucle do while.
   do{ 
    //Création d'une condition if qui vérifie l'age de l'utilisateur (ici inférieur à 11 ans).
    //Pour rentrée dans la condition enfant, si un adulte à fait ce choix après avoir refuser tout les films de la catégorie Adulte.
   if(Age < 11 || q3 == 'e'){
    
    //On crée une condition if si la variable adulte est égal à 1.
    //La variable vuenf permet de ne pas revenir sur cette catégorie si elle à deja été passée et c'est pour ça qu'on met vuenf = 1.
       if(adulte == 1){
        vuenf = 1;
    }
       //On affiche la phrase qui est situé dans le printf où les choix sont situés dans le tableau au dessus.
        printf("Voici les choix de %s\n", catégorie[0][0]);
       
       //On crée une boucle for qui va nous permettre d'afficher les films de la catégorie Enfants.
        for(int i=1;i<4;i++){
            
            //On assigne la variable q1 qui va poser la question si dessous dans la ligne 0 du tableau en partant grâce à i=1 à au premier choix qui est PapPatrol Le film.
            q1 = get_char("Voulez vous voir %s appuie sur [o] ou [n]\n", catégorie [0][i]);
            
            //On crée une condition if si la variable qi est égal à 'o'.
            if(q1 == 'o'){
                
                //On affiche la phrase en dessus avec la chaine de caractère qui correspond à la réponse 'o' de la ligne 0 du tableau.
                printf("%s va commencer", catégorie[0][i]);
                
                //On mets fin au programme entier.
                return 0;
              
             //On crée une condtion else if(sinon si) si la variable q1 est égal à 'n'.   
            }else if(q1 == 'n'){
                
                //On crée la condition if si i est égal à 3 ce qui correspond au refus de toute les propositions de la catégorie enfant.
                if(i == 3){
                    
                    //On crée la condtion if si la varaible adulte est égal à 1 donc si un adulte à vu toutes les propositions de la catégorie entant.
                    if(adulte == 1){
                        
                        //On crée la condtion if si la varaible vuado est égal à 1 donc si un ado à vu toutes les propositions de la catégorie entant.
                        if(vuado == 1){
                            
                          //On affiche la phrase si dessous.
                          printf("Renevez plus tard pour d'autres films\n");
                            
                          //On mets fin au programme principal.  
                          return 0;
                         }
                        
                        //On crée la boucle do while pour reposer la question en cas d'erreur.
                        do{
                            
                        //On assigne la variable q2 pour poser la question si dessous pour savoir si un adulte veut voir la catégorie Ado.    
                       q2 = get_char("Voulez-vous voir les %s\n ? Appuiez sur [o] ou [n]\n", catégorie[1][0]);
                     
                    //On crée la condition if si la variable q2 est égal à 'o'
                    if(q2 == 'o'){
                        
                        //La variable q3 est assigné à la lettre a qui correspond à la catégorie Ado.
                        q3 = 'a';
                        
                        //On utilise break pour pouvoir sortir de la deuxième boucle do while.
                        break;
                        
                    //On crée la condtion else if si la variable q2 est égal à 'n' donc quand on appuie sur la touche n.    
                    }else if(q2 == 'n'){
                        
                        //Cela affiiche la phrase si dessous.
                        printf("Renevez plus tard pour d'autres films\n");
                        
                        //On mets fin au programme principal.
                        return 0;
                        
                    //on crée la condtion else pour empecher d'appuier sur une autre touche que o ou n   
                    }else{
                        printf("Veuillez répondre par [o] ou [n] ! Je vous remercie de votre attention !\n");
                    }
                            
                   //Le while correspond à la fin de la boucle do while et le 1 sert rendre la boucle infini si on veut refaire des choix.         
                  }while(1);
                        
                  //On créé la condition else pour afficher le texte si dessous.      
                 }else{
                    printf("Renevez plus tard pour d'autres films\n");
                        
                    //On mets fin au programme princiapl.   
                    return 0;
                 }
                    
                //On créé la condition else pour affiche la phrase si dessous.    
                }else{
                printf("Proposition suivante\n");
                }
                
             //On crée la condition else pour assigner i-1 si on fait une erreur de touche.  
            }else{
                i--;
            }

        }

    }else if((Age>=11 && Age<=17) || q3 == 'a'){
    if(adulte == 1){
        vuado = 1;
    }
    printf("Voici les choix de %s\n", catégorie[1][0]);
    for(int i=1;i<4;i++){
            q1 = get_char("Voulez vous voir %s appuie sur [o] ou [n]\n", catégorie [1][i]);
            if(q1 == 'o'){
                printf("%s va commencer", catégorie[1][i]);
                return 0;
            }else if(q1 == 'n'){
                if(i == 3){
                    if(vuenf == 1){
                          printf("Renevez plus tard pour d'autres films\n");
                          return 0;
                         }
                    do{
                       q2 = get_char("Voulez-vous voir les %s\n ? Appuiez sur [o] ou [n]\n", catégorie[0][0]);
                    if(q2 == 'o'){
                        q3 = 'e';
                        break;
                    }else if(q2 == 'n'){
                        printf("Renevez plus tard pour d'autres films\n");
                        return 0;
                    }else{
                        printf("Veuillez répondre par [o] ou [n] ! Je vous remercie de votre attention !\n");
                    }
                  }while(1);
                }else{
                printf("Proposition suivante\n");
                }
            }else{
                i--;
            }

        }
    }
    else{
        adulte = 1;
        printf("Voici les choix de %s\n", catégorie[2][0]);
        for(int i=1;i<4;i++){
            q1 = get_char("Voulez vous voir %s appuie sur [o] ou [n]\n", catégorie [2][i]);
            if(q1 == 'o'){
                printf("%s va commencer", catégorie[2][i]);
                return 0;
            }else if(q1 == 'n'){
                if(i == 3){
                    do{
                       q2 = get_char("Voulez-vous voir les autres tranches d'âges ? Appuiez sur [o] ou [n]\n");
                    if(q2 == 'o'){
                        q3 = get_char("Il y a :\n %sappuyez sur [e]\n %s appuiez sur [a]\n",catégorie[0][0], catégorie[1][0]);
                        break;
                    }else if(q2 == 'n'){
                        printf("Renevez plus tard pour d'autres films\n");
                        return 0;
                    }else{
                        printf("Veuillez répondre par [o] ou [n] ! Je vous remercie de votre attention!\n");
                    }
                  }while(1);
                }else{
                printf("Proposition suivante\n");
                }
            }else{
                i--;
            }

        }
    }
   }while(1);
}
