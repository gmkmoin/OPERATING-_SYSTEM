#include<iostream>
using namespace std;

int Proces_Selection()
{

}

int Find_Wait_time(int proces[],int n,int Burst_time[],int Wait_time[])
{
    Wait_time[0]=0;
    int i=1;
    while (i<=n)
    {
        Wait_time[i]=Burst_time[i-1]+Wait_time[i-1];
        i++;
    }
    
}

int Find_Trun_A_time(int proces[],int n, int Brust_time[],int Wait_time[], int Trun_A_time[])
{
    int i=0;

    while (proces[i]<=n)
    {
        Trun_A_time[i]=Brust_time[i]+Wait_time[i];
        i++;
    }

}
int Avg_Time(int processes[],int n,int Burst_time[])
{
    int i,avg1,avg2;
    float total_wait_time=0,total_turn_around_time=0;
    int Wait_time[n],Turn_A_time[n];

    Find_Wait_time(processes,n,Burst_time,Wait_time);
    Find_Trun_A_time(processes,n,Burst_time,Wait_time,Turn_A_time);

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
        total_turn_around_time=total_turn_around_time+Turn_A_time[i];
        i++;
    }
    cout<<total_turn_around_time/n;

}

int short_proces(int a[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

int main()
{
    int n,i=0, processes[10], Burst_time[10];
    int avg_time;
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

    short_proces(Burst_time,n);

    Avg_Time( processes,n , Burst_time);

    
    return 0;
}