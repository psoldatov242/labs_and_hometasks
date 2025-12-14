#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class MusicalInstrument {
protected:
    string name;
    string material;
    double babki;
    vector<string> owners;
    
public:
    MusicalInstrument(string n = "", string m = "", double b = 0) 
        : name(n), material(m), babki(b) {}
    
    virtual void display() {
        cout << name << " (" << material << ") - $" << babki;
        if(!owners.empty()) {
            cout << ", Владельцы: ";
            for(auto& o : owners) cout << o << " ";
        }
        cout << endl;
    }
    
    virtual string getType() = 0;
    
    string getName() { return name; }
    string getMaterial() { return material; }
    double getPrice() { return babki; }
    vector<string>& getOwners() { return owners; }
    
    void setPrice(double p) { babki = p; }
    void setMaterial(string m) { material = m; }
    void addOwner(string owner) { owners.push_back(owner); }
};

class StringInstrument : public MusicalInstrument {
    int numStrings;
    string tuning;
    
public:
    StringInstrument(string n = "", string m = "", double b = 0, 
                     int s = 0, string t = "")
        : MusicalInstrument(n, m, b), numStrings(s), tuning(t) {}
    
    void display() override {
        cout << "Струнный: ";
        MusicalInstrument::display();
        cout << "  Струн: " << numStrings << ", Строй: " << tuning << endl;
    }
    
    string getType() override { return "String"; }
    int getNumStrings() { return numStrings; }
    string getTuning() { return tuning; }
};

class BrassInstrument : public MusicalInstrument {
    string brassType;
    double tubeLength;
    
public:
    BrassInstrument(string n = "", string m = "", double b = 0,
                    string br = "", double l = 0)
        : MusicalInstrument(n, m, b), brassType(br), tubeLength(l) {}
    
    void display() override {
        cout << "Духовой: ";
        MusicalInstrument::display();
        cout << "  Латунь: " << brassType << ", Длина: " << tubeLength << "см" << endl;
    }
    
    string getType() override { return "Brass"; }
    double getTubeLength() { return tubeLength; }
};

void loadFromFile(vector<MusicalInstrument*>& gadgets, string filename) {
    ifstream file(filename);
    if(!file) {
        cout << "Файл не найден!" << endl;
        return;
    }
    
    string line;
    while(getline(file, line)) {
        vector<string> parts;
        string part;
        
        for(char c : line) {
            if(c == ';') {
                parts.push_back(part);
                part = "";
            } else {
                part += c;
            }
        }
        parts.push_back(part);
        
        if(parts.size() < 5) continue;
        
        string type = parts[0];
        string name = parts[1];
        string material = parts[2];
        double price = stod(parts[3]);
        
        string param = parts[4];
        size_t dashPos = param.find('-');
        
        if(type == "String") {
            int strings = stoi(param.substr(0, dashPos));
            string tuning = param.substr(dashPos + 1);
            StringInstrument* si = new StringInstrument(name, material, price, strings, tuning);
            
            if(parts.size() > 5) {
                string ownersStr = parts[5];
                string owner;
                for(char c : ownersStr) {
                    if(c == '|' || c == ' ') {
                        if(!owner.empty()) {
                            si->addOwner(owner);
                            owner = "";
                        }
                    } else {
                        owner += c;
                    }
                }
                if(!owner.empty()) si->addOwner(owner);
            }
            
            gadgets.push_back(si);
        }
        else if(type == "Brass") {
            string brass = param.substr(0, dashPos);
            double length = stod(param.substr(dashPos + 1));
            BrassInstrument* bi = new BrassInstrument(name, material, price, brass, length);
            
            if(parts.size() > 5) {
                string ownersStr = parts[5];
                string owner;
                for(char c : ownersStr) {
                    if(c == '|' || c == ' ') {
                        if(!owner.empty()) {
                            bi->addOwner(owner);
                            owner = "";
                        }
                    } else {
                        owner += c;
                    }
                }
                if(!owner.empty()) bi->addOwner(owner);
            }
            
            gadgets.push_back(bi);
        }
    }
    file.close();
    cout << "Загружено " << gadgets.size() << " инструментов" << endl;
}

