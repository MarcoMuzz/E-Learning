#ifndef _H_INCLUDED
#define _H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<conio.h>

#define MAXEMAIL 50
#define PASSWORD 20
#define MAXSIZE  100
#define DATABASE 1000




typedef struct data
{
    int giorno;
    int mese;
    int anno;
}data;

typedef struct studente
{
    char nome[MAXSIZE];
    char cognome[MAXSIZE];
    char genere[MAXSIZE];
    int  matricola;
    data data_nascita;
    char residenza[MAXSIZE];
    char email[MAXEMAIL];
    char password[PASSWORD];
    int  immatricolazione;
}studente;

typedef struct docente
{
    int id;
    char nome[MAXSIZE];
    char cognome[MAXSIZE];
    char password[PASSWORD];
}docente;

typedef struct insegnamento
{
     char identificativo[MAXSIZE];
     char nome_insegnamento[MAXSIZE];
     int anno_riferimento[2];
     char docente[MAXSIZE];
     int anno;
     int semestre;
     char password[PASSWORD];
     char ssd[MAXSIZE];
}insegnamento;

typedef struct materiale
{
    char identificativo[MAXSIZE];
    char nome[MAXSIZE];
    char tipo[MAXSIZE];
    char dimensioni[MAXSIZE];
    data data_caricamento;
}materiale;

typedef struct iscrizione
{
    int matricola;
    char identificativo[MAXSIZE];
}iscrizione;


typedef struct cronologia
{
    int matricola;
    char nome[MAXSIZE];
}cronologia;

#endif
