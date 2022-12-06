
#include <iostream>
#include<Windows.h>
#include<fstream>
#include <string>
class Adress {
private:
    std::string city = "";
    std::string street = "";
    int num1 = 0;
    int num2 = 0;
    std::string print = "";

public:
    void add_adress(std::fstream& fin) {
        fin >> city;
        fin >> street;
        fin >> num1;
        fin >> num2;
    }
    std::string  get_print() {
        print = city + ", " + street + ", " + std::to_string(num1) + ", " + std::to_string(num2) + "\n";
        return print;
    }
};
    


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N = 0;
    std::fstream fin;
    std::fstream fout;
    fin.open("in.txt");
    fout.open("out.txt");
    fin >> N;
    Adress adress;
    Adress* arr = new Adress[N];
    for (int i = 0; i < N; ++i) {
        arr[i].add_adress(fin);

}
    fout << N << "\n";
    
    for (int i = N - 1; i >= 0; --i) {
        fout << arr[i].get_print();
    }
    fin.close();
    fout.close();
    delete[] arr;
}


