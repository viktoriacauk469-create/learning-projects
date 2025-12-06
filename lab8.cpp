#include <iostream>
#include<fstream>
#include<vector>
#include<string>
#include<limits>
#include<sstream>

using namespace std;
struct text_editor {
    string name;
    string vurobnuc;
    char licence;//'F' (безкоштовна), 'O' (відкрита), 'P' (платна)
    double rang;
    double price;
};
void print(const text_editor& e,int index) {
    cout << "#" << index + 1 << " "
    << "Name: " << e.name
    << ", Vurobnuc: " << e.vurobnuc
    << ", Licence: " << e.licence
    << ", Rang: " << e.rang
    << ", Price:" << e.price
    << endl;
}
void viewAll(const vector<text_editor>& n) {//перегляд всіх елементів вектора
    if (n.empty()) { cout << "Database empty.\n"; return; }
    for (int i = 0; i < n.size(); i++) {
        print(n[i], i);
    }
}
void addEditor(vector<text_editor>& editors) {//додавання нового елементу
    text_editor n;
    cout << "Write name of the text editor: ";
    getline(cin, n.name);
    cout << "Write vurobnuc of the text editor: ";
    getline(cin, n.vurobnuc);
    do {     
        cout << "Write licence used for the text editor(F - free, O - open-resource, P - paid ): ";
        cin >> n.licence;
        if (n.licence != 'P' && n.licence != 'O' && n.licence != 'F') cout << "Invalid input, try again.\n";
    } while (n.licence !='P'&& n.licence !='O' && n.licence !='F');
    do{
        cout << "Write rang of the text editor(0.0 - 5.0)): ";
        cin >> n.rang;
        if (n.rang < 0.0 || n.rang > 5.0) cout << "Invalid input, try again.\n";
    } while (n.rang < 0.0 || n.rang > 5.0);
    do{
        cout << "Write price of the text editor: ";
        cin >> n.price;
        if (n.price < 0 ) cout << "Invalid input, try again.\n";
    } while (n.price < 0);
    editors.push_back(n);
    cout << "Thanks, new element was added succesfully.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void editElement(vector<text_editor>& editors) {//редагування одного елемента
    viewAll(editors);
    cout << "Choose an index of element you want to edit: ";
    int index;
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (index<=0 || index > editors.size()) {
        cout << "There is no such an element, try again.\n";
        return;
    }
    index--;
    cout << "New name: "; 
    getline(cin, editors[index].name);
    cout << "New vurobnuc: ";
    getline(cin, editors[index].vurobnuc);
    cout << "New licence:";
    do {     
        cout << "Write licence used for the text editor(F - free, O - open-resource, P - paid ): ";
        cin >> editors[index].licence;
        if (editors[index].licence != 'P' && editors[index].licence != 'O' && editors[index].licence != 'F') cout << "Invalid input, try again.\n";
    } while (editors[index].licence !='P'&& editors[index].licence !='O' && editors[index].licence !='F');
    do{
        cout << "Write rang of the text editor(0.0 - 5.0)): ";
        cin >> editors[index].rang;
        if (editors[index].rang < 0.0 || editors[index].rang > 5.0) cout << "Invalid input, try again.\n";
    } while (editors[index].rang < 0.0 || editors[index].rang > 5.0);
    do{
        cout << "Write price of the text editor: ";
        cin >> editors[index].price;
        if (editors[index].price < 0 ) cout << "Invalid input, try again.\n";
    } while (editors[index].price < 0);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void deleteElement(vector<text_editor>& editors) {//видалення елементу
    viewAll(editors);
    cout << "Choose an index of element you want to delete: ";
    int index;
    cin >> index;
    if (index <= 0 || index > editors.size()) {
        cout << "There is no such an element, try again\n";
        return;
    }
    index--;
    editors.erase(editors.begin() + index);
    cout << "Deleted.\n";
    viewAll(editors);
}
void findElement(vector<text_editor>& editors) {//пошук елемента за назвою
    cout << "Search by name: ";
    string nameofel;
    getline(cin, nameofel);
    bool found = false;
    for (int i = 0; i < editors.size(); i++) {
        if (editors[i].name == nameofel) {
            print(editors[i], i);
            found = true;
        }
    }
    if (!found) {
        cout << "Not found.\n";
    }
}
void sortbyprice(vector<text_editor>& editors) {//сортування елементів за зростанням ціни
    for (int i = 0; i < editors.size(); i++) {
        for (int j = i + 1; j < editors.size(); j++) {
            if (editors[i].price > editors[j].price) {
                text_editor temp = editors[i];
                editors[i] = editors[j];
                editors[j] = temp;
            }
        }
    }
    cout << "Sorted by price rising.\n";
    viewAll(editors);
}
int menu() {//вибір дії з елементами
    cout << "\n--- Menu ---\n"
        << "1. Add\n"
        << "2. Search\n"
        << "3. View all\n"
        << "4. Modify\n"
        << "5. Delete\n"
        << "6. Sort by price\n"
        << "0. Exit\n"
        << "Choose: ";
    int c;
    cin >> c;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return c;
}
void intofile(vector<text_editor> editor) {//зберігання інформації в файл
    fstream file;
    file.open("file.txt",ios::out);
    file.close(); 
    file.open("file.txt",ios::app);
    if (!file.is_open()) {
        cout << "Error: could not open file.txt\n";
        return;
    }
    for (int i = 0; i < editor.size(); i++) {
        file << editor[i].name 
            << " " << editor[i].vurobnuc 
            << " " << editor[i].licence 
            << " " << editor[i].rang 
            << " " << editor[i].price 
            << endl;
    }
    file.close();
    cout << "Data saved to file.txt\n";
}
int main()
{
    ifstream f("file.txt");
    if (!f.is_open()) {
        cout << "Couldn't open a file\n";
        return 1;
    }
    vector<text_editor> array;
    string line;
    while (getline(f, line)) {
        istringstream iss(line);
        text_editor te;
        iss >> te.name >> te.vurobnuc >> te.licence >> te.rang >> te.price;
        array.push_back(te);
    }
    f.close();
    while (true) {
        int num = menu();
        if (num != 0) {
            if (num == 1) {
                addEditor(array);
            }
            else if(num == 2) {
                findElement(array);
            }
            else if (num == 3) {
                viewAll(array);
            }
            else if (num == 4) {
                editElement(array);
            }
            else if (num == 5) {
                deleteElement(array);
            }
            else if (num == 6) {
                sortbyprice(array);
            }
        }
        else if (num == 0) {
            intofile(array);
            break;
        }
        else {
            cout << "There is no such option!\n";
        }
    }
}
//maybe do something to avoid errors when something is typed wrong 

