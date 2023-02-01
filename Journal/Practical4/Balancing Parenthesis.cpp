#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
	int n = s.size();
	
	stack<char> st;
	bool ans = true;
	for(int i=0; i<n; i++){
		if(s[i] == '{' or s[i] == '(' or s[i] == '['){
			st.push(s[i]);
		}
		else if(s[i] == ')'){
			if(!st.empty() and st.top() == '('){
				st.pop();
			}
			else{
				ans = false;
				break;
			}
		}
		
		else if(s[i] == ']'){
			if(!st.empty() and st.top() == '['){
				st.pop();
			}
			else{
				ans = false;
				break;
			}
		}
		
		else if(s[i] == '}'){
			if(!st.empty() and st.top() == '{'){
				st.pop();
			}
			else{
				ans = false;
				break;
			}
		}
	}
	
	if(!st.empty())
		return false;
		
		return ans;
	
}

int main(){
	string s;
	cout<<"Enter parenthesis expression:"<<endl;
	cin>> s;
	//string s = "{([])}";
	
	if(isValid(s)){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"UnBalanced"<<endl;
	}
	return 0;
}
