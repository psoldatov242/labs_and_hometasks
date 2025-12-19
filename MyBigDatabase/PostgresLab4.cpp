#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <libpq-fe.h>
#include <windows.h>

// Pair шаблон
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(const T1& f, const T2& s) : first(f), second(s) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    void setFirst(const T1& f) { first = f; }
    void setSecond(const T2& s) { second = s; }
};

// Запись каждого лога через класс здесь
class Logger {
private:
    std::ofstream logFile;

public:
    Logger(const std::string& filename = "log.txt") {
        logFile.open(filename, std::ios::app);
    }

    ~Logger() {
        if (logFile.is_open()) logFile.close();
    }

    void log(const std::string& operation) {
        if (logFile.is_open()) {
            logFile << operation << std::endl;
        }
        std::cout << "[LOG] " << operation << std::endl;
    }
};

// Стандартные классы для работы
class Database {
private:
    PGconn* connection;

public:
    Database(const std::string& connStr) {
        connection = PQconnectdb(connStr.c_str());
        if (PQstatus(connection) != CONNECTION_OK) {
            throw std::runtime_error(PQerrorMessage(connection));
        }
    }

    ~Database() {
        if (connection) {
            PQfinish(connection);
        }
    }

    void execute(const std::string& sql) {
        PGresult* res = PQexec(connection, sql.c_str());
        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            std::string error = PQerrorMessage(connection);
            PQclear(res);
            throw std::runtime_error("SQL Error: " + error);
        }
        PQclear(res);
    }

    std::vector<std::vector<std::string>> query(const std::string& sql) {
        PGresult* res = PQexec(connection, sql.c_str());
        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            std::string error = PQerrorMessage(connection);
            PQclear(res);
            throw std::runtime_error("Query Error: " + error);
        }

        std::vector<std::vector<std::string>> result;
        int rows = PQntuples(res);
        int cols = PQnfields(res);

        for (int i = 0; i < rows; i++) {
            std::vector<std::string> row;
            for (int j = 0; j < cols; j++) {
                row.push_back(PQgetvalue(res, i, j) ? PQgetvalue(res, i, j) : "");
            }
            result.push_back(row);
        }

        PQclear(res);
        return result;
    }

    PGconn* getConnection() { return connection; }

    void beginTransaction() { execute("BEGIN"); }
    void commitTransaction() { execute("COMMIT"); }
    void rollbackTransaction() { execute("ROLLBACK"); }
};

// Класс категории
class Category {
private:
    int id;
    std::string name;
    Database* db;

public:
    Category(Database* database, const std::string& categoryName = "", int categoryId = -1)
        : db(database), name(categoryName), id(categoryId) {
    }

    void save() {
        try {
            db->beginTransaction();
            db->execute("INSERT INTO categories (category_name) VALUES ('" + name + "')");
            db->commitTransaction();
            std::cout << "Category added successfully!" << std::endl;
        }
        catch (...) {
            db->rollbackTransaction();
            throw;
        }
    }

    static std::vector<Category> getAll(Database* db) {
        auto result = db->query("SELECT id, category_name FROM categories ORDER BY category_name");
        std::vector<Category> categories;
        for (const auto& row : result) {
            categories.emplace_back(db, row[1], std::stoi(row[0]));
        }
        return categories;
    }

    static void displayAll(Database* db) {
        auto categories = getAll(db);
        std::cout << "\n=== ALL CATEGORIES ===" << std::endl;
        if (categories.empty()) {
            std::cout << "No categories found." << std::endl;
            return;
        }

        for (const auto& category : categories) {
            std::cout << category.id << ". " << category.name << std::endl;
        }
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
};

// Класс продукта
class Product {
protected:
    int id;
    std::string name;
    double price;
    int quantity;
    int categoryId;
    Database* db;

public:
    Product(Database* database, const std::string& productName = "",
        double productPrice = 0.0, int productQuantity = 0,
        int productCategoryId = -1, int productId = -1)
        : db(database), name(productName), price(productPrice),
        quantity(productQuantity), categoryId(productCategoryId), id(productId) {
    }

    virtual ~Product() {}

    virtual void save() {
        try {
            db->beginTransaction();
            std::string sql = "INSERT INTO products (name, price, quantity, category_id) VALUES ('" +
                name + "', " + std::to_string(price) + ", " + std::to_string(quantity) + ", " +
                std::to_string(categoryId) + ")";
            db->execute(sql);
            db->commitTransaction();
            std::cout << "Product added successfully!" << std::endl;
        }
        catch (...) {
            db->rollbackTransaction();
            throw;
        }
    }

