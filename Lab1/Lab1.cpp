#include <iostream>
#include <string>

class Pipe(){
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
        cout << "Pipe added succesfully\n";
    }

    void print() const {
        if (!is_created){
            std::cout << "Pipe isn't created yet\n";
            return;
        }
        std::cout << "Pipe: " << name
            << " length: " << length << " km"
            << " Diameter: " << diameter << " mm"
            << " In repair: " << (inRepair ? "Yes" : "No") << "\n"
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
    double getLength() const {return lenth;}
    double getDiameter() const {return diameter;}
    bool getRepairStatus() const {return inRepair;}

    void setData(string n, double l, double d, bool r){
        name = n; length = l; diameter = d; inRepair = r; is_created = true;
    }
};
class CSt(){
private:
    std::string name;
    int amount_total;
    int amount_active;
    std::string st_class;
    bool is_created
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
        action = getInt();
        if action == 1{
            if (amout_active == amount_total){
                std::cout << "Can't Activate Workshop, all workshops are active now";
            }
            else{
                amount_active ++;
                std::cout << "Workshop has been activated. Total workshops: "
                    << amount_total << ", Active workshops: " << amount_active << "\n";
            }
        }
        if action == 2{
            if (amout_active == 0){
                std::cout << "Can't Deactivate Workshop, all workshops are dectivated now";
            }
            else{
                amount_active --;
                std::cout << "Workshop has been deactivated. Total workshops: "
                    << amount_total << ", Active workshops: " << amount_active << "\n";
            }
        }
        if (action != 1 && action != 2){
            std::cout << "Invalid action.";
        }
    }
        
    }


int main()
{
}
