#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
	string input;
	cin >> input;	
	string number = "";
	bool isReal = false;
	bool isNegative = false;
	vector<string> res;
	for(int i = 0; i < input.length(); i++) {
		if(input[i] >= '0' && input[i] <= '9') {
			number += input[i];
		} else if(input[i] == '-' && number == "") {
			isNegative = true;
		}
		else if(number != "" && input[i] == ',' && !isReal) {
			isReal = true;
			number += input[i];
		} else if(number != ""){
			isReal = false;
			if(number[number.length()-1] == ',')
				number = number.substr(0, number.length()-1);
			res.push_back(isNegative ? '-' + number : number);
			number = "";
			isNegative = input[i] == '-';
		} else {
			isReal = false;
			number = "";
			isNegative = input[i] == '-';
		}
	}
	if(number != "")
		res.push_back(isNegative ? '-' + number : number);
	for(int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	return 0;
}
