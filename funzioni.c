#include "funzioni.h"
#include "dichiarazioni.h"

void scrivi_studenti(studente stud[], int n_stud){
    FILE *file;
    int i;
	    if((file = fopen("studenti.csv","w"))==NULL){
            puts("Errore nell'apertura dei file Studenti\n");
        }
    for(i=0; i<n_stud; i++){
        fprintf(file,"%d ;",stud[i].matricola);
        fprintf(file,"%s;",stud[i].email);
        fprintf(file,"%d ;",stud[i].immatricolazione);
        fprintf(file,"%s;",stud[i].nome);
        fprintf(file,"%s;",stud[i].cognome);
        fprintf(file,"%s;",stud[i].genere);
        fprintf(file,"%d/%d/%d ;",stud[i].data_nascita.giorno,stud[i].data_nascita.mese,stud[i].data_nascita.anno);
        fprintf(file,"%s;",stud[i].residenza);
        fprintf(file,"%s\n",stud[i].password);
    }
    fclose(file);

}

void scrivi_insegnamenti(insegnamento inseg[],int n_ins){
    FILE *file;
    int i;
	    if((file = fopen("insegnamenti.csv","w"))==NULL){
            puts("Errore nell'apertura del file Insegnamenti\n");
        }
    for(i=0; i<n_ins; i++){
        fprintf(file,"%s;",inseg[i].identificativo);
        fprintf(file,"%s;",inseg[i].nome_insegnamento);
        fprintf(file,"%d-%d ;",inseg[i].anno_riferimento[0],inseg[i].anno_riferimento[1]);
        fprintf(file,"%s;",inseg[i].docente);
        fprintf(file,"%d;",inseg[i].anno);
        fprintf(file,"%d;",inseg[i].semestre);
        fprintf(file,"%s;",inseg[i].password);
        fprintf(file,"%s\n",inseg[i].ssd);

    }
    fclose(file);
}

void scrivi_materiale (materiale mat[], int n_mat){
    FILE *file;
    int i;
	    if((file = fopen("materiale.csv","w"))==NULL){
            puts("Errore nell'apertura del file Materiale\n");
        }
    for(i=0; i<n_mat; i++){
        fprintf(file,"%s;",mat[i].nome);
        fprintf(file,"%s;",mat[i].tipo);
        fprintf(file,"%s;",mat[i].identificativo);
        fprintf(file,"%s;",mat[i].dimensioni);
        fprintf(file,"%d/%d/%d\n",mat[i].data_caricamento.giorno,mat[i].data_caricamento.mese,mat[i].data_caricamento.anno);
    }
    fclose(file);
}

void scrivi_iscrizioni(iscrizione iscr[],int n_iscr){
    FILE *file;
    int i;
	    if((file = fopen("iscrizioni.csv","w"))==NULL){
            puts("Errore nell'apertura del file Iscrizioni\n");
        }
    for(i=0; i<n_iscr; i++){
        fprintf(file,"%d ;",iscr[i].matricola);
        fprintf(file,"%s\n",iscr[i].identificativo);
        }
    fclose(file);
}

void scrivi_cronologia(cronologia crono[],int n_iscr){
    FILE *file;
    int i;
    if((file = fopen("cronologia.csv","w"))==NULL){
        puts("Errore nell'apertura del file Cronologia\n");
        }
    for(i=0; i<n_iscr; i++){
        fprintf(file,"%s;",crono[i].nome);
        fprintf(file,"%d\n",crono[i].matricola);

        }
    fclose(file);
}


int carica_studenti (studente stud[]){
    FILE *file;
    int i;
    if((file = fopen("studenti.csv","rb"))==NULL){
        puts("Errore nell'apertura del file Studenti\n");
        }

    for(i=0; !feof(file); i++){
        fflush(stdin);
        fscanf(file, "%d %*c", &stud[i].matricola);
        fscanf(file,"%[^;]%*c", stud[i].email);
        fscanf(file,"%d %*c", &stud[i].immatricolazione);
        fscanf(file,"%[^;]%*c", stud[i].nome);
        fscanf(file,"%[^;]%*c", stud[i].cognome);
        fscanf(file,"%[^;]%*c", stud[i].genere);
        fscanf(file,"%d%*c%d%*c%d %*c", &stud[i].data_nascita.giorno, &stud[i].data_nascita.mese, &stud[i].data_nascita.anno);
        fscanf(file,"%[^;]%*c", stud[i].residenza);
        fscanf(file,"%s ", stud[i].password);

    }
    fclose(file);
    return i;

}

