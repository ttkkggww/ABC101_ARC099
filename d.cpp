#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

ll ds(ll x){
	ll res = 0;
	while(x){
		res += x%10;
		x/=10;
	}
	return res;
}

int main()
{
	vector<ll> anss;
	for(ll d = 1;d<=17;d++){
		string s(d,'0');
		s[0]='1';
		if(d>1)
		for(int i = s.size()-1;i>0;i--){
			ll snum = atoll(s.c_str());
			ll snums = ds(snum);
			string t =s;
			for(int j = 0;j<10;j++){
				t[i]='0'+j;
				ll tnum = atoll(t.c_str());
				ll tnums = ds(tnum);
				if(snum*tnums>tnum*snums){
					s = t;
				}
			}
		}
		string nines;
		for(int i = s.size()-1;i>0;i--){
			if(s[i]=='9')nines.push_back('9');
		}
		ll tmp = atoll(s.substr(0,s.size()-nines.size()).c_str());
		stack<ll> S;
		//S.emplace(atoll(s.c_str()));
		for(ll i = tmp;i<tmp*10;i++){
			//cout<<i<<endl;
			string t = to_string(i);
			t += nines;
			ll tnum = atoll(t.c_str());
			ll tnums = ds(tnum);
			if(S.empty()){
				S.emplace(tnum);
				continue;
			}
			while(S.top()*tnums>tnum*ds(S.top())){
				S.pop();
			}
			S.emplace(tnum);
		}
		while(S.size()){anss.emplace_back(S.top());S.pop();}
	}
	int k;
	cin >> k;
	sort(anss.begin(),anss.end());
	for(int i=0;i<k;i++){
		cout<<anss[i]<<endl;
	}
}
