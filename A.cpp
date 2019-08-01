// Created by Sharat Sachin
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s,p1,is1,is2,is3,sum;
    
    vector<string> vs;
    
    // START OF FIRST PASS : KEEP ONLY USEFULL DATA
    while(cin>>s){
    	bool f = false;
    	if(s == "Institution:"){
    		f=true;
    		string sub = s;
    		while(cin>>is1){
    			if(is1=="S.No." || is1=="CS/Remarks") break; 
    			sub = sub + ' ' + is1;
    		}
    		s = "1 " + sub;
    	}
    	else if(s.length()==7 && s[0]=='E' && s[1]=='T') {
    		f=true;
    		string sub = s;
    		while(cin>>is1){
    			sub = sub + ' ' + is1;
    			if(is1=="1"||is1=="2"||is1=="3"||is1=="4") break; 
    		}
    		s = "2 " + p1 + ' ' + sub;
    	}
    	else if(s.length()==11 && all_of(s.begin(), s.end(), [](char c){return c>='0' && c<='9';})) {
    		f=true;
    		string sub = s;
    		while(cin>>is1){
    			if(is1=="SID:") break; 
    			sub = sub + ' ' + is1;
    		}
    		s = "3 " + sub;
    	}
    	else if((s.length()==8) && find(s.begin(), s.end(), '(') != s.end() && find(s.begin(), s.end(), ')') != s.end()) {
    		f=true;
    		cin>>is1>>is2>>is3;
    		s = "4 " + s + ' ' + is1 + ' ' + is2 + ' ' + is3;
    	}
    	else if(s == "Sem./Year:"){
    		f=true;
    		cin>>is1;
    		s = "5 Sem: " + is1;
    	}
    	else if(s == "Examination:") {
    		f=true;
    		cin>>is1;
    		s = "6 Type " + is1; 
    	}
    	else if(s == "Programme") {
    		f=true;
    		cin>>is1>>is2;
    		string sub = is2;
    		if(is1 == "Code:") s = "7 Code: " + is2; 
    		if(is1 == "Name:") {
    			while(cin>>is2){
	    			sub = sub + ' ' + is2;
	    			if(is2[is2.size()-1]==')') break; 
	    		}
	    		s = "8 " + sub;
    		}
    	}
    	else if(s == "Batch:") {
    		f=true;
    		cin>>is1;
    		s = "9 Batch " + is1; 
    	}
    	p1 = s;
    	if(!f) continue;
    	vs.push_back(s);
    }
    for(int i=0; i<vs.size(); i++) cout<<vs[i]<<"\n"; 
    // END OF FIRST PASS
    // ===================================================================================


    // vector<pair<float,string>> vp;
   	// float f=0;
    // for(int i=0; i<vs.size(); i++){
    // 	if(vs[i].length()==11) s = vs[i];
    // 	else f+=((vs[i][0]-'0')*10+(vs[i][1]-'0'));
    // 	if(vs[i+1].length()==11) {
    // 		vp.push_back({f,s});
    // 		f=0.0;
    // 	}
    // }
    // sort(vp.rbegin(), vp.rend());
    // for(int i=0;i<vp.size();i++){
    // 	cout<<i+1<<"\t: "<<vp[i].second<<' '<<mp[vp[i].second]<<"\n\t% = "<<vp[i].first/13<<"\n";
    // }
    return 0;
}