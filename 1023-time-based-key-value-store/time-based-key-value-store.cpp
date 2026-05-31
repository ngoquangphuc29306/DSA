class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string answer = "";
        auto& values = mp[key];
        int l = 0;
        int r = values.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(values[mid].first <= timestamp){
                answer = values[mid].second;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return answer;
    }
};