int carica_docenti (docente doc[]){
    FILE *file;
    int i;
    if((file = fopen("docenti.csv","rb"))==NULL){
        puts("Errore nell'apertura del file Docenti\n");
        }

    for(i=0; !feof(file); i++){
        fscanf(file,"%d %*c",&doc[i].id);
        fscanf(file,"%[^;]%*c",doc[i].nome);
        fscanf(file,"%[^;]%*c",doc[i].cognome);
        fscanf(file,"%s ",doc[i].password);
    }
    fclose(file);
    return i;
}

int carica_insegnamenti (insegnamento inseg[]){
    FILE *file;
    int i;
    if((file = fopen("insegnamenti.csv","rb"))==NULL){
        puts("Errore nell'apertura del file Insegnamenti\n");
        }

    for(i=0; !feof(file); i++){
        fscanf(file,"%[^;]%*c",inseg[i].identificativo);
        fscanf(file,"%[^;]%*c",inseg[i].nome_insegnamento);
        fscanf(file,"%d%*c%d %*c",&inseg[i].anno_riferimento[0],&inseg[i].anno_riferimento[1]);
        fscanf(file,"%[^;]%*c",inseg[i].docente);
        fscanf(file,"%d %*c",&inseg[i].anno);
        fscanf(file,"%d %*c",&inseg[i].semestre);
        fscanf(file,"%[^;]%*c",inseg[i].password);
        fscanf(file,"%s ",inseg[i].ssd);
    }
    fclose(file);
    return i;
}

int carica_materiale(materiale mat[]){

    FILE *file;
    int i;
	    if((file = fopen("materiale.csv","rb"))==NULL){
        puts("Errore nell'apertura  del file Materiale\n");
        }

    for(i=0; !feof(file); i++){
        fflush(stdin);
        fscanf(file, "%[^;]%*c", mat[i].nome);
        fscanf(file, "%[^;]%*c", mat[i].tipo);
        fscanf(file, "%[^;]%*c", mat[i].identificativo);
        fscanf(file,"%[^;]%*c", mat[i].dimensioni);
        fscanf(file,"%d%*c%d%*c%d ",&mat[i].data_caricamento.giorno,&mat[i].data_caricamento.mese,&mat[i].data_caricamento.anno);
    }
    fclose(file);
    return i;
}

int carica_iscrizioni(iscrizione iscr[]){

    FILE *file;
    int i;
	    if((file = fopen("iscrizioni.csv","rb"))==NULL){
            puts("Errore nell'apertura del file Iscrizioni\n");
        }
    for(i=0; !feof(file); i++){
        fscanf(file, "%d %*c",&iscr[i].matricola);
        fscanf(file,"%s ",iscr[i].identificativo);
    }
    fclose(file);
    return i;

}

int carica_cronologia(cronologia crono[]){
    FILE *file;
    int i;
    if((file = fopen("cronologia.csv","rb"))==NULL){	///// Ricerca e apertura del file "Account"
        puts("Errore nell'apertura del file Cronologia\n");
        }

    for(i=0; !feof(file); i++){
        fscanf(file,"%[^;]%*c",crono[i].nome);
        fscanf(file,"%d ",&crono[i].matricola);
        }
    fclose(file);
    return i;
}

