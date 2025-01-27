#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;


int main(){

    int enk,temp,n;
    cout <<"kac random sayi dondurulsun? ";  // dizi boyutu sorgu
    cin >> n;

    ofstream oinput("input.txt");        
    ifstream input("input.txt");
    ofstream output("output.txt");

    int* array = new int[n];                // dinamik dizi açma işlemi.

    srand(time(0)); // program her calistirildiginda üretilen random sayilarin farklı olmasını sağlayan fonksiyonlar

    for(int k = 0; k < n; k++){  
        int number = rand() % 10000000000;   // random sayı üretici
        oinput << number<<endl;
    }
    oinput.close();

    for (int i = 0; i < n; i++) {     // random sayiları girdi dosyasında diziye aktarım.
        input >> array[i];
    }
    input.close();

    for(int j = 0; j<n; j++){
        enk = array[j];
        for(int i = j+1; i<n; i++){
            if(enk > array[i]){
                enk = array[i];
                temp = array[j];
               array[j] = array[i];
               array[i] = temp;
            }

        }

    }

    for(int i = 0; i<n; i++){
        output <<array[i] <<endl;
    }
    output.close();

	free(array); // dinamik dizi kapatma işlemi.

}




















