void displayAll(vector<MusicalInstrument*>& gadgets) {
    cout << "\n=== ВСЕ ИНСТРУМЕНТЫ ===" << endl;
    for(int i = 0; i < gadgets.size(); i++) {
        cout << i+1 << ". ";
        gadgets[i]->display();
    }
}

void addInstrument(vector<MusicalInstrument*>& gadgets) {
    cout << "\nДобавить: 1-Струнный, 2-Духовой: ";
    int type;
    cin >> type;
    
    string name, material;
    double price;
    cout << "Название: "; cin >> name;
    cout << "Материал: "; cin >> material;
    cout << "Цена: "; cin >> price;
    
    if(type == 1) {
        int strings;
        string tuning;
        cout << "Кол-во струн: "; cin >> strings;
        cout << "Строй: "; cin >> tuning;
        gadgets.push_back(new StringInstrument(name, material, price, strings, tuning));
    } else {
        string brass;
        double length;
        cout << "Тип латуни: "; cin >> brass;
        cout << "Длина трубы: "; cin >> length;
        gadgets.push_back(new BrassInstrument(name, material, price, brass, length));
    }
    cout << "Добавлено!" << endl;
}

void editInstrument(vector<MusicalInstrument*>& gadgets) {
    displayAll(gadgets);
    cout << "Номер для редактирования: ";
    int n;
    cin >> n;
    n--;
    
    if(n < 0 || n >= gadgets.size()) {
        cout << "Неверный номер!" << endl;
        return;
    }
    
    double newPrice;
    string newMaterial;
    cout << "Новая цена: "; cin >> newPrice;
    cout << "Новый материал: "; cin >> newMaterial;
    
    gadgets[n]->setPrice(newPrice);
    gadgets[n]->setMaterial(newMaterial);
    
    cout << "Сохранено!" << endl;
}

void deleteInstrument(vector<MusicalInstrument*>& gadgets) {
    displayAll(gadgets);
    cout << "Номер для удаления: ";
    int n;
    cin >> n;
    n--;
    
    if(n < 0 || n >= gadgets.size()) {
        cout << "Неверный номер!" << endl;
        return;
    }
    
    delete gadgets[n];
    gadgets.erase(gadgets.begin() + n);
    cout << "Удалено!" << endl;
}

void task7_1(vector<MusicalInstrument*>& gadgets) {
    int count = 0;
    for(auto* inst : gadgets) {
        if(inst->getType() == "String") {
            StringInstrument* si = (StringInstrument*)inst;
            if(si->getNumStrings() > 6) count++;
        }
    }
    cout << "Струнных с >6 струнами: " << count << endl;
}

void task7_2(vector<MusicalInstrument*>& gadgets) {
    sort(gadgets.begin(), gadgets.end(), 
         [](MusicalInstrument* a, MusicalInstrument* b) {
             return a->getPrice() < b->getPrice();
         });
    cout << "Отсортировано по цене!" << endl;
}

void task7_3(vector<MusicalInstrument*>& gadgets) {
    double maxLength = 0;
    BrassInstrument* longest = nullptr;
    
    for(auto* inst : gadgets) {
        if(inst->getType() == "Brass") {
            BrassInstrument* bi = (BrassInstrument*)inst;
            if(bi->getTubeLength() > maxLength) {
                maxLength = bi->getTubeLength();
                longest = bi;
            }
        }
    }
    
    if(longest) {
        cout << "Самый длинный духовой: ";
        longest->display();
    }
}

void task8(vector<MusicalInstrument*>& gadgets) {
    cout << "Деревянные дороже $600:" << endl;
    for(auto* inst : gadgets) {
        if(inst->getMaterial() == "Wood" && inst->getPrice() > 600) {
            inst->display();
        }
    }
}

