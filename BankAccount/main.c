#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Dichiarazioni dei tipi, delle struct e delle variabili globali.
struct data{
    int giorno;
    int mese;
    int anno;
}; //Dichiaro un nuovo tipo strutturato per le date.
typedef struct data Data; //Definisco un nuovo tipo "Data".
struct lista_movimenti{
    Data data_movim;
    char tipologia[50];
    int importo;
}; //Dichiaro un nuovo tipo strutturato per le liste movimenti.
typedef struct lista_movimenti Lista_M; //Definisco un nuovo tipo "Lista_M".
struct utenti{
    char nome[20];
    char cognome[20];
    Data nascita;
    char conto_corrente[27];
    Lista_M lista_mov[10];
}; //Dichiaro un nuovo tipo strutturato per gli utenti.
typedef struct utenti Utente; //Definisco un nuovo tipo "Utenti".
Utente *putente; //Variabile globale puntatore di un tipo Utenti.

//Lista di prototipi delle Function e Procedure.
void generatore_IBAN(Utente *utente,int n_utenti);//Parametri: indirizzo base dell'utente, numeri di utenti a cui bisogna creare l'iban.
void generatore_data(Utente *utente,int n_utenti);//Parametri: indirizzo base dell'utente, numeri di utenti a cui bisogna creare le date.
void stampa_data(Utente *utente,int val,int indice); //Parametri: indirizzo base dell'utente, un valore compreso tra 0 e 1 che indica se deve stampare una data di nascita o una data di un movimento della lista movimenti, l'indice di quale movimento si vuole stampare.
void generatore_lista_movimenti(Utente *utente,int n_utenti); //Parametri: indirizzo base dell'utente, numeri di utenti a cui bisogna creare la lista movimenti.
void stampa_lista_mov(Utente *utente); //Paramentri: indirizzo base dell'utente.
void ordinamento_lista(Utente *utente,int n_utenti); //Parametri: indirizzo base dell'utente, numero di utenti a cui bisogna ordinare la lista movimenti.
int inserimento_utente(Utente *utente,int n_utenti,int spazio_massimo);//Parametri: indirizzo base dell'utente, numero di utenti registrati, numero massimo di utenti registrabili.
void stampa_utenti(Utente *utente,int n_utenti); //Parametri: indirizzo base dell'utente, numero di utenti da stampare.
int matching_utente(Utente *utente, int n_utenti,char *nome,char *cognome); //Parametri: indirizzo base dell'utente, numero di utenti registrati, indirizzo base del nome e del cognome.
int matching_iban(Utente *utente, int n_utenti,char *iban); //Parametri: indirizzo base dell'utente, numero di utenti registrati, indirizzo base dell'iban.
void cerca_mov(Utente *utente, int n_utenti); //Parametri: indirizzo base dell'utente, numero di utenti registrati.

