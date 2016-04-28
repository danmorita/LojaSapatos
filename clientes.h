#ifndef _CLIENTESH_
#define _CLIENTESH_

#include<stdio.h>
#include "interface.h"

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

void initclientes(cliente ** lista, int  tamanho){
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

void inserircliente( cliente ** lista, cliente * cli , int tamanho){
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

#endif