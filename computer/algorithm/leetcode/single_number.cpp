#include <iostream>

using namespace std;

class Solution {
public:
/*
    int singleNumber(int A[], int n) {
		int ans = 0;
		for (size_t i = 0; i < n; ++i){
			ans ^= A[i];
		}
		return ans;
    }
*/
	int singleNumber(int A[], int n) {
		bool istheone = true;
		for (int i = 0; i < n ; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j && A[i] == A[j]){
					istheone = false;
					break;
				}
			}
			if (istheone){
				return A[i];	
			}
			istheone = true;
		}
	}
};

int main(int argc, char *argv[]) {
	int A[11] = {1,2,3,4,5,5,4,3,2,1,9};
	Solution *s = new Solution();
	cout << s->singleNumber(A, 11) << endl;
	
}