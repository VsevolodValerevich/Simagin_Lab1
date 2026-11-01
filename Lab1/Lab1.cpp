#include <iostream>
#include <string>
#include <limits>
#include <fstream>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            clearInput();
            return value;
        } else {
            std::cout << "Error. Enter a number.\n";
            clearInput();
        }
    }
}

double getDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            clearInput();
            return value;
        } else {
            std::cout << "Error. Enter a number.\n";
            clearInput();
        }
    }
}

std::string getString(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

class Pipe {
private:
    std::string name;
    double length;
    double diameter;
    bool inRepair;
    bool is_created;
    
public:
    Pipe() : length(0.0), diameter(0.0), inRepair(false), is_created(false) {}

    void add(){
        std::cout << "Pipe adding\n";
        name = getString("Enter Pipe name\n");
        length = getDouble("Enter Pipe length\n");
        diameter = getDouble("Enter Pipe diameter\n");
        int repair_choice = getInt("Is Pipe under repair? \n (1 - Yes, 0 - No) \n");
        inRepair = (repair_choice == 1);
        is_created = true;
        std::cout << "Pipe added succesfully\n";
    }

    void print() const {
        if (!is_created){
            std::cout << "Pipe isn't created yet\n";
            return;
        }
        std::cout << "Pipe: " << name
            << " length: " << length << " km"
            << " Diameter: " << diameter << " mm"
            << " In repair: " << (inRepair ? "Yes" : "No") << "\n";
    }

    void toggleRepair() {
        if (!is_created){
            std::cout << "Add pipe firstly\n";
            return;
        }
        inRepair = !inRepair;
        std::cout << "Pipe Status 've been changed.\n Status: " << (inRepair ? "not" : "") << "working\n";
        
    }

    bool getCreatedStatus() const {return is_created; }
    string getName() const {return name;}
    double getLength() const {return length;}
    double getDiameter() const {return diameter;}
    bool getRepairStatus() const {return inRepair;}

    void setData(std::string n, double l, double d, bool r){
        name = n; length = l; diameter = d; inRepair = r; is_created = true;
    }
};
class CSt {
private:
    std::string name;
    int amount_total;
    int amount_active;
    std::string st_class;
    bool is_created;
public:
    CSt() : amount_total(0), amount_active(0), is_created(false) {}

    void add(){
        std::cout << "CompStation adding\n";
        name = getString("Enter CS name:\n");
        amount_total = getInt("Enter Workshops total amount:\n");
        amount_active = getInt("Enter active WS amount:\n");
        if ((amount_active > amount_total) || (0 > amount_active)) {
            while ((amount_active > amount_total) || (0 > amount_active)) {
                std::cout << "Active WS amount can not be bigger than total amount or negative";
                amount_active = getInt("Enter active WS amount:\n");
            }
        }
        st_class = getString("Enter CS class:\n");
        is_created = true;
        std::cout << "CS created successfully";
    }
    void print() const {
        if (!is_created){
            std::cout << "CS isn't created yet\n";
            return;
        }
        std::cout << "CS: " << name
            << " Total amount: " << amount_total
            << " Active amount: " << amount_active
            << " Class: " << st_class;
    }

    void editWS() {
        if (!is_created){
            std::cout << "CS isn't created yet\n";
            return;
        }
        std::cout << "\nWorkshops Editing\n"
            << "Total Workshops: " << amount_total << ", Active Workshops: " << amount_active << '\n'
            << "Choose the action:\n1.Activate Workshop\n2.Diactivate Workshop";
        int action = getInt("Enter action: ");
        if (action == 1){
            if (amount_active == amount_total){
                std::cout << "Can't Activate Workshop, all workshops are active now";
            }
            else{
                amount_active ++;
                std::cout << "Workshop has been activated. Total workshops: "
                    << amount_total << ", Active workshops: " << amount_active << "\n";
            }
        }
        else if action == 2{
            if (amout_active == 0){
                std::cout << "Can't Deactivate Workshop, all workshops are dectivated now";
            }
            else{
                amount_active --;
                std::cout << "Workshop has been deactivated. Total workshops: "
                    << amount_total << ", Active workshops: " << amount_active << "\n";
            }
        }
        else {
            std::cout << "Invalid action.";
        }
    }
        
     bool getCreatedStatus() const { return is_created; }
        std::string getName() const { return name; }
        int getAmountTotal() const { return amount_total; }
        int getAmountActive() const { return amount_active; }
        std::string getStClass() const { return st_class; }

        void setData(std::string n, int total, int active, std::string c) {
            name = n; amount_total = total; amount_active = active; st_class = c; is_created = true;
        }
    };
void saveToFile(const Pipe& pipe, const CSt& cs, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error opening file!\n";
        return;
    }

    file << pipe.getCreatedStatus() << "\n";
    if (pipe.getCreatedStatus()) {
        file << pipe.getName() << "\n" << pipe.getLength() << "\n" << pipe.getDiameter() << "\n" << pipe.getRepairStatus() << "\n";
    }

    file << cs.getCreatedStatus() << "\n";
    if (cs.getCreatedStatus()) {
        file << cs.getName() << "\n" << cs.getAmountTotal() << "\n" << cs.getAmountActive() << "\n" << cs.getStClass() << "\n";
    }

    file.close();
    std::cout << "Data saved to " << filename << "\n";
}

void loadFromFile(Pipe& pipe, CSt& cs, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: File not found!\n";
        return;
    }

    bool pipe_created;
    file >> pipe_created;
    if (pipe_created) {
        std::string n; double l, d; bool r;
        file.ignore();
        std::getline(file, n);
        file >> l >> d >> r;
        pipe.setData(n, l, d, r);
    }

    bool cs_created;
    file >> cs_created;
    if (cs_created) {
        std::string n, c; int total, active;
        file.ignore();
        std::getline(file, n);
        file >> total >> active;
        file.ignore();
        std::getline(file, c);
        cs.setData(n, total, active, c);
    }

    file.close();
    std::cout << "Data loaded from " << filename << "\n";
}

void printMenu() {
    std::cout << "\n==============================\n";
    std::cout << "1. Add Pipe\n";
    std::cout << "2. Add CS\n";
    std::cout << "3. Print all objects\n";
    std::cout << "4. Edit Pipe (toggle repair)\n";
    std::cout << "5. Edit CS (activate/deactivate WS)\n";
    std::cout << "6. Save to file\n";
    std::cout << "7. Load from file\n";
    std::cout << "0. Exit\n";
    std::cout << "==============================\n";
}

int main() {
    Pipe mainPipe;
    CSt mainCS;
    std::string filename = "data.txt";
    int choice;

    while (true) {
        printMenu();
        choice = getInt("Choose an action: ");

        switch (choice) {
            case 1: mainPipe.add(); break;
            case 2: mainCS.add(); break;
            case 3: 
                mainPipe.print(); 
                mainCS.print(); 
                break;
            case 4: mainPipe.toggleRepair(); break;
            case 5: mainCS.editWS(); break;
            case 6: saveToFile(mainPipe, mainCS, filename); break;
            case 7: loadFromFile(mainPipe, mainCS, filename); break;
            case 0: 
                std::cout << "Exiting program.\n"; 
                return 0;
            default: 
                std::cout << "Invalid menu choice.\n"; 
                break;
        }
    }
    return 0;
}
