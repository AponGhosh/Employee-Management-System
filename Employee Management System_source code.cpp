#include <iostream>     //specific & necessary header files
#include <iomanip>
#include <fstream>
using namespace std;

class Employee             //Employee class definition
{
   //class attributes
  private:
    long int empID;     //employee id
    string empName;     //employee name
    int empAge;         //employee age
    string empGender;   //employee gender
    string empDOB;      //employee date of birth
    string empPhoneNo;  //employee phone number
    string empPost;     //employee designation
    double empSalary;   //employee salary
    Employee *next=NULL;//self referential structure/pointer
    Employee *head=NULL;//declare an Employee based pointer to maintain the linked list

  public:
    //class functions
    void addToList(long int id, string name, int age, string gender, string dob, string phoneNo, string post, double salary)//insertion to the linked list
    {
      Employee *newEmp=new Employee;        //Dynamically memory allocation for create a new node
      newEmp->empID=id;                     //Assigning the value to specific class attribute
      newEmp->empName=name;
      newEmp->empAge=age;
      newEmp->empGender=gender;
      newEmp->empDOB=dob;
      newEmp->empPhoneNo=phoneNo;
      newEmp->empPost=post;
      newEmp->empSalary=salary;
      newEmp->next=NULL;
      if (head==NULL)               //if the list is empty
      {
        head=newEmp;                //Create a linked list's first node
      }
      else
      {
        Employee *temp=head;
        while (temp->next!=NULL)     //Traverse to the last node of the linked list
        {
          temp=temp->next;
        }
        temp->next=newEmp;          //insert node at the end
      }
      showList();       //committing the insertion to file
    }
    void deleteFromList(long int id)    //deletion from the linked list
    {
      Employee* temp=head;
      Employee*temp2=NULL;
      if (temp!=NULL)       //Check if the list is not empty
      {
        while ((temp->next!=NULL)&&(temp->empID!=id))   //Traverse the list for the given id to be deleted
        {
          temp2=temp;              //keep tracking the previous node of the list
          temp=temp->next;
        }
        if (temp->empID==id)        //Check if the deleted id is found
        {
          if ((temp==head)&&(temp->next==NULL))     //Check if only one node in the list
          {
            delete temp;       //Free allocated memory
            delete temp2;
            head=NULL;         //Assign NULL to head pointer
            showList();        //committing the deletion to file
          }
          else if (temp==head)      //Check if id is found at first of the list
          {
            delete temp;        //Free allocated memory
            delete temp2;
            head=head->next;    //Change the head to forward node
            showList();         //committing the deletion to file
          }
          else if(temp->next==NULL)      //Check if id is found at end of the list
          {
            temp2->next=NULL;   //Assign NULL to the previous node
            delete temp;        //Free allocated memory
            showList();         //committing the deletion to file
          }
          else        //if is found at middle of the list
          {
            temp2->next=temp->next;     //Assigning forward node link to previous node
            delete temp;                //Free allocated memory
            showList();                 //committing the deletion to file
          }
          cout<<"\n\n\n\n\n\n\t\t\tEntered employee ID's information is successfully deleted";
        }
        else   //if id is not found in the list
        {
          cout<<"\n\n\n\n\n\n\t\t\tGiven ID is not matched.\n\t\t\tDeletion is not possible."<<endl;
        }
      }

      else      //if the list is empty
      {
        cout<<"\n\n\n\n\n\n\t\t\tThe list is empty. \n\t\t\tNo deletion is possible"<<endl;
      }
    }

    void searchFromList(long int id)    //search employee info from the linked list
    {
      Employee *temp=head;
      while ((temp!=NULL)&&(temp->empID!=id)) //Traverse the list for the given id to be searched
      {
        temp=temp->next;
      }
      if ((temp!=NULL)&&temp->empID==id)
      {
        cout<<"\n\n\n\n\t\t\tName: "<<temp->empName<<endl
            <<"\t\t\tAge: "<<temp->empAge<<endl
            <<"\t\t\tGender: "<<temp->empGender<<endl
            <<"\t\t\tDate of Birth: "<<temp->empDOB<<endl
            <<"\t\t\tPhone Number: "<<temp->empPhoneNo<<endl
            <<"\t\t\tDesignation: "<<temp->empPost<<endl
            <<"\t\t\tSalary: "<<fixed<<setprecision(2)<<temp->empSalary<<endl<<endl;
      }
      else
      {
        cout<<"\n\n\n\n\n\t\t\tGiven ID is not matched in the list"<<endl;
      }
    }

