class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int,string>>q;
        q.push({1,beginWord});
        unordered_map<string,int>um;
        unordered_map<string,int>before;
        for(auto &it:wordList){
            um[it]++;
        }
        before[beginWord]=1;
        while(!q.empty()){
            int size=q.size();
            for(int j=0;j<size;j++){
                pair<int,string>p=q.front();
                q.pop();
                int step=p.first;
                string word=p.second;
                if(word==endWord){
                    return step;
                }
                for(int i=0;i<word.size();i++){
                    string temp=word;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(um.find(temp)!=um.end() && before.find(temp)==before.end()){
                            before[temp]=1;
                            q.push({step+1,temp});
                        }
                    }
                }
            }
        }
        return 0;
    }
};