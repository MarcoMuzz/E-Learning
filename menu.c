#include "menu.h"
#include "funzioni.h"
void home_page()
{
    int scelta;
    int flag=0;
    do
    {
        system("cls");
        puts("//////////////////////////////////////////////////////////\n"
             "//////////BENVENUTO NELLA PIATTAFORMA E-LEARNING//////////\n"
             "//////////////////////////////////////////////////////////\n"
            );
        fflush(stdin);
        flag=0;
        puts("1: ACCEDI\n"
             "2: REGISTRATI\n"
             "0: Esci\n");
        scanf("%d",&scelta);
        switch(scelta)
        {
        case 1:
            system("cls");
            bivio_studoc();
            home_page();
            break;
        case 2:
            system("cls");
            registrazione();
            break;
        case 0 :
            exit(0);
        default :
            puts("Scelta invalida.");
            system("pause");
            home_page();
        }

    }while (flag!=1);
}


void bivio_studoc()
{
    int scelta;
    int flag=0;
    do
    {
        fflush(stdin);
        flag = 0;
        puts("Effettua una scelta\n"
             "1 Accedi come Studente.\n"
             "2 Accedi come Docente.\n"
             "0 Esci.\n");
        scanf("%d",&scelta);
        switch(scelta)
        {
        case 1:
            system("cls");
            accesso_studenti();
            break;

        case 2 :
            system("cls");
            accesso_docenti();
            break;
        case 0 :
            system("cls");
            return;
        default:
            puts("Scelta non riconosciuta\n");
            flag=1;

        }

    }while(flag!=1);
}

void accesso_studenti(){

    char buffer[MAXSIZE] , password[PASSWORD];
    int flag;
    int i=0;
    int matricola;
    studente stud[DATABASE];
    int  n_stud=carica_studenti(stud);
    puts("Effettua l'accesso\n");
    do{
        flag=0;
        puts("Matricola: \n");
        gets(buffer);
        matricola=atoi(buffer);
        fflush(stdin);
        puts("Password: \n");
        gets(password);
        for(i=0; i<n_stud;i++){
            if( stud[i].matricola == matricola){
                if( strcmp ( password , stud[i].password )==0 ){
                    system("cls");
                    puts("///////////////////////MENU' STUDENTE/////////////////////////\n");
                    menu_studenti(matricola);
                    flag=1;
                }else{
                    puts("La Password è errata.\n");
                    break;
                    }
                }
        }
}while(flag==0);
}


void menu_studenti(int matricola){
    int vett[DATABASE];
    int scelta;
    int flag=0;
    do{
      fflush(stdin);
      puts("1.Modifica i tuoi dati\n"
           "2.Mostra insegnamenti di un dato semestre o SSD\n"
           "3.Iscriviti ad un insegnamento\n"
           "4.Rimuovi la tua iscrizione da un insegnamento.\n"
           "5.Ricerca i file di un insegnamento\n"
           "6.Scarica i file da un insegnamento\n"
           "7.Mostra gli insegnamenti a cui sei iscritto\n"
           "8.Mostra i files caricati sulla piattaforma in ordine decrescente rispetto alla data di upload\n"
           "0.Esci");
        scanf("%d",&scelta);
        switch(scelta)
        {
            case 1:
                system("cls");
                modifica_studente(matricola);
                system("pause");
                break;

            case 2:
                system("cls");
                stampa_ssd();
                break;

            case 3:
                system("cls");
                iscrizione_insegnamento(matricola);
                break;
            case 4:
                system("cls");
                gestione_iscrizioni(matricola);
                break;
            case 5:
                system("cls");
                ricerca_file(matricola);
                break;
            case 6:
                system("cls");
                download(matricola);
                break;
            case 7:
                system("cls");
                stampa_insegnamenti(matricola,vett);
                break;
             case 8:
                system("cls");
                stampa_decrescente();
                break;
            case 0:
                system("cls");
                home_page();
            default:
                puts("\n\nScelta invalida\n");
                break;
        }
    }while(flag!=1);
}

void accesso_docenti(){

    docente doc[DATABASE];
    int n_doc=carica_docenti(doc);
    char buffer[MAXSIZE] , password[PASSWORD];
    int flag;
    int i;
    int identificatore;
    puts("Effettua l'accesso\n");

    do{
        flag=0;
        fflush(stdin);
        puts("Codice Identificativo: \n");
        gets(buffer);
        identificatore=atoi(buffer);
        fflush(stdin);
        puts("Password: \n");
        gets(password);

        for(i=0; i<n_doc;i++){

            if( doc[i].id == identificatore){
                if( strcmp ( password , doc[i].password )==0 ){
                    system("cls");
                    puts("///////////////////////MENU' DOCENTI/////////////////////////\n");
                    menu_docenti(identificatore);
                    flag=1;
                }else{
                    puts("Password errata\n");
                    break;
                    }
                }
        }

    }while(flag==0);
}

void menu_docenti(int id)
{

    char scelta;
    int flag=0;
    do
    {
        fflush(stdin);
        flag=0;
        puts("1. Carica un file\n"
             "2. Rimuovi l'iscrizione di uno studente al tuo insegnamento\n"
             "3. Mostra insegnamenti di un semestre o SSD\n"
             "4. Ricerca di un file d'insegnamento\n"
             "5. Mostra i files caricati sulla piattaforma in ordine decrescente rispetto alla data di upload\n"
             "6. Visualizza la lista delle matricole che hanno effettuato dei download dalla piattaforma\n"
             "0. Esci");
            scelta=getchar();
            switch(scelta)
            {
            case '1':
                system("cls");
                upload(id);
                break;
            case '2':
                system("cls");
                gestione_iscrizioni(id);
                break;

            case '3':
                system("cls");
                stampa_ssd();
                break;
            case '4':
                system("cls");
                ricerca_file(id);
                break;
            case '5':
                system("cls");
                stampa_decrescente();
                break;
            case '6':
                system("cls");
                stampa_cronologia();
                break;
            case '0':
                system("cls");
                home_page();
            default:
                system("cls");
                printf("Scelta invalida.\n");
                break;
            }
    }while(flag!=1);
}


