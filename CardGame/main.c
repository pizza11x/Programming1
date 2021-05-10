#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Dichiarazioni dei tipi, delle struct e delle variabili globali.
typedef enum{spade,coppe,denari,bastoni}Semi; //Definisco un nuovo tipo enumerativo per i semi spagnoli delle carte.
struct carta{
    int valore;
    Semi seme;
}; //Dichiaro un nuovo tipo strutturato per le carte.
typedef struct carta Carta; //Definisco un nuovo tipo "Carta" per il mazzo napoletano.
Carta *pcarta; //Variabile globale puntatore di un tipo Carta.

//Elenco dei prototipi delle function e procedure:
void riempi_mazzo(Carta *mazzo_napoletano,int n_carte); //Parametri: indirizzo base del mazzo.
void stampa_mazzo(Carta *mazzo,int n_carte); //Parametri: indirizzo base del mazzo, numero di carte da stampare.
void mischia_mazzo(Carta *mazzo_napoletano,int n_carte,int n_mischiate); //Parametri: indirizzo base del mazzo, numero di carte, numero di mischiate.
int scelta_turno(char *giocatore1,char *giocatore2); //Parametri: indirizzo base dei nomi dei due giocatori.
int gioco_coppie(Carta *mazzo_napoletano,int n_carte,int turno_giocatore,char *giocatore1,char *giocatore2); //Parametri: indirizzo base del mazzo, numero di carte, valore numerico di chi inizia il primo turno, ed indirizzi base dei nomi dei giocatori.
void escludi_carta(Carta *mazzo_napoletano,int indice1,int indice2,int n_carte); //Parametri: indirizzo base del mazzo, i due indici da escludere, numero di carte.
int cambio_turno(int turno_giocatore); //Parametri: turno del giocatore attuale.
void stampa_vincitore(int vincitore,char *giocatore1,char *giocatore2); //Parametri: numero del vincitore, indirizzo base dei nomi dei due giocatori.

int main()
{
    //Dichiarazioni ed inizializzazioni delle variabili:
    Carta mazzo_napoletano[40];
    char giocatore1[50];
    char giocatore2[50];
    int n_carte, n_mischiate, i,j;
    int turno_giocatore; //Variabile che indica il turno del giocatore.
    int vincitore; //Variabile che indica quale giocatore ha vinto.
    n_carte=40;
    srand(time(NULL));
    //Corpo del main:
    printf("                                   ---Questo e' il gioco delle coppie!---\n");
    printf("-Inserire il nome del giocatore1: ");
    gets(giocatore1);
    printf("\n-Inserire il nome del giocatore2: ");
    gets(giocatore2);
    riempi_mazzo(&mazzo_napoletano,n_carte); //Argomenti: indirizzo base del mazzo.
    stampa_mazzo(&mazzo_napoletano,n_carte); //Argomenti: indirizzo base del mazzo, numero di carte da stampare.
    printf("\n-Quante volte deve essere mischiato il mazzo?\n");
    scanf("%d",&n_mischiate);
    mischia_mazzo(&mazzo_napoletano,n_carte,n_mischiate); //Argomenti: indirizzo base del mazzo, numero di carte, numero di mischiate.
    printf("\nIl mazzo mischiato adesso e':\n");
    stampa_mazzo(&mazzo_napoletano,n_carte); //Argomenti: indirizzo base del mazzo, numero di carte da stampare.
    //Viene inizializzata la variabile per individuare quale giocatore inizia il gioco.
    turno_giocatore=scelta_turno(&giocatore1,&giocatore2); //Argomenti: indirizzo base dei nomi dei due giocatori.
    //Viene inizializzata la variabile per indicare quale dei due giocatori ha vinto.
    vincitore=gioco_coppie(&mazzo_napoletano,n_carte,turno_giocatore,&giocatore1,&giocatore2); //Argomenti: indirizzo base del mazzo, numero di carte, valore numerico di chi inizia il primo turno, ed indirizzi base dei nomi dei giocatori.
    //Stampa il vincitore:
    stampa_vincitore(vincitore,&giocatore1,&giocatore2); //Argomenti: numero del vincitore, indirizzo base dei nomi dei giocatori.

    return 0;
}

