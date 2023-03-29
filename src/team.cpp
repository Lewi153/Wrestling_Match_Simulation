#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "team.h"


using namespace std;

team::team(default_random_engine * ptr, int idT)
{
    /////////////Initialize a Team////////////
    for(int i = 0; i < 14; i++){                        //Weight Class Array = NULL for now
        head[i]=NULL;}
    ID=idT;                                             //Set Team's ID

    normal_distribution<double> TeamSizeDist(25, 3);    //Determine Team Size (Number of Wrestlers)
    int teamSize = (int)TeamSizeDist(*ptr);
    tsize=teamSize;                                     //Set Team Size private data

    wrestler * newGuy=NULL;
    wrestler * curr=NULL;
    wrestler * prev=NULL;

    for(int i = 1; i < teamSize+1; i++){                //Create Team's Wrestlers, Amount Based on Team Size
        newGuy = new wrestler(ptr);
        int idW;
        idW = idT + i;
        newGuy->SetID(idW);                             //Set Current Wrestler's ID, Get Ability, and Get Wt Class
        int newGuyAbility = newGuy->GetAbility();
        int newGuyWtClass = newGuy->GetWtClass();


/////////WtClass Array Assignment/////////
        switch(newGuyWtClass){

        case 1:{
            curr=head[0];
            if(curr==NULL){                             //No Head exists
                head[0]=newGuy;
            }
            else if(curr->GetNext()==NULL){             //Only Head exists
                if(newGuyAbility > curr->GetAbility()){     ///Set as Head
                    head[0]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[0]->SetNext(newGuy);}              ///Set after Head
            }
            else{                                       //Head + List exist
                if(newGuyAbility>curr->GetAbility()){       ///Set as Head
                    head[0]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){        ///Set as 2nd to Last
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){  ///Set as Last
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);                                               ///Set as somewhere in Middle
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;
        // ^ Reiterated For Each Subsequent Weight Class (2-14)
        case 2:{
            curr=head[1];
            if(curr==NULL){
                head[1]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[1]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[1]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[1]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 3:{
            curr=head[2];
            if(curr==NULL){
                head[2]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[2]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[2]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[2]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 4:{
            curr=head[3];
            if(curr==NULL){
                head[3]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[3]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[3]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[3]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 5:{
            curr=head[4];
            if(curr==NULL){
                head[4]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[4]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[4]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[4]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 6:{
            curr=head[5];
            if(curr==NULL){
                head[5]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[5]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[5]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[5]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 7:{
            curr=head[6];
            if(curr==NULL){
                head[6]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[6]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[6]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[6]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 8:{
            curr=head[7];
            if(curr==NULL){
                head[7]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[7]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[7]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[7]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 9:{
            curr=head[8];
            if(curr==NULL){
                head[8]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[8]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[8]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[8]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 10:{
            curr=head[9];
            if(curr==NULL){
                head[9]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[9]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[9]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[9]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 11:{
            curr=head[10];
            if(curr==NULL){
                head[10]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[10]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[10]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[10]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 12:{
            curr=head[11];
            if(curr==NULL){
                head[11]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[11]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[11]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[11]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 13:{
            curr=head[12];
            if(curr==NULL){
                head[12]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[12]=newGuy;
                    newGuy->SetNext(curr);
                    }
                else{head[12]->SetNext(newGuy);
                }
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[12]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;

        case 14:{
            curr=head[13];
            if(curr==NULL){
                head[13]=newGuy;
            }
            else if(curr->GetNext()==NULL){
                if(newGuyAbility > curr->GetAbility()){
                    head[13]=newGuy;
                    newGuy->SetNext(curr);}
                else{head[13]->SetNext(newGuy);}
            }
            else{
                if(newGuyAbility>curr->GetAbility()){
                    head[13]=newGuy;
                    newGuy->SetNext(curr);}
                else{while(newGuyAbility < curr->GetAbility() && curr->GetNext() != NULL){
                        prev=curr;
                        curr=curr->GetNext();}
                    if(curr->GetNext()==NULL && newGuyAbility>curr->GetAbility()){
                        prev->SetNext(newGuy);
                        newGuy->SetNext(curr);}
                    else if(curr->GetNext()==NULL && newGuyAbility<=curr->GetAbility()){
                        curr->SetNext(newGuy);}
                else{prev->SetNext(newGuy);
                    newGuy->SetNext(curr);}}
            }
        newGuy=NULL;
        curr=NULL;
        prev=NULL;
        }break;
        default:{cout<<"WtClass Assignment Failed!" <<endl;}
        }//End Switch
    }//End For Loop
}//End Constructor


team::~team()
{
cout<<"Team " << ID <<" Removed";
}

wrestler * team::GetHead(int i){    //Retrieve 1st Wrestler in a Wt Class
    wrestler * currHead;
    currHead = head[i];
    return currHead;
}



void team::Display(){
    cout<<"****** TEAM: "<<ID<<" [BEGIN ALL WRESTLER DATA]******"<<endl<<endl; //Emphasize Beginning of Team Data
    cout<<"Number of Wrestlers: "<<tsize<<endl<<endl;
    for (int i =0; i<14; i++){
        cout<<"--Weight Class: "<<i+1<<"--"<<endl;
        wrestler * currGuy = head[i];
        if (currGuy==NULL){                                 //No Wrestlers in Wt Class
            cout<<"No Wrestlers. " <<endl<<endl;}
        else{while(currGuy!=NULL){                          //Wrestlers Exist in Wt Class
            currGuy->Display();
            cout<<endl;
            currGuy=currGuy->GetNext();}}
    }//End For Loop
    cout<<"****** TEAM: "<<ID<<" [END ALL WRESTLER DATA] ******"<<endl<<endl; //Emphasize End of Team Data
}//End Function
