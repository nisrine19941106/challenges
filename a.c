#include <stdio.h>
#include <string.h>

// ===================== Structures =====================
typedef struct {
    int idClient;
    char nom[30];
    char prenom[30];
    char email[50];
    float solde;
} Client;

typedef struct {
    int idProduit;
    char nom[30];
    char categorie[30];
    float prix;
    int stock;
} Produit;

typedef struct {
    char nomProduit[30];
    float prix;
} Achat;

// ===================== Variables globales =====================
Client client;       // Un seul client
int clientCree = 0;  // Pour savoir si le client existe
Produit produits[5];
int nbProduits = 5;
Achat historique[100];
int nbAchats = 0;

// ===================== Fonctions =====================
void initialiserProduits() {
    strcpy(produits[0].nom, "Ordinateur Portable");
    strcpy(produits[0].categorie, "Electronique");
    produits[0].idProduit = 1;
    produits[0].prix = 799.0;
    produits[0].stock = 5;

    strcpy(produits[1].nom, "Smartphone");
    strcpy(produits[1].categorie, "Electronique");
    produits[1].idProduit = 2;
    produits[1].prix = 499.0;
    produits[1].stock = 10;

    strcpy(produits[2].nom, "Casque Audio");
    strcpy(produits[2].categorie, "Accessoires");
    produits[2].idProduit = 3;
    produits[2].prix = 89.0;
    produits[2].stock = 15;

    strcpy(produits[3].nom, "Souris");
    strcpy(produits[3].categorie, "Accessoires");
    produits[3].idProduit = 4;
    produits[3].prix = 25.0;
    produits[3].stock = 20;

    strcpy(produits[4].nom, "Clavier");
    strcpy(produits[4].categorie, "Accessoires");
    produits[4].idProduit = 5;
    produits[4].prix = 45.0;
    produits[4].stock = 12;
}

// ===================== Profils =====================
void creerProfil() {
    printf("\n--- Création du profil ---\n");
    printf("Entrez le nom : "); scanf("%s", client.nom);
    printf("Entrez le prénom : "); scanf("%s", client.prenom);

    client.idClient = 1;
    sprintf(client.email, "%s.%s@client.com", client.prenom, client.nom);
    client.solde = 0.0;
    clientCree = 1;

    printf("✅ Profil créé avec succès !\n");
}

void modifierProfil() {
    if (!clientCree) { printf("⚠️ Profil non encore créé !\n"); return; }
    printf("Entrez le nouveau nom : "); scanf("%s", client.nom);
    printf("Entrez le nouveau prénom : "); scanf("%s", client.prenom);
    sprintf(client.email, "%s.%s@client.com", client.prenom, client.nom);
    printf("✅ Profil modifié avec succès !\n");
}

void consulterProfil() {
    if (!clientCree) { printf("⚠️ Profil non encore créé !\n"); return; }
    printf("\n--- Profil du client ---\n");
    printf("ID: %d\nNom: %s\nPrénom: %s\nEmail: %s\nSolde: %.2f MAD\n",
           client.idClient, client.nom, client.prenom, client.email, client.solde);
}

// ===================== Solde =====================
void depotArgent() {
    if (!clientCree) { printf("⚠️ Créez d'abord un profil !\n"); return; }
    float montant;
    printf("Entrez le montant à déposer : "); scanf("%f", &montant);
    client.solde += montant;
    printf("✅ Dépôt effectué ! Nouveau solde: %.2f MAD\n", client.solde);
}

void consulterSolde() {
    if (!clientCree) { printf("⚠️ Créez d'abord un profil !\n"); return; }
    printf("💰 Votre solde actuel: %.2f MAD\n", client.solde);
}

// ===================== Produits =====================
void afficherProduits() {
    printf("\n--- Liste des produits ---\n");
    for (int i = 0; i < nbProduits; i++)
        printf("%d. %s | %s | %.2f MAD | Stock: %d\n",
               produits[i].idProduit, produits[i].nom, produits[i].categorie,
               produits[i].prix, produits[i].stock);
}

void rechercherProduit() {
    char recherche[30];
    int trouve = 0;
    printf("Entrez le nom du produit à rechercher : "); scanf("%s", recherche);

    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(produits[i].nom, recherche) == 0) {
            printf("✅ Produit trouvé: %s | %.2f MAD | Stock: %d\n",
                   produits[i].nom, produits[i].prix, produits[i].stock);
            trouve = 1;
            break;
        }
    }
    if (!trouve) printf("❌ Produit introuvable !\n");
}

// ===================== Achat =====================
void acheterProduit() {
    if (!clientCree) { printf("⚠️ Créez d'abord un profil !\n"); return; }

    afficherProduits();
    int choix; printf("Entrez l'ID du produit à acheter : "); scanf("%d", &choix);
    if (choix < 1 || choix > nbProduits) { printf("❌ Produit invalide !\n"); return; }

    Produit *p = &produits[choix-1];
    if (p->stock <= 0) { printf("❌ Produit en rupture de stock !\n"); return; }
    if (client.solde < p->prix) { printf("❌ Solde insuffisant !\n"); return; }

    client.solde -= p->prix;
    p->stock--;

    // Sauvegarde dans l'historique
    strcpy(historique[nbAchats].nomProduit, p->nom);
    historique[nbAchats].prix = p->prix;
    nbAchats++;

    printf("✅ Achat réussi ! Vous avez acheté: %s\n", p->nom);
    printf("Nouveau solde: %.2f MAD\n", client.solde);
}

// ===================== Statistiques =====================
void statistiquesPersonnelles() {
    if (!clientCree) { printf("⚠️ Créez d'abord un profil !\n"); return; }
    printf("\n--- Vos statistiques ---\n");
    printf("Solde actuel: %.2f MAD\n", client.solde);
    printf("Nombre d'achats: %d\n", nbAchats);
    if (nbAchats > 0) {
        printf("Historique des achats:\n");
        for (int i = 0; i < nbAchats; i++)
            printf("%d. %s | %.2f MAD\n", i+1, historique[i].nomProduit, historique[i].prix);
    }
}

// ===================== Main =====================
int main() {
    initialiserProduits();
    int choix;

    do {
        printf("\n=== Système d'achat client ===\n");
        printf("1. Gestion du profil\n");
        printf("2. Gestion du solde\n");
        printf("3. Afficher les produits\n");
        printf("4. Acheter un produit\n");
        printf("5. Rechercher un produit\n");
        printf("6. Mes statistiques\n");
        printf("0. Quitter\n");
        printf("Votre choix: "); scanf("%d", &choix);

        switch (choix) {
            case 1: {
                printf("1- Créer un profil\n2- Modifier le profil\n3- Consulter le profil\nVotre choix: ");
                int sc; scanf("%d", &sc);
                if (sc==1) creerProfil();
                else if (sc==2) modifierProfil();
                else if (sc==3) consulterProfil();
                else printf("❌ Choix invalide !\n");
                break;
            }
            case 2: {
                printf("1- Consulter le solde\n2- Déposer de l'argent\nVotre choix: ");
                int sc; scanf("%d", &sc);
                if (sc==1) consulterSolde();
                else if (sc==2) depotArgent();
                else printf("❌ Choix invalide !\n");
                break;
            }
            case 3: afficherProduits(); break;
            case 4: acheterProduit(); break;
            case 5: rechercherProduit(); break;
            case 6: statistiquesPersonnelles(); break;
            case 0: printf("👋 Au revoir !\n"); break;
            default: printf("❌ Choix invalide !\n");
        }
    } while (choix != 0);

    return 0;
}