//Procedura per attribuire ad ogni elemento dell'array una carta:
void riempi_mazzo(Carta *mazzo_napoletano,int n_carte)
{
    int i;
    int val=1; //Variabile di aiuto per attribuire un valore alla carta.
    pcarta=mazzo_napoletano; //Pcarta punta all'indirizzo base di mazzo_napoletano.
    //Corpo della Procedura:
    for(i=0;i<n_carte;i++) //For per il riempimento dell'array.
    {
        if(i==10 || i==20 || i==30) //Controllo del contatore per riportare il valore che deve assumere la carta ad 1.
            val=1;
        if(i<10) //Se il contatore assume un valore minore di 10:
        {
            (pcarta+i)->valore=val++; //Viene assegnato in ordine crescente un valore da 1 a 10.
            (pcarta+i)->seme=spade; //Viene assegnato il seme spade.
        }
        else if(i>=10 && i<20) //Se il contatore assume un valore tra 10 e 20:
        {
            (pcarta+i)->valore=val++; //Viene assegnato in ordine crescente un valore da 1 a 10.
            (pcarta+i)->seme=coppe; //Viene assegnato il seme coppe.
        }
        else if(i>=20 && i<30) //Se il contatore assume un valore tra 20 e 30:
        {
            (pcarta+i)->valore=val++; //Viene assegnato in ordine crescente un valore da 1 a 10.
            (pcarta+i)->seme=denari; //Viene assegnato il seme denari.
        }
        else if(i>=30 && i<40)//Se il contatore assume un valore tra 30 e 40:
        {
            (pcarta+i)->valore=val++; //Viene assegnato in ordine crescente un valore da 1 a 10.
            (pcarta+i)->seme=bastoni; //Viene assegnato il seme bastoni.
        }
    }
}

//Procedura di stampa a video del mazzo:
void stampa_mazzo(Carta *mazzo,int n_carte)
{
    pcarta=mazzo; //Pcarta punta all'indirizzo base di mazzo.
    int i;
    //Corpo della Procedura:
    printf("\nNota: Seme 0= spade; Seme 1= coppe; Seme 2= denari; Seme 3= bastoni.\n"); //Stampa a video una legenda dei semi per l'utante.
    for(i=0;i<n_carte;i++) //For per la stampa a video.
        printf("carta n. %2d : valore= %d  seme= %d\n",i+1,(pcarta+i)->valore,(pcarta+i)->seme); //Stampa a video in ordine crescente il mazzo.
}

//Procedura per mischiare le carte:
void mischia_mazzo(Carta *mazzo_napoletano,int n_carte,int n_mischiate)
{
    int i,j=0;
    int indice_casuale1,indice_casuale2; //Indici delle carte da scambiare, generati casualmente.
    Carta temp; //Variabile temporanea di tipo Carta, utilizzata per lo scambio.
    //Corpo della Procedura:
    for(i=0;i<n_mischiate;i++) //Ciclo For esterno per mischiare il mazzo n volte, dove n è il numero di mischiate scelto in precedenza dall'utente.
    {
        while(j<n_carte) //Ciclo While interno per scambiare tutte le carte almeno una volta.
        {
            indice_casuale1=rand()%n_carte; //generazione di un numero casuale [0,39] per il primo indice.
            indice_casuale2=rand()%n_carte; //generazione di un numero casuale [0,39] per il secondo indice.
            //Viene effettuato lo scambio del valore e del seme tramite l'utilizzo della variabile temporanea:
            temp=mazzo_napoletano[indice_casuale1];
            mazzo_napoletano[indice_casuale1]=mazzo_napoletano[indice_casuale2];
            mazzo_napoletano[indice_casuale2]=temp;
            j++;
        }
    }
}

