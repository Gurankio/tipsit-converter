#include <iostream>
#include <string>
#include <math.h>

#include "base.cpp"
#include "../../utility/alphanumericUtility.cpp"

using namespace std;

class utf8 : public Converter {
public:
utf8() {
};

string check(string in, tuiData data) {
  cout << "Check.";
  return "TODO!";
}

string from(string in, tuiData data) {
	string res="",temp="",resT="";
	for (int i=0; i<in.length();i++){
		if (in[i]!=' ') temp.push_back(in[i]);
		if (in[i]==' ' || i==in.length()-1){
			temp=toBase1(temp,"2","0"); 
			int byte, len1=temp.length();
			if (len1<=7) resT="0xxxxxxx";
			else if (len1<=11) resT="110xxxxx-10xxxxxx"; 
			else if (len1<=16) resT="1110xxxx-10xxxxxx-10xxxxxx";
			else if (len1<=21) resT="11110xxx-10xxxxxx-10xxxxxx-10xxxxxx";
			else if (len1<=26) resT="111110xx-10xxxxxx-10xxxxxx-10xxxxxx-10xxxxxx";
			else if (len1<=31) resT="1111110x-10xxxxxx-10xxxxxx-10xxxxxx-10xxxxxx-10xxxxxx";
			int len2=resT.length();
			
			for (int i=len2-1;i>=0;i--){
				if ((resT[i]=='x') && (len1!=0)){
					resT[i]=temp[len1-1];
					len1--;
				}
				else if (resT[i]=='x') resT[i]='0';
			}
			res+=resT;
			temp="";
			if (in[i]==' ') res+=" ";
		}
	}
	return res;
}

string to(string in, tuiData data) {
	int len=in.length(), boole=0;
	string temp="",res="";
	for (int i=0; i<in.length();i++){
		if (in[i]!=' ') {
			temp.push_back(in[i]);			
		}
		if (in[i]==' ' || i==in.length()-1){
			res+=fromBase1(remove0(temp),"2"); 
			if (in[i]==' ') res+=" ";
			boole=0;
			temp="";
		}
	}
	return res; 
}
};


