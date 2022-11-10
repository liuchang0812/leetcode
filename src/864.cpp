


typedef tuple<int, int, int> state;



class Solution {
public:

    int shortestPathAllKeys(vector<string>& grid) {
        map<state, bool> visited;

        int start_x, start_y;
        int key_count = 0;
        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j){
                if (grid[i][j] == '@') {
                    start_x = i;
                    start_y = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') ++ key_count;
            }
        cout << "start keycount " << start_x << ' ' << start_y << ' ' << key_count << endl;
        visited[ std::make_tuple(start_x, start_y, 0)] = true;
        queue<state> Q;
        Q.push(std::make_tuple(start_x, start_y, 0));
        queue<int> step;
        step.push(0);
        while (Q.size()) {
            auto now = Q.front(); Q.pop();
            auto now_step = step.front(); step.pop();
            auto keys = std::get<2>(now);
            auto all_keys = ((1<<key_count)-1);
            if ((keys & all_keys) == all_keys) return now_step;

            static int dx[] = {-1, 1, 0, 0};
            static int dy[] = {0, 0, -1, 1};

            for (int i=0; i<4; ++i) {
                int nx = std::get<0>(now) + dx[i];
                int ny = std::get<1>(now) + dy[i];
                if (nx < 0 || nx >= grid.size() ||
                    ny < 0 || ny >= grid[0].size()) continue;
                
                if (grid[nx][ny] == '.' ||                 grid[nx][ny] == '@') {
                    state next_state = std::make_tuple(nx, ny,  std::get<2>(now));
                    if (visited[next_state]) continue;

                    Q.push(next_state);
                    step.push(now_step + 1);
                    visited[next_state] = true;
                }
                if (grid[nx][ny] == '#') continue;

                if (grid[nx][ny] <= 'z' && grid[nx][ny] >= 'a') {
                    state next_state = std::make_tuple(nx, ny,  (std::get<2>(now) | (1<<(grid[nx][ny]-'a'))));
                    if (visited[next_state]) continue;

                    Q.push(next_state);
                    step.push(now_step + 1);
                    visited[next_state] = true;
                }

                if (grid[nx][ny] <= 'Z' && grid[nx][ny] >= 'A') {
                    if (std::get<2>(now) & (1<<(grid[nx][ny]-'A'))) {
                        state next_state = std::make_tuple(nx, ny,  std::get<2>(now));
                        if (visited[next_state]) continue;

                        Q.push(next_state);
                        step.push(now_step + 1);
                        visited[next_state] = true;
                    }
                }
            }
        }
        return -1;
    }
};
