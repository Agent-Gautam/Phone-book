#include <bits/stdc++.h>
using namespace std;

class contact {
    public:
    static int count;
    string phone;
    string name;
    string email;
    bool fav;
    contact(){
        count++;
        phone = "";
        name = "";
        email = "";
        fav = 0;
    };
    void display(){
        cout << name << '\n' << phone << '\n' << email <<'\n';
        cout << "-----------------------------------" << '\n';
    }

    //check  : whether p has 10 or 12 elements < e has @ sign < name is atleast 2 char long
    void add(){
        string cominput;
        cout << "Name: " ;
        cin >> cominput;
        if(cominput != "-") name = cominput;            // susceptible for error
        cout << "Phone: ";
        cin >> cominput;
        if(cominput != "-") phone = cominput;               // susceptible for error
        cout << "Email: ";
        cin >> cominput;
        if(cominput != "-") email = cominput;               // susceptible for error
        cout << "Contact updated" <<'\n'; 
    }
};
class ContactList {
    vector<contact> allContacts;
    public:
    
    void createContact(){
        contact c;
        c.add();
        allContacts.push_back(c);
    }
    int search(){
        string param;
        bool found = false;
        cout << "search by name, phone or email" << '\n' << "=> ";
        cin >> param;
        cout << "searching contact  ";
        for(int i = 0; i < allContacts.size(); i++){
            cout << "-";
            if(allContacts[i].name == param or allContacts[i].email == param or allContacts[i].phone == param) {
                cout << '\n';
                found = true;
                allContacts[i].display();
                return i;
            }
        }
        if (!found){
            cout << "\n!!No such Contact exist!!" << '\n';
        }
        return -1;
    }
    void update(int i){
        if(i == -1) return;
        cout << "enter the new values. Enter '-' to retain old value " << '\n';
        allContacts[i].display();
        allContacts[i].add();
    }
    void display(){
        for(auto c : allContacts){
            c.display();
        }
    }
    void del(int i){
        allContacts.erase(allContacts.begin() + i);
    }
};
int contact::count = 0;
void execution(ContactList &cl){
    cout << "Functions :" << '\n' <<
     "1. Add Contact" << '\n' << 
     "2. Update a contact" << '\n' <<
     "3. Delete a Contact" << '\n' << 
     "4. Search Contact" << '\n' <<
     "5. show list" << '\n' <<
     "6. Exit" << '\n' << "=> ";
    int input;
    
        cin >> input;
        // throw input;
        switch (input) {
        case 1:
            int n;
            cout << "How many contact you want to make? ";
            cin >> n;
            for(int i = 0; i < n; i++) cl.createContact();
            break;
        case 2:
            cl.update(cl.search());
            break;
        case 3:
            cl.del(cl.search());
            break;
        case 4:
            cl.search();
            break;
        case 5:
            cl.display();
            break;
        case 6:
            return;
        default:
            cout << "invalid argument";
        }
    
    execution(cl);
    return;
}
int main() {
    cout << "Phone book" << '\n';
    ContactList cl;
    execution(cl);
    // 3 guatam 5834959324 gautam@ gagan 752894394 gagan@ gothwal 48234925 gothwal@ 2
    return 0;
}