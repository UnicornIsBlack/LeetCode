#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Tweet
{
	int userId;
	int tweetId;
	Tweet(int user, int tweet)
	{
		userId = user;
		tweetId = tweet;
	}
};

class Twitter
{
	public:
	/** Initialize your data structure here. */
	Twitter()
	{

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId)
	{
		Tweet tweet = Tweet(userId, tweetId);
		tweets.insert(tweets.begin(), tweet);
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId)
	{
		vector<int> res;
		for ( int i = 0; i < tweets.size(); i++ )
		{
			if ( res.size() == 10 )
				break;
			if ( tweets[i].userId == userId ||
				(followers.find(userId) != followers.end() &&
				followers[userId].find(tweets[i].userId) != followers[userId].end()) )
				res.push_back(tweets[i].tweetId);
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId)
	{
		followers[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId)
	{
		followers[followerId].erase(followeeId);
	}
	private:
	vector<Tweet> tweets;
	map<int, set<int>> followers;
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/


int main()
{
	return 0;
}