use std::cmp;

impl Solution {
    pub fn minimum_total(triangle: Vec<Vec<i32>>) -> i32 {
        let level = triangle.len();
        let mut dp: [[i32; 202]; 202] = [[10000 ;202]; 202];
        let mut ans = 10000;
        for i in 0..level {
            for j in 0..=i {
                if i == 0 && j == 0 {
                    dp[1][1] = triangle[0][0];
                    if i == level-1 {
                    ans = cmp::min(ans, dp[1][1]);
                }
                    continue;
                }
                let x = i+1;
                let y =j+1;
                dp[x][y] = cmp::min(dp[x-1][y-1], dp[x-1][y]) + triangle[i][j];
                print!("{0} {1} {2}\n", x, y, dp[x][y]);
                if i == level-1 {
                    ans = cmp::min(ans, dp[x][y]);
                }
            }
        }
        ans
    }
}
