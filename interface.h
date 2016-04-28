#ifndef _INTERFACEH_
#define _INTERFACEH_

#include<stdio.h>
#include<stdlib.h>

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

void pause(void){
	printf("\n\npressione qualquer tecla para continuar...\n");
	getchar();

}

void limpatela(int tipo){
	if(tipo == 1){
		pause();
	}
	//para compilar no windowns descomente a linha abaixo e comente a seguinte
	//system("cls");
	system("clear");
}

#endif