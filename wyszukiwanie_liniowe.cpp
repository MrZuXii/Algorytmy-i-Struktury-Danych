#include <iostream>

using namespace std;

int linear_search(int arr[],int n,int x)
{
    for(int i=0;i<x;i++) {
        if(arr[i] == n)
            return i;
    }
    return 0;
}

int main() {
    cout << "==========================================" << endl;
    cout << "      Algorytm: Wyszukiwanie liniowe      " << endl;
    cout << "==========================================" << endl;

    int arr[] = {2,3,4,10,40};
    int szukana_liczba;
    int rozmiar_tablicy = sizeof(arr) / sizeof(arr[0]);
    cout << "Podaj szukana liczbe: ";
    cin >> szukana_liczba;
    int index = linear_search(arr, szukana_liczba, rozmiar_tablicy);
    if(index)
        cout << "Liczba: " << szukana_liczba << " znajduje sie na indexie: " << index;
    else 
        cout << "Liczba nie zostala znaleziona";

        cout <<endl<< "==========================================" << endl;

}