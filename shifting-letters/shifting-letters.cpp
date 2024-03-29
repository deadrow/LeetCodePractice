class Solution {
public:
	int floorMod(long x, int y)
	{
		return ((x % y) + y) % y;
	}

	string shiftingLetters(string s, vector<int>& shifts) {
		int sum = 0;
        for(auto& it : shifts)
        {
            sum = (sum + it) % 26;
        }

		string ret(s);
		long cur = sum;
		for(int i=0;i<shifts.size();i++)
		{
			int step = floorMod(cur + (ret[i] - 97), 26);
			ret[i] = step + 97;
			cur -= shifts[i];
		}

		return ret;
	}
};