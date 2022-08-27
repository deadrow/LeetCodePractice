class Solution(object):
    def rearrangeString(self, s, k):
        n = len(s)
        if not k: return s
        count = collections.Counter(s)
        maxf = max(count.values())
        
        test = count.values().count(maxf)
        if (maxf - 1) * k + count.values().count(maxf) > len(s):
            return ""
        res = list(s)
        i = (n - 1) % k
        for c in sorted(count, key=lambda i: -count[i]):
            for j in range(count[c]):
                res[i] = c
                i += k
                if i >= n:
                    i = (i - 1) % k
        return "".join(res)
        