void registrazione(){
    char password[PASSWORD],email[MAXEMAIL]={""},buffer[MAXSIZE]={""};
    int flag=0;
    int anno_tmp;
    int scelta;
    int c=0;
    int ris=0;
    studente stud[DATABASE];
    int n_stud = carica_studenti(stud);
    do{
        system("cls");
        fflush(stdin);
        puts("Nome : ");
        gets(stud[n_stud].nome);
        fflush(stdin);
        puts("Cognome : ");
        gets(stud[n_stud].cognome);
        fflush(stdin);
                do{
                    strcpy(email,"");
                    strncat(email,stud[n_stud].nome,1);
                    strcat(email,".");
                    strcat(email,stud[n_stud].cognome);
                    if(ris>=1){
                        sprintf(buffer,"%d",ris+c);
                        strcat(email,buffer);
                        c++;
                    }
                    strcat(email,"@studenti.uniba.it");
                    ris=controllo_email(email,stud,n_stud);
                }while(ris!=0);
                do{
                    flag=0;
                    puts("\nMatricola : ");
                    fflush(stdin);
                    scanf("%d",&stud[n_stud].matricola);
                    for(int i=0; i<n_stud; i++){
                        if(stud[n_stud].matricola == stud[i].matricola){
                            printf("Matricola gia' presente in memoria");
                            flag=1;
                        }
                    }
                }while(stud[n_stud].matricola<100000 || stud[n_stud].matricola> 999999 || flag==1 );
                nascita(stud,n_stud);
                do{
                        puts("Anno di immatricolazione :");
                        scanf("%d",&anno_tmp);
                        if(anno_tmp > 1980 && anno_tmp <= 2020){
                                if( anno_tmp >= ( stud[n_stud].data_nascita.anno+18 ) ){
                                    flag=1;
                                    stud[n_stud].immatricolazione = anno_tmp;
                                }
                            }
                }while(flag!=1);
                do{
                    flag=0;
                    fflush(stdin);
                    printf("Sei un uomo o una donna?\n"
                            "1. Uomo\n"
                            "2. Donna\n"
                            "Scegli: ");
                    scanf("%d",&scelta);

                    switch(scelta){
                            case 1:
                                flag=1;
                                strcpy(stud[n_stud].genere,"M");
                                break;
                            case 2:
                                flag=1;
                                strcpy(stud[n_stud].genere,"F");
                                break;
                    }
                }while(flag!=1);

        fflush(stdin);
        puts("Inserisci la tua residenza: ");
        gets(stud[n_stud].residenza);
        flag=0;
        do{ fflush(stdin);
            printf("Inserisci la password.(Massimo 20 caratteri)\n");
            fgets(password,20,stdin);
                      fflush(stdin);
                      if(strlen(password)< 19){
                      strcpy(stud[n_stud].password,password);
                      flag=1;}
            else{
                printf("Password troppo lunga.");
            }
        }while(flag!=1);
                puts("Iscrizione avvenuta con successo\n");
                scrivi_studenti(stud,n_stud+1);
                system("pause");
                system("cls");
                menu_studenti(stud[n_stud].matricola);
                break;

    }while(scelta!=0);
}

int controllo_email(char email[],studente stud[], int n_stud){
    int i;
    for (i=0;i<n_stud;i++){
        if(strcasecmp(email, stud[i].email)==0){
            return 1;
        }
    }
    i=0;
    while(email[i]){
        putchar(tolower(email[i]));
        i++;
    }
    strcpy(stud[n_stud].email,email);
    return 0;
}

