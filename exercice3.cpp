
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class TableHachage {
private:
    vector<list<pair<int, string>>> table;
    int tailleTable;

    int hachage(int cle) {
        return (cle % tailleTable + tailleTable) % tailleTable;
    }

public:
    TableHachage(int taille) {
        tailleTable = taille;
        table.resize(tailleTable);
    }

    void inserer(int cle, string valeur) {
        int index = hachage(cle);

        for (auto& element : table[index]) {
            if (element.first == cle) {
                element.second = valeur;
                return;
            }
        }

        table[index].push_back({cle, valeur});
    }

    bool rechercher(int cle, string& valeur) {
        int index = hachage(cle);

        for (auto element : table[index]) {
            if (element.first == cle) {
                valeur = element.second;
                return true;
            }
        }

        return false;
    }

    void supprimer(int cle) {
        int index = hachage(cle);

        for (auto it = table[index].begin();
             it != table[index].end(); it++) {

            if (it->first == cle) {
                table[index].erase(it);
                return;
            }
        }
    }

    void afficher() {
        for (int i = 0; i < tailleTable; i++) {
            cout << "Case " << i << " : ";

            for (auto element : table[i]) {
                cout << "[" << element.first
                     << ", " << element.second << "] -> ";
            }

            cout << "NULL" << endl;
        }
    }
};

int main() {
    TableHachage t(5);

    t.inserer(10, "Ali");
    t.inserer(15, "Sara");
    t.inserer(20, "Youssef");

    cout << "Table de hachage :" << endl;
    t.afficher();

    string valeur;

    if (t.rechercher(15, valeur)) {
        cout << "\nValeur trouvee : " << valeur << endl;
    } else {
        cout << "\nCle introuvable !" << endl;
    }

    t.supprimer(15);

    cout << "\nApres suppression :" << endl;
    t.afficher();

    return 0;
}
