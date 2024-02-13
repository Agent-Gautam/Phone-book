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
        phone = name = email = "";
    };
    void display(){
        cout << name << '\n' << phone << '\n' << email <<'\n';
        cout << "-----------------------------------" << '\n';
    }
    void set(string n, string p, string e){
        name = n;
        phone = p;
        email = e;
        //check  : whether p has 10 or 12 elements < e has @ sign < name is atleast 2 char long
    }
    void add(contact &c){
        string cominput;
        cout << "Name: " ;
        cin >> cominput;
        c.name = cominput == "\n" ? c.name : cominput;              // susceptible for error
        cout << "Phone: ";
        cin >> c.phone;
        c.phone = cominput == "\n" ? c.phone : cominput;              // susceptible for error
        cout << "Ëmail: ";
        cin >> c.email;
        c.email = cominput == "\n" ? c.email : cominput;              // susceptible for error
        cout << "Contact created"; 
    }
};
class ContactList {
    vector<contact> allContacts;
    public:
    
    void createContact(){
        contact c;
        c.add(c);
        allContacts.push_back(c);
    }
    contact* search(){
        string param;
        bool found = false;
        cout << "search by name, phone or email" << '\n' << "=> ";
        cin >> param;
        contact* dummy;
        for(contact cont: allContacts){
            cout << "searching contact";
            if(cont.name == param or cont.email == param or cont.phone == param) {
                found = true;
                dummy = &cont;
                return dummy;
            }
        }
        if (!found){
            cout << "No such Contact exist" << '\n';
        }
        return nullptr;
    }
    void update(contact* c){
        cout << "enter the new values. Press Enter to retain old value " << '\n';
        c->add(*c);
    }
    void display(){
        for(auto c : allContacts){
            c.display();
        }
    }
};
int contact::count = -1;
int main() {
    cout << "Phone book" << '\n';
    cout << "Functions :" << '\n' <<
     "1. Add Contact" << '\n' << 
     "2. Update a contact" << '\n' <<
     "3. Delete a Contact" << '\n' << 
     "4. Search Contact" << '\n' <<
     "6. show list "
     "5. Exit" << '\n';
    int input;
    cin >> input;
    
    ContactList cl;
    switch (input) {
        case 1:
        int n;
        cout << "How many contact you want to make? ";
        cin >> n;
        for(int i = 0; i < n; i++) cl.createContact();
        main();
        case 2:
        cl.update(cl.search());
        main();
        case 5:
        return 0;
        case 6:
        cl.display();
    }
    return 0;
}