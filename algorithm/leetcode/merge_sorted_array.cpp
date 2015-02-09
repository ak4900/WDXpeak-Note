# include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	int i, j, k, large;
    	if (A[m-1] < B[n-1])
    		large = B[n-1];
    	else
    		large = A[m-1];

        // move the elements in A to its end
        for (i = m-1,j = 1; i >=0; i--, j++){
        	A[m+n-j] = A[i];
        }
        // now the first elements of A is in A[n]
        for(i = 0, j = n, k = 0; i < m+n; i++){
        	if (j == m+n){
        		A[i] = B[k];
        		k++;
        	} else if (k == n){
        		A[i] = A[j];
        		j++;
        	} else if (A[j] < B[k]){
        		A[i] = A[j];
        		j++;
        	} else {
        		A[i] = B[k];
        		k++;
        	}
        }
        A[m+n-1] = large;
    }
};
    
int main()
{
	Solution s;
	int A[6] = {4, 5, 6, 0, 0, 0};
	int B[3] = {1, 2, 3};
	s.merge(A, 3, B, 3);

}