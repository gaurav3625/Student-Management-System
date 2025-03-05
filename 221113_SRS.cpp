#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
// FILE DATABASE
//Assumption :- while searching process use first letter capital and other small
class Hostel
{
private:
    int room_alloted;
    string floor;
    string hostel_fee;
    string hostel_file ;
    string diet;

public:
    Hostel()
    {
        hostel_file = "hostel_file.csv";

        floor = "Ground floor";
        hostel_fee = "Unpaid";
    }

    void addDetails(string name, int room, string floor,string diet, string hostel_fee)
    {
        ofstream file;

        file.open(hostel_file, ios ::app);

        file << name << "," << room << "," << floor << "," << diet << "," << hostel_fee << "\n";

        file.close();
    }

    void roomAllotment(string hostel_fee)
    {
        string name;
        cout << "Enter name :";
        cin >> name;
        messDetails();
        this->hostel_fee = hostel_fee;
        if (hostel_fee == "Paid")
        {
            cout << "Alloted room no : ";
            cin >> room_alloted;
            if (room_alloted > 200 && room_alloted <= 300)
            {
                floor = "1st floor";
            }
            else if (room_alloted > 300 && room_alloted <= 400)
            {
                floor = "2nd floor";
            }
            else{
                floor = " 3rd floor";
            }

            // Assume hostel building is having 3 floors
            cout << "Floor : " << floor << "\t";
            cout << "Hostel and Mess fee payment status : " << this->hostel_fee << "\n\n";

            addDetails(name, room_alloted, floor,diet, hostel_fee);
        }

    }

    void hostelDetails(string student_name)
    {
        ifstream input_file;

        input_file.open(hostel_file);
        if (!input_file.is_open())
        {
            cout << "Error: Unable to accsess the file database " << hostel_file << "\n";
            return;
        }
        string line;
        int found = 0;
        while (getline(input_file, line))
        {
            istringstream ss(line);
            string name, room, floor,diet, hostelfee;

            getline(ss, name, ',');
            getline(ss, room, ',');
            getline(ss, floor, ',');
            getline(ss, diet, ',');
            getline(ss, hostelfee, ',');

            if (name == student_name)
            {
                found = 1;
                cout << "Record found.\n";
                cout << "Details of " << name << ":\n";
                cout << "Room : " << room << "\n";
                cout << "Floor : " << floor << "\n";
                cout << "Diet : " << diet << "\n";
                cout << "Hostel  and Mess fee status: " << hostelfee<<"\n";
                break;
            }
        }
        if (!found)
        {
            cout << "Record not found\n";
        }
        input_file.close();
    }

    void messDetails()
    {
     cout << "Diet (Vegeteian / Non-Vegeterian) : ";
     cin >> diet;

    }
};

class TrackingFee
{
private:
    string fee_status;

public:
    void feeDetails(string category, string fee_status)
    {
        if (category == "GENERAL" || category == "OBC")
        {
            cout << "Total fees : 1,47000\n";
            fee(fee_status);
        }
        if (category == "SC" || category == "ST")
        {
            cout << "Total fees : 51000\n";
            fee(fee_status);
        }
    }
    void fee(string fee_status)
    {
        cout << "Fee status : " << fee_status << endl;
        if (fee_status == "Unpaid" || fee_status == "Not Paid")
        {
            cout << "Late Fee Penalty : Rs.1500" << endl;
        }
    }
};

class Admission 
{

private:
    string name; // i may use char * instead string in later submissions
    string category;

public:
    
    void addDetails(string file_name)
    {

        ofstream file; // function to check if data already exists
        string Name, roll,gender, branch, current_year,category, fee_status,state;
        file.open(file_name, ios ::app);
        cin.ignore();
        cout << "-------------------------Add details---------------------------------"<<endl;
        cout << "Name : ";
        getline(cin, Name);
        cout << "Roll Number : ";
        getline(cin, roll);
        cout << "Gender : ";
        getline(cin, gender);
        cout << "Department : ";
        getline(cin, branch);
        cout << "Year : ";
        getline(cin, current_year);
        cout << "Category : ";
        getline(cin, category);
        cout << "Fee Status : ";
        getline(cin, fee_status);
        cout << "State : ";
        getline(cin, state);
        file << Name << "," << roll << "," << gender << "," << branch << "," << current_year << "," << category << "," << fee_status <<","<<state<<endl;

        file.close();
    }
};
class CourseRegistration : public Admission
{
protected: // can use protected ??
    string course;
    int found;

public:

