#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <vector>
using namespace std;

const int MAX=100;
int count=0;
class Student
{
public:
    void Set();
    void Add();
    void Delete();
    void Search();
    void Change();
    void Display();
    friend void Read(const vector<string>&num,const vector<string>name,const vector<string>age,const vector<string>clas);
    int Judge(string no);
private:
    string s_num;
    string s_name;
    string s_age;
    string s_sex;
    string s_clas;
};
void Student::Set()
{
    string num,name,age,sex,clas;
    ofstream outfile("student.txt");   //打开文件
    if(!outfile)
    {
        cerr<<" open error"<<endl;
        exit(1);  //退出程序
    }
    cout<<"请依次输入学生的学号,姓名,年龄,性别,班级:"<<endl;
    for(int i=0; i<MAX; i++)
    {
        cout<<"第"<<count+1<<"个学生:"<<endl;
        cin>>num;
        if(num == "0") break;  //当输入的学号是 0  时，停止录入
        cin>>name>>age>>sex>>clas;
        count++;
        s_num=num;
        outfile<<s_num<<"\t";  //每录入一个学生，写进磁盘保存
        s_name = name;
        outfile<<s_name<<"\t";
        s_age=age;
        outfile<<s_age<<"\t";
        s_sex=sex;
        outfile<<s_sex<<"\t";
        s_clas=clas;
        outfile<<s_clas<<endl;
    }
    outfile.close();
}
    void Student::Add()
    {
        string num,name,age,sex,clas;
        ofstream outfile("student.txt",ios::app);
        if(!outfile)
        {
            cerr<<" open error"<<endl;
            exit(1);
        }
        count++;
        cout<<"请依次输入要添加的学生学号,姓名,性别,专业,班级:"<<endl;
        cin>>num>>name>>age>>sex>>clas;
        s_num=num;
        outfile<<s_num<<"\t";  //每录入一个学生，写进磁盘保存
        s_name = name;
        outfile<<s_name<<"\t";
        s_age=age;
        outfile<<s_age<<"\t";
        s_sex=sex;
        outfile<<s_sex<<"\t";
        s_clas = clas;
        outfile<<s_clas<<endl;
        outfile.close();
        cout<<"添加完毕！"<<endl;
    }
    void Read(string num[],string name[],string age[],string sex[],string clas[])
    {
        ifstream infile("student.txt",ios::in);
        if (!infile)
        {
            cerr<<"open error"<<endl;
            exit(1);
            for(int i=0;i<count;i++)
            {
                infile>>num[i]>>name[i]>>age[i]>>sex[i]>>clas[i];
            }
            infile.close();
        }
    }
    int Student::Judge(string no)
    {
        string num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        Read(num,name,age,sex,clas);
        for(int i=0;i<count;i++)
        {
            if(no==num[i])
            {
                return i;
                break;
            }
        }
        return -1;
    }
    void Student::Delete()
    {
        string no,num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        Read(num,name,age,sex,clas); //读取学生所有数据
        cout<<"请输入要删除学生的编号";
        cin>>no;
        int k=Judge(no);
        if (k!=-1)
        {
            ofstream outfile("student.txt");
            if(!outfile)
            {
                cerr<<"open error"<<endl;
                exit(1);
            }
            for(int i=0;i<count;i++)
            {
                if (i!=k)
                {
                    outfile<<num[i]<<"\t";
                    outfile<<name[i]<<"\t";
                    outfile<<age[i]<<"\t";
                    outfile<<sex[i]<<"\t";
                    outfile<<clas[i]<<endl;
                }
            }
            outfile.close();
            count--;
            cout<<"删除成功！"<<endl;
        }
        else
            cout<<"没有该学生！"<<endl;
    }
    void Student::Search()
    {
        string no,num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        Read(num,name,age,sex,clas); //读取学生所有数据
        cout<<"请输入要删除学生的编号";
        cin>>no;
        int k=Judge(no);
        if (k=-1)
        {
            cout<<"学号\t姓名\t性别\t专业\t班级"<<endl;
            cout<<num[k]<<"\t";
            cout<<name[k]<<"\t";
            cout<<age[k]<<"\t";
            cout<<sex[k]<<"\t";
            cout<<clas[k]<<endl;
        }
        else
            cout<<"没有该学生！"<<endl;
    }
    void Student::Change()
    {
        string no,num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        cout<<"请输入要修改学生的编号:";
        cin>>no;
        int k=Judge(no);
        if (k!=-1)
        {
           Read(num, name,age,sex,clas);
           cout<<"请输入修改后学生的信息"<<endl;
           cin>>num[k]>>name[k]>>age[k]>>sex[k]>>clas[k];
           ofstream outfile("student.txt",ios::out);
           if (!outfile)
           {
                cerr<<"open error"<<endl;
                exit(1);
           }
           for(int i=0;i<count;i++)
            {

                outfile<<num[i]<<"\t";
                outfile<<name[i]<<"\t";
                outfile<<age[i]<<"\t";
                outfile<<sex[i]<<"\t";
                outfile<<clas[i]<<endl;
            }
           outfile.close();
           cout<<"修改成功！"<<endl;
        }
        else
        {
            cout<<"没有该学生！"<<endl;
        }

    }
    void Student::Display()
    {
        string no,num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        Read(num,name,age,sex,clas);
        cout<<"学号\t姓名\t性别\t专业\t班级"<<endl;
        for(int i=0;i<count;i++)
        {
            cout<<num[i]<<"\t";
            cout<<name[i]<<"\t";
            cout<<age[i]<<"\t";
            cout<<sex[i]<<"\t";
            cout<<clas[i]<<endl;
        }
    }

int main()
{
    int choice=-1;
    Student S;
    while(choice!=0)
    {
    cout<<"================================================================================\n\n";
    cout<<"------------------------ 请选择要操作的命令：-----------------------------------\n\n";
    cout<<"-------------------------- 1 录入学生信息--------------------------------------\n\n";
    cout<<"-------------------------- 2 添加学生信息--------------------------------------\n\n";
    cout<<"-------------------------- 3 删除学生信息--------------------------------------\n\n";
    cout<<"-------------------------- 4 查找学生信息--------------------------------------\n\n";
    cout<<"-------------------------- 5 修改学生信息--------------------------------------\n\n";
    cout<<"-------------------------- 6 显示学生信息--------------------------------------\n\n";
    cout<<"================================================================================\n\n";
    cout<<"请选择操作：";
    cin>>choice;
    switch(choice)
    {
    case 1:
        S.Set();
        break;
    case 2:
        S.Add();
        break;
    case 3:
        S.Delete();
        break;
    case 4:
        S.Search();
        break;
    case 5:
        S.Change();
        break;
    case 6:
        S.Display();
        break;
    case 0:
        break;
    default:
        cout<<"没有这个选项！"<<endl;
        break;
    }
    }
    return 0;
}


