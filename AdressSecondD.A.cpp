// AdressSecondD.A


#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>


using std::endl;
using std::string;


class Adress {
private:
    string city_name_;
    string street_name_;
    int num_house_;
    int num_flat_;
    //конструктор без параметров для массива
    Adress() :city_name_(), street_name_(), num_house_(), num_flat_() {}      
      
public:

    //конструктор с параметрами
    Adress(string city_name_, string street_name_, int num_house_, int num_flat_) :
        city_name_(city_name_), street_name_(street_name_), num_house_(num_house_), num_flat_(num_flat_)
    {}  

    //ввод из файла, сортировка и вывод в файл
    void Get_Output_Address() {
        
        std::ifstream in("in.txt");
        if (!in.is_open()) std::exit(0);
        int size; in >> size;

        //создаем массив
        Adress* adress_arr = new Adress[size];

        //читаем из файла в массив
        for (int i = 0; i < size; i++) {  
            in >> adress_arr[i].city_name_;
            in >> adress_arr[i].street_name_;
            in >> adress_arr[i].num_house_;
            in >> adress_arr[i].num_flat_;
        }

        //сортируем
        std::sort(adress_arr, adress_arr + size, [](const Adress& left, const Adress& right) {
            return left.city_name_ < right.city_name_;
            });    
         
        //вывод в файл     
        std::ofstream  out("out.txt");
        out << size << endl;
        for (int i = 0; i < size; i++) {

          out << adress_arr[i].city_name_ << ", " << adress_arr[i].street_name_ << ", " << adress_arr[i].num_house_ << ", "
              << adress_arr[i].num_flat_ << endl;
        }

        out.close();
            
        delete[] adress_arr;
        in.close();
    }

    
};
int main()
{
    //создаем объект класса из данных файла для обращения к методу
    std::ifstream in("in.txt");
    if (!in.is_open()) std::exit(0); 
    int f; in >> f;

    string nc, ns; int nh, nf; 
    in >> nc >> ns >> nh >> nf; 
    Adress adress(nc, ns, nh, nf);    
    in.close();
    
    adress.Get_Output_Address();

    return 0;
}

