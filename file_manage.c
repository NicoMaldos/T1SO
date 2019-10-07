#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include"file_manage.h"

static int cantmazo = 108;

//funcion que crea todas las cartas y las guarda en la carpeta mazo.
void createCards(){
	FILE *fp;
	char Nombre[50] = {0};
	int i;

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d rojo.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d rojo_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d amarillo.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d amarillo_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d verde.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d verde_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	for (i = 0; i < 10; i++){
		sprintf(Nombre, "mazo/%d azul.txt", i);
		fp = fopen(Nombre, "a");
		fclose ( fp );
		if (i >= 1){
			sprintf(Nombre, "mazo/%d azul_1.txt", i);
			fp = fopen(Nombre, "a");
			fclose ( fp );
		}
	}

	fp = fopen ( "mazo/+2 amarillo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 amarillo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa amarillo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa amarillo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto amarillo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto amarillo_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+2 azul.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 azul_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa azul.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa azul_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto azul.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto azul_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+2 rojo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 rojo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa rojo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa rojo_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto rojo.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto rojo_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+2 verde.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+2 verde_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa verde.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/reversa verde_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto verde.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/salto verde_1.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/cambio color_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/cambio color_2.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/cambio color_3.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/cambio color_4.txt", "a" );        
	fclose ( fp );

	fp = fopen ( "mazo/+4_1.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+4_2.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+4_3.txt", "a" );        
	fclose ( fp );
	fp = fopen ( "mazo/+4_4.txt", "a" );        
	fclose ( fp );
}

//Funcion que mueve un archivo de una carpeta a otra
void moveCards(char *src, char *card, char *dest){
	FILE *fp;
	char aux1[50];
	char aux2[50];
	char aux3[50];

	strcpy(aux1, src);
	strcpy(aux2, card);
	strcpy(aux3, dest);

	strcat(aux3, "/");
	strcat(aux3, aux2);
	fp = fopen(aux3, "a");
	fclose(fp);

	strcat(aux1, "/");
	strcat(aux1, aux2);
	remove(aux1);
}

//Esta funcion saca una carta del mazo de forma aleatoria y la almacena en la carpeta "player".
void getCard(char *player){
	DIR *dir; 
	struct dirent *sd;
	int i=0;
	char *cart, mano[108][50];
	int random = rand() % (cantmazo);

	if ((dir = opendir("mazo")) == NULL){
		perror ("opendir() error.");
	}
	else {
		while((sd = readdir(dir)) != NULL){
			if ( !strcmp(sd->d_name, ".") || !strcmp(sd->d_name, "..") ){
			}
			else{
				cart = sd->d_name;
				strcpy(mano[i], cart);
				i +=1;
			}
		}
	}
	closedir(dir);
	strcpy(cart, mano[random]);
	moveCards("mazo", cart, player);
	cantmazo -= 1;
}

//Crea las cartas del mazo y reparte las primeras 7 cartas a los 4 jugadores y deja una carta "en juego".
void startGame(){
	int i;
	
	createCards();

	for (i = 0; i < 7; i++){
		getCard("jugador 1");
	}
	for (i = 0; i < 7; i++){
		getCard("jugador 2");
	}
	for (i = 0; i < 7; i++){
		getCard("jugador 3");
	}
	for (i = 0; i < 7; i++){
		getCard("jugador 4");
	}

	getCard("ult_descarte");
}

