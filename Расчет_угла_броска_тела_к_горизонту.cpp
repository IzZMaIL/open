#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void visual(int& counter, bool& status, double* chislo) {
    string* sentence = new string[6]{
     "H(м) = ",
     "V(м/с) = ",
     "T(с) = ",
     "Угол(град) = ",
     "Ошибка. Невозможные условия задачи.",
     "Ошибка. Слишком большое число или нечисленный показатель. Попробуйте еще раз: "
    };
    if (status) {
        cout << sentence[counter];
        if (counter > 2 && counter < 4 ) cout << chislo[counter] << endl;
        delete[] sentence;
        return;
    }
    cout << sentence[5];
    delete[] sentence;
}

void enter(double* chislo, int& counter, bool& status) {
    cin >> chislo[counter];
    cin.ignore(2147483647, '\n');
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(2147483647, '\n');
        status = false;
        return;
    }
    status = true;
    counter++;
}

void podschet(double* chislo, int& counter) {
    const double Pi = 3.14159265358979323846, g = 9.8;
    double H = abs(chislo[0]);
    double V = abs(chislo[1]);
    double T = abs(chislo[2]);
    if (1 < abs(((g * T) / (2 * V)) - (H / (V * T))))
    {
        counter = 4;
        return;
    }
    chislo[3] = asin(((g * T) / (2 * V))-(H / (V * T)))*(180/Pi);
}

int main() {
    setlocale(LC_ALL, "rus");
    double chislo[4]{ 0 };
    int counter = 0;
    bool status = true;
    while (counter < 3) {
        visual(counter, status, chislo);
        enter(chislo, counter, status);
    }
    podschet(chislo, counter);
    visual(counter, status, chislo);
}
