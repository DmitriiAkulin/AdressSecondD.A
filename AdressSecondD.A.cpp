﻿// AdressSecondD.A


#include <iostream>
#include <fstream>
#include <algorithm>



using std::endl;
using std::string;

class Adress {
private:
    string city_name_;
    string street_name_;
    int num_house_;
    int num_flat_;

public:

    //конструктор без параметров
    Adress() :city_name_("unknown"), street_name_("unknown"), num_house_(0), num_flat_(0) {}

    //конструктор с параметрами
    Adress(string city_name_, string street_name_, int num_house_, int num_flat_) :
        city_name_(city_name_), street_name_(street_name_), num_house_(num_house_), num_flat_(num_flat_)
    {}

    //вывод в файл  
    void Get_Output_Address(Adress *arr, int first) {
        std::ofstream  out("out.txt");
        out << first << endl;
        for (int i = 0; i < first; i++) {

            out << arr[i].city_name_ << ", " << arr[i].street_name_ << ", " << arr[i].num_house_ << ", "
                << arr[i].num_flat_ << endl;
        }

        out.close();
    }

    //сортируем

     void CitySort(Adress *arr, int size) {

  //в закоментированном ниже пришлось бы добавить кучу кода чтобы все поля передвинуть,поэтому использовал лямбды 
         /*  string keeper;
          for(int i = 1; i < size; i++)
              for (int j = size - 1; j >= i; j--) {
                  if (arr[j - 1].city_name_ > arr[j].city_name_) {
                      keeper = arr[j-1].city_name_;
                      arr[j - 1].city_name_ = arr[j].city_name_;
                      arr[j].city_name_ = keeper;
                  }

              }*/   

         std::sort(arr,arr + size, [](const Adress& left, const Adress& right) {
             return left.city_name_ < right.city_name_;
             });

            
    }
    //доступ и запись в массив.
    void AcsessSetData() {

        std::ifstream in("in.txt");
        if (!in.is_open()) std::exit(0);
        int first; in >> first;

        Adress* adress_arr = new Adress[first];//создаем массив

        for (int i = 0; i < first; i++) {  //читаем из файла в массив
            in >> adress_arr[i].city_name_;
            in >> adress_arr[i].street_name_;
            in >> adress_arr[i].num_house_;
            in >> adress_arr[i].num_flat_;
        }

        CitySort(adress_arr, first);//сортируем по неубыванию
        
        Get_Output_Address(adress_arr, first);//пишем в файл

        delete[] adress_arr;
        in.close();



    }
};
int main()
{

    Adress adress("unknown", "unknown", 0, 0);
    adress.AcsessSetData();

    return 0;
}
