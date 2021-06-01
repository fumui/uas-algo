#include <iostream>
#include <stdio.h>
using namespace std;
FILE *file;
const char* FILEPATH = "/home/fumui/source/kuliah/algo2/uas/1.dat";
int fib(int n){
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
int main(){
    int i, j;
    //Menulis fibonachi ke arsip
    file = fopen(FILEPATH, "w");
    if (file == NULL) {
        cout << "Error membuka file" << endl;
        return 1;
    }
    cout << "Menulis ke arsip: " << endl;
    for (i = 0; i < 10; i++){
        int num = fib(i+1);
        cout << num << endl;
        fwrite(&num, sizeof(num), 1, file);
    }
    fclose(file);
    //Membaca arsip secara acak
    cout << "Membaca arsip: " << endl;
    file = fopen(FILEPATH, "r");
    if (file == NULL){
        cout << "Error membuka file" << endl;
        return 1;
    }
    //Baca Fibonachi ke-1
    fseek(file, sizeof(j), SEEK_SET);
    fread(&j, sizeof(j), 1, file);
    cout << "Fibonachi ke-1 = " << j << endl;
    //Baca Fibonachi ke-5
    fseek(file, 4 * sizeof(j), SEEK_SET);
    fread(&j, sizeof(j), 1, file);
    cout << "Fibonachi ke-5 = " << j << endl;
    //Baca Fibonachi ke-4
    fseek(file, 3 * sizeof(j), SEEK_SET);
    fread(&j, sizeof(j), 1, file);
    cout << "Fibonachi ke-4 = " << j << endl;
    fclose(file);
}