    void update(long int id)//updating already existing information for a given id in the list
    {
      Employee *temp=head;
      while ((temp->next!=NULL)&&(temp->empID!=id))     //Traverse the list for the given id to be searched
      {
        temp=temp->next;
      }
      if(temp->empID==id)       //if given id is found
      {
        string name, gender, dob, number, post;
        int age;
        double salary;
        cout<<"\n\n\n\t\t\tUpdate name: ";      //Input update employee informations from user
        cin>>name;
        temp->empName=name;              //Overriding new information to the previous list
        cout<<"\t\t\tUpdate age: ";
        cin>>age;
        temp->empAge=age;
        cout<<"\t\t\tUpdate gender: ";
        cin>>gender;
        temp->empGender=gender;
        cout<<"\t\t\tUpdate date of birth: ";
        cin>>dob;
        temp->empDOB=dob;
        cout<<"\t\t\tUpdate phone number: ";
        cin>>number;
        temp->empPhoneNo=number;
        cout<<"\t\t\tUpdate designation: ";
        cin>>post;
        temp->empPost=post;
        cout<<"\t\t\tUpdate salary: ";
        cin>>salary;
        temp->empSalary=salary;
        showList();     //committing the update to file
        cout<<"\n\n\t\t\tPrevious employee information is successfully updated";
      }

      else      //if given id is not found in the list
      {
        cout<<"\n\n\n\n\n\n\t\t\tGiven ID is not matched.\n\t\t\tUpdate is not possible."<<endl;
      }
    }
    void showList()     //commits linked list to file
    {
      if(head==NULL)       //Check if the list is empty
      {
        cout<<"\n\n\n\n\n\n\t\t\tThere is no employee information in this list"<<endl;
      }
      else          //if the list is not empty
      {
        Employee *temp=head;
        ofstream outFile;
        string line;
        outFile.open ("rawdata.txt",ios::trunc);//opening in trunc mode so that everything in file is refreshed everytime this is called
        streambuf *coutbuf = cout.rdbuf();      //save old buffer
        cout.rdbuf (outFile.rdbuf());         //redirect std::cout to rawdata.txt
        do
        {
          cout<<temp->empID<<" "<<temp->empName<<" "<<temp->empAge<<" "<<temp->empGender<<" "
            <<temp->empDOB<<" "<<temp->empPhoneNo<<" "<<temp->empPost<<" "<<fixed<<setprecision(2)<<temp->empSalary<<endl;
          temp=temp->next;
        }while(temp!=NULL);

        cout.rdbuf (coutbuf);   //reset to standard console output again
                                //this method writes to file of fileName the account details;
        outFile.close();        //close the opened file
        outFile.open ("log.txt",ios::trunc);//opening in trunc mode so that everything in file is refreshed everytime this is called
        coutbuf = cout.rdbuf();             //save old buffer
        cout.rdbuf(outFile.rdbuf());        //redirect std::cout to log.txt
        temp=head;
        do
        {
          cout<<"ID: "<<temp->empID<<endl<<"Name: "<<temp->empName<<endl<<"Age: "<<temp->empAge<<endl<<"Gender: "<<temp->empGender<<endl<<"Date of Birth: "
            <<temp->empDOB<<endl<<"Phone Number: "<<temp->empPhoneNo<<endl<<"Designation: "<<temp->empPost<<endl<<"Salary: "<<fixed<<setprecision(2)<<temp->empSalary<<endl<<endl;
          temp=temp->next;
        }while(temp!=NULL);
        cout.rdbuf (coutbuf); //reset to standard console output again
        outFile.close();        //close opened file
      }
    }
    void display()//displays from file log.txt
    {
      ifstream inFile;
      inFile.open("log.txt",ios::in);   //File opening using ifstream's object
      string line;
      if (inFile.is_open())     //Condition check for the file opening
      {
        while (getline(inFile, line)) //copy all the information from file
        {
          cout<<"\t\t"<<line<<endl;     //show all information from file
        }
        inFile.close();         //close the opened file
      }
      else  // if file is not opened
      {
        cout <<"\n\n\n\n\n\t\t\tError opening file"<<endl;
      }
    }
    void sortList()//sorts the linked list by ID.
    //Time Complexity O(n^3)
    //Could easily make another sort function based on Name or salary as well
    {
      Employee *temp=head; //this one is the pointer being compared then sorted with reference to temp2
      Employee *temp2;//this one is the pointer which acts as reference for temp for the sorting process
      long int id;
      string name, gender, dob, post, number;
      int age;
      double salary;
      if (temp==NULL)   //Check if the linked list is empty
        cout<<"\n\n\n\n\n\n\t\t\tThe list is empty. \n\t\t\tNo sorting is possible"<<endl;
      else           //if the list is not empty
      {
        while (temp!=NULL)      //Traverse the linked list
        {
          temp2=temp->next;
          while (temp2!=NULL)   //Traverse the list again except previous one
          {
            if (temp->empID>temp2->empID)   //Comparing two node's ID & swap all attributes
            {
              id=temp->empID;
              name =temp->empName;
              age =temp->empAge;
              gender=temp->empGender;
              dob =temp->empDOB;
              number =temp->empPhoneNo;
              post =temp->empPost;
              salary =temp->empSalary;
              temp->empID =temp2->empID;
              temp->empName =temp2->empName;
              temp->empAge =temp2->empAge;
              temp->empGender=temp2->empGender;
              temp->empDOB =temp2->empDOB;
              temp->empPhoneNo =temp2->empPhoneNo;
              temp->empPost =temp2->empPost;
              temp->empSalary =temp2->empSalary;
              temp2->empID =id;
              temp2->empName =name;
              temp2->empAge =age;
              temp2->empGender=gender;
              temp2->empDOB =dob;
              temp2->empPhoneNo =number;
              temp2->empPost =post;
              temp2->empSalary =salary;
            }
            temp2=temp2->next;
          }
          temp=temp->next;
        }
      }
      showList();           //commits to file
      cout<<"\n\n\n\n\n\n\t\t\tThe list is sorted successfully"<<endl;
    }
    friend void constructList(Employee *head);      //friending necessary, accessing private variables of Employee
};      //end of Employee class