int main()
{
    //Dichiarazioni delle veriabile ed inizializzazione:
    //Array di Utente per gli utenti già registrati ed inizializzazione del nome ed del cognome.
    Utente utente[80]={{"Alessia","De Vivo"},{"Alessia","Leggio"},{"Andrea","Nasello"},{"Angela","Incremona"},{"Anisia","Cappello"},
                       {"Antonio","Colucci"},{"Antonio","Cusumano"},{"Antonio","De Luca"},{"Antonio","Pantaleo"},{"Antonio","Sarno"},
                       {"Barbara","Licitra"},{"Carlotta","Idone"},{"Carmelo","Vermiglio"},{"Chiara","D'Izzia"},{"Chiara","Golino"},
                       {"Claudia","Accetta"},{"Damiano","Canzonieri"},{"Elisabetta","Giglio"},{"Federica","Assenza"},{"Federica","Giordano"},
                       {"Federica","Ingallina"},{"Federica","Ottaviano"},{"Gabriele","Occhipinti"},{"Gaetano","Pantaleo"},{"Giulia","Carfi"},
                       {"Giulia","Rosano"},{"Giuseppe","Criscione"},{"Jessica","Fuochi"},{"Jonathan","De Michele"},{"Jonathan","Marsiano"},
                       {"Kristina","Kamberaj"},{"Laura","Morelli"},{"Laura","Sarno"},{"Luca","Di Lorenzo"},{"Luciano","D'Agostino"},
                       {"Manuela","Cascone"},{"Marco","Lentini"},{"Maria","Aconte"},{"Mariachiara","Diella"},{"Mariateresa","Agosta"},
                       {"Marina","Tanga"},{"Roberta","Gaccione"},{"Roberto","Sarno"},{"Salvatore","D'Andrea"},{"Salvatore","Starace"},
                       {"Sara","Sarno"},{"Sara","Settembrini"},{"Sarah","Ruggieri"},{"Simone","Tumino"},{"Vittorio","Occhipinti"}};
    //Variabile per gli utenti registrati.
    int n_utenti=50;
    //Variabile per numero massimo di utenti registrabili.
    int spazio_massimo=80;
    int scelta1,i;
    srand(time(NULL));
    //Corpo del Main:
    //Vengono inizializzati casualmente l'IBAN, le date di nascita, le date dei movimenti e la lista movimenti.
    generatore_IBAN(utente,n_utenti); //Argomenti: indirizzo base degli utenti, numero di utenti a cui bisogna generare l'IBAN.
    generatore_data(utente,n_utenti); //Argomenti: indirizzo base degli utenti, numero di utenti a cui bisogna generare le date.
    generatore_lista_movimenti(utente,n_utenti); //Argomenti: indirizzo base degli utenti, numero di utenti a cui bisogna generare la lista movimenti.
    //Viene ordinata la lista movimenti dalla più recente alla più lontana.
    ordinamento_lista(utente,n_utenti); //Argomenti: indirizzo base degli utenti, numero di utenti a cui bisogna ordinare la lista movimenti.
    //Menù iniziale che si ripete fin quando l'utente non seleziona 0.
    do{
        printf("                               ---Questo programma gestisce %d conti correnti.---\n",n_utenti);
        printf("\nPremi 1 per inserire un nuovo correntista.\nPremi 2 per vedere la lista movimenti di un correntista.\nPremi 0 per uscire.\n");
        printf("-La tua scelta: ");
        scanf("%d",&scelta1);
        switch (scelta1){
            //Se viene digitato 1: si inserisce un nuovo utente.
            case 1: n_utenti=inserimento_utente(utente,n_utenti,spazio_massimo); //Argomenti: indirizzo base degli utente, numero di utenti registrati, numero massimo di utenti registrabili.
                    break;
            //Se viene digitato 2: si cerca una lista movimenti di un utente a scelta.
            case 2: cerca_mov(utente,n_utenti); //Argomenti: indirizzo base degli utenti, numero di utenti registrati.
                    break;
            case 0: printf("Grazie, e arrivederci!");
                    break;
            //Se viene digitato un valore differente viene visualizzato un messaggio di errore.
            default: printf("Il numero inserito non e' corretto.\n");
        }
    }while(scelta1!=0);
    return 0;
}

//Procedura che genera numeri di conto correnti casuali:
void generatore_IBAN(Utente *utente,int n_utenti)
{
    putente=utente;
    int i,j;
    //Ciclo eseguito per il numero di utenti registrati o per un singolo utente a seconda del valore di n_utenti indicato.
    for(j=0;j<n_utenti;j++)
    {
        //Ciclo ripetuto per ogni cifra dell'Iban (27)
        for(i=1;i<27;i++)
        {
            //Le prime due cifre:
            if(i<2)
            {
                //Vengono inizializzate con IT.
                (putente+j)->conto_corrente[0]='I';
                (putente+j)->conto_corrente[1]='T';
            }
            //Per la cifra numero 4:
            else if(i==4)
                (putente+j)->conto_corrente[i]=65+rand()%26; //Viene generata una lettera maiuscola dell'alfabeto.
            //Per le restanti cifre:
            else
                (putente+j)->conto_corrente[i]=48+rand()%10; //Viene generato un numero da 0 a 9.
        }
    }
    //Viene effettuato un controllo di unicità del codice IBAN:
    for(i=0;i<n_utenti;i++) //Ciclo ripetuto per tutti gli utenti.
    {
        //Se il codice IBAN dell'i-simo utente è uguale al codice dell'utente successivo:
        if(strcmp(&utente[i].conto_corrente,&utente[i+1].conto_corrente)==0)
        {
            generatore_IBAN(&utente[i+1],1);//viene generato un nuovo codice IBAN all'utente successivo.
        }
    }
}