    static std::vector<Product> getAll(Database* db) {
        auto result = db->query("SELECT id, name, price, quantity, category_id FROM products ORDER BY name");
        std::vector<Product> products;
        for (const auto& row : result) {
            products.emplace_back(db, row[1], std::stod(row[2]), std::stoi(row[3]),
                std::stoi(row[4]), std::stoi(row[0]));
        }
        return products;
    }

    static void displayAll(Database* db) {
        auto products = getAll(db);
        std::cout << "\n=== ALL PRODUCTS ===" << std::endl;
        if (products.empty()) {
            std::cout << "No products found." << std::endl;
            return;
        }

        for (const auto& product : products) {
            std::cout << product.id << ". " << product.name << " | Price: $" << product.price
                << " | Stock: " << product.quantity << " | Category ID: " << product.categoryId << std::endl;
        }
    }

    static std::vector<Product> getByCategory(Database* db, int categoryId) {
        auto result = db->query("SELECT id, name, price, quantity, category_id FROM products WHERE category_id = " +
            std::to_string(categoryId) + " ORDER BY name");
        std::vector<Product> products;
        for (const auto& row : result) {
            products.emplace_back(db, row[1], std::stod(row[2]), std::stoi(row[3]),
                std::stoi(row[4]), std::stoi(row[0]));
        }
        return products;
    }

    int getId() const { return id; }
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    void setQuantity(int newQuantity) {
        try {
            db->beginTransaction();
            db->execute("UPDATE products SET quantity = " + std::to_string(newQuantity) +
                " WHERE id = " + std::to_string(id));
            db->commitTransaction();
            quantity = newQuantity;
        }
        catch (...) {
            db->rollbackTransaction();
            throw;
        }
    }
};

// Добавление нецифрового продукта
class PhysicalProduct : public Product {
private:
    std::string weight;
    std::string dimensions;

public:
    PhysicalProduct(Database* database, const std::string& productName = "",
        double productPrice = 0.0, int productQuantity = 0,
        int productCategoryId = -1, const std::string& productWeight = "",
        const std::string& productDimensions = "", int productId = -1)
        : Product(database, productName, productPrice, productQuantity, productCategoryId, productId),
        weight(productWeight), dimensions(productDimensions) {
    }
};

// Добавление цифрового продукта
class DigitalProduct : public Product {
private:
    std::string fileSize;
    std::string downloadLink;

public:
    DigitalProduct(Database* database, const std::string& productName = "",
        double productPrice = 0.0, int productQuantity = 0,
        int productCategoryId = -1, const std::string& productFileSize = "",
        const std::string& productDownloadLink = "", int productId = -1)
        : Product(database, productName, productPrice, productQuantity, productCategoryId, productId),
        fileSize(productFileSize), downloadLink(productDownloadLink) {
    }
};

// Класс продаж
class Sale {
private:
    int id;
    int productId;
    std::string saleDate;
    int quantitySold;
    Database* db;

public:
    Sale(Database* database, int saleProductId = -1,
        int saleQuantitySold = 0, const std::string& date = "", int saleId = -1)
        : db(database), productId(saleProductId), quantitySold(saleQuantitySold),
        saleDate(date.empty() ? getCurrentDate() : date), id(saleId) {
    }

    void save() {
        try {
            db->beginTransaction();

            auto productResult = db->query("SELECT quantity FROM products WHERE id = " + std::to_string(productId));
            if (productResult.empty()) throw std::runtime_error("Product not found!");

            int currentQuantity = std::stoi(productResult[0][0]);
            if (currentQuantity < quantitySold) throw std::runtime_error("Not enough stock!");

            db->execute("INSERT INTO sales (product_id, sale_date, quantity_sold) VALUES (" +
                std::to_string(productId) + ", '" + saleDate + "', " + std::to_string(quantitySold) + ")");

            int newQuantity = currentQuantity - quantitySold;
            db->execute("UPDATE products SET quantity = " + std::to_string(newQuantity) +
                " WHERE id = " + std::to_string(productId));

            db->commitTransaction();
            std::cout << "Sale recorded successfully!" << std::endl;
        }
        catch (...) {
            db->rollbackTransaction();
            throw;
        }
    }

    static std::vector<Sale> getAll(Database* db) {
        auto result = db->query("SELECT s.id, s.product_id, p.name, s.sale_date, s.quantity_sold, p.price FROM sales s JOIN products p ON s.product_id = p.id ORDER BY s.sale_date DESC");
        std::vector<Sale> sales;
        for (const auto& row : result) {
            Sale sale(db, std::stoi(row[1]), std::stoi(row[4]), row[3], std::stoi(row[0]));
            sales.push_back(sale);
        }
        return sales;
    }

