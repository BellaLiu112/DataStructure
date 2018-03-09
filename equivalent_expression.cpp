#include <stack>
#include <iostream>

using namespace std;

void reverse_poland(string& input, string& reverse_p)
{
    stack<char> stk;
    int l = (int)input.size();
    for (int i = 0; i < l; ++i){
        if (input[i] == '(') {
            stk.push(input[i]);
        } else if (input[i] == ')'){
            char tmp = stk.top();
            if (tmp == '(') {
                stk.pop();
            } else {
                while (stk.top() != '(') {
                    reverse_p.push_back(tmp);
                    stk.pop();
                }
                stk.pop();
            }
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            if (!stk.empty()) {
                char tmp = stk.top();
                if (tmp == '+' || tmp == '-' || tmp == '*') {
                    reverse_p.push_back(tmp);
                    stk.pop();
                    stk.push(input[i]);
                } else
                    stk.push(input[i]);
            } else
                stk.push(input[i]);
        } else if (input[i] == ' ' || input[i] == '\t')
            continue;
        else
            reverse_p.push_back(input[i]);
    }
    while (!stk.empty()) {
        char tmp = stk.top();
        reverse_p.push_back(tmp);
        stk.pop();
    }
}

int expression_to_value(string& poland)
{
    int result;
    int l = (int)poland.size();
    stack<int> stk;
    for (int i = 0; i < l; ++i) {
        if (poland[i] == '+' || poland[i] == '-' || poland[i] == '*') {
            int op1, op2;
            op2 = stk.top();
            stk.pop();
            op1 = stk.top();
            stk.pop();
            switch (poland[i]) {
                case '+':
                    stk.push(op1 + op2);
                    break;
                case '-':
                    stk.push(op1 - op2);
                    break;
                case '*':
                    stk.push(op1 * op2);
            }
        } else {
            int tmp = poland[i] - 48;
            stk.push(tmp);
        }
    }
    result = stk.top();
    return result;
}



int main()
{
    string in;
    string out;

    int n;
    cin >> n;

    int value1, value2;

    while (n--) {
        in.clear();
        out.clear();
        cin >> in;
        reverse_poland(in, out);
        value1 = expression_to_value(out);

        in.clear();
        out.clear();
        cin >> in;
        reverse_poland(in, out);
        value2 = expression_to_value(out);

        if (value1 == value2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
