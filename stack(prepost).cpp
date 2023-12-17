#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Stack{
    private:
        stack<int> data;
    public:
        void push(int value){
            data.push(value);
        }
        int pop(){
        if (isEmpty()){
            cerr << "stack is empty! " << endl;
            return -1;
            }
            int top = data.top();
            data.pop();
            return top;
        }

        int top(){
        if (isEmpty()){
            cerr << "stack is empty! " << endl;
            return -1;
            }
            return data.top();
        }
        bool isEmpty(){
            return data.empty();
        }
};

int evaluatePostfix(const string expression){
    Stack stack;
    for (char ch : expression){
        if (isdigit(ch)){
            stack.push(ch - '0');
        }
        else if (ch != ' '){
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            
            switch (ch){
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0) {
                    cerr << "Divide by zero!!" << endl;
                } else {
                    stack.push(operand1 / operand2);
                }
                break;
            default:
                cout<<"Invalid character in expression: "<<ch<<endl;
                break;
            }
        }
    }
    
    if (stack.isEmpty()){
        cerr<<"Invalid expression"<<endl;
        return -1;
    }
    return stack.pop();
}

int evaluatePrefix(const string expression){
    Stack stack;
    for (int i=expression.size() - 1; i>=0; i--){
        char ch = expression[i];
        if (isdigit(ch)){
            stack.push(ch - '0');
        }
        else if (ch != ' '){
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            
            switch (ch){
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0){
                    cerr << "Divide by zero!!" << endl;
                    } else {
                    stack.push(operand1 / operand2);
                    }
                    break;
                default:
                    cout<<"Invalid character in expression: "<<ch<<endl;
                    break;
            }
        }
    }
    if (stack.isEmpty()){
        cerr<<"Invalid expression"<<endl;
        return -1;
    }
    return stack.pop();
};

int main(){
    Stack st;
    st.push(12);
    st.push(23);
    st.push(34);
    st.push(45);
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    string postfixExpression = "3 4+2*7/";
    int resultPostfix = evaluatePostfix(postfixExpression);
    if (resultPostfix != -1){
        cout<<"Result of postfix expression: "<<resultPostfix<<endl;
    }

    string prefixExpression = "/ + 3* 4 2 7";
    int resultPrefix = evaluatePrefix(prefixExpression);
    
    if (resultPrefix != -1){
        cout<<"Result of prefix expression: "<<resultPrefix<<endl;
    }

return 0;
}