#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar dos strings

int Registro() //fun��o responsavel por cadastrar os usu�rios no sistema
{   //Inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int opcao;
	//Final da cria��o de vari�veis/string
	do{
	printf("\tCADASTRO DE ALUNOS\n\n"); //titulo da fun��o
	
	printf("CPF: "); //Coletando a informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string*
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "W" significa escrever
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
	
	printf("\nDeseja cadastrar outro aluno?\n1 - Sim\n2 - Voltar ao menu\n");
    scanf("%d", &opcao);

	system("cls");
    }while (opcao == 1);

    return 0;
}

int Consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	int opcao;
	
	do{
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
		
	printf("\nDeseja consultar outro aluno?\n1 - Sim\n2 - Voltar ao menu\n");
    scanf("%d", &opcao);

	system("cls");
    }while (opcao == 1);

    return 0;
}

int Deletar()
{
	char cpf[40];
	int opcao;
	
	do{
	printf("\tDeletar ALUNO\n\n");
	
	printf("Digite CPF: ");
	scanf ("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o encontrado!\n");	
	}
	
	printf("\nDeseja deletar outro aluno?\n1 - Sim\n2 - Voltar ao menu\n");
	scanf("%d", &opcao);

	system("cls");
    }while (opcao == 1);

    return 0;
}


int main()
{			
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao; 
	
	printf("\t\tAlunos da EBAC 2024 \t \n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)
		{
			
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("\t\tAlunos da EBAC 2024\t\t\n\n"); //Inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Cadastrar:\n");
			printf("\t2 - Consultar:\n");
			printf("\t3 - Deletar:\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
			system("cls"); //Responsavel por limpar a tela
		
			switch(opcao) //Inicio da sele��o do menu
			{
				case 1:
				Registro(); //Chamada de fun��es
				break;
				
				case 2:
				Consulta();
				break;
			
				case 3:
				Deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!");
				return 0;
				break;
			
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;
			} //Fim da sele��o
		}
   	}
   	
   	else
		printf("Senha incorreta");
   	
}
