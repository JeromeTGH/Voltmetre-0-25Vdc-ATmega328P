
// ================
// Liste des images
// ================
// 1) Chiffres 0 à 9
// 2) Image entête
// 3) Image mention Vdc


// ***********************************************
// 1) Chiffres 0 à 9
// Nota 1 : chaque chiffre fera 24 pixels de haut, répartis sur 3 octets (donc 3 x 8 bits = 24)     => d'où les 3 colonnes par chiffre ci-dessous
// Nota 2 : chaque chiffre fera 16 pixels de large                                                  => d'où les 16 lignes par chiffre ci-dessous
// ***********************************************

const byte IMAGE_CHIFFRE_0[] PROGMEM = {
  0b00011110, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00111111, 0b11100000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00110001, 0b11111111, 0b10000000,   // 3ème colonne de pixels de ce chiffre
  0b00110000, 0b00000111, 0b11111000,   // 4ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b01111100,   // 5ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00000000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11100000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11111111, 0b10001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_1[] PROGMEM = {
  0b00000000, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00000000, 0b00000000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 3ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 4ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 5ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 6ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 7ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 8ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 9ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 10ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00000000,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00000000, 0b00000000,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11100000, 0b00000000,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11111111, 0b10000000,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111000,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111100    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_2[] PROGMEM = {
  0b00011110, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00111111, 0b11100000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00110001, 0b11110000, 0b00000000,   // 3ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001000,   // 4ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 5ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00010000, 0b00011000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000000, 0b00001111, 0b10001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_3[] PROGMEM = {
  0b00010000, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00110000, 0b00000000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00110000, 0b00000000, 0b00000000,   // 3ème colonne de pixels de ce chiffre
  0b00110000, 0b00010000, 0b00001000,   // 4ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 5ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00011000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11111000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11101111, 0b10001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_4[] PROGMEM = {
  0b00000000, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00000000, 0b00000000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b10000000,   // 3ème colonne de pixels de ce chiffre
  0b00000000, 0b00001111, 0b11111000,   // 4ème colonne de pixels de ce chiffre
  0b00000000, 0b00011000, 0b01111100,   // 5ème colonne de pixels de ce chiffre
  0b00000000, 0b00011000, 0b00000000,   // 6ème colonne de pixels de ce chiffre
  0b00000000, 0b00011000, 0b00000000,   // 7ème colonne de pixels de ce chiffre
  0b00000000, 0b00011000, 0b00000000,   // 8ème colonne de pixels de ce chiffre
  0b00000000, 0b00011000, 0b00000000,   // 9ème colonne de pixels de ce chiffre
  0b00000000, 0b00011000, 0b00000000,   // 10ème colonne de pixels de ce chiffre
  0b00000000, 0b00011000, 0b00000000,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00011000, 0b00000000,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11111000, 0b00000000,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11101111, 0b10000000,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_5[] PROGMEM = {
  0b00010000, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00110000, 0b00000000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00110000, 0b00000111, 0b10000000,   // 3ème colonne de pixels de ce chiffre
  0b00110000, 0b00001111, 0b11111000,   // 4ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b01111100,   // 5ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00011000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11110000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11100000, 0b00001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_6[] PROGMEM = {
  0b00011110, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00111111, 0b11100000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00110001, 0b11110111, 0b10000000,   // 3ème colonne de pixels de ce chiffre
  0b00110000, 0b00011111, 0b11111000,   // 4ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b01111100,   // 5ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00011000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11110000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11100000, 0b00001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_7[] PROGMEM = {
  0b00000000, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00000000, 0b00000000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b10000000,   // 3ème colonne de pixels de ce chiffre
  0b00000000, 0b00001111, 0b11111000,   // 4ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111100,   // 5ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00000000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11100000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11111111, 0b10001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_8[] PROGMEM = {
  0b00011110, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00111111, 0b11100000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00110001, 0b11110111, 0b10000000,   // 3ème colonne de pixels de ce chiffre
  0b00110000, 0b00011111, 0b11111000,   // 4ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b01111100,   // 5ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00011000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11111000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11101111, 0b10001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_CHIFFRE_9[] PROGMEM = {
  0b00010000, 0b00000000, 0b00000000,   // 1ère colonne de pixels de ce chiffre (octet du bas, du milieu, puis du haut => 3 x 8 bits = 24 pixels de haut)
  0b00110000, 0b00000000, 0b00000000,   // 2ème colonne de pixels de ce chiffre
  0b00110000, 0b00000111, 0b10000000,   // 3ème colonne de pixels de ce chiffre
  0b00110000, 0b00001111, 0b11111000,   // 4ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b01111100,   // 5ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 6ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 7ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 8ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 9ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 10ème colonne de pixels de ce chiffre
  0b00110000, 0b00011000, 0b00001100,   // 11ème colonne de pixels de ce chiffre
  0b00111110, 0b00011000, 0b00001100,   // 12ème colonne de pixels de ce chiffre
  0b00011111, 0b11111000, 0b00001100,   // 13ème colonne de pixels de ce chiffre
  0b00000001, 0b11101111, 0b10001100,   // 14ème colonne de pixels de ce chiffre
  0b00000000, 0b00000111, 0b11111100,   // 15ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000, 0b01111000    // 16ème colonne de pixels de ce chiffre
};

const byte IMAGE_POINT_SEPARATEUR[] PROGMEM = {
  0b00110000,                           // 1ère colonne de pixels de ce symbole (sur un octet, donc 8 pixels de haut)
  0b00110000                            // 2ème colonne de pixels de ce symbole
};


// ****************************************************************
// 2) Image d'entête, qui sera affichée en haut de l'écran
// Nota : cette image fera 16 pixels de haut, sur 84 pixels de large (soit toute la largeur de l'écran)
// ****************************************************************
const byte IMAGE_ENTETE[] PROGMEM = {
  0b00000000, 0b00000000,     // 1ère colonne de pixels de ce chiffre (octet du bas, puis du haut => 2 x 8 bits = 16 pixels de haut)
  0b00000000, 0b00000000,     // 2ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 3ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 4ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 5ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 6ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 7ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 8ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 9ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 10ème colonne de pixels de ce chiffre
  0b00111111, 0b10001100,     // 11ème colonne de pixels de ce chiffre
  0b00111100, 0b00001100,     // 12ème colonne de pixels de ce chiffre
  0b00110000, 0b01111100,     // 13ème colonne de pixels de ce chiffre
  0b00110011, 0b11111100,     // 14ème colonne de pixels de ce chiffre
  0b00110000, 0b01111100,     // 15ème colonne de pixels de ce chiffre
  0b00111100, 0b00001100,     // 16ème colonne de pixels de ce chiffre
  0b00111111, 0b10001100,     // 17ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 18ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 19ème colonne de pixels de ce chiffre
  0b00111000, 0b00011100,     // 20ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 21ème colonne de pixels de ce chiffre
  0b00110111, 0b11101100,     // 22ème colonne de pixels de ce chiffre
  0b00110111, 0b11101100,     // 23ème colonne de pixels de ce chiffre
  0b00110111, 0b11101100,     // 24ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 25ème colonne de pixels de ce chiffre
  0b00111000, 0b00011100,     // 26ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 27ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 28ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 29ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 30ème colonne de pixels de ce chiffre
  0b00110111, 0b11111100,     // 31ème colonne de pixels de ce chiffre
  0b00110111, 0b11111100,     // 32ème colonne de pixels de ce chiffre
  0b00110111, 0b11101100,     // 33ème colonne de pixels de ce chiffre
  0b00111111, 0b11101100,     // 34ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 35ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 36ème colonne de pixels de ce chiffre
  0b00111111, 0b11101100,     // 37ème colonne de pixels de ce chiffre
  0b00111111, 0b11101100,     // 38ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 39ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 40ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 41ème colonne de pixels de ce chiffre
  0b00111111, 0b00011100,     // 42ème colonne de pixels de ce chiffre
  0b00111100, 0b01111100,     // 43ème colonne de pixels de ce chiffre
  0b00110000, 0b11111100,     // 44ème colonne de pixels de ce chiffre
  0b00111100, 0b01111100,     // 45ème colonne de pixels de ce chiffre
  0b00111111, 0b00011100,     // 46ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 47ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 48ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 49ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 50ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 51ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 52ème colonne de pixels de ce chiffre
  0b00110111, 0b01101100,     // 53ème colonne de pixels de ce chiffre
  0b00110111, 0b01101100,     // 54ème colonne de pixels de ce chiffre
  0b00110111, 0b01101100,     // 55ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 56ème colonne de pixels de ce chiffre
  0b00111111, 0b11101100,     // 57ème colonne de pixels de ce chiffre
  0b00111111, 0b11101100,     // 58ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 59ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 60ème colonne de pixels de ce chiffre
  0b00111111, 0b11101100,     // 61ème colonne de pixels de ce chiffre
  0b00111111, 0b11101100,     // 62ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 63ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 64ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 65ème colonne de pixels de ce chiffre
  0b00111111, 0b01101100,     // 66ème colonne de pixels de ce chiffre
  0b00111110, 0b01101100,     // 67ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 68ème colonne de pixels de ce chiffre
  0b00110001, 0b10011100,     // 69ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 70ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 71ème colonne de pixels de ce chiffre
  0b00110000, 0b00001100,     // 72ème colonne de pixels de ce chiffre
  0b00110111, 0b01101100,     // 73ème colonne de pixels de ce chiffre
  0b00110111, 0b01101100,     // 74ème colonne de pixels de ce chiffre
  0b00110111, 0b01101100,     // 75ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 76ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 77ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 78ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 79ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 80ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 81ème colonne de pixels de ce chiffre
  0b00111111, 0b11111100,     // 82ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000,     // 83ème colonne de pixels de ce chiffre
  0b00000000, 0b00000000      // 84ème colonne de pixels de ce chiffre
};


// ****************************************************************
// 3) Image mention "Vdc", qui sera affichée en bas à droite de l'écran
// Nota : cette image fera 8 pixels de haut, sur 15 pixels de large
// ****************************************************************
const byte IMAGE_MENTION_VDC[] PROGMEM = {
  0b00000110,     // 1ère colonne de pixels de ce chiffre (1 octet, représentant les 8 pixels de haut)
  0b00011000,     // 2ème colonne de pixels de ce chiffre
  0b00100000,     // 3ème colonne de pixels de ce chiffre
  0b00011000,     // 4ème colonne de pixels de ce chiffre
  0b00000110,     // 5ème colonne de pixels de ce chiffre
  0b00000000,     // 6ème colonne de pixels de ce chiffre
  0b00111110,     // 7ème colonne de pixels de ce chiffre
  0b00100010,     // 8ème colonne de pixels de ce chiffre
  0b00100010,     // 9ème colonne de pixels de ce chiffre
  0b00011100,     // 10ème colonne de pixels de ce chiffre
  0b00000000,     // 11ème colonne de pixels de ce chiffre
  0b00011100,     // 12ème colonne de pixels de ce chiffre
  0b00100010,     // 13ème colonne de pixels de ce chiffre
  0b00100010,     // 14ème colonne de pixels de ce chiffre
  0b00100010      // 15ème colonne de pixels de ce chiffre
};
