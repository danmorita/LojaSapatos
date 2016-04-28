#include<stdio.h>
#include<stdlib.h>
#include "clientes.h"
#include "interface.h"

void main(){

	limpatela(0);
	int op;
	//Lista de clientes esta definida como um vetor de ponteiros para cliente  de 20 posicoes
	cliente * lista[20];
	initclientes(lista,20);// inicia a lista vazia
	
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
				inserircliente(lista , lecliente() , 20 );
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