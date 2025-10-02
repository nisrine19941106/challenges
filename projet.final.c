#include<stdio.h>
#include<string.h>
     typedef struct {
        int idclient;
        char nom[20];
        char prenom[20];
        char email[50];
        float solde;
    }client;
    typedef struct {
        int produit;
        char nom[30];
        char cataloge [30];
        float prix;
        int stock;
        char discription [100];
    
    }produit;
        int verifclient=0;   // pour verifier s il y a un profil client exist
          client c;
          produit p[10];
          int nbr=0;
////////////////////////////////////////// CARTE d'acueil
void menu (){
        printf(" ******* menu ******* \n");
        printf("1*Gestion du profil client\n");
        printf("2*Gestion du solde virtuel\n");
        printf("3*Consultation des produits\n");
        printf("4*Effectuer un achat\n");
        printf("5* Mes statistiques\n");
        printf("0*Quitter l'application\n");
    }
///////////////////////////////////////////  // saisi des donnes du client        
void Creationdeprofil(){
               printf("ajouter un client:\n");
          c.idclient=1;
        printf("entrer nom:\n");
        printf("%s",&c.nom);
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
       printf("idclient.%dsolde.%.2f|nom.%s|prenom.%s|email.%s|",c.idclient,c.solde,c.nom,c.prenom,c.email);
}
    
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
}
void menuclient(){
    int choix;
  do{
       printf("----menu----\n");
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
    case 0:printf("au revoir\n");break;
    default:printf("choix non dispo\n");
    }
    }while (choix!=0);
}
///////////////////////////////////SOLDE
void depotargent(){            
    if (verifclient==0){
        printf("du dois ceer un profil \n");return;
    }
    float montant;
        printf("entrer le montant a deposer\n");
        scanf("%.2f,&montant");
    c.solde=c.solde+montant;
        printf(" le nouveau est : %.2f",&c.solde);
    }
void Consultationdusolde(){
    if (verifclient==0){
        printf("du dois ceer un profil \n");return;
    }
        printf("solde actuel est :%.2f\n",c.solde);
}
///////////////////////////////////variable global
produit p[10] = {
    {1, "Ordinateur Portable", "Electronique", 7999.0, 10, "PC portable performant avec 8Go RAM"},
    {2, "Smartphone", "Electronique", 4999.0, 20, "Telephone 5G avec ecran OLED"},
    {3, "Tablette", "Electronique", 2999.0, 12, "Tablette 10 pouces avec stylet"},
    {4, "Imprimante", "Electronique", 1999.0, 8, "Imprimante multifonction WiFi"},
    {5, "Casque Audio", "Electronique", 899.0, 25, "Casque Bluetooth avec reduction de bruit"},
    {6, "Chaise Bureau", "Mobilier", 1200.0, 15, "Chaise ergonomique avec accoudoirs"},
    {7, "Bureau en bois", "Mobilier", 3500.0, 5, "Bureau solide en chêne"},
    {8, "Livre C Programming", "Livre", 250.0, 50, "Guide complet pour apprendre le langage C"},
    {9, "Sac a dos", "Accessoires", 450.0, 30, "Sac resistant et imperméable"},
    {10, "Clavier mecanique", "Electronique", 1500.0, 18, "Clavier RGB pour gamer"}
};
int nbProduits = 10;
//////////////////////////////afficher cataloge( prix et stock):
void affichagecataloge(){
       printf("*** liste produit prix/stock :\n");
    for ( int i = 0; i < nbProduits ; i++){
        printf("%.2f\n",p[i].prix);
        printf("%d",p[i].stock);
    }
    
}
///////////////////////////////recherche produit
void rechercherproduit(){
    }
       char chercher[30];
       int trouve=0;
       printf