//Function per la scelta casuale del primo turno:
int scelta_turno(char *giocatore1,char *giocatore2)
{
    int numero_casuale;
    numero_casuale=1+rand()%2; //Genera un numero casuale tra 1 e 2, in modo da stabilire chi inizierà.
    //Corpo della Function:
    printf("\nLa scelta del giocatore che iniziera' per primo e' casuale:\n");
    printf("Inizia: ");
    if(numero_casuale==1) //Se il numero casuale è 1:
        puts(giocatore1); //Stampa il nome del giocatore1.
    else //Se il numero casuale è 2:
        puts(giocatore2); //Stampa il nome del giocatore2.
    return numero_casuale; //Ritorna il numero del giocatore che deve iniziare.
}

//Function per lo svolgimento del gioco delle coppie:
int gioco_coppie(Carta *mazzo_napoletano,int n_carte,int turno_giocatore,char *giocatore1,char *giocatore2)
{
    Carta mazzo_scoperto[40]; //Array che contiene le carte scoperte.
    Carta *pmazzo_scoperte;
    int indice_scoperte=0; //Variabile per l'indisce delle carte scoperte.
    int n_carte_scoperte=0; //Variabile per contare quante carte sono state scoperte
    int punt_gioc1=0,punt_gioc2=0; //Variabili utilizzate per il conteggio dei punti dei giocatori.
    int indice1, indice2; //Variabili utilizzate per individuare le carte scelte dal giocatore.
    //Corpo della Function:
    while(n_carte!=0)
    {
        pmazzo_scoperte=mazzo_scoperto; //Pmazzo_scoperte punta all'indirizzo base del mazzo scoperto
        pcarta=mazzo_napoletano; //Pcarta punta all'indirizzo base di mazzo napoletano.
        if(turno_giocatore==1)
        {
            printf("\n");
            puts(giocatore1);
        }
        else
        {
            printf("\n");
            puts(giocatore2);
        }
        //Viene chiesto al giocatore la posizione delle due carte.
        do{
            printf("Scegli le posizioni delle tue carte (da 1 a %d):\n",n_carte);
            printf("-Posizione carta n. 1=  ");
            scanf("%d",&indice1);
            printf("\n-Posizione carta n. 2=  ");
            scanf("%d",&indice2);
            //Viene controllato la validità delle posizioni inserite:
            if(indice1<1 || indice1>n_carte || indice2<1 || indice2>n_carte) //Se le posizioni sono inferiori a 1 o maggiori del numero di carte ancora coperte:
                printf("\nErrore! La posizione inserita non e' valida, riprova!\n"); //Viene mostrato un messaggio di errore.
            else if(indice1==indice2) //Oppure se gli indici sono uguali:
                printf("\nErrore! Le posizioni non possono essere uguali! Riprova!\n"); //Viene mostrato un altro messaggio di errore.
        }while(indice1<1 || indice1>n_carte || indice2<1 || indice2>n_carte || indice1==indice2); //Uscirà fuori dal ciclo solo se le posizioni sono comprese tra 1 e 40, e sono diverse tra loro.
        //Controllo dei valori delle carte nelle posizioni scelte dal giocatore:
        if(((pcarta+indice1-1)->valore)==((pcarta+indice2-1)->valore)) //Se i valori delle carte sono uguali:
        {
            if(turno_giocatore==1) //Se è il turno del primo giocatore:
                punt_gioc1++;//Incrementa il punteggio del primo giocatore.
            else //Se è il turno del secondo giocatore:
                punt_gioc2++; //Incremente il punteggio del secondo giocatore.
            //Viene riempito l'array delle carte scoperte con le carte appena giocate.
            mazzo_scoperto[indice_scoperte]=mazzo_napoletano[indice1-1];
            mazzo_scoperto[indice_scoperte+1]=mazzo_napoletano[indice2-1];
            //Vengono escluse dal mazzo le carte giocate.
            escludi_carta(pcarta,indice1-1,indice2-1,n_carte); //Argomenti: indirizzo base del mazzo, i due indici da escludere, numero di carte.
            n_carte_scoperte=n_carte_scoperte+2; //Il numero di carte scoperte viene incrementato.
            n_carte=n_carte-2; //Il numero delle carte del mazzo napoletano viene decrementato.
            printf("\nLe coppie sono uguali! Hai fatto un punto!\n");
            //Vengono stampati i due mazzi.
            printf("\nLe carte ancora coperte sono:\n");
            stampa_mazzo(pcarta,n_carte); //Argomenti: indirizzo base del mazzo napoletano, numero di carte.
            printf("\nLe carte scoperte sono:\n");
            stampa_mazzo(pmazzo_scoperte,n_carte_scoperte); //Argomenti: indirizzo base del mazzo scoperto, numero di carte scoperte.
            indice_scoperte=indice_scoperte+2; //Viene incrementato l'indice delle carte scoperte.
            //Vengono visualizzati i punteggi di entrambi i giocatori quando un giocatore fa punto.
            printf("\nI vostri punteggi:\n");
            printf("1)Punti di: ");
            puts(giocatore1);
            printf("%d\n",punt_gioc1);
            printf("2)Punti di: ");
            puts(giocatore2);
            printf("%d\n",punt_gioc2);
        }
        else //Se i valori delle carte scelte dal giocatore sono diversi:
        {
            //Viene cambiato il turno.
            printf("Le carte sono diverse! Tocca al giocatore successivo!\n");
            turno_giocatore=cambio_turno(turno_giocatore); //Argomenti: turno degl giocatore attuale.
        }
    }
    //Calcolo del vincitore:
    if(punt_gioc1>punt_gioc2)
        return 1;
    else if(punt_gioc1<punt_gioc2)
        return 2;
    else
        return 0;
}

