#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;
deque<deque<string>>patients(20);
deque<deque<bool>>Status(20);

short int specialization;
bool status;
string name;
int choice ;

// first function: to offer the options ;
int menu(){
cout<<"Enter your choice "<<endl;
cout<<"1)Add new patient"<<endl;
cout<<"2)Print all patients"<<endl;
cout<<"3)Get next patient"<<endl;
cout<<"4)Exit"<<endl;
cin>>choice;
if(choice<1||choice>4){
cout<<"invalid operation , please choose your question "<<endl;
menu();
}
return choice;

}
//Second function :to Add new patient;
void AddPatient(){
cout<<"please Enter the specialization , name , status"<<endl;
cin>>specialization >> name>>status;
if(patients[specialization].size()>=5)
cout<<"Sorry , the reservations is full"<<endl;
 else{
 if(status==1){
 patients[specialization].push_front(name);
 Status[specialization].push_front(status);
 }
 else{
 patients[specialization].push_back(name);
 Status[specialization].push_back(status);
      }
   }
}
void print(){
for(int i=0;i<20;i++){
for(int k=0;k<5;k++){
if(!patients[i].empty()){
cout<<i<<"  "<<patients[i][k]<<"  "<<Status[i][k]<<endl;
break;
    }
   }
  }
}
void GetNextPatient(){

cout<<"please Enter the specialization"<<endl;
 cin>>specialization;
  if(!patients[specialization].empty()){

cout<<patients[specialization][0]<<"  "<<"please go with the Dr"<<endl;
 patients[specialization].pop_front();
 Status[specialization].pop_front();
 }
 if(patients[specialization].empty()){
 cout<<"sorry Dr, there is no patients"<<endl;

}
}
int  Exit(){

return 0;
}

void HospitalSystem(){
menu();
if(choice==1)
AddPatient();

else if(choice==2)
print();

else if(choice==3)
GetNextPatient();

else if(choice==4)
Exit();

if(choice!=4)
HospitalSystem();

}
int main (){
HospitalSystem();
return 0;
}
