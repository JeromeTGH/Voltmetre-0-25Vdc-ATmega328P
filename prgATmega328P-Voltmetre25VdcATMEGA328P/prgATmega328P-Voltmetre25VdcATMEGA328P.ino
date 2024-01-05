/*
   ______               _                  _///_ _           _                   _
  /   _  \             (_)                |  ___| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier :       prgATmega328P-Voltmetre25VdcATMEGA328P.ino
  
  Description :   Programme permettant de réaliser un voltmètre à base d'ATmega328P,
                  avec affichage sur écran compatible Nokia 5510
                  
  Remarques :     - l'ATmega328P mis en oeuvre devra comporter un bootloader, de type "optiboot" (comme un Arduino Uno, en fait)
                    (lien vers article PSE à venir)
                  - là on va piloter l'ATmega328 comme s'il s'agissait d'un Arduino Uno, c'est pourquoi les entrées/sorties seront notées A0..A5 et D0..D13
                                    
  Auteur :        Jérôme TOMSKI (https://passionelectronique.fr/)
  Créé le :       30.12.2023

*/

// Inclusion des images qui seront affichées à l'écran (chiffres, bloc entête, et mention Vdc)
#include "images.h"

// Inclusion de la librairie SPI (native, sous Arduino IDE, donc pas besoin de l'importer/installer)
#include <SPI.h>

// Définition des broches de raccordement ATmega328P → convertisseur de tension 5V/3,3V → écran Nokia
// Nota : là on se sert des alias d'entrées/sorties Dxx, comme si nous étions sur un Arduino Uno
#define sortieD3_ATmega328P_vers_brocheLIGHT_ecranNokia       3              // Physiquement, la sortie D3 correspond à la broche 5 de l'ATmega328P
#define sortieD13_SCK_ATmega328P_vers_brocheCLK_ecranNokia    13             // Physiquement, la sortie D13 correspond à la broche 19 de l'ATmega328P
#define sortieD11_MOSI_ATmega328P_vers_brocheDIN_ecranNokia   11             // Physiquement, la sortie D11 correspond à la broche 17 de l'ATmega328P
#define sortieD6_ATmega328P_vers_brocheDC_ecranNokia          6              // Physiquement, la sortie D6 correspond à la broche 12 de l'ATmega328P
#define sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia      10             // Physiquement, la sortie D10 correspond à la broche 16 de l'ATmega328P
#define sortieD8_ATmega328P_vers_brocheRST_ecranNokia         8              // Physiquement, la sortie D8 correspond à la broche 14 de l'ATmega328P

// Définitions des autres broches utilisées sur l'ATmega328P
#define sortieD7_ATmega328P_vers_LED_temoin_sur_pcb           7              // Physiquement, la sortie D7 correspond à la broche 13 de l'ATmega328P
#define entreeA0_ATmega328P_lecture_tension                   A0             // Physiquement, la sortie A0 correspond à la broche 23 de l'ATmega328P


// Autres paramètres de ce programme
#define nbreDeLecturesAfaireSurA0       100
#define valeurResistanceR3DansMontage   7500      // La résistance R3 de notre montage fait 7,5 kohms
#define valeurResistanceR4DansMontage   30000     // La résistance R4 de notre montage fait 30 kohms


