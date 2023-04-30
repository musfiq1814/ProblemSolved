#include <string.h>

#include <iostream>
using namespace std;



void rabinKarp(char pattern[], char text[], int q) {

  int d = 10;
  int patttern_len = strlen(pattern);
  int text_len = strlen(text);


  cout<<"Pattern Length: "<<patttern_len<<endl;

  cout<<"Text length: "<<text_len<<endl;


  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;



  for (i = 0; i < patttern_len - 1; i++)
    h = (h * d) % q;


  


  for (i = 0; i < patttern_len; i++) {
    p = (d * p + pattern[i]) % q;
    t = (d * t + text[i]) % q;
  }

cout<<"Pattern hash value: "<<p<<endl;

cout<<"Text hash value: "<<t<<endl;

for (i = 0; i <= text_len - patttern_len; i++) {
    if (p == t) {
      for (j = 0; j < patttern_len; j++) {
        if (text[i + j] != pattern[j])
          break;
      }

      if (j == patttern_len)
        cout << "Pattern is found at position: " << i + 1 << endl;
    }

    if (i < text_len - patttern_len) {
      t = (d * (t - text[i] * h) + text[i + patttern_len]) % q;

      if (t < 0)
        t = (t + q);
    }
  }
}



int main(){


    char text[] = "GCAAGATAGGCTATGATATCAGCTATGCATAAGCTGGTACCGAGCTCGGATCTAACGACTGTTGATTGGTCAGCGGAAGATAGATCTACAGTTAGGACTTGCGACAGTCCATTTAGATCTACGCTTGATGTACCGGGCCGCATCCTTAGATCTACGTGGGAAGTGTAGGGTTCCATTGATAGATCTACACACTGACCCCCCATTCACCCCAATAGATCTAGCCCACCCCTTCTACAAAACCCTACTAGATCTATCGGGTGGTTCTAATGCGGCACTTCTAGATCTATTCGTAGCCCCTCATCGCGCAATTCTAGATCTAGCCTTCGTTTTTGTCAAGCTGCCCCTAGATCTAACACCTATGCGTCCCCCTCCCCCACTAGATCTACGACAGGCGGTCGATCAATTTTGGTTAGATCTAAGGGGTTAAATTGGGACGTGTGGAGTAGATCTACAATGCGTGATGTAATCGTGACCATTAGATCTAACGCAATGTTTCTCGCGTCCCTCGCTAGATCTATCAGAATTTTAGGGATAGGACTATCTAGATCTACCGAGGGGGGCAGGTGTCGTTGTCATAGATCCACTAGTAACGCCGCCAGTGTGCTGGAATTCTGCAGATATCCATCACAATGGCGGACGCTCGAGCATGCATCTAGAGGCCCAATTCAGCCTATAGTGAGTCGTATTACAAGTCACTGGCCGACGTCATACACGTCCGGACTGGACAACCTGGCGTACCCCCTTAACGCTGGAGGCATCCCTTTCAGTGGGAAAAAAAGAGGCAAGA";


    char pattern[] = "ATAGTGAGTCGTA";
    
    
    int q = strlen(text);
    
    
    rabinKarp(pattern, text, q);
  


}