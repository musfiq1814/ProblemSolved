
#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);


    cout<<"Pattern Length: "<<M<<endl;

    cout<<"Text length: "<<N<<endl;


	int lps[M];

	computeLPSArray(pat, M, lps);

	int i = 0; 
	int j = 0; 
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}



		if (j == M) {
			printf("Found pattern at index %d to %d\n\n", i-j+1,i-j+1+M);
			j = lps[j - 1];
		}



		else if (i < N && pat[j] != txt[i]) {
		
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}




}


void computeLPSArray(char* pat, int M, int* lps)
{

	int len = 0;

	lps[0] = 0; 

	int i = 1;


	while (i < M) {


		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}


		else
		{
		
			if (len != 0) {
				len = lps[len - 1];

			
			}


			else 
			{
				lps[i] = 0;
				i++;
			}
		}



	}
}



vector<int> prefix_function(string s) {


    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }


    return pi;



}



int main()
{
    int i;
	char text[] = "GCAAGATAGGCTATGATATCAGCTATGCATAAGCTGGTACCGAGCTCGGATCTAACGACTGTTGATTGGTCAGCGGAAGATAGATCTACAGTTAGGACTTGCGACAGTCCATTTAGATCTACGCTTGATGTACCGGGCCGCATCCTTAGATCTACGTGGGAAGTGTAGGGTTCCATTGATAGATCTACACACTGACCCCCCATTCACCCCAATAGATCTAGCCCACCCCTTCTACAAAACCCTACTAGATCTATCGGGTGGTTCTAATGCGGCACTTCTAGATCTATTCGTAGCCCCTCATCGCGCAATTCTAGATCTAGCCTTCGTTTTTGTCAAGCTGCCCCTAGATCTAACACCTATGCGTCCCCCTCCCCCACTAGATCTACGACAGGCGGTCGATCAATTTTGGTTAGATCTAAGGGGTTAAATTGGGACGTGTGGAGTAGATCTACAATGCGTGATGTAATCGTGACCATTAGATCTAACGCAATGTTTCTCGCGTCCCTCGCTAGATCTATCAGAATTTTAGGGATAGGACTATCTAGATCTACCGAGGGGGGCAGGTGTCGTTGTCATAGATCCACTAGTAACGCCGCCAGTGTGCTGGAATTCTGCAGATATCCATCACAATGGCGGACGCTCGAGCATGCATCTAGAGGCCCAATTCAGCCTATAGTGAGTCGTATTACAAGTCACTGGCCGACGTCATACACGTCCGGACTGGACAACCTGGCGTACCCCCTTAACGCTGGAGGCATCCCTTTCAGTGGGAAAAAAAGAGGCAAGA";


    char pattern[] = "CAGGTGTCGTTGT";

	KMPSearch(pattern, text);

    int hashpattern = 0,p = 1;

    for(int i=0; i<strlen(pattern); i++) {
        hashpattern+=(pattern[i]-64)*p;
        p=p*3;
    }
    cout<<"Hash value of pattern : "<<hashpattern<<endl;

    vector<int> v = prefix_function(pattern);


    cout<<"size of prefix function: "<<v.size()<<endl;

    cout<<"The prefix function is : ";

    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    cout<<endl;


	return 0;
}

