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
    ofstream outfile("student.txt");   //���ļ�
    if(!outfile)
    {
        cerr<<" open error"<<endl;
        exit(1);  //�˳�����
    }
    cout<<"����������ѧ����ѧ��,����,����,�Ա�,�༶:"<<endl;
    for(int i=0; i<MAX; i++)
    {
        cout<<"��"<<count+1<<"��ѧ��:"<<endl;
        cin>>num;
        if(num == "0") break;  //�������ѧ���� 0  ʱ��ֹͣ¼��
        cin>>name>>age>>sex>>clas;
        count++;
        s_num=num;
        outfile<<s_num<<"\t";  //ÿ¼��һ��ѧ����д�����̱���
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
        cout<<"����������Ҫ��ӵ�ѧ��ѧ��,����,�Ա�,רҵ,�༶:"<<endl;
        cin>>num>>name>>age>>sex>>clas;
        s_num=num;
        outfile<<s_num<<"\t";  //ÿ¼��һ��ѧ����д�����̱���
        s_name = name;
        outfile<<s_name<<"\t";
        s_age=age;
        outfile<<s_age<<"\t";
        s_sex=sex;
        outfile<<s_sex<<"\t";
        s_clas = clas;
        outfile<<s_clas<<endl;
        outfile.close();
        cout<<"�����ϣ�"<<endl;
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
        Read(num,name,age,sex,clas); //��ȡѧ����������
        cout<<"������Ҫɾ��ѧ���ı��";
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
            cout<<"ɾ���ɹ���"<<endl;
        }
        else
            cout<<"û�и�ѧ����"<<endl;
    }
    void Student::Search()
    {
        string no,num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        Read(num,name,age,sex,clas); //��ȡѧ����������
        cout<<"������Ҫɾ��ѧ���ı��";
        cin>>no;
        int k=Judge(no);
        if (k=-1)
        {
            cout<<"ѧ��\t����\t�Ա�\tרҵ\t�༶"<<endl;
            cout<<num[k]<<"\t";
            cout<<name[k]<<"\t";
            cout<<age[k]<<"\t";
            cout<<sex[k]<<"\t";
            cout<<clas[k]<<endl;
        }
        else
            cout<<"û�и�ѧ����"<<endl;
    }
    void Student::Change()
    {
        string no,num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        cout<<"������Ҫ�޸�ѧ���ı��:";
        cin>>no;
        int k=Judge(no);
        if (k!=-1)
        {
           Read(num, name,age,sex,clas);
           cout<<"�������޸ĺ�ѧ������Ϣ"<<endl;
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
           cout<<"�޸ĳɹ���"<<endl;
        }
        else
        {
            cout<<"û�и�ѧ����"<<endl;
        }

    }
    void Student::Display()
    {
        string no,num[MAX],name[MAX],age[MAX],sex[MAX],clas[MAX];
        Read(num,name,age,sex,clas);
        cout<<"ѧ��\t����\t�Ա�\tרҵ\t�༶"<<endl;
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
    cout<<"------------------------ ��ѡ��Ҫ���������-----------------------------------\n\n";
    cout<<"-------------------------- 1 ¼��ѧ����Ϣ--------------------------------------\n\n";
    cout<<"-------------------------- 2 ���ѧ����Ϣ--------------------------------------\n\n";
    cout<<"-------------------------- 3 ɾ��ѧ����Ϣ--------------------------------------\n\n";
    cout<<"-------------------------- 4 ����ѧ����Ϣ--------------------------------------\n\n";
    cout<<"-------------------------- 5 �޸�ѧ����Ϣ--------------------------------------\n\n";
    cout<<"-------------------------- 6 ��ʾѧ����Ϣ--------------------------------------\n\n";
    cout<<"================================================================================\n\n";
    cout<<"��ѡ�������";
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
        cout<<"û�����ѡ�"<<endl;
        break;
    }
    }
    return 0;
}


