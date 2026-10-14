#include<iostream>
#include"st.h"
#include<stack>
using namespace std;

STACK<char> st;

class expression{

public:

bool isoperand(char n){
    if((n >= 'a' && n <= 'z') || (n >= '0' && n <= '9')){
        return true;
    }
    return false;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}


// INFIX TO POSTFIX

string intopost(string n){

    int l = n.length();
    string postexp = "";

    for(int i=0; i<l; i++){

        char ch = n[i];

        if(isoperand(ch)){
            postexp += ch;
        }

        else if(ch == '('){
            st.push(ch);
        }

        else if(ch == ')'){

            while(st.top() != '('){
                postexp += st.top();
                st.pop();
            }

            st.pop();
        }

        else{

            while(!st.empty() &&
                  precedence(st.top()) >= precedence(ch)){

                postexp += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while(!st.empty()){
        postexp += st.top();
        st.pop();
    }

    return postexp;
}


// INFIX TO PREFIX

string intopre(string n){

    string preexp = "";

    for(int i=n.length()-1; i>=0; i--){

        char ch = n[i];

        if(isoperand(ch)){
            preexp += ch;
        }

        else if(ch == ')'){
            st.push(ch);
        }

        else if(ch == '('){

            while(!st.empty() && st.top() != ')'){
                preexp += st.top();
                st.pop();
            }

            st.pop();
        }

        else{

            while(!st.empty() &&
                  st.top() != ')' &&
                  precedence(ch) < precedence(st.top())){

                preexp += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while(!st.empty()){
        preexp += st.top();
        st.pop();
    }

    string ans = "";

    for(int i=preexp.length()-1; i>=0; i--){
        ans += preexp[i];
    }

    return ans;
}


// POSTFIX EVALUATION

int evalpostfix(string exp){

    stack<int> s;

    for(int i=0; i<exp.length(); i++){

        char ch = exp[i];

        // Operand
        if(ch >= '0' && ch <= '9'){
            s.push(ch - '0');
        }

        // Operator
        else{

            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            if(ch == '+'){
                result = a + b;
            }

            else if(ch == '-'){
                result = a - b;
            }

            else if(ch == '*'){
                result = a * b;
            }

            else if(ch == '/'){
                result = a / b;
            }

            else if(ch == '^'){

                result = 1;

                for(int j=0; j<b; j++){
                    result = result * a;
                }
            }

            s.push(result);
        }
    }

    return s.top();
}


// PREFIX EVALUATION

int evalprefix(string exp){

    stack<int> s;

    // Scan from right to left
    for(int i=exp.length()-1; i>=0; i--){

        char ch = exp[i];

        // Operand
        if(ch >= '0' && ch <= '9'){
            s.push(ch - '0');
        }

        // Operator
        else{

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            int result;

            if(ch == '+'){
                result = a + b;
            }

            else if(ch == '-'){
                result = a - b;
            }

            else if(ch == '*'){
                result = a * b;
            }

            else if(ch == '/'){
                result = a / b;
            }

            else if(ch == '^'){

                result = 1;

                for(int j=0; j<b; j++){
                    result = result * a;
                }
            }

            s.push(result);
        }
    }

    return s.top();
}

};


// MAIN FUNCTION

int main(){

    expression a;

    int choice;
    string exp;

    do{

        cout << "\n===== EXPRESSION MENU =====" << endl;
        cout << "1. Infix to Postfix" << endl;
        cout << "2. Infix to Prefix" << endl;
        cout << "3. Evaluate Postfix" << endl;
        cout << "4. Evaluate Prefix" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;


        switch(choice){

            case 1:

                cout << "Enter infix expression: ";
                cin >> exp;

                cout << "Postfix: "
                     << a.intopost(exp) << endl;

                break;


            case 2:

                cout << "Enter infix expression: ";
                cin >> exp;

                cout << "Prefix: "
                     << a.intopre(exp) << endl;

                break;


            case 3:

                cout << "Enter postfix expression: ";
                cin >> exp;

                cout << "Result: "
                     << a.evalpostfix(exp) << endl;

                break;


            case 4:

                cout << "Enter prefix expression: ";
                cin >> exp;

                cout << "Result: "
                     << a.evalprefix(exp) << endl;

                break;


            case 5:

                cout << "Exiting..." << endl;

                break;


            default:

                cout << "Invalid choice!" << endl;
        }

    }while(choice != 5);


    return 0;
}