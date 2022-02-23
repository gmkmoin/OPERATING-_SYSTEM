#include<iostream>
using namespace std;

int Complition_Time(int proces[],int n,int Burst_time[],int Sclice,int Complit_time[])
{
    int updat_t[10],i=0 , curnt_time=0;
    while(i<n){
        updat_t[i]=Burst_time[i];
        i++;
    }

    while(1)
    {
        bool b_t=true;
        i=0;
        while(i<n)
        {
            if(updat_t[i]>0)
            {
                b_t=false;

                if(updat_t[i]>Sclice)
                {
                    updat_t[i]=updat_t[i]-Sclice;
                    curnt_time=curnt_time+Sclice;
                    Complit_time[i]=curnt_time;
                    
                    //cout<<Complit_time[i]<<"    ";
                    //cout<<updat_t[i]<<" "<<endl;
                    
                }

                else
                {
                    curnt_time=curnt_time+updat_t[i];
                    Complit_time[i]=curnt_time;
                    updat_t[i]=0;

                   // cout<<Complit_time[i]<<"    ";
                    //cout<<updat_t[i]<<" "<<endl;
                }
                

            }

            i++;
        }

        if(b_t==true)
            break;
    }


}

int Find_Wait_time(int proces[],int n,int Burst_time[],int Wait_time[],int Complit_time[])
{
    Wait_time[0]=0;
    int i=0;
    while (i<n)
    {
        Wait_time[i]=Complit_time[i]-Burst_time[i];
        i++;
    }
    
}

int Avg_Time(int processes[],int n,int Burst_time[],int Complit_time[])
{
    int i=0,avg1,avg2;
    float total_wait_time=0,total_turn_around_time=0;
    int Wait_time[n],Turn_A_time[n];

    while(i<n)
    {
        Turn_A_time[i]=Complit_time[i];
        i++;
    }

    Find_Wait_time(processes,n,Burst_time,Wait_time,Complit_time);

    cout<<"Avg WAITING TIME IS : ";
    i=0;
    while(i<n)
    {
        total_wait_time=total_wait_time+Wait_time[i];
        i++;
    }
    cout<<total_wait_time/n;

    cout<<"\nAvg TURN AROUND TIME IS : ";
    i=0;
    while(i<n)
    {
        total_turn_around_time=total_turn_around_time+Complit_time[i];
        i++;
    }
    cout<<total_turn_around_time/n<<endl;

    /* i=0;
    while(i<n)                            //print burst time , comlit time (turn around time), waiting time
    {
        cout<<Burst_time[i]<<"    ";  
        cout<<Complit_time[i]<<"    ";
        cout<<Wait_time[i]<<"    "<<endl;
        i++;
    }
    */
}
 
int main()
{
    int n,i=0, processes[10], Burst_time[10],Complit_time[10]={0};
    int Sclice;
    cout<<"ENTER NO OF PROCESSES : ";
    cin>>n;
    
    while (i<n)
    {
        processes[i]=i+1;
        i++;
    }

    cout<<"ENTER BRUST TIME OF PROCESSE : ";
    i=0;
    while (i<n)
    {
        cin>>Burst_time[i] ;
        i++;
    }

    cout<<"ENTER TIME SCLICE FOR ROUND-ROBIN : ";
    cin>>Sclice;

    Complition_Time(processes,n,Burst_time,Sclice,Complit_time);

    Avg_Time( processes,n , Burst_time,Complit_time);

    return 0;
}