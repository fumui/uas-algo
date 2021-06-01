#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
vector<int> searchString(const string& data, const char search){
    vector<int> indexes;
    for(int i = 0; i < data.length(); i++){
        if (data[i] == search){ indexes.push_back(i); }
    }
    return indexes;
}
int main(){
    string data;
    char search;
    cout << "Masukkan kalimat: " << endl;
    getline(cin, data);
    cout << "Huruf yang dicari: " << endl;
    cin >> search;

    vector<int> found = searchString(data,search);
    if (found.size() > 1){
        cout << "Ditemukan " << found.size() << " huruf pada index ke:" << endl;
        for (auto &&i : found){
            cout << i << endl;
        }
        int prev = 0;
        cout << data << endl;
        for (auto &&i : found){
            cout << setw(i+1-prev);
            cout << "^";
            prev = i+1;
        }
        cout << endl;
    } else {
        cout << "Huruf tidak ditemukan." << endl;
    }
}