//Procedura che genera date di nascita casuali se val è 0 altrimenti genera una data per la lista movimenti.
void generatore_data(Utente *utente,int n_utenti)
{
    putente=utente;
    int i,j;
    for(j=0;j<n_utenti;j++)
    {
        //Viene generato un anno di nascita tra il 1918 e il 2000.
        (putente+j)->nascita.anno=1950+rand()%51;
        //Viene generato un mese tra 1 e 12.
        (putente+j)->nascita.mese=1+rand()%12;
        if((putente+j)->nascita.mese==2) //Se il mese è Febbraio:
            (putente+j)->nascita.giorno=1+rand()%28; //Genera un numero casuale tra 1 e 28.
        else if((putente+j)->nascita.mese==1 || (putente+j)->nascita.mese==3 || (putente+j)->nascita.mese==5 || (putente+j)->nascita.mese==7 || (putente+j)->nascita.mese==8 || (putente+j)->nascita.mese==10 || (putente+j)->nascita.mese==12) //Se il mese è Gennaio, Marzo, Maggio, Luglio, Agosto, Ottobre o Dicembre:
            (putente+j)->nascita.giorno=1+rand()%31; //Genera un numero casuale tra 1 e 31.
        else //Altrimenti:
            (putente+j)->nascita.giorno=1+rand()%30; //Genera un numero casuale tra 1 e 30.
        for(i=0;i<10;i++)
        {
            (putente+j)->lista_mov[i].data_movim.anno=2018;
            (putente+j)->lista_mov[i].data_movim.mese=1+rand()%12;
            if((putente+j)->lista_mov[i].data_movim.mese==2) //Se il mese è Febbraio:
                (putente+j)->lista_mov[i].data_movim.giorno=1+rand()%28; //Genera un numero casuale tra 1 e 28.
            //Se il mese è Gennaio, Marzo, Maggio, Luglio, Agosto, Ottobre o Dicembre:
            else if((putente+j)->lista_mov[i].data_movim.mese==1 || (putente+j)->lista_mov[i].data_movim.mese==3 || (putente+j)->lista_mov[i].data_movim.mese==5 || (putente+j)->lista_mov[i].data_movim.mese==7 || (putente+j)->lista_mov[i].data_movim.mese==8 || (putente+j)->lista_mov[i].data_movim.mese==10 || (putente+j)->lista_mov[i].data_movim.mese==12)
                (putente+j)->lista_mov[i].data_movim.giorno=1+rand()%31; //Genera un numero casuale tra 1 e 31.
            else //Altrimenti:
                (putente+j)->lista_mov[i].data_movim.giorno=1+rand()%30; //Genera un numero casuale tra 1 e 30.
        }
    }
}

//Procedura di stampa della data di nascita di un utente se val è 0, altrimenti stampa una data della lista movimenti.
void stampa_data(Utente *utente,int val,int indice)
{
    putente=utente;
    //Se il valore indicato è uguale a zero: stampa le date di nascita.
    if(val==0)
    {
        //Stampa la data di nascita dell'utente per intero.
        printf("%11d/",(putente)->nascita.giorno);
        printf("%d/",(putente)->nascita.mese);
        printf("%d",(putente)->nascita.anno);
    }
    //Altrimenti: stampa le liste movimenti.
    else
    {
        //Stampa le date della lista movimenti per intero.
        printf("%13d/",(putente)->lista_mov[indice].data_movim.giorno);
        printf("%d/",(putente)->lista_mov[indice].data_movim.mese);
        printf("%d            ",(putente)->lista_mov[indice].data_movim.anno);
    }
}

