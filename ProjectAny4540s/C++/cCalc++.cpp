/*        СЧЕТЧИК ПРОГРЕССИИ
настраиваемая прогрессия с плавающей запятой, выводит на экран в столбец значения прогрессии и счетчик по порядку
для использования функции введите значения в

формате:  x^y ;  пример: 8^2,  4.5^7.14

и нажмите "submit"

по умолчанию если не вводить никаких символов программа выведет  на экран
геометрическую прогрессию 2 (2^2)
*/

/*      КАЛЬКУЛЯТОР 4 операции "+*-/"
для использования калькулятора
введите значение

в формате: 5+3, 5.5/3, 4*1.7, 2.2-1.72

и нажмите "submit"

после вычислений программа 
выведет результат на экран

поддерживаемые символы"+×*÷/-^" 
*/

/* -- design by ss2s -- */

#include <iostream>
using namespace std;

int main()
{
int z;
char znak = '^';
unsigned long int counter = 1;
double a=2,b=2,c=0, maxnum=562949953421312;

restart:

    cin >> a >> znak >>b;
	
    z=znak;
  //  cout << "cCalc ++ \n";
    if(znak == '^') {
cout <<"prog. table "<<a<<"^"<<b<<endl;
    if(a <= maxnum) {
    while (a <= maxnum) {
cout << "N "<<counter<<".     "<<a<<endl;
        a = a * b;
        counter ++;
     }
   }
 }
 else if (znak == '+') {
    c = a + b;
    cout << a <<'+'<< b <<'='<< c << endl;
    }
    else if (znak == '-') {
    c = a - b;
    cout << a <<'-'<< b <<'='<< c << endl;
    }
    else if (znak=='*'||z == 120) {
    c = a * b;
    cout << a <<'*'<< b <<'='<< c << endl;
    }
    else if (znak=='/'||z == -10) {
    if (b == 0) {
       cout << "na 0 delit nelza \n";
    } else {
    c = a / b;
    cout << a <<'/'<< b <<'='<< c << endl;}
    }
    else {
       cout << "err cCalc \n";
    }
 goto restart ;
 return 0;
}
