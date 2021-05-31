#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //Para a função getch();
#define MAX_PATRIMONIOS 50
typedef struct{
    char nome[50];
    char data[12];
    int ativo; //0->inativo...1->ativo;
    int id;
    char marca[50];
    char setor[50];
    char status[50];
    //manutencao
    char tecnico[50];
    char datamanutencao[12];
    char descricao_status[100];
    //movimentacao
    char data_transferencia[12];
    char data_retorno[12];
    char setor_origem [50];
    char setor_destino [50];
    int status_transferencia;               //Se for igual a 1 o patrimonio deve ser mostrado, se for 0 não
} patrimonio;

patrimonio patrimonios[MAX_PATRIMONIOS];    //Vetor de patrimonios usando a struct patrimonio
                                            //MAX_PATRIMONIOS define o limite da quantidade de patrimonios

void cadastrar(){
	char nome[50];
    char data[12];
    int id;
    char marca[50];
    char setor[50];
    char tecnico[50];
    char datamanutencao[12];
    char status[50];
    int ativo;
    int op=1;
    system("cls"); //Limpa o terminal


    while(op!=0){

        FILE *pat_arq; //Cria o ponteiro para o arquivo

        pat_arq = fopen("arquivo_patrimonios.txt","a"); //Abre o arquivo no modo de adição de dados "a"
        //Caso o arquivo não exista, criará um novo

        printf("*-------------------------*\n");
        printf("| Cadastrar um Patrimonio |\n");
        printf("*-------------------------*\n");
        printf("ID: ");
        scanf("%d",&id);
        printf("\nNome: ");
        scanf("%s",&nome);
        printf("\nSetor: ");
        scanf("%s",&setor);
        printf("\nData de aquisicao: ");
        scanf("%s",&data);
        printf("\nMarca: ");
        scanf("%s",&marca);
        for (int i = 0;i< MAX_PATRIMONIOS;i++){
            if (patrimonios[i].ativo==0){                   //0->inativo...1->ativo - usar na baixa de patrimonios
                patrimonios[i].id = id;
                strcpy(patrimonios[i].data, data);
                strcpy(patrimonios[i].nome, nome);
                strcpy(patrimonios[i].marca, marca);
                strcpy(patrimonios[i].status, "OK!");
                strcpy(patrimonios[i].setor, setor);
                patrimonios[i].ativo=1;

                //Registra os dados no arquivo
                fprintf(pat_arq, "\nId:        #%d\n", id);
                fprintf(pat_arq, "Nome:      %s\n", nome);
                fprintf(pat_arq, "Setor:     %s\n", setor);
                fprintf(pat_arq, "Aquisição: %s\n", data);
                fprintf(pat_arq, "Marca:     %s\n\n", marca);
                fprintf(pat_arq,"--------------------------\n");

                fclose(pat_arq);      //Fecha o arquivo

                printf("\nCadastro realizado com sucesso!\n");
                break;}}
        printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d",&op);}}

void inventario(){
    int id,d;
    system("cls");
    printf("*----------------------------*\n");
    printf("| Inventario de Patrimonios  |\n");
    printf("*----------------------------*\n");
    for (int i = 0; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].ativo==1){
        printf("\n---------------");
        printf("\nID:   #%d",patrimonios[i].id);
        printf("\nNome: %s\n\n",patrimonios[i].nome);
        }}
        printf("Digite qualquer tecla para continuar\n\n");
        getch();} //pausa na tela até uma tecla ser digitada

void mostra1(){
    int id;
    int op = 1;
    system("cls");
    while(op!=0){
        printf("*-------------------------------------*\n");
        printf("| Exibir um Patrimonio detalhadamente |\n");
        printf("*-------------------------------------*\n");
        printf("\nDigite o id do patrimonio: #\n");
        scanf("%d",&id);
        for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].id == id){
            printf("\n---------------");
            printf("\nID:     #%d",patrimonios[i].id);
            printf("\nNome:   %s",patrimonios[i].nome);
            printf("\nData:   %s",patrimonios[i].data);
            printf("\nSetor:  %s",patrimonios[i].setor);
            printf("\nMarca:  %s",patrimonios[i].marca);
            printf("\nStatus: %s",patrimonios[i].status);
            if (strcmp(patrimonios[i].status,"Em Manutencao")==0){
                printf("\n-----------------------------------------------");
                printf("\nTecnico Responsavel: %s",patrimonios[i].tecnico);
                printf("\nData da Manutencao:  %s",patrimonios[i].datamanutencao);
                printf("\nDescricao:  %s\n",patrimonios[i].descricao_status);
            }
        }
        }printf("\n\nDeseja pesquisar outro Patrimonio?\n0 - Nao\n1 - Sim\n");
    scanf("%d",&op);
    }}


