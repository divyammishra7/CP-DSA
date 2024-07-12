 #include<bits/stdc++.h>
 using namespace std;
 class DisjointSetUnion {
public:
 void initialize(int elementsnum) {
 rootparent.resize(elementsnum);
 for (int i = 0; i < elementsnum; ++i)
 rootparent[i] = i;
}

 int findRoot(int element) {
  if (rootparent[element] != element)
 rootparent[element] = findRoot(rootparent[element]);
 return rootparent[element];
}

 void unite(int element1, int element2) {
 int root1 = findRoot(element1);
 int root2 = findRoot(element2);
if (root1 != root2){
rootparent[root1] = root2;

}
}

private:
 vector<int> rootparent;
};
string solve(vector<string>& words) {
   int wordCount = words.size();

DisjointSetUnion dsu;
 dsu.initialize(26);
 vector<int> inwali(26, 0);
 vector<int> outwali(26, 0);
 vector<bool> connectionhai(26, false);

 string ANSWER;
 // ???
 for (int k = 0; k < wordCount; ++k) {
 int shuru = words[k][0] - 'a';
 int end = words[k].back() - 'a';
 outwali[shuru]++;
 inwali[end]++;
 dsu.unite(shuru, end);
 connectionhai[shuru] = connectionhai[end] = true;

 int root = dsu.findRoot(shuru);
 unordered_set<int> roootsaa;
 for (int i = 0; i < 26; ++i) {
 if (connectionhai[i] && (inwali[i] > 0 || outwali[i] > 0))
 roootsaa.insert(dsu.findRoot(i)); }

 if (roootsaa.size() > 1) {
 ANSWER.push_back('0');
 continue;
 }

 vector<int> diverse;
 for (int i = 0; i < 26; ++i) {
 if (connectionhai[i] && (inwali[i] > 0 || outwali[i] > 0))
 diverse.push_back(outwali[i] - inwali[i]);
 }
 if (!diverse.empty()) {
 int maxDifference = *max_element(diverse.begin(), diverse.end());
 int minDifference = *min_element(diverse.begin(), diverse.end());
 if (!((maxDifference == 0 && minDifference == 0) || (maxDifference == 1 && minDifference == -1 && count(diverse.begin(), diverse.end(), 1) == 1 && count(diverse.begin(), diverse.end(), -1) == 1))) {
 ANSWER.push_back('0');
 continue;
 }
 }

 ANSWER.push_back('1');
 }

 return ANSWER;
}


 int main(){
  return 0;
 }