void modifica_studente(int matricola){
    studente stud[DATABASE];
    int n_stud = carica_studenti(stud);
    int i;
    int m;
    int flag=0;
    int anno_tmp;
    int scelta;
    int opzione;
    for(i=0 ; i < n_stud ; i++)
        {
        if( stud[i].matricola == matricola)
            {
            m = i;
            }
        }
     do
      {

          fflush(stdin);
          flag=0;
          puts("Scegli cosa modificare: \n");
          printf("1. Cognome: %s\n",stud[m].cognome);
          printf("2. Nome: %s\n",stud[m].nome);
          printf("3. Anno di Immatricolazione: %d\n",stud[m].immatricolazione);
          printf("4. Genere: %s\n",stud[m].genere);
          printf("5. Data di nascita: %d/%d/%d \n ",stud[m].data_nascita.giorno,stud[m].data_nascita.mese,stud[m].data_nascita.anno);
          printf("6. Residenza: %s\n",stud[m].residenza);
          printf("7. Password: %s\n",stud[m].password);
          printf("0. Esci.\n");
          printf("Scegli: ");
          scelta=getchar();
          switch(scelta){
                case  '1':
                    fflush(stdin);
                    puts("Cognome : \n");
                    gets(stud[m].cognome);
                    break;
                case  '2':
                    fflush(stdin);
                    puts("Nome : \n");
                    gets(stud[m].nome);
                    break;
                case  '3':
                    do{
                        puts("Anno d'immatricolazione: \n");
                        scanf("%d",&anno_tmp);
                        printf("%d",anno_tmp);
                        if(anno_tmp > 1989 || anno_tmp <= 2020){
                                if( anno_tmp >= ( stud[m].data_nascita.anno+18 ) ){
                                    flag=1;
                                    stud[m].immatricolazione = anno_tmp;
                                }
                        }
                    }while(flag!=1);
                    break;
                case '4':
                    do{     fflush(stdin);
                            printf("Uomo o donna?\n"
                                   "1. Uomo\n"
                                   "2. Donna\n"
                                   "0. Esci\n"
                                   "Scegli:");
                            scanf("%d",&opzione);

                            switch(opzione)
                            {
                                case 1:

                                    strcpy(stud[m].genere,"M");
                                    break;
                                case 2:
                                    strcpy(stud[m].genere,"F");
                                    break;
                            }
                        }while(opzione!=0);
                            break;
                case '5':
                    do{
                        nascita(stud,m);
                            if( stud[m].data_nascita.anno <= ( stud[m].immatricolazione-18 ) ){
                                flag=1;
                            }
                    }while(flag!=1);
                    break;
                case '6':
                    fflush(stdin);
                    puts("Residenza\n");
                    gets(stud[m].residenza);
                    break;
                case '7':
                    fflush(stdin);
                    int flagp=0;
                    char* newpass[PASSWORD];
                    do{
                      printf("Inserisci la nuova password.(Massimo 20 caratteri)\n");
                      fgets(newpass,19,stdin);
                      fflush(stdin);
                      if(strlen(newpass)< 19){
                      strcpy(stud[m].password,newpass);
                      flagp=1;}
                    }while(flagp!=1);
                    break;
          }

    }while(scelta!='0');
        scrivi_studenti(stud,n_stud);
        return;
    }

void iscrizione_insegnamento(int matricola){
    int i;
    int scelta;
    int flag;
    iscrizione iscr[DATABASE];
    insegnamento inseg[DATABASE];
    char buffer[MAXSIZE], password[MAXSIZE];
    int n_ins = carica_insegnamenti(inseg);
    int n_iscr = carica_iscrizioni(iscr);
    do{
        flag=0;
        system("cls");
        printf("A quale insegnamento vuoi iscriverti?\n");
        for(i=0; i< n_ins; i++){
            printf("%d. Nome: %s\n",i+1,inseg[i].nome_insegnamento);
        }
        printf("0. Esci.\n"
               "Scegli:\n ");
        fflush(stdin);
        gets(buffer);
        scelta=atoi(buffer);
        system("cls");
        if(scelta!=0){
            for (i=0;i<n_iscr;i++){
                int check = strcasecmp( iscr[i].identificativo,inseg[scelta-1].identificativo );
                if( iscr[i].matricola == matricola )
                {
                    if( (check=strcasecmp( iscr[i].identificativo,inseg[scelta-1].identificativo ) ) == 0 ){
                      puts("Sei gia' registrato.\n");
                        system("pause");
                        system("cls");
                        return;
                    }

                }
            }
            printf("Digita la Password: %s\n",inseg[scelta-1].nome_insegnamento);
            gets(password);
            printf("Password Inserita: %s \n",password);
            if(strcmp(password,inseg[scelta-1].password)== 0){
                flag=1;
                iscr[n_iscr].matricola= matricola;
                strcpy(iscr[n_iscr].identificativo,inseg[scelta-1].identificativo);
                printf("Iscrizione effettuata.\n");
                scrivi_iscrizioni(iscr,n_iscr+1);
                return;
            }else{
                printf("Password errata!\n\n\n");
                return;
            }
        }else{
            return;
        }
        }while(flag!=1);
}