void baixa(){
    system("cls");
    printf("*--------------------------------*\n");
    printf("| Efetuar Baixa de um Patrimonio | \n");
    printf("*--------------------------------*\n");
    int id;
    inventario();
    printf("Digite o ID do patrimonio a ser removido: #");
    scanf("%d",&id);
    for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if(patrimonios[i].id==id){
        strcpy(patrimonios[i].status,"Indisponivel");            //torna o status patrimonio como inativo
        patrimonios[i].ativo=0;                             //tira o patrimonio do inventario (ainda ? possivel acessar pelo mostra1())
        printf("\nBaixa efetuada com sucesso!\n\n");
        getch();
}}}

void edicao(){
    int id, op = 1,opcao;
    while(op==1){
    system("cls");
    printf("*---------------------------------*\n");
    printf("| Efetuar Edicao de um Patrimonio | \n");
    printf("*---------------------------------*\n");
    printf("Digite o ID do patrimonio a ser editado: #");
    scanf("%d" ,&id);
    for(int i = 0; i < MAX_PATRIMONIOS; i++){
          if(patrimonios[i].id==id && strcmp(patrimonios[i].status,"Indisponivel")==0){
            printf("[ERRO] Nao foi possivel encontrar este patrimonio. Verique o inventario.");}
          else if(patrimonios[i].id==id){
          system("cls");
          printf("\n------------------------");
          printf("\n|     Patrimonio       |");
          printf("\n------------------------\n");

          printf("\n1-ID:     #%d",patrimonios[i].id);
          printf("\n2-Nome:   %s",patrimonios[i].nome);
          printf("\n3-Data:   %s",patrimonios[i].data);
          printf("\n4-Setor:  %s",patrimonios[i].setor);
          printf("\n5-Marca:  %s",patrimonios[i].marca);
          printf("\n------------------------");
          printf("Qual informacao deseja editar? ");
          scanf("%d",&opcao);
            if(opcao==1){
              printf("\nDigite o novo ID: ");
              scanf("%d" ,&patrimonios[i].id);}
            if(opcao==2){
              printf("\nDigite o novo Nome: ");
              scanf("%s" ,&patrimonios[i].nome);}
            if(opcao==3){
              printf("\nDigite a nova Data: ");
              scanf("%s" ,&patrimonios[i].data);}
            if(opcao==4){
              printf("\nDigite o novo Setor: ");
              scanf("%s" ,&patrimonios[i].setor);}
            if(opcao==5){
              printf("\nDigite a nova Marca: ");
              scanf("%s" ,&patrimonios[i].marca);}
          printf("\n------------------------");
          printf("\n Patrimonio editado com sucesso!");

          }
      }printf("\n1 - Continuar\n0 - Sair\n");
       scanf("%d" ,&op);
    }
}


