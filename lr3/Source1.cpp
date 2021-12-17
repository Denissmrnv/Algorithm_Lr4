#include <iostream>
#include <sstream>
#include <stack>
#include <cmath>
#include <stdio.h>

using namespace std;

string readStr() {
    string val;

    getline(cin, val);
    return val;
}

int main() {

    setlocale(LC_ALL, "Russian");
    cout << "¬ведите выражение в обратной польской записи" << endl;
    stack <double> stackNum;
    auto v = readStr();
    auto s = istringstream(v);
    int count = 0;
    string exp;

    
    while (getline(s, exp, ' ')) {
        float num = 0;
        if (sscanf_s(exp.data(), "%f", &num) >= 1) {
            stackNum.push(num);
            count++;
            continue;
        }
        if (stackNum.size() > 1) {
            auto y = stackNum.top();
            stackNum.pop();

            auto x = stackNum.top();
            stackNum.pop();

            switch (exp[0]) {
            case '+':
                stackNum.push(x + y);
                count--;
                break;
            case '-':
                stackNum.push(x - y);
                count--;
                break;
            case '*':
                stackNum.push(x * y);
                count--;
                break;
            case '/':
                stackNum.push(x / y);
                count--;
                break;
            }
        }
        else {
            cout << " Error";
            return 0;
        }
    }

    if (count == 1)
        cout << " Result = " << stackNum.top();
    else 
        cout << " Error " << endl;
    return 0;
}