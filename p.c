#include<stdio.h>
#include <stdlib.h>
#include<string.h>
     typedef struct {
        int idclient;
        char nom[20];
        char prenom[20];
        char email[50];
        float solde;
    }client;
    typedef struct {
        int idproduit;
        char nom[30];
        char cataloge [30];
        float prix;
        int stock;
        char discription [100];
    
    }produit;
        int verifclient=0;   // pour verifier s il y a un profil client exist
          client c;
         // produit p[10];
          int nbr=0; 
          //variable global
produit p[10] = {
    {1, "Ordinateur Portable", "Electronique", 7999.0, 10, "PC portable performant avec 8Go RAM"},
    {2, "Smartphone", "Electronique", 4999.0, 1, "Telephone 5G avec ecran OLED"},
    {3, "Tablette", "Electronique", 2999.0, 12, "Tablette 10 pouces avec stylet"},
    {4, "Imprimante", "Electronique", 1999.0, 8, "Imprimante multifonction WiFi"},
    {5, "Casque Audio", "Electronique", 899.0, 25, "Casque Bluetooth avec reduction de bruit"},
    {6, "Chaise Bureau", "Mobilier", 1200.0, 15, "Chaise ergonomique avec accoudoirs"},
    {7, "Bureau en bois", "Mobilier", 3500.0, 5, "Bureau solide en chêne"},
    {8, "Livre C Programming", "Livre", 250.0, 50, "Guide complet pour apprendre le langage C"},
    {9, "Sac a dos", "Accessoires", 450.0, 30, "Sac resistant et imperméable"},
    {10, "Clavier mecanique", "Electronique", 1500.0, 18, "Clavier RGB pour gamer"}
};
// nombre Max Produit 
int nbProduits = 10;


 // saisi des donnes du client        
void Creationdeprofil(){
               printf("ajouter un client:\n");
          c.idclient=1;
        printf("entrer nom:\n");
        scanf("%s",&c.nom);
        printf("enter prenom:\n");
        scanf("%s",&c.prenom);
        sprintf(c.email,"%s.%s@client.com",c.prenom,c.nom);
        c.solde=0.0;
        verifclient=1;
        printf(" client cree avec succes\n ");
        }
///////////////////////////////////////// afficher tous les donner du client a la fois
void affichage(){
    if(verifclient==0){
        printf("aucun client trouver\n");
       return;}
       printf("idclient: %d |solde:%.2f|nom: %s|prenom: %s|email: %s| \n",c.idclient,c.solde,c.nom,c.prenom,c.email);
}
///////////////////modification du profil par nom et prenom 
void modification(){  
    if (verifclient==0){
       printf("aucun client trouver\n");
       return;
    }
       printf("modifier le nom\n:");
       scanf("%s",&c.nom);
       printf("modifier le prenom:\n");
       scanf("%s",&c.prenom);
       sprintf(c.email,"%s.%s@client.com",c.prenom,c.nom);
       printf(" client Modifier avec succes\n ");
}

//////// Agent SOLDE
void depotargent(){            
    if (verifclient==0){
        printf("du dois ceer un profil \n");
		return;
    }
    float montant;
        printf("entrer le montant a deposer\n :");
        scanf("%f",&montant);
    c.solde=c.solde+montant;
        printf("\n le nouveau est : %.2f",c.solde);
    }
    
    //consultation
void Consultationdusolde(){
    if (verifclient==0){
        printf("du dois ceer un profil \n");return;
    }
        printf("solde actuel est :%.2f\n",c.solde);
}

//afficher cataloge( prix et stock):
void affichagecataloge(){                                           
       printf("*** liste produit prix/stock :\n");
    for ( int i = 0; i < nbProduits ; i++){
    	printf("ID : %d |",p[i].idproduit);
    	printf(" nom : %s |",p[i].nom);
    	printf(" cataloge : %s |",p[i].cataloge);
        printf(" prix : %.2f |",p[i].prix);
        printf(" stock : %d |\n",p[i].stock);
        //printf("discription : %s |",p[i].discription);
        printf("-------------------------------------------------------------------------------------------\n");
    }
    
}
///recherche produit
int rechercherproduit(){
    char chercher[30];
    int trouver = 0;

    printf("Entrer le nom du produit à rechercher :\n");
    scanf("%s", chercher);

    for(int i=0; i<nbProduits; i++){
        // comparer par nom (on peut changer par p[i].cataloge si besoin)
        if(strcmp(p[i].nom, chercher) == 0){
            printf("ID : %d | ", p[i].idproduit);
            printf("Nom : %s | ", p[i].nom);
            printf("Catégorie : %s | ", p[i].cataloge);
            printf("Prix : %.2f | ", p[i].prix);
            printf("Stock : %d |\n", p[i].stock);
            printf("------------------------------------------------------------------------------------------------\n");
            
            trouver = 1;
            break;  // on arrête la recherche dès qu’on trouve
        }
    }

    if(trouver == 0){
        printf("Aucun produit trouvé\n");
    }

    return trouver;
}
///recherche produit par id 
int rechercherproduitId(){
    int chercherid;
    int trouver = 0,position;

    printf("Entrer le ID du produit à rechercher :\n");
    scanf("%d",&chercherid);

    for(int i=0; i<nbProduits; i++){
       //charche par ID pour Traval function Achat
        if(chercherid==p[i].idproduit){
            position=i;
            trouver = 1;
            break;  // on arrête la recherche dès qu’on trouve
        }
    }

    if(trouver == 0){
        printf("Aucun produit trouvé\n");
    }

    return position;
}
        