void movimentacao(){
    system("cls");
    printf("*-----------------------*\n");
    printf("| Transferir Patrimonio |\n");
    printf("*-----------------------*\n");
    int id,op=1;
    char setor_destino[50];
    char data_transferencia[12];
    char data_retorno[12];
    while(op==1){

    printf("Digite o ID do patrimonio que foi movido: #");
    scanf("%d",&id);
    for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if(patrimonios[i].id==id && strcmp(patrimonios[i].status,"Indisponivel")==0){
            printf("[ERRO] Nao foi possivel encontrar este patrimonio. Verique o inventario.");
           }
        else if(patrimonios[i].id==id){
        printf("\nEscolha uma opcao:\n");
        printf("1-Transferencia Definitiva:\n");
        printf("2-Transferencia provisoria:\n");
        printf("3-Declarar retorno:\n");
        int opc;
        FILE *patm_arq;

        patm_arq = fopen("arquivo_movimentacao.txt","a");

        scanf("%d", &opc);
        if (opc == 1){
            printf("\nData de Transferencia: ");
            scanf("%s",&data_transferencia);
                printf("\nSetor de destino: ");
            scanf("%s",&setor_destino);
            for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
                if(patrimonios[i].id==id){
                fprintf(patm_arq, "\nId:                 #%d\n", id);
                fprintf(patm_arq, "\n   Tranferencia Definitiva   \n");
                strcpy(patrimonios[i].setor_origem,patrimonios[i].setor);
                fprintf(patm_arq, "Setor Origem:          %s\n", patrimonios[i].setor);

                strcpy(patrimonios[i].setor,setor_destino);
                fprintf(patm_arq, "Setor Atual:           %s\n", patrimonios[i].setor);

                strcpy(patrimonios[i].data_transferencia,data_transferencia);
                fprintf(patm_arq, "Data de Transferencia: %s\n",patrimonios[i].data_transferencia );

                fprintf(patm_arq,"-------------------------------------------\n");
                strcpy(patrimonios[i].status,"OK!");
                patrimonios[i].status_transferencia = 1;                   //mostra que ja foi transferido

                printf("\nTransferencia efetuada com sucesso!\n\n");
                fclose(patm_arq);      //Fecha o arquivo
}
        }}
        if (opc == 2){
            printf("\nData de Transferencia: ");
            scanf("%s",&data_transferencia);
            printf("\nData de retorno: ");
            scanf("%s",&data_retorno);
            printf("\nSetor de destino: ");
            scanf("%s",&setor_destino);

            for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
                if(patrimonios[i].id==id){
                fprintf(patm_arq, "\nId:                    #%d\n", id);
                fprintf(patm_arq, "\n   Tranferencia Provisoria   \n");

                strcpy(patrimonios[i].data_transferencia,data_transferencia);
                fprintf(patm_arq, "Data de Transferencia: %s\n",patrimonios[i].data_transferencia );

                strcpy(patrimonios[i].data_retorno,data_retorno);
                fprintf(patm_arq, "Data de Retorno:       %s\n",patrimonios[i].data_retorno );

                strcpy(patrimonios[i].setor_origem,patrimonios[i].setor);
                fprintf(patm_arq, "Setor de Origem:       %s\n",patrimonios[i].setor_origem );

                strcpy(patrimonios[i].setor_destino,setor_destino);
                fprintf(patm_arq, "Setor Destino:         %s\n",patrimonios[i].setor_destino );
                fprintf(patm_arq,"-------------------------------------------\n");

                patrimonios[i].status_transferencia = 1;
                strcpy(patrimonios[i].status,"Transferido Provisoriamente");
                printf("\nTransferencia efetuada com sucesso!\n\n");
                fclose(patm_arq);      //Fecha o arquivo
}}}
               if (opc ==3){
                for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
                if(patrimonios[i].id==id){
                strcpy(patrimonios[i].status,"OK!");
                patrimonios[i].status_transferencia = 0;}}
                printf("\nRetorno efetuado com sucesso!\n\n");
                fclose(patm_arq);}
}}      printf("\n1 - Continuar\n0 - Sair\n");
        scanf("%d",&op);}}

void reg_movimentacao(){
    system("cls");
    printf("*-------------------------*\n");
    printf("| Registro de Moviemtacao |\n");
    printf("*-------------------------*\n");
    for (int i = 0; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].status_transferencia==1){
        printf("\n--------------------------------------------------");
        printf("\nID:   #%d\n",patrimonios[i].id);
        if(strcmp(patrimonios[i].status,"Transferido Provisoriamente")==0){
                printf("Transferencia Provisoria\n");
                printf("\nSetor de Origem: %s\n",patrimonios[i].setor_origem);
                printf("\nSetor Atual: %s\n",patrimonios[i].setor_destino);
                printf("\nData de Transferencia: %s\n",patrimonios[i].data_transferencia);
                printf("\nRetorno: %s\n\n",patrimonios[i].data_retorno);}
            else{
                printf("Transferencia Definitiva\n");
                printf("\nSetor de Origem: %s\n",patrimonios[i].setor_origem);
                printf("\nSetor Atual: %s\n",patrimonios[i].setor);
                printf("\nData de Transferencia: %s\n\n",patrimonios[i].data_transferencia);}
}}        printf("Digite qualquer tecla para continuar\n\n");
          getch();}