// ========================
// Initialisation programme
// ========================
void setup() {

  // Définition des sorties de l'ATmega328P
  pinMode(sortieD3_ATmega328P_vers_brocheLIGHT_ecranNokia, OUTPUT);
  pinMode(sortieD13_SCK_ATmega328P_vers_brocheCLK_ecranNokia, OUTPUT);
  pinMode(sortieD11_MOSI_ATmega328P_vers_brocheDIN_ecranNokia, OUTPUT);
  pinMode(sortieD6_ATmega328P_vers_brocheDC_ecranNokia, OUTPUT);
  pinMode(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, OUTPUT);
  pinMode(sortieD8_ATmega328P_vers_brocheRST_ecranNokia, OUTPUT);
  pinMode(sortieD7_ATmega328P_vers_LED_temoin_sur_pcb, OUTPUT);

  // Définition des entrées de l'ATmega328P (inutile dans l'absolu, car les ports d'E/S sont configurés en "entrée", par défaut ; mais bon, là c'est juste pour la "bonne forme" !)
  pinMode(entreeA0_ATmega328P_lecture_tension, INPUT);

  // Mise à l'état par défaut de certaines des broches de sortie de l'ATmega328P
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, LOW);      // Ligne CE du Nokia5110 = LOW, pour désactiver le module
  digitalWrite(sortieD8_ATmega328P_vers_brocheRST_ecranNokia, HIGH);        // Ligne RST du Nokia5110 = HIGH, pour désactiver le reset
  digitalWrite(sortieD3_ATmega328P_vers_brocheLIGHT_ecranNokia, LOW);       // Ligne LIGHT du Nokia5110 = LOW, pour allumer le rétroéclairage
  digitalWrite(sortieD7_ATmega328P_vers_LED_temoin_sur_pcb, HIGH);          // Allumage de la LED "témoin de bon fonctionnement" du montage (indique que le programme a bien démarré)
  
  // Initialisation du bus SPI
  SPI.begin();                            // Initialise la librairie SPI
  SPI.setClockDivider(SPI_CLOCK_DIV4);    // On divise l'horloge 16 MHz du µC par 4, pour fonctionner à 4 MHz (ce qui est la vitesse maxi, pour l'écran nokia 5110)

  // Reset du module Nokia 5110 (via ligne RST, active à l'état bas)
  digitalWrite(sortieD8_ATmega328P_vers_brocheRST_ecranNokia, LOW);
  delay(100);
  digitalWrite(sortieD8_ATmega328P_vers_brocheRST_ecranNokia, HIGH);
  delay(100);
  
  // Initialisation de l'écran Nokia 5110
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, LOW);    // Sélection de l'écran (ligne "slave select" SPI de l'ATmega328P → ligne CE de l'écran)
  envoiUneCommandeAuNokia5510(0b00100001);    // [Function set] => PD(power-down)=0, V(vertical-adressing)=0, et H=1 (H à 1 permet d'avoir accès aux commandes "étendues" de l'écran LCD)
  envoiUneCommandeAuNokia5510(0b10111000);    // [Set LCD Vop] => bits 6 à 0 donnent une valeur en 0 et 127  ; ici, 56 (x011 1000) de "contraste" est sélectionné
  envoiUneCommandeAuNokia5510(0b00010100);    // [Bias system] => bits 2, 1, et 0 donnent une valeur en 0 et 7  ; ici, 4 (xxxx x100) de "bias" est sélectionné
  envoiUneCommandeAuNokia5510(0b00100000);    // [Function set] => PD(power-down)=0, V(vertical-adressing)=0, et H=0 (retour aux commandes "normales" de l'écran LCD)
  envoiUneCommandeAuNokia5510(0b00001100);    // [Display control] => D=1, 0, E=0 (DE=10 signifie un fonctionnement en "Normal mode")
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, HIGH);   // Déselection de l'afficheur LCD

  // Petite pause, avec d'attaquer la boucle LOOP
  delay(500);


  // Mise en place des "élements fixes, sur l'écran LCD"
  effaceLecran();
  affichageBanniereEnHaut();


}


// =================
// Boucle principale
// =================
void loop() {

  // ****************************************************************************************************************************************
  // Effectue plusieurs lectures de l'entrée A0, puis en fait la moyenne (pour avoir une valeur qui varie lentement, notamment à l'affichage)
  // ****************************************************************************************************************************************
  // Nota : A0 retourne une valeur entre 0 et 1023, puisque l'ADC de l'ATmega328P sur ces entrées analogiques fait 10 bits
  int sommeDesValeursLues = 0;
  for(int i=0; i<nbreDeLecturesAfaireSurA0; i++) {
    sommeDesValeursLues = sommeDesValeursLues + analogRead(entreeA0_ATmega328P_lecture_tension);
  }
  int moyenneValeurA0 = sommeDesValeursLues / nbreDeLecturesAfaireSurA0;


  // *******************************************************************************************************************************
  // Calcul la tension mesurée, en fonction de la valeur moyenne lue sur A0, et du pont diviseur résistif présent dans notre montage
  // *******************************************************************************************************************************
  float tensionMoyenneSurA0 = (float)moyenneValeurA0 * 5 / 1023;
          // 5 correspond aux +5V de référence de l'ATmega328P (son alim), et 1023 à la résolution de lecture des entrées analogiques (10 bits)
  float tensionMesureeSurMontage = tensionMoyenneSurA0 * (valeurResistanceR3DansMontage + valeurResistanceR4DansMontage) / valeurResistanceR4DansMontage;
          // Nota : il s'agit en fait de la formule du pont diviseur de tension, mais inversée (pour trouver la valeur d'entrée, en fonction de la sortie)

  
  // ****************************************************************************
  // Affichage de la tension d'entrée calculée, sur l'écran compatible Nokia 5110
  // ****************************************************************************
  // ... à venir

  // Puis rebouclage, après une petite pause (pour ne pas faire varier l'affichage trop rapidement non plus !)
  delay(1000);
  
}




