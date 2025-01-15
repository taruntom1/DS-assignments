#include <iostream>
#include <string>

class Employee
{
private:
    std::string name;
    std::string id_number;
    double salary;
    int total_leaves;
    int remaining_leaves;

public:
    Employee(const std::string &name, const std::string &id_number, double salary, int total_leaves)
        : name(name), id_number(id_number), salary(salary), total_leaves(total_leaves), remaining_leaves(total_leaves) {}

    void apply_leave(int leave_days)
    {
        if (leave_days <= remaining_leaves)
        {
            remaining_leaves -= leave_days;
            std::cout << leave_days << " days of leave approved for " << name << ". Remaining leaves: " << remaining_leaves << std::endl;
        }
        else
        {
            std::cout << "Leave request denied for " << name << ". Not enough leave balance." << std::endl;
        }
    }

    void annual_increment(double increment_amount)
    {
        salary += increment_amount;
        std::cout << "Annual increment applied for " << name << ". New salary: " << salary << std::endl;
    }

    void display_info() const
    {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "ID Number: " << id_number << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Total Leaves: " << total_leaves << std::endl;
        std::cout << "Remaining Leaves: " << remaining_leaves << std::endl;
    }
};

int main()
{
    // Creating employee objects
    Employee emp1("John Doe", "E001", 50000, 20);
    Employee emp2("Jane Smith", "E002", 60000, 15);

    // Displaying initial employee information
    emp1.display_info();
    std::cout << "-" << std::endl;
    emp2.display_info();
    std::cout << std::string(20, '-') << std::endl;

    // Applying leaves
    emp1.apply_leave(5);
    emp2.apply_leave(16);
    std::cout << std::string(20, '-') << std::endl;

    // Displaying employee information after leave
    emp1.display_info();
    std::cout << "-" << std::endl;
    emp2.display_info();
    std::cout << std::string(20, '-') << std::endl;

    // Applying annual increment
    emp1.annual_increment(5000);
    emp2.annual_increment(4000);
    std::cout << std::string(20, '-') << std::endl;

    // Displaying final employee information
    emp1.display_info();
    std::cout << "-" << std::endl;
    emp2.display_info();

    return 0;
}
