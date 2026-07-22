class Twitter {
    public:
        unordered_map<int, priority_queue<pair<int, int>>> users_tweet;
        unordered_map<int, unordered_set<int>> following_map;
        int lastest;
    
        Twitter() {
            lastest = 0;
        }
        
        void postTweet(int userId, int tweetId) {
            users_tweet[userId].push({lastest++, tweetId});
            following_map[userId].insert(userId);
        }
        
        vector<int> getNewsFeed(int userId) {
            vector<int> tweets;
            priority_queue<pair<int, int>> final_queue;
            priority_queue<pair<int, int>> temp_queue;
    
            for(auto user: following_map[userId]) {
                temp_queue = users_tweet[user];
                while(!temp_queue.empty()) {
                    final_queue.push(temp_queue.top());
                    temp_queue.pop();
                }
            }
    
            int cnt = 0;
    
            while(cnt < 10 && !final_queue.empty()) {
                tweets.push_back(final_queue.top().second);
                final_queue.pop();
                cnt++;
            }
        
    
            return tweets;
        }
        
        void follow(int followerId, int followeeId) {
            following_map[followerId].insert(followeeId);
        }
        
        void unfollow(int followerId, int followeeId) {
            if (followerId != followeeId)
                following_map[followerId].erase(followeeId);
        }
    };
    
    
    /**
     * Your Twitter object will be instantiated and called as such:
     * Twitter* obj = new Twitter();
     * obj->postTweet(userId,tweetId);
     * vector<int> param_2 = obj->getNewsFeed(userId);
     * obj->follow(followerId,followeeId);
     * obj->unfollow(followerId,followeeId);
     */