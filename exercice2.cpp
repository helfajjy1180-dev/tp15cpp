
#include <iostream>
#include <stdexcept>
using namespace std;

class File {
private:
    struct Noeud {
        int valeur;
        Noeud* suivant;

        Noeud(int v) {
            valeur = v;
            suivant = nullptr;
        }
    };

    Noeud* debut;
    Noeud* fin;

public:
    File() {
        debut = nullptr;
        fin = nullptr;
    }

    bool estVide() {
        return debut == nullptr;
    }

    bool estPleine() {
        return false;
    }

    void enfiler(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        if (estVide()) {
            debut = nouveau;
            fin = nouveau;
        } else {
            fin->suivant = nouveau;
            fin = nouveau;
        }
    }

    int defiler() {
        if (estVide()) {
            throw runtime_error("La file est vide !");
        }

        Noeud* temp = debut;
        int valeur = temp->valeur;

        debut = debut->suivant;

        if (debut == nullptr) {
            fin = nullptr;
        }

        delete temp;
        return valeur;
    }

    void afficher() {
        Noeud* courant = debut;

        while (courant != nullptr) {
            cout << courant->valeur << " ";
            courant = courant->suivant;
        }

        cout << endl;
    }

    ~File() {
        while (!estVide()) {
            defiler();
        }
    }
};

int main() {
    File f;
    int choix, valeur;

    do {
        cout << "\n1. Enfiler";
        cout << "\n2. Defiler";
        cout << "\n3. Afficher";
        cout << "\n4. Quitter";
        cout << "\nVotre choix : ";
        cin >> choix;

        try {
            switch (choix) {
                case 1:
                    cout << "Donner une valeur : ";
                    cin >> valeur;
                    f.enfiler(valeur);
                    break;

                case 2:
                    cout << "Element retire : "
                         << f.defiler() << endl;
                    break;

                case 3:
                    f.afficher();
                    break;

                case 4:
                    cout << "Fin du programme." << endl;
                    break;

                default:
                    cout << "Choix invalide !" << endl;
            }
        }
        catch (exception& e) {
            cout << "Erreur : " << e.what() << endl;
        }

    } while (choix != 4);

    return 0;
}
