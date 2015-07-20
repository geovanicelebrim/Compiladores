#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct N
{
	char c[1024];
}; 
typedef struct N str;
struct Node
{
	int num;
	struct Node *prox;
}; 
typedef struct Node node;

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
}

int vazia(node *LISTA)
{
	int temp;
	temp = LISTA->prox == NULL;
	if(!temp) goto l1v;
	return 1;
l1v:
	return 0;
}

void insereFim(node *LISTA, int num)
{
	node *novo;
	novo = (node *) malloc(sizeof(node));
	if(novo) goto l2i;
	printf("Sem memoria disponivel!\n");
	exit(1);
l2i:
	novo->num = num;
	novo->prox = NULL;
	if(!vazia(LISTA)) goto l3i;
	LISTA->prox=novo;
	return;
l3i:
	node *tmp;
	tmp = LISTA->prox;
l4i:
	if(tmp->prox == NULL) goto l5i;
	tmp = tmp->prox;
	goto l4i;
l5i:
	tmp->prox = novo;
}

void exibe(node *LISTA)
{
	if(!vazia(LISTA)) goto l1e;
	printf("Lista vazia!\n\n");
	return ;
l1e:
	node *tmp;
	tmp = LISTA->prox;
l2e:
	if( tmp == NULL) goto l3e;
	printf("%d\n", tmp->num);
	tmp = tmp->prox;
	goto l2e;
l3e:
	printf("\n");
}

int tamanho(node *LISTA)
{
	int tamanho;
	tamanho = 0;
	if(vazia(LISTA)) return tamanho;
	node *tmp;
	tmp = LISTA->prox;
l1t:
	if(tmp == NULL) goto l2t;
	tamanho++;
	tmp = tmp->prox;
	goto l1t;
l2t:
	return tamanho;
}

int mapper(node *indice, node *tam)
{
	int endereco = 0;
	int mult;
	node *tmp_indice;
	tmp_indice = indice->prox;
	node *tmp_tamanho;
	tmp_tamanho = tam->prox;
	int i;
	int teste;
	int t1;
	int t2;
	int t3;
	int t4;
	i = 0;
l2m:
	teste = i < tamanho(tam);
	if(!teste) goto l1m;
	t1 = tmp_indice->num >= tmp_tamanho->num;
	t2 = tmp_indice->num*(-1) > tmp_tamanho->num;
	t3 = tamanho(indice) != tamanho(tam);
	if(t1) goto l3m;
	if(t2) goto l3m;
	if(t3) goto l3m;
	goto l4m;
l3m:
	printf("\nAcesso a indice não permitido.\n");
	exit(1);
l4m:
	t4 = tmp_indice->num < 0;
	if(!t4) goto l5m;
	tmp_indice->num = tmp_tamanho->num + tmp_indice->num;
l5m:
	tmp_indice = tmp_indice->prox;
	tmp_tamanho = tmp_tamanho->prox;
	i = i + 1;
	goto l2m;
l1m:
	tmp_indice = indice->prox;
	tmp_tamanho = tam->prox;
	node *aux;
	aux = tam->prox;
	int i2;
	int i3;
	int teste2;
	int teste3;
	i2 = 0;
l6m:
	teste2 = i2 < tamanho(tam) - 1;
	if(!teste2) goto l7m;
	mult = tmp_indice->num;
	i3 = i2;
l8m:
	teste3 = i3 < tamanho(tam) - 1;
	if(!teste3) goto l9m;
	mult = mult*tmp_tamanho->num;
	tmp_tamanho = tmp_tamanho->prox;
	i3 = i3 + 1;
	goto l8m;
l9m:
	tmp_tamanho = aux;
	endereco += mult;
	tmp_indice = tmp_indice->prox;
	aux = aux->prox;
	i2 = i2 + 1;
	goto l6m;
l7m:
	int i4;
	int teste4;
	int val;
	i4 = 0;
	tmp_indice = indice->prox;
l10m:
	teste4 = i4 < tamanho(tam);
	if(!teste4) goto l11m;
	val = tmp_indice->num;
	tmp_indice = tmp_indice->prox;
	i4 = i4 + 1;
	goto l10m;
l11m:
	endereco = endereco + val;
	return endereco;
}
char temp_string_EXP_41[1024];
char temp_string_EXP_42[1024];
char temp_string_EXP_43[1024];
char temp_string_EXP_77[1024];
char temp_string_EXP_78[1024];
int temp_boolean_EXP_10;
int temp_boolean_EXP_17;
int temp_boolean_EXP_27;
int temp_boolean_EXP_34;
int temp_boolean_EXP_63;
int temp_boolean_EXP_70;
int temp_int_EXP_0;
int temp_int_EXP_13;
int temp_int_EXP_14;
int temp_int_EXP_16;
int temp_int_EXP_1;
int temp_int_EXP_20;
int temp_int_EXP_21;
int temp_int_EXP_22;
int temp_int_EXP_24;
int temp_int_EXP_26;
int temp_int_EXP_2;
int temp_int_EXP_30;
int temp_int_EXP_31;
int temp_int_EXP_33;
int temp_int_EXP_37;
int temp_int_EXP_38;
int temp_int_EXP_39;
int temp_int_EXP_47;
int temp_int_EXP_48;
int temp_int_EXP_49;
int temp_int_EXP_50;
int temp_int_EXP_53;
int temp_int_EXP_54;
int temp_int_EXP_57;
int temp_int_EXP_58;
int temp_int_EXP_59;
int temp_int_EXP_5;
int temp_int_EXP_60;
int temp_int_EXP_62;
int temp_int_EXP_66;
int temp_int_EXP_67;
int temp_int_EXP_69;
int temp_int_EXP_73;
int temp_int_EXP_74;
int temp_int_EXP_75;
int temp_int_EXP_7;
int temp_int_EXP_9;
int temp_int_cont_6;
int temp_int_i_25;
int temp_int_i_61;
int temp_int_i_8;
int temp_int_j_15;
int temp_int_j_32;
int temp_int_j_68;