//Procedura che genera 10 movimenti di un utente.
void generatore_lista_movimenti(Utente *utente,int n_utenti)
{
    putente=utente;
    int i,j,n_casuale,importo;
    //Ciclo ripetuto per il numero di utenti registrati.
    for(j=0;j<n_utenti;j++)
    {
        //Ciclo ripetuto per il numero di movimenti.
        for(i=0;i<10;i++)
        {
            //Genera un numero casuale da 1 a 4.
            n_casuale=1+rand()%4;
            //Se il numero casuale è 1
            if(n_casuale==1)
            {
                strcpy((putente+j)->lista_mov[i].tipologia,"Versamento"); //Viene inserito la paraola Versamento nella tipologia.
                (putente+j)->lista_mov[i].importo=100+rand()%4901; //Viene assegnato all'importo un numero casuale tra 100 e 5000.
            }
            //Se il numero casuale è 2:
            else if(n_casuale==2)
            {
                strcpy((putente+j)->lista_mov[i].tipologia,"Prelievo"); //Viene inserito la parola Prelievo nella tipologia.
                importo=50+rand()%151;//Viene generato un numero casuale tra 50 e 200.
                (putente+j)->lista_mov[i].importo=-importo;//Viene assegnato all'importo il negativo del numero generato.
            }
            else if(n_casuale==3)
            {
                strcpy((putente+j)->lista_mov[i].tipologia,"Bonifico a vostro favore");//Viene inserito la parola Bonifico a vostro favore nella tipologia.
                (putente+j)->lista_mov[i].importo=50+rand()%251;//Viene assegnato all'importo un numero casuale tra 50 e 300.
            }
            else
            {
                strcpy((putente+j)->lista_mov[i].tipologia,"Vostro Bonifico");//Viene inserito la parola Vostro Bonifico nella tipologia.
                importo=50+rand()%251;//Viene generato un numero casuale tra 50 e 300.
                (putente+j)->lista_mov[i].importo=-importo;//Viene assegnato all'importo il negativo del numero generato.
            }
        }
    }
}

//Pocedura che ordina la lista movimenti in base alla data, dalla più recente alla più lontana.
void ordinamento_lista(Utente *utente,int n_utenti)
{
    int i,j,k;
    Lista_M temp;
    putente=utente;
    //Ordinamento eseguito per tutti gli utenti registrati.
    for(k=0;k<n_utenti;k++)
    {
        //Ciclo eseguito per i 10 movimenti registrati.
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                //Se il giorno dell'i-simo movimento è più grande del giorno del j-simo movimento:
                if((putente+k)->lista_mov[i].data_movim.giorno>(putente+k)->lista_mov[j].data_movim.giorno)
                {
                    //Effettua lo scambio di posizioni.
                    temp=(putente+k)->lista_mov[i];
                    (putente+k)->lista_mov[i]=(putente+k)->lista_mov[j];
                    (putente+k)->lista_mov[j]=temp;
                }
                //Se il mese dell'i-simo movimento è più grande del mese del j-simo movimento:
                if((putente+k)->lista_mov[i].data_movim.mese>(putente+k)->lista_mov[j].data_movim.mese)
                {
                    //Effettua lo scambio di posizioni.
                    temp=(putente+k)->lista_mov[i];
                    (putente+k)->lista_mov[i]=(putente+k)->lista_mov[j];
                    (putente+k)->lista_mov[j]=temp;
                }
            }
        }
    }
}
//Procedura di stampa della lista movimenti.
void stampa_lista_mov(Utente *utente)
{
    int i;
    putente=utente;
    printf("Verranno visualizzati gli ultimi 10 movimenti dell'utente scelto.\n");
    //Ciclo eseguito per il numero di movimenti registrato.
    for(i=0;i<10;i++)
    {
        printf("\n     Importo:           Data:            Operazione:");
        printf("\n%d)",i+1);
        printf("%8d",(putente)->lista_mov[i].importo);
        stampa_data(utente,1,i);//Argomenti: indirizzo di memoria dell'utente ricercato, variabile che indica se bisgna stampare date di nascita o date delle liste, e l'indice della data del movimento che bisogna far stampare.
        puts((putente)->lista_mov[i].tipologia);
    }
}

