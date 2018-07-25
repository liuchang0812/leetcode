class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int posx, posy, direct;
        posx = posy = direct = 0;

        long long ans = 0;

        map<int, map<int, bool>> obs;
        for (auto i:obstacles)
            obs[i[0]][i[1]] = true;

        for (auto cmd: commands) {
            if (cmd == -2) {
                // turn left
                direct = (direct + 3) % 4;
            } else if (cmd == -1) {
                // turn right
                direct = (direct + 1) % 4;
            } else {
                if (cmd >=1 && cmd <= 9) {
                    // go ahead
                    int nextX, nextY;
                    for (int i=0; i<cmd; ++i) {
                        nextX = posx + dx[direct];
                        nextY = posy + dy[direct];

                        if (obs[nextX][nextY]) break;
                        else {
                            posx = nextX;
                            posy = nextY;

                            ans = max(ans, 1ll*posx*posx + 1ll*posy*posy);
                        }
                    }

                }
            }
        }
        return ans;
    }
};
