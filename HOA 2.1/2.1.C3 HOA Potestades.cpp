#include <iostream>
#include <string>

class Produce {
protected:
    std::string name;
    double price;
    int quantity;
public:
    Produce(const std::string& n, double p, int q) : name(n), price(p), quantity(q) {}
    virtual ~Produce() {}
    double calculateSum() const {
        return price * quantity;
    }

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setName(const std::string& n) { name = n; }
    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }
};

class Fruit : public Produce {
public:
    Fruit(const std::string& n, double p, int q) : Produce(n, p, q) {}
    Fruit(const Fruit& other) : Produce(other) {}
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            Produce::operator=(other);
        }
        return *this;
    }
    ~Fruit() {}
};

class Vegetable : public Produce {
public:
    Vegetable(const std::string& n, double p, int q) : Produce(n, p, q) {}
    Vegetable(const Vegetable& other) : Produce(other) {}
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            Produce::operator=(other);

        }
        return *this;
    }
    ~Vegetable() {}
};

int main() {
    Fruit apple("Apple", 10, 7);
    Fruit banana("Banana", 10, 8);
    Vegetable broccoli("Broccoli", 60, 12);
    Vegetable lettuce("Lettuce", 50, 10);
    std::cout << "Apple cost: PHP " << apple.calculateSum() << " (Quantity: " << apple.getQuantity() << ")" << std::endl;
    std::cout << "Banana cost: PHP " << banana.calculateSum() << " (Quantity: " << banana.getQuantity() << ")" << std::endl;
    std::cout << "Broccoli cost: PHP " << broccoli.calculateSum() << " (Quantity: " << broccoli.getQuantity() << ")" << std::endl;
    std::cout << "Lettuce cost: PHP " << lettuce.calculateSum() << " (Quantity: " << lettuce.getQuantity() << ")" << std::endl;
    double totalSum = apple.calculateSum() + banana.calculateSum() + broccoli.calculateSum() + lettuce.calculateSum();
    std::cout << "Total cost: PHP " << totalSum << std::endl;
    return 0;
}
