class Logger {
public:
    unordered_map<string,int> record;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = record.find(message);
        if(it != record.end())
        {
            int lastTimestamp = record[message];
            if(timestamp-lastTimestamp < 10)
            {
                return false;
            }
            else
                record[message] = timestamp;
        }
        else
            record[message] = timestamp;
        
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */