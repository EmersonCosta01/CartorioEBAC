#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro() //Função responsável por cadastrar os usuários no sistema
{//int registro
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	//Iníco da criação de variáveis/strings
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Final da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informação do usuário
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo - "w" significa escrever
	fprintf(file, "CPF: ");
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");// "a" significa atualizar
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");//Coletando nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");//Coletando sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//Coletando cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}//int registro

int consulta()//Função responsável por consultar os usuários no sistema
{//int consulta
	setlocale(LC_ALL, "Portuguese");
	
	//Início da ciação das variáveis/strings
	
	char cpf[40];
	char conteudo[200];
	
	//Final da ciação das variáveis/strings
	
	printf("Digite o CPF a ser consultado: ");//Coletando informações do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");// "r" significa ler (read)
	
	if(file == NULL)// NULL significa nulo
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Extraindo as informações do arquivo para o usuário
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}//int consulta

int deletar()//Função responsável por deletar os usuários do sistema
{//int deletar
	setlocale(LC_ALL, "Portuguese");
	
	//Início da ciação das variáveis/strings
	
	char cpf[40]; 
	
	//Final da ciação das variáveis/strings
	
	printf("Digite o CPF do usuário a ser deletado: ");//Coletando informações do usuário
	scanf("%s", cpf);
	
	remove(cpf);//Removendo as informações do usuário
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	 	
}//int deletar


	
int main()//Função responsável pelo Menu
{//int main
		
	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[20]="a";//Senha do login
	int comparacao;//Criando a variável de comparação
	
	printf("### Cartório da EBAC ###\n\n");//Tela de login
	printf("Login de administrador!\n Digite a sua senha: ");//Requisitando a senha de login
	scanf("%s",senhadigitada);//Armazenando a senha em uma variável
	
	comparacao = strcmp(senhadigitada, "admin");//armazenando uma comparação na variável "comparacao"
	
	if(comparacao==0)//Se a senha estiver correta começao todo o comando
	{
		system("cls");
		
		for(laco=1;laco=1;)
		{

			system("cls");
			
			printf("### Cartório da EBAC ###\n\n"); //Início do menu
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n"); 
			printf("Opção: ");//Fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usuário
		
			system("cls");//Responsável por limpar a tela
	
			switch(opcao) //Início da seleção
			{
				case 1:
				registro();//Chamada de funções
				break;
			
				case 2:
				consulta();
				break;
		
				case 3:
				deletar();
				break;
			
				case 4://Encerra o programa
				printf("Obriado por utilizar o sistema!\n");
				return 0;
				break;
		
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;//Fim da seleção
			} 
		}
	}
	else
		printf("Senha inválida!");//Comando da senha inválida, não começa o comando até a senha estar correta
}//int main
