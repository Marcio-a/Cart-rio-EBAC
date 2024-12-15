#include <stdio.h> // biblioteca responsavel pela comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço de memoria
#include <locale.h> // alocação de texto por região
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
		
		printf("número de CPF não encontrado");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
	
		
		printf("\nessas são as informações dos usuários\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar(){

	char cpf[40]; 		//variavel a ser armazenada para uso na função de deletar

	printf("digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf); 	// salva o cpf digitado pelo usuário na variavel cpf
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	if (file != NULL){
		remove(cpf);
		printf("usuário removido com sucesso\n");
		system("pause");
	}
	
	else{
		printf("erro ao remover usuário, usuário não encontrado\n");
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
		
		
		printf("###cartório da EBAC ### \n\n");
		printf("escolha a opção desejada do menu: \n\n");
		printf("\t1 - registrar nomes \n");
		printf("\t2 - consultar nomes \n");
		printf("\t3 - deletar nomes \n\n");
		printf("opção: ");
		
		scanf("%d", &opcao); // armazenando escolha do usuário
		
		system("cls");
		
		switch (opcao){  // opções do menu principal
			
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
				printf("opção indisponivel\n"); // caso o usuário escolha uma opção deferente do esperado, responde como invalido
				system("pause");
				break;		
		}
	}
}
