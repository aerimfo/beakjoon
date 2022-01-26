// [16506] CPU
// https://www.acmicpc.net/problem/16506

#include <iostream> 
using namespace std;

string opcode, bit;
int n, rD, rA, rBC;

void checkOpcode()
{
    if(opcode == "ADD") {
        bit.replace(0, 4, "0000");
    }
    else if(opcode == "SUB") {
        bit.replace(0, 4, "0001");
    }
    else if(opcode == "MOV") {
        bit.replace(0, 4, "0010");
    }
    else if(opcode == "AND") {
        bit.replace(0, 4, "0011");
    }
    else if(opcode == "OR") {
        bit.replace(0, 4, "0100");
    }
    else if(opcode == "NOT") {
        bit.replace(0, 4, "0101");
    }
    else if(opcode == "MULT") {
        bit.replace(0, 4, "0110");
    }
    else if(opcode == "LSFTL") {
        bit.replace(0, 4, "0111");
    }
    else if(opcode == "LSFTR") {
        bit.replace(0, 4, "1000");
    }
    else if(opcode == "ASFTR") {
        bit.replace(0, 4, "1001");
    }
    else if(opcode == "RL") {
        bit.replace(0, 4, "1010");
    }
    else if(opcode == "RR") {
        bit.replace(0, 4, "1011");
    }
}

void getBinary(int r, int idx)
{
    while(r != 0) {
        bit[idx] = (char)(r % 2 + 48);
        r /= 2;
        idx--;
    }
}

void assemblyToMachine()
{
    bit = "0000000000000000";
    int length = opcode.size();
    if(opcode[length-1] == 'C') {
        bit[4] = '1';
        opcode.erase(length-1);
    }

    checkOpcode();
    getBinary(rD, 8);
    getBinary(rA, 11);
    if(bit[4] == '0') {
        getBinary(rBC, 14);
    }
    else {
        getBinary(rBC, 15);
    }
    
    cout << bit << '\n';
}

void input()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> opcode >> rD >> rA >> rBC;
        assemblyToMachine();
    }    
}

int main(void)
{
    input();
}