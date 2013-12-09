#include<map>
#include<vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	
	UndirectedGraphNode* cloneGraph_internal(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*>& map) {
		UndirectedGraphNode* targetNode = map[node];
		if (targetNode != NULL) return targetNode;
		targetNode = new UndirectedGraphNode(node->label);
		map[node] = targetNode;
		vector<UndirectedGraphNode*>& neighbors=node->neighbors;
		for(vector<UndirectedGraphNode*>::iterator i=neighbors.begin();i!=neighbors.end();i++){
			targetNode->neighbors.push_back(cloneGraph_internal(*i, map));
		}
		return targetNode;
	}
	
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL) return NULL;
        map<UndirectedGraphNode*, UndirectedGraphNode*> map;
		return cloneGraph_internal(node, map);
    }
};

int main(){
	return 0;
}