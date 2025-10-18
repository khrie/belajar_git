#include <bits/stdc++.h>
using namespace std;

class staff{
    private:
    string password = "admin";

    public:

    bool s_login(string pass){
        if(pass == password){
            cout << "Login Successful" << endl;
            return true;
        }else{
            cout<<"Incorrect Password"<<endl;
            return false;
        }
    }

    void s_changepass(string oldpass, string newpass){
        if(oldpass == password){
            password = newpass;
        }else{
            cout<<"Incorrect Password"<<endl;
        }
    }

};

class product {
public:
    string brand;
    string name;
    int price;

    void show(){
        cout << name << " (" << brand << ") - Rp" << price << endl;
    }

    virtual string getType(){  
        return "Product"; 
    }; 
};

class food : public product {
public:
    string getType() override {
        return "Food"; 
    }
};

class beverage : public product {
public:
    string getType() override {
        return "Beverage"; 
    }
};

class tools : public product {
    public:
    string getType() override { 
        return "Tools"; 
    }
};


class cart_item{
    public:
    int category;
    int index;
    product item;

};

class customer{
    private:

    string name;
    string email;
    string password;
    int balance = 0;

    public:
    vector<cart_item> cart;

    void addtocart(int category, int index, product item){
        cart_item ci;
        ci.category = category;
        ci.index = index;
        ci.item = item;
        cart.push_back(ci);
    }

    void showcart(){
        cout << "Your cart: " << endl;
        if(cart.size() == 0){
            cout << "Empty" << endl;
        }else{
            for(int i=0; i<cart.size(); i++){
                cout << i+1 << ". ";
                cart[i].item.show();
            }
        }
    }

    bool checkout(){
        if(cart.empty()){
            cout << "Your cart is empty!" << endl;
            return false;
        }

        int total = 0;
        for(int i = 0; i < cart.size(); i++){
            total += cart[i].item.price;
        }

        cout << "Total amount: Rp" << total << endl;
        if(balance < total){
            cout << "Insufficient balance! Please add more money." << endl;
            return false;
        }else{
            balance -= total;
            cout << "Checkout successful! Remaining balance: Rp" << balance << endl;
            return true;
        }
    }


    void newacc(string n, string e, string p){
        name = n;
        email = e;
        password = p;
    }

    bool c_login(string e, string p){
        if(e == email){
            if(p == password){
                cout << endl << "Login Successful" << endl
                    << "Welcome " << name << " to Abinara Mart" << endl;
                return true;
            }else{
                cout << "Incorrect Password" << endl;
                return false;
            }
        }else{
            return false;
        }
    }


    void details(){
        cout << "Name: " << name << endl <<
            "Email: " << email << endl <<
            "Password: " << password << endl <<
            "Balance: " << balance << endl;
    }

    void addbalance(int amt){
        balance += amt;
    }

};