//Procedura che toglie dal mazzo napoletano le carte scoperte.
void escludi_carta(Carta *mazzo_napoletano,int indice1,int indice2,int n_carte)
{
    int i,j;
    //Calcolo dell'indice più grande, e spostamento della carta di un posto indietro.
    if(indice1<indice2) //Se l'indice1 è maggiore dell'indice2:
    {
        i=indice1;
        j=indice2;
        //Ripetere lo spostamento della carta dell'indice i+1 di un posto indietro, fin quando i non arriva all'indice2.
        while(i<=indice2)
        {
            mazzo_napoletano[i]=mazzo_napoletano[i+1];
            i++;
        }
        //Ripetere lo spostamento della carta dell'indice j-1 di un posto indietro, fin quando j non arriva all'ultima carta.
        while(j<n_carte)
        {
            mazzo_napoletano[j-1]=mazzo_napoletano[j+1];
            j++;
        }
    }
    else //Se l'indice1 è minore dell'indice2:
    {
        i=indice2;
        j=indice1;
        //Ripetere lo spostamento della carta dell'indice i+1 di un posto indietro, fin quando i non arriva all'indice1.
        while(i<=indice1)
        {
            mazzo_napoletano[i]=mazzo_napoletano[i+1];
            i++;
        }
        //Ripetere lo spostamento della carta dell'indice j-1 di un posto indietro, fin quando j non arriva all'ultima carta.
        while(j<n_carte)
        {
            mazzo_napoletano[j-1]=mazzo_napoletano[j+1];
            j++;
        }
    }
}

//Function che cambia il turno del giocatore in base al turno precedente.
int cambio_turno(int turno_giocatore)
{
    //Cambia il turno del giocatore in base al turno precedente.
    if(turno_giocatore==1) //Se il turno è del giocatore1:
        turno_giocatore=2; //Spostare il turno al giocatore2.
    else //Se il turno è del giocatore2:
        turno_giocatore=1; //Spostare il turno al giocatore1.
    return turno_giocatore; //Ritorna il turno aggiornato.
}

//Procedura che stampa il vincitore:
void stampa_vincitore(int vincitore,char *giocatore1,char *giocatore2)
{
    //Stampa il vincitore in base al valore della variabile:
    if(vincitore==0) //Se la variabile vincitore risulta 0:
        printf("C'è stato un pareggio! Avete vinto entrambi.\n"); //Stampa che c'è stato un pareggio.
    else //Se la variabile vincitore è diversa da zero:
    {
        printf("\nComplimenti! Ha vinto: ");
        if(vincitore==1) //Se la variabile risulta 1:
            puts(giocatore1); //Stampa il nome del giocatore1.
        else //Se la variabile risulta 2:
            puts(giocatore2); //Stampa il nome del giocatore2.
    }
}
