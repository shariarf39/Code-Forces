#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Member
{
private:
    string name;
    int age;
    int roomNumber;
    int id;
    double payment;
    double totalBlance;
    double totalBlance=0.0;
public:
    
    Member(string n,int ag,int rNum,int mId,double payment=0.0, double tp):name(n),age(ag),roomNumber(rNum),id(mId),payment(payment), totalBlance(tp) {};

    void display() const
    {

        cout << "Member ID: " << id << "\n Name: " << name << "\n Age: " << age
             << "\n Room Number: " << roomNumber<< endl;
    }

        void displayTotal() const
    {

        cout << "Member ID: " << id << "\n Name: " << name << "\n Age: " << age
             << "\n Room Number: " << roomNumber <<endl <<"Blance: " << payment<< endl<<endl<<endl;

       totalBlance+=payment;

      cout<< "Toal Blance: " << totalBlance <<endl;
    }





    int getId()
    {
        return id;

    }

    void setPayment(double s)
    {

        payment=s;
    }
    double getPayment() const
    {
        return payment;

    }


};


void addMember( std::vector<Member>& members)
{




    int age,roomNumber,id;
    string name;
    cout<<"Enter The name:"<<endl;
    cin.ignore();                                  // Clear input buffer
    getline(cin, name);
    cout<<"Enter The age"<<endl;
    cin>>age;
    cout<<"Enter The roomNumber"<<endl;
    cin>>roomNumber;
    cout<<"Enter the Member ID"<<endl;
    cin>>id;

    members.push_back(Member(name, age, roomNumber, id));
    cout << "Member added successfully!\n";


}

void addMember_Payment(std::vector<Member>& members)
{

    if (members.empty())
    {
        cout << "No members found!\n";
    }

    else
    {

        int searchId;
        double newPayment;
        cout<<"Enter The member ID:"<<endl;
        cin>>searchId;
        int count=0;
        for(auto& member: members)
        {
            if(member.getId()==searchId)
            {
                cout<<"Enter Your Payment\n";
                cin>>newPayment;
                member.setPayment(newPayment);
                count=1;
                cout<<"Your payment Has Been Added Successfully\n";
                break;


            }
        }
        if(count=0)
            cout<<"The ID with"<<searchId<<"don;t found\n";






    }



}
void displayTotal(std::vector<Member>& members)
{

    if (members.empty())
    {
        cout << "No members found!\n";
    }
    else
    {
        cout<<"There are"<<members.size()<<" Member in this Hostel\n";
        cout<<"Here are the list of members\n";
        for (const auto& member : members)
        {
            member.displayTotal();
        }
    }
}




void displayPerperson(std::vector<Member>& members)
{

    if (members.empty())
    {
        cout << "No members found!\n";
    }

    else
    {

        int searchId;
        double newPayment;
        cout<<"Enter The member ID:"<<endl;
        cin>>searchId;
        for(auto& member: members)
        {
            if(member.getId()==searchId)
            {
                member.display();


            }

        }

    }

}

void displayPement(std::vector<Member>& members)
{
    if (members.empty())
    {
        cout << "No members found!\n";
    }
    else
    {
        int searchId;
        cout << "Enter The member ID:" << endl;
        cin >> searchId;
        for (auto& member : members)
        {
            if (member.getId() == searchId)
            {
                cout << "Payment: " << member.getPayment() << " Tk" << endl; // Assuming setPayment returns the payment value
                return; // Exit the function after finding the member
            }
        }
        cout << "The ID " << searchId << " was not found.\n";
    }
}












int main()
{
    vector<Member> members;


    while(1)
    {

        cout<<"-------WELCOME TO BHAIBROTHER HOME----------\n";
        int choice;

        cout<<"1.Add Member\n";
        cout<<"2.Add member payment\n";
        cout<<"3.See All Member Details\n";
        cout<<"4.Display Member Details(per person)\n";
        cout<<"5.See per member payment\n";

        cout<<"6.Exit\n:";
        cout<<"7.See All member Details\n";
        cout<<"Enter Your Choice Please:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            addMember(members);
            break;


        case 2:
            addMember_Payment(members);
            break;
        case 3:
            displayTotal(members);
            break;
        case 4:
            displayPerperson(members);
            break;
        case 5:
            displayPement(members);
            break;
        case 6:
            cout<<"Thanks For Using this code.written by Chayon \n";
            return 0;
        case 7:
           displayAllperson();
        default:
            cout<<"You have enter a wrong key\n";

        }
    }
}
