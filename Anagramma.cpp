#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;
ifstream in1("parole length.txt");
ifstream in2("parole sort.txt");
ifstream inde("index.txt");

vector < pair<string,string> > vet;
vector <int> index;

void load(){
	string s1,s2;
	while(in1>>s1){
		in2>>s2;
		vet.push_back( make_pair(s1,s2) ); 
	}
	int x;
	while(inde>>x) index.push_back(x);
}

int main(){
	load();
	string s,s_ort,f;
	do{
		cout<<"inserisci una parola"<<endl;
		cin>>s;
		cout<<endl<<"i suoi anagrammi sono: "<<endl;
		s_ort=s;
		sort(s_ort.begin(),s_ort.end());
		for(int i=index[s.length()-1];i<index[s.length()];i++){
			if(s_ort==vet[i].second) cout<<vet[i].first<<endl;
		}
		cout<<endl<<"per continuare premi y"<<endl;
		cin>>f;
		system("CLS");
	}while(f=="y");
}
