// [1969] DNA
// https://www.acmicpc.net/problem/1969

#include <iostream>
using namespace std;

int n, m, ans[1001], hammingDisSum = 0;
string dna[1001];

void input()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> dna[i];
    }   
}

void setDNA(int idx)
{
    int nucleotide[4] = {0,};
    for(int i = 0; i < n; i++) {
        if(dna[i][idx] == 'A') {
            nucleotide[0]++;
        }
        else if(dna[i][idx] == 'C') {
            nucleotide[1]++;
        }
        else if(dna[i][idx] == 'G') {
            nucleotide[2]++;
        }
        else {
            nucleotide[3]++;
        }
    }

    int max = nucleotide[0];
    ans[idx] = 0;
    for(int i = 1; i < 4; i++) {
        if(nucleotide[i] > max) {
            max = nucleotide[i];
            ans[idx] = i;
        }
    }
    hammingDisSum += (n - nucleotide[ans[idx]]);
}

void getMinDNA()
{
    int hammingDis = 0;
    for(int i = 0; i < m; i++) {
        setDNA(i);
    }
}

void printDNA()
{
    for(int i = 0; i < m; i++) {
        if(ans[i] == 0) {
            cout << 'A';
        }
        else if(ans[i] == 1) {
            cout << 'C';
        }
        else if(ans[i] == 2) {
            cout << 'G';
        }
        else {
            cout << 'T';
        }
    }
    cout << '\n' << hammingDisSum << '\n';
}

int main(void)
{
    input();
    getMinDNA();
    printDNA();
}