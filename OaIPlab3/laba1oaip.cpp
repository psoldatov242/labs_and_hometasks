#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

vector<Product> readProductsFromFile(const string& filename) {
    vector<Product> products;
    ifstream file(filename);
    if (!file.is_open()) {
        return products;
    }

    Product p;
    while (file >> p.name >> p.price >> p.quantity) {
        products.push_back(p);
    }
    file.close();
    return products;
}

void writeProductsToFile(const string& filename, const vector<Product>& products) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& p : products) {
        file << p.name << " " << p.price << " " << p.quantity << endl;
    }
    file.close();
}

void appendProductToFile(const string& filename, const Product& product) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for appending: " << filename << endl;
        return;
    }

    file << product.name << " " << product.price << " " << product.quantity << endl;
    file.close();
}

void writeToOutput(const string& message) {
    ofstream out("output.txt", ios::app);
    if (out.is_open()) {
        out << message << endl;
        out.close();
    }
}

void addProduct() {
    Product p;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, p.name);

    if (p.name.empty()) {
        return;
    }

    cout << "Enter price: ";
    cin >> p.price;
    cout << "Enter quantity: ";
    cin >> p.quantity;

    appendProductToFile("products.txt", p);
    string message = "Added product: " + p.name + ", Price: " + to_string(p.price) + ", Quantity: " + to_string(p.quantity);
    writeToOutput(message);
    cout << "Product added successfully!" << endl;
}

void searchProduct() {
    string searchName;
    cout << "Enter product name to search: ";
    cin.ignore();
    getline(cin, searchName);

    vector<Product> products = readProductsFromFile("products.txt");
    bool found = false;
    string message;

    for (const auto& p : products) {
        if (p.name == searchName) {
            message = "Found product: " + p.name + ", Price: " + to_string(p.price) + ", Quantity: " + to_string(p.quantity);
            cout << message << endl;
            writeToOutput(message);
            found = true;
            break;
        }
    }

    if (!found) {
        message = "Product with name '" + searchName + "' not found";
        cout << message << endl;
        writeToOutput(message);
    }
}

void sortProducts() {
    int criterion;
    cout << "Choose sorting criterion (1 - by price, 2 - by quantity): ";
    cin >> criterion;

    vector<Product> products = readProductsFromFile("products.txt");

    if (criterion == 1) {
        sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
            return a.price < b.price;
            });
        writeToOutput("Sorting by price:");
    }
    else if (criterion == 2) {
        sort(products.begin(), products.end(), [](const Product& a, const Product& b) {
            return a.quantity < b.quantity;
            });
        writeToOutput("Sorting by quantity:");
    }
    else {
        cout << "Invalid sorting criterion!" << endl;
        return;
    }

    writeProductsToFile("products.txt", products);

    for (const auto& p : products) {
        string message = p.name + " " + to_string(p.price) + " " + to_string(p.quantity);
        writeToOutput(message);
    }

    cout << "Products sorted successfully!" << endl;
}

void outputProductsByPrice() {
    double maxPrice;
    cout << "Enter maximum price: ";
    cin >> maxPrice;

    vector<Product> products = readProductsFromFile("products.txt");
    bool found = false;
    string message = "Products with price not more than " + to_string(maxPrice) + ":";
    cout << message << endl;
    writeToOutput(message);

    for (const auto& p : products) {
        if (p.price <= maxPrice) {
            message = p.name + ", Price: " + to_string(p.price) + ", Quantity: " + to_string(p.quantity);
            cout << message << endl;
            writeToOutput(message);
            found = true;
        }
    }

    if (!found) {
        message = "No products found";
        cout << message << endl;
        writeToOutput(message);
    }
}

int main() {
    // Здесь почисмтил файл логов отчета перед новым запуском проги
    ofstream clearFile("output.txt");
    clearFile.close();

    int choice;
    do {
        cout << "\n=== Product Management Menu ===" << endl;
        cout << "1. Add product" << endl;
        cout << "2. Search product" << endl;
        cout << "3. Sort products" << endl;
        cout << "4. Output products by price" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            searchProduct();
            break;
        case 3:
            sortProducts();
            break;
        case 4:
            outputProductsByPrice();
            break;
        case 0:
            cout << "Program finished." << endl;
            writeToOutput("Program finished.");
            break;
        default:
            cout << "Wrong choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}