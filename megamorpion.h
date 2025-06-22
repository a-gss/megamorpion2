#pragma once

#define MORP_CONST        2     // hauteur d'une petite case + 1, toujours pair sinon on peut pas centrer les xo dans une case

/* SUR MAC-OS */
#define MORP_ENTER       10
#define MORP_ESCAPE      27
#define MORP_SPACE       32
#define MORP_VIRGULE     44
#define MORP_QUESTION    63
#define MORP_BACKSPACE  127

typedef struct grid_s{
    int hspacing;
    int vspacing;
    int hsize;
    int vsize;
} grid_t;

typedef struct vec2_s {
    int y;
    int x;
} vec2_t;

int screen_1(void);
int screen_2(int* size1, int* size2, char* buffer1, char* buffer2);
int screen_3(char* J1, char* J2);

/* FONCTION COMMUNE AUX 3 ECRANS ***********************************/
void print_header(int ch);