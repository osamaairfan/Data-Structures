#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <fstream>
#define MAX_LEN 128

using namespace std;

void AsciiBanner(FILE* fptr) {
    char read_string[MAX_LEN];
    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        cout << read_string;
}

class Parser {
public:

    char stack1[100];
    int top = -1;

    void push(char item) {
        stack1[++top] = item;
    }

    char pop() {
        return stack1[top--];
    }


    int precedence(char token) {        //For returning the precedence or priority of operators

        switch (token) {

        case '+':

        case '-':
            return 2;
            break;

        case '*':

        case '/':
            return 3;
            break;

        case '^':
            return 4;
            break;

        case '(':

        case ')':

        case '#':
            return 1;
            break;
        }
    }


    int isOperator(char token) {           //To check if the token is operator or not

        switch (token) {

        case '+':

        case '-':

        case '*':

        case '/':

        case '^':

        case '(':

        case ')':
            return 1;
            break;

        default:
            return 0;
        }
    }


    void convert(char infix[], char postfix[]) {       // For converting the infix expression to postfix

        int i, token, j = 0;
        stack1[++top] = '#';

        for (i = 0; i < strlen(infix); i++) {
            token = infix[i];

            if (isOperator(token) == 0) {
                postfix[j] = token;
                j++;
            }

            else {

                if (token == '(') {
                    push(token);
                }

                else {

                    if (token == ')') {

                        while (stack1[top] != '(') {
                            postfix[j] = pop();
                            j++;
                        }

                        pop();              //pop ( 
                    }

                    else {

                        if (precedence(token) > precedence(stack1[top])) {
                            push(token);
                        }

                        else {

                            while (precedence(token) <= precedence(stack1[top])) {
                                postfix[j] = pop();
                                j++;
                            }

                            push(token);
                        }
                    }
                }
            }
        }

        while (stack1[top] != '#') {
            postfix[j] = pop();
            j++;
        }

        postfix[j] = '\0';   //string terminated. 
    }

};

class Evaluate {
public:

    int stack2[100];             //stack1 for evaluating expression
    int top_int = -1;

    void push_int(int item) {
        stack2[++top_int] = item;
    }

    char pop_int() {
        return stack2[top_int--];
    }


    int evaluate(char* postfix) {               //For evaluating the postfix expression

        char ch;
        int i = 0, operand1, operand2;

        while ((ch = postfix[i++]) != '\0') {

            if (isdigit(ch)) {
                push_int(ch - '0'); // Push the operand 
            }

            else {
                operand2 = pop_int();     //Operator pop 2 operands
                operand1 = pop_int();

                switch (ch) {

                case '+':
                    push_int(operand1 + operand2);
                    break;

                case '-':
                    push_int(operand1 - operand2);
                    break;

                case '*':
                    push_int(operand1 * operand2);
                    break;

                case '/':
                    push_int(operand1 / operand2);
                    break;

                case '^':
                    push_int(pow(operand1, operand2));
                    break;
                }
            }
        }

        return stack2[top_int];
    }
};

int main() {


    char* filename = "image.txt";
    FILE* fptr = NULL;
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        return 1;
    }

    AsciiBanner(fptr);
    fclose(fptr);
  	
  	int choice;
	system("Color 0A");
    Parser s1;
    Evaluate e1;
    char infix[100];
    char postfix[100];

	up:	
    cout << endl << endl;
    cout << "Enter Your Choice: " << endl;
    cout << "1) Convert Infix Expression to Postfix Expression" << endl;
    cout << "2) Evaluate the Postfix Expression" << endl;
    cout << "3) Show Results" << endl;
	cout << "4) Clear Screen" << endl;
    cout << "5) Exit Program" << endl;

    cin >> choice;
    
  	switch(choice) {
  		
		case 1:
		  	cout << "Enter an Expression: ";
    		cin >> infix;
    		s1.convert(infix, postfix);
    		cout << "Expression saved Successfully!";
	  		break;
			
		case 2:
			
			e1.evaluate(postfix);
			cout << "Evaluated Successfully!" << endl;
			break;
			
		case 3:
			
			cout << endl << "---------------RESULT--------------" << endl;
	    	cout << "Infix Expression is: " << infix << endl;
	    	cout << "Postfix Expression is: " << postfix << endl;
	
	    	cout << "-----------------------------------" << endl;
	    	cout << "Evaluated Postfix Expression is: " << e1.evaluate(postfix);
	    	cout << endl << "-----------------------------------" << endl;
    		break;
    	
    	case 4:
    		system("CLS");
    		break;
    		
    	case 5:
    		exit(0);
    		break;
    	
		default:
    		cout << "Wrong input";
    		
	}	
    
    ofstream myfile("Data.txt");                             //Filling
	myfile << "Infix Expression is: " << infix << endl;
	myfile << "Postfix Expression is: " << postfix << endl;
	myfile << "Evaluated Postfix Expression is: " << e1.evaluate(postfix);
	myfile.close();
	
	goto up;
    return 0;
}
