#include <iostream>
#include <vector>
#include <string>


bool less(float a, float b){
    return a < b;
}

bool less(char a, char b){
    return a < b;
}

bool less(std::string a, std::string b){
    return a.length() < b.length();
}

bool less(int a, int b){
    return a * a < b * b;
}


template <typename T>
int partition(std::vector<T>& tab, int lo) {
    int hi = tab.size() - 1;
    T pivot = tab[lo];  // Wybieramy element osiowy (pierwszy element)
    int i = lo, j = hi + 1;  // Lewy i prawy wskaźnik

    while (true) {
        // Znajdź element większy od pivota z lewej strony
        while (less(tab[++i], pivot)) {
            if (i == hi) break;
        }
        // Znajdź element mniejszy od pivota z prawej strony
        while (less(pivot, tab[--j])) {
            if (j == lo) break;
        }
        // Jeśli wskaźniki się spotkają, przerwij
        if (i >= j) break;
        // Zamień elementy, które są nie na swoim miejscu
        std::swap(tab[i], tab[j]);
    }
    // Zamień element osiowy na właściwe miejsce
    std::swap(tab[lo], tab[j]);

    return j;  // Zwróć indeks pivota
}

template <typename T>
void sort(std::vector<T>& v, int lo, int hi)
{
    if (hi <= lo) return;
    int j = partition(v, lo); // Podział (zobacz stronę 303).
    sort(v, lo, j - 1); // Sortowanie lewej strony a[lo .. j-1].
    sort(v, j + 1, hi); // Sortowanie prawej strony a[j+1 .. hi].
}



template <typename T>
void print(const std::vector<T>& v) {    
    for (int i = 0; i < v.size(); i ++)
        std::cout << v[i] << "\t";
}



int main() 
{
    std::vector<char> v_char = {'K', 'B', 'D', 'L', 'W', 'I', 'G', 'S', 'Q', 'L', 'X', 'C'};
    print(v_char);

    std::cout<<std::endl;
    
    partition(v_char, 0);
    print(v_char);
    sort(v_char, 0, v_char.size() - 1);


    // std::vector<std::string> v_str = {"POLSKA", "HOLANDIA", "JEMEN", "UL", "USA", "SEMINARIUM", "JABŁKO"};
    // print(v_str);
    // std::cout<<std::endl;

    // partition(v_str, 0);
    // print(v_str);

    // sort(v_str, 0, v_str.size() - 1);
    // std::cout<<std::endl;
    // print(v_str);
}