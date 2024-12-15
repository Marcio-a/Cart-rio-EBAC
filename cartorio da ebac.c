#include <stdio.h> // biblioteca responsavel pela comunica��o com o usuario
#include <stdlib.h> // biblioteca de aloca��o de espa�o de memoria
#include <locale.h> // aloca��o de texto por regi�o
#include <string.h> // biblioteca de strings

int registrar(){

	char arquivo	[40];
	char cpf		[40];
	char nome		[40];
	char sobrenome	[40];
	char cargo		[40];
	
	printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);
		strcpy(arquivo, cpf); // copia os dados das strings
		
		FILE *file; //cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file,cpf); //salvo o valor da variavel
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
	fclose(file);
	
	
	printf("digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
	fclose(file);	
	
	
	printf("digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
	fclose(file);	
	
	printf("digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
	fclose(file);
	
	
	system("pause");
}

int consultar(){

	setlocale(LC_ALL, "Portuguese");


	char cpf 		[40];
	char conteudo 	[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		
		printf("n�mero de CPF n�o encontrado");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
	
		
		printf("\nessas s�o as informa��es dos usu�rios\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar(){

	char cpf[40]; 		//variavel a ser armazenada para uso na fun��o de deletar

	printf("digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf); 	// salva o cpf digitado pelo usu�rio na variavel cpf
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	if (file != NULL){
		remove(cpf);
		printf("usu�rio removido com sucesso\n");
		system("pause");
	}
	
	else{
		printf("erro ao remover usu�rio, usu�rio n�o encontrado\n");
		system("pause");
	}
		
}

int main(){
	
	int opcao=0; // definindo variaveis
	int x=1;
	
	for (x=1; x=1;)
	{
		system("cls");
		
		
		setlocale(LC_ALL, "portuguese"); // define a linguagem
		
		
		printf("###cart�rio da EBAC ### \n\n");
		printf("escolha a op��o desejada do menu: \n\n");
		printf("\t1 - registrar nomes \n");
		printf("\t2 - consultar nomes \n");
		printf("\t3 - deletar nomes \n\n");
		printf("op��o: ");
		
		scanf("%d", &opcao); // armazenando escolha do usu�rio
		
		system("cls");
		
		switch (opcao){  // op��es do menu principal
			
			case 1:
				registrar();
			break;
			
			case 2:
				consultar();
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("op��o indisponivel\n"); // caso o usu�rio escolha uma op��o deferente do esperado, responde como invalido
				system("pause");
				break;		
		}
	}
}