    void checkData(string course)
    {
        this->course = course;

        string filename = "";

        if (course == "b.tech" || course == "B.Tech")
        {
            filename = "btech_input.csv";
        }
        else if (course == "m.tech" || course == "M.Tech")
        {
            filename = "mtech_input.csv";
        }

        int ch;

        cout << "\n1. Search student information\t\t2. Add information of new student\t3. Exit \n ";
        cout << "Enter the choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            search(filename);
            break;
        case 2:
            search(filename);
            if (found == 0)
            {
                addDetails(filename);
            }
            break;
        case 3:
            break;
        }
    }

    void search(string filename)
    {
        string name;
        cin.ignore(); // to remove newline character
        cout << "Enter the name :";
        getline(cin,name);
        ifstream input_file;
        input_file.open(filename);
        if (!input_file.is_open())
        {
            cout << "Error: Unable to accsess the file database " << filename << "\n";
            return;
        }

        string search_name = name;
        found = 0;
        string line;

        TrackingFee f;
        while (getline(input_file, line))
        {
            istringstream ss(line);
            string name, roll, gender, branch, current_year, category, fee_status,state;

            getline(ss, name, ',');
            getline(ss, roll, ',');
            getline(ss, gender, ',');
            getline(ss, branch, ',');
            getline(ss, current_year, ',');
            getline(ss, category, ',');
            getline(ss, fee_status, ',');
            getline(ss, state, ',');

            if (name == search_name)
            {
                found = 1;
                cout << "-------------------------Record  found--------------------------\n";
                cout << "\n--------------------Details of " << name <<"-------------------" ":\n";
                cout << "Roll: " << roll << "\n";
                cout << "gender: " << gender << "\n";
                cout << "Department: " << branch << "\n";
                cout << "Year: " << current_year << "\n";
                cout << "Category: " << category << "\n";
                f.feeDetails(category, fee_status);
                cout << "State: " << state << "\n";
                break;
            }
        }

        if (!found)
        {
            cout << "---------------------------Record not found---------------------------\n";
        }
        input_file.close();
    }
};

class Result
{
private :
    int total_credits ; //  Assume total credits are 10 for current sem , 4 for math, 3-3 for remaining  
    float cgpa;
    float programming_points;
    float math_points;
    float english_points;

public:
   
    
    void calculateCgpa()//this is basic function which calculates cgpa according to grade(points)
    {
         total_credits = 10 ;
            
            cout << " \nEnter points gained(out of 10) : " << endl;
            cout << " Math : " ;
            cin >> math_points;
            cout << "Programming : " ;
            cin >> programming_points;
            cout << "English : " ;
            cin >> english_points;
            cgpa = (((math_points*4+programming_points*3+english_points*3)) / total_credits);
            cout << " \nCGPA : " << cgpa ;
            if( cgpa < 5){
                cout<<"\tFail";
            } 
            else{
                cout << "\tPassed";
                cout << "\n--------------------------------------------------------------------------";
            }
    }
};

class SRS
{
private:
    string course_name;

public:
    void userInput()
    {
        int mainChoice;

        cout << "1. Academics\t2. Hostel and Mess\t3. Exit" << endl;
        cout << "Choose option: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            academicsMenu();
            break;
        case 2:
            hostelMenu();
            break;
        case 3:
            cout<<"Exiting program.......................";
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    void academicsMenu()
    {
        CourseRegistration c;
        Result r;
        string result;
        while (true)
        {
            cout << "\n1. B.Tech\t2. M.Tech\t3. Exit" << endl;
            cout << "Choose the course: ";
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                course_name = "B.Tech";
                cout << "Performing B.Tech operations..." << endl;
                cout<<"--------------------------------------------------------";
                c.checkData(course_name);
                
                cout << "\nWant to know cgpa of Existing student(Yes/No)? : ";
                cin >> result;
           
                if(result == "Yes" || result == "yes"){
                    r.calculateCgpa();
                }
                break;
            case 2:
                course_name = "M.Tech";
                cout << "Performing M.Tech operations..." << endl;
                cout<<"--------------------------------------------------------";
                c.checkData(course_name);
                cout << "\nWant to know cgpa of Existing student(Yes/No)? : ";
                cin >> result;
                if(result == "Yes" || result == "yes"){
                    r.calculateCgpa();
                }
                break;
            case 3:
                cout<<"Exiting program.......................";
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    void hostelMenu()
    {
        Hostel h;
        while (true)
        {
            cout << "\n1. Student's hostel information\t\t2. New student's room allotment and Mess registration\t\t3. Exit" << endl;
            int ch;
            cout << "Choose option: ";
            cin >> ch;

            string name;
            switch (ch)
            {
            case 1:
                cout << "Enter the name of student: ";
                cin >> name;
                h.hostelDetails(name);
                cout<<"--------------------------------------------------------";
                break;
            case 2:
                h.roomAllotment("Paid");
                cout<<"--------------------------------------------------------";
                break;
            case 3:
                cout<<"Exiting program.......................";
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main()
{
    SRS s;
    s.userInput();
    return 0;
}