void manutencao(){ //cadastra manutencoes para um patrimonio
    int id;
    int op = 1;
    int opcao;
    char datamanutencao[12];
    char descricao_status[100];
    char tecnico[50];

    system("cls");

    FILE *patma_arq;

    while(op!=0){
        printf("*-------------------------------------*\n");
        printf("| Manutencao do Patrimonio |\n");
        printf("*-------------------------------------*\n");
        printf("\nDigite o id do patrimonio: #\n");
        scanf("%d",&id);
        for(int i = 0 ; i < MAX_PATRIMONIOS; i++){
        if (patrimonios[i].id == id){
            printf("\nEscolha uma opcao:\n");
            printf("\n1-Efetuar Manutencao");
            printf("\n2-Concluir Manutencao\n");
            scanf("%d",&opcao);
            if(opcao==1){
                printf("\n-----------------------------------\n");
                printf("| Informacoes do Patrimonio |\n"); //mostra as informacoes do patrimonio para checar se é o correto
                printf("\nID:     #%d",patrimonios[i].id);
                printf("\nNome:   %s",patrimonios[i].nome);
                printf("\nSetor:  %s",patrimonios[i].setor);
                printf("\nMarca:  %s",patrimonios[i].marca);
                printf("\nStatus: %s\n",patrimonios[i].status);
                printf("\n-----------------------------------");
                patma_arq = fopen("arquivo_manutencao.txt","a"); //Abre o arquivo
                printf("\n| Digite a Data, a Descricao e o Tecnico Responsavel |\n"); //Avisa ao usuario o que deve ser informado para cadastrar a manutencao
                printf("\nData: ");
                scanf("%s",&datamanutencao);
                fflush(stdin);
                printf("\nDescricao: ");
                fgets(descricao_status, 50, stdin);
                printf("\nTecnico: ");
                scanf("%s",&tecnico);
                strcpy(patrimonios[i].status,"Em Manutencao");
                strcpy(patrimonios[i].datamanutencao, datamanutencao);
                strcpy(patrimonios[i].descricao_status, descricao_status);
                strcpy(patrimonios[i].tecnico, tecnico);
                fprintf(patma_arq, "\n-------------------------------------------------\n");
                fprintf(patma_arq, "ID: #%d\n",patrimonios[i].id);
                fprintf(patma_arq, "Data da Manutencao: %s\n",patrimonios[i].datamanutencao);
                fprintf(patma_arq, "Tecnico Responsavel: %s\n",patrimonios[i].tecnico);
                fprintf(patma_arq, "Descricao: #%d\n",patrimonios[i].descricao_status);
                fprintf(patma_arq, "\n-------------------------------------------------\n");

                fclose(patma_arq);      //Fecha o arquivo

                printf("\n*-------------------------------------*\n"); //Mostra o que foi cadastrado para o Cliente verificar
                printf("\nManuencao cadastrada com sucesso!\n");
                printf("\nData da Manutencao:  %s",patrimonios[i].datamanutencao);
                printf("\nDescricao:  %s",patrimonios[i].descricao_status);
                printf("\nTecnico Responsavel: %s\n",patrimonios[i].tecnico);
                printf("*-------------------------------------*\n");
            }else if(opcao==2){
                printf("Manutencao Concluida com Sucesso!");
                strcpy(patrimonios[i].status,"OK!");
            }
            printf("\n\nDeseja cadastrar manutencao em outro patrimonio?\n0 - Nao\n1 - Sim\n");
            scanf("%d",&op);}}}}

void menu(){
	int opcao;
	while(1){
        system("cls");
        printf("\n*---------------------------------------------------------------------------*");
		printf("\n| Bem vindo ao Sistema de controle do patrimonios dos equipamentos da UFU! |");
        printf("\n*---------------------------------------------------------------------------*");
		printf("\n1- Cadastrar Patrimonio");
		printf("\n2- Inventario de patrimonios");
		printf("\n3- Mostrar um Patrimonio detalhadamente");
        printf("\n4- Efetuar Baixa de um Patrimonio");
        printf("\n5- Editar Informacoes de um Patrimonio");
        printf("\n6- Efetuar Transferencia");
        printf("\n7- Registro de Transferencia");
        printf("\n8- Manutencao");
		printf("\n0- Sair ");
		printf("\n\nDigite uma  opcao: ");
		scanf("%d", &opcao);
		if(opcao == 1) cadastrar();
		if(opcao == 2) inventario();
		if(opcao == 3) mostra1();
		if(opcao == 4) baixa();
		if(opcao == 5) edicao();
        if(opcao == 6) movimentacao();
	   	if(opcao == 7) reg_movimentacao();
		if(opcao == 8) manutencao();
		//if(opcao == 9) reg_recebimento();
		if(opcao == 0) return;}}

int main(){
	menu();
}