void tridesproduit(){
   produit tri;
    int choix;

    printf("---- Tri des produits ----\n");
    printf("1* Par prix croissant\n");
    printf("2* Par prix décroissant\n");
    printf("3* Par nom (A-Z)\n");
    printf("4* Par nom (Z-A)\n");
    printf("Entrer le choix Tri : \n");
    scanf("%d",&choix);

    for(int i=0;i<nbProduits-1;i++){
        for(int j=i+1;j<nbProduits;j++){
            if(choix==1){  // Prix croissant
                if(p[i].prix > p[j].prix){
                    tri = p[i];
                    p[i] = p[j];
                    p[j] = tri;
                }
            }else if(choix==2){ // Prix décroissant
                if(p[i].prix < p[j].prix){
                    tri = p[i];
                    p[i] = p[j];
                    p[j] = tri;
                }
            }else if(choix==3){ // Nom A-Z
                if(strcmp(p[i].nom, p[j].nom) > 0){
                    tri = p[i];
                    p[i] = p[j];
                    p[j] = tri;
                }
            }else if(choix==4){ // Nom Z-A
                if(strcmp(p[i].nom, p[j].nom) < 0){
                    tri = p[i];
                    p[i] = p[j];
                    p[j] = tri;
                }
            }
        }
    }

    printf("Tri effectué avec succès !\n");
    printf("---- Produits triés ----\n");
	  affichagecataloge();      
}
// Achat 
void acheterProduit() {
    if (verifclient == 0) {
        printf("? Vous devez d'abord créer un client!\n");
        return;
    }

    printf("\n---- Liste des Produits ----\n");
    //affcihe tout Produit
    affichagecataloge();
    // function rechercherproduitId() pour return position le produit
	//idxProduit stocker position produit  
  int idxProduit =  rechercherproduitId();
  
  // Vérifier le stock
    if (p[idxProduit].stock <= 0) {
        printf("? Produit en rupture de stock!\n");
        return;
    }

    // Vérifier le solde
    if (c.solde < p[idxProduit].prix) {
        printf("? Solde insuffisant!\n");
        return;
    }

    // Effectuer l'achat
    c.solde -= p[idxProduit].prix;
    p[idxProduit].stock--;

    printf("? Achat effectué! Produit: %s\n", p[idxProduit].nom);
    printf("?? Solde restant: %.2f MAD\n", c.solde);
 
    
}
    
//Menu Produit 
void CataloguedesProduits(){
	 system("cls");
	int choix;
do{
       printf("----Menu Catalogue des Produits----\n");
       printf("1*Affichage catalogue:\n");
       printf("2*Recherche produits :\n");
       printf("3*Tri des produits :\n");
       printf("4*Détails produit :\n");
       printf("0*quitter\n");
       printf("entrer votre choix:");
       scanf("%d",&choix);
    switch (choix){  
	
	case 1:affichagecataloge();break;
    case 2:rechercherproduit();break;
    case 3:tridesproduit();break;
    case 4:rechercherproduit();break;
    case 0:printf("Retour Menu Prnicpal \n");break;
    default:printf("choix non dispo\n");break;
    	
	}
	
}while(choix!=0);
}

//menu client 
void menuclient(){
	 system("cls");
    int choix;
  do{ 
       printf("----Menu client----\n");
       printf("1*creer client:\n");
       printf("2*modifier client:\n");
       printf("3*afficher client:\n");
       printf("0*quitter\n");
       printf("entrer votre choix:");
       scanf("%d",&choix);
    switch (choix)
    {
    case 1:Creationdeprofil();break;
    case 2:modification();break;
    case 3:affichage();break;
    case 0:printf("Retour Menu Prnicpal \n");break;
    default:printf("choix non dispo\n");break;
    }
    //check 
    }while (choix!=0);
}
//Menu solde
void menuSolde(){
	 system("cls");
	printf("\n-------------------------------\n");
	int choix;
	   do{ printf("menu solde\n");
	       printf("1* depot d'argent \n");
	       printf("2* consultaion du solde \n");
	       printf("0*quitter \n");
		   printf("entrer votre choix\n");
		   scanf("%d",&choix);
	switch(choix){
		   case 1: depotargent();break;
		   case 2: Consultationdusolde();break;
		   case 0: printf("retour au menu principal\n");break;
		   default : printf("choix non dispo\n");break;
	}
    }while(choix!=0);
}

////// Menu Prncipal
void menuPrincipal (){
   system("cls");
	int choix;
      do{
        printf(" ******* menu ******* \n");
        printf("1*Gestion du profil client\n");
        printf("2*Gestion du solde virtuel\n");
        printf("3*Consultation des produits\n");
        printf("4*Effectuer un achat\n");
        printf("5* Mes statistiques\n");
        printf("0*Quitter l'application\n");
        printf("enter le choix :");
        scanf("%d",&choix);
    switch(choix)
	{
	case 1:menuclient();break;
	case 2:menuSolde();break;
	case 3: CataloguedesProduits();break;
	case 4: acheterProduit();break;
	case 0:printf(" Quitter l'application!\n");break;
	default:printf("choix non valable");break;
	
      		}
    }while(choix!=0);
 }
    

int main(){
	 printf("\n-------------------------------\n");
	menuPrincipal();
	
	return 0;
}