#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>

#define MAX_EQUIPA 5
#define MAX_JOGADORES 17

typedef struct
{
	char nome[17];
	int id[6];
	int activo;
}Equipa;
typedef struct 
{
	
	int id[7];
	char nome[40];
	char apelido[10];
	char data_incio_contrato[9];
	char data_fim_contrato[9];
	int n_golos;
	int activo;

}Jogadores;
Equipa equipa[MAX_EQUIPA];
Jogadores jogadores[MAX_JOGADORES];
	
void menu();	
void cadastrar_Equipa();
void cadastrar_Jogador();
void listar();
	
	
int main()
{
	printf("\t\tPrograma de Cadastro de Equipas e Jogadores\n\n");
	menu();
	system("pause");
	return 0;
}

void menu(){
	//system("cls");

	int x=0;
	
	do{
		printf("1-Cadastrar Equipa\n2-Cadastrar Jogador\n");
	   	printf("3-Listar Jogadores\n0-Sair\n");
	   	printf("\n\nEscolha uma opcao: ");
	 	 fflush(stdin);
	   	scanf("%i", &x);
	   	getchar();
	   	switch(x)
		   {
		   case 1:
		   		cadastrar_Equipa();
			   break;
		   case 2:
		   	cadastrar_Jogador();
		   		break;
		   	case 3:
		   		listar();
		   		break;
		   	default:
		   		break;
		   }
	}while(x!=0);	
}

void cadastrar_Equipa(){
	Equipa equipas;
	char nome[17];
	int id[6];
	int a=0;
	int x;
	system("cls");
	printf("\tCadastrando Equipa\n");
	do{
			printf("Id: ");
			scanf("%i", &id[0]);
			fflush(stdin);
			printf("Nome: ");
			fgets(nome,sizeof(nome),stdin);		
			
			for(x = 0; x < MAX_EQUIPA; ++x){
				if(equipa[x].activo==0){
					equipa[x].id[0]=id[0];
					strcpy(equipa[x].nome, nome);
					equipa[x].activo=1;
					break;
				}
			}
			FILE *arquivo;
			arquivo= fopen("equipas.txt", "a");
			if(arquivo!=NULL){
			fprintf(arquivo, "%i %s", equipas.id, equipas.nome);
			}fclose(arquivo);
	

			printf("\n\n1-Continuar\n0-Sair\n");
			scanf("%i", &a);
			system("cls");
	}while(a!=0);
}
void cadastrar_Jogador(){
	Jogadores jogador;
	int id[7];
	char nome[40];
	char apelido[10];
	char data_incio_contrato[9];
	char data_fim_contrato[9];
	int activo;
	int a;
	int n_golos;
	int x;
	
	system("cls");
	printf("\tCadastrando Jogador\n");
	FILE * arquivo;
	arquivo= fopen("jogadores.txt", "a");
	if(arquivo!=NULL){
		fprintf(arquivo, "%i %s  %s %s %s %s %i", jogador.id, jogador.apelido, jogador.nome, jogador.data_incio_contrato, jogador.data_fim_contrato, jogador.n_golos);
	}fclose(arquivo);
	
	do{
			printf("\nId: ");
			scanf("%i", &id);
			fflush(stdin);
			printf("Nome: ");
			fgets(nome,sizeof(nome),stdin);	
			printf("Apelido: ");
			fgets(apelido,sizeof(apelido),stdin);
			printf("Numero de golos: ");
			scanf("%i", &n_golos);				
			for(x=0; x < MAX_JOGADORES;++x){
				if(jogadores[x].activo==0){
					jogadores[x].id[x]=id[x];
					strcpy(jogadores[x].nome, nome);
					strcpy(jogadores[x].apelido, apelido);
					strcpy(jogadores[x].data_incio_contrato, data_incio_contrato);
					strcpy(jogadores[x].data_fim_contrato, data_fim_contrato);
					jogadores[x].n_golos=n_golos;
					jogadores[x].activo=1;
					break;
				}
			}
			
			fwrite(&jogadores, sizeof(Jogadores),1, arquivo);
			printf("\n\n1-Continuar\n0-Sair\n");
			scanf("%i", &a);
			
	}while(a!=0);
	system("cls");
}

void listar(){
	Jogadores jogador;
	int i; char imprime;
	system("cls");
	printf("\t\t Lista dos Jogadores");
	for(i=0;i<MAX_JOGADORES;++i){
		if(jogadores[i].activo==1){
			printf("\nId: %i\n",jogadores[i].id);
			printf("Apelido: %s",jogadores[i].apelido);
			printf("Nome: %s",jogadores[i].nome);
			printf("Data de inicio: %s\n",jogadores[i].data_incio_contrato);
			printf("Data de Fim: %s\n",jogadores[i].data_fim_contrato);
			printf("Numero de golos: %i",jogadores[i].n_golos);	
			printf("\n____________________________________\n");
			break;
		}
	}
	FILE*arquivo;
	arquivo= fopen("jogadores.txt", "r");
	imprime= fscanf(arquivo, "%i %s  %s %s %s %s %i", jogador.id, jogador.apelido, jogador.nome, jogador.data_incio_contrato, jogador.data_fim_contrato, jogador.n_golos);
	while(arquivo!=EOF){
		fprintf(arquivo, "%i %s  %s %s %s %s %i", jogador.id, jogador.apelido, jogador.nome, jogador.data_incio_contrato, jogador.data_fim_contrato, jogador.n_golos);
	}fclose(arquivo);
	
}