    static void displayAll(Database* db) {
        auto result = db->query("SELECT s.id, p.name, s.sale_date, s.quantity_sold, p.price FROM sales s JOIN products p ON s.product_id = p.id ORDER BY s.sale_date DESC");
        std::cout << "\n=== ALL SALES ===" << std::endl;
        if (result.empty()) {
            std::cout << "No sales found." << std::endl;
            return;
        }

        double total = 0;
        for (const auto& row : result) {
            double saleTotal = std::stod(row[3]) * std::stod(row[4]);
            total += saleTotal;
            std::cout << row[0] << ". " << row[1] << " | Date: " << row[2]
                << " | Qty: " << row[3] << " | Total: $" << saleTotal << std::endl;
        }
        std::cout << "GRAND TOTAL: $" << total << std::endl;
    }

    static std::vector<Pair<std::string, int>> getTopSellingProducts(Database* db, int limit = 5) {
        auto result = db->query("SELECT p.name, SUM(s.quantity_sold) as total FROM sales s JOIN products p ON s.product_id = p.id GROUP BY p.name ORDER BY total DESC LIMIT " + std::to_string(limit));
        std::vector<Pair<std::string, int>> topProducts;
        for (const auto& row : result) {
            topProducts.emplace_back(row[0], std::stoi(row[1]));
        }
        return topProducts;
    }

    static std::vector<Pair<std::string, double>> getRevenueByProduct(Database* db) {
        auto result = db->query("SELECT p.name, SUM(s.quantity_sold * p.price) as revenue FROM sales s JOIN products p ON s.product_id = p.id GROUP BY p.name ORDER BY revenue DESC");
        std::vector<Pair<std::string, double>> revenueList;
        for (const auto& row : result) {
            revenueList.emplace_back(row[0], std::stod(row[1]));
        }
        return revenueList;
    }

    static std::vector<Pair<std::string, int>> getSoldUnitsByProduct(Database* db) {
        auto result = db->query("SELECT p.name, SUM(s.quantity_sold) as units FROM sales s JOIN products p ON s.product_id = p.id GROUP BY p.name ORDER BY units DESC");
        std::vector<Pair<std::string, int>> unitsList;
        for (const auto& row : result) {
            unitsList.emplace_back(row[0], std::stoi(row[1]));
        }
        return unitsList;
    }

