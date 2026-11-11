
#include <iostream>
using namespace std;

class Noeud {
public:
    int valeur;
    Noeud* suivant;

    Noeud(int v) {
        valeur = v;
        suivant = nullptr;
    }
};

class ListeChainee {
private:
    Noeud* tete;
    int nombre;

public:
    ListeChainee() {
        tete = nullptr;
        nombre = 0;
    }

    void ajouterDebut(int valeur) {
        Noeud* nouveau = new Noeud(valeur);
        nouveau->suivant = tete;
        tete = nouveau;
        nombre++;
    }

    void ajouterFin(int valeur) {
        Noeud* nouveau = new Noeud(valeur);

        if (tete == nullptr) {
            tete = nouveau;
        } else {
            Noeud* courant = tete;
            while (courant->suivant != nullptr) {
                courant = courant->suivant;
            }
            courant->suivant = nouveau;
        }
        nombre++;
    }

    void supprimer(int valeur) {
        if (tete == nullptr) return;

        if (tete->valeur == valeur) {
            Noeud* temp = tete;
            tete = tete->suivant;
            delete temp;
            nombre--;
            return;
        }

        Noeud* courant = tete;

        while (courant->suivant != nullptr &&
               courant->suivant->valeur != valeur) {
            courant = courant->suivant;
        }

        if (courant->suivant != nullptr) {
            Noeud* temp = courant->suivant;
            courant->suivant = temp->suivant;
            delete temp;
            nombre--;
        }
    }

    void afficher() {
        Noeud* courant = tete;

        while (courant != nullptr) {
            cout << courant->valeur << " -> ";
            courant = courant->suivant;
        }

        cout << "NULL" << endl;
    }

    int taille() {
        return nombre;
    }

    ~ListeChainee() {
        Noeud* courant = tete;

        while (courant != nullptr) {
            Noeud* temp = courant;
            courant = courant->suivant;
            delete temp;
        }
    }
};

int main() {
    ListeChainee liste;

    liste.ajouterDebut(10);
    liste.ajouterDebut(5);
    liste.ajouterFin(20);

    cout << "Liste : ";
    liste.afficher();

    liste.supprimer(10);

    cout << "Apres suppression : ";
    liste.afficher();

    cout << "Taille : " << liste.taille() << endl;

    return 0;
}
