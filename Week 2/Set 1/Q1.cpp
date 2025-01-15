/*1.Create a computer   warehouse class   in which  three types of computer peripherals are stored ,for 
selling.
Write a main function which prints how many of each  peripheral is sold, what is the total  amount 
received by sales ,and  a message stating whether the month’s target is achieved or not .Note that 
every  month , many of these items are sold .Develop the code for such a system.*/

#include <iostream>
#include <string>

class Peripheral {
public:
    std::string name;
    double price;
    int sold;

    Peripheral(std::string n, double p) : name(n), price(p), sold(0) {}

    void sell(int quantity) {
        sold += quantity;
    }

    double totalSales() const {
        return sold * price;
    }
};

class Warehouse {
private:
    Peripheral keyboard;
    Peripheral mouse;
    Peripheral monitor;
    double salesTarget;

public:
    Warehouse(double target)
        : keyboard("Keyboard", 20.0),
          mouse("Mouse", 15.0),
          monitor("Monitor", 100.0),
          salesTarget(target) {}

    void sellPeripheral(const std::string& name, int quantity) {
        if (name == "Keyboard") {
            keyboard.sell(quantity);
        } else if (name == "Mouse") {
            mouse.sell(quantity);
        } else if (name == "Monitor") {
            monitor.sell(quantity);
        } else {
            std::cout << "Unknown peripheral: " << name << std::endl;
        }
    }

    void printSalesReport() const {
        double totalSales = keyboard.totalSales() + mouse.totalSales() + monitor.totalSales();

        std::cout << "Sales Report:" << std::endl;
        std::cout << "Keyboards sold: " << keyboard.sold << ", Total: $" << keyboard.totalSales() << std::endl;
        std::cout << "Mice sold: " << mouse.sold << ", Total: $" << mouse.totalSales() << std::endl;
        std::cout << "Monitors sold: " << monitor.sold << ", Total: $" << monitor.totalSales() << std::endl;
        std::cout << "Total Sales: $" << totalSales << std::endl;

        if (totalSales >= salesTarget) {
            std::cout << "Target achieved!" << std::endl;
        } else {
            std::cout << "Target not achieved." << std::endl;
        }
    }
};

int main() {
    // Set a sales target
    Warehouse warehouse(1000.0);

    // Simulate sales
    warehouse.sellPeripheral("Keyboard", 30);
    warehouse.sellPeripheral("Mouse", 50);
    warehouse.sellPeripheral("Monitor", 10);

    // Print the sales report
    warehouse.printSalesReport();
    int a;
    std::cin>>a;

    return 0;
}
