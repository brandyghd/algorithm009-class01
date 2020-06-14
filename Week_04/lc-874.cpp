//874. 模拟行走机器人
class Solution {
public:
    struct pair_hash
    {
        template<class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const
        {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1^h2;
        }
    };
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        int dX[4] = {0,1,0,-1};
        int dY[4] = {1,0,-1,0};

        unordered_set<pair<int,int>, pair_hash> mySet;
        for(vector<vector<int>>::iterator iteObs = obstacles.begin(); iteObs != obstacles.end(); ++iteObs)
        {
            mySet.insert(make_pair((*iteObs)[0],(*iteObs)[1]));
        }

        int curX = 0, curY = 0, curDir = 0, maxDis = 0;
        for(vector<int>::iterator iteComm = commands.begin(); iteComm != commands.end(); ++iteComm)
        {
            //direction
            if(*iteComm < 0)
            {
                if(-2 == *iteComm)
                {
                    curDir = (curDir+4-1)%4;
                }
                if(-1 == *iteComm)
                {
                    curDir = (curDir+1)%4;
                }
            }
            else
            {
                for(int i = 0; i < *iteComm; ++i)
                {
                    if(mySet.find(make_pair(curX+dX[curDir],curY+dY[curDir])) == mySet.end())
                    {
                        curX += dX[curDir];
                        curY += dY[curDir]; 
                    }
                    else
                    {
                        break;
                    }
                }
                maxDis = (curX*curX+curY*curY > maxDis)?(curX*curX+curY*curY):maxDis;
            }
        }
        return maxDis;
    }
};