void stampa_insegnamenti(int matricola, int vett[]){
    int i,j;
    int c=0;
    int flag;
    iscrizione iscr[DATABASE];
    insegnamento inseg[DATABASE];
    int n_ins = carica_insegnamenti(inseg);
    int n_isc = carica_iscrizioni(iscr);
    printf("Ecco la lista degli insegnamenti a cui sei iscritto:\n\n");
    for(i=0; i<n_isc; i++){
        if(iscr[i].matricola==matricola){
                for(j=0; j< n_ins; j++){

                    if( strcasecmp(iscr[i].identificativo,inseg[j].identificativo)==0 )
                    {
                            printf("%d.  \t\t %s\n\n",c+1,inseg[j].nome_insegnamento);
                            vett[c]=i;
                            c++;
                            flag=1;
                    }
                                        }
                                        }


    }
    if(flag==1){
        return;
    }else{
        printf("Non sei iscritto.\n");
        system("pause");
        return;
    }
}

void gestione_iscrizioni(int cod){
    int i=0,k;
    int c=0;
    int flag=0;
    int pos[MAXSIZE];
    int scelta;
    char nome_doc[MAXSIZE]={""};
    iscrizione iscr[DATABASE];
    insegnamento inseg[DATABASE];
    docente doc[DATABASE];
    int n_ins = carica_insegnamenti(inseg);
    int n_isc = carica_iscrizioni(iscr);
    carica_docenti(doc);
    iscrizione isc_tmp[DATABASE];
    if(cod < 100000){
        strcat(nome_doc,doc[cod-1].nome);
        strcat(nome_doc," ");
        strcat(nome_doc,doc[cod-1].cognome);
        printf("Ecco la lista dei tuoi insegnamenti:\n");
        for(i=0;i<n_ins;i++){

            if(strcasecmp(nome_doc,inseg[i].docente)==0 ){
                printf("-%d. %s\n",c+1,inseg[i].nome_insegnamento);
                pos[c]=i;
                c++;
            }
        }
        do{
           printf("A quale insegnamento vuoi accedere? ");
           scanf("%d",&scelta);
           k=pos[scelta-1];
        }while(scelta<0 || scelta>c);
        if(scelta!=0){
            c=0;
            printf("Ecco le matricole iscritte al tuo insegnamento\n");
            for(i=0;i<n_isc; i++){
                if( strcasecmp(iscr[i].identificativo,inseg[k].identificativo)==0){
                    printf("-%d Matricola: %d\n",c+1,iscr[i].matricola);
                    pos[c]=i;
                    c++;
                }
            }
            printf("A quale matricola vuoi rimuovere l'iscrizione al tuo insegnamento?(Inserisci 0 se non ci sono matricole)");
            scanf("%d",&k);
            if(k>1 || k<=c){
                k=pos[k-1];
                c=0;
                for(i=0;i<n_isc;i++){
                    if( iscr[i].matricola == iscr[k].matricola && strcasecmp(iscr[i].identificativo,iscr[k].identificativo)==0){
                        flag=1;
                    }else{
                        isc_tmp[c]=iscr[i];
                        c++;
                    }
                }
            }
        }
    }else{
        stampa_insegnamenti(cod,pos);
        printf("Scegli: ");
        scanf("%d",&k);
        k = pos[k-1];
        for(i=0; i<n_isc;i++){
            if( i!=k ){
                isc_tmp[c]=iscr[i];
                c++;
            }else{
                flag=1;
            }
        }

    }
    if(flag==1){
        scrivi_iscrizioni(isc_tmp,c);
        printf("Iscrizione rimossa.\n");
        system("pause");
        return;
    }else{
        printf("Errore.\n");
        system("pause");
        return;
    }
}

