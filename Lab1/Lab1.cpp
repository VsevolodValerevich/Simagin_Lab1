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
        int trying = getInt("Enter active Workshops amount:\n");
        if (trying > amount_total) {
            while (trying > amount_total) {
                std::cout << "Active WS amount can not be bigger than total amount";
                trying = getInt("Enter active WS amount:\n");
            amount_active = trying;
            }
        }
        else{amount_active = trying}
        st_class = getString("Enter CS class:\n");
        is_created = true;
        std::cout << "CS created successfully";
    }
    void 
    
};



int main()
{
}
