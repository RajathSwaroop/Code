#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>

using namespace std;

int main(){
string s = "12.25 + 12.25 & 14.32 - 14.32 & 12.3 | 12.89 + 123.21 | 12.87";
map <int,float> num;
map <int,char> op;
map <int,char>::iterator opt;
map <int,float>::iterator numt;
int n=s.length(),j=1,i=1;
char c[n+1];
strcpy(c,s.c_str());
char *a;
float t=0,l=0,r=0,result=0;
int l_1=0,r_1=0;

a = strtok(c," ");

while(a!=NULL){
	if(*a == '+' | *a == '&' | *a == '|' | *a == '-'){
			cout<<"operator"<<*a<<endl;
			op[j]=*a;
			j++;
	}
	else{
		num[i] = atof(a);
		i++;
	}
	a = strtok(NULL," ");
}

//numt = num.find(2);
//cout<<numt->second<<endl;

for(opt = op.begin();opt!=op.end();opt++){
	if(opt->second == '&'){
	
	numt = num.find(opt->first + 1);
	r_1 = opt->first;
	while(numt->second == 0){	
		r_1++;
		numt = num.find(r_1 + 1);
	}
	num.erase(numt);	
	r = numt->second;

	l_1 = opt->first;
	numt = num.find(l_1);
	while(numt->second == 0){
		l_1--;
		numt = num.find(l_1 + 1);	
	}
	l = numt->second;

	cout<<"l:"<<l<<endl;
	cout<<"r:"<<r<<endl;	
	result = (l>r) ? l : r;	
	num[numt->first] = result;

	}
}

cout<<endl;

for(numt = num.begin();numt!=num.end();numt++){
	cout<<numt->second<<endl;
}



cout<<endl;

for(opt = op.begin();opt!=op.end();opt++){
	cout<<opt->second<<endl;
	
}

cout<<endl;

for(opt = op.begin();opt!=op.end();opt++){
	if(opt->second == '|'){
	cout<<opt->first<<endl;
	

	numt = num.find(opt->first + 1);
	r_1 = opt->first;
	while(numt->second == 0){	
		r_1++;
		numt = num.find(r_1 + 1);
	}
	r = numt->second;	
	num.erase(numt);

	l_1 = opt->first;
	numt = num.find(l_1);
	while(numt->second == 0){
		l_1--;
		numt = num.find(l_1 + 1);	
	}
	l = numt->second;

	cout<<"l:"<<l<<endl;
	cout<<"r:"<<r<<endl;
	result = (l<r) ? l : r;	
	num[numt->first] = result;

	}
}


cout<<endl;

for(numt = num.begin();numt!=num.end();numt++){
	cout<<numt->second<<endl;
}

cout<<endl;


for(opt = op.begin();opt!=op.end();opt++){
	cout<<opt->second<<endl;
}

cout<<endl;

for(opt = op.begin();opt!=op.end();opt++){
	if(opt->second == '+'){
	cout<<opt->first<<endl;
	op.erase(opt->first);
	
	
	numt = num.find(opt->first + 1);
	r_1 = opt->first;
	while(numt->second == 0){	
		r_1++;
		numt = num.find(r_1 + 1);
	}
	r = numt->second;	
	num.erase(numt);
	
	l_1 = opt->first;
	numt = num.find(l_1);
	while(numt->second == 0){
		l_1--;
		numt = num.find(l_1 + 1);	
	}
	l = numt->second;
	cout<<"l:"<<l<<endl;
	cout<<"r:"<<r<<endl;
	result = l+r;	
	num[numt->first] = result;
	}
}


cout<<endl;

for(numt = num.begin();numt!=num.end();numt++){
	cout<<numt->second<<endl;
}

cout<<endl;


for(opt = op.begin();opt!=op.end();opt++){
	cout<<opt->second<<endl;
	cout<<opt->first<<endl;
}

cout<<endl;

for(opt = op.begin();opt!=op.end();opt++){
	if(opt->second == '-'){
	
	numt = num.find(opt->first + 1);
	r_1 = opt->first;
	while(numt->second == 0){	
		r_1++;
		numt = num.find(r_1 + 1);
	}
	r = numt->second;	
	num.erase(numt);
	
	l_1 = opt->first;
	numt = num.find(l_1);
	while(numt->second == 0){
		l_1--;
		numt = num.find(l_1 + 1);	
	}
	l = numt->second;
	
	cout<<"l:"<<l<<endl;
	cout<<"r:"<<r<<endl;
	result = l-r;	
	num[opt->first] = result;
	}
}

cout<<"result:"<<result<<endl;


cout<<endl;

for(numt = num.begin();numt!=num.end();numt++){
	cout<<numt->second<<endl;
}

cout<<endl;


for(opt = op.begin();opt!=op.end();opt++){
	cout<<opt->second<<endl;
}

cout<<endl;

return 0;
}