void stampa_ssd(){
    int i=0,scelta;
    int flag=0;
    int opzione;
    char *settore[]={"INF/01","ING-INF/05","MAT/02","MAT/05","MAT/06","MAT/08","FIS/01","L-LIN/12","IUS/20"};
    insegnamento inseg[DATABASE];
    int n_ins = carica_insegnamenti(inseg);
    do{
        flag=0;
        system("cls");
        printf("Salve puoi indicare che tipo di ricerca vuoi effettuare?\n"
               "1.Per semestre.\n"
               "2.Per settore disciplinare.\n"
               "Scegli: ");
        scanf("%d",&scelta);
        switch(scelta){
            case 1:
                do{
                   system("cls");
                   printf("Puoi indicarmi per quale semestre vuoi vedere gli insegnamenti?\n"
                          "1.Primo Semestre.\n"
                          "2.Secondo Semestre.\n"
                          "Scegli: ");
                   scanf("%d",&opzione);
                }while(opzione>2 ||opzione<1);
                for(i=0; i<n_ins;i++){
                    if(inseg[i].semestre == opzione){
                        printf("////////////////////////////////////////////////////////////\n"
                               "Identificativo: %s"
                                "\nNome insegnamento: %s"
                                "\nSettore disciplinare: %s\n"
                                "\nAnno di riferimento: %d-%d"
                                "\nNome: %s"
                                "\nAnno:%d\nSemestre: %d\n", inseg[i].identificativo,inseg[i].nome_insegnamento,inseg[i].ssd,inseg[i].anno_riferimento[0],
                                inseg[i].anno_riferimento[1],inseg[i].docente,
                                inseg[i].anno,inseg[i].semestre);
                        flag=1;
                    }
                }
                system("pause");
                return;
                break;
            case 2:
                do{
                    for(i=0;i< 9;i++){
                        printf("%d. %s\n",i+1,settore[i]);
                    }
                    printf("Scegli: ");
                    scanf("%d",&opzione);
                }while(opzione<0 || opzione>n_ins);
                for(i=0;i<n_ins;i++){
                    if( strcasecmp(settore[opzione-1], inseg[i].ssd) ==0){
                        printf("////////////////////////////////////////////////////////////\n"
                               "Identificativo: %s"
                                "\nNome insegnamento: %s"
                                "\nSettore disciplinare: %s\n"
                                "\nAnno di riferimento: %d-%d"
                                "\nNome: %s"
                                "\nAnno:%d\nSemestre: %d\n" , inseg[i].identificativo,inseg[i].nome_insegnamento,inseg[i].ssd,inseg[i].anno_riferimento[0],
                                inseg[i].anno_riferimento[1],inseg[i].docente,
                                inseg[i].anno,inseg[i].semestre);
                        flag=1;
                    }
                }
                system("pause");
                return;
                break;

        }
    }while(flag!=1);
    return;
}

void ricerca_file(int id){
    int i=0,k;
    int flag=0;
    int pos[MAXSIZE];
    int scelta;
    iscrizione iscr[DATABASE];
    insegnamento inseg[DATABASE];
    materiale mat[DATABASE];
    int n_mat = carica_materiale(mat);
    int n_ins = carica_insegnamenti(inseg);
    carica_iscrizioni(iscr);
    if(id < 100000){
        printf("Di quale insegnamento vuoi visionare i file caricati?\n");
        do{
            for(i=0; i<n_ins; i++){
                printf("-%d %s\n",i+1,inseg[i].nome_insegnamento);
            }
            printf("Scegli: ");
            scanf("%d",&scelta);
        }while(scelta<=0 || scelta > n_ins);
        for(i=0; i<n_mat; i++){
            if( strcasecmp(mat[i].identificativo,inseg[scelta-1].identificativo)==0){
               printf("///////////////////////////////////////////////////\n"
                      "Nome file: %s\n"
                      "Dimensione: %s\n"
                      "Data di caricamento: %d/%d/%d\n",mat[i].nome,mat[i].dimensioni,mat[i].data_caricamento.giorno,
                      mat[i].data_caricamento.mese,mat[i].data_caricamento.anno);
                flag=1;
               }
        }
    }else{
        stampa_insegnamenti(id,pos);
        printf("\nScegli: ");
        scanf("%d",&k);
        k = pos[k-1];
        for(i=0; i<n_mat; i++){
            if( strcasecmp(mat[i].identificativo,iscr[k].identificativo)==0){
               printf("///////////////////////////////////////////////////////\n"
                      "Nome file: %s\n"
                      "Dimensione: %s\n"
                      "Data di caricamento: %d/%d/%d\n",mat[i].nome,mat[i].dimensioni,mat[i].data_caricamento.giorno,
                      mat[i].data_caricamento.mese,mat[i].data_caricamento.anno);
                flag=1;
               }
        }

    }
    if(flag==1){
        system("pause");
        return;
    }else{
        printf("Non è stato aggiunto alcun tipo di materiale per questo insegnamento.\n\n\n");
        system("pause");
        system("cls");
        return;
    }
}

