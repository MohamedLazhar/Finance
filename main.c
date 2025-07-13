#include <stdio.h>

// STRUCTURE DES DONNEES
// Le Compte 

typedef struct Comptes
{
  int ID;
  Char Libelle[31];
  
} Comptes;

int main ()
{
  Comptes Compte[11];
  for(int i=1;i<32;i++)
    {
     scan("%d",Compte.ID[i]);
     scan("%d",Compte.Libelle[i]);
     printf(" Les Comptes ID : %d Libelle : %c /n ", Compte.ID,Compte.Libelle);
    }
  
  
}


