/**
 * Time: O(N\log(N))
 * Declaration: DSU dsu(n);
 * Function: 
 * - `dsu.size(x)`: returns size of component of `x`
 * - `dsu.find(x)`: returns leader of `x`
 * - `dsu.unite(x,y)`: connects `x` and `y`,
 *      - returns true if connection is successful, false if they're already connected
 */


class DSU{
    private:
        vector<int>parents;
        vector<int> sizes;
    public:
	    // DSU dsu(n);
        DSU(int size): parents(size),sizes(size,1){
            for(int i = 0;i<size;i++){
                parents[i]=i;
            }
        }
        
        int size(int x){
            return sizes[find(x)];
        }

        int find(int x){
            return parents[x] == x ? x : (parents[x] = find(parents[x])); 
        }

        bool unite(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if (xr == yr){
                return false;
            }

            if(sizes[xr] < sizes[yr]){
                swap(xr,yr);
            }
            sizes[xr] += sizes[yr];
            parents[yr]=xr;
            return true;
        }
};
