#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int main(){
    char pause;
    int opcao;
    printf("Bem vindo ao Negrinho do Pastoreio CompilatorCode 3000 \nEscolha uma opção!\n1 - Criptografar\n2 - Descriptografar\n");
    scanf("%d", &opcao);
    switch (opcao){
    case 1:{
        setlocale(LC_ALL, "Portuguese"); 
    	char mensagem[500];
    	char senha[16];
    	int cifrada[500];
    	printf("Escreva uma mensagem no qual deseja criptografar: "BLU);
		scanf(" %500[^\n]s", mensagem);
    	printf(RESET"Escreva uma senha para criptografar a mensagem: "RED);
    	scanf(" %16[^\n]s", senha);
    	printf(RESET"A mensagem Criptografada é: \n\n");
    	for(int i=0 ;  i<strlen(mensagem)  ;  i++){
        	cifrada[i] = (mensagem [i] ^ senha[i%strlen(senha)]);
    		printf(GRN "%02X" RESET, cifrada[i]);
    	}
		printf("\n");
		//for(int i=0 ;  i<strlen(mensagem)  ;  i++){
		//	printf("%d ", cifrada[i]);
		//}
    	//cifrada = mensagem^senha;
        scanf("%c", &pause);
    	return 0;
    }
    	
   	case 2:{
    	setlocale(LC_ALL, "Portuguese");
		char mensagem[500];
		char senha[16];
		char hex[1000];
		int cifrada[500];
		int num[500];
		int count = 0;
		printf("Escreva a mensagem Criptografada: "GRN);
		scanf(" %1000[^\n]s", hex);

		for(int i=0; i < strlen(hex);i+=2){
			char hexa[2];
			hexa[0]=hex[i];
			hexa[1]=hex[i+1];
			char *res;
			num[i/2] = strtol(hexa, &res, 16);
			cifrada[i/2] = num[i/2];
			count++;
		}
		printf(RESET"Escreva a senha para Descriptografar a 	mensagem: "RED);
		scanf(" %16[^\n]s", senha);
		printf(RESET"A mensagem Original é: \n\n");
    	for(int i=0 ;  i<count; i++){
    		//printf(BLU "|%d|" RESET, cifrada[i]);
        	mensagem[i] = (cifrada[i]) ^ senha[i%strlen(senha)];
    		printf(BLU "%c" RESET, mensagem[i]);
    	}
        scanf("%c", &pause);
		return 0;

    }
	}
}