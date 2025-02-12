#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{//int registro
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	//In�co da cria��o de vari�veis/strings
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s", cpf);// %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo - "w" significa escrever
	fprintf(file, "CPF: ");
	fprintf(file,cpf); // salvo o valor da vari�vel
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

int consulta()//Fun��o respons�vel por consultar os usu�rios no sistema
{//int consulta
	setlocale(LC_ALL, "Portuguese");
	
	//In�cio da cia��o das vari�veis/strings
	
	char cpf[40];
	char conteudo[200];
	
	//Final da cia��o das vari�veis/strings
	
	printf("Digite o CPF a ser consultado: ");//Coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");// "r" significa ler (read)
	
	if(file == NULL)// NULL significa nulo
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Extraindo as informa��es do arquivo para o usu�rio
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
	
}//int consulta

int deletar()//Fun��o respons�vel por deletar os usu�rios do sistema
{//int deletar
	setlocale(LC_ALL, "Portuguese");
	
	//In�cio da cia��o das vari�veis/strings
	
	char cpf[40]; 
	
	//Final da cia��o das vari�veis/strings
	
	printf("Digite o CPF do usu�rio a ser deletado: ");//Coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	remove(cpf);//Removendo as informa��es do usu�rio
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	 	
}//int deletar


	
int main()//Fun��o respons�vel pelo Menu
{//int main
		
	setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[20]="a";//Senha do login
	int comparacao;//Criando a vari�vel de compara��o
	
	printf("### Cart�rio da EBAC ###\n\n");//Tela de login
	printf("Login de administrador!\n Digite a sua senha: ");//Requisitando a senha de login
	scanf("%s",senhadigitada);//Armazenando a senha em uma vari�vel
	
	comparacao = strcmp(senhadigitada, "admin");//armazenando uma compara��o na vari�vel "comparacao"
	
	if(comparacao==0)//Se a senha estiver correta come�ao todo o comando
	{
		system("cls");
		
		for(laco=1;laco=1;)
		{

			system("cls");
			
			printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
			printf("Escolha a op��o desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n"); 
			printf("Op��o: ");//Fim do menu
				
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
			system("cls");//Respons�vel por limpar a tela
	
			switch(opcao) //In�cio da sele��o
			{
				case 1:
				registro();//Chamada de fun��es
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
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;//Fim da sele��o
			} 
		}
	}
	else
		printf("Senha inv�lida!");//Comando da senha inv�lida, n�o come�a o comando at� a senha estar correta
}//int main
