#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
Equipa *equipa;
//equipa=&Equipas;
Jogadores *jogadores;
//jogadores=&Jogador;	

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
	Equipa *equipas;
	char nome[17];
	int id[6];
	int a=0;
	int x;
	system("cls");
	printf("\tCadastrando Equipa\n");
	do{
			printf("Id: ");
			scanf("%p", &equipas->id);
			fflush(stdin);
			printf("Nome: ");
			fgets(equipa->nome,sizeof(nome),stdin);		
			
			for(x = 0; x < 5; ++x){
				if(equipa->activo==0){
				//	equipa->id=id[x];
					strcpy(equipa->nome, nome);
					equipa->activo=1;
					break;
				}
			}
			FILE *arquivo;
			arquivo= fopen("equipas.txt", "a");
			if(arquivo!=NULL){
			fprintf(arquivo, "%p %p", equipa->id, equipa->nome);
			}fclose(arquivo);
	
			fflush(stdin);
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
		fprintf(arquivo, "%p %p  %p %p %p %p %p", jogadores->id, jogadores->apelido, jogadores->nome, jogadores->data_incio_contrato, jogadores->data_fim_contrato, jogadores->n_golos);
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
			for(x=0; x < 7;++x){
				if(jogadores->activo==0){
					jogadores->id[x]=id[x];
					strcpy(jogadores->nome, nome);
					strcpy(jogadores->apelido, apelido);
					strcpy(jogadores->data_incio_contrato, data_incio_contrato);
					strcpy(jogadores->data_fim_contrato, data_fim_contrato);
					jogadores->n_golos=n_golos;
					jogadores->activo=1;
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
	for(i=0;i<17;++i){
		if(jogadores->activo==1){
			printf("\nId: %p\n",jogadores->id);
			printf("Apelido: %p",jogadores->apelido);
			printf("Nome: %p",jogadores->nome);
			printf("Data de inicio: %p\n",jogadores->data_incio_contrato);
			printf("Data de Fim: %p\n",jogadores->data_fim_contrato);
			printf("Numero de golos: %p",jogadores->n_golos);	
			printf("\n____________________________________\n");
			break;
		}
	}
	FILE*arquivo;
	arquivo= fopen("jogadores.txt", "r");
	imprime= fscanf(arquivo, "%p %p  %p %p %p %p %p", jogadores->id, jogadores->apelido, jogadores->nome, jogadores->data_incio_contrato, jogadores->data_fim_contrato, jogadores->n_golos);
	while(arquivo!=EOF){
		fprintf(arquivo, "%p %p  %p %p %p %p %p", jogadores->id, jogadores->apelido, jogadores->nome, jogadores->data_incio_contrato, jogadores->data_fim_contrato, jogadores->n_golos);
	}fclose(arquivo);
	
}