//Function di inserimeno di un utente.
int inserimento_utente(Utente *utente,int n_utenti,int spazio_massimo)
{
    int scelta2;
    //Alla fine del ciclo verrà chiesto all'utente se vorrà aggiungere un altro utente, e il ciclo si ripeterà se la sua scelta sarà positiva.
    do{
        putente=utente;
        printf("\nPuoi aggiungere un massimo di %d nuovi utenti.\n",spazio_massimo-n_utenti);
        //Viene fatto il controllo alla spazio rimasto.
        if (n_utenti<spazio_massimo)//Se è rimasto spazio:
        {
            fflush(stdin); //Inizializza ("ripulisce") l'area di memoria dedicata all'input;
            //Vengono chiesti alcuni dati all'utente e successivamente salvati.
            printf("\n-Inserisci il tuo nome: ");
            gets((putente+n_utenti)->nome);
            printf("\n-Inserisci il tuo cognome: ");
            gets((putente+n_utenti)->cognome);
            printf("-Inserisci la tua data di nascita:\n");
            do{
                printf("Anno: ");
                scanf("%d", &(putente+n_utenti)->nascita.anno);
                if((putente+n_utenti)->nascita.anno>2018 || (putente+n_utenti)->nascita.anno<1918)//Se l'anno inserito non vale:
                    printf("\nAnno inserito non valido.\n");//Viene Visualizzato un messaggio di errore.
            }while((putente+n_utenti)->nascita.anno>2018 || (putente+n_utenti)->nascita.anno<1918); //In caso di errore viene ripetuta la richiesta.
            do{
                printf("Mese: ");
                scanf("%d", &(putente+n_utenti)->nascita.mese);//Se il mese inserito non vale:
                if((putente+n_utenti)->nascita.mese>12 || (putente+n_utenti)->nascita.anno<1)
                    printf("\nMese inserito non valido.\n");//Viene Visualizzato un messaggio di errore.
            }while((putente+n_utenti)->nascita.mese>12 || (putente+n_utenti)->nascita.anno<1);//In caso di errore viene ripetuta la richiesta.
            do{
                printf("Giorno: ");
                scanf("%d", &(putente+n_utenti)->nascita.giorno);
                if((putente+n_utenti)->nascita.giorno>31 || (putente+n_utenti)->nascita.giorno<1)//Se il giorno inserito non vale:
                    printf("\nGiorno inserito non valido.\n");//Viene visualizzato un messaggio di errore.
            }while((putente+n_utenti)->nascita.giorno>31 || (putente+n_utenti)->nascita.giorno<1);//In caso di errore viene ripetuta la richiesta.
             //Viene incrementeto il numero di utenti registrati.
            n_utenti=n_utenti+1;
            //Viene generato un IBAN casuale e successivamente stampato.
            generatore_IBAN(&utente[n_utenti-1],1);//Argomenti: indirizzo del nuovo utente, il numero degli utenti che bisogna generare l'IBAN, in questo caso 1.
            printf("Il tuo codice IBAN e': ");
            puts(&utente[n_utenti-1].conto_corrente);
            printf("\n\nGrazie per la registrazione!\n");
        }
        else //Se il numero degli utenti è uguale al limite massimo:
            printf("E' stato raggiunto il limite massimo di utenti. Mi dispiace!\n"); //Viene visualizzato l'avviso del raggiungimento del limite massimo.
        do{
            printf("Premi 1 per aggiungere un altro correntista.\nPremi 0 per tornare al menu'.\n");
            printf("-La tua scelta: ");
            scanf("%d",&scelta2);
            if(scelta2>1)
                printf("\nLa tua scelta non e' valida.\n");
        }while(scelta2>1);//Se il numero inserito è diverso da 0 o 1 viene ripetuta la richiesta di digitare una scelta.
    }while(scelta2!=0);//Viene ripetuto se l'utente sceglie di aggiungere un altro correntista.
    return n_utenti;//Ritorna il numero di utenti aggiornato.
}

