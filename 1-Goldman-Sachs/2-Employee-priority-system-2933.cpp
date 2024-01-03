class Solution {
public:

    bool isvalid(vector<int>times)
    {
        for(int i=0;i<times.size()-2;i++)
        {
            if(times[i+2]-times[i]<60)
            {
                return true;
            }
        }
        return false;
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        unordered_map<string,vector<int>> umap;
        for(auto x:access_times)
        {
            string h=x[1].substr(0,2);
            string m=x[1].substr(2,2);
            int totmin=stoi(h)*60+stoi(m);
            umap[x[0]].push_back(totmin);
        }
        for(auto p:umap)
        {
            if(p.second.size()<3)
            {
                continue;
            }
            sort(p.second.begin(),p.second.end());
            if(isvalid(p.second))
            {
                ans.push_back(p.first);
            }
        }
        return ans;
        
    }
};
