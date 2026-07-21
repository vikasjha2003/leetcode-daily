class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int n = startTime.length();

        int st = 0;
        int en = 0;

        int sec = 3600;

        for(int i = 0; i<n; i+=3) {     
            st += stoi(startTime.substr(i,2)) * sec;
            en += stoi(endTime.substr(i,2)) * sec;

            sec /= 60;     
        }

        return en - st;
    }
};