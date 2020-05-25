#include <iostream>
#include <math.h>

using namespace std;

const int m=9; //Type M

enum status{Empty,Deleted,Occupied};

class slot
{
public:
    int data;
    status stat;

    slot()
    {
        stat=status::Empty;
    }
};

int h(int k,int n)
{
    return (k%9 + 8*n + 3*(int)pow(n,2))%m; //Type func
}

void showdata(slot slots[],int m)
{
    for(int i=0;i<m;i++)
    {
        switch(slots[i].stat)
        {
        case status::Occupied:
            cout<<slots[i].data<<" ";
            break;
        case status::Deleted:
            cout<<"D ";
            break;
        case status::Empty:
            cout<<"E ";
            break;
        }
    }
    cout<<"\n";
}

void insert(slot slots[],int m,int k)
{
    cout<<k<<" beszurasa:\nProbasorozat: ";
    int pos;
    int dpos=-1;
    int i=0;
    do
    {
        pos=h(k,i);
        if(slots[pos].stat==status::Deleted && dpos==-1) dpos=pos;
        cout<<pos<<" ";
        i++;
    }while(slots[pos].stat!=status::Empty && slots[pos].data!=k);
    if(slots[pos].data!=k)
    {
        if(dpos==-1)
        {
            slots[pos].stat=status::Occupied;
            slots[pos].data=k;
            cout<<"| beszurasra kerult a(z) "<<pos<<" indexre";
        }
        else
        {
            slots[dpos].stat=status::Occupied;
            slots[dpos].data=k;
            cout<<"| beszurasra kerult a(z) "<<dpos<<" indexre";
        }
    }
    else cout<<"Nem sikerult beszurni";
    cout<<"\n";
}

void del(slot slots[],int m,int k)
{
    cout<<k<<" torlese:\nProbasorozat: ";
    int pos;
    int i=0;
    do
    {
        pos=h(k,i);
        cout<<pos<<" ";
        i++;
    }while(slots[pos].stat!=status::Empty && slots[pos].data!=k);
    if(slots[pos].data==k)
    {
        slots[pos].stat=status::Deleted;
    }
    else
    {
        cout<<"A torlendo dolog nincs benne";
    }
    cout<<"\n";
}

void search(slot slots[],int m,int k)
{
    cout<<k<<" keresese:\nProbasorozat: ";
    int pos;
    int i=0;
    do
    {
        pos=h(k,i);
        cout<<pos<<" ";
        i++;
    }while(slots[pos].stat!=status::Empty && slots[pos].data!=k);
    if(slots[pos].stat==status::Empty) cout<<"A keresendo dolog nincs benne";
    cout<<"\n";
}

void run(slot slots[],int m)
{
    cout<<"Mukodes:\nn beszurasa: insert n\nn torlese: delete n\nn keresese: search n\nA tabla kiirasa: show\nkilepes: exit\nBarmi mas parancs nem fog mukodni.\n";
    string order;
    int k;
    do
    {
        cin>>order;
        if(order=="insert")
        {
            cin>>k;
            insert(slots,m,k);
        }
        else if(order=="delete")
        {
            cin>>k;
            del(slots,m,k);
        }
        else if(order=="search")
        {
            cin>>k;
            search(slots,m,k);
        }
        else if(order=="show")
        {
            showdata(slots,m);
        }
    }while(order!="exit");
}

int main()
{
    slot slots[m];
    run(slots,m);
    return 0;
}