void upload(int id){
    int i=0,k;
    int pos[MAXSIZE];
    int scelta=0;
    int c=0;
    char nome_doc[MAXSIZE]={""};
    time_t t = time(NULL);
    struct tm data= *localtime(&t);
    materiale mat[DATABASE];
    int n_mat = carica_materiale(mat);
    docente doc[DATABASE];
    carica_docenti(doc);
    insegnamento inseg[DATABASE];
    int n_ins = carica_insegnamenti(inseg);
    strcat(nome_doc,doc[id-1].nome);
    strcat(nome_doc," ");
    strcat(nome_doc,doc[id-1].cognome);
    printf("Ecco la lista dei tuoi insegnamenti:\n");
    for(i=0;i<n_ins;i++){
        if(strcasecmp(nome_doc,inseg[i].docente)==0 ){
            printf("-%d. %s\n",c+1,inseg[i].nome_insegnamento);
            pos[c]=i;
            c++;
        }
    }
    if(c>0){
        do{
            printf("Di quale insegnamento è il materiale che vuoi caricare sulla piattaforma?");
            scanf("%d",&scelta);
            k=pos[scelta-1];
        }while(scelta<0 || scelta>c);
        if(scelta!=0){
            fflush(stdin);
            printf("Nome del File:");
            gets(mat[n_mat].nome);
            fflush(stdin);
            printf("Estensione del File:");
            gets(mat[n_mat].tipo);
            strcpy(mat[n_mat].identificativo,inseg[k].identificativo);
            fflush(stdin);
            printf("Dimensione del File:");
            gets(mat[n_mat].dimensioni);
            mat[n_mat].data_caricamento.anno= data.tm_year+1900;
            mat[n_mat].data_caricamento.mese = data.tm_mon +1;
            mat[n_mat].data_caricamento.giorno = data.tm_mday;
            scrivi_materiale(mat,n_mat+1);
            puts("Upload eseguito.\n");
    }
    }else{
        printf("Non ci sono insegnamenti.\n\n");
        return;
    }
    return;
}

void download(int matricola){
    int i=0,k;
    int flag=0;
    int pos[MAXSIZE];
    int scelta=0;
    int c;
    iscrizione iscr[DATABASE];
    materiale mat[DATABASE];
    cronologia crono[DATABASE];
    int n_cron = carica_cronologia(crono);
    int n_mat = carica_materiale(mat);
    carica_iscrizioni(iscr);
    do{
        stampa_insegnamenti(matricola,pos);
        printf("Scegli: ");
        scanf("%d",&k);
        k = pos[k-1];
        c=0;
        for(i=0; i<n_mat; i++)
        {
            if( strcasecmp(mat[i].identificativo,iscr[k].identificativo)==0){
               printf("/////////File Numero %d//////////\n"
                      "Nome file: %s\n"
                      "Dimensione: %s\n"
                      "Data Caricamento: %d/%d/%d\n",c+1,mat[i].nome,mat[i].dimensioni,mat[i].data_caricamento.giorno,
                      mat[i].data_caricamento.mese,mat[i].data_caricamento.anno);
                      pos[c]=i;
                      c++;
                flag=1;
               }
        }
        if(flag==0){
        printf("Non ci sono file caricati per questo insegnamento.\n\n");
        return;
        }
        do{
           printf("\nQuale file vuoi scaricare?");
           scanf("%d",&scelta);
           k=pos[scelta-1];
        }while(scelta<0 || scelta>c);
            if(k >=0 || k < c){
                crono[n_cron].matricola = matricola;
                strcpy(crono[n_cron].nome,mat[k].nome);
                scrivi_cronologia(crono,n_cron+1);
            printf("\nDownload effettuato.\n\n");
                return;
            }

    }while(k < 0 || k > n_mat);
    return;
}

