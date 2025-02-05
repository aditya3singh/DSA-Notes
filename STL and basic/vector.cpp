/*

Vector


#include <bits/stdc++.h>
using namespace std;

void explainVector(vector <int> &a){
    cout << "Vector size: " << a.size() << endl;

    for(auto i = a.begin();  i!= a.end(); i++){
        cout<< *(i);
    }
}

void Eraser(vector <int> &a){
    a.erase(a.begin()+1);
}

int main(){
    cout<<"the explaination of vector "<<endl;

    vector<int> a = {1,2,3,4,5};
    explainVector(a);
    Eraser(a);

}
*/

/*

Vector Iterator

*/

#include <bits/stdc++.h>
using namespace std;

void explain()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int>::iterator it = v.begin();
    it++;
    cout << *it << endl;

    // Iterator loop
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration
    cout << "Reverse iteration: ";
    for(auto rit = v.rbegin(); rit != v.rend(); ++rit){
        cout << *rit << " ";
    }
    cout << endl;

    // Erasing elements
    if (v.size() > 1) {
        v.erase(v.begin() + 1);
    }
    
    // This erase operation is now commented out as v doesn't have enough elements
    // v.erase(v.begin() + 2, v.begin() + 4);

    // Creating a new vector
    vector<int> v2(2, 200);
    v2.insert(v2.begin(), 300);
    v2.insert(v2.begin() + 1, 2, 10);

    vector<int> copy(2, 50);
    v2.insert(v2.begin(), copy.begin(), copy.end());

    cout << "Size of v2: " << v2.size() << endl;
    
    if (!v2.empty()) {
        v2.pop_back();
    }

    cout << "Is v2 empty? " << (v2.empty() ? "Yes" : "No") << endl;

    v2.clear();
    cout << "Is v2 empty after clear? " << (v2.empty() ? "Yes" : "No") << endl;
}

void explainList(){
    list<int> ls;
    ls.push_back(2);
    ls.emplace_back(2,4);

    ls.push_front(5);
    ls.emplace_front(); 
}

int main() {
    explain();
    return 0;
}