#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void printVector(vector<int>& data) {
    for (int i = 0; i < data.size(); i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
void InsertionSort(vector<int>& data){
    for (int i = 1; i < data.size(); i += 1) {
        int temp = data[i], j;
        for (j = i; data[j] < temp; j -= 1) {
            data[j] = data[j - 1];
        }
        data[j] = temp;
        printVector(data);
    }
}
int main(){
    vector<int> data;
    int n;
    cout << "Masukkan jumlah data" << endl;
    cin >> n;
    for (int i = 0, x; i < n; i++){
        cout << "Data ke-"<< i+1 <<": ";
        cin >> x;
        data.push_back(x);
    }
    cout << "Data awal: "<< endl;
    printVector(data);
    InsertionSort(data);
    cout << "Data setelah diurutkan: "<< endl;
    printVector(data);
}