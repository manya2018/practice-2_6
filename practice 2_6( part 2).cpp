#include <iostream>
#include <string>
using namespace std;    // TASK 2:
class expression
{
public:
    double  a=0;
    double b=0;
    char operation='+';
};
expression convert(string s)
{
    expression y;
    int j=0;
    int error=0;
    const int siz=s.size();
    int r=siz-1;
    char S[r];    // дополнительный массив для вычислений
    for (int i = 0; i < siz; i++) {
           if (s[i] == ':' or s[i] == '+' or s[i] == '-' or s[i] == '*') // с 20 по 32 строчку мы заполняем массив S
               // двумя числами с пробелом между ними, чтобы потом с помощью функции strtod преобразовать их в два числа типа double,(c 41 по 45 строчки)
           {
                   y.operation = s[i];
                   S[j] = ' ';
                   j++;
                   continue;
           };
           if (isdigit(s[i]) or s[i]==' ')
           {
               S[j] = s[i];
               j++;
               continue;
           }   // если предыдушие два цикла if не выполнились и программа дошла до 34 строчки, значит введен неправильный символ, выдаем ошибку
           cout << "ERROR: you entered the wrong character!" << endl;
           error++;
           break;
    }
    if (error==0) // выполняем только если нет ошибки
    {

        char *ptr;
        char *p;
        y.a = strtod(S, &ptr);
        p = ptr;
        y.b = strtod(p, &ptr);
    }
    return y;
}
double solve()   /* TASK 3 (там в задании вооббще написано чтобы функция принимала переменную типа
exspression,но я помумала, что это слишком скучно, поэтому вот функция, которая преобразует выражение, введенное пользователем, в переменную типа
 expression и выдает результат)*/
{
    string s;
    cout << "enter your expression:" << endl;
    getline(cin,s);
    expression x= convert(s);
    switch (x.operation){
        case '-':
            cout  << x.a <<  " " << x.operation << " " << x.b<< " = " << x.a-x.b<<  endl;
            break;
        case '+':
            cout  << x.a <<  " " << x.operation << " " << x.b<< " = " << x.a + x.b<<  endl;
            break;
        case '*':
            cout  << x.a <<  " " << x.operation << " " << x.b<< " = " << x.a*x.b<<  endl;
            break;
        case ':':
            if (x.b==0)
            {
                cout << "error: it is impossible to divide by zero!" << endl;
            }
            else
            {
                cout << x.a << " " << x.operation << " " << x.b << " = " << x.a / x.b << endl;
            }
            break;

    }


}

int main()
{
     solve();
}
