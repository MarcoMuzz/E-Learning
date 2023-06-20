#include "dichiarazioni.h"
#include "menu.h"

//Funzioni di scrittura su File
void scrivi_studenti(studente [],int);
void scrivi_insegnamenti(insegnamento [],int);
void scrivi_iscrizioni(iscrizione[],int);
void scrivi_materiale(materiale[],int);
void scrivi_cronologia(cronologia[],int);

//Funzioni di lettura da file
int carica_studenti(studente []);
int carica_docenti(docente []);
int carica_insegnamenti(insegnamento []);
int carica_materiale(materiale []);
int carica_iscrizioni(iscrizione []);
int carica_cronologia(cronologia []);

//Tutto il resto
void modifica_studente(int);
void iscrizione_insegnamento(int);
void stampa_insegnamenti(int , int []);
void gestione_iscrizioni(int);
void stampa_ssd();
void ricerca_file(int);
void upload(int);
void download(int);
void stampa_cronologia();
void registrazione();
void nascita(studente stud[], int );
int controllo_email(char [],studente [], int );
void stampa_decrescente();
void ordina_file(materiale*, int );





