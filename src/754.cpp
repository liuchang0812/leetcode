class Solution
{
	public:
		int reachNumber(int target)
		{
			target = abs(target);
			vector<int> ans = { 0, 1, 3, 2, 3, 5, 3 };

			if (target <= 6) return ans[target];
			int n = 0;
			int sum = 0;
			while (sum < target)
			{ 	++n;
				sum += n;
			}

			int delta = sum - target;
			if (delta == 0) return n;
			if (delta % 2 == 0)
				return n;
			else
			{
				if ((n + 1) % 2 == 1)
					return n + 1;
				else
					return n + 2;
			}
		}
};
