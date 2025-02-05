#include <unordered_map>
#include <string>
using namespace std;
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char, int> umap;  // map for storing character counts of the pattern
	    int ans = 0;
	    
	    // Storing the occurrence of each character in the pattern
	    for(auto &x : pat){
	        umap[x]++;
	    }
	    
	    int count = umap.size();  // This keeps track of how many distinct characters need to match
	    int k = pat.size();  // The length of the window we need to check (same as the length of the pattern)
	    int i = 0, j = 0;    // i is the start of the window, j is the end of the window
	    
	    // Sliding window loop
	    while(j < txt.size()){
	        // Calculation part: If the current character is in the pattern map, decrease its count
	        if(umap.find(txt[j]) != umap.end()){
	            umap[txt[j]]--;
	            if(umap[txt[j]] == 0) {
	                count--;  // All occurrences of this character have been matched
	            }
	        }
	        
	        // If the window size is smaller than k, expand the window
	        if(j - i + 1 < k){
	            j++;
	        }
	        // When the window size matches the pattern length
	        else if(j - i + 1 == k){
	            // If count is 0, it means the current window is a permutation of the pattern
	            if(count == 0){
	                ans++;
	            }
	            
	            // Now, slide the window by removing the influence of the character at index i
	            if(umap.find(txt[i]) != umap.end()){
	                umap[txt[i]]++;
	                if(umap[txt[i]] == 1) {
	                    count++;  // We need to match this character again
	                }
	            }
	            
	            // Slide the window by moving both i and j
	            i++;
	            j++;
	        }
	    }
	    
	    return ans;
	}
};
