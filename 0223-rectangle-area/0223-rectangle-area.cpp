class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int firstArea = abs(ax2-ax1) * abs(ay2-ay1);
        int secondArea = abs(bx2-bx1) * abs(by2-by1);
        
        int x3 = max(ax1, bx1);
        int y3 = max(ay1, by1);
        int x4 = min(ax2, bx2);
        int y4 = min(ay2, by2);
        
        if(x3 > x4 || y3 > y4)
            return firstArea + secondArea;
        
        int intersection = abs(x3 - x4) * abs(y3 - y4);
        return firstArea + secondArea - intersection;
    }
};