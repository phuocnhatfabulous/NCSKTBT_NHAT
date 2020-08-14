#include<iostream>
using namespace std;
void towerOfHN(int n, char from_rod, char to_rod, char aux_rod){
    if(n==1){
        cout<<"Move disk 1 from rod"<<from_rod<<"to rod"<<to_rod<<endl;
        return;
    }
    towerOfHN(n-1, from_rod, aux_rod, to_rod);
    cout<<"Move disk"<<n<<"from rod"<<from_rod<<"to rod"<<to_rod<<endl;
    towerOfHN(n-1, aux_rod, to_rod, from_rod);
}
//Driver code
int main(){
    int n;
    cout<<"Enter number of disks:";
    cin>>n;
    towerOfHN(n, 'A', 'C', 'B');//A,B,C are names of rods
    return 0;
}