//Procedura che stampa la lista completa degli utenti registrati.
void stampa_utenti(Utente *utente,int n_utenti)
{
    int i,j,n;
    putente=utente;
    printf("\nQuesta e' la lista degli utenti registrati:\n");
    //Ciclo ripetuto per tutti gli utenti registrati.
    for(i=0;i<n_utenti;i++)
    {
        printf("\n\nIBAN:                                 Data di nascita:                     Nome&Cognome:\n");
        //Viene stampato il codice IBAN intero.
        for(j=0;j<27;j++)
            printf("%c",utente[i].conto_corrente[j]);
        printf("     ");
        //Viene stampata la data di nascita,
        stampa_data(&utente[i],0,0); //Argomenti: Indirizzo base dell'utente, valore 0 che indica di stampare la data di nascita, indice generico che non verrà utilizzato.
        printf("                         ");
        //Calcolo della lunghezza del nome.
        n=strlen(&utente[i].nome);
        //Viene stampato il nome.
        for(j=0;j<n;j++)
            printf("%c",utente[i].nome[j]);
        printf(" ");
        //Calcolo della lunghezza del cognome.
        n=strlen(&utente[i].cognome);
        //Viene stampato il cognome.
        for(j=0;j<n;j++)
            printf("%c",utente[i].cognome[j]);
    }
}

//Function che trova il correntista registrato, tramite nome e cognome dell'utente.
int matching_utente(Utente *utente,int n_utenti,char *nome,char *cognome)
{
    int i,j,n,punteggio_max=0,punteggio,indice=0;
    //Ciclo ripetuto per tutti gli utenti registrati.
    for(i=0;i<n_utenti;i++)
    {
        punteggio=0;
        //Calcolo della lunghezza del nome dell'i-simo utente.
        n=strlen(&utente[i].nome);
        //Ciclo ripetututo fino all'ultima lettera del nome.
        for(j=0;j<n;j++)
            if(utente[i].nome[j]==nome[j]) //Se la j-sima lettera del nome dell'utente è uguale alla j-sima lettera del nome inserito è uguale:
                punteggio++; //incrementa il punteggio.
        //Calcolo della lunghezza del cognome dell'i-simo utente.
        n=strlen(&utente[i].cognome);
        //Ciclo ripetuto fino all'ultima lettera del cognome.
        for(j=0;j<n;j++)
            if(utente[i].cognome[j]==cognome[j]) //Se la j-sima lettera del cognome dell'utente è uguale alla j-sima lettare del cognome inserito è uguale:
                punteggio++;//incrementa il punteggio.
        if(punteggio>punteggio_max)//Se il punteggio appena creato è maggiore al punteggio più altro degli utenti:
        {
            punteggio_max=punteggio;//Aggiorna il punteggio più algo
            indice=i;//E viene memorizzato l'indice dell'utente il cui nome e cognome si avvicinano di più a quelli inseriti.
        }
    }
    return indice; //Ritorna l'indice dell'utente che ha avuto il punteggio più alto.
}