int main(void)
{
	temp_int_EXP_0 = 5;
	temp_int_EXP_1 = 5;
	temp_int_EXP_2 = temp_int_EXP_0 * temp_int_EXP_1;

	
	node *temp_Label_4;
	temp_Label_4 = (node *) malloc(sizeof(node));
	inicia(temp_Label_4);
	if(!temp_Label_4) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_4, temp_int_EXP_0);
	insereFim(temp_Label_4, temp_int_EXP_1);

	int temp_int_a_3[temp_int_EXP_2];
	
	temp_int_EXP_5 = 1;
	temp_int_cont_6 = temp_int_EXP_5;

	
	temp_int_EXP_7 = 0;
	temp_int_i_8 = temp_int_EXP_7;
temp_Label_12:
	
	temp_int_EXP_9 = 5;
	temp_boolean_EXP_10 = temp_int_i_8 < temp_int_EXP_9;
	temp_int_EXP_13 = !temp_boolean_EXP_10;
	if(temp_int_EXP_13) goto temp_Label_11;
	
	temp_int_EXP_14 = 0;
	temp_int_j_15 = temp_int_EXP_14;
temp_Label_19:
	
	temp_int_EXP_16 = 5;
	temp_boolean_EXP_17 = temp_int_j_15 < temp_int_EXP_16;
	temp_int_EXP_20 = !temp_boolean_EXP_17;
	if(temp_int_EXP_20) goto temp_Label_18;
	
	node *temp_Label_23;
	temp_Label_23 = (node *) malloc(sizeof(node));
	inicia(temp_Label_23);
	if(!temp_Label_23) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_23, temp_int_i_8);
	insereFim(temp_Label_23, temp_int_j_15);
	temp_int_EXP_22 = mapper(temp_Label_23, temp_Label_4);
	temp_int_a_3[temp_int_EXP_22] = temp_int_cont_6;

	temp_int_cont_6 = temp_int_cont_6 + 1;

	temp_int_j_15 = temp_int_j_15 + 1;

	goto temp_Label_19;

temp_Label_18:

	temp_int_i_8 = temp_int_i_8 + 1;

	goto temp_Label_12;

temp_Label_11:


	
	temp_int_EXP_24 = 0;
	temp_int_i_25 = temp_int_EXP_24;
temp_Label_29:
	
	temp_int_EXP_26 = 5;
	temp_boolean_EXP_27 = temp_int_i_25 < temp_int_EXP_26;
	temp_int_EXP_30 = !temp_boolean_EXP_27;
	if(temp_int_EXP_30) goto temp_Label_28;
	
	temp_int_EXP_31 = 0;
	temp_int_j_32 = temp_int_EXP_31;
temp_Label_36:
	
	temp_int_EXP_33 = 5;
	temp_boolean_EXP_34 = temp_int_j_32 < temp_int_EXP_33;
	temp_int_EXP_37 = !temp_boolean_EXP_34;
	if(temp_int_EXP_37) goto temp_Label_35;
	
	node *temp_Label_40;
	temp_Label_40 = (node *) malloc(sizeof(node));
	inicia(temp_Label_40);
	if(!temp_Label_40) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_40, temp_int_i_25);
	insereFim(temp_Label_40, temp_int_j_32);
	temp_int_EXP_39 = mapper(temp_Label_40, temp_Label_4);
	
	cout << temp_int_a_3[temp_int_EXP_39];

	strcpy(temp_string_EXP_41, "\t");
	cout << temp_string_EXP_41;

	temp_int_j_32 = temp_int_j_32 + 1;

	goto temp_Label_36;

