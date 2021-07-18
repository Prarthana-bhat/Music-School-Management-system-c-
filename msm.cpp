#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int ID;
struct Music
{
    int id;
    string name;
    string age;
    string course;
    string fee;
};

void addStudent()
{
    Music student;
    cout<<"\n\tEnter the name : ";
    cin.get();
    getline(cin, student.name);
    cout<<"\n\tEnter  age : ";
    cin>>student.age;
    cout<<"\n\tEnter the course opted : ";
    cin>>student.course;
    cout<<"\n\tEnter monthly fee : ";
    cin>>student.fee;
    ID++;

    ofstream write;
    write.open("msd.txt", ios::app);
    write<<"\n"<<ID;
    write<<"\n"<<student.name ;
    write<<"\n"<<student.age ;

    write<<"\n"<<student.course ;
    write<<"\n"<<student.fee;
    write.close();
    write.open("id.txt");
    write<<ID;
    write.close();
    cout<<"\n\tData has been saved to the file";
}

void print(Music s)
{
    cout<<"\n\t---Student Data---";
    cout<<"\n\tID is : "<< s.id;
    cout<<"\n\tName is : "<< s.name;
    cout<<"\n\tAge is : "<< s.age;
    cout<<"\n\tcourse is : "<< s.course;
    cout<<"\n\tmonthly fee is : "<< s.fee;

}

void readData()
{
   Music student;
    ifstream read;
    read.open("msd.txt");
    while(!read.eof())
    {
        read>>student.id;
        read.ignore();
        getline(read, student.name);
        read>>student.age;
        read>>student.course;
        read>>student.fee;
        print(student);
    }
    read.close();
}

int searchData() {
    int id;
    cout<<"\n\tEnter the id you want to search : ";
    cin>>id;
    Music student;
    ifstream read;
    read.open("msd.txt");
    while(!read.eof())
    {
        read>>student.id;
        read.ignore();
        getline(read, student.name);
        read>>student.age;
        read>>student.course;
        read>>student.fee;
        if(student.id == id)
        {
            print(student);
            return id;
        }
    }
}

void deleteData()
{
    int id = searchData();
    cout<<"\n\tYou want to delete record (y/n) : ";
    char choice;
    cin>>choice;
    if (choice == 'y')
    {
        Music student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("msd.txt");
        while(!read.eof())
        {
            read>>student.id;
            read.ignore();
            getline(read, student.name);
            read>>student.age;
            read>>student.course;
            read>>student.fee;
            if(student.id != id)
            {
                tempFile<<"\n"<<student.id;
                tempFile<<"\n"<<student.name;
                tempFile<<"\n"<<student.age;
                tempFile<<"\n"<<student.course;
                tempFile<<"\n"<<student.fee;
            }
        }
        read.close();
        tempFile.close();
        remove("msd.txt");
        rename("temp.txt", "msd.txt");
        cout<<"\n\tData deleted successfully";
    }
    else
    {
        cout<<"\n\tRecord not deleted";
    }
}

void updateData()
{
    int id = searchData();
    cout<<"\n\tYou want to update record (y/n) : ";
    char choice;
    cin>>choice;
    if(choice=='y')
    {
        Music newData;
        cout<<"\n\tEnter the name : ";
        cin.get();
        getline(cin, newData.name);
        cout<<"\n\tEnter the age : ";
        cin>>newData.age;
        cout<<"\n\tEnter the course : ";
        cin>>newData.course;
        cout<<"\n\tEnter monthly fee : ";
        cin>>newData.fee;
        Music student;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("msd.txt");
        while (!read.eof())
        {
            read>>student.id;
            read.ignore();
            getline(read, student.name);
            read>>student.age;
            read>>student.course;
            read>>student.fee;
            if(student.id!=id)
            {
                tempFile<<"\n"<<student.id;
                tempFile<<"\n"<<student.name;
                tempFile<<"\n"<<student.age;
                tempFile<<"\n"<<student.course;
                tempFile<<"\n"<<student.fee;
            }
            else
            {
                tempFile<<"\n"<<student.id;
                tempFile<<"\n"<<newData.name;
                tempFile<<"\n"<<newData.age;
                tempFile<<"\n"<<newData.course;
                tempFile<<"\n"<<newData.fee;
            }
        }
        read.close();
        tempFile.close();
        remove("msd.txt");
        rename("temp.txt", "msd.txt");
        cout<<"\n\tData was updated successfully";
    }
    else
    {
        cout<<"\n\tRecord is not deleted";
    }
}
int main()
{
    ifstream read;
    cout<<"!-----------------MUSIC SCHOOL DATA-------------------!";
    read.open("id.txt");
    if(!read.fail())
    {
        read>>ID;
    }
    else
    {
        ID = 0;
    }
    read.close();

    while(true)
    {
        cout<<"\n\t1.Add student data";
        cout<<"\n\t2.view student data";
        cout<<"\n\t3.Search student data";
        cout<<"\n\t4.Delete student data";
        cout<<"\n\t5.Update student data";
        cout<<"\n\t6.exit";

        int choice;
        cout<<"\n\tEnter choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:addStudent();
                    break;
            case 2:readData();
                    break;
            case 3:searchData();
                    break;
            case 4:deleteData();
                    break;
            case 5:updateData();
                    break;
            default:cout<<"Thank you:)";
                    exit(0);
        }
    }

}