void stampa_cronologia(){
    int i;
    cronologia crono[DATABASE];
    int n_crono=carica_cronologia(crono);
    puts("Ecco la lista delle matricole che hanno effettuato dei download sulla piattaforma\n");
        for(i=0;i<n_crono;i++){
        printf("%d.%d \t %s\n",i+1,crono[i].matricola,crono[i].nome);
        }
    system("pause");
    system("cls");
return;
}


void nascita(studente stud[], int pos){

    do{ fflush(stdin);
        printf("In che anno sei nato? ");
        scanf("%d",&stud[pos].data_nascita.anno);
    }while( stud[pos].data_nascita.anno<1900 || stud[pos].data_nascita.anno>2001);

    do{ fflush(stdin);
        printf("In che mese sei nato(1-12): ");
        scanf("%d",&stud[pos].data_nascita.mese);
    }while(stud[pos].data_nascita.mese < 1 || stud[pos].data_nascita.mese >12);

	if(stud[pos].data_nascita.mese==4||stud[pos].data_nascita.mese==6||stud[pos].data_nascita.mese==9||stud[pos].data_nascita.mese==11){
		do{ fflush(stdin);
			printf("In quale giorno?(1-30): ");
			scanf("%d",& stud[pos].data_nascita.giorno);
		}while( stud[pos].data_nascita.giorno==0|| stud[pos].data_nascita.giorno>30);
	}
	else if(stud[pos].data_nascita.mese==2){
			do{ fflush(stdin);
				printf("In quale giorno?(1-28/29 se bisestile): ");
				scanf("%d",& stud[pos].data_nascita.giorno);
			}while( stud[pos].data_nascita.giorno==0|| stud[pos].data_nascita.giorno>29);
		}
		else{
		do{ fflush(stdin);
			printf("In quale giorno?(1-31): ");
			scanf("%d",& stud[pos].data_nascita.giorno);
		}while( stud[pos].data_nascita.giorno==0|| stud[pos].data_nascita.giorno>31);
	}
}



void stampa_decrescente(){
        int i=0,n_mat;
        materiale *mat=(materiale*)calloc(MAXSIZE,sizeof(materiale));
        n_mat=carica_materiale(mat);
        ordina_file(mat,n_mat);
        puts("Materiale didattico in ordine di data decrescente. \n");
        for(i=0;i<n_mat;i++)
        {
            printf("%d.%s,%s,%s,%s,%d/%d/%d\n",i+1,mat[i].nome,mat[i].tipo,mat[i].identificativo,mat[i].dimensioni,
                   mat[i].data_caricamento.giorno,mat[i].data_caricamento.mese,mat[i].data_caricamento.anno);
        }
        free(mat);
        system("pause");
        system("cls");
}

void ordina_file(materiale*mat, int size){
    materiale temp;
    int i,j;
    for(j=0;j<size-1;j++)
    { for(i=0;i<size-1;i++)
        { if(mat[i].data_caricamento.anno<mat[i+1].data_caricamento.anno)
          { temp=mat[i];
            mat[i]=mat[i+1];
            mat[i+1]=temp;
          }
        }
    }
    for(j=0;j<size-1;j++)
    { for(i=0;i<size-1;i++)
        { if(mat[i].data_caricamento.anno==mat[i+1].data_caricamento.anno&&mat[i].data_caricamento.mese<mat[i+1].data_caricamento.mese)
          { temp=mat[i];
            mat[i]=mat[i+1];
            mat[i+1]=temp;
          }
        }
    }
     for(j=0;j<size-1;j++)
    {  for(i=0;i<size-1;i++)
        { if(mat[i].data_caricamento.mese==mat[i+1].data_caricamento.mese && mat[i].data_caricamento.anno==mat[i+1].data_caricamento.anno&&mat[i].data_caricamento.giorno<mat[i+1].data_caricamento.giorno)
         { temp=mat[i];
           mat[i]=mat[i+1];
           mat[i+1]=temp;
         }
        }
    }
}






