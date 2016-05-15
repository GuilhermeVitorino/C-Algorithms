/*****************************************************/
/* Nome: Guilherme Vitorino da Silva                 */
/* Topicos de Programacao 2016                       */
/*****************************************************/
/* Arquivo final (gerado dia 08/01/2016)             */
/*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 100
#define ARGS_SIZE 10
#define TEL_SIZE 20

struct _contato {
    char nome[STRING_SIZE];
    char sobrenome[STRING_SIZE];
    char endereco[STRING_SIZE];
    char telefone[TEL_SIZE];
    char email[STRING_SIZE];     
};

typedef struct _contato item;

struct _celula {
   item info;
   struct _celula* prox;
};

typedef struct _celula* agenda;

void strtrim(char* str) {
    int idx, size;
    size = strlen(str);
    for (idx = size - 1; idx >= 0 && 
            (str[idx] == '\n' || str[idx] == ' '); str[idx--] = '\0');
}

agenda createAgenda() {
   agenda cabeca;
   cabeca = (agenda) malloc(sizeof(*cabeca));

   if (cabeca == NULL) {
      printf("Erro no malloc da cabeca \n");
      exit(1);
   }
   
   return cabeca;
}

int addEntry(char *cmd, int argc, char **argv, agenda ag) {
    
    char *nome, *sobrenome, *endereco, *telefone, *email;
    agenda novo, anterior, atual;
       
    novo = malloc(sizeof(*novo));
    anterior = malloc(sizeof(*anterior));
    atual = malloc(sizeof(*atual));
   
    nome = malloc(STRING_SIZE * sizeof(char));
    sobrenome = malloc(STRING_SIZE * sizeof(char));
    endereco = malloc(STRING_SIZE * sizeof(char));
    telefone = malloc(TEL_SIZE * sizeof(char));
    email = malloc(STRING_SIZE * sizeof(char));

    if (novo == NULL) {
      printf("Erro no malloc da variavel novo\n");
      exit(1);
    }

    if (anterior == NULL) {
      printf("Erro no malloc da variavel anterior\n");
      exit(1);
    }

    if (atual == NULL) {
      printf("Erro no malloc da variavel atual\n");
      exit(1);
    }
   
    if (nome == NULL) {
      printf("Erro no malloc da variavel nome\n");
      exit(1);
    }

    if (sobrenome == NULL) {
      printf("Erro no malloc da variavel sobrenome\n");
      exit(1);
    }

    if (endereco == NULL) {
      printf("Erro no malloc da variavel endereco\n");
      exit(1);
    }

    if (telefone == NULL) {
      printf("Erro no malloc da variavel telefone\n");
      exit(1);
    }
    
    if (email == NULL) {
      printf("Erro no malloc da variavel email\n");
      exit(1);
    }

    printf("Nome: ");
    fgets(nome, STRING_SIZE, stdin);
    printf("Sobrenome: ");
    fgets(sobrenome, STRING_SIZE, stdin);
    printf("Endereco: ");
    fgets(endereco, STRING_SIZE, stdin);
    printf("Telefone: ");
    fgets(telefone, TEL_SIZE, stdin);
    printf("Email: ");
    fgets(email, STRING_SIZE, stdin);
    
    strtrim(nome);
    strtrim(sobrenome);
    strtrim(endereco);
    strtrim(telefone);
    strtrim(email);

    strcpy(novo->info.nome, nome);
    strcpy(novo->info.sobrenome, sobrenome);
    strcpy(novo->info.endereco, endereco);
    strcpy(novo->info.telefone, telefone);
    strcpy(novo->info.email, email);
 
    anterior = ag;
    atual = ag->prox;

    while(atual != NULL){

      if(strcmp(atual->info.nome, novo->info.nome) > 0)
         break;
     
      anterior = anterior->prox;
      atual = atual->prox;	
    }
   
    novo->prox = anterior->prox;
    anterior->prox = novo;
  
    free(nome);
    free(sobrenome);
    free(endereco);
    free(telefone);
    free(email);

    printf("Salvo\n");
    return 0;
}

void addEntryInOrder(agenda ag, item contato, char *paramOrd) {
    printf("entrou na funcao\n");
    agenda novo, anterior, atual;

    novo = malloc(sizeof(*novo));
    anterior = malloc(sizeof(*anterior));
    atual = malloc(sizeof(*atual));

    if (novo == NULL) {
        printf("Erro no malloc da variavel novo\n");
        exit(1);
    }

    if (anterior == NULL) {
        printf("Erro no malloc da variavel anterior\n");
        exit(1);
    }

    if (atual == NULL) {
        printf("Erro no malloc da variavel atual\n");
        exit(1);
    }
      
    anterior = ag;
    atual = ag->prox;
    novo->info = contato;

    while (atual != NULL) {

        if(strcmp(paramOrd, "sobrenome") == 0 
            && strcmp(atual->info.sobrenome, novo->info.sobrenome) > 0)
            break;

        if(strcmp(paramOrd, "endereco") == 0 
            && strcmp(atual->info.endereco, novo->info.endereco) > 0)
            break;

        if(strcmp(paramOrd, "telefone") == 0 
            && strcmp(atual->info.telefone, novo->info.telefone) > 0)
            break;

        if(strcmp(paramOrd, "email") == 0 
            && strcmp(atual->info.email, novo->info.email) > 0)
            break;	
     
        anterior = anterior->prox;
        atual = atual->prox;
    }

    novo->prox = anterior->prox;
    anterior->prox = novo;
}

int deleteEntry(char *cmd, int argc, char **argv, agenda ag) {

    char *argumento, *nome, *sobrenome;
    agenda anterior, atual, celDel;
    int deletou = 0;    

    anterior = malloc(sizeof(agenda*));
    atual = malloc(sizeof(agenda*));

    if (anterior == NULL) {
      printf("Erro no malloc da variavel anterior\n");
      exit(1);
    }

    if (atual == NULL) {
      printf("Erro no malloc da variavel atual\n");
      exit(1);
    }
    
    nome = malloc(STRING_SIZE * sizeof(char));
    sobrenome = malloc(STRING_SIZE * sizeof(char));
    argumento = malloc(STRING_SIZE * sizeof(char));

    if (argc == 0) {
        printf("Informe o criterio de exclusao (nome ou sobrenome)\n");
        return 0;
    }

    argumento = argv[0];

    anterior = ag; 
    atual = ag->prox;

    if (strcmp(argumento, "nome") == 0) {
        printf("Nome: ");
        fgets(nome, STRING_SIZE, stdin);
        strtrim(nome);

        while (atual != NULL) {
            	
            if (strcmp(atual->info.nome, nome) == 0) {
            	celDel = atual;         
                anterior->prox = atual->prox;
                atual = anterior->prox;
                free(celDel);
                deletou = 1;
                break;
            } else {
                anterior = anterior->prox; 
                atual = atual->prox;
            }
       }
    }

    else if (strcmp(argumento, "sobrenome") == 0) {
        printf("Sobrenome: ");
        fgets(sobrenome, STRING_SIZE, stdin);
        strtrim(sobrenome);
 		 		        
        while (atual != NULL) {
        	
            if (strcmp(atual->info.sobrenome, sobrenome) == 0) {          
                celDel = atual;
                anterior->prox = atual->prox;
                atual = anterior->prox;
                free(celDel);
                deletou = 1;
                break;
            } else {
                anterior = anterior->prox; 
                atual = atual->prox;
            }
       }
    }
       
    if (deletou == 0) {
        if (strcmp(argumento, "nome") == 0)   
            printf("Nao existe ninguem com o nome %s\n", nome);
        else if (strcmp(argumento, "sobrenome") == 0)
            printf("Nao existe ninguem com o sobrenome %s\n", sobrenome);
        else 
        	printf("Informe corretamente o criterio de exclusao (nome ou sobrenome)\n");
    } else {
        printf("Deletado!\n");
    }

    free(nome);
    free(sobrenome);

    return 0;
}

int listEntries(char *cmd, int argc, char **argv, agenda ag) {
    char *argumento, *nome, *sobrenome;
    agenda novaOrdenacao, aux;

    novaOrdenacao = createAgenda();
    argumento = argv[0];
    
    aux = ag->prox;
    
    if (strcmp(argumento, "sobrenome") == 0 ||
        strcmp(argumento, "endereco") == 0 ||
        strcmp(argumento, "telefone") == 0 ||
        strcmp(argumento, "email") == 0) {
 
        while (aux != NULL) {
            addEntryInOrder(novaOrdenacao, aux->info, argumento);
            aux = aux->prox;    
        }

        printf("Listando por %s...\n", argumento);
        printf("%-17s | %-17s | %-17s | %-12s | %-17s\n", "Nome", "Sobrenome", "Endereco", "Telefone", "e-mail");

        aux = novaOrdenacao->prox;

        while(aux != NULL){
            printf("%-17s", aux->info.nome);
            printf(" | %-17s", aux->info.sobrenome);
            printf(" | %-17s", aux->info.endereco);
            printf(" | %-12s", aux->info.telefone);
            printf(" | %-17s\n", aux->info.email);
            aux = aux->prox;
        }

        printf("\n");
        return 0;
    }
      
    printf("Listando por nome...\n");
    printf("%-17s | %-17s | %-17s | %-12s | %-17s\n", "Nome", "Sobrenome", "Endereco", "Telefone", "e-mail");

    while(aux != NULL){
      printf("%-17s", aux->info.nome);
      printf(" | %-17s", aux->info.sobrenome);
      printf(" | %-17s", aux->info.endereco);
      printf(" | %-12s", aux->info.telefone);
      printf(" | %-17s\n", aux->info.email);
      aux = aux->prox;
    }

    printf("\n");
    return 0;
}

// A partir daqui não precisa mexer... mas é BEM interessante olhar :)
int unknown(char* cmd, int argc, char **argv, agenda ag) {
    printf("Comando '%s' não conhecido\n", cmd);
    return 0;
}

int normalexit(agenda ag) {
	agenda aux, celDel;
	aux = malloc(sizeof(agenda*));
    aux = ag->prox;

    while(aux != NULL){
        celDel = aux;
        aux = aux->prox;
        free(celDel);
    }

    free(ag);
    free(aux);

    printf("Fechando agenda e saindo...\n");
    exit(0);
}

int helptext() {
    printf("Comandos aceitos\n");
    printf(" novo: cria uma nova entrada na agenda\n");
    printf(" listar: lista as entradas da agenda\n");
    printf(" apagar: deleta uma entrada da agenda\n");
    printf(" sair (ou exit): sair do programa\n");
    printf(" help (ou comandos): lista os comandos validos\n");
    return 0;
}

int (*findCommand(char *cmdName)) (char*, int, char**, agenda) {
    if (strcmp(cmdName, "novo") == 0) {
        return &addEntry;
    }

    if (strcmp(cmdName, "apagar") == 0) {
        return &deleteEntry;
    }

    if (strcmp(cmdName, "listar") == 0) {
        return &listEntries;
    }

    if (strcmp(cmdName, "sair") == 0 || strcmp(cmdName, "exit") == 0) {
        return (int (*)(char*, int, char**, agenda)) &normalexit;
    }

    if (strcmp(cmdName, "help") == 0 || strcmp(cmdName, "comandos") == 0) {
        return (int (*)(char*, int, char**, agenda)) &helptext;
    }

    return &unknown;
} 

int main() {
    char *s, *buf, *cmd, **args;
    int i, pos;
    buf = malloc(STRING_SIZE * sizeof(char));
    cmd = malloc(STRING_SIZE * sizeof(char));

    agenda ag = createAgenda();

    args = malloc(ARGS_SIZE * sizeof(char*));
    for (i = 0; i < ARGS_SIZE; i++) {
        args[i] = malloc(STRING_SIZE * sizeof(char));
    }

    printf("Agenda Topicos de Programacao 2016\n");
    while (1) {
        printf("> ");
        if (fgets(buf, STRING_SIZE, stdin) == NULL) normalexit(ag);

        sscanf(buf, "%s %n", cmd, &pos);

        s = buf + pos;

        i = 0;
        while (sscanf(s, "%s %n", args[i], &pos) != EOF) {
            i++;
            s = s + pos;
        }

        int (*foo)(char*, int, char**, agenda) = findCommand(cmd);
        (*foo)(cmd, i, args, ag);
    }

    free(buf);
    free(cmd);

    return 0;
}

