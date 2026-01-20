#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblioteca de alocação de espaço em momoria 
#include <locale.h> // bilbioteca de alocações de texto por região 
#include <string.h> // biblioteca responsável por cuidar das string

int registro() // Função responsavel por cadastrar os usuarios no sistema 
{
  // inicio criação de variaveis/string
  
  char arquivo [40];    // criamos as variaveis 
  char cpf [40];
  char nome[40];
  char sobrenome [40];
  char cargo [40];
  // final da criação de variaveis/string
  
  
  printf ("Digite o cpf a ser cadastrado: "); // coletando informações do usuário 
  scanf ("%s", cpf); // %s refere-se string
  
  strcpy(arquivo, cpf); // Responsavel por copiar os valores das string
  
  FILE *file; // cria arquivo 
  file = fopen(arquivo, "w"); // cria arquivo 
  fprintf (file,cpf); // salvo o valor da variavel 
  fclose(file); // fecha o arquivo
  
  file = fopen (arquivo, "a");
  fprintf (file, ",");
  fclose(file);
  
  printf ("Digite o nome a ser cadastrado: ");
  scanf ("%s", nome);
  
  file = fopen (arquivo, "a");
  fprintf(file,nome);
  fclose(file);
  
  file = fopen (arquivo, "a");
  fprintf (file, ",");
  fclose(file);
  
  printf ("Digite o sobrenome a ser cadastrado: ");
  scanf ("%s", sobrenome);
  
  file = fopen (arquivo, "a");
  fprintf (file,sobrenome);
  fclose(file);
  
  file = fopen (arquivo, "a");
  fprintf (file, ",");
  fclose(file);
  
  printf ("Digite o cargo a ser cadastrado: ");
  scanf ("%s", cargo);
  
  file = fopen (arquivo, "a");
  fprintf (file,cargo);
  fclose (file);
  
  system ("pause");
  
  
  
  
}

int consulta()

{

  setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
  char cpf [40];
  char conteudo [200];
  
  printf("Digite o CPF a ser consultado: ");
  scanf("%s",cpf);
  
  FILE *file;
  file = fopen(cpf,"r");
  
  if(file == NULL)
  
  {
 printf("Não foi possivel abrir o arquivo, não localizado!.\n");
  	
  }
  
  while(fgets (conteudo, 200, file) != NULL)
  
  {
  	printf ("\n Essas são as informações do usuário: ");
  	printf("%s", conteudo);
  	printf("\n\n");
  	
  }
    system("pause");
}

int deletar()
{
 
 char cpf[40];
 
 printf("Digite o CPF a ser cancelado: ");
 scanf("%s",cpf);
 
 remove(cpf);
 
 FILE *file;
 file = fopen(cpf,"r");
 
 if(file == NULL)
 {
 printf("O usúario não se encontra no sistema!.\n");
 
 system("pause");
 	
 }
	
}

 int main()
   {
	  
	  int opcao=0; // definindo variavel 
	  int laco=1; // foi criado essa variavel, para o comando de repetição
	  char senhadigitada [10]="a";
	  
	  printf("### Cartorio da EBAC ###\n\n");
	  printf("Login de administrador!\n\nDigite a sua senha: " );
	  scanf("s", senhadigitada);
	  
	  if(senhadigitada[10] == "admin");
	   {
	  
	  
	         for(laco=1;laco=1;)  // comando de repetições começa do { até } do abraço 
	         {
	  	
	         system("cls");
	    
	  
	         setlocale(LC_ALL, "Portuguese"); // Definindo o idioma 
	 
	         printf("### Cartorio da EBAC ###\n\n"); // inicio do menu 
	         printf("Escolha a opção desejada do menu:\n\n");
	         printf("\t1 - Registrar nomes\n");  // \t1 é para inserir linha 1 linha 2 e por assim adiante 
	         printf("\t2 - Consultar nomes\n");
	         printf("\t3 - Deletar nomes\n\n"); 
	         printf("Por favor escolha a opção: \n");// fim do menu
	  
	          printf("OBS: Esse software é de livre uso dos alunos\n\n");
	 
	         scanf("%d", &opcao); // serve para colher a informação do usuario da variavel declarada "armazenando a escolha do úsuario"
	  
	         system("cls"); // essa fução serve para apagar mensagens anteriores 
	  
	         switch(opcao)
	          {
	  	     case 1:
	     	registro();
	     	break;
		
		
		     case 2:
	         consulta();	
	       	break;
		
		
	       	 case 3:
	         deletar();		
	     	 break;
		
	    	 default:
		     printf("Essa opção não está disponivel!\n"); // fim da seleção
	         system("pause");
		     break;	
	  	
	         }   
	  
	  
	         }
             }
             
      else 
      printf("Senha incorreta!");
     
      
      
  
   }
             
             

