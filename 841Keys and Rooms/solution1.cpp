class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size());
        dfs(rooms, visited,0);
        int visited_rooms=0;
        for(int i=0; i<rooms.size(); i++){
            if(visited[i]){
                visited_rooms+=1;
            }
        }
        return rooms.size()==visited_rooms;
    }
    
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int pos){
        visited[pos]=true;
        for(int i=0; i<rooms[pos].size() ; i++){
            int room_num=rooms[pos].at(i);
            if(!visited[room_num]){
                dfs(rooms, visited, room_num);
            }
        }
    }
};