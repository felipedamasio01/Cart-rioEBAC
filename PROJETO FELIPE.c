#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar dos strings

int Registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("\tCADASTRO DE ALUNOS\n\n");
	
	printf("CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("NOME: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("SOBRENOME: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("CARGO: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int Consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\tCONSULTA DE ALUNOS\n\n");
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF n�o encontrado.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
	system("pause");
}

int Deletar()
{
	printf("Voc� escolheu a op��o Deletar.\n");
	system("pause");
}


int main()
{	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("--- Alunos da EBAC 2024 ---\n\n"); // inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Cadastrar:\n");
		printf("\t2 - Consultar:\n");
		printf("\t3 - Deletar:\n\n");
		printf("Op��o: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			Registro();
			break;
			
			case 2:
			Consulta();
			break;
			
			case 3:
			Deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
		}
	}
}
