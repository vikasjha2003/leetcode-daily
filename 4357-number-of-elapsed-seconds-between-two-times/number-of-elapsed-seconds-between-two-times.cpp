class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int n = startTime.length();

        int st = 0;
        int en = 0;

        int sec = 3600;

        for(int i = 0; i<n; i++) {
            string str = "";
            string stri = "";
            while(i < n && startTime[i] != ':') {
                str += startTime[i];
                stri += endTime[i];
                i++;
            }
            
            st += stoi(str) * sec;
            en += stoi(stri) * sec;

            sec /= 60;     
        }

        return en - st;
    }
};