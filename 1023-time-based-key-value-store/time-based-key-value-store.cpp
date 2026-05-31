class TimeMap {
public:
    map<string,map<int, string>> mp; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].upper_bound(timestamp);
        if(it == mp[key].begin()) return "";
        it--;
        return mp[key][it->first];
    }
};