    static double getTotalRevenue(Database* db) {
        auto result = db->query("SELECT SUM(s.quantity_sold * p.price) as total FROM sales s JOIN products p ON s.product_id = p.id");
        if (!result.empty() && !result[0][0].empty()) {
            return std::stod(result[0][0]);
        }
        return 0.0;
    }

private:
    static std::string getCurrentDate() {
        std::time_t now = std::time(nullptr);
        std::tm timeinfo;
        localtime_s(&timeinfo, &now);
        char buffer[80];
        std::strftime(buffer, 80, "%Y-%m-%d", &timeinfo);
        return std::string(buffer);
    }
};

// Работа меню 
void setupDatabase() {
    try {
        std::cout << "==========================================" << std::endl;
        std::cout << "POSTGRESQL PRODUCT MANAGEMENT SYSTEM" << std::endl;
        std::cout << "==========================================" << std::endl;

        Database db("host=localhost port=5432 dbname=postgres user=postgres password=1991");

        try {
            db.execute("CREATE DATABASE products_db");
            std::cout << "[SUCCESS] Database 'products_db' created" << std::endl;
        }
        catch (...) {
            std::cout << "[INFO] Database 'products_db' already exists" << std::endl;
        }

        Database lab_db("host=localhost port=5432 dbname=products_db user=postgres password=1991");

        std::cout << "\nCreating tables..." << std::endl;

        lab_db.execute(R"(
            CREATE TABLE IF NOT EXISTS categories (
                id SERIAL PRIMARY KEY,
                category_name VARCHAR(100) NOT NULL UNIQUE
            )
        )");
        std::cout << "- Table 'categories' created" << std::endl;

        lab_db.execute(R"(
            CREATE TABLE IF NOT EXISTS products (
                id SERIAL PRIMARY KEY,
                name VARCHAR(100) NOT NULL,
                price DECIMAL(10,2) CHECK (price >= 0),
                quantity INTEGER CHECK (quantity >= 0),
                category_id INTEGER REFERENCES categories(id)
            )
        )");
        std::cout << "- Table 'products' created" << std::endl;

        lab_db.execute(R"(
            CREATE TABLE IF NOT EXISTS sales (
                id SERIAL PRIMARY KEY,
                product_id INTEGER REFERENCES products(id),
                sale_date DATE DEFAULT CURRENT_DATE,
                quantity_sold INTEGER CHECK (quantity_sold > 0)
            )
        )");
        std::cout << "- Table 'sales' created" << std::endl;

        std::cout << "\nCreating indexes..." << std::endl;

        try {
            lab_db.execute("CREATE INDEX idx_category_name ON categories(category_name)");
            std::cout << "- Index on categories(category_name) created" << std::endl;
        }
        catch (...) {
            std::cout << "- Index on categories(category_name) already exists" << std::endl;
        }

        try {
            lab_db.execute("CREATE INDEX idx_product_name ON products(name)");
            std::cout << "- Index on products(name) created" << std::endl;
        }
        catch (...) {
            std::cout << "- Index on products(name) already exists" << std::endl;
        }

        try {
            lab_db.execute("CREATE INDEX idx_sale_date ON sales(sale_date)");
            std::cout << "- Index on sales(sale_date) created" << std::endl;
        }
        catch (...) {
            std::cout << "- Index on sales(sale_date) already exists" << std::endl;
        }

        std::cout << "\n==========================================" << std::endl;
        std::cout << "SETUP COMPLETED SUCCESSFULLY!" << std::endl;
        std::cout << "==========================================" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        std::cout << "Check if:" << std::endl;
        std::cout << "1. PostgreSQL is running" << std::endl;
        std::cout << "2. Password is correct" << std::endl;
        throw;
    }
}

void showMenu() {
    std::cout << "\n=== PRODUCT MANAGEMENT SYSTEM ===" << std::endl;
    std::cout << "1. Add Category" << std::endl;
    std::cout << "2. Add Product" << std::endl;
    std::cout << "3. Add Sale Record" << std::endl;
    std::cout << "4. View All Products" << std::endl;
    std::cout << "5. View All Sales" << std::endl;
    std::cout << "6. View Products by Category" << std::endl;
    std::cout << "7. Calculate Total Revenue" << std::endl;
    std::cout << "8. Show Top 5 Products" << std::endl;
    std::cout << "9. Show Revenue by Product" << std::endl;
    std::cout << "10. Show Sold Units by Product" << std::endl;
    std::cout << "11. View All Categories" << std::endl;
    std::cout << "12. Exit" << std::endl;
    std::cout << "Select option (1-12): ";
}

void addCategory(Database& db) {
    std::string name;
    std::cout << "Enter category name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    Category category(&db, name);
    category.save();
}

void addProduct(Database& db) {
    std::string name, price_str, quantity_str, category_id_str;
    int productType;

    std::cout << "Select product type:" << std::endl;
    std::cout << "1. Physical Product" << std::endl;
    std::cout << "2. Digital Product" << std::endl;
    std::cout << "Enter choice (1-2): ";
    std::cin >> productType;
    std::cin.ignore();

    std::cout << "Enter product name: ";
    std::getline(std::cin, name);

    std::cout << "Enter price: ";
    std::getline(std::cin, price_str);

    std::cout << "Enter quantity: ";
    std::getline(std::cin, quantity_str);

    Category::displayAll(&db);

    std::cout << "Enter category ID: ";
    std::getline(std::cin, category_id_str);

    try {
        double price = std::stod(price_str);
        int quantity = std::stoi(quantity_str);
        int category_id = std::stoi(category_id_str);

        if (productType == 1) {
            std::string weight, dimensions;
            std::cout << "Enter weight: ";
            std::getline(std::cin, weight);
            std::cout << "Enter dimensions: ";
            std::getline(std::cin, dimensions);

            PhysicalProduct product(&db, name, price, quantity, category_id, weight, dimensions);
            product.save();
        }
        else if (productType == 2) {
            std::string fileSize, downloadLink;
            std::cout << "Enter file size: ";
            std::getline(std::cin, fileSize);
            std::cout << "Enter download link: ";
            std::getline(std::cin, downloadLink);

            DigitalProduct product(&db, name, price, quantity, category_id, fileSize, downloadLink);
            product.save();
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void addSaleRecord(Database& db) {
    try {
        auto products = Product::getAll(&db);
        if (products.empty()) {
            std::cout << "No products available!" << std::endl;
            return;
        }

        std::cout << "\n=== AVAILABLE PRODUCTS ===" << std::endl;
        for (const auto& product : products) {
            if (product.getQuantity() > 0) {
                std::cout << product.getId() << ". " << product.getName()
                    << " | Price: $" << product.getPrice()
                    << " | Stock: " << product.getQuantity() << std::endl;
            }
        }

        std::string product_id_str, quantity_str;
        std::cout << "\nEnter product ID: ";
        std::cin.ignore();
        std::getline(std::cin, product_id_str);

        std::cout << "Enter quantity to sell: ";
        std::getline(std::cin, quantity_str);

        int product_id = std::stoi(product_id_str);
        int quantity = std::stoi(quantity_str);

        Sale sale(&db, product_id, quantity);
        sale.save();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void viewProductsByCategory(Database& db) {
    Category::displayAll(&db);

    std::string category_id_str;
    std::cout << "\nEnter category ID to view products: ";
    std::cin.ignore();
    std::getline(std::cin, category_id_str);

    try {
        int category_id = std::stoi(category_id_str);
        auto products = Product::getByCategory(&db, category_id);

        std::cout << "\n=== PRODUCTS IN CATEGORY ===" << std::endl;
        if (products.empty()) {
            std::cout << "No products in this category." << std::endl;
            return;
        }

        for (const auto& product : products) {
            std::cout << product.getId() << ". " << product.getName()
                << " | Price: $" << product.getPrice()
                << " | Stock: " << product.getQuantity() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void calculateTotalRevenue(Database& db) {
    double totalRevenue = Sale::getTotalRevenue(&db);
    std::cout << "\n=== TOTAL REVENUE ===" << std::endl;
    std::cout << "Total Revenue: $" << totalRevenue << std::endl;
}

void showTop5Products(Database& db) {
    auto topProducts = Sale::getTopSellingProducts(&db, 5);

    std::cout << "\n=== TOP 5 SELLING PRODUCTS ===" << std::endl;
    if (topProducts.empty()) {
        std::cout << "No sales data." << std::endl;
        return;
    }

    int rank = 1;
    for (const auto& product : topProducts) {
        std::cout << rank++ << ". " << product.getFirst()
            << " - Sold: " << product.getSecond() << std::endl;
    }
}

void showRevenueByProduct(Database& db) {
    auto revenueList = Sale::getRevenueByProduct(&db);

    std::cout << "\n=== REVENUE BY PRODUCT ===" << std::endl;
    if (revenueList.empty()) {
        std::cout << "No sales data." << std::endl;
        return;
    }

    for (const auto& item : revenueList) {
        std::cout << item.getFirst() << " - Revenue: $" << item.getSecond() << std::endl;
    }
}

void showSoldUnitsByProduct(Database& db) {
    auto unitsList = Sale::getSoldUnitsByProduct(&db);

    std::cout << "\n=== SOLD UNITS BY PRODUCT ===" << std::endl;
    if (unitsList.empty()) {
        std::cout << "No sales data." << std::endl;
        return;
    }

    for (const auto& item : unitsList) {
        std::cout << item.getFirst() << " - Units Sold: " << item.getSecond() << std::endl;
    }
}

// Цикл работы процесса
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Logger logger("log.txt");
    logger.log("========== PROGRAM STARTED ==========");

    try {
        setupDatabase();
        Database lab_db("host=localhost port=5432 dbname=products_db user=postgres password=1991");

        int choice;
        do {
            showMenu();
            std::cin >> choice;

            switch (choice) {
            case 1: addCategory(lab_db); break;
            case 2: addProduct(lab_db); break;
            case 3: addSaleRecord(lab_db); break;
            case 4: Product::displayAll(&lab_db); break;
            case 5: Sale::displayAll(&lab_db); break;
            case 6: viewProductsByCategory(lab_db); break;
            case 7: calculateTotalRevenue(lab_db); break;
            case 8: showTop5Products(lab_db); break;
            case 9: showRevenueByProduct(lab_db); break;
            case 10: showSoldUnitsByProduct(lab_db); break;
            case 11: Category::displayAll(&lab_db); break;
            case 12:
                std::cout << "Exiting program..." << std::endl;
                logger.log("========== PROGRAM FINISHED ==========");
                break;
            default: std::cout << "Invalid option!" << std::endl;
            }

        } while (choice != 12);

    }
    catch (const std::exception& e) {
        std::cerr << "FATAL ERROR: " << e.what() << std::endl;
        std::cout << "Press Enter to exit...";
        std::cin.ignore();
        std::cin.get();
        return 1;
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();
    return 0;
}

// 402 - Работа меню
// До 402 - все связь postgre и sql и добавление базовых классов
// Тело процесса - 690