//Funcion que nos ejecuta todo un turno de un jugador(sin robar).
void turno(char *folder){
	DIR *dir; 
	struct dirent *sd; 
	char i, *ant = "", *sig = "", *subsig = "", *cartmano = "", optstr[2] = "", optstr2[2] = "", *descarte = "", cartdes[50] = "ult_descarte/", mano[100][50], cartjug[50] = "";
	int cont = 0, cont2 = 0, optint, optint2, seguir = 0;

	while(seguir == 0){
		printf("-------------------- Turno del %s --------------------\n", folder);
		printf("<<< La ultima carta descartada fue: ");
		if ((dir = opendir("ult_descarte")) == NULL){
			perror ("opendir() error.");
		}
		else {
			while((sd = readdir(dir)) != NULL){
				if ( !strcmp(sd->d_name, ".") || !strcmp(sd->d_name, "..") ){
				}
				else{
					descarte = sd->d_name;
					if( strlen(descarte)>5){
						strcpy(cartdes, descarte);
						descarte = strtok(sd->d_name, ".");
						descarte = strtok(descarte, "_");
						printf("%s >>>\n", descarte);
					}
				}
			}
		}
		closedir(dir);

		printf("<<< Puedes tirar una de las cartas de tu mano o robar una carta del mazo: >>>\n");
		if ((dir = opendir(folder)) == NULL){
			perror ("opendir() error.");
		}
		else {
			while((sd = readdir(dir)) != NULL){
				if ( !strcmp(sd->d_name, ".") || !strcmp(sd->d_name, "..") ){
				}
				else{
					cartmano = sd->d_name;
					strcpy(mano[cont], cartmano);
					cartmano = strtok(sd->d_name, ".");
					cartmano = strtok(cartmano, "_");
					cont += 1;
					printf("%d) %s\n", cont, cartmano);
				}
			}
			cont+=1;
			printf("%d) Robar carta\n", cont);
		}
		closedir(dir);

		char *numdes = "", *numjug = "", colordes[9] = "", colorjug[9] = "", aux[50] = "", aux2[50] = "", aux3[50] = "";

		printf("*** Indique el numero de la opción a realizar: ***\n");
		scanf("%s", optstr);
		optint = atoi(optstr);
		while(optint < 0 || optint > cont){
			printf("Opcion incorrecta\n");
			printf("Indique el numero de la opción a realizar: \n");
			scanf("%s", optstr);
			optint = atoi(optstr);
		}
		if(optint == cont){
			getCard(folder);
			seguir = 1;
			cont2 = cont;
			cont = 0;
		}
		else{
			cont2 = cont;
			cont = 0;
			strcpy(aux, cartdes);
			strcpy(aux2, cartdes);
			strtok(aux, ".");
			strtok(aux, "_");
			numdes = strtok(aux2, " ");

			if (strlen(numdes) == 1){
				for (i = 2; i < strlen(aux); i++){
					colordes[i-2] = aux[i];
				}
			}
			else if (strlen(numdes) == 2){
				for (i = 3; i < strlen(aux); i++){
					colordes[i-3] = aux[i];
				}
			}
			else if(strlen(numdes) == 5){
				for (i = 6; i < strlen(aux); i++){
					colordes[i-6] = aux[i];
				}
			}
			else if(strlen(numdes) == 7){
				for (i = 8; i < strlen(aux); i++){
					colordes[i-8] = aux[i];
				}
			}

			strcpy(cartjug, mano[optint-1]);
			strcpy(aux3, mano[optint-1]);
			strtok(cartjug, ".");
			strtok(cartjug, "_");

			numjug = strtok(aux3, " ");
			numjug = strtok(numjug, "_");

			if (strlen(numjug) == 1){
				for (i = 2; i < strlen(cartjug); i++){
					colorjug[i-2] = cartjug[i];
				}
			}
			else if (strlen(numjug) == 2 && strcmp(numjug, "+4") != 0){
				for (i = 3; i < strlen(cartjug); i++){
					colorjug[i-3] = cartjug[i];
				}
			}
			else if(strlen(numjug) == 5){
				for (i = 6; i < strlen(cartjug); i++){
					colorjug[i-6] = cartjug[i];
				}
			}
			else if(strlen(numjug) == 7){
				for (i = 8; i < strlen(cartjug); i++){
					colorjug[i-8] = cartjug[i];
				}
			}
			
			if (strcmp(numjug, "cambio") == 0){
				printf("¿A que color deseas cambiar?\n");
				printf("1) Azul.\n");
				printf("2) Amarillo.\n");
				printf("3) Verde.\n");
				printf("4) Rojo.\n");
				scanf("%s", optstr2);
				optint2 = atoi(optstr2);
				while(optint2 < 0 || optint2 > 4){
					printf("Opcion incorrecta\n");
					printf("Indique el numero del color a cambiar:\n");
					scanf("%s", optstr2);
					optint2 = atoi(optstr2);
				}
				if (optint2 == 1){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/x azul.txt", "a");
					fclose(fp);
				}
				if (optint2 == 2){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/x amarillo.txt", "a");
					fclose(fp);
				}
				if (optint2 == 3){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/x verde.txt", "a");
					fclose(fp);
				}
				if (optint2 == 4){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/x rojo.txt", "a");
					fclose(fp);
				}
				strcpy(aux, folder);
				strcat(aux, "/");
				strcat(aux, mano[optint-1]);
				remove(aux);

				seguir = 1;	
				cont2 -= 1;
			}
			else if (strcmp(numjug, "+4") == 0){
				printf("¿A que color deseas cambiar?\n");
				printf("1) Azul.\n");
				printf("2) Amarillo.\n");
				printf("3) Verde.\n");
				printf("4) Rojo.\n");
				scanf("%s", optstr2);
				optint2 = atoi(optstr2);

				while(optint2 < 0 || optint2 > 4){
					printf("Opcion incorrecta\n");
					printf("Indique el numero del color a cambiar:\n");
					scanf("%s", optstr2);
					optint2 = atoi(optstr2);
				}
				if (optint2 == 1){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/+ azul.txt", "a");
					fclose(fp);
				}
				else if (optint2 == 2){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/+ amarillo.txt", "a");
					fclose(fp);
				}
				else if (optint2 == 3){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/+ verde.txt", "a");
					fclose(fp);
				}
				else if (optint2 == 4){
					strcpy(aux, "ult_descarte/");
					strcat(aux, cartdes);
					remove(aux);
					FILE *fp;
					fp = fopen("ult_descarte/+ rojo.txt", "a");
					fclose(fp);
				}
				strcpy(aux, folder);
				strcat(aux, "/");
				strcat(aux, mano[optint-1]);
				remove(aux);

				seguir = 1;	
				cont2 -= 1;
			}
			else if (strcmp(numdes, numjug) == 0 || strcmp(colordes, colorjug) == 0){
				strcpy(aux, "ult_descarte/");
				strcat(aux, cartdes);
				remove(aux);
				moveCards(folder, mano[optint-1], "ult_descarte");
				seguir = 1;	
				cont2 -= 1;
			}
			else{
				printf("No puedes jugar esta carta. Fijate en el numero y color de la carta en juego!\n");
				seguir = 0;
			}
			
		}
	}

	if(cont2 == 0){
		printf("Ganaste, juego terminado");
	}
	else if(cantmazo == 0){
		printf("No quedan cartas en el mazo, nadie gana.");
	}
	else{
		if(cont2 == 1){
			printf("UNO!");
		}

		if(strcmp(folder, "jugador 1") == 0){
			ant = "jugador 4";
			sig = "jugador 2";
			subsig = "jugador 3";
		}
		else if(strcmp(folder, "jugador 2") == 0){
			ant = "jugador 1";
			sig = "jugador 3";
			subsig = "jugador 4";
		}
		else if(strcmp(folder, "jugador 3") == 0){
			ant = "jugador 2";
			sig = "jugador 4";
			subsig = "jugador 1";
		}
		else{
			ant = "jugador 3";
			sig = "jugador 1";
			subsig = "jugador 2";
		}
		
		strtok(cartjug, " ");

		if(strcmp(cartjug, "+2") == 0){
			printf("el %s debe sacar 2 cartas! ¡Pierde turno!\n", sig);
			for(i=0; i<2; i++){
				getCard(sig);
			}
			turno(subsig);
		}
		else if(strcmp(cartjug, "+4") == 0){
			printf("el %s debe sacar 4 cartas! ¡Pierde turno!\n", sig);
			for(i=0; i<4; i++){
				getCard(sig);
			}
			turno(subsig);
		}
		else if(strcmp(cartjug, "salto") == 0){
			turno(subsig);
		}
		else if(strcmp(cartjug, "reversa") == 0){
			turno(ant);
		}
		else if(strcmp(cartjug, "cambio") == 0){
			turno(sig);
		}
		else{
			turno(sig);
		}
	}
}
