class Solution {
    private:
        bool dfs(int course_num, unordered_map<int, vector<int>> &course_rule, unordered_set<int> &visited) {
            if (visited.find(course_num) != visited.end())
                return false;
    
            if (course_rule[course_num].empty())
                return true;
            
            visited.insert(course_num);
            
            for (int idx = 0; idx < course_rule[course_num].size(); idx++) {
                if (!dfs(course_rule[course_num][idx], course_rule, visited))
                    return false;
            }
    
            visited.erase(course_num);
            course_rule[course_num].clear();
    
            return true;
        }
    
    public:
        bool canFinish(int numCourses, vector<vector<int>>& rules) {
            unordered_map<int, vector<int>> course_rule;
            unordered_set<int> visited;
            
            for(auto rule: rules) {
                if (course_rule[rule[0]].empty())
                    course_rule[rule[0]] = {};
                course_rule[rule[0]].push_back(rule[1]);
            }
                
            for (int idx = 0; idx < numCourses; idx++) {
                if (!dfs(idx, course_rule, visited))
                    return false;
            }
    
            return true;
        }
    };
    