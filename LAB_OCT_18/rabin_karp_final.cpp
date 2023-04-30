#include<bits/stdc++.h>
using namespace std;

int main() {
    string text,pattern;
    cout<<"Enter the text : ";
    cin>>text;
    cout<<"Enter the pattern : ";
    cin>>pattern;
    int p=1,hashpattern=0,hashtemp=0,countt=0;
    int lenp = pattern.length(), lent=pattern.length();
    for(int i=0; pattern[i]; i++) {
        hashpattern+=(pattern[i]-64)*p;
        p=p*3;
    }
    cout<<"Hash value of pattern : "<<hashpattern<<endl;
    p=1;
    for(int i=0; text[i]; i++) {
        if(i<lenp) {
            hashtemp+=(text[i]-64)*p;
            p=p*3;
            if(i==lenp-1 && hashtemp==hashpattern)  countt++,cout<<"Pattern found at postion : "<<1<<endl;
        }
        else {
            int t=p/3;
            hashtemp = ((hashtemp-(text[i-lenp]-64))/3) + ((text[i]-64)*t);
            if(hashtemp==hashpattern)  countt++,cout<<"Pattern found at position : "<<(i-lenp+2)<<" to "<<(i-lenp+2)+pattern.length()<<endl;
        }
    }
    cout<<"Total pattern = : "<<countt<<endl;
    return 0;
}
/*
GCAAGATAGGCTATGATATCAGCTATGCATAAGCTGGTACCGAGCTCGGATCTAACGACTGTTGATTGGTCAGCGGAAGATAGATCTACAGTTAGGACTTGCGACAGTCCATTTAGATCTACGCTTGATGTACCGGGCCGCATCCTTAGATCTACGTGGGAAGTGTAGGGTTCCATTGATAGATCTACACACTGACCCCCCATTCACCCCAATAGATCTAGCCCACCCCTTCTACAAAACCCTACTAGATCTATCGGGTGGTTCTAATGCGGCACTTCTAGATCTATTCGTAGCCCCTCATCGCGCAATTCTAGATCTAGCCTTCGTTTTTGTCAAGCTGCCCCTAGATCTAACACCTATGCGTCCCCCTCCCCCACTAGATCTACGACAGGCGGTCGATCAATTTTGGTTAGATCTAAGGGGTTAAATTGGGACGTGTGGAGTAGATCTACAATGCGTGATGTAATCGTGACCATTAGATCTAACGCAATGTTTCTCGCGTCCCTCGCTAGATCTATCAGAATTTTAGGGATAGGACTATCTAGATCTACCGAGGGGGGCAGGTGTCGTTGTCATAGATCCACTAGTAACGCCGCCAGTGTGCTGGAATTCTGCAGATATCCATCACAATGGCGGACGCTCGAGCATGCATCTAGAGGCCCAATTCAGCCTATAGTGAGTCGTATTACAAGTCACTGGCCGACGTCATACACGTCCGGACTGGACAACCTGGCGTACCCCCTTAACGCTGGAGGCATCCCTTTCAGTGGGAAAAAAAGAGGCAAGA
*/
/*
ATAGTGAGTCGTA
*/