// =============================
// Fonction : testAffichageImage
// =============================
void testAffichageImage() {

  // Position de cette image
  byte Xpos = 0;    // Entre 0 et 83, sur l'axe horizontal
  byte Ypos = 0;    // Entre 0 et 5, sur l'axe vertical (chaque position ici représentant 8 bits/pixels de haut)

  // Commande de l'écran
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, LOW);  // Activation de l'écran LCD (en mettant sa ligne CE à l'état bas)
  envoiUneCommandeAuNokia5510(0b10000000 + Xpos);                       // Saut à la position horizontale "Xpos"
  envoiUneCommandeAuNokia5510(0b01000000 + Ypos);                       // Saut à la position verticale "Ypos"

  // Effaçage de l'écran (84 pixels de large, sur 6 paquets de 8 pixels de haut, ce qui donne 84x6=504 octets)
  for(int i=0; i < 504; i++) {
    envoiDesDonneesAuNokia5510(0x00);                                   // Mise à 0 préalable de tous les pixels de l'écran
  }

  // Nota : implicitement, on est revenu en X=0 et Y=0

  // Test 1 : image "VDC" (faisant 15 pixels de large)
  // for(byte j=0; j<15; j++) {
  //   envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_MENTION_VDC + j));    // Envoi de l'image sur l'écran LCD
  // }
  // Test 2 : image "bannière haute" (faisant 84 pixels de large, sur 2 octets de haut soit 16 pixels)
  // for(byte j=0; j<84; j++) {
  //   envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_ENTETE + (2*j+1)));    // Envoi de l'image sur l'écran LCD
  // }
  // for(byte j=0; j<84; j++) {
  //   envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_ENTETE + (2*j)));    // Envoi de l'image sur l'écran LCD
  // }
  // Test 3 : image "chiffre xxx" (faisant 16 pixels de large, sur 3 octets de haut soit 24 pixels)
  envoiUneCommandeAuNokia5510(0b10000000);      // X = 0
  envoiUneCommandeAuNokia5510(0b01000000 + 0);  // Y = 0 (1er octet du haut)
  for(byte j=0; j<16; j++) {
    envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_CHIFFRE_8 + (3*j+2)));    // Envoi de l'image sur l'écran LCD
  }
  envoiUneCommandeAuNokia5510(0b10000000);      // X = 0
  envoiUneCommandeAuNokia5510(0b01000000 + 1);  // Y = 1 (2ème octet, donc 8 pixels plus bas)
  for(byte j=0; j<16; j++) {
    envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_CHIFFRE_8 + (3*j+1)));    // Envoi de l'image sur l'écran LCD
  }
  envoiUneCommandeAuNokia5510(0b10000000);      // X = 0
  envoiUneCommandeAuNokia5510(0b01000000 + 2);  // Y = 2 (3ème octet, donc 16 pixels plus bas)
  for(byte j=0; j<16; j++) {
    envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_CHIFFRE_8 + (3*j+0)));    // Envoi de l'image sur l'écran LCD
  }
  

  // Désélection de l'écran Nokia 5110 (fin du transfert de données)
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, HIGH); // Par la mise au niveau haut de la ligne CE
}



















// ======================================
// Fonction : envoiUneCommandeAuNokia5510
// ======================================
// Permet d'envoyer un ordre (instruction) à l'afficheur LCD, pour qu'il l'exécute (par exemple : positionner curseur à tel ou tel endroit, régler contraste, ...)
void envoiUneCommandeAuNokia5510(byte commande) {
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, LOW);  // Activation de l'écran LCD (en mettant sa ligne CE à l'état bas)
  digitalWrite(sortieD6_ATmega328P_vers_brocheDC_ecranNokia, LOW);      // Passage en mode "commande" de l'écran LCD (ligne DC à 0)
  SPI.transfer(commande);                                               // Envoi des 8 bits de commande
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, HIGH); // Désélection de l'écran Nokia 5110, en ramenant sa ligne /SS à l'état haut
}


