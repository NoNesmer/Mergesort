#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right){
    int il, ir; /// il = index_left, ir = index_right
    il = ir = 0;
    vector<int> merged;
    while(il < left.size() && ir < right.size()){
        if(left[il] <= right[ir]){
            merged.push_back(left[il]);
            il++;
        } else {
            merged.push_back(right[ir]);
            ir++;
        }
    }
while(il < left.size()){
    merged.push_back(left[il]);
    il++;
}

while(ir < right.size()){
    merged.push_back(right[ir]  );
    ir++;
}

return merged;
}

vector<int> merge_sort(vector<int> array){
    if(array.size() <= 1){
        return array;
    }
    int mdp;  /// mdp = midpoint
    mdp = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + mdp);
    vector<int> right(array.begin() + mdp, array.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);

}


int main() {
int n;
cin >> n;
if(n <= 0){
    cout << "This is wrong size of mas";
    return 0;
}
vector<int> mas(n); /// mas = massive
for(int i = 0; i < n; i++){
    cin >> mas[i];
}
mas = merge_sort(mas);
for(int i = 0; i < n; i++){
    cout << mas[i];
}
    return 0;
}
