#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar dos strings

int Registro() //função responsavel por cadastrar os usuários no sistema
{   //Inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int opcao;
	//Final da criação de variáveis/string
	do{
	printf("\tCADASTRO DE ALUNOS\n\n"); //titulo da função
	
	printf("CPF: "); //Coletando a informação do usuário
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
		printf("CPF não encontrado.\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("CPF não encontrado!\n");	
	}
	
	printf("\nDeseja deletar outro aluno?\n1 - Sim\n2 - Voltar ao menu\n");
	scanf("%d", &opcao);

	system("cls");
    }while (opcao == 1);

    return 0;
}


int main()
{			
	int opcao=0; //Definindo variáveis
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
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Cadastrar:\n");
			printf("\t2 - Consultar:\n");
			printf("\t3 - Deletar:\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuário
		
			system("cls"); //Responsavel por limpar a tela
		
			switch(opcao) //Inicio da seleção do menu
			{
				case 1:
				Registro(); //Chamada de funções
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
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			} //Fim da seleção
		}
   	}
   	
   	else
		printf("Senha incorreta");
   	
}
