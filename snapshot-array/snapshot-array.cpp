class SnapshotArray {
public:
    vector<vector<pair<int,int>>>data;
    int snap_idx=0;
    SnapshotArray(int length) {
        data.resize(length);
        for(int i=0;i<length;i++)
            data[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        data[index].push_back({snap_idx, val});
    }
    
    int snap() {
        return snap_idx++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(data[index].begin(), data[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */