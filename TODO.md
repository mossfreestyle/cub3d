//TODO

CUB3D - ROADMAP FRONT (AFFICHAGE & RENDU)
==========================================

📋 TABLE DES MATIÈRES
=====================
1. INITIALISATION AFFICHAGE
2. GESTION FENÊTRE & IMAGES
3. RAYCASTING & RENDU MURS
4. TEXTURES & COULEURS
5. AFFICHAGE JOUEUR & MINIMAP
6. BOUCLE DE RENDU & EVENTS
7. OPTIMISATIONS RENDU
8. BONUS VISUELS

═══════════════════════════════════════════════════════════════════════════════

1. INITIALISATION AFFICHAGE
===========================
- Initialiser la connexion MLX (mlx_init)
- Créer la fenêtre principale (mlx_new_window)
- Créer une image buffer (mlx_new_image)
- Récupérer l’adresse du buffer image (mlx_get_data_addr)
- Définir les constantes d’affichage (WIDTH_DISPLAY, HEIGHT_DISPLAY)

2. GESTION FENÊTRE & IMAGES
===========================
- Afficher l’image à l’écran (mlx_put_image_to_window)
- Gérer la fermeture propre de la fenêtre (croix, ESC)
- Détruire les images et la fenêtre à la fermeture
- Nettoyer la mémoire (textures, buffers)

3. RAYCASTING & RENDU MURS
==========================
- Boucle principale de raycasting (pour chaque colonne de l’écran)
- Calculer la direction du rayon pour chaque colonne
- Appliquer l’algorithme DDA pour trouver les murs
- Calculer la distance au mur et la hauteur à dessiner
- Dessiner la colonne de pixels correspondante (mur)

4. TEXTURES & COULEURS
======================
- Charger les textures (mlx_xpm_file_to_image)
- Récupérer l’adresse des textures (mlx_get_data_addr)
- Appliquer la texture sur les murs selon la direction frappée (N/S/E/W)
- Gérer les couleurs du sol et du plafond (remplir le haut/bas de l’image)
- Gérer les erreurs de chargement texture

5. AFFICHAGE JOUEUR & MINIMAP (OPTIONNEL)
=========================================
- Afficher la position du joueur sur une mini-map 2D
- Afficher les rayons sur la mini-map (debug)
- Afficher la direction du joueur

6. BOUCLE DE RENDU & EVENTS
===========================
- Rafraîchir l’image à chaque frame (mlx_loop_hook)
- Gérer les entrées clavier (déplacement, rotation)
- Mettre à jour la position/angle du joueur et relancer le rendu
- Gérer la fermeture via ESC ou croix

7. OPTIMISATIONS RENDU
======================
- Limiter le nombre de recalculs inutiles
- Utiliser des buffers pour éviter les flickers
- Optimiser les accès mémoire lors du dessin
- (Bonus) Afficher le FPS à l’écran

8. BONUS VISUELS (SI TEMPS)
===========================
- Sprites (objets, ennemis)
- Effets de lumière ou ombres
- Animation des textures
- HUD (vie, munitions, etc.)
- Transitions ou effets spéciaux

═══════════════════════════════════════════════════════════════════════════════

📝 NOTES IMPORTANTES
====================
- Respecter la Norminette (fonctions courtes, noms explicites)
- Toujours vérifier les retours de malloc et des fonctions MLX
- Nettoyer toute la mémoire à la fermeture
- Tester sur différentes tailles de cartes et textures
- Priorité à la stabilité et à la fluidité d’affichage

═══════════════════════════════════════════════════════════════════════════════

Imprime ce plan et coche chaque étape au fur et à mesure !
Bon dev sur le front 🚀