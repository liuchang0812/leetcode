class Solution {
 public:
  int NetworkQuality(int x, int y, int radius, vector<int>& tower) {
    int d = ((tower[0] - x) * (tower[0] - x) + (tower[1] - y) * (tower[1] - y));
    // printf("%d %d %d %d\n", x, y, radius, d);
    if (d > radius * radius) return 0;
    return floor(tower[2] / (1 + sqrt(d)));
  }

  vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    sort(towers.begin(), towers.end(), [](vector<int> a, vector<int> b) {
      return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
    });

    int ans = 0;
    vector<int> ans_pos = {0, 0};
    int n = towers.size();
    for (int x = towers[0][0]; x <= towers[n - 1][0]; ++x)
      for (int y = 0; y <= 50; ++y) {
        int quality = 0;
        for (auto& tower : towers) {
          quality += NetworkQuality(x, y, radius, tower);
        }
        // printf("cal %d %d %d\n", quality, x, y);

        if (quality > ans) {
          // printf("old %d %d %d\n", ans, ans_pos[0], ans_pos[1]);
          // printf("new %d %d %d\n", quality, x, y);
          ans = quality;
          ans_pos = {x, y};
        }
      }
    return ans_pos;
  }
};
