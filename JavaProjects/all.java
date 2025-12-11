class Product {
    private String name;
    private double price;

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public String toString() {
        return name + " --- " + price + " руб.";
    }
}

class Cart {
    private Product[] products;
    private int count;

    public Cart() {
        products = new Product[10];
        count = 0;
    }

    public void addProduct(Product p) {
        if (count >= products.length) {
            Product[] newProducts = new Product[products.length * 2];
            for (int i = 0; i < products.length; i++) {
                newProducts[i] = products[i];
            }
            products = newProducts;
        }
        products[count] = p;
        count++;
    }

    public void removeProduct(String name) {
        for (int i = 0; i < count; i++) {
            if (products[i].getName().equalsIgnoreCase(name)) {
                for (int j = i; j < count - 1; j++) {
                    products[j] = products[j + 1];
                }
                products[count - 1] = null;
                count--;
                break;
            }
        }
    }

    public double getTotal() {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += products[i].getPrice();
        }
        return total;
    }

    public void printCart() {
        System.out.println("=== Корзина ===");
        for (int i = 0; i < count; i++) {
            System.out.println((i + 1) + ". " + products[i]);
        }
        System.out.println("Итого: " + getTotal() + " руб.\n");
    }
}

public class Main {
    public static void main(String[] args) {
        Product laptop = new Product("Ноутбук", 75000.0);
        Product mouse = new Product("Мышка", 1500.0);
        Product keyboard = new Product("Клавиатура", 3000.0);

        Cart cart = new Cart();

        cart.addProduct(laptop);
        cart.addProduct(mouse);
        cart.addProduct(keyboard);

        cart.printCart();

        System.out.println("Удаляем: Мышка");
        cart.removeProduct("Мышка");

        cart.printCart();
    }
}