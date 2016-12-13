#include <bits/stdc++.h>
using namespace std;

int lower_bound2(vector<int> &vec, int low, int high, int key) {
	if(low==high && key<=vec[low])
		return low;
	else if(low==high)
		return -1;
	int mid = (low+high)/2;
	if(key<=vec[mid])
		return lower_bound2(vec, low, mid, key);
	else return lower_bound2(vec, mid+1, high, key);
}
int main() {
	vector<int> vec;
	for(int i=1 ; i<26 ; i+=2) {
		vec.push_back(i);
	}
	vec[4] = 7;
	for(int i=0 ; i<vec.size() ; ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;
	cout << lower_bound2(vec, 0, vec.size()-1, 11);
}
