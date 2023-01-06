/*6.Perfect Rectangle
Given an array rectangles where rectangles[i] = [xi, yi, ai, bi]
represents an axis-aligned rectangle. The bottom-left point of the
rectangle is (xi, yi) and the top-right point of it is (ai, bi).
Return true if all the rectangles together form an exact cover of a rectangular region.*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> m;
        /*the value representation of a whole rectangle is same as the value representation of all grids.*/
        for(int i=0;i<rectangles.size();i++)
        {
            m[{rectangles[i][0],rectangles[i][1]}]++;//bottom left
            m[{rectangles[i][2],rectangles[i][3]}]++;//top right
            m[{rectangles[i][0],rectangles[i][3]}]--;//top left
            m[{rectangles[i][2],rectangles[i][1]}]--;//bottom right
        }
        int ans=0;
        /*only 4 points having value +1 or -1 make rectangle.*/
        for(auto it:m)
        {
            if(it.second)
            {
                if(abs(it.second)==1)ans++;
                else return false;
            }
        }
        return ans==4;
    }
};
