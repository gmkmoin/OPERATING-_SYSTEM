#include<iostream>
using namespace std;

int Find_Wait_time(int proces[],int n,int *point,int Wait_time[])
{
    Wait_time[0]=0;
    int i=1;
    while (i<=n)
    {
        Wait_time[i]= *point + Wait_time[i-1];
        point=point+2;
        i++;
    }
}

int Find_Trun_A_time(int proces[],int n, int *point,int Wait_time[], int Trun_A_time[])
{
    int i=0;
    int *bst;
    bst=point;
    while (proces[i]<=n)
    {
        Trun_A_time[i]= *point + Wait_time[i];
        point=point+2;
        i++;
    }
    
    cout<<"S.NO.       Burst Time        Priority       Turn Around Time     Waiting Time\n";
     i=0;
    while(i<n)
    {
        cout<<i+1<<"              ";
        cout<<*bst<<"                 ";
        bst=bst+1;
        cout<<*bst<<"                ";
        bst=bst+1;
        cout<<Trun_A_time[i]<<"                  ";
        cout<<Wait_time[i]<<"\n";
        i++;
    }

}
int Avg_Time(int processes[],int n,int *point)
{
    int i,avg1,avg2;
    float total_wait_time=0,total_turn_around_time=0;
    int Wait_time[n],Turn_A_time[n];

    Find_Wait_time(processes,n,point,Wait_time );
    Find_Trun_A_time(processes,n,point,Wait_time,Turn_A_time);

    cout<<"\nAvg WAITING TIME IS : ";
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

int short_proces(int a[][2],int n)
{
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[i][1]>a[j][1])
            {
                swap(a[i],a[j]);
            }
        }
    }
}

int main()
{
    int n,i=0, processes[10], Burst_time[10][2];
    int *point;
    point=&Burst_time[0][0];
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
        cin>>Burst_time[i][0] ;
        i++;
    }
    
    cout<<"GIVE PRIORITY TO ";
    i=0;
    while (i<n)
    {
        cin>>Burst_time[i][1];
        i++;
    }
    short_proces(Burst_time,n);
    

    Avg_Time( processes,n , point);

    
    return 0;
}