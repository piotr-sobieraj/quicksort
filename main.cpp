#include <iostream>
#include <vector>
#include <string>

bool less(char a, char b){
    return a < b;
}

bool less(std::string a, std::string b){
    return a.length() < b.length();
}



template <typename T>
int partition(std::vector<T>& v, int lo, int hi) {
    // Podział na a[lo..i-1], a[i], a[i+1..hi]
    int i = lo, j = hi + 1;  // Lewy i prawy wskaźnik
    T pivot = v[lo];  // Wybieramy element osiowy (pierwszy element)

    while (true) {
        // Znajdź element większy od pivota z lewej strony
        while (less(v[++i], pivot)) if (i == hi) break;
        
        // Znajdź element mniejszy od pivota z prawej strony
        while (less(pivot, v[--j])) if (j == lo) break;
        
        // Jeśli wskaźniki się spotkają, przerwij
        if (i >= j) break;
        
        // Zamień elementy, które są nie na swoim miejscu
        std::swap(v[i], v[j]);
    }
    // Wstaw element osiowy na właściwe miejsce
    std::swap(v[lo], v[j]);

    return j;  // Zwróć indeks pivota
}

template <typename T>
void sort(std::vector<T>& v, int lo, int hi)
{
    if (hi <= lo) return;
    int j = partition(v, lo, hi); // Podział 
    sort(v, lo, j - 1); // Sortowanie lewej strony a[lo .. j-1].
    sort(v, j + 1, hi); // Sortowanie prawej strony a[j+1 .. hi].
}

template <typename T>
void sort(std::vector<T>& v)
{
    sort(v, 0, v.size() - 1);
}

template <typename T>
void print(const std::vector<T>& v) {    
    for (int i = 0; i < v.size(); i ++)
        std::cout << v[i] << "    ";

    std::cout<<std::endl;
}



int main() 
{
    std::vector<char> v_char = {'G', 'B', 'D', 'L', 'W', 'I', 'G', 'S', 'Q', 'L', 'X', 'C'};
    print(v_char);
    sort(v_char);
    print(v_char);

    std::cout<<std::endl;

    std::vector<std::string> v_str = {"SEMINARIUM", "JEDEN", "GRUSZKA", "POLSKA", "INFORMATYKA", "UL", "C++"};
    print(v_str);
    sort(v_str);
    print(v_str);
    std::cout<<std::endl;

    return 0;
}