// =====================================
// Fonction : envoiDesDonneesAuNokia5510
// =====================================
// Permet d'envoyer des données à l'afficheur LCD (les pixels à afficher à l'écran, en fait)
void envoiDesDonneesAuNokia5510(byte donnees) { // Send data to display
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, LOW);  // Activation de l'écran LCD (en mettant sa ligne CE à l'état bas)
  digitalWrite(sortieD6_ATmega328P_vers_brocheDC_ecranNokia, HIGH);     // Passage en mode "données" de l'écran LCD (ligne DC à 1)
  SPI.transfer(donnees);                                                // Envoi des 8 bits de commande
  digitalWrite(sortieD10_SS_ATmega328P_vers_brocheCE_ecranNokia, HIGH); // Désélection de l'écran Nokia 5110, en ramenant sa ligne /SS à l'état haut
}


// ==============================
// Fonction : positionneLeCurseur
// ==============================
// Permet de positionner le curseur à la position souhaité
// (en sachant qu'on va de 1 en 1 sur l'axe X, et de 8 en 8 sur l'axe Y)
void positionneLeCurseur(byte posX, byte posY) {

  // Avec
  //   - posX : valeur entre 0 et 83, sur l'axe horizontal (on va de 1 en 1 pixel sur l'axe X)
  //   - posY : valeur entre 0 et 5, sur l'axe vertical (on va de 8 en 8 pixels sur l'axe Y)
  //
  //               REMARQUE IMPORTANTE:
  //                   L'axe Y de l'écran fait 48 pixels de haut (ce qui occupe donc 48 bits d'espace mémoire, au sein de l'écran).
  //                   Par contre, l'écran Nokia 5110 gère sa mémoire sous forme "d'octets" et non de "bits", sur l'axe Y. Ainsi,
  //                   ces 48 bits seront répartis sur 6 octets, ce qui nous donne bien 6x8 = 48 pixels. Cela explique pourquoi ici
  //                   la position_Y va de 0 à 5 (octets) dans ce cas, et non de 0 à 47 (bits).
    
  envoiUneCommandeAuNokia5510(0b10000000 + Xpos);                       // Saut à la position horizontale "Xpos" (exprimée en "pixels", pour ainsi dire)
  envoiUneCommandeAuNokia5510(0b01000000 + Ypos);                       // Saut à la position verticale "Ypos" (exprimée en "numéro de ligne de 8 pixels", en quelque sorte)

}


// =======================
// Fonction : effaceLecran
// =======================
// Permet d'effacer tous les pixels de l'écran (indispensable au démarrage, car l'écran Nokia 5110 peut afficher des pixels "allumés" par ci, par là !)
void effaceLecran() {

  // On se place "en haut/à gauche" de l'écran
  byte colonneX = 0;      // De 0 à 83, représentant nos 84 pixels de large, sur l'écran
  byte ligneY = 0;        // De 0 à 5, représentant nos 6 lignes de 8 pixels de haut, sur l'écran
  positionneLeCurseur(colonneX, ligneY);

  // Puis on efface les 504 octets de mémoire de l'afficheur LCD
  // Nota : l'écran faisant 84 pixels de large, sur 6 paquets de 8 pixels de haut, cela nous donne bien 84x6 soit 504 octets !
  for(int i=0; i < 504; i++) {
    envoiDesDonneesAuNokia5510(0x00);                                   // Mise à 0 préalable de tous les pixels de l'écran
  }

}


// ==================================
// Fonction : affichageBanniereEnHaut
// ==================================
void affichageBanniereEnHaut() {

  // On se place "en haut/à gauche" de l'écran
  byte colonneX = 0;      // De 0 à 83, représentant nos 84 pixels de large, sur l'écran
  byte ligneY = 0;        // De 0 à 5, représentant nos 6 lignes de 8 pixels de haut, sur l'écran
  positionneLeCurseur(colonneX, ligneY);

  // *********************************
  // Envoi de l'image "bannière haute"
  // *********************************
  // Nota : cette image fait :
  //   - 84 pixels de large (envoyés 1 par 1)
  //   - 16 pixels de haut (envoyés 8 par 8, donc répartis sur 2 x 8 bits, d'où les 2 envois séparés ci-dessous)
  for(byte j=0; j<84; j++) {
    envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_ENTETE + (2*j+1)));     // 8 bits "supérieurs" de notre image, sur 84 pixels de large
  }
  for(byte j=0; j<84; j++) {
    envoiDesDonneesAuNokia5510(pgm_read_byte_near(IMAGE_ENTETE + (2*j)));       // 8 bits "inférieurs" de notre image, sur 84 pixels de large
  }

}