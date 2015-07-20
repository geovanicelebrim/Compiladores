#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char temp_char_EXP_12;
char temp_char_EXP_3;
char temp_string_EXP_15[1024];
char temp_string_EXP_16[1024];
char temp_string_EXP_8[1024];
char temp_string_EXP_9[1024];
char temp_string_a_13[1024];
char temp_string_b_14[1024];
int temp_boolean_EXP_10;
int temp_boolean_EXP_4;
int temp_int_EXP_11;
int temp_int_EXP_7;

char *temp_string_foo1_0(int temp_boolean_val_1, char temp_char_tam_2)
{
	temp_char_EXP_3 = 'e';
	temp_boolean_EXP_4 = temp_char_tam_2 == temp_char_EXP_3;
	temp_int_EXP_7 = !temp_boolean_EXP_4;
	if(temp_int_EXP_7) goto temp_Label_6;
	strcpy(temp_string_EXP_8, " -> str()");
	return temp_string_EXP_8;
	
goto temp_Label_5;
temp_Label_6:
temp_Label_5:

	if(temp_boolean_val_1) cout << "true";
	if(!temp_boolean_val_1) cout << "false";

	strcpy(temp_string_EXP_9, " ");
	cout << temp_string_EXP_9;

	cout << temp_char_tam_2;

	cout << endl;

	
	temp_boolean_EXP_10 = !temp_boolean_val_1;

	temp_int_EXP_11 = 1;	
	temp_char_EXP_12 = temp_char_tam_2 + temp_int_EXP_11;
	return temp_string_foo1_0(temp_boolean_EXP_10, temp_char_EXP_12);
	
	return NULL;
}


int main(void)
{
	strcpy(temp_string_a_13, "");

	strcpy(temp_string_b_14, "");

	strcpy(temp_string_EXP_15, "Entre com um texto: ");
	cout << temp_string_EXP_15;

	cout << endl;

	cin.getline(temp_string_a_13, 1024);
	
	strcpy(temp_string_EXP_16, "Entre com outro texto: ");
	cout << temp_string_EXP_16;

	cout << endl;

	cin.getline(temp_string_b_14, 1024);
	
	cout << temp_string_a_13;

	cout << endl;

	return 0;
}

