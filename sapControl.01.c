#include<stdio.h>
#include<stdlib.h>
/*Struct cliente
	atributos: código, nome, endereço, cidade, estado, telefone (ou celular), documento, e mail
*/

typedef struct Cliente{
	int codigo;
	char nome[50];
	char endereco[50];
	char cidade[50];
	char estado[10];
	int telefone;
	int documento;
	char email[50];

}cliente;

int showmenu(){

	int opt;
	printf("        CONTROLE DA LOJA         \n");
	printf(" 1- Listar clientes\n");
	printf(" 2- Inserir cliente\n");
	printf(" 3- Alterar Cliente\n");
	printf(" 4- Excluir Cliente\n");
	printf(" 0- Sair\n");
	scanf("%d",&opt);

	return(opt);
}
void freio(){
        char gambi[2];
	printf("\n\npressione qualquer tecla seguida de  [ENTER] para continuar...\n");
	scanf("%s",gambi);

}
void limpatela(int tipo){
	if(tipo == 1)
		freio();
	//para compilar no windowns descomente a linha abaixo e comente a seguinte
	//system("cls");
	system("clear");
}

void zeralista(cliente ** lista, int  tamanho){
	int i;	
	for(i  = 0; i < tamanho; i++){
		lista[i] = NULL;

	} 
}

cliente * lecliente(){
	cliente *cli;
	
	cli = (cliente *) malloc(sizeof(cliente));

	printf("Entre com os dados do cliente\n");
	printf("Codigo: ");
	scanf("%d",&cli->codigo);
	printf("\nNome Completo : ");
	scanf(" %[^\n]s",cli->nome);
	printf("\nEndereco completo : ");
	scanf(" %[^\n]s",cli->endereco);
	printf("\nCidade : ");
	scanf(" %[^\n]s", cli->cidade);
	printf("\nEstado (sigla) : ");	
	scanf(" %[^\n]s",cli->estado);
	printf("\nTelefone : ");
	scanf("%d",&cli->telefone);
	printf("\nDocumento : ");
	scanf("%d",&cli->documento);
	printf("\nEmail : ");
	scanf("%s", cli->email);

	return cli;

}
void removecliente( cliente ** lista, int tamanho,int codigocli){
	limpatela(0);
	int i=0, encontrado =0;
	if(lista[i] == NULL){
		printf("nao existem clientes para serem excluidos\n");

	}else{

		while( lista[i] != NULL && i < tamanho){
			if(lista[i]->codigo == codigocli){
				encontrado =1;
				//excluindo cliente
				
				printf("O cliente %s foi excluido da lista\n",lista[i]->nome);
				lista[i] = NULL;
				//realocamos os clientes na lista excluindo a lacula deixada
				while( lista[i+1] != NULL && i < tamanho){
					lista[i] = lista[i+1];
					i++;
				}
	
				break;
			
			}
			i++;
		}
	
		if(encontrado == 0 ){
			printf("nao foi encontrado nenhum cliente com o codigo: %d",codigocli);
		
		}
	}
	

}
void listarcliente( cliente ** lista, int tamanho){
	int i =0;
	limpatela(0);

	if(lista[i] == NULL){
		printf("nao existem clientes cadastrados\n");

	}else{
		printf("Lista de clientes cadastrados:\n\n");
	
	}

	while( lista[i] != NULL && i < tamanho){
		printf("Nome : %s \t Codigo: %d \nEndereco : %s\nCidade : %s \tEstado : %s\nTelefone : %d\tDocumento: %d\nEmail : %s\n",lista[i]->nome,lista[i]->codigo, lista[i]->endereco,lista[i]->cidade,lista[i]->estado,lista[i]->telefone,lista[i]->documento,lista[i]->email);
		printf("------------------------------------------------------------------------\n");

		i++;
	}	

}

void inserirnalista( cliente ** lista, cliente * cli , int tamanho){
	int i = 0;	
	while( lista[i] != NULL && i < tamanho){
		i++;
	}
	if(i == (tamanho-1)){
		printf("Memoria insuficiente\n");

	}else{
		printf("salvando na pos %d",i);
		lista[i] = cli;
	}

}
void main(){
	int op;
	//Lista de clientes esta definida como um vetor de ponteiros para cliente  de 20 posicoes
	cliente * lista[20];
	zeralista(lista,20);// inicia a lista vazia
	
	do{

		op = showmenu();
		
		switch(op){
			case 0:
				printf("Saindo.....\n");
				limpatela(1);
				break;
			case 1:
				listarcliente(lista,20);
				limpatela(1);
				break;
			case 2:
				inserirnalista(lista , lecliente() , 20 );
				limpatela(1);
				break;
			case 3:
				limpatela(0);
				printf("Esse recurso ainda nao foi implementado\n");
				limpatela(1);
				break;
			case 4:
				limpatela(0);
				printf("Informe o codigo do cliente que deseja exlcuir\n");
				int cod;
				scanf("%d",&cod);
				removecliente(lista,20,cod);
				limpatela(1);
				break;
			default:
				printf("Opcao invalida\n");
				limpatela(1);
				break;


		}
	
	}while(op != 0);

	

}