void task9(vector<MusicalInstrument*>& gadgets) {
    int maxStrings = 0;
    StringInstrument* maxInst = nullptr;
    
    for(auto* inst : gadgets) {
        if(inst->getType() == "String") {
            StringInstrument* si = (StringInstrument*)inst;
            if(si->getNumStrings() > maxStrings) {
                maxStrings = si->getNumStrings();
                maxInst = si;
            }
        }
    }
    
    if(maxInst) {
        cout << "Струнный с максимальным числом струн: ";
        maxInst->display();
    }
}

void task10(vector<MusicalInstrument*>& gadgets) {
    vector<StringInstrument*> strings;
    
    for(auto* inst : gadgets) {
        if(inst->getType() == "String") {
            strings.push_back((StringInstrument*)inst);
        }
    }
    
    sort(strings.begin(), strings.end(), 
         [](StringInstrument* a, StringInstrument* b) {
             if(a->getTuning() != b->getTuning())
                 return a->getTuning() < b->getTuning();
             return a->getPrice() < b->getPrice();
         });
    
    cout << "Струнные отсортированы по строю и цене!" << endl;
    for(auto* si : strings) si->display();
}

void saveToFile(vector<MusicalInstrument*>& gadgets, string filename) {
    ofstream file(filename);
    for(auto* inst : gadgets) {
        if(inst->getType() == "String") {
            StringInstrument* si = (StringInstrument*)inst;
            file << "String;" << si->getName() << ";" 
                 << si->getMaterial() << ";" << si->getPrice() << ";"
                 << si->getNumStrings() << "-" << si->getTuning() << ";";
            
            auto& owners = si->getOwners();
            for(int i = 0; i < owners.size(); i++) {
                file << owners[i];
                if(i < owners.size()-1) file << "|";
            }
            file << endl;
        }
        else {
            BrassInstrument* bi = (BrassInstrument*)inst;
            file << "Brass;" << bi->getName() << ";" 
                 << bi->getMaterial() << ";" << bi->getPrice() << ";"
                 << "BrassType-" << bi->getTubeLength() << ";";
            
            auto& owners = bi->getOwners();
            for(int i = 0; i < owners.size(); i++) {
                file << owners[i];
                if(i < owners.size()-1) file << "|";
            }
            file << endl;
        }
    }
    file.close();
    cout << "Сохранено в " << filename << endl;
}

int main() {
    vector<MusicalInstrument*> gadgets;
    
    gadgets.push_back(new StringInstrument("Гитара", "Дерево", 500, 6, "Стандарт"));
    gadgets.push_back(new BrassInstrument("Труба", "Латунь", 1200, "Желтая", 120));
    
    while(true) {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Загрузить из файла" << endl;
        cout << "2. Показать все" << endl;
        cout << "3. Добавить" << endl;
        cout << "4. Редактировать" << endl;
        cout << "5. Удалить" << endl;
        cout << "6. Сохранить в файл" << endl;
        cout << "7. Задание 7 (лямбды)" << endl;
        cout << "8. Задание 8 (фильтр)" << endl;
        cout << "9. Задание 9 (макс струны)" << endl;
        cout << "10. Задание 10 (сортировка)" << endl;
        cout << "0. Выход" << endl;
        cout << "Выбор: ";
        
        int choice;
        cin >> choice;
        
        switch(choice) {
            case 1:
                loadFromFile(gadgets, "catalog.txt");
                break;
            case 2:
                displayAll(gadgets);
                break;
            case 3:
                addInstrument(gadgets);
                break;
            case 4:
                editInstrument(gadgets);
                break;
            case 5:
                deleteInstrument(gadgets);
                break;
            case 6:
                saveToFile(gadgets, "output.txt");
                break;
            case 7:
                task7_1(gadgets);
                task7_2(gadgets);
                task7_3(gadgets);
                break;
            case 8:
                task8(gadgets);
                break;
            case 9:
                task9(gadgets);
                break;
            case 10:
                task10(gadgets);
                break;
            case 0:
                for(auto* inst : gadgets) delete inst;
                return 0;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
}