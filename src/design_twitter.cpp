/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Twitter {
public:
	map<int, map<int, int> > mFollower;
	vector<pair<int, int> > mTweets; // user, tweet
	
    /** Initialize your data structure here. */
    Twitter() {
    	mFollower.clear();
		mTweets.clear();    
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        mTweets.push_back(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
    	vector<int> ret;
        for (int i=mTweets.size()-1; i>=0 && ret.size() < 10; --i)
        {
        	//cout << userId << ' ' << mTweets[i].first << ' ' << mTweets[i].second << ' ' << mFollower[userId][mTweets[i].first] << endl;
        	if (userId == mTweets[i].first || mFollower[userId][mTweets[i].first] == 1)
        		ret.push_back(mTweets[i].second);
		}
		//for (int i=0; i<ret.size(); ++i) cout << ret[i] << ' '; cout << endl;

		return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        mFollower[followerId][followeeId] = 1;
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        mFollower[followerId][followeeId] = 0;
    }
};
