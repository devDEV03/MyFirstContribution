#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class I_Printable{
    
    friend ostream &operator<<(ostream &,I_Printable &);
    public:
    virtual void print(ostream &os) = 0;
};
 ostream &operator<<(ostream &os,I_Printable &obj){
    obj.print(os);
    return os;
}
class Account : public I_Printable{
    protected:
    double balance;
    public:
    Account():balance{0}{
        cout<<"-----------------Welcome to Bareilly Bank--------------"<<endl;
    }
    Account(double x): balance{x}{
        cout<<"-----------------Welcome to Bareilly Bank--------------"<<endl;
    }
    virtual bool deposit(double amount){
        if(amount>0){
            balance= balance + amount;
            cout<<"----------------SUCCESFULLY DEPOSITED-------------------"<<endl;
            return true;
        }
        else{
            cout<<"------------------ERROR----------------------------"<<endl;
            return false;
        }
    };
    virtual bool withdraw(double cash){
         if(balance-cash>=0){
            balance-=cash;
            cout<<"-----------------SUCCESFULLY WITHDRAWN--------------------"<<endl;
            return true;
        }
        else{
            cout<<"----------------------ERROR-----------------------------"<<endl;
            return false;
        }
    };
    virtual void print(ostream &os) override
    {
        os<<"Hello,I am Account"<<endl;
    }
    virtual ~Account(){}

};
class Savings_Account : public Account{
    protected:
    double int_rate;
    public:
    Savings_Account():Account(1000),int_rate{0}{}
    Savings_Account(double balance,double x):Account(balance),int_rate{x}{}

    virtual bool deposit(double amount ) 
    {
        if(amount>0){
            balance= balance + amount*(int_rate/100) ;
            cout<<"----------------SUCCESFULLY DEPOSITED-------------------"<<endl;
            return true;
        }
        else{
            cout<<"------------------ERROR----------------------------"<<endl;
            return false;
        }
    }

    virtual bool withdraw(double cash){
     if(balance-cash>=0){
            balance-=cash;
            cout<<"-----------------SUCCESFULLY WITHDRAWN--------------------"<<endl;
            return true;
        }
        else{
            cout<<"----------------------ERROR-----------------------------"<<endl;
            return false;
        }
    }
      virtual void print(ostream &os){
        os<<"Hello,I am Savings Account"<<endl;
    }
    virtual ~Savings_Account(){}
};

class Checking_Account : public Savings_Account{
    protected:
    double flat_fee=1.50;
    string name_acc;
    public:
    Checking_Account(): Savings_Account(1000,5) ,name_acc{"UNKNOWN"}{}
    Checking_Account(double balance,double int_rate,string name_ofacc)
        :Savings_Account(balance,int_rate),name_acc{name_ofacc}{}
        virtual bool withdraw(double cash){
        if(balance-cash>=0){
            balance-=cash - flat_fee;
            cout<<"-----------------SUCCESFULLY WITHDRAWN--------------------"<<endl;
            return true;
        }
        else{
            cout<<"----------------------ERROR-----------------------------"<<endl;
            return false;
        }
    }
      virtual void print(ostream &os){
        os<<"Hello,I am Checking Account"<<endl;
    }
    
    virtual ~Checking_Account(){}
};

class Trust_Account : public Checking_Account{
    protected:
    int no_of_withdrawls=0;
    int max_withdrawls=3;
    public:
    Trust_Account() : Checking_Account(){}
    Trust_Account(double balance,double int_rate,string names): Checking_Account(balance,int_rate,names){}

    
    virtual bool deposit(double amount){
        if(amount>0){
            if(amount>500){
            balance= balance + amount*(int_rate/100) + 50 ;
            cout<<"----------------SUCCESFULLY DEPOSITED-------------------"<<endl;
            return true;
            }
            else{
                     balance= balance + amount*(int_rate/100) ;
            cout<<"----------------SUCCESFULLY DEPOSITED-------------------"<<endl;
            return true;
            }
        }
        else{
            cout<<"------------------ERROR----------------------------"<<endl;
            return false;
        }
    }

     virtual bool withdraw(double cash){
        if(no_of_withdrawls<max_withdrawls && cash>=(0.20*balance))
        if(balance-cash>=0){
            balance-=cash - flat_fee;
            cout<<"-----------------SUCCESFULLY WITHDRAWN--------------------"<<endl;
            no_of_withdrawls++;
            return true;
        }
        else{
            cout<<"----------------------ERROR-----------------------------"<<endl;
            return false;
        }
    }
      virtual void print(ostream &os){
        os<<"Hello,I am Trust Account"<<endl;
    }
    virtual ~Trust_Account(){}
};

void display(vector <Account *> acc){
    for(auto x : acc){
        cout << *x <<endl;
    }
}

void withdraw(vector <Account *> acc,double amount){
    for(auto x : acc){
        x->withdraw(3);
    }
}
void deposit(vector <Account *> acc,double amount){
    for(auto x : acc){
        x->withdraw(500);
    }
}




int main(){
    Account *p1 = new Savings_Account();
    Account *p2 = new Account();
    Account *p3 = new Trust_Account();

    vector<Account *> faps;
    faps.push_back(p1);
    faps.push_back(p2);
     faps.push_back(p3);
    for(auto x : faps){
        cout << *x <<endl;
    }
    
    display(faps);
    deposit(faps,1000);
    delete(p1);
    delete(p2);
    delete(p3);
    return 0;

}