class Solution {
public:
    map<int, map<int, bool>> visited;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       int c = image[sr][sc]; 
       image[sr][sc] = newColor;
       visited[sr][sc] = true;
       static int dx[] = {0, 0, -1, +1};
       static int dy[] = {-1, +1, 0, 0};
       for (int i=0; i<4; ++i) {
           int nextX = sr + dx[i];
           int nextY = sc + dy[i];
           if (nextX >= 0 && nextX < image.size() &&
               nextY >= 0 && nextY < image[0].size() && visited[nextX][nextY] == false && image[nextX][nextY] == c)
               floodFill(image, nextX, nextY, newColor);
       }
       return image;
    }
};
