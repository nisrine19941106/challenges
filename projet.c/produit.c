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
