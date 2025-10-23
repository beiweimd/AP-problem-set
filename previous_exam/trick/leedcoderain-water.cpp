class Solution {
public:
    int trap(vector<int>& height) { 
        // 可以观察 每个柱子的雨水这一竖格的贡献是左右两边最高的格子中较矮的一个
        int ans=0;
        int len=height.size();
        // vector<int >suf(len+2),pre(len+2);
        // suf[len+1]=0;pre[0]=0;
        // for(int i=0;i<len;i++){pre[i+1]=max(pre[i],height[i]);}
        // for(int i=len-1;i>=0;i--){suf[i]=max(suf[i+1],height[i]);}
        // 单调栈写法
        stack<int>sk;
        for(int i=0;i<len;i++){ // 大概思想是维护一个递减的单调栈
            // 然后遇到一个比较大的时候 我们可以依次退栈顶元素，此时退的这个元素
            // 和右边这个比自己大的元素就有贡献 算一下
            // 然后这一步相当于填平了这个小坑 所以后续再遇到更大的贡献是不会丢的
            while(!sk.empty() &&height[i]>height[sk.top()]){
                int pos=sk.top();
                sk.pop();
                if(!sk.empty()) {
                    ans=ans+
                    max(
                        (min(height[i],height[sk.top()])-height[pos])
                        *
                    (i-sk.top()-1),
                    0);
                }
            }
            sk.push(i);
        }
        return ans;
    }
};