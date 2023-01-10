/*11.Number of Ways to Arrive at Destination
You are in a city that consists of n intersections numbered from 0 to n - 1
with bi-directional roads between some intersections. The inputs are generated
such that you can reach any intersection from any other intersection and that
there is at most one road between any two intersections.You are given an integer
n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there
is a road between intersections ui and vi that takes timei minutes to travel.
You want to know in how many ways you can travel from intersection 0 to
intersection n - 1 in the shortest amount of time.Return the number of ways
you can arrive at your destination in the shortest amount of time. Since the
answer may be large, return it modulo 1e9 + 7.
 */
 #define ll long long
#define MAX LONG_MAX
const int mod = 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < roads.size(); i++){
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }

        vector<ll> dp(n,MAX);
        dp[0] = 0;

        vector<ll> ans(n,0);
        ans[0] = 1;
        priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;//{time,node}
        pq.push({0,0});
        while(!pq.empty()){
            ll time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                ll t = it.second;
                if(time + t < dp[adjNode]){
                    dp[adjNode] = time + t;
                    pq.push({dp[adjNode],adjNode});
                    ans[adjNode] = ans[node]%mod;
                }
                else if(time + t == dp[adjNode])
                    ans[adjNode] = (ans[adjNode]+ans[node])%mod;
            }
        }

        return ans[n-1];
    }
};