//Function che trova il correntista registrato, tramite il codice IBAN
int matching_iban(Utente *utente,int n_utenti,char *iban)
{
    int i,indice=-1;
    //Ciclo ripetuto per tutti gli utenti registrati.
    for(i=0;i<n_utenti;i++)
        if(strcmp(&utente[i].conto_corrente,iban)==0)//Se tutte le cifre dell'IBAN inserito è uguale a tutte le cifre dell'IBAN dell'i-simo utente:
            indice=i;//Viene memorizzato l'indice dell'utente il cui IBAN corrisponde a quello inserito.
    return indice;//Ritorna l'indice dell'utente.
}

//Procedura di cerca cerca lista movimenti di un utente.
void cerca_mov(Utente *utente,int n_utenti)
{
    int scelta2,lung_cercare,indice_utente;
    char IBAN_cerc[28];
    char nome_cerc[20];
    char cognome_cerc[20];
    do{
        //Viene chiesto all'utente se cercare tramite IBAN o tramite Nome e Cognome.
        putente=utente;printf("\nPremi 1 per effettuare la ricerca tramite IBAN.\nPremi 2 per effettuare la ricerca tramite Nome e Cognome.\n");
        printf("-La tua scelta: ");
        scanf("%d",&scelta2);
        do{
            //Viene stampata l'intera lista degli utenti registrati.
            stampa_utenti(utente,n_utenti);
            //Se l'utente scegle di cercare tramite IBAN:
            if(scelta2==1)
            {
                fflush(stdin);
                //Viene visualizzato un messaggio di attenzione per le lettere masiuscole da rispettare.
                printf("\n\nATTENZIONE alle lettere maiuscole!\n");
                printf("-Inserisci il codice IBAN dell'utente che vuoi cercare: ");
                //viene inserito l'IBAN da cercare.
                gets(IBAN_cerc);
                //viene effettuata la ricercare, e l'indice ritornato viene salvato nella variabile indice_utente.
                indice_utente=matching_iban(utente,n_utenti,IBAN_cerc); //Argomenti: indirizzo base degli utenti, numero di utenti registrati, indirizzo base dell'IBAN da cercare.
                if(indice_utente<0)//Se l'indirizzo che viene tornato dalla Frunction è negativa vuol dire che nessun IBAN corrisponde a quella inserita.
                    printf("\nIl codice Iban inserito non e' tra i nostri utenti. Riprova!\n");
            }
            //Se viene scelto di cercare tramite nome e cognome:
            else
            {
                fflush(stdin);
                printf("\n\n-Inserisci il Nome dell'utente che vuoi cercare: ");
                //Viene inserito il nome da cercare.
                gets(nome_cerc);
                printf("\n-Inserisci il Cognome dell'utente che vuoi cercare: ");
                //Viene inserito il cognome da cercare.
                gets(cognome_cerc);
                //Viene effettuata la ricerca tramite nome e cognome, l'indice ritornato viene salvato nella variabile indice_utente.
                indice_utente=matching_utente(utente,n_utenti,nome_cerc,cognome_cerc);//Argomenti: indirizzo base degli utenti, numero di utenti registrati, indirizzo base del nome e cognome da cercare.
            }
         }while(indice_utente<0);//Se non viene trovata nessuna corrispondenza viene chiesto di ricercare di nuovo.
        //Viene stampata la lista movimenti dell'utente corrispondete.
        stampa_lista_mov(&utente[indice_utente]);//Argomenti: indirizzo base dell'utente trovato.
        do{
            //viene chiesto all'utente se vuole ripetere la ricerca.
            printf("\nPremi 1 per effettuare un'altra ricerca.\nPremi 0 per tornare al menu'.\n");
            printf("-La tua scelta: ");
            scanf("%d",&scelta2);
            printf("\n");
            if(scelta2>1)//Se il la scelta effettuata non è valida viene visualizzato un messaggio di errore.
                printf("\nLa tua scelta non e' valida.\n");
        }while(scelta2>1);//Viene ripetuto fin quando la scelta è valida
    }while(scelta2!=0);
}