void constructList(Employee *head)//constructs the list from file every time the program is run and file is not empty
{
  ifstream inFile;
  long int id;
  int age;
  double salary;
  string name, gender, dob, number, post, line;
  inFile.open ("rawdata.txt", ios::in);        //opening file
  if (inFile.is_open())         //Condition check for the file opening
  {
    while (inFile >> id >> name >> age >> gender >> dob>>number>>post>>salary) //read all the information from file
    {
      //inFile >> id >> name >> age >> gender >> dob>>number>>post>>salary;
      head->addToList(id, name, age, gender, dob, number, post, salary);  //creating new list from file
    }
    inFile.close();     //close the file
  }
  else  //if file is not opened
  {
  cout << "\n\n\n\n\n\n\t\t\tError opening file!!!"<<endl;
  }

}

bool isEmpty(ifstream& inFile)//checks if the file is empty or not. failure to open results in true as well
{
    return inFile.peek() == ifstream::traits_type::eof();
}
int main()
{
    Employee*head=new Employee;//instance of the linked list
    int n;
    long int id;
    int age;
    double salary;
    string name, gender, dob, number, post;
    ifstream inFile;
    inFile.open("rawdata.txt");    //open a file
    if (!isEmpty(inFile))//Check if the file isn't empty
    {
      constructList(head);//construct the list from data in the file
    }
    inFile.close();     //close the opened file

    while(true)
    {
        system("cls");
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t    |  **********  MAIN MENU   **********  |  \n";
        cout<<"\t\t\t    |      EMPLOYEE MANAGEMENT SYSTEM      |  \n";
        cout<<"\t\t\t    |======================================|  \n";
        cout<<"\n\t--------------------------------------------------------------------------------\n";
      	cout<<"\n\n\t\t1. Add employee information\n\n";
        cout<<"\t\t2. Delete employee information\n\n";
        cout<<"\t\t3. Update employee information\n\n";
        cout<<"\t\t4. Search employee information\n\n ";
        cout<<"\t\t5. Sort employee information\n\n";
        cout<<"\t\t6. Display employee information from file\n\n";
        cout<<"\t\t0. Exit\n\n";
        cout<<"\n\t================================================================================\n";
        cout<<"\n\n\t\tPlease Enter Your Choice : ";
        cin>>n;
        switch (n)
        {
        case 1:
            system("cls");
            system("color 0E");
            cout<<"\n\n\n\n\n\n\t\t\tInput ID: ";
            cin>>id;
            cout<<"\t\t\tInput name: ";
            cin>>name;
            cout<<"\t\t\tInput age: ";
            cin>>age;
            cout<<"\t\t\tInput gender: ";
            cin>>gender;
            cout<<"\t\t\tInput date of birth: ";
            cin>>dob;
            cout<<"\t\t\tInput Phone number: ";
            cin>>number;
            cout<<"\t\t\tInput Designation: ";
            cin>>post;
            cout<<"\t\t\tInput Salary: ";
            cin>>salary;
            head->addToList(id, name,age, gender, dob, number, post, salary);
            cout<<"\n\n\t\t\tNew employee information is successfully added";
            cout<<"\n\n\n\t\t\t";
            system("pause");
            break;
        case 2:
            system("cls");
            system("color FC");
            cout<<"\n\n\n\n\n\n\t\t\tInput ID: ";
            cin>>id;
            head->deleteFromList(id);
            cout<<"\n\n\n\t\t\t";
            system("pause");
            break;
        case 3:
            system("cls");
            system("color 0A");
            cout<<"\n\n\n\n\n\n\t\t\tInput ID: ";
            cin>>id;
            head->update(id);
            cout<<"\n\n\n\t\t\t";
            system("pause");
            break;
        case 4:
            system("cls");
            system("color F0");
            cout<<"\n\n\n\n\n\n\t\t\tInput ID: ";
            cin>>id;
            head->searchFromList(id);
            cout<<"\n\n\n\t\t\t";
            system("pause");
            break;
        case 5:
            system("cls");
            system("color B0");
            head->sortList();
            cout<<"\n\n\n\t\t\t";
            system("pause");
            break;
        case 6:
            system("cls");
            system("color 0D");
            head->display();
            cout<<"\n\n\n\t\t\t";
            system("pause");
            break;
        case 0:
            system("color 3E");
            return 0;
            break;
        default:
            system("cls");
            system("color 71");
            cout<<"\n\n\n\n\n\n\t\t\tInvalid choice!!!\n\n\t\t\tPlease enter correct option ";
            cout<<"\n\n\n\t\t\t";
            system("pause");
        }
    }

    return 0;
}
//having a employee management database implemented using linked list has a lot of drawbacks
//computationally very expensive, all in terms of constructing the list, accessing/traversing, sorting, outputting to file, reading from file, any operations on the list (or the employee database in other words) etc
//only benefit being it only uses memory that it needs and nothing more
//just representing the linked list with information on the employees to file, then using that file going forward to generate a linked list every time the program is run and to do any sort of operations on it, was the only way to make a linked list based employee management system work
//O(n) for almost any of the operations possible are large, inefficient and wasteful, and in practical real world scenarios, would be better served being implemented with almost any other type of data structure, for example dynamic arrays would have far better average and best case performance, and equal or better worst case performance compared to this.
//representing a linked list to a human readable file defeats the purpose of both
//the output files are overwritten every time with the new list generated when any of the operations that alter the list (add, delete, sort, update) are performed

