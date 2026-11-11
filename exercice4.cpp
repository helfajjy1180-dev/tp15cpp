
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

template <typename T>
class Pile {
private:
    vector<T> elements;

public:
    void empiler(T element) {
        elements.push_back(element);
    }

    T depiler() {
        if (estVide()) {
            throw runtime_error("La pile est vide !");
        }

        T element = elements.back();
        elements.pop_back();

        return element;
    }

    T sommet() const {
        if (estVide()) {
            throw runtime_error("La pile est vide !");
        }

        return elements.back();
    }

    bool estVide() const {
        return elements.empty();
    }

    void inverser() {
        reverse(elements.begin(), elements.end());
    }

    void afficher() const {
        for (const T& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {

    // Test avec int
    Pile<int> p1;

    p1.empiler(10);
    p1.empiler(20);
    p1.empiler(30);

    cout << "Pile int : ";
    p1.afficher();

    cout << "Sommet : " << p1.sommet() << endl;
    cout << "Depile : " << p1.depiler() << endl;

    p1.inverser();

    cout << "Apres inversion : ";
    p1.afficher();

    // Test avec string
    Pile<string> p2;

    p2.empiler("Bonjour");
    p2.empiler("C++");

    cout << "\nPile string : ";
    p2.afficher();

    // Test avec double
    Pile<double> p3;

    p3.empiler(3.14);
    p3.empiler(2.5);

    cout << "\nPile double : ";
    p3.afficher();

    // Gestion des exceptions
    Pile<int> p4;

    try {
        p4.depiler();
    }
    catch (exception& e) {
        cout << "\nErreur : " << e.what() << endl;
    }

    return 0;
}