temp_Label_35:

	strcpy(temp_string_EXP_42, "");
	cout << temp_string_EXP_42;

	cout << endl;

	temp_int_i_25 = temp_int_i_25 + 1;

	goto temp_Label_29;

temp_Label_28:

	strcpy(temp_string_EXP_43, "-----------[2:4,2:4]---------------");
	cout << temp_string_EXP_43;

	cout << endl;

	node *temp_Label_45;
	temp_Label_45 = (node *) malloc(sizeof(node));
	inicia(temp_Label_45);
	if(!temp_Label_45) cout << "Sem memoria disponivel!\n";

	temp_int_EXP_48 = 4 - 2;
	if(temp_int_EXP_48 > 1)
	insereFim(temp_Label_45, temp_int_EXP_48);

	temp_int_EXP_49 = 4 - 2;
	if(temp_int_EXP_49 > 1)
	insereFim(temp_Label_45, temp_int_EXP_49);

	temp_int_EXP_47 = 1;
	temp_int_EXP_47 = temp_int_EXP_47 * temp_int_EXP_48;
	temp_int_EXP_47 = temp_int_EXP_47 * temp_int_EXP_49;
	int temp_int_b_44[temp_int_EXP_47];

	temp_int_EXP_50 = 0;
	
	temp_int_EXP_57 = 2;
temp_Label_56:
	temp_int_EXP_58 = temp_int_EXP_57 < 4;
	if(!temp_int_EXP_58)goto temp_Label_55;

	temp_int_EXP_53 = 2;
temp_Label_52:
	temp_int_EXP_54 = temp_int_EXP_53 < 4;
	if(!temp_int_EXP_54)goto temp_Label_51;



	node *temp_Label_46;
	temp_Label_46 = (node *) malloc(sizeof(node));
	inicia(temp_Label_46);
	if(!temp_Label_46) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_46, temp_int_EXP_57);
	insereFim(temp_Label_46, temp_int_EXP_53);

	temp_int_EXP_59 = mapper(temp_Label_46, temp_Label_4);
	temp_int_b_44[temp_int_EXP_50] = temp_int_a_3[temp_int_EXP_59];
	temp_int_EXP_50 = temp_int_EXP_50 + 1;

	temp_int_EXP_53 = temp_int_EXP_53 + 1;
goto temp_Label_52;
temp_Label_51:
	
	temp_int_EXP_57 = temp_int_EXP_57 + 1;
goto temp_Label_56;
temp_Label_55:
	

	
	temp_int_EXP_60 = 0;
	temp_int_i_61 = temp_int_EXP_60;
temp_Label_65:
	
	temp_int_EXP_62 = 2;
	temp_boolean_EXP_63 = temp_int_i_61 < temp_int_EXP_62;
	temp_int_EXP_66 = !temp_boolean_EXP_63;
	if(temp_int_EXP_66) goto temp_Label_64;
	
	temp_int_EXP_67 = 0;
	temp_int_j_68 = temp_int_EXP_67;
temp_Label_72:
	
	temp_int_EXP_69 = 2;
	temp_boolean_EXP_70 = temp_int_j_68 < temp_int_EXP_69;
	temp_int_EXP_73 = !temp_boolean_EXP_70;
	if(temp_int_EXP_73) goto temp_Label_71;
	
	node *temp_Label_76;
	temp_Label_76 = (node *) malloc(sizeof(node));
	inicia(temp_Label_76);
	if(!temp_Label_76) cout << "Sem memoria disponivel!\n";
	insereFim(temp_Label_76, temp_int_i_61);
	insereFim(temp_Label_76, temp_int_j_68);
	temp_int_EXP_75 = mapper(temp_Label_76, temp_Label_45);
	
	cout << temp_int_b_44[temp_int_EXP_75];

	strcpy(temp_string_EXP_77, "\t");
	cout << temp_string_EXP_77;

	temp_int_j_68 = temp_int_j_68 + 1;

	goto temp_Label_72;

temp_Label_71:

	strcpy(temp_string_EXP_78, "");
	cout << temp_string_EXP_78;

	cout << endl;

	temp_int_i_61 = temp_int_i_61 + 1;

	goto temp_Label_65;

temp_Label_64:

	return 0;
}