int main(){

    vector<customer> customers;
    vector<food> foodShelf;
    vector<beverage> beverageShelf;
    vector<tools> toolsShelf;
    staff s;

    while(true){
        cout << endl << "==============================" << endl <<
            "   Welcome to Abinara Mart   " << endl <<
            "==============================" << endl;

        cout << endl << "menu: " << endl <<
            "1. staff" << endl <<
            "2. customer" << endl <<
            "3. exit" << endl <<
            "> ";

        int choice;
        cin >> choice;

        if(choice == 1){

            cout << "Enter password: ";
            string pass;
            cin >> pass;
            if(s.s_login(pass)){
                while(true){
                    cout << endl << "staff menu: " << endl <<
                        "1. change password" << endl <<
                        "2. add product" << endl <<
                        "3. view products" << endl <<
                        "4. logout" << endl <<
                        "> ";
                    int c;
                    cin >> c;
                    if(c == 1){
                        string oldpass, newpass;
                        cout << "Enter old password: ";
                        cin >> oldpass;
                        cout << "Enter new password: ";
                        cin >> newpass;
                        s.s_changepass(oldpass, newpass);
                        cout << "Password changed successfully" << endl;

                    }else if(c == 2){
                        cout << endl << "Choose category: " << endl
                            << "1. Food" << endl
                            << "2. Beverage" << endl
                            << "3. Tools" << endl
                            << "> ";

                        int cat;
                        cin >> cat;

                        string name, brand;
                        int price;
                        cout << "Enter product name: ";
                        cin >> name;
                        cout << "Enter brand: ";
                        cin >> brand;
                        cout << "Enter price: ";
                        cin >> price;

                        if(cat == 1){
                            food f;
                            f.name = name;
                            f.brand = brand;
                            f.price = price;
                            foodShelf.push_back(f);
                        }else if(cat == 2){
                            beverage b;
                            b.name = name;
                            b.brand = brand;
                            b.price = price;
                            beverageShelf.push_back(b);
                        }else if(cat == 3){
                            tools t;
                            t.name = name;
                            t.brand = brand;
                            t.price = price;
                            toolsShelf.push_back(t);
                        }else{
                            cout << "Invalid category" << endl;
                            continue;
                        }
                        
                        cout << "Product added successfully!" << endl;

                    }else if(c == 3){
                        cout << endl << "=== Food Shelf ===" << endl;
                        if(foodShelf.size() == 0){
                            cout << "Empty" << endl;
                        }
                        for(int i=0; i<foodShelf.size(); i++){
                            cout << i+1 << ". ";
                            foodShelf[i].show();
                        }
                        cout << endl << "=== Beverage Shelf ===" << endl;
                        if(beverageShelf.size() == 0){
                            cout << "Empty" << endl;
                        }
                        for(int i=0; i<beverageShelf.size(); i++){
                            cout << i+1 << ". ";
                            beverageShelf[i].show();
                        }
                        cout << endl << "=== Tools Shelf ===" << endl;
                        if(toolsShelf.size() == 0){
                            cout << "Empty" << endl;
                        }
                        for(int i=0; i<toolsShelf.size(); i++){
                            cout << i+1 << ". ";
                            toolsShelf[i].show();
                        }
                    }else if(c == 4){
                        cout << "Logged out successfully" << endl;
                        break;
                    }else{
                        cout << "Invalid choice" << endl;
                        continue;
                    }
                }
            }

        }else if(choice == 2){

            cout << endl << "menu: " << endl <<
                "1. create account" << endl <<
                "2. login" << endl <<
                "> ";
            int c;
            cin >> c;

            if(c == 1){
                string n, e, p;
                cout << "Enter name: ";
                cin >> n;
                cout << "Enter email: ";
                cin >> e;
                cout << "Enter password: ";
                cin >> p;
                customer cust;
                cust.newacc(n, e, p);
                customers.push_back(cust);
                cout << "Account created successfully" << endl;

            }else if(c == 2){
                string e, p;
                cout << "Enter email: ";
                cin >> e;
                cout << "Enter password: ";
                cin >> p;
                bool found = false;
                int i;
                for(i = 0; i < customers.size(); i++){
                    if(customers[i].c_login(e, p)){ 
                        found = true;
                        break;
                    }
                } 

                if(!found){
                    cout << "No account found with this email" << endl;
                }else{
                    while(true){
                        cout << endl << "cutomer menu: " << endl <<
                            "1. logout" << endl <<
                            "2. show account details" << endl <<
                            "3. add balance" << endl <<
                            "4. add to cart" << endl <<
                            "5. view cart" << endl <<
                            "6. checkout" << endl <<
                            "> ";
                        int ch;
                        cin >> ch;
                        if(ch == 1){
                            cout << "Logged out successfully" << endl;
                            break;
                        }else if(ch == 2){
                            customers[i].details();
                        }else if(ch == 3){
                            int amt;
                            cout << "Enter amount to add: ";
                            cin >> amt;
                            customers[i].addbalance(amt);
                            cout << "Balance added successfully" << endl;
                        }else if(ch == 4){

                            cout << endl << "=== Food Shelf ===" << endl;
                            if(foodShelf.size() == 0){
                                cout << "Empty" << endl;
                            }
                            for(int i=0; i<foodShelf.size(); i++){
                                cout << i+1 << ". ";
                                foodShelf[i].show();
                            }
                            cout << endl << "=== Beverage Shelf ===" << endl;
                            if(beverageShelf.size() == 0){
                                cout << "Empty" << endl;
                            }
                            for(int i=0; i<beverageShelf.size(); i++){
                                cout << i+1 << ". ";
                                beverageShelf[i].show();
                            }
                            cout << endl << "=== Tools Shelf ===" << endl;
                            if(toolsShelf.size() == 0){
                                cout << "Empty" << endl;
                            }
                            for(int i=0; i<toolsShelf.size(); i++){
                                cout << i+1 << ". ";
                                toolsShelf[i].show();
                            }

                            cout << "Enter product type to add to cart (1. Food, 2. Beverage, 3. Tools): ";
                            int ptype;
                            cin >> ptype;
                            int pindex;
                            cout << "Enter product index: ";
                            cin >> pindex;
                            if(ptype == 1){
                                if(pindex < 1 || pindex > foodShelf.size()){
                                    cout << "Invalid product index" << endl;
                                }else{
                                    customers[i].addtocart(1, pindex - 1, foodShelf[pindex - 1]);
                                    cout << "Product added to cart successfully" << endl;
                                }
                            }else if(ptype == 2){
                                if(pindex < 1 || pindex > beverageShelf.size()){
                                    cout << "Invalid product index" << endl;
                                }else{
                                    customers[i].addtocart(2, pindex - 1, beverageShelf[pindex - 1]);
                                    cout << "Product added to cart successfully" << endl;
                                }
                            }else if(ptype == 3){
                                if(pindex < 1 || pindex > toolsShelf.size()){
                                    cout << "Invalid product index" << endl;
                                }else{
                                    customers[i].addtocart(3, pindex - 1, toolsShelf[pindex - 1]);
                                    cout << "Product added to cart successfully" << endl;
                                }
                            }
                        }else if(ch == 5){
                            customers[i].showcart();
                        }else if(ch == 6){
                            if(customers[i].checkout()){
                                for(int j = 0; j < customers[i].cart.size(); j++){
                                    int type = customers[i].cart[j].category;
                                    int index = customers[i].cart[j].index;
                                    if(type == 1 && index < foodShelf.size()){
                                        foodShelf.erase(foodShelf.begin() + index);
                                    } else if(type == 2 && index < beverageShelf.size()){
                                        beverageShelf.erase(beverageShelf.begin() + index);
                                    } else if(type == 3 && index < toolsShelf.size()){
                                        toolsShelf.erase(toolsShelf.begin() + index);
                                    }
                                }
                                customers[i].cart.clear();  
                            }

                        }else{
                            cout << "Invalid choice" << endl;
                        }
                    }
                }
            }

        }else if(choice == 3){
            cout << "Exiting" << endl;
            break;
        }else{
            cout << "Invalid choice" << endl;
        }

    }
        
}

