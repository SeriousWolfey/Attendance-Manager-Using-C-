#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

void changeColor(int desiredColor){
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
class student
{
    public:
    long long roll;
    int isPresent;
    string name, Class, labBatch;
    student()
    {
        roll=0;
        isPresent=0;
    }
};

map <long long int, student> students;
map <string, vector<long long int> > Classes;
void groupStudents()
{
    Classes.clear();
    for (auto i : students)
    {
        Classes[i.second.Class].emplace_back(i.first);
        Classes[i.second.Class+i.second.labBatch].emplace_back(i.first);
    }
}

void importStudentData()
{
    ifstream f("studentDatabase.txt");
    while (f)
    {
        student s;
        f>>s.roll;
        f.ignore();
        getline(f,s.name);
        getline(f,s.Class);
        getline(f,s.labBatch);
        if (s.roll)
            students[s.roll]=s;
    }
    cout<<students.size()<<" Values Imported from studentDatabase.txt.\nConsider Running \"createfile.cpp\" to use a Predefined set of Data"<<endl;
    f.close();
}
void exportStudentData()
{
    groupStudents();
    ofstream f("studentDatabase.txt");
    for (auto i : students)
        f<<i.first<<"\n"<<i.second.name<<"\n"<<i.second.Class<<"\n"<<i.second.labBatch<<"\n";
    f.close();
}
void addStudentDatabase()
{
    student s;
    cout<<"Enter Enrollment Number: ";
    cin>>s.roll;
    if (students.count(s.roll))
        cout<<"A Student Already Exists with that Enrollment Number"<<endl;
    else
    {
        cin.clear();
        cin.sync();
        cout<<"Enter Name: ";
        getline(cin,s.name);
        cout<<"Enter Class: ";
        getline(cin,s.Class);
        cout<<"Enter Lab Batch: ";
        getline(cin,s.labBatch);
        students[s.roll]=s;
        cout<<"Student Added Sucessfully."<<endl;
    }
    exportStudentData();
}
void updateStudentDatabase()
{
    student s;
    cout<<"Enter Enrollment Number: ";
    cin>>s.roll;
    if (students.count(s.roll))
    {
        cin.clear();
        cin.sync();
        cout<<"Enter Name (Previously "<<students[s.roll].name<<"): ";
        getline(cin,s.name);
        cout<<"Enter Class (Previously "<<students[s.roll].Class<<"): ";
        getline(cin,s.Class);
        cout<<"Enter Lab Batch (Previously "<<students[s.roll].labBatch<<"): ";
        getline(cin,s.labBatch);
        students[s.roll]=s;
        cout<<"Student Updated Sucessfully."<<endl;
    }
    else
        cout<<"No Student found"<<endl;
    exportStudentData();
}
void deleteStudentDatabase()
{
    long long int i;
    cout<<"Enter Enrollment Number: ";
    cin>>i;
    if (students.count(i))
    {
        students.erase(i);
        cout<<"Student Deleted Sucessfully!"<<endl;
    }
    else
        cout<<"No Student found"<<endl;
    exportStudentData();
}
void displayStudentDatabase()
{
    long long int i;
    cout<<"Enter Enrollment Number: ";
    cin>>i;
    if (students.count(i))
    {
        cout<<"Name: "<<students[i].name<<endl
            <<"Class: "<<students[i].Class<<endl
            <<"Lab Batch: "<<students[i].labBatch<<endl;
    }
    else
        cout<<"No Student found"<<endl;
    exportStudentData();
}
void displayAttendance(vector <long long int> Class)
{
    system("CLS");
    int i,l=0;
    for (i=0;i<Class.size();i++)
    {
        if (students[Class[i]].name.length()>l)
            l=students[Class[i]].name.length();
    }
    cout<<"Attendance:\n";
    for (i=0;i<Class.size();i++)
    {
        cout<<Class[i]<<": "<<setw(l)<<left<<students[Class[i]].name<<": ";
        changeColor(((students[Class[i]].isPresent)?10:4));
        cout<<((students[Class[i]].isPresent)?"Present":"Absent")<<endl;
        changeColor(7);
    }
    cout<<"Do you want to save this Attendance on \"Attendance.txt\"? (y/n): ";
    char p=getch();
    if (p=='y')
    {
        ofstream f("Attendance.txt");
        for (i=0;i<Class.size();i++)
            f<<Class[i]<<": "<<setw(l)<<left<<students[Class[i]].name<<": "<<((students[Class[i]].isPresent)?"Present":"Absent")<<endl;
        cout<<"\nData Saved Sucessfully!"<<endl;
    }
    else
        cout<<"\nSave Aborted."<<endl;
}
void takeAttendance(int type)
{
    string x;
    cout<<"Enter Your Class from the following options:"<<endl;
    for (auto i : Classes)
        cout<<i.first<<endl;
    cout<<"> ";
    cin>>x;
    if (Classes.count(x))
    {
        system("CLS");
        cout<<"Taking Attendance of "<<Classes[x].size()<<" Students: "<<endl;
        int i,l=0;
        for (i=0;i<Classes[x].size();i++)
        {
            if (students[Classes[x][i]].name.length()>l)
                l=students[Classes[x][i]].name.length();
        }
        switch (type)
        {

            case 1:
            {
                char p;

                for (i=0;i<Classes[x].size();i++)
                {
                    cout<<Classes[x][i]<<": ";
                    cout<<setw(l)<<left<<students[Classes[x][i]].name;
                    cout<<": ";
                    p=getch();
                    changeColor(p=='p'?10:p=='a'?4:7);
                    cout<<p<<endl;
                    changeColor(7);
                    if (p=='p')
                        students[Classes[x][i]].isPresent=1;
                    else if (p=='a')
                        students[Classes[x][i]].isPresent=0;
                    else
                    {
                        cout<<"Invalid Option"<<endl;
                        i--;
                    }
                }
            }
            break;
            case 2:
            {
                int i,n=1,digits=0,diff,flag;
                long long int roll;
                diff=(Classes[x][Classes[x].size()-1]-Classes[x][0]);
                for (i=1;i<(Classes[x][Classes[x].size()-1]-Classes[x][0]+(Classes[x][0]%i));i*=10)
                    digits++;
                //cout<<"Since the difference between first and last number is "<<diff<<endl;
                cout<<"Enter each present Student's Last "<<digits<<" Digits of their Enrollment Number, or 0 to End Attendance"<<endl;
                while (n!=0)
                {
                    cin>>n;
                    if (n!=0)
                    {
                        roll=Classes[x][0]+n-(Classes[x][0]%((long long int)(pow(10,digits))));
                        flag = 0;
                        for (i=0;i<Classes[x].size();i++)
                            if (roll==Classes[x][i])
                            {
                                flag = 1;
                            }
                        if (flag)
                        {
                            students[roll].isPresent=(!students[roll].isPresent);
                            cout<<students[roll].name<<": ";
                            changeColor(((students[roll].isPresent)?10:4));
                            cout<<(students[roll].isPresent?"Present":"Absent")<<endl;
                            changeColor(7);
                            //cout<<Class[i]<<": "<<setw(l)<<students[Class[i]].name<<": ";
                            //cout<<((students[Class[i]].isPresent)?"Present":"Absent")<<endl;
                        }
                        else
                            cout<<"Student not found"<<endl;
                    }
                }
            }
            break;
        }
        displayAttendance(Classes[x]);

    }
    else if (x=="exit")
        ;
    else
    {
        cout<<"Invalid Class. Retry or enter \"exit\" to stop"<<endl;
        takeAttendance(type);
    }
}
int main()
{
    importStudentData();
    groupStudents();
    while (1)
    {
        cout<<"Enter: \n1: Take Attendance\n2: Update Database\n> ";
        int x;
        cin>>x;
        system("CLS");
        switch (x)
        {
            case 1:
                cout<<"Enter \n1: Sorted Method\n2: Unsorted Method\n> ";
                cin>>x;
                system("CLS");
                switch (x)
                {
                    case 1:
                        takeAttendance(1);
                    break;
                    case 2:
                        takeAttendance(2);
                    break;
                    default:
                        cout<<"Invalid Option"<<endl;
                    break;
                }
            break;
            case 2:
                cout<<"Enter \n1: Add Database\n2: Update Database\n3: Delete Database\n4: Display Database\n2: > ";
                cin>>x;
                //system("CLS");
                switch (x)
                {
                    case 1:
                        addStudentDatabase();
                    break;
                    case 2:
                        updateStudentDatabase();
                    break;
                    case 3:
                        deleteStudentDatabase();
                    break;
                    case 4:
                        displayStudentDatabase();
                    break;
                    default:
                        cout<<"Invalid Option"<<endl;
                    break;
                }
            break;
            default:
                cout<<"Invalid Option"<<endl;
            break;
        }
        cout<<"\nEnter anything to continue...\n";
        getch();
        system("CLS");
    }
    return 0;
}
